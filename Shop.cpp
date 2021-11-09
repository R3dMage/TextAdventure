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
	int choice = 0;
	bool escapeWasPressed = false;
	bool itemSelected = false;
	bool funds = true;
	COORD cursorPosition;

	PopulateInventory(MapName);
	unsigned int maxY = Wares.size() + 1;

	map<int, Item*> stuff;
	
	for (unsigned int i = 0; i < Wares.size(); i++)
	{
		stuff.insert(std::pair<int, Item*>(i + 2, Wares[i]));
	}

	while (!escapeWasPressed)
	{
		cursorPosition.X = 13;
		cursorPosition.Y = 2;
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
		do
		{
			if (Menu->MoveCursor(cursorPosition, itemSelected, escapeWasPressed, 2, maxY))
			{
				Menu->DrawCursor(cursorPosition, yellow, 175);
				choice = cursorPosition.Y;
				Display->DisplayItem(stuff[choice]);
			}
			Display->DisplayText(" ", 79, 23, white);
		} while (!itemSelected);
		if (escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		if (player->GetGold() < stuff[choice]->GetCost())
			funds = false;
		if (funds)
		{
			playerInventory.push_back(stuff[choice]);
			player->SetGold(player->GetGold() - stuff[choice]->GetCost());
		}
		if (!funds)
		{
			Display->DisplayText("You do not have sufficient funds", 13, 9, white);
			Sleep(1500);
		}
	}// End while bEsc
	Display->ClearAll();
}
