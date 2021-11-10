#pragma once

#include <vector>
#include "Greeting.h"
#include "GameDisplay.h"
#include "ItemRepository.h"
#include "ISaveLoadGame.h"
#include "Player.h"
#include "Item.h"
#include "magic.h"

class MainMenuSystem
{
public:
	MainMenuSystem(GameDisplay* gameDisplay, ISaveLoadGame* gameSaver, ItemRepository* itemRepository);

	bool YesOrNoPrompt();
	void HandleMainMenu(Player* player, vector<Magic*>& spells, vector<Item*>& Stuff, vector<Item*>& playerInventory, string&);
	void HandleInventory(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, string);	
	void Equip(Player* player, vector<Item*>& playerInventory);
	void Drop(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, string);
	void DeleteItem(vector<Item*>& playerInventory);
	void Options(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& M, string& map);
	void OptionsMenu(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& M, string& map);
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
};

