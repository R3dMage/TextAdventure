#ifndef SCREEN_H
#define SCREEN_H

#include "Player.h"
#include "Creature.h"

void ShopBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.Y = 10;
	
	SetConsoleCursorPosition(OutputH, pos);
	cout << RC;
	pos.X ++;
    do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X ++;
	}while(pos.X < Xmax);

}

void PBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin)
{
	//COORD pos = {0,6};	
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.Y = 10;
	
	SetConsoleCursorPosition(OutputH, pos);
	cout << RC;
	pos.X ++;
    do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X ++;
	}while(pos.X < Xmax);

	SetConsoleCursorPosition(OutputH, pos);
	cout << LC;
	pos.X = 12;
	pos.Y = Ymax;
	SetConsoleCursorPosition(OutputH, pos);
	cout << UC;
	pos.Y --;

	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y --;
	}while(pos.Y > Ymin);

	SetConsoleCursorPosition(OutputH, pos);
	cout << BC;
	pos.X = 12;
	pos.Y = 10;
	SetConsoleCursorPosition(OutputH, pos);
	cout << CTR;

}

void DrawScreen(COORD pos,char ULC,char URC, char LRC, char LLC, char VL, char HL, int Xmax, int Xmin, int Ymax, int Ymin)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	

	SetConsoleCursorPosition(OutputH, pos);
	cout << ULC;
	pos.X ++;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X ++;
	}while(pos.X < Xmax);
	cout << URC;
	pos.Y ++;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y ++;
	}while(pos.Y < Ymax);
	pos.Y = Ymax;
	SetConsoleCursorPosition(OutputH, pos);
	cout << LRC;
	pos.X --;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << HL;
		pos.X --;
	}while(pos.X > Xmin);
	pos.X = 0;
	SetConsoleCursorPosition(OutputH, pos);
	cout << LLC;
	pos.Y --;
	do
	{
		SetConsoleCursorPosition(OutputH, pos);
		cout << VL;
		pos.Y --;
	}while(pos.Y > Ymin);
}

void BoxScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	

	COORD CursPos = {0,0};
	int num1 = 186;
	int num2 = 187;
	int num3 = 188;
	int num4 = 200;
	int num5 = 201;
	int num6 = 205;

	DrawScreen(CursPos,num5,num2,num3,num4,num1,num6,78,0,24,0);
}

void DScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);


	COORD CursPos = {0,0};
	int num1 = 186;
	int num2 = 187;
	int num3 = 188;
	int num4 = 200;
	int num5 = 201;
	int num6 = 205;
	int num7 = 204;
	int num8 = 203;
	int num9 = 206;
	int num10= 202;
	int num11= 185;

	DrawScreen(CursPos,num5,num2,num3,num4,num1,num6,78,0,24,0);
	PBox(CursPos,num7,num8,num11,num10,num9,num6,num1,78,0,24,0);
	//p2->info();
}
void DSScreen()
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);


	COORD CursPos = {0,0};
	int num1 = 186;
	int num2 = 187;
	int num3 = 188;
	int num4 = 200;
	int num5 = 201;
	int num6 = 205;
	int num7 = 204;
	int num8 = 203;
	int num9 = 206;
	int num10= 202;
	int num11= 185;

	DrawScreen(CursPos,num5,num2,num3,num4,num1,num6,78,0,24,0);
	ShopBox(CursPos,num7,num8,num11,num10,num9,num6,num1,78,0,24,0);
}

void DSScreen();
void DScreen();
void ShopBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);
void PBox(COORD pos, char RC, char BC, char LC, char UC, char CTR, char HL, char VL, int Xmax, int Xmin, int Ymax, int Ymin);
void DrawScreen(COORD,char,char,char,char,char,char,int,int,int,int);

#endif 