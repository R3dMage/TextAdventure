#pragma once
#include <vector>

#include "TextDisplay.h"
#include "item.h"
#include "player.h"
#include "location.h"
#include "PlayerEnvironment.h"

class GameDisplay : public TextDisplay
{
public:	
	void BoxScreen();
	void DrawBoxWithCross();
	void DrawScreen(COORD pos, char ULC, char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin);
	void DrawCross(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);

	void ClearTopRight();
	void ClearAll();
	void ClearTopBelow(int Y);
	void ClearBottom();
	void ClearBottomRight();

	std::string GetFileName();
	void DisplayLocation(PlayerEnvironment* playerEnvironment);
	void DisplayPlayerInfo(Player* player);
	void DisplayPlayerStatus(Player* player);
	void DisplayPlayerItems(std::vector<Item*>& playerInventory);
	void DisplayItem(Item* item);
	void DisplayItemsOnGround(std::vector<Item*> worldItems, std::string map, int x, int y);

	void DisplayCastingCost(int amount);
	void DisplayIncantation(string description, string incantation);
	void DisplaySpellName(string name, int yPosition, WORD color);

	void DisplayError(string errorText);

private:
	void DisplayCost(int cost);
	void DisplayDescription(string description);
	void DisplayLongDescription(string description);
	WORD GetDirectionColor(Location* location);
};