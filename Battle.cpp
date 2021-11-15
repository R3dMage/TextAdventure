#include <sstream>
#include "Battle.h"

Battle::Battle(MainMenuSystem* menu, FightDisplay* fightDisplay, ItemRepository* itemRepository, MusicPlayer* musicPlayer)
{
	Menu = menu;
	Display = fightDisplay;
	Items = itemRepository;
	Music = musicPlayer;
}

void Battle::Engage(Player* player, Creature* enemy, std::vector<Item*>& playerInventory, std::vector<Item*>& worldItems, std::vector<Magic*>& spells, std::string mapName)
{
	COORD CursPos;					// Mystical Cursor Position
	string Ename = enemy->GetName();	// Name of the enemy
	int choice;						// Um, choice?
	int Evd;						// An Evade variable
	int Damage;						// A Damage Variable
	int R = 0;						// R?
	Weapon* weapon = player->GetWeapon(); // Weapon Variable
	Armor* armor = player->GetArmor();	// Armor Variable
	
	bool bWeak = false;				// Weakness bool for, checking weakness
	bool bMagical = false;			// Magical bool for checking magicalness
	bool bFight = true;				// To check if player is in a fight
	bool run = false;

	Display->ClearAll();
	/*==================================================================
		This calls some music to play for the fights, dynamic according
		to the different enemies. How awesome is that?
	===================================================================*/
	Music->PlayMusic(enemy->GetMusic().c_str());

	Display->DisplayAttackAnnouncement(enemy);

	if (enemy->GetHasBanter())						// Check if enemy will talk before the fight
		enemy->Banter();							// Enemy's prefight speech

	while (enemy->GetHitPoints() > 0 && player->GetCurrentHitPoints() > 0 && !run)
	{
		bool bEsc = false;				// Escape bool for menu
		bool bSel = false;				// Select bool for menu
		bool bLeave = false;			// Leave  bool for menu
		bool fight = false;
		bool magic = false;
		bool item = false;
		bool pass = false;

		Display->DisplayPlayerInfo(player);	// Display player info
		Display->DisplayCreatureStatus(enemy); // Display enemy info, this will probably be phased out, or tweaked

		if (player->GetIsAsleep())					// Checks if player is asleep
		{
			R = rand() % 100 + 1;
			if (R < 50)								// 50% chance of waking up. NOTE: Maybe make that enemy specific %
			{
				player->SetIsAsleep(false);
				Display->DisplayMessage("You awake from sleep!");
			}
		}
		if (player->GetIsAsleep())					// Checks if you're still asleep after your chance to wake
		{
			Display->DisplayMessage("You are asleep");
		}
		else
		{
			CursPos.X = 2;
			CursPos.Y = 12;

			Display->DisplayFightMenu();

			Menu->DrawCursor(CursPos, ftext, 175);
			do
			{
				if (Menu->MoveCursor(CursPos, bSel, bEsc, 12, 15))
				{
					Menu->DrawCursor(CursPos, ftext, 175);
				}
				// text("", 79, 23, ftext);
			} while (!bSel);

			choice = CursPos.Y;
			switch (choice)
			{
			case 12:
				PlayerAttack(player, Display, enemy);
				break;
			case 13:
				PlayerMagic(player, enemy, spells, bEsc, pass);
				break;
			case 14:
				Menu->UseItem(player, worldItems, playerInventory, true, bLeave, mapName);
				if (bLeave)
					pass = true;
				armor = player->GetArmor();
				weapon = player->GetWeapon();
				break;
			case 15:
				run = true;
				break;
			}

			/*============================================================================================
				Should the player try to run, we go here
			============================================================================================*/
			if (run)
			{
				if (RunAway(player, enemy))
					break;

				run = false;
			}
			
			if (enemy->GetHitPoints() <= 0)
				pass = true;
			
			if (enemy->GetState() == 2)
			{
				Display->DisplayMessage("The enemy is stunned");
				pass = true;
				enemy->SetState(0);
			}
			
			if (enemy->GetState() == 3)
			{
				Damage = rand() % 10 + 10;
				enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
				Display->DisplayMessageWithRedNumber("The enemy takes poison damage: ", Damage);
				if (enemy->GetHitPoints() <= 0)
					pass = true;
			}
		}
		//===========================================================================================================
		//		This is where the enemy gets to attack the player. Cuz you know, they do that.
		//===========================================================================================================

		if (!pass)
		{
			Display->ClearAll();
			Display->DisplayCreatureStatus(enemy);
			Display->DisplayPlayerInfo(player);
			Evd = rand() % 100 + 1;
			if (Evd <= player->GetEvade() + armor->GetEvadeModifier() && !player->GetIsAsleep())	// Elaborate equation for evasion
			{
				Display->DisplayMessage("You dodged the enemy attack");
			}
			else
			{
				if (player->GetIsPoisoned())										// Check if player is poisoned
				{
					Damage = rand() % 10 + 1;								// Conjure up some poison damage
					player->SetHitPoints(player->GetCurrentHitPoints() - Damage);						// Incur that damage	
					Display->DisplayMessageWithRedNumber("You take poison damage: ", Damage);
					if (player->GetCurrentHitPoints() < 1)
						break;
				}
				enemy->Attack(player, Display);							// Enemy attack
				Display->DisplayPlayerInfo(player);
				Display->ClearAll();
			}
		}
		if (enemy->GetRunAway())											// Check to see if the enemy will run away
			break;

	}//===========================================[End while HP > 0
//=============================================================================================================
//										This is where the fighting ends
//		Then we check for level ups and junk.
//=============================================================================================================
	if (enemy->GetHitPoints() <= 0)
	{
		Win(Display, player, enemy, worldItems, mapName);
	}

	if (player->GetCurrentHitPoints() <= 0)
	{
		Display->ClearAll();
		Display->DisplayMessage("You have died");
		return;
	}

	if (enemy->GetRunAway())
	{
		Display->ClearAll();
		Display->DisplayMessage("The enemy has run off!!!");
		enemy->SetRunAway(false);
		Display->ClearAll();
	}
	/*============================================================
		Here, we put the map music back on. Providing of course
		that we haven't changed musicFilename at all. I hope!
	=============================================================*/
	Music->PlayMusic(Music->GetMusicFilename());
}

void Battle::PlayerAttack(Player* player, FightDisplay* fightDisplay, Creature* enemy)
{
	fightDisplay->DisplayPlayerInfo(player);						// Display player info
	fightDisplay->DisplayCreatureStatus(enemy);	// Display enemy info NOTE: TEMPORARY or something anyway
												//----------------------------------------------------------------->|Check for hit!
	int Evd = rand() % 100 + 1;
	if (Evd <= enemy->GetEvade())
	{
		fightDisplay->DisplayMessage("The enemy has dodged your attack!");
		return;
	}

	bool bWeak = false;
	bool bMagical = false;
	Weapon* weap = player->GetWeapon();
	int Damage = rand() % weap->GetDamage() + weap->GetDamageModifier();//--->|Weapon's Damage
	int StrMod = rand() % (player->GetStrength() / 2) + 2;//-------------------->|Strength modifier
	Damage += StrMod;
	if (weap->GetHitsTwice())//-------------------------------------->|Xtra hit check
	{
		int D2 = rand() % weap->GetDamage() + weap->GetDamageModifier();
		StrMod = rand() % (player->GetStrength() / 2) + 2;
		D2 += StrMod;
		fightDisplay->DisplayMessage("2 Hits!!");
		Damage += D2;
	}
	//----------------------->Checks for weakness in the monsters. Double Damage is pretty cool
	if (weap->GetAttribute1() == enemy->GetWeakness() || weap->GetAttribute2() == enemy->GetWeakness())
		bWeak = true;
	//---------------------------------------------------------->Checks if the weapon is magical
	if (weap->GetAttribute1() == "magical")
		bMagical = true;
	//----------------->|If the creature is weak against the player's weapon, then double damage.
	if (bWeak)
		Damage *= 2;
	//----------------------------------------------------->|Damage to the undead is cut in half. 
	if (!bWeak && !bMagical && enemy->GetType() == "undead")
		Damage /= 2;
	//PlaySound("sword1.wav",NULL,SND_FILENAME | SND_ASYNC);


	//----------------------------------------------------->|Some enemies have good defenses				
	Damage = Damage - enemy->GetDefense();
	if (Damage < 1)
		Damage = 1;//-------------------------------------->|But damage is always at least 1.
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);

	stringstream messageStream;
	messageStream << "Your Damage :" << Damage;
	fightDisplay->DisplayMessage(messageStream.str());
	fightDisplay->DisplayDamage(Damage);
	if (weap->HasLifeSteal())
	{
		player->SetHitPoints(player->GetCurrentHitPoints() + Damage / 2);
		messageStream.str(string());
		messageStream << "Life Gained:    " << Damage / 2;
		fightDisplay->DisplayMessage(messageStream.str());
		fightDisplay->DisplayDamage(Damage / 2);
	}

}

void Battle::PlayerMagic(Player* player, Creature* enemy, std::vector<Magic*>& spells, bool& bEsc, bool &pass)
{
	if (!player->HasLearnedSpells())
	{
		pass = true;
		Display->DisplayMessage("You have no magic");
	}
	else
	{
		Menu->InFightMagicMenu(player, enemy, spells, bEsc);
		if (bEsc)
			pass = true;
	}
}

bool Battle::RunAway(Player* player, Creature* enemy)
{
	int Evd = rand() % 100 + 1;
	if (Evd > enemy->GetEvade())
	{
		PlaySound("./data/run.wav", NULL, SND_FILENAME | SND_ASYNC);
		Display->DisplayMessage("You ran away");
		Display->ClearAll();
		return true;
	}
	else
	{
		Display->DisplayMessage("The enemy thought you should stay");
		return false;
	}
}

void Battle::Win(FightDisplay* fightDisplay, Player* player, Creature* enemy, vector<Item*>& worldItems, string map)
{
	player->SetMagicStatus(0);						// After a fight state gets set to zero
	player->SetIsPoisoned(false);					// After a fight you are no longer poisoned
	fightDisplay->ClearAll();
	Music->StopMusic();
	PlaySound("./data/WinBattle.wav", NULL, SND_FILENAME | SND_ASYNC);

	fightDisplay->DisplayWinContent(player, enemy);
	player->SetTotalKills(player->GetTotalKills() + 1);
	player->SetGold(player->GetGold() + enemy->GetGold());
	player->SetExperience(player->GetExperience() + enemy->GetExperience());
	fightDisplay->DisplayPlayerInfo(player);

	/*================================================================
		Here I will put the you beat the bad guy music! which will
		be static I think. Unless you get cooler music from a boss.
	==================================================================*/
	while (player->ReachedNextLevel())
	{
		player->IncreaseLevel();						// Player function to go up a level
		//p2->playMusic("Level Up Music");  Don't have level up music yet
		fightDisplay->DisplayLevelUp(player);
	}
	if (enemy->DroppedItem())						// Checks to see if the enemy dropped an item
	{
		Item* item = Items->GetItem(enemy->Token());
		worldItems.push_back(item);
	}

	fightDisplay->ClearAll();
}

Battle::~Battle()
{
	free(Display);
}
