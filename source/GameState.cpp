#include "GameState.h"
#include "enemies.h"

GameState::GameState()
{
	player = new Player();
	Quit = false;
}

void GameState::NewGameState(ItemRepository* itemRepository, string playerName)
{
	player->SetName(playerName);
	player->SetArmor(itemRepository->GetArmor("Clothes"));
	player->SetWeapon(itemRepository->GetWeapon("Dagger"));

	Item* vial;
	vial = new Item;
	vial->SetName("Empty Vial");
	vial->SetMapName("forest1");
	vial->SetPositionX(5);
	vial->SetPositionY(5);
	vial->SetKeep(true);

	Item* horseshoe;
	horseshoe = new Item;
	horseshoe->SetName("Horseshoe");
	horseshoe->SetMapName("field");
	horseshoe->SetPositionX(5);
	horseshoe->SetPositionY(5);
	horseshoe->SetKeep(true);

	playerInventory.push_back(itemRepository->GetItem("Potion"));
	playerInventory.push_back(itemRepository->GetItem("Potion"));
	worldItems.push_back(vial);
	worldItems.push_back(horseshoe);

	monk.push_back(new Monk);					//This puts in THE only monk in the game.
	
	map = "valesh";

	string cheat = "rex";
	if (player->GetName() == cheat.c_str())
	{
		map = "icefield1";

		player->SetGold(5000);
		player->SetMaxHitPoints(500);
		player->SetHitPoints(500);
		player->SetMaxKa(100);
		player->SetKa(100);
		player->SetPositionX(5);
		player->SetPositionY(9);

		player->SetHasSpells(true);
		spells.push_back(new MinorHeal);
		spells.push_back(new MajorHeal);
		spells.push_back(new BriarBush);
		spells.push_back(new Blizzard);
		spells.push_back(new PerfectStorm);
		map = "island1";
		playerInventory.push_back(itemRepository->GetItem("+1 Scimitar"));
		playerInventory.push_back(itemRepository->GetItem("DeathSword"));
		playerInventory.push_back(itemRepository->GetItem("RedMail"));
	}
}

void GameState::LoadGameState()
{
	if (!player->PlotEventStates.Monk)
		monk.push_back(new Monk);					//This puts in THE only monk in the game.
	else
		monk.push_back(new Fly);
}

void GameState::PickupItems(GameDisplay* display)
{
	Item* temp;
	if (playerInventory.size() < 12)
	{
		for (unsigned int offset = 0; offset < worldItems.size(); offset++)
		{
			if (worldItems[offset]->GetPositionY() == player->GetPositionY() && worldItems[offset]->GetPositionX() == player->GetPositionX() && worldItems[offset]->GetMapName() == map)
			{
				playerInventory.push_back(worldItems[offset]);
				temp = worldItems[worldItems.size() - 1];
				worldItems[worldItems.size() - 1] = worldItems[offset];
				worldItems[offset] = temp;
				worldItems.pop_back();
				break;
			}
		}
		display->ClearTopBelow(2);
	}
	else
	{
		display->DisplayText("You do not have enough room!", 13, 9, white);
		Sleep(3000);
		display->DisplayText("                            ", 13, 9, white);
	}
}

void GameState::SetupNpcs(int xMax, int yMax)
{
	for (unsigned int i = 0; i < encounter.size(); i++)
	{
		delete encounter[i];
	}
	encounter = NpcCreator::SetupNpcs(map, xMax, yMax, player->PlotEventStates, player->RaceReactions);
}

void GameState::SetMapName(std::string mapName)
{
	map = mapName;
}

std::string GameState::GetMapName()
{
	return map;
}

Player* GameState::GetPlayer()
{
	return player;
}

std::vector<Creature*> GameState::GetCreatures()
{
	return encounter;
}

std::vector<Creature*> GameState::GetMonk()
{
	return monk;
}

std::vector<Item*>& GameState::GetPlayerInventory()
{
	return playerInventory;
}

std::vector<Item*>& GameState::GetWorldItems()
{
	return worldItems;
}

std::vector<Magic*>& GameState::GetPlayerSpells()
{
	return spells;
}

void GameState::SetQuit(bool quit)
{
	Quit = quit;
}

bool GameState::PlayerHasQuit()
{
	return Quit;
}
