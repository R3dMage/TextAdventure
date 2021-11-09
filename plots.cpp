#include "Plots.h"

Plots::Plots(GameDisplay* display)
{
	Display = display;
}

/*================================================================================
	This function is designed to handle all the plots in the game
=================================================================================*/
void Plots::Check(GameEvents* plotEventStates, string map, int PositionX, int PositionY)
{
	if(map == "valesh" && PositionX == 2 && PositionY == 1 && !plotEventStates->Start)
	{
		plotEventStates->Start = true;

		Display->ClearTopBelow(1);
		Display->DisplayText("The town elder approaches you. He tells you of a priest who",13,2,white);
		Display->DisplayText("went mad with power! Rumor has it that he went to an island",13,3,white);
		Display->DisplayText("only accessable by ferry from Marintown. A fishing port to the",13,4,white);
		Display->DisplayText("east. You must take the eastern road to get there. Good Luck.",13,5,white);
		Display->DisplayText("", 13, 23,white);
		system("pause");
		Display->ClearTopBelow(1);
	}
}