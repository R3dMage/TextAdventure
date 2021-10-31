#ifndef LOCATION_H
#define LOCATION_H


#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

void text(string szText, int X, int Y, WORD color);
void Number(int num,int X,int Y,WORD color);
void DrawCurs(COORD pos, WORD color, char curs);
bool MoveCurs2(COORD &CursPos, bool &bSelect, bool &bEsc,COORD Min, COORD Max);


class Location{
public:
	Location();
	void SetIsMapChange(bool);
	void SetIsShop(bool);
	void SetHasPlot(bool);
	void SetPositionX(int);
	void SetPositionY(int);
	void SetNeoX(int);
	void SetNeoY(int);
	void SetMapChangeName(string);
	void SetShopName(string);
	void SetDescription(string);
	void SetSummary(string);
	void SetPlotText(string);
	bool GetIsMapChange();
	bool GetIsShop();
	bool GetHasPlot();
	int GetPositionX();
	int GetPositionY();
	int GetNeoX();
	int GetNeoY();
	string GetMapChangeName();
	string GetShopName();
	string GetDescription();
	string GetSummary();
	string GetPlotText();

private:
	bool IsMapChange;
	bool IsShop;
	bool HasPlot;
	int PositionX;
	int PositionY;
	int NeoX;
	int NeoY;
	string MapChangeName;
	string ShopName;
	string Description;
	string Summary;
	string PlotText;
	string szChng;
	string DisplayValue;
};
#endif