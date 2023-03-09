#include <iostream>
#include "GameDisplay.h"

using namespace std;

GameDisplay::GameDisplay(GameSettings* settings) :
	TextDisplay(settings)
{
}

void GameDisplay::BoxScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, grey);

	COORD CursPos = { 0,0 };
	int num1 = 186;
	int num2 = 187;
	int num3 = 188;
	int num4 = 200;
	int num5 = 201;
	int num6 = 205;

	DrawScreen(CursPos, num5, num2, num3, num4, num1, num6, 78, 0, 24, 0);
}

// Draws border, then draws cross
void GameDisplay::DrawBoxWithCross()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, grey);

	COORD CursPos = { 0,0 };
	int num1 = 186;
	int num2 = 187;
	int num3 = 188;
	int num4 = 200;
	int num5 = 201;
	int num6 = 205;
	int num7 = 204;
	int num8 = 203;
	int num9 = 206;
	int num10 = 202;
	int num11 = 185;

	DrawScreen(CursPos, num5, num2, num3, num4, num1, num6, 78, 0, 24, 0);
	DrawCross(CursPos, num7, num8, num11, num10, num9, num6, num1, 78, 0, 24, 0);
}

// Draws a border around the game area
void GameDisplay::DrawScreen(COORD pos, char ULC, char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(OutputH, pos);
	cout << ULC;
	pos.X++;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X++;
	} while (pos.X < Xmax);
	cout << URC;
	pos.Y++;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y++;
	} while (pos.Y < Ymax);
	pos.Y = Ymax;
	SetConsoleCursorPosition(OutputH, pos);
	cout << LRC;
	pos.X--;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X--;
	} while (pos.X > Xmin);
	pos.X = 0;
	SetConsoleCursorPosition(OutputH, pos);
	cout << LLC;
	pos.Y--;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y--;
	} while (pos.Y > Ymin);
}

// Draws the lines across - PlayBox maybe the intent?
void GameDisplay::DrawCross(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.Y = 10;

	SetConsoleCursorPosition(OutputH, pos);
	cout << RC;
	pos.X++;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X++;
	} while (pos.X < Xmax);

	SetConsoleCursorPosition(OutputH, pos);
	cout << LC;
	pos.X = 12;
	pos.Y = Ymax;
	SetConsoleCursorPosition(OutputH, pos);
	cout << UC;
	pos.Y--;

	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y--;
	} while (pos.Y > Ymin);

	SetConsoleCursorPosition(OutputH, pos);
	cout << BC;
	pos.X = 12;
	pos.Y = 10;
	SetConsoleCursorPosition(OutputH, pos);
	cout << CTR;
}

void GameDisplay::ClearTopRight()
{
	int Y = 1;
	while (Y < 10)
	{
		DisplayText("                                                                 ", 13, Y, white);
		Y++;
	}
}

void GameDisplay::ClearAll()
{
	int Y = 1;
	while (Y < 10)
	{
		DisplayText("                                                                 ", 13, Y, white);
		DisplayText("           ", 1, Y, white);
		Y++;
	}
	Y = 11;
	while (Y < 24)
	{
		DisplayText("                                                                 ", 13, Y, white);
		DisplayText("           ", 1, Y, white);
		Y++;
	}
	DrawBoxWithCross();
}

//=====================================================================================
//	This function clears above the midline
//=====================================================================================
void GameDisplay::ClearTopBelow(int Y)
{
	while (Y < 10)
	{
		DisplayText("                                                                 ", 13, Y, white);
		Y++;
	}
}
//=====================================================================================
//	This function clears below the midline
//=====================================================================================
void GameDisplay::ClearBottom()
{
	int Y = 11;
	while (Y < 24)
	{
		DisplayText("                                                                 ", 13, Y, white);
		DisplayText("           ", 1, Y, white);
		Y++;
	}
}
//====================================================================================
// This function is the same as clr, WTF is with that?
//====================================================================================
void GameDisplay::ClearBottomRight()
{
	int Y = 11;
	while (Y < 24)
	{
		DisplayText("                                                                 ", 13, Y, white);
		Y++;
	}
}

void GameDisplay::HideCursor()
{
	DisplayText("", 78, 24, white);
}

void GameDisplay::HideCursorAndPause()
{
	HideCursor();
	Sleep(Settings->GetPauseDuration());
}

void GameDisplay::DrawCursor(COORD position, WORD color, unsigned char cursor)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);

	cout << cursor;
	position.X = 78;
	position.Y = 24;
	SetConsoleCursorPosition(OutputH, position);
}

string GameDisplay::GetFileName()
{
	string filename = "";
	DisplayText("Enter name of character: ", 13, 11, yellow);
	DisplayText("", 38, 11, white);
	cin >> filename;

	return filename;
}

void GameDisplay::DisplayTitleScreen()
{
	DisplayText(" Adventure of Lexi ", 28, 5, brown);
}

void GameDisplay::DisplayMessage(string message, WORD color)
{
	DisplayText(message, 13, 9, color);
}

void GameDisplay::DisplayCompass(int playerX, int playerY, int maxX, int maxY)
{
	DisplayText("/---------\\", 1, 11, cyan);
	DisplayText("|         |", 1, 12, cyan);
	DisplayText("|    |    |", 1, 13, cyan);
	DisplayText("| ---+--- |", 1, 14, cyan);
	DisplayText("|    |    |", 1, 15, cyan);
	DisplayText("|         |", 1, 16, cyan);
	DisplayText("\\---------/", 1, 17, cyan);

	if (playerY == maxY)
		DisplayText("N", 6, 12, blue);
	else
		DisplayText("N", 6, 12, cyan);
	if (playerY == 1)
		DisplayText("S", 6, 16, blue);
	else
		DisplayText("S", 6, 16, cyan);
	if (playerX == maxX)
	{
		DisplayText("E", 10, 14, blue);
	}
	else
	{
		DisplayText("E", 10, 14, cyan);
	}
	if (playerX == 1)
	{
		DisplayText("W", 2, 14, blue);
	}
	else
	{
		DisplayText("W", 2, 14, cyan);
	}
	DisplayText("", 78, 24, white);
}

void GameDisplay::DisplayLocation(PlayerEnvironment* playerEnvironment)
{
	ClearBottomRight();
	DisplayDescription(playerEnvironment->PlayerLocation->GetDescription());

	DisplayText("North", 13, 15, GetDirectionColor(playerEnvironment->NorthOfPlayer));
	DisplayText("South", 13, 16, GetDirectionColor(playerEnvironment->SouthOfPlayer));
	DisplayText("East", 13, 17, GetDirectionColor(playerEnvironment->EastOfPlayer));
	DisplayText("West", 13, 18, GetDirectionColor(playerEnvironment->WestOfPlayer));

	DisplayText(playerEnvironment->NorthOfPlayer->GetSummary(), 19, 15, white);
	DisplayText(playerEnvironment->SouthOfPlayer->GetSummary(), 19, 16, white);
	DisplayText(playerEnvironment->EastOfPlayer->GetSummary(), 18, 17, white);
	DisplayText(playerEnvironment->WestOfPlayer->GetSummary(), 18, 18, white);
}

void GameDisplay::DisplayDescription(string description)
{
	if (description.length() <= 65)
	{
		DisplayText(description, 13, 11, white);
		return;
	}

	DisplayLongDescription(description);
}

void GameDisplay::DisplayLongDescription(string description)
{
	string first;
	string second;
	string third;

	int i = 0;
	int j = 0;
	j = static_cast<int>(description.size() / 65);
	i = static_cast<int>(description.size() % 65);

	first = description.substr(0, 65);
	second = description.substr(65, i);

	if (j > 1)	//If there is more than 130 characters in the description
	{
		first = description.substr(0, 65);		//Creates a string out of the first 65 characters
		second = description.substr(65, 65);	//Creates a string out of the second 65 characters
		third = description.substr(130, i);		//Creates a string out of the third 65 characters
	}

	DisplayText(first, 13, 11, white);
	DisplayText(second, 13, 12, white);
	DisplayText(third, 13, 13, white);
}

WORD GameDisplay::GetDirectionColor(Location* location)
{
	if (location->GetIsMapChange())
		return green;

	return yellow;
}

void GameDisplay::DisplayPlayerInfo(Player* player)
{
	if (player->GetIsPoisoned())
		DisplayText(player->GetName() , 1, 1, green);
	else
		DisplayText(player->GetName(), 1, 1, white);
	DisplayText("HP:    ", 1, 2, white);
	DisplayText("Ka:    ", 1, 3, white);
	DisplayText("GP:    ", 1, 4, white);
	DisplayNumber(player->GetCurrentHitPoints(), 5, 2, white);
	DisplayText("/", 8, 2, white);
	DisplayNumber(player->GetMaxHitPoints(), 9, 2, white);
	DisplayNumber(player->GetCurrentKa(), 5, 3, white);
	DisplayText("/", 8, 3, white);
	DisplayNumber(player->GetMaxKa(), 9, 3, white);
	DisplayNumber(player->GetGold(), 5, 4, white);
	DisplayText("X:   ", 1, 6, white);
	DisplayText("Y:   ", 1, 7, white);
	DisplayNumber(player->GetPositionX(), 3, 6, white);
	DisplayNumber(player->GetPositionY(), 3, 7, white);
	DisplayText("           ", 1, 8, white);
	DisplayText("           ", 1, 9, white);
	DisplayText(player->GetWeapon()->GetName(), 1, 8, white);
	DisplayText(player->GetArmor()->GetName(), 1, 9, white);
}

void GameDisplay::DisplayPlayerStatus(Player* player)
{
	Weapon* weapon = player->GetWeapon();

	DisplayText("Name:   ", 13, 11, white);
	cout << player->GetName();
	DisplayText("HP:     ", 13, 12, white);
	cout << player->GetCurrentHitPoints() << "/" << player->GetMaxHitPoints();
	DisplayText("Str:    ", 13, 13, white);
	cout << player->GetStrength();
	DisplayText("Mind:   ", 13, 14, white);
	cout << player->GetMind();
	DisplayText("%Evade: ", 13, 15, white);
	cout << player->GetEvade();
	DisplayText("Kills:  ", 13, 16, white);
	cout << player->GetTotalKills();
	DisplayText("Weapon Damage: ", 13, 17, white);
	cout << weapon->GetDamageModifier() << " to " << weapon->GetDamageModifier() + weapon->GetDamage() - 1;
	DisplayText("Total Damage:  ", 13, 18, white);
	cout << weapon->GetDamageModifier() + 2 << " to " << weapon->GetDamage() + weapon->GetDamageModifier() + player->GetStrength() / 2 - 1;
	DisplayText("Level:  ", 31, 12, white);
	cout << player->GetLevel();
	DisplayText("Exp:    ", 31, 13, white);
	cout << player->GetExperience();
	DisplayText("NxtLev: ", 31, 14, white);
	cout << player->GetExperienceForNextLevel();
	DisplayText("Gold:   ", 31, 15, white);
	cout << player->GetGold();
	DisplayText("Orc Kills: ", 45, 12, white);
	cout << player->RaceKillCounts.OrcKillCount;
	DisplayText("Elf Kills: ", 45, 13, white);
	cout << player->RaceKillCounts.ElfKillCount;
	DisplayText("Hmn Kills: ", 45, 14, white);
	cout << player->RaceKillCounts.HumanKillCount;
	string god;
	switch (player->PlotEventStates.GodChoice)
	{
	case DeitySelection::CHAOS:
		god = "GOD OF CHAOS";
		break;
	case DeitySelection::DEATH:
		god = "GOD OF DEATH";
		break;
	case DeitySelection::NONE:
		god = "NO GOD";
		break;
	case DeitySelection::ORDER:
		god = "GOD OF ORDER";
		break;
	case DeitySelection::WAR:
		god = "GOD OF WAR";
		break;
	default:
		break;
	}
	DisplayText("Pledged to: ", 45, 15, white);
	cout << god;
	DisplayText("", 13, 23, white);
	system("pause");
}

void GameDisplay::DisplayCastingCost(int amount)
{
	DisplayText("       ", 1, 23, white);
	DisplayNumber(amount, 1, 23, white);
	DisplayText("ka", 4, 23, white);
}

void GameDisplay::DisplayIncantation(string description, string incantation)
{
	DisplayText("", 13, 9, white);
	SlowDisplay(incantation);
	DisplayText(description, 13, 11, white);
	Sleep(1500);
}

void GameDisplay::DisplaySpellName(string name, int yPosition, WORD color)
{
	DisplayText(name, 16, yPosition, color);
}

void GameDisplay::DisplayDamage(std::string message, int amount)
{
	int length = message.size() + 1;

	DisplayText("                                                                ", 13, 11, white);
	DisplayText(message, 13, 11, white);
	DisplayNumber(amount, 13 + length, 11, red);
	HideCursorAndPause();
}

void GameDisplay::DisplayCure(string message, int amount)
{
	int length = message.size() + 1;

	DisplayText("                                                                ", 13, 11, white);
	DisplayText(message, 13, 11, white);
	DisplayNumber(amount, 13 + length, 11, green);
	HideCursorAndPause();
}

void GameDisplay::DisplayPlayerItems(vector<Item*>& playerInventory)
{
	unsigned int offset = 0;
	DisplayText(" [---Items---] ", 13, 11, brown);
	while (offset < playerInventory.size())
	{
		DisplayText(playerInventory[offset]->GetName(), 15, 12 + offset, yellow);
		offset++;
		if (offset >= 12)
			break;
	}
}

void GameDisplay::DisplayItem(Item* item)
{
	DisplayText(item->Display(), 30, 11, white);
	DisplayCost(item->GetCost());
}

void GameDisplay::DisplayCost(int cost)
{
	DisplayText("Value: ", 1, 22, white);
	DisplayNumber(cost, 2, 23, white);
	cout << " GP  ";
}

void GameDisplay::DisplayItemsOnGround(vector<Item*> stuff, string map, Player* player)
{
	unsigned int Offset = 0;
	int NumItems = 0;
	DisplayText("[---Ground---]", 13, 1, brown);
	while (Offset < stuff.size())
	{
		if (stuff[Offset]->GetPositionY() == player->GetPositionY() && stuff[Offset]->GetPositionX() == player->GetPositionX() && stuff[Offset]->GetMapName() == map)
		{
			DisplayText(stuff[Offset]->GetName(), 15, 2 + NumItems, yellow);
			NumItems++;
		}
		Offset++;
		if (NumItems > 10)
			break;
	}
	DisplayText("", 78, 24, white);
}