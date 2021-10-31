#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Creature.h"
#include "Screen.h"
#include "Weapon.h"
#include "Armor.h"
#include "Enemies.h"
#include "Player.h"
#include "World.h"

#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
;
using namespace std;



void main()
{
	srand(GetTickCount());
	char name[10]; 
	bool load = false;
	ifstream fin;
	string map = "valesh";
	string temp;
	string filename;

	World globe;
	BoxScreen();
	

	//------------------------------------------------------->>>  Player Definition
	Player p;

	cout << "Enter your name: ";
	cin.get(name,10);
	p.SetName(name);
	filename = p.GetName() + ".svg";

	fin.open(filename.c_str());
	fin >> temp;
	fin.close();

	if(temp != "Name:")
	{
		load = false;
		p.DisplayStatus();
		system("cls");
	}
	if(temp == "Name:")
		load = true;

	string cheat = "rex";
	if(p.GetName() == cheat.c_str())
	{
		map = "icefield1";
		//p.setelf(1);
		//p.setbspells(true);
		p.SetGold(5000);
		//p.setmka(50);
		p.SetMaxHitPoints(500);
		p.SetHitPoints(500);
		p.SetKa(50);
		//p.setweapon(loadWeapon("DeathSword"));
		//p.setarmor(loadArmor("Hvy.Chain"));
	}
	globe.Locations(map,&p,load);
	text("",13,23,white);
	system("pause");

}

void text(string szText,int X,int Y,WORD color)
{
	HANDLE OutputH;
	COORD pos = {X, Y};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << szText;
}
//=====================================================================================
//	This function clear, erases the screen except for the lines.
//=====================================================================================
void clear()
{
	int Y = 1;
	while(Y < 10)
	{
		text("                                                                 ",13,Y,FOREGROUND_BLUE);
		text("           ",1,Y,FOREGROUND_BLUE);
		Y++;
	}
	Y = 11;
	while(Y < 24)
	{
		text("                                                                 ",13,Y,FOREGROUND_BLUE);
		text("           ",1,Y,FOREGROUND_BLUE);
		Y++;
	}
	DScreen();
}

//=====================================================================================
//	This function clr clears the bottom right space, where the descriptions are.
//=====================================================================================
void clr()
{
	int Y = 11;
	while(Y < 24)
			{
				text("                                                                 ",13,Y,FOREGROUND_BLUE);
				Y++;
			}
}
//=====================================================================================
//	This function clears above the midline
//=====================================================================================
void clrtop(int Y)
{
	while(Y < 10)
	{
		text("                                                                 ",13,Y,FOREGROUND_BLUE);
		Y++;
	}
}
//=====================================================================================
//	This function clears below the midline
//=====================================================================================
void clrbottom()
{
	int Y = 11;
	while(Y < 24)
	{
		text("                                                                 ",13,Y,FOREGROUND_BLUE);
		text("           ",1,Y,FOREGROUND_BLUE);
		Y++;
	}
}
//====================================================================================
// This function is the same as clr, WTF is with that?
//====================================================================================
void clritems()
{
	int Y = 11;
	while(Y < 24)
	{
		text("                                                                 ",13,Y,FOREGROUND_BLUE);
		Y++;
	}
}
void num(int num,int X,int Y,WORD color)
{
	HANDLE OutputH;
	COORD pos = {X, Y};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << num;
}

string rotate(string pStr)
{
	string rStr;
	rStr = pStr.substr(1,pStr.length()-1);
	return rStr;
}


Weapon* loadWeapon(string name)
{
	Weapon *weaponPtr;
	weaponPtr = new Weapon;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	bool bVal;
	int num;
	ifstream fin;
	fin.open("./data/weapon.dta");
	if(fin.fail())
	{
		char full[256];
		_fullpath(full, ".", 256);
		text("ERROR loading weapon file.   ",13,11,FOREGROUND_RED); 
		text(strerror(errno), 13, 12, FOREGROUND_RED);
		text(full, 13, 13, FOREGROUND_RED);
		text("", 13, 20, FOREGROUND_RED);
		system("pause");
		exit(0);
	}

	while(!nameFound)
	{
		fin >> szWord;
		getline(fin,temp);
		szName = rotate(temp);
		if(name == szName)
			nameFound = true;	

		weaponPtr->SetName(rotate(temp));

		fin >> szWord;
		getline(fin,temp);
		weaponPtr->SetAttribute1(rotate(temp));
		fin >> szWord;
		getline(fin,temp);
		weaponPtr->SetAttribute2(rotate(temp));
		fin >> szWord >> num;
		weaponPtr->SetDamage(num);
		fin >> szWord >> num;
		weaponPtr->SetDamageModifier(num);
		fin >> szWord >> bVal; 
		weaponPtr->SetHitsTwice(bVal);
		fin >> szWord >> bVal;
		weaponPtr->SetStealsLife(bVal);
		fin >> szWord >> num;
		weaponPtr->SetCost(num);
	}
	return weaponPtr;
}

Armor* loadArmor(string name)
{
	Armor *armorPtr = new Armor;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	int num;
	ifstream fin;
	fin.open("./data/armor.dta");
	if(fin.fail())
	{
		text("ERROR loading armor file.   ",13,11,FOREGROUND_RED); 
		system("pause");
		exit(0);
	}


	while(!nameFound)
	{
		fin >> szName;
		if(name == szName)
			nameFound = true;
		
		fin >> szWord;
		getline(fin,temp);
		armorPtr->SetName(rotate(temp));
		fin >> szWord >> num;
		armorPtr->SetDefenseModifier(num);
		fin >> szWord >> num;
		armorPtr->SetEvadeModifier(num);
		fin >> szWord >> num;
		armorPtr->SetCost(num);
		if(fin.eof())
		{
			text("END of Armor File reached.   ",13,11,FOREGROUND_RED); 
			system("pause");
			return armorPtr;
		}
	}
	return armorPtr;
}

Item* loaditem(string name)
{
	Item *itemPtr = new Item;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	int num;
	ifstream fin;
	fin.open("./data/items.dta");
	if(fin.fail())
	{
		text("ERROR loading item file.   ",13,11,FOREGROUND_RED); 
		system("pause");
		exit(0);
	}


	while(!nameFound)
	{
		fin >> szName;
		if(name == szName)
			nameFound = true;
		itemPtr->SetName(szName);
		fin >> num; itemPtr->SetType(num);
		fin >> szWord >> num;
		itemPtr->SetCost(num);
	}
	return itemPtr;
}

void ground(vector<Item*> stuff,string Map,int X,int Y)
{
	unsigned int Offset = 0;
	int NumItems = 0;	
	text("[---Ground---]",13,1,brown);
	while(Offset < stuff.size())
	{		
		if(stuff[Offset]->GetPositionY() == Y && stuff[Offset]->GetPositionX() == X && stuff[Offset]->GetMapName() == Map)
		{
			text(stuff[Offset]->GetName(),15,2+NumItems,yellow);
			NumItems++;
		}
		Offset++;		
		if(NumItems > 10)
			break;
	}
	if(Offset < 10)
		text("                       ",15,3+NumItems,yellow);
}
void items(vector<Item*> &pstuff)
{
	unsigned int Offset = 0;
 	text(" [---Items---] ",13,11,brown);
	while(Offset < pstuff.size())
	{		
		text(pstuff[Offset]->GetName(),15,12+Offset,yellow);
		Offset++;
		if(Offset >= 12)
			break;
	}
}
void cure(int D)
{
	int X = 13;
	while(X < 50)
	{
		num(D,X,9,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(50);
		X++;
		text("   ",X-1,9,FOREGROUND_GREEN);
	}
}
void plot(string Map, string ID)
{
	int i = 3;
	ifstream fin;
	string szThing;
	string file = Map + ID + ".plt";
	string holder;
	string speaker = "[---";
	string spoken;
	fin.open(file.c_str());
	if(fin.fail())
	{
		text("ERROR LOADING PLOT FILE", 13,11,yellow);
		Sleep(1500);
		exit(0);
	}
	fin >> szThing;
	getline(fin,holder);
	rotate(holder);
	speaker = speaker + holder + "---]";

	text(speaker,13,1,brown);
	while(!fin.eof())
	{
		fin >> szThing;
		getline(fin,spoken);
		rotate(spoken);
		text(spoken,13,i,white);
		spoken = " ";
		i++;		
	}
	text("",13,23,white);
	system("pause");
}







