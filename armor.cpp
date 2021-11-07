#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>

#include "Armor.h"

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

string Armor::Display()
{
	char message[50];
	sprintf_s(message, "Absorbs %d and adds %d to your evade  ", DefenseModifier, EvadeModifier);
	return string(message);
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