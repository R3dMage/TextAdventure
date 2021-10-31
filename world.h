#ifndef WORLD_H
#define WORLD_H


#include "location.h"
#include "magic.h"
#include "CFmod.h"
#include "Fmod.h"

void num(int num,int X, int Y,WORD color);
void text(string,int,int,WORD);
void clear();
void clrbottom();
void clritems();
void clrtop(int);
Armor* loadArmor(string);
weapon* loadWeapon(string);
string rotate(string pStr);
Item* loaditem(string name);
void ground(vector<Item*> stuff,string Map,int X, int Y);
void items(vector<Item*> &pstuff);
void plot(string Map, string ID);

class world
{
public:
	world();
	~world();
	void move(vector<creature*> &encounter,int Xmax, int Ymax);
	void fight(Player *p2, creature *guy, vector<Item*> &pstuff,vector<Item*> &stuff,vector<magik*> &spells,string Map);
	void locations(string,Player*,bool);
	void armory(vector<Item*> &pstuff,Player *p2,string Map);
	void magicshop(vector<Item*> &pstuff, Player *p2,string Map);
	void inn(Player *p2, string Map);
	void buyer(Player *, vector<Item*> &,string Map);
	void npcSetup(vector< creature* > &npc, string Map,int,int,GameEvents,RaceReactionIndex,char*&,char*);
	bool Overflow(int size);
	void DescriptDisplay(string, string &, string &, string &);
	void loadmap(vector< location* > &g, string &Map, int &Xmax, int &Ymax, bool &bTown);
	void menu(Player *p2,vector<magik*> &spells,vector<Item*> &Stuff, vector<Item*> &pstuff,string &);
	void inventory(Player *p2,vector<Item*> &stuff, vector<Item*> &pstuff,string);
	void items(vector<Item*> &pstuff);
	void equip(Player *p2,vector<Item*> &pstuff);
	void drop(Player *p2,vector<Item*> &stuff, vector<Item*> &pstuff,string);
	void XXX(vector<Item*> &pstuff);
	void options(Player *p2,vector<Item*> &stuff, vector<Item*> &pstuff,vector<magik*> &M,string &Map);	
	void useItem(Player *p2,vector<Item*> &stuff,vector<Item*> &pstuff,bool &bFight, bool &bLeave,string Map);
	void use(Player *p2,vector<Item*> &pstuff,bool &Iused,bool bFight);
	void magic(Player *p2,vector<magik*> &spells);
	void fmagic(Player *p2, creature *enemy,vector<magik*> &spells,bool &bEsc);
	
	

private:
	void intro();
	void start();
	bool musicCmp(char *,char *);
	void music(char*, Player *);
	void setup(Player *, vector<Item*> &,vector<Item*> &,vector<magik*> &, string &);
	bool MoveCurs(COORD &CursPos, bool &bSelect,bool &bEsc,int Ymin, int Ymax);
	bool walk(bool &bSelect,bool &bEsc, Player *p,int Xmax, int Ymax, int &T);
	void DrawCurs(COORD pos, WORD color, char curs);
	void magicCheck(Player *,vector<magik*> &);
	bool hasMagic(vector<magik*>,string);
	Item Ebody(creature *guy, string Map);
	void Eplenish(vector<creature*> &enemies,int num);
	void clr(int);
	void slidedown(vector<Item*> &,int);
	void save(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map);
	void load(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map);
	void load1(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map);
	void MagikSave(vector<magik*> &M,ofstream &);
	void GroundSave(vector<Item*> &stuff,ofstream &);
	void InvenSave(vector<Item*> &stuff,ofstream &);	
	void loadInven(vector<Item*> &,ifstream &);
	void loadGround(vector<Item*> &,ifstream &);
	void loadMagik(vector<magik*> &M,ifstream &);
	magik* getMagik(string);
	string GetFileName();
};

#endif