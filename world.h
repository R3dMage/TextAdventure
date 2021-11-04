#ifndef WORLD_H
#define WORLD_H

#include "Location.h"
#include "Magic.h"
#include "CFmod.h"
#include "Fmod.h"
#include "GameDisplay.h"
#include "MainMenuSystem.h"

void num(int num, short X, short Y,WORD color);
void text(string, short, short, WORD);
void clrbottom();
void clritems();
void clrtop(int);
Armor* loadArmor(string);
Weapon* loadWeapon(string);
string rotate(string pStr);
Item* loaditem(string name);
void items(vector<Item*> &playerInventory);
void plot(string Maplayer, string ID);

class World
{
public:
	World(GameDisplay* gameDisplay);
	~World();
	void Move(vector<Creature*> &encounter,int Xmax, int Ymax);
	void Fight(Player *player, Creature *guy, vector<Item*> &playerInventory,vector<Item*> &worldItems,vector<Magic*> &spells,string map);
	void Locations(string,Player*,bool);
	void Armory(vector<Item*> &playerInventory,Player *player,string map);
	void MagicShop(vector<Item*> &playerInventory, Player *player,string map);
	void Inn(Player *player, string map);
	void PawnShop(Player *, vector<Item*> &,string map);
	void SetupNcps(vector<Creature*> &npc, string mapName,int xMax,int yMax,GameEvents plotEvents,RaceReactionIndex raceReaction,char*& musicFile);
	bool Overflow(int size);
	void DescriptionDisplay(string, string &, string &, string &);
	void LoadMap(vector< Location* > &locations, string &mapName, int &Xmax, int &Ymax, bool &bTown);
	
	

private:
	GameDisplay* Display;
	MainMenuSystem* Menu;
	ISaveLoadGame* GameSaver;
	void Intro();
	bool MusicNameComparer(char *,char *);
	void SetMusic(char*, Player *);
	void OptionsMenu(Player *, vector<Item*> &,vector<Item*> &,vector<Magic*> &, string &);
	// bool MoveCursor(COORD &cursorPosition, bool &bSelect,bool &bEsc,int Ymin, int Ymax);
	bool Walk(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	// void DrawCursor(COORD pos, WORD color, unsigned char curs);
	void CheckMagic(Player *,vector<Magic*> &);
	bool HasMagic(vector<Magic*>,string);
	Item Ebody(Creature *guy, string map);
	void ReplenishEnemy(vector<Creature*> &enemies,int num);

	string GetFileName();
};

#endif