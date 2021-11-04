#pragma once
#include <vector>

#include "item.h"
#include "player.h"
#include "magic.h"

class ISaveLoadGame
{
public:
	virtual void SaveGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map) = 0;
	virtual void LoadGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map, string filename) = 0;
};

