#include <sstream>
#include "OptionsMenuHandler.h"

OptionsMenuHandler::OptionsMenuHandler(GameDisplay* gameDisplay, MusicPlayer* music, GameSettings* settings, ISaveLoadGame* loader)
{
	Display = gameDisplay;
	Music = music;
	Settings = settings;
	Loader = loader;
	StartingX = 2;
	StartingY = 12;
	MaxY = 14;
	MinY = 12;
}

void OptionsMenuHandler::DisplayMenu(int currentY)
{
	Display->DisplayText("/---------\\", 1, 11, cyan);
	Display->DisplayText("|  Music  |", 1, 12, cyan);
	Display->DisplayText("|  Speed  |", 1, 13, cyan);
	Display->DisplayText("|  Volume |", 1, 14, cyan);
	Display->DisplayText("|         |", 1, 15, cyan);
	Display->DisplayText("\\---------/", 1, 16, cyan);
}

void OptionsMenuHandler::DisplayInfo(int currentY)
{
	if (currentY == 12 && Music->GetIsMusicOn())
		Display->DisplayText("Music: On    ", 13, 12, yellow);
	else if (currentY == 12 && !Music->GetIsMusicOn())
		Display->DisplayText("Music: Off   ", 13, 12, yellow);

	if (currentY == 13) {
		stringstream stream;
		stream << "Speed: " << Settings->GetPauseDuration();
		Display->DisplayText(stream.str(), 13, 12, yellow);
	}

	if (currentY == 14) {
		stringstream stream;
		stream << "Volume " << Settings->GetVolume() << "  ";
		Display->DisplayText("              ", 13, 12, yellow);
		Display->DisplayText(stream.str(), 13, 12, yellow);
	}
	Display->DisplayText("", 78, 24, white);
}

void OptionsMenuHandler::OnKeyDown()
{
}

void OptionsMenuHandler::OnKeyUp()
{
}

void OptionsMenuHandler::OnKeyLeft()
{
	int volume = Settings->GetVolume();
	volume--;
	if (volume < 0)
		volume = 0;

	Settings->SetVolume(volume);
	Music->SetVolume(volume);
}

void OptionsMenuHandler::OnKeyRight()
{
	int volume = Settings->GetVolume();
	volume++;
	if (volume > 100)
		volume = 100;
	
	Settings->SetVolume(volume);
	Music->SetVolume(volume);
}

void OptionsMenuHandler::OnSelect()
{
}

void OptionsMenuHandler::OnEscape()
{
	Loader->SaveSettings(Settings);
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
	Display->DisplayText("", 78, 24, white);
}
