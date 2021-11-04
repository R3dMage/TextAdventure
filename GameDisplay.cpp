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

void GameDisplay::text(string szText, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << szText;
}