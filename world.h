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

class World
{
public:
	World(GameDisplay* gameDisplay, ItemRepository* items, MusicPlayer* musicPlayer, VirtualMap* virtualMap);
	~World();
	void StartGame();
	void Move(vector<Creature*>& encounter, int Xmax, int Ymax);
	void Locations(string map, Player* player, bool playerIsLoaded);
	bool Overflow(int size);
	
	

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

	bool Walk(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	void ReplenishEnemy(vector<Creature*>& enemies, int num);
};

#endif