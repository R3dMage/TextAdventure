#ifndef CREATURE_H
#define CREATURE_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings

#include "Player.h"
#include "Item.h"

using namespace std;

Item* loaditem(string name);
void text(string,short,short,WORD);
void clear();
void num(int num,int X, int Y,WORD color);

class Creature{
public:
	Creature();
	bool bant;

	void SetLevel(int);
	int GetLevel();
	void SetHitPoints(int);
	int GetHitPoints();
	void SetMaxHitPoints(int);
	int GetMaxHitPoints();
	void SetExperience(int);
	int GetExperience();
	void SetDamage(int);
	int GetDamage();
	void SetDamageModifier(int);
	int GetDamageModifier();
	int GetDefense();
	void SetEvade(int);
	int GetEvade();
	void SetGold(int);
	int GetGold();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	void SetMagicDefense(int);
	int GetMagicDefense();
	void SetName(string);
	void SetTalkTo(bool);
	bool GetTalkTo();
	void SetRunAway(bool);
	void SetKa(int);
	int GetKa();
	int GetMaxKa();
	void SetState(int);
	int GetState();
	bool GetRunAway();
	void SetDontMove(bool);
	bool GetDontMove();
	string GetType();
	string GetName();
	string GetWeakness();
	string gettoken();
	string GetMap();
	char* GetMusic();
	virtual void SetMap(string);

	void DisplayInfo();
	void DisplayDamage(int);
	void DisplayCure(int);
	void slowDisp(string);
	void LoadPosition(int X, int Y);
	virtual Creature* Replenish() const = 0;
	virtual Item* Body(string) const = 0;
	Item* Loadtoken();
	virtual void Win(Player *player);
	virtual bool DroppedItem();
	virtual void Attack(Player *player, vector<Item*> &playerInventory,vector<Item*> &worldItems,string map);
	virtual Item* Token(string);
	virtual bool TalkTo(Player *player);
	virtual void Banter();

protected:
	int 	Level;
	int		HitPoints;
	int		MaxHP;
	int		Experience;
	int		Damage;
	int		DamageModifier;
	int		Defense;
	int		MagicDefense;
	int		Evade;
	int		Gold;
	int		X;
	int		Y;
	int		Ka;
	int		MaxKa;
	int		State;
	bool	CanTalkTo;
	bool	RunAway;
	bool	DontMove;
	bool	IsAsleep;
	bool	IsPoisoned;
	string  Type;
	string	Name;
	string  Map;
	string  Weakness;
	char *  Music;

	bool MoveCursor(COORD &CursPos, bool &bSelect, int Ymin, int Ymax);
	void DrawCursor(COORD pos, WORD color, char curs);
};
#endif 