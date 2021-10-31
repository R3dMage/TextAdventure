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

struct RaceReactionIndex{
	int Elf;
	int Human;
	int Orc;
};
struct PlayerKillCounts{
	int ElfKillCount;
	int HumanKillCount;
	int OrcKillCount;
};
struct GameEvents{
	bool Start;
	bool Priest1;
	bool Priest2;
	bool Priest3;
	bool Priest4;
	bool GreenDragon;
	bool BlueDragon;
	bool RedDragon;
	bool Monk;
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

	PlayerKillCounts RaceKillCounts;
	GameEvents PlotEventStates;
	RaceReactionIndex RaceReactions;
	

private:
	//time_h	p_time;						// Time in game
	CFmod	MapMusic;						// Music controller
	string	Name;							// Player's Name
	weapon*	EquippedWeapon;					// Current Weapon
	armor*	EquippedArmor;					// Current Armor
	int		X;								// Players X coordinate on the current map
	int		Y;								// Players Y coordinate on the current map
	int		Strength;						// Strength
	int		Mind;							// Mental Ability
	int		Gold;							// Um, Gold
	int		Evade;							// Chance to evade an attack
	int		MaxHP;							// Max Hit Points
	int		HP;								// Current Hit Points
	int		Experience;						// Experience
	int		Level;							// Level	
	int		Ka;								// Current Magic Points
	int		MaxKa;							// Max Magic Points
	int		ExperienceNeededForNextLevel;	// Experience for next level
	int		TotalKills;						// # of kills
	int		PauseDuration;					// Pause duration in milliseconds
	int		HealthState;					// Current state
	bool	IsInFight;						// To determine if there is a fight
	bool	IsPoisoned;						// Poison status
	bool	IsAsleep;						// Sleep Status
	bool	HasSpells;						// Whether or not player has spells
	bool	MemberHasJoined;				// ???
	bool	IsLoaded;						// Whether or not a character has been loaded
	char *  MusicFilename;					// Name of musicFile

/* =========================================================
   These will be player specific options that can be changed
   in the option menu should the player so choose. 
   =========================================================*/

	bool	MusicIsOn;		// Option to turn music on or off
	bool	Invisible;		// Sometimes you want to be invisible to enemies

	bool MoveCurs(COORD &cursorPosition, bool &hasSelection, bool &bEsc, int Ymin, int Ymax);
	void DrawCurs(COORD position, WORD color, char cursorCharacter);
};
#endif