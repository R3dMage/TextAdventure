#pragma once
#include <string>
#include "GameDisplay.h"
#include "MainMenuSystem.h"
#include "player.h"

class Lodging
{
public:
	Lodging(GameDisplay* display, MainMenuSystem* menu);
	void Enter(Player* player, std::string mapName);

private:
	GameDisplay* Display;
	MainMenuSystem* Menu;
	int Price;
};

