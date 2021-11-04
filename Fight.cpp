//============================================================================================================
//	Backbone of the game is this fight function. It basically just does some simple math calculations
//	Did you hit the guy, how much damage it did. I gave it it's own .CPP cuz it keeps growing with the game
//
//============================================================================================================

#include "World.h"
#include "Creature.h"
#include "Enemies.h"
#include "Item.h"
#include "Location.h"

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY


void World::Fight(Player *player, Creature *enemy, vector<Item*> &playerInventory,vector<Item*> &worldItems,vector<Magic*> &spells,string map)
{
	COORD CursPos;					// Mystical Cursor Position
	string Ename = enemy->GetName();	// Name of the enemy
	int choice;						// Um, choice?
	int Evd;						// An Evade variable
	int Damage;						// A Damage Variable
	int D2;							// 2nd Damage Variable for Xtra damage
	int StrMod;						// Strength Modifier variable
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

	Display->clear();
/*==================================================================
	This calls some music to play for the fights, dynamic according
	to the different enemies. How awesome is that?
===================================================================*/
	player->PlayMusic(enemy->GetMusic());


	text("You have been attacked by a ",13,11, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text(enemy->GetName(),41,11,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("",13,12,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("pause");
	Display->clear();

	if(enemy->bant)					// Check if enemy will talk before the fight
		enemy->Banter();				// Enemy's prefight speech

	while(enemy->GetHitPoints() > 0 && player->GetCurrentHitPoints() > 0 && !run)
	{
	// Initiallize all these boolean variables ot false
		bSel = false;
		bEsc = false;
		bLeave = false;
		fight = false;
		magic = false;
		item = false;
		run  = false;
		pass = false;
		
		player->DisplayInfo();					// Display player info
		enemy->DisplayInfo();				// Display enemy info, this will probably be phased out, or tweaked

		if(player->GetIsAsleep())			// Checks if player is asleep
		{
			R = rand()% 100 + 1;	
			if(R < 50)				// 50% chance of waking up. NOTE: Maybe make that enemy specific %
			{
				player->SetIsAsleep(false);							
				text("You awake from sleep!",13,11,white);
				text("",79,23,white);
				Sleep(player->GetIsAsleep());
				text("                     ",13,11,white);
			}
		}
		if(player->GetIsAsleep())			// Checks if you're still asleep after your chance to wake
		{
			text("You are asleep.",13,11,white);
			text("",79,23,white);
			Sleep(player->GetPauseDuration());
			text("                                          ",13,11,white);
		}			
		else 
		{
			text("           ",1,11,white);
			text("           ",1,12,white);
			text("           ",1,13,white);
			text("                                                                 ",13,11,FOREGROUND_BLUE);
			text("/---------\\",1,14,ftext);
			text("|  Attack |",1,15,ftext);
			text("|  Magic  |",1,16,ftext);
			text("|  Item   |",1,17,ftext);
			text("|  Run    |",1,18,ftext);
			text("\\---------/",1,19,ftext);

			

			CursPos.X = 2;
			CursPos.Y = 15;

			DrawCursor(CursPos,ftext,26);
			do
			{
				if(MoveCursor(CursPos,bSel,bEsc,15,18))
				{
					DrawCursor(CursPos,ftext,26);
				}
				text("", 79, 23, ftext);
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
				player->DisplayInfo();						// Display player info
				enemy->DisplayInfo();					// Display enemy info NOTE: TEMPORARY or something anyway
				//----------------------------------------------------------------->|Check for hit!
				Evd = rand()%100 + 1;
				if(Evd <= enemy->GetEvade())
				{
					text("The enemy has dodged your attack!",13,11,white);
					Sleep(player->GetPauseDuration());
				}
				else //--------------------------------------------------------->|Damage applications
				{
					Damage = rand()% weap->GetDamage() + weap->GetDamageModifier();//--->|Weapon's Damage
					StrMod = rand()% (player->GetStrength()/2) + 2;//-------------------->|Strength modifier
					Damage += StrMod;
					if(weap->GetHitsTwice())//-------------------------------------->|Xtra hit check
					{
						D2 = rand()% weap->GetDamage() + weap->GetDamageModifier();
						StrMod = rand()% (player->GetStrength()/2) + 2;
						D2 += StrMod;
						text("2 Hits!!",13,11,white);
						Sleep(player->GetPauseDuration());
						Damage += D2;
					}
					//----------------------->Checks for weakness in the monsters. Double Damage is pretty cool
					if(weap->GetAttribute1() == enemy->GetWeakness() || weap->GetAttribute2() == enemy->GetWeakness())
						bWeak = true;
					//---------------------------------------------------------->Checks if the weapon is magical
					if(weap->GetAttribute1() == "magical")
						bMagical = true;
					//----------------->|If the creature is weak against the player's weapon, then double damage.
					if(bWeak)
						Damage *= 2;
					//----------------------------------------------------->|Damage to the undead is cut in half. 
					if(!bWeak && !bMagical && enemy->GetType()== "undead")
						Damage /= 2;
					//PlaySound("sword1.wav",NULL,SND_FILENAME | SND_ASYNC);


					//----------------------------------------------------->|Some enemies have good defenses				
					Damage = Damage - enemy->GetDefense();
					if(Damage < 1)
						Damage = 1;//-------------------------------------->|But damage is always at least 1.
					enemy->SetHitPoints(enemy->GetHitPoints() - Damage);				
					text("Your Damage: ",13,11,white);
					cout << Damage;
					enemy->DisplayDamage(Damage);
					if(weap->HasLifeSteal())
					{
						player->SetHitPoints(player->GetCurrentHitPoints() + Damage / 2);
						text("Life Gained:     ",13,11,white);
						cout << Damage / 2;
						enemy->DisplayDamage(Damage / 2);
					}				
				}
			}
	//===========================================================================================================
	//	This is the code if the player wants to use magic.
	//===========================================================================================================
			if(magic)
			{
				if(!player->HasLearnedSpells())
				{
					pass = true;
					text("You have no magic",13,11,white);
					Sleep(player->GetPauseDuration());
					text("                 ",13,11,white);
				}
				else
				{
					InFightMagicMenu(player,enemy,spells,bEsc);				
					if(bEsc)
						pass = true;
				}
			}

	//===========================================================================================================
	//	This is the code if the player uses an item.
	//===========================================================================================================

			if(item)
			{			
				UseItem(player,worldItems,playerInventory,bFight,bLeave,map);
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
				Evd = rand()%100+1;
				if(Evd > enemy->GetEvade())
				{
					run = true;
					text("You ran away",13,11,red);
					PlaySound("run.wav",NULL, SND_FILENAME | SND_ASYNC);
					Sleep(player->GetPauseDuration());	
					Display->clear();
					break;
				}
				else
				{
					text("The enemy thought you should stay!",13,11,red);
					Sleep(player->GetPauseDuration());
					pass = false;
					run  = false;				
				}			
			}
			if(enemy->GetHitPoints() <= 0)
				pass = true;
			if(enemy->GetState() == 2)
			{
				text("The enemy is stunned",13,11,white);
				text("",79,23,white);
				Sleep(player->GetPauseDuration());
				pass = true;
				enemy->SetState(0);
			}
			if(enemy->GetState() == 3)
			{
				Damage = rand()% 10 + 10;
				enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
				text("The enemy takes poison damage: ",13,11,white);
				num(Damage,45,11,red);
				if(enemy->GetHitPoints() <= 0)
					pass = true;
			}
		}
//===========================================================================================================
//		This is where the enemy gets to attack the player. Cuz you know, they do that.
//===========================================================================================================

		if(!pass)
		{			
			Display->clear();
			enemy->DisplayInfo();
			player->DisplayInfo();
			Evd = rand()%100 + 1;
			if(Evd <= player->GetEvade() + arm->GetEvadeModifier() && !player->GetIsAsleep())	// Elaborate equation for evasion
			{
				text("You dodged the enemy attack",13,11,white);
				Sleep(player->GetPauseDuration());
			}
			else
			{
				if(player->GetIsPoisoned())										// Check if player is poisoned
				{
					Damage = rand()% 10 + 1;								// Conjure up some poison damage
					player->SetHitPoints(player->GetCurrentHitPoints() - Damage);						// Incur that damage	
					text("You take poison damage: ",13,11,white);			// Display that damage	
					num(Damage,45,11,red);			
					Sleep(player->GetPauseDuration());
					if(player->GetCurrentHitPoints() < 1)
						break;
				}
				enemy->Attack(player,playerInventory,worldItems,map);							// Enemy attack
				Display->clear();
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
		player->SetMagicStatus(0);						// After a fight state gets set to zero
		player->SetIsPoisoned(false);					// After a fight you are no longer poisoned
		Display->clear();
		player->StopMusic();
		PlaySound("WinBattle.wav",NULL, SND_FILENAME | SND_ASYNC);	
		text("The enemy has been slain",13,11,white);
		Sleep(player->GetPauseDuration());
		Display->clear();
		enemy->Win(player);							// Dynamic enemy win function
/*================================================================
	Here I will put the you beat the bad guy music! which will
	be static I think. Unless you get cooler music from a boss.
==================================================================*/
		while(player->ReachedNextLevel())
		{
			player->IncreaseLevel();						// Player function to go up a level
			//p2->playMusic("Level Up Music");  Don't have level up music yet

			Display->clear();
			text("You have gone up in level!!", 13, 11, FOREGROUND_GREEN);
			text("", 79, 23, white);
			Sleep(player->GetPauseDuration());
		}
		if(enemy->DroppedItem())						// Checks to see if the enemy dropped an item
			worldItems.push_back(enemy->Token(map));	// Drops item on the ground
		Display->clear();
	}
	if(player->GetCurrentHitPoints() <= 0)
	{
		Display->clear();
		text("You have died",13,11,white);
		Sleep(player->GetPauseDuration());
		return;
	}
	if(enemy->GetRunAway())
	{
		Display->clear();
		text("The enemy has run off!!!",13,11,white);
		Sleep(player->GetPauseDuration());
		enemy->SetRunAway(false);
		Display->clear();
	}
/*============================================================
	Here, we put the map music back on. Providing of course
	that we haven't changed musicFilename at all. I hope!
=============================================================*/
	player->PlayMusic(player->GetMusicFilename());
}
