#include "FightDisplay.h"

void FightDisplay::DisplayAttackAnnouncement(Creature* enemy)
{
	text("You have been attacked by a ", 13, 11, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text(enemy->GetName(), 41, 11, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("", 13, 12, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("pause");
	clear();
}

void FightDisplay::DisplayBanter(std::vector<string> speech)
{
	clrtop(1);
	for (unsigned int i = 0; i < speech.size(); i++)
	{
		text(speech[i], 13, i + 1, white);
	}
	text(string(), 13, 23, white);
	system("pause");
	clrtop(1);
}

void FightDisplay::DisplayMessage(string message, int pauseDuration)
{
	text(message, 13, 11, white);
	text("", 79, 23, white);
	Sleep(pauseDuration);
	text("                     ", 13, 11, white);
}

void FightDisplay::DisplayMessageWithRedNumber(string message, int damage, int pauseDuration)
{
	text(message, 13, 11, white);
	num(damage, 45, 11, red);
	Sleep(pauseDuration);
}

void FightDisplay::DisplayCreatureStatus(Creature* creature)
{
	text(creature->GetName(), 13, 1, white);
	text("Level: ", 13, 2, white);
	text("HP:    ", 13, 3, white);
	text("Ka:    ", 13, 4, white);
	num(creature->GetLevel(), 20, 2, white);
	num(creature->GetHitPoints(), 17, 3, white);
	num(creature->GetKa(), 17, 4, white);
}

void FightDisplay::DisplayFightMenu()
{
	text("           ", 1, 11, white);
	text("           ", 1, 12, white);
	text("           ", 1, 13, white);
	text("                                                                 ", 13, 11, FOREGROUND_BLUE);
	text("/---------\\", 1, 14, ftext);
	text("|  Attack |", 1, 15, ftext);
	text("|  Magic  |", 1, 16, ftext);
	text("|  Item   |", 1, 17, ftext);
	text("|  Run    |", 1, 18, ftext);
	text("\\---------/", 1, 19, ftext);
}

void FightDisplay::DisplayWinContent(Player* player, Creature* enemy)
{
	text("The enemy has been slain", 13, 11, white);
	Sleep(player->GetPauseDuration());
	clear();

	text("After every enemy dies you get stuff!!!", 13, 9, green);
	text("Gold: ", 13, 11, green);
	text("Exp : ", 13, 12, green);
	num(enemy->GetGold(), 20, 11, green);
	num(enemy->GetExperience(), 20, 12, green);

	enemy->Win(player);
	Sleep(player->GetPauseDuration());
}

void FightDisplay::DisplayLevelUp(Player* player)
{
	clear();
	text("You have gone up in level!!", 13, 11, FOREGROUND_GREEN);
	text("", 79, 23, white);
	Sleep(player->GetPauseDuration());
}
