//=============================================================================================================
// This one function sets the enemies for each and every map, since this is expandable I gave it
//it's own file. 2/21/05
//=============================================================================================================

#include "World.h"
#include "Creature.h"
#include "Enemies.h"



void World::SetupNcps(vector<Creature*> &npc,string mapName,int xMax, int yMax,GameEvents plot,RaceReactionIndex raceReaction,char*& musicFile)
{
	string MapInfo = mapName + ".ifo";
	unsigned int T;
	unsigned int i;
	

	npc.clear();
	T = xMax * yMax;
	T = T / 5;

	if(mapName == "elvencity" && raceReaction.Elf == 1)
	{
		npc.push_back(new ElvenWarrior);		npc[0]->setdontmove(true);		npc[0]->loadPos(3,2);
		npc.push_back(new ElvenWarrior);		npc[1]->setdontmove(true);		npc[1]->loadPos(3,2);
		npc.push_back(new ElvenMage);		npc[2]->setdontmove(true);		npc[2]->loadPos(3,2);
		musicFile = "woods.mp3";
	}
	if(mapName == "orccamp" && raceReaction.Orc == 1)
	{
		npc.push_back(new OrcSoldier);		npc[0]->setdontmove(true);		npc[0]->loadPos(4,2);
		npc.push_back(new OrcSoldier);		npc[1]->setdontmove(true);		npc[1]->loadPos(4,2);
		npc.push_back(new OrcSorceror);		npc[2]->setdontmove(true);		npc[2]->loadPos(4,2);
		musicFile = "woods.mp3";
	}
	if(mapName == "field")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new Goblin);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Snake);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "field1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new Adventurer);	npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName);
			i++;
			npc.push_back(new ElvenWarrior);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new OrcSoldier);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Ogre);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Troll);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Eagle);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "field2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new Knight);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ElvenMage);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new OrcSorceror);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new OrcWanderer);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Adventurer);	npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName); 
			i++;
			npc.push_back(new Wizard);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "road1")
	{
		npc.push_back(new Human);				npc[0]->loadPos(xMax,yMax);
		npc.push_back(new Adventurer);			npc[1]->loadPos(xMax,yMax);	npc[1]->setmap(mapName);
		musicFile = "town.mp3";
	}
	if(mapName == "road2")
	{
		npc.push_back(new Giant);				npc[0]->loadPos(xMax,yMax);
		npc.push_back(new Adventurer);			npc[1]->loadPos(xMax,yMax);	npc[1]->setmap(mapName);
		musicFile = "town.mp3";
	}
	if(mapName == "dwoods1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Elf);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Raven);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Raven);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Elf);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ElvenWarrior);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new ElvenMage);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new Raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods4")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new OrcSoldier);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new OrcSorceror);	npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new Raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods5" || mapName == "dwoods6")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Ogre);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Troll);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new GiantSpider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new Ghost);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new Raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if(mapName == "cemetary")
	{
		npc.push_back(new Skeleton);	npc[0]->loadPos(xMax,yMax);
		npc.push_back(new Ghoul);		npc[1]->loadPos(xMax,yMax);
		musicFile = "cemetary.mp3";
	}

	if (mapName == "catacombs1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Ghoul);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Skeleton);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Phantom);		npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Phantom);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Ghost);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Ghoul);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Ghost);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Phantom);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Skeleton);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs4")
	{
		for(i=0; i<T; i++)
		{
			if(i == 0)
			{	npc.push_back(new Vampire);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new Ghost);		npc[i]->loadPos(xMax,yMax);}
			i++;
			npc.push_back(new Phantom);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs5")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Vampire);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Vampire);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}


	if(mapName == "island1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new Giant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Treeman);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Nymph);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Eagle);	npc[i]->loadPos(xMax,yMax);			
		}		
		musicFile = "island.mp3";
	}

	if(mapName == "treealter" && !plot.Priest1)
	{
		npc.push_back(new WoodPriest); npc[npc.size()-1]->loadPos(2,1);
		musicFile = "island.mp3";
	}

	if(mapName == "icefield1" || mapName == "icefield2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new PolarBear);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new FrostGiant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new IceWizard);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Snowman);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new IceElf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new IceOrc);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "icefield.mp3";
	}
	if(mapName == "icehall")
	{
			npc.push_back(new ShrineGuard);	npc[0]->loadPos(xMax,yMax);
			npc.push_back(new RockGolem);	npc[1]->loadPos(xMax,yMax);
			musicFile = "icehall.mp3";
	}

	if(mapName == "iceshrine")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new RockGolem);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ShrineGuard);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new IceWizard);	npc[i]->loadPos(xMax,yMax);
		}
		if(!plot.Priest2)
			npc.push_back(new IcePriest); npc[npc.size()-1]->loadPos(10,10);
		musicFile = "icehall.mp3";
	}
	if(mapName == "icehall2" && !plot.BlueDragon)
	{
		npc.push_back(new BlueDragon); npc[npc.size()-1]->loadPos(1,10);
		musicFile = "icehall.mp3";
	}

	if(mapName == "mountainpath")
	{		
		npc.push_back(new FireOrc);	npc[0]->loadPos(xMax,yMax);
		npc.push_back(new FireElf);	npc[1]->loadPos(xMax,yMax);
		npc.push_back(new Cyclops);	npc[2]->loadPos(xMax,yMax);
		musicFile = "mountain.mp3";
	}
	if(mapName == "cave1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new FireDemon);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new FireOrc);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new FireElf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Magmaman);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "mountain.mp3";
	}
	if(mapName == "mtaltar" && !plot.Priest3)
	{
		npc.push_back(new FirePriest); npc[npc.size()-1]->loadPos(1,3);
		musicFile = "mountain.mp3";
	}

	if(mapName == "cave2" && !plot.RedDragon)
	{
		npc.push_back(new RedDragon); npc[npc.size()-1]->loadPos(10,2);
		musicFile = "mountain.mp3";
	}

	if(mapName == "tunnel")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new FireOrc);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Magmaman);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new FireElf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Cyclops);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new FireDemon); npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "mountain.mp3";
	}
	if(mapName == "island2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new Centipede);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Wyvern);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Hydra);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new IronGolem);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new OrcWanderer);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Adventurer); npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName);
		}
		musicFile = "island.mp3";
	}

    if(mapName == "island3")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new StormGiant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new SteelGolem);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Minotaur);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new Acolyte);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(!plot.Priest4){
				npc.push_back(new WindPriest); npc[i]->loadPos(xMax,yMax);}
			else{
				npc.push_back(new Minotaur); npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "island.mp3";
	}

	if(mapName == "temple")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Gargoyle);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "temple.mp3";
	}

	if(mapName == "temple2")
	{
		if(raceReaction.Elf == 3 && raceReaction.Human == 3)
		{
			npc.push_back(new GodOfLife);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Orc == 3 && raceReaction.Human == 3)
		{
			npc.push_back(new GodOfChaos);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Elf == 3 && raceReaction.Human == 0 || raceReaction.Orc == 3 && raceReaction.Human == 0)
		{
			npc.push_back(new GodOfLife);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Elf == 0 && raceReaction.Orc == 0 && raceReaction.Human == 0)
		{
			npc.push_back(new GodOfLife);
			npc[0]->loadPos(3,5);
		}
		musicFile = "temple.mp3";
	}
}