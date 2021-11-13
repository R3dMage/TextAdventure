#include "Settings.h"

void GameSettings::SetPauseDuration(int pauseDuration)
{
	PauseDuration = pauseDuration;
}

int GameSettings::GetPauseDuration()
{
	return PauseDuration;
}

void GameSettings::SetVolume(int volume)
{
	Volume = volume;
}

int GameSettings::GetVolume()
{
	return Volume;
}