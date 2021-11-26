#include "NpcCreator.h"

vector<Creature*> NpcCreator::SetupNpcs(string mapName, int xMax, int yMax, GameEvents plot, RaceReactionIndex raceReaction)
{
	vector<Creature*> npc;
	string MapInfo = mapName + ".ifo";
	unsigned int totalMapLocations;
	unsigned int i;

	totalMapLocations = xMax * yMax;
	totalMapLocations = totalMapLocations / 5;

	if (mapName == "elvencity" && raceReaction.Elf == 1)
	{
		npc.push_back(new ElvenWarrior);	npc[0]->SetDontMove(true);		npc[0]->LoadPosition(3, 2);
		npc.push_back(new ElvenWarrior);	npc[1]->SetDontMove(true);		npc[1]->LoadPosition(3, 2);
		npc.push_back(new ElvenMage);		npc[2]->SetDontMove(true);		npc[2]->LoadPosition(3, 2);
	}
	if (mapName == "orccamp" && raceReaction.Orc == 1)
	{
		npc.push_back(new OrcSoldier);		npc[0]->SetDontMove(true);		npc[0]->LoadPosition(4, 2);
		npc.push_back(new OrcSoldier);		npc[1]->SetDontMove(true);		npc[1]->LoadPosition(4, 2);
		npc.push_back(new OrcSorceror);		npc[2]->SetDontMove(true);		npc[2]->LoadPosition(4, 2);
	}
	if (mapName == "field")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Goblin);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Snake);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "field1")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Adventurer);	npc[i]->LoadPosition(xMax, yMax);	npc[i]->SetMap(mapName);
			i++;
			npc.push_back(new ElvenWarrior);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new OrcSoldier);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Ogre);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Troll);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Eagle);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "field2")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Knight);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new ElvenMage);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new OrcSorceror);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new OrcWanderer);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Adventurer);	npc[i]->LoadPosition(xMax, yMax);	npc[i]->SetMap(mapName);
			i++;
			npc.push_back(new Wizard);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "road1")
	{
		npc.push_back(new Human);				npc[0]->LoadPosition(xMax, yMax);
		npc.push_back(new Adventurer);			npc[1]->LoadPosition(xMax, yMax);	npc[1]->SetMap(mapName);
	}
	if (mapName == "road2")
	{
		npc.push_back(new Giant);				npc[0]->LoadPosition(xMax, yMax);
		npc.push_back(new Adventurer);			npc[1]->LoadPosition(xMax, yMax);	npc[1]->SetMap(mapName);
	}
	if (mapName == "dwoods1")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Elf);		npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Raven);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "dwoods2")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Orc);		npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Raven);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "dwoods3")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Elf);		npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new ElvenWarrior);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			if (i % 5 == 1)
			{
				npc.push_back(new ElvenMage);		npc[i]->LoadPosition(xMax, yMax);
			}
			else
			{
				npc.push_back(new Raven);		npc[i]->LoadPosition(xMax, yMax);
			}
		}
	}
	if (mapName == "dwoods4")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Orc);		npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new OrcSoldier); npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			if (i % 5 == 1)
			{
				npc.push_back(new OrcSorceror);	npc[i]->LoadPosition(xMax, yMax);
			}
			else
			{
				npc.push_back(new Raven);		npc[i]->LoadPosition(xMax, yMax);
			}
		}
	}
	if (mapName == "dwoods5" || mapName == "dwoods6")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Ogre);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Troll);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			if (i % 5 == 1)
			{
				npc.push_back(new Ghost);		npc[i]->LoadPosition(xMax, yMax);
			}
			else
			{
				npc.push_back(new Raven);		npc[i]->LoadPosition(xMax, yMax);
			}
		}
	}
	if (mapName == "cemetary")
	{
		npc.push_back(new Skeleton);	npc[0]->LoadPosition(xMax, yMax);
		npc.push_back(new Ghoul);		npc[1]->LoadPosition(xMax, yMax);
	}

	if (mapName == "catacombs1")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Ghoul);		npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Skeleton);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Phantom);		npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "catacombs2")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Phantom);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Ghost);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Ghoul);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "catacombs3")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Ghost);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Phantom);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Skeleton);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "catacombs4")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			if (i == 0)
			{
				npc.push_back(new Vampire);		npc[i]->LoadPosition(xMax, yMax);
			}
			else
			{
				npc.push_back(new Ghost);		npc[i]->LoadPosition(xMax, yMax);
			}
			i++;
			npc.push_back(new Phantom);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "catacombs5")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Vampire);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Vampire);	npc[i]->LoadPosition(xMax, yMax);
		}
	}


	if (mapName == "island1")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Giant);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Treeman);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Nymph);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Eagle);	npc[i]->LoadPosition(xMax, yMax);
		}
	}

	if (mapName == "treealter" && !plot.Priest1)
	{
		npc.push_back(new WoodPriest); npc[npc.size() - 1]->LoadPosition(2, 1);
	}

	if (mapName == "icefield1" || mapName == "icefield2")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new PolarBear);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new FrostGiant);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new IceWizard);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Snowman);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new IceElf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new IceOrc);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "icehall")
	{
		npc.push_back(new ShrineGuard);	npc[0]->LoadPosition(xMax, yMax);
		npc.push_back(new RockGolem);	npc[1]->LoadPosition(xMax, yMax);
	}

	if (mapName == "iceshrine")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new RockGolem);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new ShrineGuard);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new IceWizard);	npc[i]->LoadPosition(xMax, yMax);
		}
		if (!plot.Priest2)
			npc.push_back(new IcePriest); npc[npc.size() - 1]->LoadPosition(10, 10);
	}
	if (mapName == "icehall2" && !plot.BlueDragon)
	{
		npc.push_back(new BlueDragon); npc[npc.size() - 1]->LoadPosition(1, 10);
	}

	if (mapName == "mountainpath")
	{
		npc.push_back(new FireOrc);	npc[0]->LoadPosition(xMax, yMax);
		npc.push_back(new FireElf);	npc[1]->LoadPosition(xMax, yMax);
		npc.push_back(new Cyclops);	npc[2]->LoadPosition(xMax, yMax);
	}
	if (mapName == "cave1")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new FireDemon);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new FireOrc);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new FireElf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Magmaman);	npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "mtaltar" && !plot.Priest3)
	{
		npc.push_back(new FirePriest); npc[npc.size() - 1]->LoadPosition(1, 3);
	}

	if (mapName == "cave2" && !plot.RedDragon)
	{
		npc.push_back(new RedDragon); npc[npc.size() - 1]->LoadPosition(10, 2);
	}

	if (mapName == "tunnel")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new FireOrc);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Magmaman); npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new FireElf);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Cyclops);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new FireDemon); npc[i]->LoadPosition(xMax, yMax);
		}
	}
	if (mapName == "island2")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Centipede);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Wyvern);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Hydra);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new IronGolem);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new OrcWanderer);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Adventurer); npc[i]->LoadPosition(xMax, yMax);	npc[i]->SetMap(mapName);
		}
	}

	if (mapName == "island3")
	{
		totalMapLocations = totalMapLocations / 2;
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new StormGiant);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new SteelGolem); npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Minotaur);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			npc.push_back(new Acolyte);	npc[i]->LoadPosition(xMax, yMax);
			i++;
			if (!plot.Priest4) {
				npc.push_back(new WindPriest); npc[i]->LoadPosition(xMax, yMax);
			}
			else {
				npc.push_back(new Minotaur); npc[i]->LoadPosition(xMax, yMax);
			}
		}
	}

	if (mapName == "temple")
	{
		for (i = 0; i < totalMapLocations; i++)
		{
			npc.push_back(new Gargoyle);	npc[i]->LoadPosition(xMax, yMax);
		}
	}

	if (mapName == "temple2")
	{
		if (plot.GodChoice == DeitySelection::ORDER)
		{
			npc.push_back(new GodOfLife);
			npc[0]->LoadPosition(3, 5);
		}
		if (plot.GodChoice == DeitySelection::CHAOS)
		{
			npc.push_back(new GodOfChaos);
			npc[0]->LoadPosition(3, 5);
		}
		if (plot.GodChoice == DeitySelection::WAR)
		{
			npc.push_back(new GodOfWar);
			npc[0]->LoadPosition(3, 5);
		}
		if (plot.GodChoice == DeitySelection::DEATH)
		{
			npc.push_back(new GodOfDeath);
			npc[0]->LoadPosition(3, 5);
		}
	}
	return npc;
}