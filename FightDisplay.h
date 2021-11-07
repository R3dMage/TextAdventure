#pragma once
#include "GameDisplay.h"
#include "player.h"
#include "creature.h"

#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

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

