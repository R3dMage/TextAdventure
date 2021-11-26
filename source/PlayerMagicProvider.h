#pragma once
#include <vector>
#include "TextDisplay.h"
#include "player.h"
#include "magic.h"

class PlayerMagicProvider
{
public:
	PlayerMagicProvider(TextDisplay* textDisplay);
	void CheckMagic(Player* player, vector<Magic*>& spells);

private:
	TextDisplay* Display;
	bool HasMagic(string spellName, vector<Magic*>& spells);
	void CheckChaos(Player* player, vector<Magic*>& spells);
	void CheckDeath(Player* player, vector<Magic*>& spells);
	void CheckOrder(Player* player, vector<Magic*>& spells);
	void CheckWar(Player* player, vector<Magic*>& spells);
};