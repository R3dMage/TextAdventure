#include "DeitySelectionHandler.h"

DeitySelectionHandler::DeitySelectionHandler(GameDisplay* gameDisplay, Player* player)
{
	Display = gameDisplay;
	PlayerCharacter = player;

	StartingX = 2;
	StartingY = 12;
	MaxY = 15;
	MinY = 12;
}

void DeitySelectionHandler::DisplayMenu(int currentY)
{
	Display->DisplayText("/---------\\", 1, 11, cyan);
	Display->DisplayText("|  Order  |", 1, 12, cyan);
	Display->DisplayText("|  Chaos  |", 1, 13, cyan);
	Display->DisplayText("|  War    |", 1, 14, cyan);
	Display->DisplayText("|  Death  |", 1, 15, cyan);
	Display->DisplayText("\\---------/", 1, 16, cyan);
}

void DeitySelectionHandler::DisplayInfo(int currentY)
{
	Display->ClearBottomRight();

	switch (currentY)
	{
	case 12:
		Display->DisplayText("Every day the orcs are corrupting this world closer to chaos!", 13, 12, green);
		Display->HideCursor();
		break;
	case 13:
		Display->DisplayText("I cannot abide the purity the elves bring!", 13, 12, yellow);
		Display->HideCursor();
		break;
	case 14:
		Display->DisplayText("Incite the humans to fight! Kill as many as you can!", 13, 12, red);
		Display->HideCursor();
		break;
	case 15:
		Display->DisplayText("Become my agent upon the land and recieve true power!", 13, 12, BACKGROUND_RED | BACKGROUND_INTENSITY );
		Display->HideCursor();
		break;
	default:
		Display->HideCursor();
		break;
	}
}

void DeitySelectionHandler::OnChoiceMade(int currentY)
{
	Display->ClearTopRight();

	Display->DisplayText(" Blinding light opens up around you.", 13, 2, white);
	Display->DisplayText(" You gaze upon the hall and you can feel the aura of protection", 13, 3, white);
	Display->DisplayText(" your new deity has cloaked you in. You feel filled with purpose", 13, 4, white);
	Display->DisplayText(" and ambition.", 13, 5, white);
	Display->DisplayText(" Now go forth, destroy the four priests and bring your God's", 13, 6, white);
	Display->DisplayText(" vision to the world.", 13, 7, white);
	Display->DisplayText("", 13, 8, white);
	system("pause");

	switch (currentY)
	{
	case 12:
		PlayerCharacter->PlotEventStates.GodChoice = DeitySelection::ORDER;
		break;
	case 13:
		PlayerCharacter->PlotEventStates.GodChoice = DeitySelection::CHAOS;
		break;
	case 14:
		PlayerCharacter->PlotEventStates.GodChoice = DeitySelection::WAR;
		break;
	case 15:
		PlayerCharacter->PlotEventStates.GodChoice = DeitySelection::DEATH;
		break;
	default:
		PlayerCharacter->PlotEventStates.GodChoice = DeitySelection::NONE;
		break;
	}
}
