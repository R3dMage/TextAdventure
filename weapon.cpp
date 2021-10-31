#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>

#include "weapon.h"
using namespace std;

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

weapon::weapon()
{
	IsWeapon = true;
	twohits = false;
	lifesteal = false;
	Keep = true;
	Type = -2;
	damage = 5;
	damMod = 1;
	Cost = 0;
	attribute1 = "none";
	attribute2 = "none";
}
bool weapon::getmod()
{
	return mod;
}
void weapon::setmod(bool M)
{
	mod = M;
}
void weapon::setAttribute1(string A)
{
	attribute1 = A;
}
string weapon::getAttribute1()
{
	return attribute1;
}
void weapon::setAttribute2(string A)
{
	attribute2 = A;
}
string weapon::getAttribute2()
{
	return attribute2;
}
void weapon::set2hits(bool bValue)
{
	twohits = bValue;
}
void weapon::setdamage(int num)
{
	if(num < 0){num = 0;}
	damage = num;
}
void weapon::setdamMod(int num)
{
	if(num < 0){num = 0;}
	damMod = num;
}

void weapon::setlsteal(bool bValue)
{
	lifesteal = bValue;
}
bool weapon::get2hits()
{
	return twohits;
}
int weapon::getdamage()
{
	return damage;
}
int weapon::getdamMod()
{
	return damMod;
}

bool weapon::getlsteal()
{
	return lifesteal;
}

void weapon::display()
{
	text("Deals ",30,11,white);
	cout << damMod << " to " << damage + damMod - 1 << " points of damage          ";
	DisplayCost();
}

void weapon::unload(string file)
{
	ofstream fout;
	fout.open("ulweapons.sav");

	fout << Name << endl;
	fout << "name: " << Name << endl;
	fout << "att1: " << attribute1 << endl;
	fout << "att2: " << attribute2 << endl;
	fout << "dam : " << damage << endl;
	fout << "damM: " << damMod << endl;
	fout << "2hit: " << twohits << endl;
	fout << "life: " << lifesteal << endl;
	fout << "cost: " << Cost << endl;
	fout << endl;

	fout.close();	
}
