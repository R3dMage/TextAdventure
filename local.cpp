#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <fstream>			//For file accessing

#include "Local.h"

Surroundings::Surroundings()
{
	PositionX = 1;
	PositionY = 1;
	Script = "Class Created";
}
void Surroundings::SetScript(string sz1)
{
	Script = sz1;
}
void Surroundings::SetPositionX(int x)
{
	PositionX = x;
}

void Surroundings::SetPositionY(int y)
{
	PositionY = y;
}
string Surroundings::GetScript()
{
	return Script;
}
int Surroundings::GetPositionX()
{
	return PositionX;
}
int Surroundings::GetPositionY()
{
	return PositionY;
}

void Surroundings::Setup(string map)
{
	ifstream fin;
	bool foundLocation = false;
	int X2 = 0;
	int Y2 = 0;
	
	string szL;
	string displayText;
	string szHolder;

	fin.open(map.c_str());
	if(fin.fail())
	{
		cout << "ERROR ERROR ERROR";
		system("pause");
		exit(0);
	}
	fin.seekg(0);	

	while(!foundLocation)
	{
		fin >> szHolder;
		if(szHolder != "X:")
			if(szHolder == "MC:")
			{
				fin >> szHolder;
				fin >> szHolder >> szHolder;
				fin >> szHolder >> szHolder;
			}
			else
                fin >> szHolder;
		else
		{
			fin >> X2;
			fin >> szHolder;
			fin >> Y2;
			fin >> szHolder;
			getline(fin,szL);
			fin >> szHolder;
			getline(fin,displayText);
		}

		if(X2 == PositionX && Y2 == PositionY)
			foundLocation = true;
		if(fin.eof() && !foundLocation)
		{
			displayText = " there is no path to follow.";
			foundLocation = true;
		}
	}
	Script = displayText;
}