#pragma once
#include <Windows.h>
#include <string>
#include <vector>

#include "item.h"

#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

class GameDisplay
{
public:	
	void BoxScreen();
	void DScreen();
	void DSScreen();
	void DrawScreen(COORD pos, char ULC, char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin);
	void ShopBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);
	void PBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);

	void clear();
	void clrtop(int Y);
	void clrbottom();
	void clritems();

	std::string GetFileName();
	void DisplayPlayerItems(std::vector<Item*>& playerInventory);
	void DisplayItem(Item* item);
	void ground(std::vector<Item*> worldItems, std::string map, int x, int y);

	void text(std::string szText, short X, short Y, WORD color);
	void num(int num, short X, short Y, WORD color);

private:
	void DisplayCost(int cost);
};