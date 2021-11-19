#include <map>
#include "Shop.h"

Shop::Shop(GameDisplay* display, MainMenuSystem* menu, ItemRepository* itemRepository, string mapName)
{
	Display = display;
	Menu = menu;
	ItemFactory = itemRepository;
	MapName = mapName;
}

void Shop::AddItem(Item* item)
{
	if (Wares.size() < 6)
		Wares.push_back(item);
}

void Shop::ShowShop(Player* player, vector<Item*> &playerInventory)
{
	bool escapeWasPressed = false;
	bool escapeConfirmation = false;
	bool itemSelected = false;
	bool funds = true;
	COORD cursorPosition;
	cursorPosition.X = 13;
	cursorPosition.Y = 2;

	PopulateInventory(MapName);
	unsigned int maxY = Wares.size() + 1;

	map<int, Item*> itemsForSale;
	
	for (unsigned int i = 0; i < Wares.size(); i++)
	{
		itemsForSale.insert(std::pair<int, Item*>(i + 2, Wares[i]));
	}

	while (!escapeWasPressed)
	{
		itemSelected = false;
		funds = true;
		Display->ClearAll();
		Display->DisplayPlayerInfo(player);
		Display->DisplayPlayerItems(playerInventory);

		Display->DisplayText("[-----For Sale-----]", 13, 1, yellow);
		for (unsigned int i = 0; i < Wares.size(); i++)
		{
			Display->DisplayText(Wares[i]->GetName(), 15, i + 2, white);
			Display->DisplayNumber(Wares[i]->GetCost(), 28, i + 2, white);
		}

		Menu->DrawCursor(cursorPosition, yellow, 175);
		Display->DisplayItem(Wares[0]);
		while (!itemSelected && !escapeWasPressed)
		{
			if (Menu->MoveCursor(cursorPosition, itemSelected, escapeWasPressed, 2, maxY))
			{
				Menu->DrawCursor(cursorPosition, yellow, 175);				
				Display->DisplayItem(itemsForSale[cursorPosition.Y]);
			}
			Display->DisplayText("", 78, 24, white);
		}
		if (escapeWasPressed)
			break;

		itemSelected = false;
		Display->DisplayText("This Item?                  ", 13, 9, white);
		Display->DisplayText(itemsForSale[cursorPosition.Y]->GetName(), 15, cursorPosition.Y, green);
		while (!itemSelected && !escapeConfirmation)
		{
			Menu->MoveCursor(cursorPosition, itemSelected, escapeConfirmation, cursorPosition.Y, cursorPosition.Y);
			Menu->DrawCursor(cursorPosition, yellow, 175);
			Display->DisplayText("", 78, 24, white);
		}
		if (escapeConfirmation)
		{
			escapeConfirmation = false;
			continue;
		}

		BuyItem(player, playerInventory, itemsForSale[cursorPosition.Y]);

	}// End while bEsc
	Display->ClearAll();
}

void Shop::BuyItem(Player* player, std::vector<Item*>& playerInventory, Item* item)
{
	bool funds = true;

	if (player->GetGold() < item->GetCost())
		funds = false;
	if (funds)
	{
		playerInventory.push_back(item);
		player->SetGold(player->GetGold() - item->GetCost());
	}
	if (!funds)
	{
		Display->DisplayText("You do not have sufficient funds", 13, 9, white);
		Sleep(1500);
	}
}
