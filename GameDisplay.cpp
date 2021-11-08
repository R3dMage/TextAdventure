#include <iostream>
#include "GameDisplay.h"

using namespace std;

void GameDisplay::BoxScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
void GameDisplay::DScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
	PBox(CursPos, num7, num8, num11, num10, num9, num6, num1, 78, 0, 24, 0);
}

// Draws border, then draws just the horizontal line
void GameDisplay::DSScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

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
	ShopBox(CursPos, num7, num8, num11, num10, num9, num6, num1, 78, 0, 24, 0);
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

// Draws a horizontal line at Y=10
void GameDisplay::ShopBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin)
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
}

// Draws the lines across - PlayBox maybe the intent?
void GameDisplay::PBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin)
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

void GameDisplay::clr()
{
	int Y = 11;
	while (Y < 24)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		Y++;
	}
}

void GameDisplay::clear()
{
	int Y = 1;
	while (Y < 10)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		text("           ", 1, Y, FOREGROUND_BLUE);
		Y++;
	}
	Y = 11;
	while (Y < 24)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		text("           ", 1, Y, FOREGROUND_BLUE);
		Y++;
	}
	DScreen();
}

//=====================================================================================
//	This function clears above the midline
//=====================================================================================
void GameDisplay::clrtop(int Y)
{
	while (Y < 10)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		Y++;
	}
}
//=====================================================================================
//	This function clears below the midline
//=====================================================================================
void GameDisplay::clrbottom()
{
	int Y = 11;
	while (Y < 24)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		text("           ", 1, Y, FOREGROUND_BLUE);
		Y++;
	}
}
//====================================================================================
// This function is the same as clr, WTF is with that?
//====================================================================================
void GameDisplay::clritems()
{
	int Y = 11;
	while (Y < 24)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		Y++;
	}
}

string GameDisplay::GetFileName()
{
	string filename = "";
	text("Enter name of character: ", 13, 11, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 38, 11, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cin >> filename;

	return filename;
}

void GameDisplay::DisplayPlayerInfo(Player* player)
{
	if (player->GetIsPoisoned())
		text(player->GetName() , 1, 1, green);
	else
		text(player->GetName(), 1, 1, white);
	text("HP:    ", 1, 2, white);
	text("Ka:    ", 1, 3, white);
	text("GP:    ", 1, 4, white);
	num(player->GetCurrentHitPoints(), 5, 2, white);
	text("/", 8, 2, white);
	num(player->GetMaxHitPoints(), 9, 2, white);
	num(player->GetCurrentKa(), 5, 3, white);
	text("/", 8, 3, white);
	num(player->GetMaxKa(), 9, 3, white);
	num(player->GetGold(), 5, 4, white);
	text("X:   ", 1, 6, white);
	text("Y:   ", 1, 7, white);
	num(player->GetPositionX(), 3, 6, white);
	num(player->GetPositionY(), 3, 7, white);
	text("           ", 1, 8, white);
	text("           ", 1, 9, white);
	text(player->GetWeapon()->GetName(), 1, 8, white);
	text(player->GetArmor()->GetName(), 1, 9, white);
}

void GameDisplay::DisplayPlayerStatus(Player* player)
{
	Weapon* weapon = player->GetWeapon();

	text("Name:   ", 13, 11, white);
	cout << player->GetName();
	text("HP:     ", 13, 12, white);
	cout << player->GetCurrentHitPoints() << "/" << player->GetMaxHitPoints();
	text("Str:    ", 13, 13, white);
	cout << player->GetStrength();
	text("Mind:   ", 13, 14, white);
	cout << player->GetMind();
	text("%Evade: ", 13, 15, white);
	cout << player->GetEvade();
	text("Kills:  ", 13, 16, white);
	cout << player->GetTotalKills();
	text("Weapon Damage: ", 13, 17, white);
	cout << weapon->GetDamageModifier() << " to " << weapon->GetDamageModifier() + weapon->GetDamage() - 1;
	text("Total Damage:  ", 13, 18, white);
	cout << weapon->GetDamageModifier() + 2 << " to " << weapon->GetDamage() + weapon->GetDamageModifier() + player->GetStrength() / 2 - 1;
	text("Level:  ", 31, 12, white);
	cout << player->GetLevel();
	text("Exp:    ", 31, 13, white);
	cout << player->GetExperience();
	text("NxtLev: ", 31, 14, white);
	cout << player->GetExperienceForNextLevel();
	text("Gold:   ", 31, 15, white);
	cout << player->GetGold();
	text("Orc Kills: ", 45, 12, white);
	cout << player->RaceKillCounts.OrcKillCount;
	text("Elf Kills: ", 45, 13, white);
	cout << player->RaceKillCounts.ElfKillCount;
	text("Hmn Kills: ", 45, 14, white);
	cout << player->RaceKillCounts.HumanKillCount;
	text("", 13, 23, white);
	system("pause");
}

void GameDisplay::DisplayCastingCost(int amount)
{
	text("       ", 1, 23, white);
	num(amount, 1, 23, white);
	text("ka", 4, 23, white);
}

void GameDisplay::DisplayIncantation(string description, string incantation)
{
	text("", 13, 9, white);
	SlowDisplay(incantation);
	text(description, 13, 11, white);
	Sleep(1500);
}

void GameDisplay::DisplaySpellName(string name, int yPosition, WORD color)
{
	text(name, 16, yPosition, color);
}

void GameDisplay::DisplayError(string errorText)
{
	text(errorText, 13, 11, FOREGROUND_RED);
	system("pause");
}

void GameDisplay::DisplayPlayerItems(vector<Item*>& playerInventory)
{
	unsigned int offset = 0;
	text(" [---Items---] ", 13, 11, FOREGROUND_RED | FOREGROUND_GREEN);
	while (offset < playerInventory.size())
	{
		text(playerInventory[offset]->GetName(), 15, 12 + offset, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		offset++;
		if (offset >= 12)
			break;
	}
}

void GameDisplay::DisplayItem(Item* item)
{
	switch (item->GetType())
	{
	case -1:
		text("                                           ", 30, 11, white);
		break;
	case 0:
		text("Heals 25 points of life                    ", 30, 11, white);
		break;
	case 1:
		text("Restores 5 to 10 point of ka", 30, 11, white);
		break;
	case 2:
		text("Increases Strength 1-5 points              ", 30, 11, white);
		break;
	case 3:
		text("Increases Mind 1-5 points                  ", 30, 11, white);
		break;
	case 4:
		text("Heals 75 points of life              ", 30, 11, white);
		break;
	case 5:
		("Heals 150 points of life              ", 30, 11, white);
		break;
	case 6:
		text("Heals all of your life              ", 30, 11, white);
		break;
	}
	DisplayCost(item->GetCost());
}

void GameDisplay::DisplayCost(int cost)
{
	text("Value: ", 1, 22, white);
	num(cost, 2, 23, white);
	cout << " GP  ";
}

void GameDisplay::SlowDisplay(string szText)
{
	for (unsigned int i = 0; i < szText.size(); i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}

void GameDisplay::ground(vector<Item*> stuff, string Map, int X, int Y)
{
	unsigned int Offset = 0;
	int NumItems = 0;
	text("[---Ground---]", 13, 1, FOREGROUND_RED | FOREGROUND_GREEN);
	while (Offset < stuff.size())
	{
		if (stuff[Offset]->GetPositionY() == Y && stuff[Offset]->GetPositionX() == X && stuff[Offset]->GetMapName() == Map)
		{
			text(stuff[Offset]->GetName(), 15, 2 + NumItems, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			NumItems++;
		}
		Offset++;
		if (NumItems > 10)
			break;
	}
	if (Offset < 10)
		text("                       ", 15, 3 + NumItems, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}