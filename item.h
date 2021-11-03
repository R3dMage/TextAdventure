#ifndef ITEM_H
#define ITEM_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <vector>

using namespace std;

void text(string,short,short,WORD);
void num(int, short X, short Y,WORD);

class Item {
public:
	Item();
	void SetName(string N);
	string GetName();
	void SetMapName(string M);
	string GetMapName();
	void SetPositionX(int neoX);
	int GetPositionX();
	void SetPositionY(int neoY);
	int GetPositionY();
	void SetCost(int);
	int GetCost();
	void SetIsArmor(bool);
	bool GetIsArmor();
	void SetIsWeapon(bool);
	bool GetIsWeapon();
	void SetKeep(bool);
	bool GetKeep();
	int GetType();
	void SetType(int);

	virtual void Display();

protected:
	string Name;
	string MapName;
	int duration;
	int PositionX;
	int PositionY;
	int Cost;
	int Type;
	int Time;
	int LifeTime;
	bool Keep;
	bool IsWeapon;
	bool IsArmor;

	void DisplayCost();
};
#endif 