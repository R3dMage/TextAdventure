#pragma once

#include <vector>
#include "Creature.h"
#include "Enemies.h"

class NpcCreator
{
public:
	static void SetupNpcs(std::vector<Creature*>& npc, string mapName, int xMax, int yMax, GameEvents plot, RaceReactionIndex raceReaction);
	static void ClearCreatures(std::vector<Creature*>& creatures);
};