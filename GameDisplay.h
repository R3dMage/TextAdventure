#pragma once
#include <vector>

#include "TextDisplay.h"
#include "item.h"
#include "player.h"

class GameDisplay : public TextDisplay
{
public:	
	void BoxScreen();
	void DScreen();
	void DSScreen();
	void DrawScreen(COORD pos, char ULC, char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin);
	void ShopBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);
	void PBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);

	void clr();
	void clear();
	void clrtop(int Y);
	void clrbottom();
	void clritems();

	std::string GetFileName();
	void DisplayPlayerInfo(Player* player);
	void DisplayPlayerStatus(Player* player);
	void DisplayPlayerItems(std::vector<Item*>& playerInventory);
	void DisplayItem(Item* item);
	void ground(std::vector<Item*> worldItems, std::string map, int x, int y);

	void DisplayCastingCost(int amount);
	void DisplayIncantation(string description, string incantation);
	void DisplaySpellName(string name, int yPosition, WORD color);

	void DisplayError(string errorText);

private:
	void DisplayCost(int cost);
	void SlowDisplay(string szText);
};