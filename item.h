#ifndef ITEM_H
#define ITEM_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <vector>

class Item {
public:
	Item();
	void SetName(std::string N);
	std::string GetName();
	void SetMapName(std::string M);
	std::string GetMapName();
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

	virtual std::string Display();

protected:
	std::string Name;
	std::string MapName;
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
};
#endif 