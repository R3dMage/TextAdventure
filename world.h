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
armor* loadArmor(string);
weapon* loadWeapon(string);
string rotate(string pStr);
item* loaditem(string name);
void ground(vector<item*> stuff,string Map,int X, int Y);
void items(vector<item*> &pstuff);
void plot(string Map, string ID);

class world
{
public:
	world();
	~world();
	void move(vector<creature*> &encounter,int Xmax, int Ymax);
	void fight(player *p2, creature *guy, vector<item*> &pstuff,vector<item*> &stuff,vector<magik*> &spells,string Map);
	void locations(string,player*,bool);
	void armory(vector<item*> &pstuff,player *p2,string Map);
	void magicshop(vector<item*> &pstuff, player *p2,string Map);
	void inn(player *p2, string Map);
	void buyer(player *, vector<item*> &,string Map);
	void npcSetup(vector< creature* > &npc, string Map,int,int,events,robj,char*&,char*);
	bool Overflow(int size);
	void DescriptDisplay(string, string &, string &, string &);
	void loadmap(vector< location* > &g, string &Map, int &Xmax, int &Ymax, bool &bTown);
	void menu(player *p2,vector<magik*> &spells,vector<item*> &Stuff, vector<item*> &pstuff,string &);
	void inventory(player *p2,vector<item*> &stuff, vector<item*> &pstuff,string);
	void items(vector<item*> &pstuff);
	void equip(player *p2,vector<item*> &pstuff);
	void drop(player *p2,vector<item*> &stuff, vector<item*> &pstuff,string);
	void XXX(vector<item*> &pstuff);
	void options(player *p2,vector<item*> &stuff, vector<item*> &pstuff,vector<magik*> &M,string &Map);	
	void useItem(player *p2,vector<item*> &stuff,vector<item*> &pstuff,bool &bFight, bool &bLeave,string Map);
	void use(player *p2,vector<item*> &pstuff,bool &Iused,bool bFight);
	void magic(player *p2,vector<magik*> &spells);
	void fmagic(player *p2, creature *enemy,vector<magik*> &spells,bool &bEsc);
	
	

private:
	void intro();
	void start();
	bool musicCmp(char *,char *);
	void music(char*, player *);
	void setup(player *, vector<item*> &,vector<item*> &,vector<magik*> &, string &);
	bool MoveCurs(COORD &CursPos, bool &bSelect,bool &bEsc,int Ymin, int Ymax);
	bool walk(bool &bSelect,bool &bEsc, player *p,int Xmax, int Ymax, int &T);
	void DrawCurs(COORD pos, WORD color, char curs);
	void magicCheck(player *,vector<magik*> &);
	bool hasMagic(vector<magik*>,string);
	item Ebody(creature *guy, string Map);
	void Eplenish(vector<creature*> &enemies,int num);
	void clr(int);
	void slidedown(vector<item*> &,int);
	void save(player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map);
	void load(player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map);
	void load1(player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map);
	void MagikSave(vector<magik*> &M,ofstream &);
	void GroundSave(vector<item*> &stuff,ofstream &);
	void InvenSave(vector<item*> &stuff,ofstream &);	
	void loadInven(vector<item*> &,ifstream &);
	void loadGround(vector<item*> &,ifstream &);
	void loadMagik(vector<magik*> &M,ifstream &);
	magik* getMagik(string);
	string GetFileName();
};

#endif