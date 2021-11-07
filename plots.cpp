#include "Plots.h"

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

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

		Display->clrtop(1);
		Display->text("The town elder approaches you. He tells you of a priest who",13,2,white);
		Display->text("went mad with power! Rumor has it that he went to an island",13,3,white);
		Display->text("only accessable by ferry from Marintown. A fishing port to the",13,4,white);
		Display->text("east. You must take the eastern road to get there. Good Luck.",13,5,white);
		Display->text("", 13, 23,white);
		system("pause");
		Display->clrtop(1);
	}
}