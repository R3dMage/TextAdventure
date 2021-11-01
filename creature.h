#ifndef CREATURE_H
#define CREATURE_H


#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings

#include "Player.h"
#include "Item.h"

using namespace std;

Item* loaditem(string name);
void text(string,int,int,WORD);
void clear();
void num(int num,int X, int Y,WORD color);

class Creature{
public:
	Creature();
	bool bant;

	void setlevel(int);
	int getlevel();
	void sethp(int);
	int gethp();
	void setmhp(int);
	int getmhp();
	void setexp(int);
	int getexp();
	void setdamage(int);
	int getdamage();
	void setdamMod(int);
	int getdamMod();
	int getdef();
	void setevade(int);
	int getevade();
	void setgold(int);
	int getgold();
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setmagdef(int);
	int getmagdef();
	void setname(string);
	void setTalkTo(bool);
	bool getTalkTo();
	void setrunAway(bool);
	void setka(int);
	int getka();
	int getmka();
	void setstate(int);
	int getstate();
	bool getrunAway();
	void setdontmove(bool);
	bool getdontmove();
	string gettype();
	string getname();
	string getweakness();
	string gettoken();
	string getmap();
	char* getMusic();
	virtual void setmap(string);

	void info();
	void dam(int);
	void cure(int);
	void slowDisp(string);
	void loadPos(int X, int Y);
	virtual Creature* replenish() const = 0;
	virtual Item* body(string) const = 0;
	Item* Loadtoken();
	virtual void win(Player *p2);
	virtual bool dropItem();
	virtual void attack(Player *p2, vector<Item*> &pstuff,vector<Item*> &stuff,string Map);
	virtual Item* token(string);
	virtual bool talkto(Player *p2);
	virtual void banter();

protected:
	int 	level;
	int		hp;
	int		mhp;
	int		exp;
	int		damage;
	int		damMod;
	int		def;
	int		magdef;
	int		evade;
	int		gold;
	int		X;
	int		Y;
	int		ka;
	int		mka;
	int		state;
	bool	talkTo;
	bool	runAway;
	bool	dontmove;
	bool	bSleep;
	bool	bPoison;
	string  type;
	string	name;
	string  map;
	string  weakness;
	char *  music;

	bool MoveCurs(COORD &CursPos, bool &bSelect, int Ymin, int Ymax);
	void DrawCurs(COORD pos, WORD color, char curs);



	
};


#endif 
