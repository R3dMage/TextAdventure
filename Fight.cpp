//============================================================================================================
//	Backbone of the game is this fight function. It basically just does some simple math calculations
//	Did you hit the guy, how much damage it did. I gave it it's own .CPP cuz it keeps growing with the game
//
//============================================================================================================

#include <sstream>
#include "World.h"
#include "Creature.h"
#include "Enemies.h"
#include "Item.h"
#include "Location.h"
#include "FightDisplay.h"

void World::Fight(Player *player, Creature *enemy, vector<Item*> &playerInventory,vector<Item*> &worldItems,vector<Magic*> &spells,string map)
{
	FightDisplay* fightDisplay = new FightDisplay();
	COORD CursPos;					// Mystical Cursor Position
	string Ename = enemy->GetName();	// Name of the enemy
	int choice;						// Um, choice?
	int Evd;						// An Evade variable
	int Damage;						// A Damage Variable
	int R = 0;						// R?
	Weapon *weap = player->GetWeapon(); // Weapon Variable
	Armor *arm = player->GetArmor();	// Armor Variable
	bool bEsc = false;				// Escape bool for menu
	bool bSel = false;				// Select bool for menu
	bool bLeave = false;			// Leave  bool for menu
	bool bWeak = false;				// Weakness bool for, checking weakness
	bool bMagical = false;			// Magical bool for checking magicalness
	bool pass;						// Bool for passing through code without fighting
	bool fight;						// Used to check if player selected fight
	bool magic;						// Used to check if player selected magic
	bool item;						// Used to check if player selected item
	bool run = false;				// To check if player will run
	bool bFight = true;				// To check if player is in a fight

	fightDisplay->clear();
/*==================================================================
	This calls some music to play for the fights, dynamic according
	to the different enemies. How awesome is that?
===================================================================*/
	player->PlayMusic(enemy->GetMusic().c_str());

	fightDisplay->DisplayAttackAnnouncement(enemy);

	if(enemy->GetHasBanter())						// Check if enemy will talk before the fight
		enemy->Banter();							// Enemy's prefight speech

	while(enemy->GetHitPoints() > 0 && player->GetCurrentHitPoints() > 0 && !run)
	{
		bSel = false;
		bEsc = false;
		bLeave = false;
		fight = false;
		magic = false;
		item = false;
		run  = false;
		pass = false;
		
		fightDisplay->DisplayPlayerInfo(player);	// Display player info
		fightDisplay->DisplayCreatureStatus(enemy); // Display enemy info, this will probably be phased out, or tweaked

		if(player->GetIsAsleep())					// Checks if player is asleep
		{
			R = rand()% 100 + 1;	
			if(R < 50)								// 50% chance of waking up. NOTE: Maybe make that enemy specific %
			{
				player->SetIsAsleep(false);							
				fightDisplay->DisplayMessage("You awake from sleep!", player->GetPauseDuration());
			}
		}
		if(player->GetIsAsleep())					// Checks if you're still asleep after your chance to wake
		{
			fightDisplay->DisplayMessage("You are asleep", player->GetPauseDuration());
		}			
		else 
		{
			CursPos.X = 2;
			CursPos.Y = 15;

			fightDisplay->DisplayFightMenu();

			Menu->DrawCursor(CursPos, ftext, 26);
			do
			{
				if(Menu->MoveCursor(CursPos, bSel, bEsc, 15, 18))
				{
					Menu->DrawCursor(CursPos, ftext, 26);
				}
				// text("", 79, 23, ftext);
			}while(!bSel);

			choice = CursPos.Y;
			switch(choice)
			{
			case 15:
				fight = true;
				break;
			case 16:
				magic = true;
				break;
			case 17:
				item =	true;
				break;
			case 18:
				run =	true;
				break;
			}

	//===========================================================================================================
	//	This is the primary melee fighting code. Pretty straightforward. I hope.
	//===========================================================================================================

			if(fight)
			{
				PlayerAttack(player, fightDisplay, enemy);
			}
	//===========================================================================================================
	//	This is the code if the player wants to use magic.
	//===========================================================================================================
			if(magic)
			{
				if(!player->HasLearnedSpells())
				{
					pass = true;
					fightDisplay->DisplayMessage("You have no magic", player->GetPauseDuration());
				}
				else
				{
					Menu->InFightMagicMenu(player, enemy, spells, bEsc);
					if(bEsc)
						pass = true;
				}
			}

	//===========================================================================================================
	//	This is the code if the player uses an item.
	//===========================================================================================================

			if(item)
			{			
				Menu->UseItem(player, worldItems, playerInventory, bFight, bLeave, map);
				if(bLeave)
					pass = true;
				arm = player->GetArmor();
				weap = player->GetWeapon();
			}
	/*============================================================================================
		Should the player try to run, we go here
	============================================================================================*/
			if(run)
			{
				Evd = rand()% 100 + 1;
				if(Evd > enemy->GetEvade())
				{
					run = true;					
					PlaySound("./data/run.wav",NULL, SND_FILENAME | SND_ASYNC);					
					fightDisplay->DisplayMessage("You ran away", player->GetPauseDuration());
					fightDisplay->clear();
					break;
				}
				else
				{
					fightDisplay->DisplayMessage("The enemy thought you should stay", player->GetPauseDuration());
					pass = false;
					run  = false;				
				}			
			}
			if(enemy->GetHitPoints() <= 0)
				pass = true;
			if(enemy->GetState() == 2)
			{
				fightDisplay->DisplayMessage("The enemy is stunned", player->GetPauseDuration());
				pass = true;
				enemy->SetState(0);
			}
			if(enemy->GetState() == 3)
			{
				Damage = rand()% 10 + 10;
				enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
				fightDisplay->DisplayMessageWithRedNumber("The enemy takes poison damage: ", Damage, player->GetPauseDuration());
				if(enemy->GetHitPoints() <= 0)
					pass = true;
			}
		}
//===========================================================================================================
//		This is where the enemy gets to attack the player. Cuz you know, they do that.
//===========================================================================================================

		if(!pass)
		{			
			fightDisplay->clear();
			fightDisplay->DisplayCreatureStatus(enemy);
			fightDisplay->DisplayPlayerInfo(player);
			Evd = rand()%100 + 1;
			if(Evd <= player->GetEvade() + arm->GetEvadeModifier() && !player->GetIsAsleep())	// Elaborate equation for evasion
			{
				fightDisplay->DisplayMessage("You dodged the enemy attack", player->GetPauseDuration());
			}
			else
			{
				if(player->GetIsPoisoned())										// Check if player is poisoned
				{
					Damage = rand()% 10 + 1;								// Conjure up some poison damage
					player->SetHitPoints(player->GetCurrentHitPoints() - Damage);						// Incur that damage	
					fightDisplay->DisplayMessageWithRedNumber("You take poison damage: ", Damage, player->GetPauseDuration());
					if(player->GetCurrentHitPoints() < 1)
						break;
				}
				enemy->Attack(player, fightDisplay);							// Enemy attack
				fightDisplay->DisplayPlayerInfo(player);
				fightDisplay->clear();
			}
		}
		if(enemy->GetRunAway())											// Check to see if the enemy will run away
			break;

	}//===========================================[End while HP > 0
//=============================================================================================================
//										This is where the fighting ends
//		Then we check for level ups and junk.
//=============================================================================================================
	if(enemy->GetHitPoints() <= 0)
	{
		Win(fightDisplay, player, enemy, worldItems, map);
	}

	if(player->GetCurrentHitPoints() <= 0)
	{
		fightDisplay->clear();
		fightDisplay->DisplayMessage("You have died", player->GetPauseDuration());
		return;
	}

	if(enemy->GetRunAway())
	{
		fightDisplay->clear();
		fightDisplay->DisplayMessage("The enemy has run off!!!", player->GetPauseDuration());
		enemy->SetRunAway(false);
		fightDisplay->clear();
	}
/*============================================================
	Here, we put the map music back on. Providing of course
	that we haven't changed musicFilename at all. I hope!
=============================================================*/
	player->PlayMusic(player->GetMusicFilename());
}

void World::PlayerAttack(Player* player, FightDisplay* fightDisplay, Creature* enemy)
{
	fightDisplay->DisplayPlayerInfo(player);						// Display player info
	fightDisplay->DisplayCreatureStatus(enemy);	// Display enemy info NOTE: TEMPORARY or something anyway
												//----------------------------------------------------------------->|Check for hit!
	int Evd = rand() % 100 + 1;
	if (Evd <= enemy->GetEvade())
	{
		fightDisplay->DisplayMessage("The enemy has dodged your attack!", player->GetPauseDuration());
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
		fightDisplay->DisplayMessage("2 Hits!!", player->GetPauseDuration());
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
	fightDisplay->DisplayMessage(messageStream.str(), 0);
	fightDisplay->DisplayDamage(Damage);
	if (weap->HasLifeSteal())
	{
		player->SetHitPoints(player->GetCurrentHitPoints() + Damage / 2);
		messageStream.str(string());
		messageStream << "Life Gained:    " << Damage / 2;
		fightDisplay->DisplayMessage(messageStream.str(), 0);
		fightDisplay->DisplayDamage(Damage / 2);
	}
	
}

void World::Win(FightDisplay* fightDisplay, Player* player, Creature* enemy, vector<Item*>& worldItems, string map)
{
	player->SetMagicStatus(0);						// After a fight state gets set to zero
	player->SetIsPoisoned(false);					// After a fight you are no longer poisoned
	fightDisplay->clear();
	player->StopMusic();
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
		
	fightDisplay->clear();
}