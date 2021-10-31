#include "player.h"

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

/*================================================================================
	This function is designed to handle all the plots in the game
=================================================================================*/
void Player::plots(string map)
{
	if(map == "valesh" && X == 2 && Y == 1 && !PlotEventStates.Start)
	{
		clrtop(1);
		text("The town elder approaches you. He tells you of a priest who",13,2,white);
		text("went mad with power! Rumor has it that he went to an island",13,3,white);
		text("only accessable by ferry from Marintown. A fishing port to the",13,4,white);
		text("east. You must take the eastern road to get there. Good Luck.",13,5,white);
		text("", 13, 23,white);
		system("pause");
		clrtop(1);
		PlotEventStates.Start=true;
	}
}