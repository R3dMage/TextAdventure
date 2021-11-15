#pragma once
#include <vector>
#include "ItemRepository.h"
#include "player.h"
#include "item.h"
#include "creature.h"
#include "magic.h"

class GameState
{
public:
	void InitializeState(ItemRepository* itemRepository, std::string playerName);
	void PickupItems(GameDisplay* display);

	Player* GetPlayer();
	void SetMapName(std::string mapName);
	std::string GetMapName();
	std::vector<Creature*> GetCreatures();
	std::vector<Creature*> GetMonk();
	std::vector<Item*> GetPlayerInventory();
	std::vector<Item*> GetWorldItems();
	std::vector<Magic*> GetPlayerSpells();

private:
	Player* player;
	std::string map;
	std::vector<Creature*> monk;				// This is a seperate vector for THE monk.
	std::vector<Item*> worldItems;				// Globals will contain ALL the items in the world
	std::vector<Item*> playerInventory;			// inv is the players inventory
	std::vector<Creature*> encounter;			// encounter holds all the enemies on a certain map
	std::vector<Magic*> spells;					// Magik will hold all the spells granted to the player
};