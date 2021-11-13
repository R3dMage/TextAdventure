#pragma once
#include<vector>
#include<string>
#include "location.h"
#include "PlayerEnvironment.h"

class VirtualMap
{
public:
	VirtualMap(std::string name);
	void LoadMap(std::string name);
	PlayerEnvironment GetPlayerEnvironment(int playerX, int playerY);
	int GetMaxX();
	int GetMaxY();
	std::string GetMusicFileName();

private:
	int MaxPositionX;
	int MaxPositionY;
	int TotalLocations;
	bool IsTown;
	Location* EmptyLocation;
	std::string MusicFileName;
	std::string MapName;
	std::vector<Location*> Locations;
};

