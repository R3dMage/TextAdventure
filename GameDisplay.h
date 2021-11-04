#pragma once
#include <Windows.h>
#include <string>
#include <vector>

#include "item.h"

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

	string GetFileName();
	void DisplayPlayerItems(vector<Item*>& playerInventory);
	void ground(vector<Item*> worldItems, string map, int x, int y);

	void text(std::string szText, short X, short Y, WORD color);
};