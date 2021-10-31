//=============================================================================================================
// This one function sets the enemies for each and every map, since this is expandable I gave it
//it's own file. 2/21/05
//=============================================================================================================

#include "World.h"
#include "Creature.h"
#include "Enemies.h"



void World::SetupNcps(vector<creature*> &npc,string map,int maxX, int maxY,GameEvents plot,RaceReactionIndex godchoice,char*& MM,char* MapMusic)
{
	string MapInfo = map + ".ifo";
	unsigned int T;
	unsigned int i;
	

	npc.clear();
	T = maxX * maxY;
	T = T / 5;

	if(map == "elvencity" && godchoice.Elf == 1)
	{
		npc.push_back(new warrior);		npc[0]->setdontmove(true);		npc[0]->loadPos(3,2);
		npc.push_back(new warrior);		npc[1]->setdontmove(true);		npc[1]->loadPos(3,2);
		npc.push_back(new mage);		npc[2]->setdontmove(true);		npc[2]->loadPos(3,2);
		MM = "woods.mp3";
	}
	if(map == "orccamp" && godchoice.Orc == 1)
	{
		npc.push_back(new osoldier);		npc[0]->setdontmove(true);		npc[0]->loadPos(4,2);
		npc.push_back(new osoldier);		npc[1]->setdontmove(true);		npc[1]->loadPos(4,2);
		npc.push_back(new sorceror);		npc[2]->setdontmove(true);		npc[2]->loadPos(4,2);
		MM = "woods.mp3";
	}
	if(map == "field")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new goblin);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new snake);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "field.mp3";
	}
	if(map == "field1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new adventure);	npc[i]->loadPos(maxX,maxY);	npc[i]->setmap(map);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new osoldier);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new ogre);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "field.mp3";
	}
	if(map == "field2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new knight);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new mage);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new sorceror);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new adventure);	npc[i]->loadPos(maxX,maxY);	npc[i]->setmap(map); 
			i++;
			npc.push_back(new wizard);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "field.mp3";
	}
	if(map == "road1")
	{
		npc.push_back(new human);				npc[0]->loadPos(maxX,maxY);
		npc.push_back(new adventure);			npc[1]->loadPos(maxX,maxY);	npc[1]->setmap(map);
		MM = "town.mp3";
	}
	if(map == "road2")
	{
		npc.push_back(new giant);				npc[0]->loadPos(maxX,maxY);
		npc.push_back(new adventure);			npc[1]->loadPos(maxX,maxY);	npc[1]->setmap(map);
		MM = "town.mp3";
	}
	if(map == "dwoods1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "woods.mp3";
	}
	if (map == "dwoods2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "woods.mp3";
	}
	if (map == "dwoods3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new mage);		npc[i]->loadPos(maxX,maxY);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(maxX,maxY);}
		}
		MM = "woods.mp3";
	}
	if (map == "dwoods4")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new osoldier);npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new sorceror);	npc[i]->loadPos(maxX,maxY);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(maxX,maxY);}
		}
		MM = "woods.mp3";
	}
	if (map == "dwoods5" || map == "dwoods6")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ogre);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(maxX,maxY);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new ghost);		npc[i]->loadPos(maxX,maxY);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(maxX,maxY);}
		}
		MM = "woods.mp3";
	}
	if(map == "cemetary")
	{
		npc.push_back(new skel);	npc[0]->loadPos(maxX,maxY);
		npc.push_back(new ghoul);		npc[1]->loadPos(maxX,maxY);
		MM = "cemetary.mp3";
	}

	if (map == "catacombs1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghoul);		npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new phantom);		npc[i]->loadPos(maxX,maxY);
		}
		MM = "cemetary.mp3";
	}
	if (map == "catacombs2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new phantom);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new ghost);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new ghoul);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "cemetary.mp3";
	}
	if (map == "catacombs3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghost);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "cemetary.mp3";
	}
	if (map == "catacombs4")
	{
		for(i=0; i<T; i++)
		{
			if(i == 0)
			{	npc.push_back(new vampire);		npc[i]->loadPos(maxX,maxY);}
			else
			{	npc.push_back(new ghost);		npc[i]->loadPos(maxX,maxY);}
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "cemetary.mp3";
	}
	if (map == "catacombs5")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new vampire);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new vampire);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "cemetary.mp3";
	}


	if(map == "island1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new giant);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new treeman);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new nymph);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(maxX,maxY);			
		}		
		MM = "island.mp3";
	}

	if(map == "treealter" && !plot.Priest1)
	{
		npc.push_back(new woodpriest); npc[npc.size()-1]->loadPos(2,1);
		MM = "island.mp3";
	}

	if(map == "icefield1" || map == "icefield2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new pbear);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new frostgiant);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new snowman);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new iceelf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new iceorc);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "icefield.mp3";
	}
	if(map == "icehall")
	{
			npc.push_back(new shrineguard);	npc[0]->loadPos(maxX,maxY);
			npc.push_back(new rockgolem);	npc[1]->loadPos(maxX,maxY);
			MM = "icehall.mp3";
	}

	if(map == "iceshrine")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new rockgolem);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new shrineguard);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(maxX,maxY);
		}
		if(!plot.Priest2)
			npc.push_back(new icepriest); npc[npc.size()-1]->loadPos(10,10);
		MM = "icehall.mp3";
	}
	if(map == "icehall2" && !plot.BlueDragon)
	{
		npc.push_back(new bluedragon); npc[npc.size()-1]->loadPos(1,10);
		MM = "icehall.mp3";
	}

	if(map == "mountainpath")
	{		
		npc.push_back(new fireorc);	npc[0]->loadPos(maxX,maxY);
		npc.push_back(new fireelf);	npc[1]->loadPos(maxX,maxY);
		npc.push_back(new cyclops);	npc[2]->loadPos(maxX,maxY);
		MM = "mountain.mp3";
	}
	if(map == "cave1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new firedemon);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new fireorc);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new magmaman);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "mountain.mp3";
	}
	if(map == "mtaltar" && !plot.Priest3)
	{
		npc.push_back(new firepriest); npc[npc.size()-1]->loadPos(1,3);
		MM = "mountain.mp3";
	}

	if(map == "cave2" && !plot.RedDragon)
	{
		npc.push_back(new reddragon); npc[npc.size()-1]->loadPos(10,2);
		MM = "mountain.mp3";
	}

	if(map == "tunnel")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new fireorc);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new magmaman);npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new cyclops);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new firedemon); npc[i]->loadPos(maxX,maxY);
		}
		MM = "mountain.mp3";
	}
	if(map == "island2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new centipede);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wyvern);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new hydra);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new irongolem);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new adventure); npc[i]->loadPos(maxX,maxY);	npc[i]->setmap(map);
		}
		MM = "island.mp3";
	}

    if(map == "island3")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new stormgiant);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new steelgolem);npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new minator);	npc[i]->loadPos(maxX,maxY);
			i++;
			npc.push_back(new acolyte);	npc[i]->loadPos(maxX,maxY);
			i++;
			if(!plot.Priest4){
				npc.push_back(new windpriest); npc[i]->loadPos(maxX,maxY);}
			else{
				npc.push_back(new minator); npc[i]->loadPos(maxX,maxY);}
		}
		MM = "island.mp3";
	}

	if(map == "temple")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new gargoyle);	npc[i]->loadPos(maxX,maxY);
		}
		MM = "temple.mp3";
	}

	if(map == "temple2")
	{
		if(godchoice.Elf == 3 && godchoice.Human == 3)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		if(godchoice.Orc == 3 && godchoice.Human == 3)
		{
			npc.push_back(new godofchaos);
			npc[0]->loadPos(3,5);
		}
		if(godchoice.Elf == 3 && godchoice.Human == 0 || godchoice.Orc == 3 && godchoice.Human == 0)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		if(godchoice.Elf == 0 && godchoice.Orc == 0 && godchoice.Human == 0)
		{
			npc.push_back(new godoflife);
			npc[0]->loadPos(3,5);
		}
		MM = "temple.mp3";
	}
}





