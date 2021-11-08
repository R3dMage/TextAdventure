#include "Greeting.h"

Greeting::Greeting(std::string introduction, std::string details, bool isHostile)
{
	Introduction = introduction;
	Details = details;
	IsHostile = isHostile;
}

std::string Greeting::GetIntroduction()
{
	return Introduction;
}

std::string Greeting::GetDetails()
{
	return Details;
}

bool Greeting::GetIsHostile()
{
	return IsHostile;
}
