#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <fstream>			//For file accessing
#include <string>			//For Strings

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#include "Item.h"

using namespace std;
 
Item::Item()
{
	PositionX = 0;
	PositionY = 0;
	Name = "Ghost";
	MapName = "field";
	IsWeapon = false;
	IsArmor = false;
	Keep = false;
	Cost = 0;
	Type = -1;
}
int Item::GetType()
{
	return Type;
}
void Item::SetType(int type)
{
	Type = type;
}
void Item::SetIsArmor(bool isArmor)
{
	IsArmor = isArmor;
}
bool Item::GetIsArmor()
{
	return IsArmor;
}
void Item::SetIsWeapon(bool isWeapon)
{
	IsWeapon = isWeapon;
}
bool Item::GetIsWeapon()
{
	return IsWeapon;
}
void Item::SetCost(int cost)
{
	Cost = cost;
}
int Item::GetCost()
{
	return Cost;
}
void Item::SetName(string name)
{
	Name = name;
}
string Item::GetName()
{
	return Name;
}
void Item::SetMapName(string mapName)
{
	MapName = mapName;
}
string Item::GetMapName()
{
	return MapName;
}
void Item::SetPositionX(int neoX)
{
	PositionX = neoX;
}
int Item::GetPositionX()
{
	return PositionX;
}
void Item::SetPositionY(int neoY)
{
	PositionY = neoY;
}
int Item::GetPositionY()
{
	return PositionY;
}
void Item::SetKeep(bool keep)
{
	Keep = keep;
}
bool Item::GetKeep()
{
	return Keep;
}

string Item::Display()
{
	string displayText;
	switch(Type)
	{
	case 0:
		displayText = "Heals 25 points of life                    ";
		break;
	case 1:
		displayText = "Restores 5 to 10 point of ka";
		break;
	case 2:
		displayText = "Increases Strength 1-5 points              ";
		break;
	case 3:
		displayText = "Increases Mind 1-5 points                  ";
		break;
	case 4:
		displayText = "Heals 75 points of life                    ";
		break;
	case 5:
		displayText = "Heals 150 points of life              ";
		break;
	case 6:
		displayText = "Heals all of your life              ";
		break;
	default:
		displayText = "                                           ";
	}
	return displayText;
}