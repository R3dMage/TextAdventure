#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include "Location.h"

;using namespace std;

#define green FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define ltgreen FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define black BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY

location::location()
{
	bMC =	false;
	bShop = false;
	bPlot = false;
	X =		0;
	Y =		0;
	NeoX =	0;
	NeoY =	0;
	szMC =  "+";
	szShop ="+";
	szLoc = "+";
	szSum = "+";
	szChng= "+";
	D =		"-";
}
void location::setbMC(bool B)
{
	bMC = B;
	if(bMC)
		D = 'M';
}
void location::setbPlot(bool B)
{
	bPlot = B;
}
void location::setbShop(bool B)
{
	bShop = B;
	if(bShop)
		D = 'S';
}
void location::setX(int N)
{
	X = N;
}
void location::setY(int N)
{
	Y = N;
}
void location::setNeoX(int N)
{
	NeoX = N;
}
void location::setNeoY(int N)
{
	NeoY = N;
}
void location::setszMC(string S)
{
	szMC = S;
}
void location::setszShop(string S)
{
	szShop = S;	
}
void location::setszP(string S)
{
	szP = S;
}
void location::setszLoc(string S)
{
	szLoc = S;
}
void location::setszSum(string S)
{
	szSum = S;
}
void location::setszChng(string S)
{
	szChng = S;
}
bool location::getbMC()
{
	return bMC;
}
bool location::getbShop()
{
	return bShop;
}
bool location::getbPlot()
{
	return bPlot;
}
int location::getX()
{
	return X;
}
int location::getY()
{
	return Y;
}
int location::getNeoX()
{
	return NeoX;
}
int location::getNeoY()
{
	return NeoY;
}
string location::getszMC()
{
	return szMC;
}
string location::getszShop()
{
	return szShop;
}
string location::getszLoc()
{
	return szLoc;
}
string location::getszSum()
{
	return szSum;
}
string location::getszChng()
{
	return szChng;
}
string location::getszP()
{
	return szP;
}






































































