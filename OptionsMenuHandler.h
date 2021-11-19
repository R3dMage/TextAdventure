#pragma once
#include "BaseMenuInputHandler.h"
#include "GameDisplay.h"
#include "MusicPlayer.h"
#include "GameSettings.h"

class OptionsMenuHandler : public BaseMenuInputHandler
{
public:
	OptionsMenuHandler(GameDisplay* gameDisplay, MusicPlayer* music, GameSettings* settings);

	virtual void DisplayMenu(int currentY) override;
	virtual void DisplayInfo(int currentY) override;
	virtual void OnKeyDown() override;
	virtual void OnKeyUp() override;
	virtual void OnKeyLeft() override;
	virtual void OnKeyRight() override;
	virtual void OnSelect() override;
	virtual void OnEscape() override;
	virtual void OnChoiceMade(int currentY) override;

private:
	GameDisplay* Display;
	MusicPlayer* Music;
	GameSettings* Settings;
};