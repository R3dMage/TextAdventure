#pragma once
#include <string>
#include <vector>
#include "GameDisplay.h"
#include "item.h"

class ItemRepository
{
public:
	ItemRepository(GameDisplay* display);
	Item* GetItem(std::string name);
	Armor* GetArmor(std::string name);
	Weapon* GetWeapon(std::string name);

	static string rotate(std::string text);

private:
	void Load(GameDisplay* display);
	void LoadArmor(GameDisplay* display);
	void LoadWeapons(GameDisplay* display);
	void LoadItems(GameDisplay* display);

	std::vector<Item*> Items;
};

