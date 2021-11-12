#include <Windows.h>
#include "VirtualMap.h"
#include "fstream"

using namespace std;

VirtualMap::VirtualMap(std::string name)
{
	MapName = name;
	LoadMap("./data/" + name + ".tgm");

	EmptyLocation = new Location();
	EmptyLocation->SetSummary("There is no path to follow");
}

PlayerEnvironment VirtualMap::GetPlayerEnvironment(int playerX, int playerY)
{
	PlayerEnvironment environment;
	
	int playerPosition = (playerY - 1) * MaxPositionX + playerX - 1;

	environment.PlayerLocation = Locations[playerPosition];

	if (playerPosition + MaxPositionX >= TotalLocations)
		environment.NorthOfPlayer = EmptyLocation;
	else
		environment.NorthOfPlayer = Locations[playerPosition + MaxPositionX];

	if (playerPosition - MaxPositionX < 0)
		environment.SouthOfPlayer = EmptyLocation;
	else
		environment.SouthOfPlayer = Locations[playerPosition - MaxPositionX];
	
	if (playerPosition % MaxPositionX == MaxPositionX - 1)
		environment.EastOfPlayer = EmptyLocation;
	else
		environment.EastOfPlayer = Locations[playerPosition + 1];
	
	if (playerPosition % MaxPositionX == 0)
		environment.WestOfPlayer = EmptyLocation;
	else
		environment.WestOfPlayer = Locations[playerPosition - 1];

	return environment;
}

int VirtualMap::GetMaxX()
{
	return MaxPositionX;
}

int VirtualMap::GetMaxY()
{
	return MaxPositionY;
}

void VirtualMap::LoadMap(std::string mapFileName)
{
	ifstream fin;
	string szHolder;

	COORD max = { 0,0 };
	int tempInt;

	Locations.clear();
	fin.open(mapFileName.c_str());
	fin >> szHolder >> IsTown;
	fin >> szHolder >> MusicFileName;
	while (!fin.eof())
	{
		Location* location = new Location;
				
		fin >> szHolder;
		if (szHolder == "P:")		// PLOT
		{
			location->SetHasPlot(true);
			fin >> szHolder;	location->SetPlotText(szHolder);
			fin >> szHolder;
		}
		if (szHolder == "MC:")		// MAP CHANGE
		{
			fin.get();
			location->SetIsMapChange(true);
			getline(fin, szHolder);
			location->SetMapChangeName(szHolder);
			fin >> szHolder >> tempInt;
			location->SetNeoX(tempInt);
			fin >> szHolder >> tempInt;
			location->SetNeoY(tempInt);
			fin >> szHolder;
		}
		if (szHolder == "Shop:")	// SHOP
		{
			fin.get();
			location->SetIsShop(true);
			getline(fin, szHolder);
			location->SetShopName(szHolder);
			fin >> szHolder;
		}
		if (szHolder == "X:")
		{
			fin >> tempInt;
			if (tempInt > max.X)
				max.X = tempInt;
			location->SetPositionX(tempInt);
			fin >> szHolder;
		}
		if (szHolder == "Y:")
		{
			fin >> tempInt;
			if (tempInt > max.Y)
				max.Y = tempInt;
			location->SetPositionY(tempInt);
			fin >> szHolder;
		}
		if (szHolder == "L:")		// Location description
		{
			fin.get();
			getline(fin, szHolder);
			location->SetDescription(szHolder);
			fin >> szHolder;
		}
		if (szHolder == "S:")		// Summary Description
		{
			fin.get();
			getline(fin, szHolder);
			location->SetSummary(szHolder);
		}
		Locations.push_back(location);
	}
	MaxPositionX = max.X;
	MaxPositionY = max.Y;
	TotalLocations = MaxPositionX * MaxPositionY;
}
