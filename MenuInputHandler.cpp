#include "MenuInputHandler.h"
#include <iostream>

using namespace std;

MenuInputHandler::MenuInputHandler(COORD initalPosition, int minY, int maxY)
{
	CursorPosition = initalPosition;
	MaxPositionY = maxY;
	MinPositionY = minY;
}

int MenuInputHandler::GetCurrentY()
{
	return CursorPosition.Y;
}

bool MenuInputHandler::SelectionWasMade()
{
	return SelectionMade;
}

bool MenuInputHandler::EscapeWasPressed()
{
	return EscapePressed;
}

bool MenuInputHandler::MoveCursor()
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursorPosition;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord, 1, &Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if (InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			bCursMov = true;
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
			bCursMov = true;
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
			bCursMov = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bCursMov = false;
			SelectionMade = true;
			EscapePressed = true;
		}
	}
	if (bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH, OldCursPos);
		cout << "  ";
		return true;
	}

	return false;
}
