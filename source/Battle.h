#pragma once
#include <string>
#include "enemies.h"
#include "player.h"
#include "item.h"
#include "MainMenuSystem.h"
#include "FightDisplay.h"
#include "ItemRepository.h"
#include "MusicPlayer.h"

class Battle
{
public:
	Battle(MainMenuSystem* menu, FightDisplay* fightDisplay, ItemRepository* itemRepository, MusicPlayer* musicPlayer);
	void Engage(Player* player, Creature* enemy, std::vector<Item*>& playerInventory, std::vector<Item*>& worldItems, std::vector<Magic*>& spells, std::string mapName);
	~Battle();

private:
	FightDisplay* Display;
	MainMenuSystem* Menu;
	ItemRepository* Items;
	MusicPlayer* Music;

	void PlayerAttack(Player* player, FightDisplay* fightDisplay, Creature* enemy);
	void PlayerMagic(Player* player, Creature* enemy, std::vector<Magic*>& spells, bool& escapePressed, bool &pass);
	bool RunAway(Player* player, Creature* enemy);
	void Win(FightDisplay* fightDisplay, Player* player, Creature* enemy, vector<Item*>& worldItems, string map);
};

