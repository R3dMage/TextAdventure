#pragma once
#include <vector>
#include "TextDisplay.h"
#include "player.h"
#include "magic.h"

class SpellStore
{
public:
	SpellStore(TextDisplay* textDisplay);
	void AddSpell(Magic* newSpell);
	void CheckMagic(PlayerKillCounts killCounts, Player* player);

private:
	std::vector<Magic*> Spells;
	TextDisplay* Display;
	bool HasMagic(string spellName);
};