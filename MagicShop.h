#pragma once
#include "Shop.h"

class MagicShop : public Shop
{
public:
	MagicShop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, std::string mapName);

protected:
	virtual void PopulateInventory(std::string mapName) override;
};

