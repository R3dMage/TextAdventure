#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "CFmod.h"
#include "Fmod.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"



string rotate(string);
void text(string,int,int,WORD);
void num(int num,int X, int Y,WORD color);
void clear();
armor* loadArmor(string);
weapon* loadWeapon(string);
void ground(vector<item> stuff,string Map,int X,int Y);
void cure(int D);
void clrtop(int);

struct robj{
int elf;
int human;
int orc;
};
struct rkills{
	int Ekills;
	int Hkills;
	int Okills;
};
struct events{
	bool start;
	bool priest1;
	bool priest2;
	bool priest3;
	bool priest4;
	bool gd;
	bool bd;
	bool rd;
	bool monk;
};

class Player {

public:
	Player();

	void setname(string);
	string getname();
	void setweapon(weapon*);
	weapon* getweapon();
	void setarmor(armor*);
	armor* getarmor();
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setstr(int);
	int getstr();
	void setmind(int);
	int getmind();
	void setgold(int);
	int getgold();
	void setMHP(int);
	int getMHP();
	void setHP(int);
	int getHP();
	void setexp(int);
	int getexp();
	void setlev(int);
	int getlev();
	void setka(int);
	int getka();
	void setmka(int);
	int getmka();
	void setNext(int);
	int getNext();
	void setEvd(int);
	int getEvd();
	void setKills(int);
	int getKills();
	void setPause(int);
	int getPause();
	void setelf(int);
	int getelf();
	void sethuman(int);
	int gethuman();
	void setorc(int);
	int getorc();
	void setstate(int);
	int getstate();
	bool getbspells();
	void setbspells(bool);
	bool getbjoined();
	void setbjoined(bool);
	void setpoisoned(bool);
	bool getpoisoned();
	void setLoaded(bool);
	bool getLoaded();
	void setSleep(bool);
	bool getSleep();
	void setInvis(bool);
	bool getInvis();
	void setMusic(bool);
	bool getMusic();
	void setMusicFilename(char *);
	char * getMusicFilename();

	void status();
	void info();
	bool LevUp();
	void raiseLev();
	void Save(ofstream &fout);
	void Load(ifstream &fin);
	void playMusic(char *);
	void stopMusic();
	void changeMusic();
	void plots(string);

	rkills kill;
	events plot;
	robj react;
	

private:
	//time_h	p_time;			// Time in game
	CFmod	mapMusic;		// Music controller
	string	name;			// Player's Name
	weapon	*weap;			// Current Weapon
	armor	*arm;			// Current Armor
	int		X;				// Players X coordinate on the current map
	int		Y;				// Players Y coordinate on the current map
	int		str;			// Strength
	int		mind;			// Mental Ability
	int		gold;			// Um, Gold
	int		evade;			// Chance to evade an attack
	int		MHP;			// Max Hit Points
	int		HP;				// Current Hit Points
	int		exp;			// Experience
	int		lev;			// Level	
	int		ka;				// Current Magic Points
	int		mka;			// Max Magic Points
	int		NextLev;		// Experience for next level
	int		kills;			// # of kills
	int		pause;			// Pause duration in milliseconds
	int		state;			// Current state
	bool	fight;			// To determine if there is a fight
	bool	poisoned;		// Poison status
	bool	sleep;			// Sleep Status
	bool	bspells;		// Whether or not player has spells
	bool	bjoined;		// ???
	bool	Loaded;			// Whether or not a character has been loaded
	char *  musicFilename;  // Name of musicFile

/* =========================================================
   These will be player specific options that can be changed
   in the option menu should the player so choose. 
   =========================================================*/

	bool	music;			// Option to turn music on or off
	bool	Invisible;		// Sometimes you want to be invisible to enemies
	
	


	bool MoveCurs(COORD &CursPos, bool &bSelect, bool &bEsc, int Ymin, int Ymax);
	void DrawCurs(COORD pos, WORD color, char curs);



};





#endif