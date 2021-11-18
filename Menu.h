#pragma once
#include <Windows.h>


class Menu
{
public:
	Menu(COORD initalPosition, int minY, int maxY);
	int GetCurrentY();
	bool SelectionWasMade();
	bool EscapeWasPressed();
	bool GetMenuInput();
	
private:
	COORD CursorPosition;
	bool SelectionMade;
	bool EscapePressed;
	int MaxPositionY;
	int MinPositionY;
};