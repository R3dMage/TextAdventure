#include <iostream>
#include "TextDisplay.h"

using namespace std;

void TextDisplay::DisplayText(string szText, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << szText;
}

void TextDisplay::DisplayNumber(int num, short X, short Y, WORD color)
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
		DisplayNumber(amount, X, 9, color);
		Sleep(50);
		X++;
		DisplayText("   ", X - 1, 9, color);
	}
}

void TextDisplay::SlowDisplay(string szText)
{
	for (unsigned int i = 0; i < szText.size(); i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}