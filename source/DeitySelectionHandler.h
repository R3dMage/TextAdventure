#pragma once
#include "BaseMenuInputHandler.h"
#include "GameDisplay.h"
#include "player.h"

class DeitySelectionHandler : public BaseMenuInputHandler
{
public:
	DeitySelectionHandler(GameDisplay* gameDisplay, Player* player);

	virtual void DisplayMenu(int currentY) override;
	virtual void DisplayInfo(int currentY) override;
	virtual void OnChoiceMade(int currentY) override;

private:
	GameDisplay* Display;
	Player* PlayerCharacter;
};