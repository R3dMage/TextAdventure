#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

#include "World.h"
#include "Enemies.h"
#include "Location.h"
#include "SaveLoadGame.h"
#include "ArmoryShop.h"
#include "MagicShop.h"
#include "Lodging.h"
#include "PawnShop.h"
#include "NpcCreator.h"

World::World(GameDisplay* gameDisplay, ItemRepository* items, MusicPlayer* musicPlayer, VirtualMap* virtualMap, GameSettings* gameSettings)
{
	Display = gameDisplay;
	Items = items;
	Music = musicPlayer;
	CurrentMap = virtualMap;
	Settings = gameSettings;
	GameSaver = new SaveLoadGame(Items, Display);
	Menu = new MainMenuSystem(Display, GameSaver, Items, musicPlayer, gameSettings);
	GamePlots = new Plots(Display);
	Fight = new Battle(Menu, new FightDisplay(gameSettings), Items, musicPlayer);
	MagicProvider = new PlayerMagicProvider(Display);
}

World::~World()
{
	delete GameSaver;
	delete Menu;
	delete GamePlots;
	delete Fight;
	delete MagicProvider;
}

void World::StartGame()
{
	Player player;
	ifstream fin;
	string filename;
	string temp;
	string map = "valesh";
	char name[255];
	bool load = false;

	cout << "Enter your name: ";
	cin.get(name, 10);
	player.SetName(name);
	filename = player.GetName() + ".svg";

	fin.open(filename.c_str());
	fin >> temp;
	fin.close();

	if (temp != "Name:")
	{
		load = false;
		player.SetArmor(Items->GetArmor("Clothes"));
		player.SetWeapon(Items->GetWeapon("Dagger"));
		Display->DisplayPlayerStatus(&player);
		system("cls");
	}
	if (temp == "Name:")
		load = true;

	string cheat = "rex";
	if (player.GetName() == cheat.c_str())
	{
		map = "icefield1";
		//p.setelf(1);
		//p.setbspells(true);
		player.SetGold(5000);
		//p.setmka(50);
		player.SetMaxHitPoints(500);
		player.SetHitPoints(500);
		player.SetKa(50);
		//p.setweapon(loadWeapon("DeathSword"));
		//p.setarmor(loadArmor("Hvy.Chain"));
	}

	Locations(map, &player, load);
}

void World::Locations(string map, Player *player, bool load)
{
	unsigned int i;
	int time = 0;
	int choice;
	int playerPositionIndex=0;
	COORD cursorPosition;

	string oldMap = map;

	bool selectionWasMade;
	bool escapeWasPressed;

//==============================================================================================================
//		These are the vectors that are used throughout the game to maintain inventory, items on the ground
// locations on the virtual maps in memory, AND what magic spells the character has.
//===============================================================================================================

	vector< Creature* > monk(0);					//This is a seperate vector for THE monk.
	vector< Item* > worldItems(0);					//Globals will contain ALL the items in the world
	vector< Item* > playerInventory(0);				//inv is the players inventory
	vector< Creature* > encounter(0);				//encounter holds all the enemies on a certain map
	vector<Magic*> spells(0);						//Magik will hold all the spells granted to the player

//===========================================================================================================
//  This sets up the items in their starting places for the player to find. It uses the if(load) to prevent
// them from being loaded into their places again before they are loaded from the players save file.
//===========================================================================================================
	if(!load)
	{
//==============================================================================================================
//			This section of code creates the items that will be placed throughout the game
//==============================================================================================================

		Item *vial;
		vial = new Item;
		vial->SetName("Empty Vial");
		vial->SetMapName("forest1");
		vial->SetPositionX(5);
		vial->SetPositionY(5);
		vial->SetKeep(true);

		Item *horseshoe;
		horseshoe = new Item;
		horseshoe->SetName("Horseshoe");
		horseshoe->SetMapName("field");
		horseshoe->SetPositionX(5);
		horseshoe->SetPositionY(5);
		horseshoe->SetKeep(true);
//==============================================================================================================
//			This section of code pushes them into their proper vectors =)
//==============================================================================================================

		playerInventory.push_back(Items->GetItem("Potion"));
		playerInventory.push_back(Items->GetItem("Potion"));
		worldItems.push_back(vial);
		worldItems.push_back(horseshoe);

		monk.push_back(new Monk);						//This puts in THE only monk in the game.

		GamePlots->DisplayIntro();
	}


	if(load)
	{
		GameSaver->LoadGame(player, worldItems, playerInventory, spells, map, player->GetName());
	}

//==============================================================================================================
//		A slight cheat to test out how the spells work real quick. You can change them up however you like =)
//==============================================================================================================
	
	if(player->GetName() == "rex" && !load)
	{
		//p2->setInvis(true);
		player->SetHasSpells(true);
		spells.push_back(new MinorHeal);
		spells.push_back(new MajorHeal);
		spells.push_back(new BriarBush);
		spells.push_back(new Blizzard);
		spells.push_back(new PerfectStorm);
		map = "island1";
		player->SetMaxKa(100);
		player->SetKa(100);
		player->SetPositionX(5);
		player->SetPositionY(9);
		playerInventory.push_back(Items->GetItem("+1 Scimitar"));
		playerInventory.push_back(Items->GetItem("DeathSword"));
		playerInventory.push_back(Items->GetItem("RedMail"));
	}

    Display->ClearAll();

	CurrentMap = new VirtualMap(map);

	NpcCreator::SetupNpcs(encounter, map, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), player->PlotEventStates, player->RaceReactions);

	Music->SetMusicFilename(CurrentMap->GetMusicFileName());
	
	if(!player->PlotEventStates.Monk)
		monk.push_back(new Monk);					//This puts in THE only monk in the game.
	else
		monk.push_back(new Fly);

	while(player->GetCurrentHitPoints() > 0)			//This is THE while loop for the game
	{
		monk[0]->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());

		selectionWasMade   = false;
		escapeWasPressed   = false; 		

//======================================================================================================
//					Code for loading up the descriptions, Map Changes, Plots, and Shops!
//Feb.2005 Added virtual map so as not to access the file EVERY time you move
//======================================================================================================
		
		PlayerEnvironment surroundings = CurrentMap->GetPlayerEnvironment(player->GetPositionX(), player->GetPositionY());
		Location* playerLocation = surroundings.PlayerLocation;
		
		if(surroundings.PlayerLocation->GetIsMapChange())
		{
			player->SetPositionX(surroundings.PlayerLocation->GetNeoX());
			player->SetPositionY(surroundings.PlayerLocation->GetNeoY());

			map = surroundings.PlayerLocation->GetMapChangeName();

			CurrentMap->LoadMap(map);
			NpcCreator::SetupNpcs(encounter, map, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), player->PlotEventStates, player->RaceReactions);
			
			Music->SetMusicFilename(CurrentMap->GetMusicFileName());
			
			surroundings = CurrentMap->GetPlayerEnvironment(player->GetPositionX(), player->GetPositionY());
		}

		if(surroundings.PlayerLocation->GetHasPlot())
		{
			Display->ClearAll();
			Display->DisplayPlayerInfo(player);
			
			GamePlots->DisplayPlot(map, surroundings.PlayerLocation->GetPlotText());
		}
		
		if(surroundings.PlayerLocation->GetIsShop())
		{
			string ShopType = surroundings.PlayerLocation->GetShopName();
			if (ShopType == "armory")
			{
				ArmoryShop armory(Display, Menu, Items, map);
				armory.ShowShop(player, playerInventory);
			}
			
			if (ShopType == "inn")
			{
				Lodging lodging(Display, Menu);
				lodging.Enter(player, map);
			}
			
			if (ShopType == "magic")
			{
				MagicShop magicShop(Display, Menu, Items, map);
				magicShop.ShowShop(player, playerInventory);
			}
			
			if (ShopType == "buy")
			{
				PawnShop pawnShop(Display, Menu);
				pawnShop.Enter(player, playerInventory, map);
			}
		}
//============================================================================================================= 
//									Puts location descriptions on the screen!
//=============================================================================================================
		Display->DisplayLocation(&surroundings);
		Display->DisplayPlayerInfo(player);

//=============================================================================================================
//		Debugging: displays mapname, Vmap#, and number of encounters in the map
// Adding Map size 5/16/05.
// Rem. Out encounter size and # of squares for beta version 6/14/05
//=============================================================================================================
		Display->DisplayText("          ",2,22,white);
		Display->DisplayNumber(CurrentMap->GetMaxX(), 2, 22, white);
		Display->DisplayText("x",4,22,white);
		Display->DisplayNumber(CurrentMap->GetMaxY(), 5, 22, white);
		Display->DisplayText("          ",2,19,white);
		Display->DisplayText(map,2,19,yellow);			
//		Display->num(T,2,20,yellow);			T = 0;
//		Display->num(static_cast<int>(encounter.size()),2,21,blue);
//=============================================================================================================
//								 Code that displays enemies grid locations
// Rem. out Enemy grid locations 6/14/05
//=============================================================================================================
		//int k = 0;
		//for(i=0;i < encounter.size() && i < 20;i++)
		//{
		//	int j = 16;
		//	Display->text("X: ",13,8,white);
		//	Display->text("Y: ",13,9,white);
		//	Display->num(encounter[i]->getX(),j+i+k,8,white);
		//	Display->num(encounter[i]->getY(),j+i+k,9,white);
		//	k += 2;
		//}
//===========================================================================================================
//											Compass box display code
// The letters are a darker color when the player is on the edge of a map. To let the player know that they 
// can't go that way anymore.
//===========================================================================================================

		cursorPosition.X = 2;
		cursorPosition.Y = 12;

		Display->DisplayCompass(player->GetPositionX(), player->GetPositionY(), CurrentMap->GetMaxX(), CurrentMap->GetMaxY());

//================================================================================================================

//		This function clears the items that WERE on the ground
		Display->ClearTopBelow(2);

//		Function that displays what's on the ground =)
		Display->DisplayItemsOnGround(worldItems,map,player->GetPositionX(),player->GetPositionY());


		while(!selectionWasMade)
		{
			if(load)
				load = false;
			//Display->num(time,15,5,ftext);
			Walk(selectionWasMade, escapeWasPressed, player, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), time);
			//time++;
		}
		selectionWasMade = false;

        if(escapeWasPressed)//=================>  This is the code that calls the player menu for advanced fun
		{
			//clear();                    For smooth look remarked out on 2/15/06
			Menu->HandleMainPlayerMenu(player, spells, worldItems, playerInventory, map);
			if(player->GetIsLoaded())
			{
				CurrentMap->LoadMap(map);
				NpcCreator::SetupNpcs(encounter, map, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), player->PlotEventStates, player->RaceReactions);
				
				Music->SetMusicFilename(CurrentMap->GetMusicFileName());
				
				player->SetIsLoaded(false);
			}
			choice = 0;
		}
//=======[Function to check, and change plots]======================		
		GamePlots->Check(&player->PlotEventStates, map, player->GetPositionX(), player->GetPositionY());

//===============================================================================================
//							This section will be checking player location
//	If the player hasn't defeated the 4 priests, then he can't enter the temple sanctum 
//  So, if the player tries, it warps them away! Or at least outside the temple. Maybe later it 
//  will check other places, I don't know yet 6/12/05.
//===============================================================================================
		
		if(map == "templehall" && player->GetPositionX() == 1 && player->GetPositionY() == 10)
		{
			Display->DisplayText("You are not yet powerful enough to enter here.",13,11,white);
			Sleep(3000);
			map = "field";
			player->SetPositionX(17);
			player->SetPositionY(1);
			
			CurrentMap->LoadMap(map);
			NpcCreator::SetupNpcs(encounter, map, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), player->PlotEventStates, player->RaceReactions);
			
			Music->SetMusicFilename(CurrentMap->GetMusicFileName());
		}

//=================================================================================================================
//											Enemy Encounter Code
//Cycles through encounter[] checking if any encounter are at the players current location.
//==================================================================================================================

		if (!player->GetIsLoaded())//								This makes sure that you're not attacked when you load the game.
		{
			for (i = 0; i < encounter.size(); i++)
			{
				Creature* creature = encounter[i];

				if (player->GetPositionX() == creature->GetX() && player->GetPositionY() == creature->GetY() && creature->GetHitPoints() != 0)
				{
					if (!creature->GetTalkTo())
						Fight->Engage(player, creature, playerInventory, worldItems, spells, map);
					else
					{						
						Display->DisplayPlayerInfo(player);
						Greeting greeting = creature->GetGreeting(player);

						if (Menu->TalkTo(&greeting, Settings->GetPauseDuration()))
							Fight->Engage(player, creature, playerInventory, worldItems, spells, map);
					}
					if (creature->GetHitPoints() <= 0)
					{
						worldItems.push_back(creature->Body(map));		//Drops enemy unique item if the enemy is dead
					}
					MagicProvider->CheckMagic(player, spells);

//===========================================================================================================
//					Replenishes the dead enemies, so we don't run out of them on a map
//Moved to inside the for loop 6/14/05
//===========================================================================================================
					for (i = 0; i < encounter.size();i++)
					{
						if (creature->GetHitPoints() <= 0 && !creature->GetDontMove())
						{
							ReplenishEnemy(encounter, i);
							encounter[encounter.size()-1]->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
						}
					}
					if (monk[0]->GetHitPoints() <= 0)
					{
						ReplenishEnemy(monk, i);
						monk[monk.size()-1]->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
					}

				}
			}
		}
		if(player->GetIsLoaded())
			player->SetIsLoaded(false);

		if(monk[0]->GetX() == player->GetPositionX() && monk[0]->GetY() == player->GetPositionY() && map == "field2")
			Fight->Engage(player, monk[0], playerInventory, worldItems, spells, map);


//===============================================================================================
//									Function for moving enemies around on the map
//===============================================================================================

		Move(encounter, CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
	}// -------------------------------->End Walking Loop
}
//===================================================================================================================
//                                              End Function
//===================================================================================================================


//==========================================================================================================
//	Function for walking around the map. It returns true if you've moved (that is pressed a movement key)
//	to load up the description of the place you've moved to. Also it takes the bEsc variable to see if you
//  hit Esc key to enter the menu.
//==========================================================================================================
bool World::Walk(bool &selectionWasMade, bool &escapeWasPressed, Player *player,int Xmax, int Ymax, int &T)
{
	T++;
	INPUT_RECORD InputRecord;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		// If you hit up, go up! But not if your as up as you can go on the map.
		{
			player->SetPositionY(player->GetPositionY()+1);
			if(player->GetPositionY() > Ymax)
				player->SetPositionY(Ymax);
			selectionWasMade = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		// If you hit down, go down! The Player Class prevents Y from being 0.
		{
			player->SetPositionY(player->GetPositionY()-1);
			selectionWasMade = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
		// If you hit right, go right! But not if your as right as you can go on the map.
		{
			player->SetPositionX(player->GetPositionX()+1);
			if(player->GetPositionX() > Xmax)
				player->SetPositionX(Xmax);
			selectionWasMade = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
		// If you hit left, go left! The player class prevents X from being 0.
		{
			player->SetPositionX(player->GetPositionX()-1);
			selectionWasMade = true;
		}
		
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		// This changes bEsc, so that the main loop knows to go into the menu function
		{
			escapeWasPressed = true;
			selectionWasMade = true;
		}
	}	
	Display->DisplayText(" ", 79, 23,white);
return false;	
}

//==========================================================================================================
//	Function for replenishing enemies
//==========================================================================================================
void World::ReplenishEnemy(vector<Creature*> &enemies, int index)
{
	Creature *temp;

	temp = enemies[enemies.size()-1];				//Saves off the last in the vector
	enemies[enemies.size()-1] = enemies[index];		//Moves the killed enemy to the last slot
	enemies[index] = temp;							//Moves saved last into the slot of slain enemy
	temp = enemies[enemies.size()-1];				//Saves off slain enemy to use its replenish function
	enemies.pop_back();
	enemies.push_back(temp->Replenish());			//Dynamically replenishes the enemy with a new one!

//  Well not too dynamically. It's all taken care of by the classes replenish funcion which just returns a new
//  Member of its own class. What fun.
}

//==========================================================================================================
//	This function was designed to check the number of items in inventory. If you were going to go over the 
//	limit of 10 it would tell you you're out of room. Not yet implemented 5/11/05
//==========================================================================================================
bool World::Overflow(int size)
{
	if(size >= 10)
	{
		Display->DisplayText("You do not have enough room!",13,12,white);
		Sleep(3000);
		return true;
	}
	else
		return false;
}

//==========================================================================================================
//	This function runs through the vector of creatures, moving them around the map in a random fashion
//  5/10/05
//==========================================================================================================
void World::Move(vector<Creature*> &encounter,int Xmax, int Ymax)
{
	int random;
	unsigned int i;
	for(i = 0; i < encounter.size(); i++)
		{
			random = rand()% 4 + 1;
			Creature* creature = encounter[i];

			if (creature->GetDontMove())
				continue;

			switch(random)
			{
			case 1:
				creature->SetX(creature->GetX() + 1);
				if(creature->GetX() > Xmax)
					creature->SetX(Xmax);
				break;
			case 2:
				creature->SetX(creature->GetX() - 1);
				break;
			case 3:
				creature->SetY(creature->GetY() + 1);
				if(creature->GetY() > Ymax)
					creature->SetY(Ymax);
				break;
			case 4:
				creature->SetY(creature->GetY() - 1);
				break;
			default:
				break;
			}
		}
}