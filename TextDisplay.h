#pragma once
#include <Windows.h>
#include <string>

#define box FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define dkgreen FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define compassColor FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

class TextDisplay
{
public:
	void DisplayText(std::string szText, short X, short Y, WORD color);
	void DisplayNumber(int num, short X, short Y, WORD color);
	void DisplayError(std::string errorText);
	void DisplayDamage(int amount);
	void DisplayCure(int amount);
	void SlowDisplay(std::string szText);

private:
	void DisplayRunningNumber(int amount, WORD color);
};