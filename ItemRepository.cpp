#include <fstream>
#include "ItemRepository.h"
#include "armor.h"
#include "weapon.h"

ItemRepository::ItemRepository(GameDisplay* gameDisplay)
{
	Load(gameDisplay);
}

Item* ItemRepository::GetItem(std::string name)
{
	for (unsigned int i = 0; i < Items.size(); i++)
	{
		if (name == Items[i]->GetName())
			return Items[i];
	}

	exit(1);
}

Armor* ItemRepository::GetArmor(std::string name)
{
	return (Armor*)GetItem(name);
}

Weapon* ItemRepository::GetWeapon(std::string name)
{
	return (Weapon*)GetItem(name);
}

void ItemRepository::Load(GameDisplay* display)
{
	LoadArmor(display);
	LoadWeapons(display);
	LoadItems(display);		
}

void ItemRepository::LoadArmor(GameDisplay* display)
{
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	int num;
	ifstream fin;
	fin.open("./data/armor.dta");
	if (fin.fail())
	{
		display->DisplayError("ERROR loading armor file");
		exit(0);
	}

	while (!fin.eof())
	{
		Armor* armorPtr = new Armor;
		fin >> szName;
		fin >> szWord;
		getline(fin, temp);
		armorPtr->SetName(rotate(temp));
		fin >> szWord >> num;
		armorPtr->SetDefenseModifier(num);
		fin >> szWord >> num;
		armorPtr->SetEvadeModifier(num);
		fin >> szWord >> num;
		armorPtr->SetCost(num);

		Items.push_back(armorPtr);
	}
	fin.close();
}

void ItemRepository::LoadWeapons(GameDisplay* display)
{
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool bVal;
	int num;
	ifstream fin;

	fin.open("./data/weapon.dta");
	if (fin.fail())
	{
		display->DisplayError("ERROR loading weapon file");
		exit(0);
	}

	while (!fin.eof())
	{
		Weapon* weapon = new Weapon;
		fin >> szWord;
		getline(fin, temp);
		szName = rotate(temp);

		weapon->SetName(szName);
		fin >> szWord;
		getline(fin, temp);
		weapon->SetAttribute1(rotate(temp));
		fin >> szWord;
		getline(fin, temp);
		weapon->SetAttribute2(rotate(temp));
		fin >> szWord >> num;
		weapon->SetDamage(num);
		fin >> szWord >> num;
		weapon->SetDamageModifier(num);
		fin >> szWord >> bVal;
		weapon->SetHitsTwice(bVal);
		fin >> szWord >> bVal;
		weapon->SetStealsLife(bVal);
		fin >> szWord >> num;
		weapon->SetCost(num);

		Items.push_back(weapon);
	}
}

void ItemRepository::LoadItems(GameDisplay* display)
{
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	int num;
	ifstream fin;

	fin.open("./data/items.dta");
	if (fin.fail())
	{
		display->DisplayError("ERROR loading item");
		exit(0);
	}

	while (!fin.eof())
	{
		Item* itemPtr = new Item;
		fin >> szName;
		itemPtr->SetName(szName);
		fin >> num; itemPtr->SetType(num);
		fin >> szWord >> num;
		itemPtr->SetCost(num);

		Items.push_back(itemPtr);
	}
}

string ItemRepository::rotate(string pStr)
{
	string rStr;
	rStr = pStr.substr(1, pStr.length() - 1);
	return rStr;
}
