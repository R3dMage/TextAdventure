#pragma once
#include <string>
#include "enemies.h"
#include "player.h"
#include "item.h"
#include "MainMenuSystem.h"
#include "FightDisplay.h"
#include "ItemRepository.h"

class Battle
{
public:
	Battle(MainMenuSystem* menu, FightDisplay* fightDisplay, ItemRepository* itemRepository);
	void Encounter(Player* player, Creature* enemy, std::vector<Item*>& playerInventory, std::vector<Item*>& worldItems, std::vector<Magic*>& spells, std::string mapName);
	void PlayerAttack(Player* player, FightDisplay* fightDisplay, Creature* enemy);
	void Win(FightDisplay* fightDisplay, Player* player, Creature* enemy, vector<Item*>& worldItems, string map);
	~Battle();

private:
	FightDisplay* Display;
	MainMenuSystem* Menu;
	ItemRepository* Items;
};

