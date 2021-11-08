#pragma once
#include <vector>

#include "TextDisplay.h"
#include "item.h"
#include "player.h"

#define box FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define dkgreen FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

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
	void DisplayDamage(int amount);
	void DisplayCure(int amount);

	void DisplayError(string errorText);

private:
	void DisplayHitPointUpdate(int amount, WORD color);
	void DisplayCost(int cost);
	void SlowDisplay(string szText);
};