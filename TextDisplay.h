#pragma once
#include <Windows.h>
#include <string>

class TextDisplay
{
public:
	void text(std::string szText, short X, short Y, WORD color);
	void num(int num, short X, short Y, WORD color);
};

