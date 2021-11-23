#include <fstream>
#include "Plots.h"

using namespace std;

Plots::Plots(GameDisplay* display)
{
	Display = display;
}

void Plots::DisplayIntro()
{
	Display->DisplayText("In the past when gods could be bested by mortal men, ", 13, 2, white);
	Display->DisplayText("four priests are keeping the pantheon at bay and ruling", 13, 3, white);
	Display->DisplayText("the world for their own evil schemes. If the priests were ", 13, 4, white);
	Display->DisplayText("out of the picture however...", 13, 5, white);
	Display->DisplayText(" ", 13, 6, white);
	system("pause");
}

void Plots::DisplayPlot(string Map, string ID)
{
	int i = 3;
	ifstream fin;
	string szThing;
	string file = Map + ID + ".plt";
	string holder;
	string speaker = "[---";
	string spoken;
	fin.open(file.c_str());
	if (fin.fail())
	{
		Display->DisplayError("ERROR LOADING PLOT");
		exit(0);
	}
	fin >> szThing;
	fin.get();
	getline(fin, holder);
	speaker = speaker + holder + "---]";

	Display->DisplayText(speaker, 13, 1, brown);
	while (!fin.eof())
	{
		fin >> szThing;
		fin.get();
		getline(fin, spoken);
		Display->DisplayText(spoken, 13, i, white);
		spoken = " ";
		i++;
	}
	Display->DisplayText("", 13, 23, white);
	system("pause");
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