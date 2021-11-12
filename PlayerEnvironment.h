#pragma once
#include "location.h"

class PlayerEnvironment
{
public:
	Location* PlayerLocation;
	Location* NorthOfPlayer;
	Location* SouthOfPlayer;
	Location* EastOfPlayer;
	Location* WestOfPlayer;
};

