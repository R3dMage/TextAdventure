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
};