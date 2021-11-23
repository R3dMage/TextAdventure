#pragma once
#include <vector>

#include "item.h"
#include "player.h"
#include "magic.h"
#include "GameState.h"

class ISaveLoadGame
{
public:
	virtual void SaveGame(GameState* gameState) = 0;
	virtual void LoadGame(string filename, GameState* gameState) = 0;
};

