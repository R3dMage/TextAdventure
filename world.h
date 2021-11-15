#ifndef WORLD_H
#define WORLD_H

#include "Location.h"
#include "Magic.h"
#include "CFmod.h"
#include "Fmod.h"
#include "FightDisplay.h"
#include "MainMenuSystem.h"
#include "ItemRepository.h"
#include "Plots.h"
#include "Battle.h"
#include "VirtualMap.h"
#include "PlayerMagicProvider.h"
#include "MusicPlayer.h"
#include "GameSettings.h"
#include "GameState.h"

class World
{
public:
	World(GameDisplay* gameDisplay, ItemRepository* items, MusicPlayer* musicPlayer, VirtualMap* virtualMap, GameSettings* gameSettings);
	~World();
	void TitleScreen();
	void SetupGame();
	void PlayGame();
	
	

private:
	GameDisplay* Display;
	VirtualMap* CurrentMap;
	MainMenuSystem* Menu;
	ISaveLoadGame* GameSaver;
	ItemRepository* Items;
	Plots* GamePlots;
	Battle* Fight;
	PlayerMagicProvider* MagicProvider;
	MusicPlayer* Music;
	GameSettings* Settings;

	// State of the game
	GameState* CurrentState;
	//Player* player;
	//std::string map;
	//std::vector<Creature*> monk;				// This is a seperate vector for THE monk.
	//std::vector<Item*> worldItems;				// Globals will contain ALL the items in the world
	//std::vector<Item*> playerInventory;			// inv is the players inventory
	//std::vector<Creature*> encounter;			// encounter holds all the enemies on a certain map
	//std::vector<Magic*> spells;					// Magik will hold all the spells granted to the player

	void MoveCreatures(vector<Creature*>& encounter, int Xmax, int Ymax);
	bool CheckForPlayerMovement(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	void ReplenishEnemy(vector<Creature*>& enemies, int num);
	bool Overflow(int size);
};

#endif