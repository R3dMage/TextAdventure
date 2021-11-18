#include "Menu.h"
#include "TextDisplay.h"
#include <iostream>

using namespace std;

Menu::Menu(COORD initalPosition, BaseMenuInputHandler* inputHandler, int minY, int maxY)
{
	CursorPosition = initalPosition;
	InputHandler = inputHandler;
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

void Menu::Begin()
{
	while (!EscapePressed)
	{
		while (!SelectionMade)
		{
			InputHandler->DisplayMenu(CursorPosition.Y);
			DrawCursor(CursorPosition, yellow, 175);

			if (GetMenuInput())
			{
				InputHandler->DisplayMenu(CursorPosition.Y);
				DrawCursor(CursorPosition, yellow, 175);
			}

			if (EscapePressed)
				break;
		}
		InputHandler->OnChoiceMade(CursorPosition.Y);
	}
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
			InputHandler->OnKeyDown();
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
			InputHandler->OnKeyUp();
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
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
		{
			InputHandler->OnKeyLeft();
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
		{
			InputHandler->OnKeyRight();
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			InputHandler->OnSelect();
			cursorMoved = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			InputHandler->OnSelect();
			cursorMoved = false;
			SelectionMade = true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			InputHandler->OnEscape();
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

void Menu::DrawCursor(COORD position, WORD color, unsigned char cursor)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);

	cout << cursor;
	position.X = 78;
	position.Y = 24;
	SetConsoleCursorPosition(OutputH, position);
}
