#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(COORD initalPosition, int minY, int maxY)
{
	CursorPosition = initalPosition;
	MaxPositionY = maxY;
	MinPositionY = minY;
	EscapePressed = false;
	SelectionMade = false;
}

int Menu::GetCurrentY()
{
	return CursorPosition.Y;
}

bool Menu::SelectionWasMade()
{
	return SelectionMade;
}

bool Menu::EscapeWasPressed()
{
	return EscapePressed;
}

bool Menu::GetMenuInput()
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursorPosition;
	DWORD Events = 0;
	HANDLE hInput;
	bool cursorMoved = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord, 1, &Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if (InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			cursorMoved = true;
			if (CursorPosition.Y < MaxPositionY)
			{
				CursorPosition.Y++;
			}
			else
			{
				CursorPosition.Y = MinPositionY;
			}
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			cursorMoved = true;
			if (CursorPosition.Y > MinPositionY)
			{
				CursorPosition.Y--;
			}
			else
			{
				CursorPosition.Y = MaxPositionY;
			}
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			cursorMoved = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			cursorMoved = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			cursorMoved = false;
			SelectionMade = true;
			EscapePressed = true;
		}
	}
	if (cursorMoved)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH, OldCursPos);
		cout << "  ";
		return true;
	}

	return false;
}
