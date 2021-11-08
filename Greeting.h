#pragma once
#include <string>

class Greeting
{
public:
	Greeting(std::string introduction, std::string details, bool isHostile);
	std::string GetIntroduction();
	std::string GetDetails();
	bool GetIsHostile();

private:
	std::string Introduction;
	std::string Details;
	bool IsHostile;
};

