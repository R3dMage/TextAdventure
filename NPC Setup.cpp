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
		npc.push_back(new warrior);		npc[0]->setdontmove(true);		npc[0]->loadPos(3,2);
		npc.push_back(new warrior);		npc[1]->setdontmove(true);		npc[1]->loadPos(3,2);
		npc.push_back(new mage);		npc[2]->setdontmove(true);		npc[2]->loadPos(3,2);
		musicFile = "woods.mp3";
	}
	if(mapName == "orccamp" && raceReaction.Orc == 1)
	{
		npc.push_back(new osoldier);		npc[0]->setdontmove(true);		npc[0]->loadPos(4,2);
		npc.push_back(new osoldier);		npc[1]->setdontmove(true);		npc[1]->loadPos(4,2);
		npc.push_back(new sorceror);		npc[2]->setdontmove(true);		npc[2]->loadPos(4,2);
		musicFile = "woods.mp3";
	}
	if(mapName == "field")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new goblin);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new snake);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "field1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new adventure);	npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new osoldier);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ogre);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "field2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new knight);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new mage);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new sorceror);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new adventure);	npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName); 
			i++;
			npc.push_back(new wizard);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "field.mp3";
	}
	if(mapName == "road1")
	{
		npc.push_back(new human);				npc[0]->loadPos(xMax,yMax);
		npc.push_back(new adventure);			npc[1]->loadPos(xMax,yMax);	npc[1]->setmap(mapName);
		musicFile = "town.mp3";
	}
	if(mapName == "road2")
	{
		npc.push_back(new giant);				npc[0]->loadPos(xMax,yMax);
		npc.push_back(new adventure);			npc[1]->loadPos(xMax,yMax);	npc[1]->setmap(mapName);
		musicFile = "town.mp3";
	}
	if(mapName == "dwoods1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new mage);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods4")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new osoldier);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new sorceror);	npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if (mapName == "dwoods5" || mapName == "dwoods6")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ogre);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new ghost);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "woods.mp3";
	}
	if(mapName == "cemetary")
	{
		npc.push_back(new skel);	npc[0]->loadPos(xMax,yMax);
		npc.push_back(new ghoul);		npc[1]->loadPos(xMax,yMax);
		musicFile = "cemetary.mp3";
	}

	if (mapName == "catacombs1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghoul);		npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new phantom);		npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new phantom);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ghost);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ghoul);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghost);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs4")
	{
		for(i=0; i<T; i++)
		{
			if(i == 0)
			{	npc.push_back(new vampire);		npc[i]->loadPos(xMax,yMax);}
			else
			{	npc.push_back(new ghost);		npc[i]->loadPos(xMax,yMax);}
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}
	if (mapName == "catacombs5")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new vampire);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new vampire);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "cemetary.mp3";
	}


	if(mapName == "island1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new giant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new treeman);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new nymph);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(xMax,yMax);			
		}		
		musicFile = "island.mp3";
	}

	if(mapName == "treealter" && !plot.Priest1)
	{
		npc.push_back(new woodpriest); npc[npc.size()-1]->loadPos(2,1);
		musicFile = "island.mp3";
	}

	if(mapName == "icefield1" || mapName == "icefield2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new pbear);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new frostgiant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new snowman);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new iceelf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new iceorc);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "icefield.mp3";
	}
	if(mapName == "icehall")
	{
			npc.push_back(new shrineguard);	npc[0]->loadPos(xMax,yMax);
			npc.push_back(new rockgolem);	npc[1]->loadPos(xMax,yMax);
			musicFile = "icehall.mp3";
	}

	if(mapName == "iceshrine")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new rockgolem);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new shrineguard);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(xMax,yMax);
		}
		if(!plot.Priest2)
			npc.push_back(new icepriest); npc[npc.size()-1]->loadPos(10,10);
		musicFile = "icehall.mp3";
	}
	if(mapName == "icehall2" && !plot.BlueDragon)
	{
		npc.push_back(new bluedragon); npc[npc.size()-1]->loadPos(1,10);
		musicFile = "icehall.mp3";
	}

	if(mapName == "mountainpath")
	{		
		npc.push_back(new fireorc);	npc[0]->loadPos(xMax,yMax);
		npc.push_back(new fireelf);	npc[1]->loadPos(xMax,yMax);
		npc.push_back(new cyclops);	npc[2]->loadPos(xMax,yMax);
		musicFile = "mountain.mp3";
	}
	if(mapName == "cave1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new firedemon);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new fireorc);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new magmaman);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "mountain.mp3";
	}
	if(mapName == "mtaltar" && !plot.Priest3)
	{
		npc.push_back(new firepriest); npc[npc.size()-1]->loadPos(1,3);
		musicFile = "mountain.mp3";
	}

	if(mapName == "cave2" && !plot.RedDragon)
	{
		npc.push_back(new reddragon); npc[npc.size()-1]->loadPos(10,2);
		musicFile = "mountain.mp3";
	}

	if(mapName == "tunnel")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new fireorc);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new magmaman);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new cyclops);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new firedemon); npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "mountain.mp3";
	}
	if(mapName == "island2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new centipede);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wyvern);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new hydra);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new irongolem);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new adventure); npc[i]->loadPos(xMax,yMax);	npc[i]->setmap(mapName);
		}
		musicFile = "island.mp3";
	}

    if(mapName == "island3")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new stormgiant);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new steelgolem);npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new minator);	npc[i]->loadPos(xMax,yMax);
			i++;
			npc.push_back(new acolyte);	npc[i]->loadPos(xMax,yMax);
			i++;
			if(!plot.Priest4){
				npc.push_back(new windpriest); npc[i]->loadPos(xMax,yMax);}
			else{
				npc.push_back(new minator); npc[i]->loadPos(xMax,yMax);}
		}
		musicFile = "island.mp3";
	}

	if(mapName == "temple")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new gargoyle);	npc[i]->loadPos(xMax,yMax);
		}
		musicFile = "temple.mp3";
	}

	if(mapName == "temple2")
	{
		if(raceReaction.Elf == 3 && raceReaction.Human == 3)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Orc == 3 && raceReaction.Human == 3)
		{
			npc.push_back(new godofchaos);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Elf == 3 && raceReaction.Human == 0 || raceReaction.Orc == 3 && raceReaction.Human == 0)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		if(raceReaction.Elf == 0 && raceReaction.Orc == 0 && raceReaction.Human == 0)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		musicFile = "temple.mp3";
	}
}