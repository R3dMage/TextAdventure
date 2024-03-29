#include "PawnShop.h"

PawnShop::PawnShop(GameDisplay* display, MainMenuSystem* menu)
{
	Display = display;
	Menu = menu;
}

void PawnShop::Enter(Player* player, std::vector<Item*>& playerInventory, string mapName)
{
	Item* selectedItem;
	unsigned int offset = 0;
	unsigned int choice = 0;
	int sellPrice;
	double sellMultiplier = .75;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool bLeave = false;
	Item holder;
	COORD cursorPosition;
	cursorPosition.X = CursorStartX;
	cursorPosition.Y = CursorStartY;


	if (mapName == "valesh")
		sellMultiplier = .5;
	
	if (mapName == "elvencity")
		sellMultiplier = .6;
	
	if (mapName == "marintown")
		sellMultiplier = .75;
	
	if (mapName == "yamashi")
		sellMultiplier = .85;
	
	while (!bLeave)
	{
		selectionWasMade = false;
		Display->ClearBottom();
		Display->ClearTopBelow(3);
		Display->DisplayPlayerInfo(player);
		Display->DisplayText("[---We buy STUFF!---]", 13, 1, brown);
		if (playerInventory.size() < 1)
		{
			Display->DisplayTextAndPause("You have nothing to sell!!!", 13, 3, white);
			Display->ClearTopRight();
			return;
		}
		else
			Display->DisplayText("What would you like to sell?", 13, 3, white);

		Display->DisplayPlayerItems(playerInventory);
		while (!selectionWasMade)
		{
			escapeWasPressed = false;
			selectionWasMade = false;

			Display->DrawCursor(cursorPosition, yellow, 175);
			offset = cursorPosition.Y - 12;
			Display->DisplayItem(playerInventory[offset]);
			
			do
			{
				choice = 11 + playerInventory.size();
				if (Menu->MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, choice))
				{
					Display->DrawCursor(cursorPosition, yellow, 175);
					offset = cursorPosition.Y - CursorStartY;
					playerInventory[offset]->Display();
				}
				Display->DisplayText(" ", 79, 23, white);
			} while (!selectionWasMade);
		}
		
		if (escapeWasPressed)
		{
			Display->ClearBottom();
			Display->ClearTopBelow(1);
			return;
		}
		
		offset = cursorPosition.Y - CursorStartY;
		selectedItem = playerInventory[offset];
		selectionWasMade = false;

		sellPrice = static_cast<int>(selectedItem->GetCost() * sellMultiplier);
		Display->DisplayText(playerInventory[offset]->GetName(), 15, cursorPosition.Y, green);
		Display->DisplayText("This Item?                  ", 13, 3, white);
		Display->DisplayText(selectedItem->GetName(), 13, 5, white);
		cout << "   " << sellPrice << "GP";
		
		do
		{
			if (Menu->MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, cursorPosition.Y, cursorPosition.Y))
			{
				Display->DrawCursor(cursorPosition, yellow, 175);
			}
			Display->DisplayText(" ", 78, 24, white);
		} while (!selectionWasMade);
		
		if (escapeWasPressed)
		{
			continue;
		}
		selectionWasMade = false;
		player->SetGold(player->GetGold() + sellPrice);

		//======================================NEW CODE TO REMOVE ITEM=====================================
		Menu->SlideDown(playerInventory, offset);
		playerInventory.pop_back();
		//==================================================================================================
		Display->ClearBottom();
		Display->DisplayPlayerInfo(player);
		Display->DisplayTextAndPause("There you go!", 13, 3, white);
		cursorPosition.Y = CursorStartY;
	}
}