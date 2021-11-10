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

World::World(GameDisplay* gameDisplay, ItemRepository* items)
{
	Display = gameDisplay;
	Items = items;
	GameSaver = new SaveLoadGame(Items, Display);
	Menu = new MainMenuSystem(Display, GameSaver, Items);
	GamePlots = new Plots(Display);
	Fight = new Battle(Menu, new FightDisplay(), Items);
}

World::~World()
{
	free(Display);
	free(GameSaver);
	free(Menu);
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
	int Xmax = 0;
	int Ymax = 0;
	int time = 0;
	int choice;
	int total;
	int playerPositionIndex=0;
	COORD cursorPosition;

	char *musicFileName = "town.mp3";
    char *mapMusic = "town.mp3";

	string description;
	string line1;
	string line2;
	string line3;
	string summary;
	string szHolder;
	string oldMap = map;
	string MapName;
	string ShopType;
	string szPlot;

	string north;
	string south;
	string east;
	string west;

	bool selectionWasMade;
	bool escapeWasPressed;
	bool bTown = false;

//==============================================================================================================
//		These are the vectors that are used throughout the game to maintain inventory, items on the ground
// locations on the virtual maps in memory, AND what magic spells the character has.
//===============================================================================================================

	vector< Creature* > monk(0);					//This is a seperate vector for THE monk.


	vector< Item* > worldItems(0);					//Globals will contain ALL the items in the world
	vector< Item* > playerInventory(0);				//inv is the players inventory
	vector< Creature* > encounter(0);				//encounter holds all the enemies on a certain map
	vector< Location* > mapLocations(0);			//Vmap holds the Map in memory, so no running around
													//taking up time looking in map files. Well we look once. Then keep it in memory
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

		Intro();									//Calls the games intro
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

	ifstream fin;									//fin is what I use as an ifstream operator
	MapName = "./data/" + map + ".tgm";				//This adds the extensions we need to access Map Files
	fin.open(MapName.c_str());
	if(fin.fail())
	{
		Display->DisplayText("ERROR LOADING MAP",13,11,FOREGROUND_RED);	//Errors that tell you what went wrong are useful
		system("pause");
		exit(0);
	}
	fin.close();
	LoadMap(mapLocations,MapName,Xmax,Ymax,bTown);		//This function loads all the map places into the V(irtual)map in memory
	SetupNcps(encounter,map,Xmax,Ymax,player->PlotEventStates,player->RaceReactions,musicFileName);	//This function sets up the enemies according to the map
	if(MusicNameComparer(musicFileName,mapMusic))
		mapMusic = musicFileName;
	SetMusic(mapMusic,player);


	while(player->GetCurrentHitPoints() > 0)			//This is THE while loop for the game
	{
		
		selectionWasMade   = false;
		escapeWasPressed   = false; 

		if(!player->PlotEventStates.Monk)
			monk.push_back(new Monk);					//This puts in THE only monk in the game.
		else
			monk.push_back(new Fly);

		

//======================================================================================================
//					Code for loading up the descriptions, Map Changes, Plots, and Shops!
//Feb.2005 Added virtual map so as not to access the file EVERY time you move
//======================================================================================================
		

		total = Xmax * Ymax;
		playerPositionIndex = (player->GetPositionY() - 1) * Xmax + player->GetPositionX() - 1;
		
		if(mapLocations[playerPositionIndex]->GetIsMapChange())
		{
			player->SetPositionX(mapLocations[playerPositionIndex]->GetNeoX());
			player->SetPositionY(mapLocations[playerPositionIndex]->GetNeoY());

			map = mapLocations[playerPositionIndex]->GetMapChangeName();
			
			MapName = "./data/" + map + ".tgm";
			LoadMap(mapLocations,MapName,Xmax,Ymax,bTown);
			SetupNcps(encounter,map,Xmax,Ymax,player->PlotEventStates,player->RaceReactions,musicFileName);
			
			if(MusicNameComparer(musicFileName,mapMusic))
				mapMusic = musicFileName;
			
			SetMusic(mapMusic,player);

			total = Xmax * Ymax;
			
			playerPositionIndex = (player->GetPositionY()-1) * Xmax + player->GetPositionX() - 1;
		}

		if(mapLocations[playerPositionIndex]->GetHasPlot())
		{
			Display->ClearAll();
			Display->DisplayPlayerInfo(player);
			
			plot(map,mapLocations[playerPositionIndex]->GetPlotText());
		}
		
		if(mapLocations[playerPositionIndex]->GetIsShop())
		{
			ShopType = mapLocations[playerPositionIndex]->GetShopName();
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

		monk[0]->LoadPosition(Xmax,Ymax);

//=============================================================================================================
//										loads up the proper summaries
//=============================================================================================================
		if(playerPositionIndex + Xmax >= total)
			north = "There is no path to follow";
		else
			north = mapLocations[playerPositionIndex + Xmax]->GetSummary();
		if(playerPositionIndex - Xmax < 0)
			south = "There is no path to follow";
		else
			south = mapLocations[playerPositionIndex - Xmax]->GetSummary();
		if(playerPositionIndex % Xmax == Xmax-1)
			east = "There is no path to follow";
		else
			east = mapLocations[playerPositionIndex + 1]->GetSummary();
		if(playerPositionIndex % Xmax == 0)
			west = "There is no path to follow";
		else
			west = mapLocations[playerPositionIndex - 1]->GetSummary();
		description = mapLocations[playerPositionIndex]->GetDescription();

//============================================================================================================= 
//									Puts location descriptions on the screen!
//=============================================================================================================
		Menu->ClearTextBottomRight(11);
		if(description.length() > 65)
		{
			DescriptionDisplay(description,line1,line2,line3);
			Display->DisplayText(line1,13,11,white);
			Display->DisplayText(line2,13,12,white);
			Display->DisplayText(line3,13,13,white);
			line1 = line2 = line3 = "";
		}
		else
		{
			Display->DisplayText(description,13,11,white);
		}

		Display->DisplayText("North",13,15,yellow);		Display->DisplayText(north,19,15,white);
		Display->DisplayText("South",13,16,yellow);		Display->DisplayText(south,19,16,white);
		Display->DisplayText("East",13,17,yellow);		Display->DisplayText(east,18,17,white);
		Display->DisplayText("West",13,18,yellow);		Display->DisplayText(west,18,18,white);

//=============================================================================================================
		if((playerPositionIndex + Xmax) < static_cast<int>(mapLocations.size()) && mapLocations[playerPositionIndex + Xmax]->GetIsMapChange())
			Display->DisplayText("North",13,15,green);
		
		if((playerPositionIndex - Xmax) > 0 && mapLocations[playerPositionIndex - Xmax]->GetIsMapChange())
			Display->DisplayText("South",13,16,green);
		
		if((playerPositionIndex % Xmax != Xmax-1) && (playerPositionIndex + 1 < total) && (mapLocations[playerPositionIndex + 1]->GetIsMapChange()))
			Display->DisplayText("East ",13,17,green);
		
		if((playerPositionIndex % Xmax != 0) && (playerPositionIndex - 1 >= 0) && (mapLocations[playerPositionIndex - 1]->GetIsMapChange()))
			Display->DisplayText("West",13,18,green);

		Display->DisplayPlayerInfo(player);

//=============================================================================================================
//		Debugging: displays mapname, Vmap#, and number of encounters in the map
// Adding Map size 5/16/05.
// Rem. Out encounter size and # of squares for beta version 6/14/05
//=============================================================================================================
		Display->DisplayText("          ",2,22,white);
		Display->DisplayNumber(Xmax,2,22,white);
		Display->DisplayText("x",4,22,white);
		Display->DisplayNumber(Ymax,5,22,white);
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

		Display->DisplayText("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|         |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|    |    |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("| ---+--- |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|    |    |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|         |",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		if(player->GetPositionY() == Ymax)
			Display->DisplayText("N",6,12,FOREGROUND_BLUE);
		else
			Display->DisplayText("N",6,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(player->GetPositionY() == 1)
			Display->DisplayText("S",6,16,FOREGROUND_BLUE);
		else
			Display->DisplayText("S",6,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(player->GetPositionX() == Xmax)
		{
			Display->DisplayText("E",10,14,FOREGROUND_BLUE);
		}
		else		
		{
			Display->DisplayText("E",10,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		
		if(player->GetPositionX() == 1)
		{
			Display->DisplayText("W",2,14,FOREGROUND_BLUE);
		}
		else
		{
			Display->DisplayText("W",2,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
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
			Walk(selectionWasMade,escapeWasPressed,player,Xmax,Ymax,time);
			//time++;
		}
		selectionWasMade = false;

        if(escapeWasPressed)//=================>  This is the code that calls the player menu for advanced fun
				//   Basically, Press Esc for the menu
		{
			//clear();                    For smooth look remarked out on 2/15/06
			Menu->HandleMainMenu(player,spells,worldItems,playerInventory,map);
			if(player->GetIsLoaded())
			{
				MapName = "./data/" + map + ".tgm";						//This adds the extensions we need to access Map Files
				fin.open(MapName.c_str());
				if(fin.fail())
				{
					Display->DisplayText("ERROR LOADING MAP \n\n",13,11,FOREGROUND_RED);
					system("pause");
					exit(0);
				}
				
				LoadMap(mapLocations,MapName,Xmax,Ymax,bTown);
				SetupNcps(encounter,map,Xmax,Ymax,player->PlotEventStates,player->RaceReactions,musicFileName);
				if(MusicNameComparer(musicFileName,mapMusic))
					mapMusic = musicFileName;
				SetMusic(mapMusic,player);
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
			MapName = "./data/" + map + ".tgm";
			LoadMap(mapLocations, MapName, Xmax, Ymax, bTown);
			SetupNcps(encounter, map, Xmax, Ymax, player->PlotEventStates, player->RaceReactions,musicFileName);
			
			if(MusicNameComparer(musicFileName,mapMusic))
				mapMusic = musicFileName;
			
			SetMusic(mapMusic, player);

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
						Fight->Encounter(player, creature, playerInventory, worldItems, spells, map);
					else
					{						
						Display->DisplayPlayerInfo(player);
						Greeting greeting = creature->GetGreeting(player);

						if (Menu->TalkTo(&greeting, player->GetPauseDuration()))
							Fight->Encounter(player, creature, playerInventory, worldItems, spells, map);
					}
					if (creature->GetHitPoints() <= 0)							
					{
						worldItems.push_back(creature->Body(map));		//Drops enemy unique item if the enemy is dead
					}
					CheckMagic(player, spells);
//===========================================================================================================
//					Replenishes the dead enemies, so we don't run out of them on a map
//Moved to inside the for loop 6/14/05
//===========================================================================================================
					for (i = 0; i < encounter.size();i++)
					{
						if (creature->GetHitPoints() <= 0 && !creature->GetDontMove())
						{				
							ReplenishEnemy(encounter, i);							
							encounter[encounter.size()-1]->LoadPosition(Xmax, Ymax);
						}
					}
					if (monk[0]->GetHitPoints() <= 0)
					{
						ReplenishEnemy(monk, i);							
						monk[monk.size()-1]->LoadPosition(Xmax, Ymax);
					}

				}
			}
		}
		if(player->GetIsLoaded())
			player->SetIsLoaded(false);

		if(monk[0]->GetX() == player->GetPositionX() && monk[0]->GetY() == player->GetPositionY() && map == "field2")
			Fight->Encounter(player, monk[0], playerInventory, worldItems, spells, map);


//===============================================================================================
//									Function for moving enemies around on the map
//===============================================================================================

		Move(encounter, Xmax, Ymax);
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
//	This function splits up the description string, into 3 strings of text. Sort of text wrapping.
//==========================================================================================================
void World::DescriptionDisplay(string description, string &first, string &second, string &third)
{
	int i = 0;
	int j = 0;
	j = static_cast<int>(description.size() / 65);
	i = static_cast<int>(description.size() % 65);

	first = description.substr(0,65);
	second = description.substr(65,i);
	
	if(j > 1)	//If there is more than 130 characters in the description
	{
		first = description.substr(0,65);		//Creates a string out of the first 65 characters
		second = description.substr(65,65);	//Creates a string out of the second 65 characters
        third = description.substr(130,i);		//Creates a string out of the third 65 characters
	}
}

void World::LoadMap(vector< Location* > &mapLocations, string &mapFileName,int &Xmax, int &Ymax, bool &isTown)
{
	ifstream fin;
	string szHolder;

	COORD max = {0,0};
	int t;
	int i = 0;

	fin.open(mapFileName.c_str());
	mapLocations.clear();
	fin >> szHolder >> isTown;
	fin >> szHolder >> szHolder;
	while(!fin.eof())
	{		
		mapLocations.push_back(new Location);
		fin >> szHolder; 
		if(szHolder == "P:")
		{
			mapLocations[i]->SetHasPlot(true);
			fin >> szHolder;	mapLocations[i]->SetPlotText(szHolder);
			fin >> szHolder;
		}
		if(szHolder == "MC:")
		{
			mapLocations[i]->SetIsMapChange(true);
			getline(fin,szHolder);
			mapLocations[i]->SetMapChangeName(rotate(szHolder));
			fin >> szHolder;
			fin >> t;
			mapLocations[i]->SetNeoX(t);
			fin >> szHolder;
			fin >> t;
			mapLocations[i]->SetNeoY(t);
			fin >> szHolder;
		}
		if(szHolder == "Shop:")
		{
			mapLocations[i]->SetIsShop(true);
			getline(fin,szHolder);
			mapLocations[i]->SetShopName(rotate(szHolder));
			fin >> szHolder;
		}
		if(szHolder == "X:")
		{
			fin >> t;
			if(t > max.X)
				max.X = t;
			mapLocations[i]->SetPositionX(t);
			fin >> szHolder;
		}
		if(szHolder == "Y:")
		{
			fin >> t;
			if(t > max.Y)
				max.Y = t;
			mapLocations[i]->SetPositionY(t);
			fin >> szHolder;
		}
		if(szHolder == "L:")
		{
			getline(fin,szHolder);
			mapLocations[i]->SetDescription(rotate(szHolder));
			fin >> szHolder;
		}
		if(szHolder == "S:")
		{
			getline(fin,szHolder);
			mapLocations[i]->SetSummary(rotate(szHolder));
		}
		i++;
	}
	Xmax = max.X;
	Ymax = max.Y;
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

//==========================================================================================================
//	This function checks to see if Player is eligable for any magics, and checks so not to give the same
//  one twice. REM added 1/5/06
//==========================================================================================================
void World::CheckMagic(Player *player,vector<Magic*> &magic)
{
	if(player->RaceKillCounts.OrcKillCount == 5 && player->RaceKillCounts.ElfKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Minor Heal"))
			return;
		//p2->setbspells(true);             Just there to test when to give ka
		Display->DisplayText("The god of life has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new MinorHeal);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.OrcKillCount == 10 && player->RaceKillCounts.ElfKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Briar Bush"))
			return;
		Display->DisplayText("The god of life has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new BriarBush);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.OrcKillCount == 20 && player->RaceKillCounts.ElfKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Major Heal"))
			return;
		Display->DisplayText("The god of life has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new MajorHeal);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.OrcKillCount == 40 && player->RaceKillCounts.ElfKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Snow"))
			return;
		Display->DisplayText("The god of life has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Blizzard);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount == 5 && player->RaceKillCounts.OrcKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Drain Life"))
			return;
		player->SetHasSpells(true);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new DrainLife);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount == 10 && player->RaceKillCounts.OrcKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Flame Arrow"))
			return;
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new FireArrow);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount == 20 && player->RaceKillCounts.OrcKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Steal Ka"))
			return;
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new StealKa);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount == 40 && player->RaceKillCounts.OrcKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Fire"))
			return;
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Fire);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 4 && player->RaceKillCounts.OrcKillCount > 4 &&  player->RaceKillCounts.HumanKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Strength"))
			return;
		player->SetHasSpells(true);
		Display->DisplayText("The god of war has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Might);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 8 && player->RaceKillCounts.OrcKillCount > 8 &&  player->RaceKillCounts.HumanKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Dispel"))
			return;
		Display->DisplayText("The god of war has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Dispel);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 12 && player->RaceKillCounts.OrcKillCount > 12 &&  player->RaceKillCounts.HumanKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Shock"))
			return;
		Display->DisplayText("The god of war has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Shock);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 15 && player->RaceKillCounts.OrcKillCount > 15 &&  player->RaceKillCounts.HumanKillCount == 0 && magic.size() < 10)
	{
		if(HasMagic(magic,"Acid Rain"))
			return;
		Display->DisplayText("The god of war has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new AcidRain);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 3 && player->RaceKillCounts.OrcKillCount > 3 &&  player->RaceKillCounts.HumanKillCount > 3 && magic.size() < 10)
	{
		if(HasMagic(magic,"Poison"))
			return;
		player->SetHasSpells(true);
		Display->DisplayText("The god of death has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Poison);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 10 && player->RaceKillCounts.OrcKillCount > 10 &&  player->RaceKillCounts.HumanKillCount > 10 && magic.size() < 10)
	{
		if(HasMagic(magic,"Skeleton"))
			return;
		Display->DisplayText("The god of death has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new RaiseSkeleton);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 15 && player->RaceKillCounts.OrcKillCount > 15 &&  player->RaceKillCounts.HumanKillCount > 15 && magic.size() < 10)
	{
		if(HasMagic(magic,"Dark Strike"))
			return;
		Display->DisplayText("The god of death has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new DarkStrike);
		Sleep(player->GetPauseDuration());
	}
	if(player->RaceKillCounts.ElfKillCount > 20 && player->RaceKillCounts.OrcKillCount > 20 &&  player->RaceKillCounts.HumanKillCount > 20 && magic.size() < 10)
	{
		if(HasMagic(magic,"Critical"))
			return;
		Display->DisplayText("The god of death has rewarded you with a magic spell!",13,9,white);
		magic.push_back(new Critical);
		Sleep(player->GetPauseDuration());
	}
	
}

bool World::HasMagic(vector<Magic*> M,string name)
{
	unsigned int i;
	for(i=0;i<M.size();i++)
	{
		if(name == M[i]->GetName())
			return true;		
	}
	return false;
}
//==========================================================================================================
//	Intro to the game!
//==========================================================================================================
void World::Intro()
{
	Display->DisplayText("In the past when gods could be bested by mortal men, ",13,2,white);
	Display->DisplayText("four priests are keeping the pantheon at bay and ruling",13,3,white);
	Display->DisplayText("the world for their own evil schemes. If the priests were ",13,4,white);
	Display->DisplayText("out of the picture however...",13,5,white);
	Display->DisplayText(" ", 13, 6,white);
	system("pause");
}
/*==========================================================================================================
	A string comparison function. Yeah I wrote my own, wanna fight about it?
============================================================================================================*/
bool World::MusicNameComparer(char* string1,char* string2)
{
	if(string1 == string2)
		return false;
	else
		return true;	
}

/*===========================================
This function will play music of the game
=============================================*/
void World::SetMusic(char * mapMusic, Player *player)
{
/*================================================
    copy the map music into the player's music
    otherwise, there are problems. sheesh. 1/9/07
=================================================*/
	player->SetMusicFilename(mapMusic);

	if(player->GetIsMusicOn())
	{
		player->PlayMusic(mapMusic);
	}
}

void World::plot(string Map, string ID)
{
	int i = 3;
	ifstream fin;
	string szThing;
	string file = Map + ID + ".plt";
	string holder;
	string speaker = "[---";
	string spoken;
	fin.open(file.c_str());
	if (fin.fail())
	{
		Display->DisplayError("ERROR LOADING PLOT");
		exit(0);
	}
	fin >> szThing;
	getline(fin, holder);
	rotate(holder);
	speaker = speaker + holder + "---]";

	Display->DisplayText(speaker, 13, 1, brown);
	while (!fin.eof())
	{
		fin >> szThing;
		getline(fin, spoken);
		rotate(spoken);
		Display->DisplayText(spoken, 13, i, white);
		spoken = " ";
		i++;
	}
	Display->DisplayText("", 13, 23, white);
	system("pause");
}

string World::rotate(string pStr)
{
	string rStr;
	rStr = pStr.substr(1, pStr.length() - 1);
	return rStr;
}