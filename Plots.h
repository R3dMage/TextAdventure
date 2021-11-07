#pragma once
#include <string>
#include "player.h"
#include "GameDisplay.h"

class Plots
{
public:
	Plots(GameDisplay* display);
	void Check(GameEvents* plotEventStates, std::string map, int PositionX, int PositionY);

private:
	GameDisplay* Display;
};