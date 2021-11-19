#pragma once
#include <Windows.h>
#include "GameDisplay.h"
#include "BaseMenuInputHandler.h"


class Menu
{
public:
	Menu(GameDisplay* display,BaseMenuInputHandler* inputHandler);
	bool SelectionWasMade();
	bool EscapeWasPressed();
	void Begin();
	bool GetMenuInput();
	void MoveCursorUp();
	void MoveCursorDown();
	void ClearOldCursor(COORD cursorPosition);
	void DrawCursor(COORD position, WORD color, unsigned char cursor);
	
private:
	COORD CursorPosition;
	bool SelectionMade;
	bool EscapePressed;
	int MaxPositionY;
	int MinPositionY;
	BaseMenuInputHandler* InputHandler;
	GameDisplay* Display;
};