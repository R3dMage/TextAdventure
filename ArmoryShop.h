#pragma once
#include "Shop.h"

class ArmoryShop : public Shop
{
public:
	ArmoryShop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, std::string mapName);

protected:
	virtual void PopulateInventory(std::string mapName) override;
};

