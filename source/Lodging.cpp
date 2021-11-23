#include <sstream>
#include "Lodging.h"

Lodging::Lodging(GameDisplay* display, MainMenuSystem* menu)
{
	Display = display;
	Menu = menu;
}

void Lodging::Enter(Player* player, string mapName)
{
	string nameOfInn;

	if (mapName == "valesh")					//Price and name of the inn in Valesh
	{
		Price = 55;
		nameOfInn = "Inn of the Lucky Whale";
	}
	if (mapName == "elvencity")				//Price and name of the inn in ElvenCity
	{
		Price = 105;
		nameOfInn = "Inn of warm dreams";
	}

	if (mapName == "marintown")				//Price and name of the inn in Marintown
	{
		Price = 155;
		nameOfInn = "Inn of Soft Love";
	}

	if (mapName == "yamashi")				//Price and name of the inn in Yamashi
	{
		Price = 255;
		nameOfInn = "Inn of the Mountain";
	}

	stringstream stream;
	stream << "[---" << nameOfInn << "---]";

	Display->ClearAll();
	Display->DisplayPlayerInfo(player);
	Display->DisplayText(stream.str(), 13, 1, brown);
	Display->DisplayText("One night: ", 13, 2, white); 
	Display->DisplayNumber(Price, 24, 2, yellow);

	bool stayAtTheInn = Menu->YesOrNoPrompt();

	if (!stayAtTheInn)
	{
		Display->DisplayTextAndPause("Sorry, maybe next time.                   ", 13, 11, white);
		return;
	}

	if (player->GetGold() < Price)
	{
		Display->DisplayTextAndPause("You have insufficient funds", 13, 11, yellow);
		return;
	}

	player->SetGold(player->GetGold() - Price);
	player->SetHitPoints(player->GetMaxHitPoints());
	player->SetKa(player->GetMaxKa());
	Display->DisplayTextAndPause("Pleasure doing business with you!", 13, 11, white);
	Display->ClearAll();
}
