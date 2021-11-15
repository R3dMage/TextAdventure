#pragma once
class GameSettings
{
public:
	void SetPauseDuration(int pauseDuration);
	int GetPauseDuration();
	void SetVolume(int volume);
	int GetVolume();
	//void SetIsNewGame(bool isNewGame);
	//bool GetIsNewGame();

private:
	int PauseDuration;
	int Volume;
	bool IsNewGame;
};