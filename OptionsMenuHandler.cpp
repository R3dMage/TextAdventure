#include "OptionsMenuHandler.h"

OptionsMenuHandler::OptionsMenuHandler(GameDisplay* gameDisplay, MusicPlayer* music, GameSettings* settings)
{
	Display = gameDisplay;
	Music = music;
	Settings = settings;
}

void OptionsMenuHandler::DisplayMenu(int currentY)
{
	Display->DisplayText("/---------\\", 1, 11, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|  Music  |", 1, 12, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|  Speed  |", 1, 13, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|  Volume |", 1, 14, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("|         |", 1, 15, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Display->DisplayText("\\---------/", 1, 16, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	if (currentY == 12 && Music->GetIsMusicOn())
		Display->DisplayText("Music: On    ", 13, 12, yellow);
	else if (currentY == 12 && !Music->GetIsMusicOn())
		Display->DisplayText("Music: Off   ", 13, 12, yellow);

	if (currentY == 13) {
		Display->DisplayText("              ", 13, 12, yellow);
		Display->DisplayText("Speed: ", 13, 12, yellow);
		cout << Settings->GetPauseDuration();
	}
}

void OptionsMenuHandler::OnKeyDown()
{
}

void OptionsMenuHandler::OnKeyUp()
{
}

void OptionsMenuHandler::OnKeyLeft()
{
}

void OptionsMenuHandler::OnKeyRight()
{
}

void OptionsMenuHandler::OnSelect()
{
}

void OptionsMenuHandler::OnEscape()
{
}

void OptionsMenuHandler::OnChoiceMade(int currentY)
{
	switch (currentY)
	{
	case 12:
		Music->ToggleMusic();
		Display->DisplayText("               ", 13, 11, yellow);
		break;
	case 13:
		Display->DisplayText("Changing Speed?", 13, 11, yellow);
		Sleep(Settings->GetPauseDuration());
		Display->DisplayText("               ", 13, 11, yellow);
		break;
	case 14:
		Display->DisplayText("To be added later.", 13, 11, yellow);
		Sleep(Settings->GetPauseDuration());
		Display->DisplayText("               ", 13, 11, yellow);
		break;
	case 15:
		Display->DisplayText("To be added later.", 13, 11, yellow);
		Sleep(Settings->GetPauseDuration());
		Display->DisplayText("               ", 13, 11, yellow);
		break;
	}
}
