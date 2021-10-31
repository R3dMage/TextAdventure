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
	void setbMC(bool);
	void setbShop(bool);
	void setbPlot(bool);
	void setX(int);
	void setY(int);
	void setNeoX(int);
	void setNeoY(int);
	void setszMC(string);
	void setszShop(string);
	void setszLoc(string);
	void setszSum(string);
	void setszChng(string);
	void setszP(string);
	bool getbMC();
	bool getbShop();
	bool getbPlot();
	int getX();
	int getY();
	int getNeoX();
	int getNeoY();
	int getPlot();
	string getszMC();
	string getszShop();
	string getszLoc();
	string getszSum();
	string getszChng();	
	string getszP();

private:
	bool bMC;
	bool bShop;
	bool bPlot;
	int X;
	int Y;
	int NeoX;
	int NeoY;
	string szMC;
	string szShop;
	string szLoc;
	string szSum;
	string szChng;
	string szP;
	string D;
};
#endif