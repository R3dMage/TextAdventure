#pragma once
#include "GameDisplay.h"
#include "MainMenuSystem.h"

class PawnShop
{
public:
	PawnShop(GameDisplay* display, MainMenuSystem* menu);
	void Enter(Player* player, std::vector<Item*>& playerInventory, string mapName);

private:
	GameDisplay* Display;
	MainMenuSystem* Menu;
	const int CursorStartX = 13;
	const int CursorStartY = 12;
};