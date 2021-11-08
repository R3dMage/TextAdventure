#pragma once
#include "GameDisplay.h"
#include "player.h"
#include "creature.h"

class FightDisplay : public GameDisplay
{
public:
	void DisplayAttackAnnouncement(Creature* enemy);
	void DisplayBanter(std::vector<string> speech);
	void DisplayMessage(string message, int pauseDuration);
	void DisplayMessageWithRedNumber(string message, int damage, int pauseDuration);
	void DisplayCreatureStatus(Creature* creature);
	void DisplayFightMenu();
	void DisplayWinContent(Player* player, Creature* enemy);
	void DisplayLevelUp(Player* player);

};

