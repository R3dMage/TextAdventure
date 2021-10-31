#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>

#include "armor.h"
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

using namespace std;


armor::armor()
{
	IsArmor = true;
	Keep = true;
	Type = -1;
	defmod = 0;
	evadMod = 0;
	Cost = 0;

}
void armor::setdefMod(int num)
{
	if(num < 0){num = 0;}
	defmod = num;
}
void armor::setevadMod(int num)
{	
	evadMod = num;
}


int armor::getdefMod()
{
	return defmod;
}
int armor::getevadMod()
{
	return evadMod;
}
bool armor::getmod()
{
	return mod;
}

void armor::display()
{
	text("Absorbs ",30,11,white);
	cout << defmod << " and adds " << evadMod << " to your evade   ";
	DisplayCost();
}

void armor::unload(string file)
{
	ofstream fout;
	fout.open("ularmor.sav");

	fout << Name;
	fout << "name: " << Name;
	fout << "Def : " << defmod;
	fout << "abs : " << evadMod;
	fout << endl;
	fout.close();

}
