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

class World
{
public:
	World(GameDisplay* gameDisplay, ItemRepository* items);
	~World();
	void StartGame();
	void Move(vector<Creature*> &encounter,int Xmax, int Ymax);
	void Fight(Player *player, Creature *guy, vector<Item*> &playerInventory,vector<Item*> &worldItems,vector<Magic*> &spells,string map);
	void PlayerAttack(Player* player, FightDisplay* fightDisplay, Creature* enemy);
	void Locations(string,Player*,bool);
	void PawnShop(Player *, vector<Item*> &,string map);
	void SetupNcps(vector<Creature*> &npc, string mapName,int xMax,int yMax,GameEvents plotEvents,RaceReactionIndex raceReaction,char*& musicFile);
	bool Overflow(int size);
	void DescriptionDisplay(string, string &, string &, string &);
	void LoadMap(vector< Location* > &locations, string &mapName, int &Xmax, int &Ymax, bool &bTown);
	
	

private:
	GameDisplay* Display;
	MainMenuSystem* Menu;
	ISaveLoadGame* GameSaver;
	ItemRepository* Items;
	Plots* GamePlots;

	void Intro();
	bool MusicNameComparer(char *,char *);
	void SetMusic(char*, Player *);
	bool Walk(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	void CheckMagic(Player *,vector<Magic*> &);
	bool HasMagic(vector<Magic*>,string);
	void ReplenishEnemy(vector<Creature*> &enemies,int num);
	void Win(FightDisplay* fightDisplay, Player* player, Creature* enemy, vector<Item*>& worldItems, string map);

	void plot(string map, string ID);
	string rotate(string pStr);
};

#endif