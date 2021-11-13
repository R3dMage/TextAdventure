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
	World(GameDisplay* gameDisplay, ItemRepository* items, MusicPlayer* musicPlayer);
	~World();
	void StartGame();
	void Move(vector<Creature*>& encounter, int Xmax, int Ymax);
	void Locations(string map, Player* player, bool playerIsLoaded);
	void SetupNpcs(vector<Creature*>& npc, string mapName, int xMax, int yMax, GameEvents plotEvents, RaceReactionIndex raceReaction);
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

	void Intro();
	bool Walk(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	void ReplenishEnemy(vector<Creature*>& enemies, int num);

	void plot(string map, string ID);
};

#endif