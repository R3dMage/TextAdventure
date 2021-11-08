#include <iostream>
#include "TextDisplay.h"

using namespace std;

void TextDisplay::text(string szText, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << szText;
}

void TextDisplay::num(int num, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << num;
}

void TextDisplay::DisplayDamage(int amount)
{
	DisplayRunningNumber(amount, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void TextDisplay::DisplayCure(int amount)
{
	DisplayRunningNumber(amount, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void TextDisplay::DisplayRunningNumber(int amount, WORD color)
{
	int X = 13;
	while (X < 50)
	{
		num(amount, X, 9, color);
		Sleep(50);
		X++;
		text("   ", X - 1, 9, color);
	}
}