#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include "Location.h"

using namespace std;

#define green FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define ltgreen FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define black BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY

Location::Location()
{
	IsMapChange =	false;
	IsShop = false;
	HasPlot = false;
	PositionX =		0;
	PositionY =		0;
	NeoX =	0;
	NeoY =	0;
	MapChangeName =  "+";
	ShopName ="+";
	Description = "+";
	Summary = "+";
	DisplayValue =		"-";
}
void Location::SetIsMapChange(bool B)
{
	IsMapChange = B;
	if(IsMapChange)
		DisplayValue = 'M';
}
void Location::SetHasPlot(bool B)
{
	HasPlot = B;
}
void Location::SetIsShop(bool B)
{
	IsShop = B;
	if(IsShop)
		DisplayValue = 'S';
}
void Location::SetPositionX(int N)
{
	PositionX = N;
}
void Location::SetPositionY(int N)
{
	PositionY = N;
}
void Location::SetNeoX(int N)
{
	NeoX = N;
}
void Location::SetNeoY(int N)
{
	NeoY = N;
}
void Location::SetMapChangeName(string S)
{
	MapChangeName = S;
}
void Location::SetShopName(string S)
{
	ShopName = S;	
}
void Location::SetPlotText(string S)
{
	PlotText = S;
}
void Location::SetDescription(string S)
{
	Description = S;
}
void Location::SetSummary(string S)
{
	Summary = S;
}
bool Location::GetIsMapChange()
{
	return IsMapChange;
}
bool Location::GetIsShop()
{
	return IsShop;
}
bool Location::GetHasPlot()
{
	return HasPlot;
}
int Location::GetPositionX()
{
	return PositionX;
}
int Location::GetPositionY()
{
	return PositionY;
}
int Location::GetNeoX()
{
	return NeoX;
}
int Location::GetNeoY()
{
	return NeoY;
}
string Location::GetMapChangeName()
{
	return MapChangeName;
}
string Location::GetShopName()
{
	return ShopName;
}
string Location::GetDescription()
{
	return Description;
}
string Location::GetSummary()
{
	return Summary;
}
string Location::GetPlotText()
{
	return PlotText;
}






































































