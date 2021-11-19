#include "Menu.h"
#include "TextDisplay.h"
#include <iostream>

using namespace std;

Menu::Menu(GameDisplay* display, BaseMenuInputHandler* inputHandler)
{
	Display = display;
	InputHandler = inputHandler;
	EscapePressed = false;
	SelectionMade = false;
	CursorPosition.X = inputHandler->GetStartingX();
	CursorPosition.Y = inputHandler->GetStartingY();
	MaxPositionY = inputHandler->GetMaxY();
	MinPositionY = inputHandler->GetMinY();
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
	InputHandler->DisplayMenu(CursorPosition.Y);
	InputHandler->DisplayInfo(CursorPosition.Y);
	DrawCursor(CursorPosition, yellow, 175);
	
	while (!EscapePressed && !SelectionMade)
	{

		if (GetMenuInput())
		{
			DrawCursor(CursorPosition, yellow, 175);
			InputHandler->DisplayInfo(CursorPosition.Y);
		}

		if (SelectionMade)
			InputHandler->OnChoiceMade(CursorPosition.Y);
	}
	
	Display->ClearBottomRight();
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
			MoveCursorDown();
			InputHandler->OnKeyDown();
			ClearOldCursor(OldCursPos);
			return true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			MoveCursorUp();
			InputHandler->OnKeyUp();
			ClearOldCursor(OldCursPos);
			return true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
		{
			InputHandler->OnKeyLeft();
			ClearOldCursor(OldCursPos);
			return true;
		}
		else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
		{
			InputHandler->OnKeyRight();
			ClearOldCursor(OldCursPos);
			return true;
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
			SelectionMade = false;
			EscapePressed = true;
		}
	}
	if (cursorMoved)
	{
		return true;
	}

	return false;
}

void Menu::MoveCursorUp()
{
	if (CursorPosition.Y > MinPositionY)
	{
		CursorPosition.Y--;
	}
	else
	{
		CursorPosition.Y = MaxPositionY;
	}
}

void Menu::MoveCursorDown()
{
	if (CursorPosition.Y < MaxPositionY)
	{
		CursorPosition.Y++;
	}
	else
	{
		CursorPosition.Y = MinPositionY;
	}
}

void Menu::ClearOldCursor(COORD cursorPosition)
{
	HANDLE	OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(OutputH, cursorPosition);
	cout << "  ";
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
