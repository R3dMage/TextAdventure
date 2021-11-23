#pragma once

#include <vector>
#include "Greeting.h"
#include "GameDisplay.h"
#include "ItemRepository.h"
#include "ISaveLoadGame.h"
#include "Player.h"
#include "Item.h"
#include "magic.h"
#include "MusicPlayer.h"
#include "GameSettings.h"
#include "GameState.h"

class MainMenuSystem
{
public:
	MainMenuSystem(GameDisplay* gameDisplay, ISaveLoadGame* gameSaver, ItemRepository* itemRepository, MusicPlayer* musicPlayer, GameSettings* settings);

	void TitleScreenMenu(GameState* gameState);
	bool YesOrNoPrompt();
	void HandleMainPlayerMenu(GameState* gameState);
	void HandleInventory(GameState* gameState);	
	void Equip(Player* player, vector<Item*>& playerInventory);
	void Drop(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, string);
	void DeleteItem(vector<Item*>& playerInventory);
	void Options(GameState* gameState);
	void OptionsMenu();
	void UseItem(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, bool bFight, bool& bLeave, string map);
	void Use(Player* player, vector<Item*>& playerInventory, bool& Iused, bool bFight);
	void MagicMenu(Player* player, vector<Magic*>& spells);
	void InFightMagicMenu(Player* player, Creature* enemy, vector<Magic*>& spells, bool& bEsc);
	bool TalkTo(Greeting* greeting, int pauseDuration);

	void ClearTextBottomRight(int);
	void SlideDown(vector<Item*>&, int);

	void DrawCursor(COORD pos, WORD color, unsigned char curs);
	bool MoveCursor(COORD& cursorPosition, bool& bSelect, bool& bEsc, int Ymin, int Ymax);

private:
	GameDisplay* Display;
	ISaveLoadGame* GameSaver;
	ItemRepository* Items;
	MusicPlayer* Music;
	GameSettings* Settings;
};