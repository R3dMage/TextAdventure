#pragma once
#include <Windows.h>
#include <string>

class ITextDisplay
{
	virtual void DisplayText(std::string szText, short X, short Y, WORD color) = 0;
	virtual void DisplayTextAndPause(std::string text, short X, short Y, WORD color) = 0;
	virtual void DisplayNumber(int num, short X, short Y, WORD color) = 0;
	virtual void DisplayError(std::string errorText) = 0;
	virtual void SlowDisplay(std::string szText) = 0;
};