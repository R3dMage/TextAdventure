#include "ArmoryShop.h"

ArmoryShop::ArmoryShop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, std::string mapName)
	: Shop(display, menu, itemRepository, mapName)
{
	
}

void ArmoryShop::PopulateInventory(string mapName)
{
	if (mapName == "valesh")
	{
		AddItem(ItemFactory->GetItem("Rapier"));
		AddItem(ItemFactory->GetItem("Longsword"));
		AddItem(ItemFactory->GetItem("Scimitar"));
		AddItem(ItemFactory->GetItem("Padded"));
		AddItem(ItemFactory->GetItem("Leather"));
		AddItem(ItemFactory->GetItem("Lt.Chain"));
	}
	else if (mapName == "elvencity")
	{
		AddItem(ItemFactory->GetItem("+1 Rapier"));
		AddItem(ItemFactory->GetItem("+1Longsword"));
		AddItem(ItemFactory->GetItem("+1 Scimitar"));
		AddItem(ItemFactory->GetItem("Padded"));
		AddItem(ItemFactory->GetItem("Leather"));
		AddItem(ItemFactory->GetItem("Elvenchain"));
	}
	else if (mapName == "marintown")
	{
		AddItem(ItemFactory->GetItem("Scimitar"));
		AddItem(ItemFactory->GetItem("Claymore"));
		AddItem(ItemFactory->GetItem("Spitfire"));
		AddItem(ItemFactory->GetItem("Leather"));
		AddItem(ItemFactory->GetItem("Lt.Chain"));
		AddItem(ItemFactory->GetItem("SteelMail"));
	}
	else if (mapName == "yamashi")
	{
		AddItem(ItemFactory->GetItem("Spitfire"));
		AddItem(ItemFactory->GetItem("Hammer"));
		AddItem(ItemFactory->GetItem("Katana"));
		AddItem(ItemFactory->GetItem("Leather"));
		AddItem(ItemFactory->GetItem("Lt.Chain"));
		AddItem(ItemFactory->GetItem("SteelMail"));
	}
	else
	{
		AddItem(ItemFactory->GetItem("Rapier"));
		AddItem(ItemFactory->GetItem("Longsword"));
		AddItem(ItemFactory->GetItem("Scimitar"));
		AddItem(ItemFactory->GetItem("Padded"));
		AddItem(ItemFactory->GetItem("Leather"));
		AddItem(ItemFactory->GetItem("Lt.Chain"));
	}
}
