#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>

#include "Armor.h"
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

using namespace std;


Armor::Armor()
{
	IsArmor = true;
	Keep = true;
	Type = -1;
	DefenseModifier = 0;
	EvadeModifier = 0;
	Cost = 0;

}
void Armor::SetDefenseModifier(int num)
{
	if(num < 0){num = 0;}
	DefenseModifier = num;
}
void Armor::SetEvadeModifier(int num)
{	
	EvadeModifier = num;
}


int Armor::GetDefenseModifier()
{
	return DefenseModifier;
}
int Armor::GetEvadeModifier()
{
	return EvadeModifier;
}

void Armor::Display()
{
	text("Absorbs ",30,11,white);
	cout << DefenseModifier << " and adds " << EvadeModifier << " to your evade   ";
	DisplayCost();
}

void Armor::Save(string file)
{
	ofstream fout;
	fout.open("ularmor.sav");

	fout << Name;
	fout << "name: " << Name;
	fout << "Def : " << DefenseModifier;
	fout << "abs : " << EvadeModifier;
	fout << endl;
	fout.close();

}