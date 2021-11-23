#pragma once

#include <vector>
#include "Creature.h"
#include "Enemies.h"

class NpcCreator
{
public:
	static std::vector<Creature*> SetupNpcs( string mapName, int xMax, int yMax, GameEvents plot, RaceReactionIndex raceReaction);
};