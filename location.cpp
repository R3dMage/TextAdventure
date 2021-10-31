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

Location::Location()
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
void Location::setbMC(bool B)
{
	bMC = B;
	if(bMC)
		D = 'M';
}
void Location::setbPlot(bool B)
{
	bPlot = B;
}
void Location::setbShop(bool B)
{
	bShop = B;
	if(bShop)
		D = 'S';
}
void Location::setX(int N)
{
	X = N;
}
void Location::setY(int N)
{
	Y = N;
}
void Location::setNeoX(int N)
{
	NeoX = N;
}
void Location::setNeoY(int N)
{
	NeoY = N;
}
void Location::setszMC(string S)
{
	szMC = S;
}
void Location::setszShop(string S)
{
	szShop = S;	
}
void Location::setszP(string S)
{
	szP = S;
}
void Location::setszLoc(string S)
{
	szLoc = S;
}
void Location::setszSum(string S)
{
	szSum = S;
}
void Location::setszChng(string S)
{
	szChng = S;
}
bool Location::getbMC()
{
	return bMC;
}
bool Location::getbShop()
{
	return bShop;
}
bool Location::getbPlot()
{
	return bPlot;
}
int Location::getX()
{
	return X;
}
int Location::getY()
{
	return Y;
}
int Location::getNeoX()
{
	return NeoX;
}
int Location::getNeoY()
{
	return NeoY;
}
string Location::getszMC()
{
	return szMC;
}
string Location::getszShop()
{
	return szShop;
}
string Location::getszLoc()
{
	return szLoc;
}
string Location::getszSum()
{
	return szSum;
}
string Location::getszChng()
{
	return szChng;
}
string Location::getszP()
{
	return szP;
}






































































