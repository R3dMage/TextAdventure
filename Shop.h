#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "GameDisplay.h"
#include "MainMenuSystem.h"

class Shop
{
public:
	Shop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, std::string mapName);
	void ShowShop(Player* player, vector<Item*> &playerInventory);

	void BuyItem(Player* player, std::vector<Item*>& playerInventory, Item* item);

protected:
	virtual void PopulateInventory(std::string mapName) = 0;
	void AddItem(Item* item);

	std::string MapName;
	std::vector<Item*> Wares;
	GameDisplay* Display;
	MainMenuSystem* Menu;
	ItemRepository* ItemFactory;
};

