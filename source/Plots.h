#pragma once
#include <string>
#include "player.h"
#include "GameDisplay.h"
#include "GameState.h"
#include "VirtualMap.h"
#include "MusicPlayer.h"

class Plots
{
public:
	Plots(GameDisplay* display, GameState* state);
	void DisplayIntro();
	void DisplayPlot(std::string map, std::string ID);
	void Check(VirtualMap* map, Player* player, MusicPlayer* soundSystem);

private:
	GameDisplay* Display;
	GameState* CurrentState;
};