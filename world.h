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

	void MoveCreatures(vector<Creature*>& encounter, int Xmax, int Ymax);
	void CheckPlayerLocation(Player* player);
	bool CheckForPlayerMovement(bool &bEsc,Player *player, int Xmax,int Ymax, int &T);
	void CheckForEnemyEncounters(Player* player);
	void ReplenishEnemy(Creature* enemy);
	bool Overflow(int size);
};

#endif