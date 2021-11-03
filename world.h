#ifndef WORLD_H
#define WORLD_H

#include "Location.h"
#include "Magic.h"
#include "CFmod.h"
#include "Fmod.h"

void num(int num,int X, int Y,WORD color);
void text(string, short, short, WORD);
void clear();
void clrbottom();
void clritems();
void clrtop(int);
Armor* loadArmor(string);
Weapon* loadWeapon(string);
string rotate(string pStr);
Item* loaditem(string name);
void ground(vector<Item*> worldItems,string Maplayer,int X, int Y);
void items(vector<Item*> &playerInventory);
void plot(string Maplayer, string ID);

class World
{
public:
	World();
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
	void HandleMainMenu(Player *player,vector<Magic*> &spells,vector<Item*> &Stuff, vector<Item*> &playerInventory,string &);
	void HandleInventory(Player *player,vector<Item*> &worldItems, vector<Item*> &playerInventory,string);
	void DisplayPlayerItems(vector<Item*> &playerInventory);
	void Equip(Player *player,vector<Item*> &playerInventory);
	void Drop(Player *player,vector<Item*> &worldItems, vector<Item*> &playerInventory,string);
	void DeleteItem(vector<Item*> &playerInventory);
	void Options(Player *player,vector<Item*> &worldItems, vector<Item*> &playerInventory,vector<Magic*> &M,string &map);	
	void UseItem(Player *player,vector<Item*> &worldItems,vector<Item*> &playerInventory,bool &bFight, bool &bLeave,string map);
	void Use(Player *player,vector<Item*> &playerInventory,bool &Iused,bool bFight);
	void MagicMenu(Player *player,vector<Magic*> &spells);
	void InFightMagicMenu(Player *player, Creature *enemy,vector<Magic*> &spells,bool &bEsc);
	
	

private:
	void Intro();
	bool MusicNameComparer(char *,char *);
	void SetMusic(char*, Player *);
	void OptionsMenu(Player *, vector<Item*> &,vector<Item*> &,vector<Magic*> &, string &);
	bool MoveCursor(COORD &cursorPosition, bool &bSelect,bool &bEsc,int Ymin, int Ymax);
	bool Walk(bool &bSelect,bool &bEsc, Player *player,int Xmax, int Ymax, int &T);
	void DrawCursor(COORD pos, WORD color, char curs);
	void CheckMagic(Player *,vector<Magic*> &);
	bool HasMagic(vector<Magic*>,string);
	Item Ebody(Creature *guy, string map);
	void ReplenishEnemy(vector<Creature*> &enemies,int num);
	void ClearTextBottomRight(int);
	void SlideDown(vector<Item*> &,int);
	void SaveGame(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map);
	void Load(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map);
	void load1(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map);
	void SaveMagic(vector<Magic*> &M,ofstream &);
	void SaveGround(vector<Item*> &worldItems,ofstream &);
	void SaveInventory(vector<Item*> &worldItems,ofstream &);	
	void LoadInventory(vector<Item*> &,ifstream &);
	void LoadGround(vector<Item*> &,ifstream &);
	void LoadMagic(vector<Magic*> &M,ifstream &);
	Magic* GetMagic(string);
	string GetFileName();
};

#endif