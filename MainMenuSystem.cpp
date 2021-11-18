#include "MainMenuSystem.h"
#include "Menu.h"
#include "OptionsMenuHandler.h"

MainMenuSystem::MainMenuSystem(GameDisplay* gameDisplay, ISaveLoadGame* gameSaver, ItemRepository* itemRepository, MusicPlayer* musicPlayer, GameSettings* settings)
{
	Display = gameDisplay;
	GameSaver = gameSaver;
	Items = itemRepository;
	Music = musicPlayer;
	Settings = settings;
}

void MainMenuSystem::TitleScreenMenu(GameState* gameState)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool startGame = false;
	COORD cursorPosition;

	while (!startGame)
	{
		ClearTextBottomRight(11);
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  New    |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Load   |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Setup  |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Quit   |", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("           ", 1, 17, blue);

		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, 15))
			{
				DrawCursor(cursorPosition, yellow, 175);
			}
		} while (!selectionWasMade);

		choice = cursorPosition.Y;
		switch (choice)
		{
		case 12:
			gameState->NewGameState(Items, Display->GetFileName());
			startGame = true;
			break;
		case 13:
			GameSaver->LoadGame(Display->GetFileName(), gameState);
			gameState->LoadGameState();
			startGame = true;
			break;
		case 14:
			OptionsMenu();
			break;
		case 15:
			exit(0);
			break;
		}
	}// End of While(escapeWasPressed)
}

bool MainMenuSystem::YesOrNoPrompt()
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD curosrPosition;

	while (!escapeWasPressed)
	{
		curosrPosition.X = 2;
		curosrPosition.Y = 12;
		selectionWasMade = false;
		Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Yes    |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  No     |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCursor(curosrPosition, yellow, 175);
		do
		{
			if (MoveCursor(curosrPosition, selectionWasMade, escapeWasPressed, 12, 13))
			{
				DrawCursor(curosrPosition, yellow, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
			break;

		choice = curosrPosition.Y;
		switch (choice)
		{
		case 12:
			return true;
			break;
		case 13:
			return false;
			break;
		}
	}

	return false;
}

void MainMenuSystem::HandleMainPlayerMenu(GameState* gameState)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition;

	while (!escapeWasPressed)
	{
		ClearTextBottomRight(11);
		Display->DisplayPlayerInfo(gameState->GetPlayer());
		Display->DisplayItemsOnGround(gameState->GetWorldItems(), gameState->GetMapName(), gameState->GetPlayer());
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Inv.   |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Status |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Magic  |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Options|", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("           ", 1, 17, blue);

		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, 15))
			{
				DrawCursor(cursorPosition, yellow, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch (choice)
		{
		case 12:
			HandleInventory(gameState);
			break;
		case 13:
			Display->DisplayPlayerStatus(gameState->GetPlayer());
			break;
		case 14:
			if (gameState->GetPlayer()->HasLearnedSpells())
				MagicMenu(gameState->GetPlayer(), gameState->GetPlayerSpells());
			else
			{
				Display->DisplayTextAndPause("You have no magic", 13, 11, white);
				Display->DisplayText("                 ", 13, 11, white);
			}
			break;
		case 15:
			Options(gameState);
			break;
		}
	}// End of While(escapeWasPressed)


}
void MainMenuSystem::HandleInventory(GameState* gameState)
{
	int choice = 0;
	int Y = 11;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool wasUsed = false;
	bool pickup;
	bool selectedUse;
	COORD cursorPosition = { 2,12 };

	while (!escapeWasPressed)
	{
		Display->DisplayPlayerItems(gameState->GetPlayerInventory());
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		pickup = false;
		selectedUse = false;
		Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  PickUp |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Utilize|", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|         |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|         |", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, 13))
			{
				DrawCursor(cursorPosition, yellow, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch (choice)
		{
		case 12:
			gameState->PickupItems(Display);
			break;
		case 13:
			UseItem(gameState->GetPlayer(), gameState->GetWorldItems(), gameState->GetPlayerInventory(), false, escapeWasPressed, gameState->GetMapName());
			break;
		}
	}//--------------------End While escapeWasPressed
}//------------------------End Inventory function

void MainMenuSystem::Equip(Player* player, vector<Item*>& playerInventory)
{
	unsigned int Offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	Item* temp;
	COORD cursorPosition;

	while (!selectionWasMade)
	{
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		Offset = cursorPosition.Y - 12;
		DrawCursor(cursorPosition, yellow, 175);
		playerInventory[Offset]->Display();
		do
		{
			choice = static_cast<int>(11 + playerInventory.size());
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, choice))
			{
				DrawCursor(cursorPosition, yellow, 175);
				Offset = cursorPosition.Y - 12;
				playerInventory[Offset]->Display();
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
		{
			Display->DisplayText("          ", 1, 22, white);
			Display->DisplayText("          ", 1, 23, white);
			Display->ClearBottom();
			Display->DisplayPlayerItems(playerInventory);
			return;
		}
	}// End While selectionWasMade
	Offset = cursorPosition.Y - 12;
	temp = playerInventory[Offset];
	if (!temp->GetIsArmor() && !temp->GetIsWeapon())
	{
		Display->DisplayText("You cannot equip that.", 13, 9, white);
		Sleep(Settings->GetPauseDuration());
	}
	if (temp->GetIsArmor())
	{
		playerInventory.push_back(player->GetArmor());
		player->SetArmor(Items->GetArmor(temp->GetName()));
		playerInventory[Offset] = playerInventory[playerInventory.size() - 1];
		playerInventory[playerInventory.size() - 1] = temp;
		playerInventory.pop_back();
	}
	if (temp->GetIsWeapon())
	{
		playerInventory.push_back(player->GetWeapon());
		player->SetWeapon(Items->GetWeapon(temp->GetName()));
		playerInventory[Offset] = playerInventory[playerInventory.size() - 1];
		playerInventory[playerInventory.size() - 1] = temp;
		playerInventory.pop_back();
	}
	Display->DisplayText("              ", cursorPosition.X, cursorPosition.Y, white);
	Display->DisplayPlayerInfo(player);
	Display->DisplayPlayerItems(playerInventory);
	Display->DisplayText("                                           ", 175, 11, white);
	Display->DisplayText("           ", 1, 22, white);
	Display->DisplayText("           ", 1, 23, white);
}

void MainMenuSystem::Drop(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, string map)
{
	unsigned int Offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	//item *temp;
	COORD cursorPosition;


	while (!escapeWasPressed)
	{
		Display->DisplayItemsOnGround(worldItems, map, player);
		Display->DisplayPlayerItems(playerInventory);
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			choice = static_cast<int>(11 + playerInventory.size());
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, choice))
			{
				DrawCursor(cursorPosition, yellow, 175);
				Offset = cursorPosition.Y - 12;
				playerInventory[Offset]->Display();
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
		{
			Display->DisplayText("          ", 1, 22, white);
			Display->DisplayText("          ", 1, 23, white);
			Display->ClearBottom();
			Display->DisplayPlayerItems(playerInventory);
			return;
		}


		Offset = cursorPosition.Y - 12;
		playerInventory[Offset]->SetMapName(map);
		playerInventory[Offset]->SetPositionX(player->GetPositionX());
		playerInventory[Offset]->SetPositionY(player->GetPositionY());
		worldItems.push_back(playerInventory[Offset]);
		SlideDown(playerInventory, Offset);
		playerInventory.pop_back();
		Display->DisplayText("  ", 13, 12, white);
		Display->DisplayText("                    ", 13, 12 + Offset, white);
		Display->DisplayText("                    ", 13, static_cast<short>(12 + playerInventory.size()), white);
		if (playerInventory.size() < 1)
			return;
	}//end While escapeWasPressed
}
void MainMenuSystem::DeleteItem(vector<Item*>& playerInventory)
{
	unsigned int offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	//item *temp;
	COORD cursorPosition;

	while (!escapeWasPressed)
	{
		Display->DisplayPlayerItems(playerInventory);
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			choice = static_cast<int>(11 + playerInventory.size());
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, choice))
			{
				DrawCursor(cursorPosition, yellow, 175);
				offset = cursorPosition.Y - 12;
				playerInventory[offset]->Display();
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
		{
			Display->DisplayText("          ", 1, 22, white);
			Display->DisplayText("          ", 1, 23, white);
			Display->ClearBottom();
			Display->DisplayPlayerItems(playerInventory);
			return;
		}

		offset = cursorPosition.Y - 12;
		selectionWasMade = false;
		Display->DisplayText(playerInventory[offset]->GetName(), 15, cursorPosition.Y, FOREGROUND_RED | FOREGROUND_INTENSITY);
		do
		{

			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, cursorPosition.Y, cursorPosition.Y))
			{
				DrawCursor(cursorPosition, yellow, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
			return;
		SlideDown(playerInventory, offset);
		playerInventory.pop_back();
		ClearTextBottomRight(12);
		Display->DisplayText("                    ", 13, static_cast<short>(12 + playerInventory.size()), white);
		if (playerInventory.size() < 1)
			return;

	}// End While escapeWasPressed

}

void MainMenuSystem::Options(GameState* gameState)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition;

	while (!escapeWasPressed)
	{
		//clear();       For smooth look remarked out 2/15/06
		Display->DisplayPlayerInfo(gameState->GetPlayer());
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Save   |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Load   |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Setup  |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("|  Quit   |", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, 15))
			{
				DrawCursor(cursorPosition, yellow, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
			break;

		choice = cursorPosition.Y;

		switch (choice)
		{
		case 12:
			Display->DisplayText("Saving game ", 13, 11, yellow);
			GameSaver->SaveGame(gameState);
			Sleep(Settings->GetPauseDuration());
			Display->DisplayText("            ", 13, 11, yellow);
			break;
		case 13:
			GameSaver->LoadGame(Display->GetFileName(), gameState);
			break;
		case 14:
			OptionsMenu();
			break;
		case 15:
			system("cls");
			Display->DisplayText("See you next time.", 13, 11, yellow);
			Sleep(Settings->GetPauseDuration());
			exit(0);
			break;
		}
	}// End of While(escapeWasPressed)
}

/*=====================================================================================
	Input for the setup of the game. Music, speed, etc.
=====================================================================================*/
void MainMenuSystem::OptionsMenu()
{
	OptionsMenuHandler* handler = new OptionsMenuHandler(Display, Music, Settings);
	COORD cursorPosition;
	cursorPosition.X = 2;
	cursorPosition.Y = 12;

	Menu menu(cursorPosition, handler, 12, 14);
	menu.Begin();
}
void MainMenuSystem::UseItem(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, bool isFighting, bool& didLeave, string map)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool Iused = false;
	COORD cursorPosition;

	WORD color = isFighting ? ftext : compassColor;

	while (!escapeWasPressed)
	{
		ClearTextBottomRight(12);
		if (isFighting && Iused)
			break;
		Display->DisplayPlayerInfo(player);
		Display->DisplayPlayerItems(playerInventory);
		if (!isFighting)
			Display->DisplayItemsOnGround(worldItems, map, player);
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		Display->DisplayText("/---------\\", 1, 11, color);
		Display->DisplayText("|  Use    |", 1, 12, color);
		Display->DisplayText("|  Equip  |", 1, 13, color);
		Display->DisplayText("|  Drop   |", 1, 14, color);
		Display->DisplayText("|  XXXX   |", 1, 15, color);
		Display->DisplayText("\\---------/", 1, 16, color);

		DrawCursor(cursorPosition, color, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, 15))
			{
				DrawCursor(cursorPosition, color, 175);
			}
		} while (!selectionWasMade);
		if (escapeWasPressed)
		{
			didLeave = true;
			break;
		}
		choice = cursorPosition.Y;
		switch (choice)
		{
		case 12:
			if (playerInventory.size() > 0)
				Use(player, playerInventory, Iused, isFighting);
			else
			{
				Display->DisplayText("You have no items.", 13, 11, white);
				Sleep(Settings->GetPauseDuration());
			}
			break;
		case 13:
			if (playerInventory.size() > 0)
				Equip(player, playerInventory);
			else
			{
				Display->DisplayText("You have nothing to equip", 13, 12, white);
				Sleep(Settings->GetPauseDuration());
			}
			break;
		case 14:
			if (playerInventory.size() > 0)
				Drop(player, worldItems, playerInventory, map);
			else
			{
				Display->DisplayText("You have nothing to drop", 13, 12, white);
				Sleep(Settings->GetPauseDuration());
			}
			break;
		case 15:
			if (playerInventory.size() > 0)
				DeleteItem(playerInventory);
			else
			{
				Display->DisplayText("You have nothing to dispose of", 13, 12, white);
				Sleep(Settings->GetPauseDuration());
			}
			break;
		}//--------End Switch
	}//------------End While escapeWasPressed
	ClearTextBottomRight(12);
}
void MainMenuSystem::Use(Player* player, vector<Item*>& playerInventory, bool& itemWasUsed, bool isFighting)
{
	Weapon weapon;
	Armor  armor;
	Item* itemUsed;
	unsigned int offset = 0;
	int choice = 0;
	int Num;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition;


	while (!escapeWasPressed && playerInventory.size() > 0)
	{
		Display->ClearBottomRight();
		Display->DisplayPlayerItems(playerInventory);
		Display->DisplayPlayerInfo(player);

		if (itemWasUsed && isFighting)
			break;
		escapeWasPressed = false;
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition, yellow, 175);

		playerInventory[offset]->Display();
		do
		{
			choice = static_cast<int>(11 + playerInventory.size());
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 12, choice))
			{
				DrawCursor(cursorPosition, yellow, 175);
				offset = cursorPosition.Y - 12;
				playerInventory[offset]->Display();
			}
		} while (!selectionWasMade);

		if (escapeWasPressed)
		{
			Display->DisplayText("          ", 1, 22, white);
			Display->DisplayText("          ", 1, 23, white);
			Display->ClearBottom();
			Display->DisplayPlayerItems(playerInventory);
			return;
		}
		offset = cursorPosition.Y - 12;
		itemUsed = playerInventory[offset];
		if (!escapeWasPressed)
		{
			if (!itemUsed->GetKeep())
			{
				SlideDown(playerInventory, offset);
				playerInventory.pop_back();
				Display->DisplayText("                   ", 13, static_cast<short>(12 + playerInventory.size()), white);
			}


			switch (itemUsed->GetType())
			{
			case 0:
				Num = 25;
				player->SetHitPoints(player->GetCurrentHitPoints() + Num);
				Display->DisplayText("You were healed: ", 13, 8, white); cout << Num;
				Display->DisplayCure(Num);
				break;
			case 1:
				Num = 15;
				player->SetKa(player->GetCurrentKa() + Num);
				Display->DisplayText("Ka recovered: ", 13, 8, white); cout << Num;
				Display->DisplayCure(Num);
				break;
			case 2:
				Num = rand() % 5 + 1;
				player->SetStrength(player->GetStrength() + Num);
				Display->DisplayText("Your strength has increased", 13, 8, white);
				Sleep(Settings->GetPauseDuration());
				break;
			case 3:
				Num = rand() % 5 + 1;
				player->SetMind(player->GetMind() + Num);
				Display->DisplayText("Your mind powers have increased", 13, 8, white);
				Sleep(Settings->GetPauseDuration());
				break;
			case 4:
				Num = 75;
				player->SetHitPoints(player->GetCurrentHitPoints() + Num);
				Display->DisplayText("You were healed: ", 13, 8, white); cout << Num;
				Display->DisplayCure(Num);
				break;
			case 5:
				Num = 150;
				player->SetHitPoints(player->GetCurrentHitPoints() + Num);
				Display->DisplayText("You were healed: ", 13, 8, white); cout << Num;
				Display->DisplayCure(Num);
				break;
			case 6:
				Num = player->GetMaxHitPoints() - player->GetCurrentHitPoints();
				player->SetHitPoints(player->GetMaxHitPoints());
				Display->DisplayText("You were healed: ", 13, 8, white); cout << Num;
				Display->DisplayCure(Num);
			default:
				Display->DisplayText("This item does nothing", 13, 8, white);
				Sleep(Settings->GetPauseDuration());
				break;
			}
			itemWasUsed = true;
			Display->ClearTopBelow(2);
			if (isFighting)
				escapeWasPressed = true;
		}

	}// End While escapeWasPressed && playerInventory.size() > 0
	Display->ClearBottom();
}
void MainMenuSystem::MagicMenu(Player* player, vector<Magic*>& spells)
{
	int choice = 0;
	int offset = 0;
	unsigned int i;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition;

	while (!escapeWasPressed)
	{
		Display->ClearAll();
		Display->DisplayPlayerInfo(player);
		cursorPosition.X = 14;
		cursorPosition.Y = 13;
		selectionWasMade = false;
		Display->DisplayText("/----------------\\", 13, 12, green);
		Display->DisplayText("|                |", 13, 13, green);
		Display->DisplayText("|                |", 13, 14, green);
		Display->DisplayText("|                |", 13, 15, green);
		Display->DisplayText("|                |", 13, 16, green);
		Display->DisplayText("|                |", 13, 17, green);
		Display->DisplayText("|                |", 13, 18, green);
		Display->DisplayText("|                |", 13, 19, green);
		Display->DisplayText("|                |", 13, 20, green);
		Display->DisplayText("|                |", 13, 21, green);
		Display->DisplayText("|                |", 13, 22, green);
		Display->DisplayText("\\----------------/", 13, 23, green);


		for (i = 0; i < spells.size(); i++)
		{
			if (spells[i]->GetIsInFight() || player->GetCurrentKa() < spells[i]->GetCost())
			{
				Display->DisplaySpellName(spells[i]->GetName(), i + 13, dkgreen);
			}
			else
				Display->DisplaySpellName(spells[i]->GetName(), i + 13, green);			
		}
		DrawCursor(cursorPosition, yellow, 175);
		offset = cursorPosition.Y - 13;
		Display->DisplayCastingCost(spells[offset]->GetCost());
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, escapeWasPressed, 13, 12 + static_cast<int>(spells.size())))
			{
				DrawCursor(cursorPosition, yellow, 175);
				offset = cursorPosition.Y - 13;
				Display->DisplayCastingCost(spells[offset]->GetCost());
			}
		} while (!selectionWasMade);

		if (escapeWasPressed)
			return;
		
		offset = cursorPosition.Y - 13;
		if (spells[offset]->GetIsInFight())
		{
			Display->DisplayTextAndPause("That spell can only be used in battle", 13, 9, white);
		}
		else if (player->GetCurrentKa() < spells[offset]->GetCost())
		{
			Display->DisplayTextAndPause("Not enough Ka", 13, 9, white);
		}
		else
			spells[offset]->Cast(player, NULL, Display);
	}//==================================End of While loop==================================
}

void MainMenuSystem::InFightMagicMenu(Player* player, Creature* enemy, vector<Magic*>& spells, bool& pressedEscape)
{
	int choice = 0;
	int offset = 0;
	unsigned int i;
	bool selectionWasMade = false;
	COORD cursorPosition;

	pressedEscape = false;
	while (!pressedEscape)
	{
		cursorPosition.X = 14;
		cursorPosition.Y = 13;
		selectionWasMade = false;
		Display->DisplayText("/----------------\\", 13, 12, green);
		Display->DisplayText("|                |", 13, 13, green);
		Display->DisplayText("|                |", 13, 14, green);
		Display->DisplayText("|                |", 13, 15, green);
		Display->DisplayText("|                |", 13, 16, green);
		Display->DisplayText("|                |", 13, 17, green);
		Display->DisplayText("|                |", 13, 18, green);
		Display->DisplayText("|                |", 13, 19, green);
		Display->DisplayText("|                |", 13, 20, green);
		Display->DisplayText("|                |", 13, 21, green);
		Display->DisplayText("|                |", 13, 22, green);
		Display->DisplayText("\\----------------/", 13, 23, green);

		for (i = 0; i < spells.size(); i++)
		{
			if (spells[i]->GetIsInFight() || player->GetCurrentKa() < spells[i]->GetCost())
			{
				Display->DisplaySpellName(spells[i]->GetName(), i + 13, dkgreen);
			}
			else
				Display->DisplaySpellName(spells[i]->GetName(), i + 13, green);
		}
		Display->DisplayCastingCost(spells[offset]->GetCost());
		DrawCursor(cursorPosition, yellow, 175);
		do
		{
			if (MoveCursor(cursorPosition, selectionWasMade, pressedEscape, 13, 12 + static_cast<int>(spells.size())))
			{
				DrawCursor(cursorPosition, yellow, 175);
				offset = cursorPosition.Y - 13;
				Display->DisplayCastingCost(spells[offset]->GetCost());
			}
		} while (!selectionWasMade);
		
		if (pressedEscape)
			return;
		
		offset = cursorPosition.Y - 13;
		if (player->GetCurrentKa() < spells[offset]->GetCost())
		{
			Display->DisplayText("Not enough Ka", 13, 9, white);
			Sleep(Settings->GetPauseDuration());
		}
		else
		{
			ClearTextBottomRight(11);
			Magic* castedSpell = spells[offset];
			Display->DisplayIncantation(castedSpell->GetDescription(), castedSpell->GetIncantation());
			castedSpell->Cast(player, enemy, Display);
			return;
		}
	}//==================================End of While loop==================================
}

bool MainMenuSystem::TalkTo(Greeting* greeting, int pauseDuration)
{
	int choice;
	int X = 13;
	bool bSel;
	bool bEsc;
	COORD CursPos;

	Display->ClearTopRight();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	Display->DisplayText(greeting->GetIntroduction(), 13, 11, white);
	Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|  Talk   |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|  Fight  |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|         |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|         |", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("           ", 1, 17, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	DrawCursor(CursPos, yellow, 175);
	do
	{
		if (MoveCursor(CursPos, bSel, bEsc, 12, X))
		{
			DrawCursor(CursPos, yellow, 175);
		}
	} while (!bSel);
	choice = CursPos.Y;
	switch (choice)
	{
	case 12:
		Display->DisplayText(greeting->GetDetails(), 13, 9, white);
		Sleep(pauseDuration);
		return greeting->GetIsHostile();
		break;
	case 13:
		return true;
		break;
	}
}

void MainMenuSystem::ClearTextBottomRight(int Y)
{
	while (Y < 24)
	{
		Display->DisplayText("                                                                 ", 13, Y, FOREGROUND_BLUE);
		Y++;
	}
}

//=========================================================================================================
//	This function moves all the elements of the playerInventory DOWN by one.
//After taking element X and putting it aside. It then puts element X at the end.
//Usually to pop the last element off.
//=========================================================================================================
void MainMenuSystem::SlideDown(vector<Item*>& playerInventory, int X)
{
	int Y = X + 1;
	Item* temp;

	temp = playerInventory[X];
	while (Y <= static_cast<int>(playerInventory.size() - 1))
	{
		playerInventory[X] = playerInventory[Y];
		X++;
		Y++;
	}
	playerInventory[playerInventory.size() - 1] = temp;
}

void MainMenuSystem::DrawCursor(COORD pos, WORD color, unsigned char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << curs;
	pos.X = 78;
	pos.Y = 24;
	SetConsoleCursorPosition(OutputH, pos);
}

bool MainMenuSystem::MoveCursor(COORD& CursPos, bool& bSelect, bool& bEsc, int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursPos;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord, 1, &Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if (InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			if (CursPos.Y < Ymax)
			{
				CursPos.Y++;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymin;
				bCursMov = true;
			}
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if (CursPos.Y > Ymin)
			{
				CursPos.Y--;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymax;
				bCursMov = true;
			}
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bCursMov = false;
			bSelect = true;
			bEsc = true;
		}
	}
	if (bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH, OldCursPos);
		cout << "  ";
		return true;
	}
	return false;
}