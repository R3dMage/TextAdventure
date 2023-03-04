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
	GameDisplay(GameSettings* settings);
	void BoxScreen();
	void DrawBoxWithCross();

	void ClearTopRight();
	void ClearAll();
	void ClearTopBelow(int Y);
	void ClearBottom();
	void ClearBottomRight();
	void HideCursor();
	void HideCursorAndPause();

	std::string GetFileName();

	void DisplayTitleScreen();
	void DisplayMessage(std::string message, WORD color = white);
	void DisplayCompass(int playerX, int playerY, int maxX, int maxY);
	void DisplayLocation(PlayerEnvironment* playerEnvironment);
	void DisplayPlayerInfo(Player* player);
	void DisplayPlayerStatus(Player* player);
	void DisplayPlayerItems(std::vector<Item*>& playerInventory);
	void DisplayItem(Item* item);
	void DisplayItemsOnGround(std::vector<Item*> worldItems, std::string map, Player* player);

	void DisplayCastingCost(int amount);
	void DisplayIncantation(std::string description, string incantation);
	void DisplaySpellName(std::string name, int yPosition, WORD color);

	void DisplayDamage(std::string message, int amount);
	void DisplayCure(std::string, int amount);

private:
	void DrawCross(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);
	void DrawScreen(COORD pos, char ULC, char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin);
	
	void DisplayCost(int cost);
	void DisplayDescription(string description);
	void DisplayLongDescription(string description);
	WORD GetDirectionColor(Location* location);
};