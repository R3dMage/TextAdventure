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


void world::fight(Player *p2, creature *guy, vector<Item*> &pstuff,vector<Item*> &stuff,vector<magik*> &spells,string Map)
{
	COORD CursPos;					// Mystical Cursor Position
	string Ename = guy->getname();	// Name of the enemy
	int choice;						// Um, choice?
	int Evd;						// An Evade variable
	int Damage;						// A Damage Variable
	int D2;							// 2nd Damage Variable for Xtra damage
	int StrMod;						// Strength Modifier variable
	int R = 0;						// R?
	Weapon *weap = p2->GetWeapon(); // Weapon Variable
	Armor *arm = p2->GetArmor();	// Armor Variable
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

	clear();
/*==================================================================
	This calls some music to play for the fights, dynamic according
	to the different enemies. How awesome is that?
===================================================================*/
	p2->PlayMusic(guy->getMusic());


	text("You have been attacked by a ",13,11, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text(guy->getname(),41,11,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("",13,12,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("pause");
	clear();

	if(guy->bant)					// Check if enemy will talk before the fight
		guy->banter();				// Enemy's prefight speech

	while(guy->gethp() > 0 && p2->GetCurrentHitPoints() > 0 && !run)
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
		
		p2->DisplayInfo();					// Display player info
		guy->info();				// Display enemy info, this will probably be phased out, or tweaked

		if(p2->GetIsAsleep())			// Checks if player is asleep
		{
			R = rand()% 100 + 1;	
			if(R < 50)				// 50% chance of waking up. NOTE: Maybe make that enemy specific %
			{
				p2->SetIsAsleep(false);							
				text("You awake from sleep!",13,11,white);
				text("",79,23,white);
				Sleep(p2->GetIsAsleep());
				text("                     ",13,11,white);
			}
		}
		if(p2->GetIsAsleep())			// Checks if you're still asleep after your chance to wake
		{
			text("You are asleep.",13,11,white);
			text("",79,23,white);
			Sleep(p2->GetPauseDuration());
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

			DrawCurs(CursPos,ftext,26);
			do
			{
				if(MoveCurs(CursPos,bSel,bEsc,15,18))
				{
					DrawCurs(CursPos,ftext,26);
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
				p2->DisplayInfo();						// Display player info
				guy->info();					// Display enemy info NOTE: TEMPORARY or something anyway
				//----------------------------------------------------------------->|Check for hit!
				Evd = rand()%100 + 1;
				if(Evd <= guy->getevade())
				{
					text("The enemy has dodged your attack!",13,11,white);
					Sleep(p2->GetPauseDuration());
				}
				else //--------------------------------------------------------->|Damage applications
				{
					Damage = rand()% weap->GetDamage() + weap->GetDamageModifier();//--->|Weapon's Damage
					StrMod = rand()% (p2->GetStrength()/2) + 2;//-------------------->|Strength modifier
					Damage += StrMod;
					if(weap->GetHitsTwice())//-------------------------------------->|Xtra hit check
					{
						D2 = rand()% weap->GetDamage() + weap->GetDamageModifier();
						StrMod = rand()% (p2->GetStrength()/2) + 2;
						D2 += StrMod;
						text("2 Hits!!",13,11,white);
						Sleep(p2->GetPauseDuration());
						Damage += D2;
					}
					//----------------------->Checks for weakness in the monsters. Double Damage is pretty cool
					if(weap->GetAttribute1() == guy->getweakness() || weap->GetAttribute2() == guy->getweakness())
						bWeak = true;
					//---------------------------------------------------------->Checks if the weapon is magical
					if(weap->GetAttribute1() == "magical")
						bMagical = true;
					//----------------->|If the creature is weak against the player's weapon, then double damage.
					if(bWeak)
						Damage *= 2;
					//----------------------------------------------------->|Damage to the undead is cut in half. 
					if(!bWeak && !bMagical && guy->gettype()== "undead")
						Damage /= 2;
					//PlaySound("sword1.wav",NULL,SND_FILENAME | SND_ASYNC);


					//----------------------------------------------------->|Some enemies have good defenses				
					Damage = Damage - guy->getdef();
					if(Damage < 1)
						Damage = 1;//-------------------------------------->|But damage is always at least 1.
					guy->sethp(guy->gethp() - Damage);				
					text("Your Damage: ",13,11,white);
					cout << Damage;
					guy->dam(Damage);
					if(weap->HasLifeSteal())
					{
						p2->SetHitPoints(p2->GetCurrentHitPoints() + Damage / 2);
						text("Life Gained:     ",13,11,white);
						cout << Damage / 2;
						guy->dam(Damage / 2);
					}				
				}
			}
	//===========================================================================================================
	//	This is the code if the player wants to use magic.
	//===========================================================================================================
			if(magic)
			{
				if(!p2->HasLearnedSpells())
				{
					pass = true;
					text("You have no magic",13,11,white);
					Sleep(p2->GetPauseDuration());
					text("                 ",13,11,white);
				}
				else
				{
					fmagic(p2,guy,spells,bEsc);				
					if(bEsc)
						pass = true;
				}
			}

	//===========================================================================================================
	//	This is the code if the player uses an item.
	//===========================================================================================================

			if(item)
			{			
				useItem(p2,stuff,pstuff,bFight,bLeave,Map);
				if(bLeave)
					pass = true;
				arm = p2->GetArmor();
				weap = p2->GetWeapon();
			}
	/*============================================================================================
		Should the player try to run, we go here
	============================================================================================*/
			if(run)
			{
				Evd = rand()%100+1;
				if(Evd > guy->getevade())
				{
					run = true;
					text("You ran away",13,11,red);
					PlaySound("run.wav",NULL, SND_FILENAME | SND_ASYNC);
					Sleep(p2->GetPauseDuration());	
					clear();
					break;
				}
				else
				{
					text("The enemy thought you should stay!",13,11,red);
					Sleep(p2->GetPauseDuration());
					pass = false;
					run  = false;				
				}			
			}
			if(guy->gethp() <= 0)
				pass = true;
			if(guy->getstate() == 2)
			{
				text("The enemy is stunned",13,11,white);
				text("",79,23,white);
				Sleep(p2->GetPauseDuration());
				pass = true;
				guy->setstate(0);
			}
			if(guy->getstate() == 3)
			{
				Damage = rand()% 10 + 10;
				guy->sethp(guy->gethp() - Damage);
				text("The enemy takes poison damage: ",13,11,white);
				num(Damage,45,11,red);
				if(guy->gethp() <= 0)
					pass = true;
			}
		}
//===========================================================================================================
//		This is where the enemy gets to attack the player. Cuz you know, they do that.
//===========================================================================================================

		if(!pass)
		{			
			clear();
			guy->info();
			p2->DisplayInfo();
			Evd = rand()%100 + 1;
			if(Evd <= p2->GetEvade() + arm->GetEvadeModifier() && !p2->GetIsAsleep())	// Elaborate equation for evasion
			{
				text("You dodged the enemy attack",13,11,white);
				Sleep(p2->GetPauseDuration());
			}
			else
			{
				if(p2->GetIsPoisoned())										// Check if player is poisoned
				{
					Damage = rand()% 10 + 1;								// Conjure up some poison damage
					p2->SetHitPoints(p2->GetCurrentHitPoints() - Damage);						// Incur that damage	
					text("You take poison damage: ",13,11,white);			// Display that damage	
					num(Damage,45,11,red);			
					Sleep(p2->GetPauseDuration());
					if(p2->GetCurrentHitPoints() < 1)
						break;
				}
				guy->attack(p2,pstuff,stuff,Map);							// Enemy attack			
			}
		}
		if(guy->getrunAway())											// Check to see if the enemy will run away
			break;

	}//===========================================[End while HP > 0
//=============================================================================================================
//										This is where the fighting ends
//		Then we check for level ups and junk.
//=============================================================================================================
	if(guy->gethp() <= 0)
	{
		p2->SetMagicStatus(0);						// After a fight state gets set to zero
		p2->SetIsPoisoned(false);					// After a fight you are no longer poisoned
		clear();
		p2->StopMusic();
		PlaySound("WinBattle.wav",NULL, SND_FILENAME | SND_ASYNC);	
		text("The enemy has been slain",13,11,white);
		Sleep(p2->GetPauseDuration());
		guy->win(p2);							// Dynamic enemy win function
/*================================================================
	Here I will put the you beat the bad guy music! which will
	be static I think. Unless you get cooler music from a boss.
==================================================================*/
		while(p2->ReachedNextLevel())
		{
			p2->IncreaseLevel();						// Player function to go up a level
			//p2->playMusic("Level Up Music");  Don't have level up music yet
		}
		if(guy->dropItem())						// Checks to see if the enemy dropped an item
			stuff.push_back(guy->token(Map));	// Drops item on the ground
		clear();
	}
	if(p2->GetCurrentHitPoints() <= 0)
	{
		clear();
		text("You have died",13,11,white);
		Sleep(p2->GetPauseDuration());
		return;
	}
	if(guy->getrunAway())
	{
		clear();
		text("The enemy has run off!!!",13,11,white);
		Sleep(p2->GetPauseDuration());
		guy->setrunAway(false);
		clear();
	}
/*============================================================
	Here, we put the map music back on. Providing of course
	that we haven't changed musicFilename at all. I hope!
=============================================================*/
	p2->PlayMusic(p2->GetMusicFilename());
}
