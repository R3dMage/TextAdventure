#pragma once
class GameSettings
{
public:
	GameSettings();
	void SetPauseDuration(int pauseDuration);
	int GetPauseDuration();
	void SetVolume(int volume);
	int GetVolume();

private:
	int PauseDuration;
	int Volume;
};