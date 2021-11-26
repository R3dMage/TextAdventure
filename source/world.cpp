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

World::World(GameDisplay* gameDisplay, ItemRepository* items, MusicPlayer* musicPlayer, VirtualMap* virtualMap, GameSettings* gameSettings)
{
	Display = gameDisplay;
	Items = items;
	Music = musicPlayer;
	CurrentMap = virtualMap;
	Settings = gameSettings;
	CurrentState = new GameState();
	GameSaver = new SaveLoadGame(Items, Display);
	Menu = new MainMenuSystem(Display, GameSaver, Items, musicPlayer, gameSettings);
	GamePlots = new Plots(Display, CurrentState);
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

void World::TitleScreen()
{
	Music->SetMusicFilename("TitleScreen.mp3");
	Display->DisplayTitleScreen();
	Menu->TitleScreenMenu(CurrentState);	
}

void World::SetupGame()
{
	// GamePlots->DisplayIntro();
	Player* player = CurrentState->GetPlayer();
	vector<Creature*> monk = CurrentState->GetMonk();

	CurrentMap = new VirtualMap(CurrentState->GetMapName());
	CurrentState->SetupNpcs(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
	Music->SetMusicFilename(CurrentMap->GetMusicFileName());
}

void World::PlayGame()
{
	int time = 0;

	Player* player = CurrentState->GetPlayer();
	
	bool selectionWasMade;
	bool escapeWasPressed;

    Display->ClearAll();

	while(player->GetCurrentHitPoints() > 0)			//This is THE while loop for the game
	{
		CurrentState->GetMonk()[0]->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());

		selectionWasMade   = false;
		escapeWasPressed   = false;

		CheckPlayerLocation(player);

		PlayerEnvironment surroundings = CurrentMap->GetPlayerEnvironment(player->GetPositionX(), player->GetPositionY());
		Display->DisplayLocation(&surroundings);
		Display->DisplayPlayerInfo(player);

//=============================================================================================================
//		Debugging: displays mapname, Vmap#, and number of encounters in the map
// Adding Map size 5/16/05.
// Commented out encounter size and # of squares for beta version 6/14/05
//=============================================================================================================
		Display->DisplayText("          ",2,22,white);
		Display->DisplayNumber(CurrentMap->GetMaxX(), 2, 22, white);
		Display->DisplayText("x",4,22,white);
		Display->DisplayNumber(CurrentMap->GetMaxY(), 5, 22, white);
		Display->DisplayText("          ",2,19,white);
		Display->DisplayText(CurrentState->GetMapName(),2,19,yellow);			
//		Display->num(T,2,20,yellow);			T = 0;
//		Display->num(static_cast<int>(CurrentState->GetCreatures().size()),2,21,blue);
//=============================================================================================================
//								 Code that displays enemies grid locations
// commented out Enemy grid locations 6/14/05
//=============================================================================================================
		//int k = 0;
		//for(i=0;i < encounter.size() && i < 20;i++)
		//{
		//	int j = 16;
		//	Display->text("X: ",13,8,white);
		//	Display->text("Y: ",13,9,white);
		//	Display->num(CurrentState->GetCreatures()[i]->getX(),j+i+k,8,white);
		//	Display->num(CurrentState->GetCreatures()[i]->getY(),j+i+k,9,white);
		//	k += 2;
		//}

		Display->DisplayCompass(player->GetPositionX(), player->GetPositionY(), CurrentMap->GetMaxX(), CurrentMap->GetMaxY());

		//	This function clears any items that WERE on the ground
		Display->ClearTopBelow(2);
		Display->DisplayItemsOnGround(CurrentState->GetWorldItems(), CurrentState->GetMapName(), player);

		CheckForPlayerMovement(escapeWasPressed, player, CurrentMap->GetMaxX(), CurrentMap->GetMaxY(), time);

		if(escapeWasPressed)//=================>  This is the code that calls the player menu for advanced fun
		{
			//clear();                    For smooth look commented out on 2/15/06
			Menu->HandleMainPlayerMenu(CurrentState);
			if(player->GetIsLoaded())
			{
				CurrentMap->LoadMap(CurrentState->GetMapName());
				CurrentState->SetupNpcs(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
				
				Music->SetMusicFilename(CurrentMap->GetMusicFileName());
				
				player->SetIsLoaded(false);
			}
			if (CurrentState->PlayerHasQuit())
			{
				CurrentState->SetQuit(false);
				break;
			}
		}

		GamePlots->Check(CurrentMap, player, Music);

		CheckForEnemyEncounters(player);

//===============================================================================================
//									Function for moving enemies around on the map
//===============================================================================================

		MoveCreatures(CurrentState->GetCreatures(), CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
	}// -------------------------------->End Walking Loop
}

void World::CheckForEnemyEncounters(Player* player)
{
	//=================================================================================================================
	//											Enemy Encounter Code
	//Cycles through encounter[] checking if any encounter are at the players current location.
	//==================================================================================================================

	vector<Creature*> monk = CurrentState->GetMonk();
	vector<Creature*> encounters = CurrentState->GetCreatures();
	if (!player->GetIsLoaded())//								This makes sure that you're not attacked when you load the game.
	{
		for (vector<Creature*>::iterator encounter = encounters.begin(); encounter != encounters.end(); ++encounter)
		{
			Creature* creature = *encounter;

			if (player->GetPositionX() == creature->GetX() && player->GetPositionY() == creature->GetY() && creature->GetHitPoints() != 0)
			{
				if (!creature->GetTalkTo())
					Fight->Engage(player, creature, CurrentState->GetPlayerInventory(), CurrentState->GetWorldItems(), CurrentState->GetPlayerSpells(), CurrentState->GetMapName());
				else
				{
					Display->DisplayPlayerInfo(player);
					Greeting greeting = creature->GetGreeting(player);

					if (Menu->TalkTo(&greeting, Settings->GetPauseDuration()))
						Fight->Engage(player, creature, CurrentState->GetPlayerInventory(), CurrentState->GetWorldItems(), CurrentState->GetPlayerSpells(), CurrentState->GetMapName());
				}
				if (creature->GetHitPoints() <= 0)
				{
					CurrentState->GetWorldItems().push_back(creature->Body(CurrentState->GetMapName()));		//Drops enemy unique item if the enemy is dead
				}
				MagicProvider->CheckMagic(player, CurrentState->GetPlayerSpells());


				if (monk.front()->GetHitPoints() <= 0)
				{
					Creature* temp = monk.front();
					delete temp;
					monk.clear();
					monk.push_back(new Fly());
					monk[monk.size() - 1]->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
				}

			}
		}

		//===========================================================================================================
		//					Replenishes the dead enemies, so we don't run out of them on a map
		//Moved to inside the for loop 6/14/05
		//===========================================================================================================
		for (vector<Creature*>::iterator encounter = encounters.begin(); encounter != encounters.end(); ++encounter)
		{
			Creature* creature = *encounter;
			if (creature->GetHitPoints() <= 0 && !creature->GetDontMove())
			{
				creature->Replenish();
				creature->LoadPosition(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());
			}
		}
	}
	if (player->GetIsLoaded())
		player->SetIsLoaded(false);

	if (monk.front()->GetX() == player->GetPositionX() && monk.front()->GetY() == player->GetPositionY() && CurrentState->GetMapName() == "field2")
		Fight->Engage(player, monk.front(), CurrentState->GetPlayerInventory(), CurrentState->GetWorldItems(), CurrentState->GetPlayerSpells(), CurrentState->GetMapName());
}

void World::CheckPlayerLocation(Player* player)
{
	PlayerEnvironment surroundings = CurrentMap->GetPlayerEnvironment(player->GetPositionX(), player->GetPositionY());
	Location* playerLocation = surroundings.PlayerLocation;

	if (surroundings.PlayerLocation->GetIsMapChange())
	{
		player->SetPositionX(surroundings.PlayerLocation->GetNeoX());
		player->SetPositionY(surroundings.PlayerLocation->GetNeoY());

		CurrentState->SetMapName(surroundings.PlayerLocation->GetMapChangeName());

		CurrentMap->LoadMap(CurrentState->GetMapName());
		CurrentState->SetupNpcs(CurrentMap->GetMaxX(), CurrentMap->GetMaxY());		

		Music->SetMusicFilename(CurrentMap->GetMusicFileName());
	}

	else if (surroundings.PlayerLocation->GetHasPlot())
	{
		Display->ClearAll();
		Display->DisplayPlayerInfo(player);

		GamePlots->DisplayPlot(CurrentState->GetMapName(), surroundings.PlayerLocation->GetPlotText());
	}

	else if (surroundings.PlayerLocation->GetIsShop())
	{
		string ShopType = surroundings.PlayerLocation->GetShopName();
		if (ShopType == "armory")
		{
			ArmoryShop armory(Display, Menu, Items, CurrentState->GetMapName());
			armory.ShowShop(player, CurrentState->GetPlayerInventory());
		}

		if (ShopType == "inn")
		{
			Lodging lodging(Display, Menu);
			lodging.Enter(player, CurrentState->GetMapName());
		}

		if (ShopType == "magic")
		{
			MagicShop magicShop(Display, Menu, Items, CurrentState->GetMapName());
			magicShop.ShowShop(player, CurrentState->GetPlayerInventory());
		}

		if (ShopType == "buy")
		{
			PawnShop pawnShop(Display, Menu);
			pawnShop.Enter(player, CurrentState->GetPlayerInventory(), CurrentState->GetMapName());
		}
	}
}


//==========================================================================================================
//	Function for walking around the map. It returns true if you've moved (that is pressed a movement key)
//	to load up the description of the place you've moved to. Also it takes the bEsc variable to see if you
//  hit Esc key to enter the menu.
//==========================================================================================================
bool World::CheckForPlayerMovement(bool &escapeWasPressed, Player *player, int Xmax,int Ymax, int &time)
{
	time++;
	INPUT_RECORD InputRecord;
	DWORD Events = 0;
	HANDLE hInput;
	bool cursorMoved = false;
	bool selectionWasMade = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);

	while (!selectionWasMade)
	{
		ReadConsoleInput(hInput, &InputRecord,1,&Events);
		bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
		if (InputRecord.EventType == KEY_EVENT && bKeyDown)
		{
			if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
				// If you hit up, go up! But not if your as up as you can go on the map.
			{
				player->SetPositionY(player->GetPositionY() + 1);
				if (player->GetPositionY() > Ymax)
					player->SetPositionY(Ymax);
				selectionWasMade = true;
			}
			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
				// If you hit down, go down! The Player Class prevents Y from being 0.
			{
				player->SetPositionY(player->GetPositionY() - 1);
				selectionWasMade = true;
			}
			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
				// If you hit right, go right! But not if your as right as you can go on the map.
			{
				player->SetPositionX(player->GetPositionX() + 1);
				if (player->GetPositionX() > Xmax)
					player->SetPositionX(Xmax);
				selectionWasMade = true;
			}
			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
				// If you hit left, go left! The player class prevents X from being 0.
			{
				player->SetPositionX(player->GetPositionX() - 1);
				selectionWasMade = true;
			}

			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
				// This changes bEsc, so that the main loop knows to go into the menu function
			{
				escapeWasPressed = true;
				selectionWasMade = true;
			}
		}
	}	
	Display->DisplayText("", 78, 24,white);
	return false;	
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
void World::MoveCreatures(vector<Creature*> &encounter,int Xmax, int Ymax)
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