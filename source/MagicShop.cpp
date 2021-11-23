#include "MagicShop.h"

MagicShop::MagicShop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, string mapName)
	: Shop(display, menu, itemRepository, mapName)
{

}

void MagicShop::PopulateInventory(std::string mapName)
{
	if (mapName == "valesh")
	{
		AddItem(ItemFactory->GetItem("Potion"));
	}
	else if (mapName == "elvencity")
	{
		AddItem(ItemFactory->GetItem("Potion"));
		AddItem(ItemFactory->GetItem("Potion2"));
		AddItem(ItemFactory->GetItem("Refresh"));
	}
	else if (mapName == "marintown")
	{
		AddItem(ItemFactory->GetItem("Potion"));
		AddItem(ItemFactory->GetItem("Potion2"));
		AddItem(ItemFactory->GetItem("Potion3"));
		AddItem(ItemFactory->GetItem("Refresh"));
		AddItem(ItemFactory->GetItem("RedVial"));
	}
	else if (mapName == "yamashi")
	{
		AddItem(ItemFactory->GetItem("Potion2"));
		AddItem(ItemFactory->GetItem("Potion3"));
		AddItem(ItemFactory->GetItem("Refresh"));
		AddItem(ItemFactory->GetItem("BlueVial"));
	}
	else
	{
		AddItem(ItemFactory->GetItem("Potion"));
	}
}
