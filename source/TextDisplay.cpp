#include <iostream>
#include "TextDisplay.h"

using namespace std;

TextDisplay::TextDisplay(GameSettings* settings)
{
	Settings = settings;
}

void TextDisplay::DisplayText(string szText, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << szText;
}

void TextDisplay::DisplayTextAndPause(std::string text, short X, short Y, WORD color)
{
	DisplayText(text, X, Y, color);
	Sleep(Settings->GetPauseDuration());
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

void TextDisplay::DisplayError(string errorText)
{
	DisplayText(errorText, 13, 11, FOREGROUND_RED);
	system("pause");
}

void TextDisplay::SlowDisplay(string szText)
{
	for (unsigned int i = 0; i < szText.size(); i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}