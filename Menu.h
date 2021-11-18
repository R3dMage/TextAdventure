#pragma once
#include <Windows.h>
#include "BaseMenuInputHandler.h"


class Menu
{
public:
	Menu(COORD initalPosition, BaseMenuInputHandler* inputHandler, int minY, int maxY);
	int GetCurrentY();
	bool SelectionWasMade();
	bool EscapeWasPressed();
	void Begin();
	bool GetMenuInput();
	void DrawCursor(COORD position, WORD color, unsigned char cursor);
	
private:
	COORD CursorPosition;
	bool SelectionMade;
	bool EscapePressed;
	int MaxPositionY;
	int MinPositionY;
	BaseMenuInputHandler* InputHandler;
};