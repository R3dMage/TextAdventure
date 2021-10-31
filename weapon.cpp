#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>

#include "weapon.h"
using namespace std;

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

Weapon::Weapon()
{
	IsWeapon = true;
	HitsTwice = false;
	StealsLife = false;
	Keep = true;
	Type = -2;
	Damage = 5;
	DamageModifier = 1;
	Cost = 0;
	Attribute1 = "none";
	Attribute2 = "none";
}
void Weapon::SetAttribute1(string A)
{
	Attribute1 = A;
}
string Weapon::GetAttribute1()
{
	return Attribute1;
}
void Weapon::SetAttribute2(string A)
{
	Attribute2 = A;
}
string Weapon::GetAttribute2()
{
	return Attribute2;
}
void Weapon::SetHitsTwice(bool value)
{
	HitsTwice = value;
}
void Weapon::SetDamage(int num)
{
	if(num < 0){num = 0;}
	Damage = num;
}
void Weapon::SetDamageModifier(int num)
{
	if(num < 0){num = 0;}
	DamageModifier = num;
}

void Weapon::SetStealsLife(bool bValue)
{
	StealsLife = bValue;
}
bool Weapon::GetHitsTwice()
{
	return HitsTwice;
}
int Weapon::GetDamage()
{
	return Damage;
}
int Weapon::GetDamageModifier()
{
	return DamageModifier;
}

bool Weapon::HasLifeSteal()
{
	return StealsLife;
}

void Weapon::Display()
{
	text("Deals ",30,11,white);
	cout << DamageModifier << " to " << Damage + DamageModifier - 1 << " points of damage          ";
	DisplayCost();
}

void Weapon::Save(string file)
{
	ofstream fout;
	fout.open("ulweapons.sav");

	fout << Name << endl;
	fout << "name: " << Name << endl;
	fout << "att1: " << Attribute1 << endl;
	fout << "att2: " << Attribute2 << endl;
	fout << "dam : " << Damage << endl;
	fout << "damM: " << DamageModifier << endl;
	fout << "2hit: " << HitsTwice << endl;
	fout << "life: " << StealsLife << endl;
	fout << "cost: " << Cost << endl;
	fout << endl;

	fout.close();	
}
