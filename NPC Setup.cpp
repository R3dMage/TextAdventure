//=============================================================================================================
// This one function sets the enemies for each and every map, since this is expandable I gave it
//it's own file. 2/21/05
//=============================================================================================================

#include "world.h"
#include "creature.h"
#include "enemies.h"



void world::npcSetup(vector<creature*> &npc,string Map,int Xmax, int Ymax,GameEvents plot,RaceReactionIndex godchoice,char*& MM,char* MapMusic)
{
	string MapInfo = Map + ".ifo";
	unsigned int T;
	unsigned int i;
	

	npc.clear();
	T = Xmax * Ymax;
	T = T / 5;

	if(Map == "elvencity" && godchoice.Elf == 1)
	{
		npc.push_back(new warrior);		npc[0]->setdontmove(true);		npc[0]->loadPos(3,2);
		npc.push_back(new warrior);		npc[1]->setdontmove(true);		npc[1]->loadPos(3,2);
		npc.push_back(new mage);		npc[2]->setdontmove(true);		npc[2]->loadPos(3,2);
		MM = "woods.mp3";
	}
	if(Map == "orccamp" && godchoice.Orc == 1)
	{
		npc.push_back(new osoldier);		npc[0]->setdontmove(true);		npc[0]->loadPos(4,2);
		npc.push_back(new osoldier);		npc[1]->setdontmove(true);		npc[1]->loadPos(4,2);
		npc.push_back(new sorceror);		npc[2]->setdontmove(true);		npc[2]->loadPos(4,2);
		MM = "woods.mp3";
	}
	if(Map == "field")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new goblin);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new snake);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "field.mp3";
	}
	if(Map == "field1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new adventure);	npc[i]->loadPos(Xmax,Ymax);	npc[i]->setmap(Map);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new osoldier);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new ogre);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "field.mp3";
	}
	if(Map == "field2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new knight);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new mage);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new sorceror);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new adventure);	npc[i]->loadPos(Xmax,Ymax);	npc[i]->setmap(Map); 
			i++;
			npc.push_back(new wizard);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "field.mp3";
	}
	if(Map == "road1")
	{
		npc.push_back(new human);				npc[0]->loadPos(Xmax,Ymax);
		npc.push_back(new adventure);			npc[1]->loadPos(Xmax,Ymax);	npc[1]->setmap(Map);
		MM = "town.mp3";
	}
	if(Map == "road2")
	{
		npc.push_back(new giant);				npc[0]->loadPos(Xmax,Ymax);
		npc.push_back(new adventure);			npc[1]->loadPos(Xmax,Ymax);	npc[1]->setmap(Map);
		MM = "town.mp3";
	}
	if(Map == "dwoods1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "woods.mp3";
	}
	if (Map == "dwoods2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wolf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new raven);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "woods.mp3";
	}
	if (Map == "dwoods3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new elf);		npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new warrior);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new mage);		npc[i]->loadPos(Xmax,Ymax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(Xmax,Ymax);}
		}
		MM = "woods.mp3";
	}
	if (Map == "dwoods4")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new Orc);		npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new osoldier);npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new sorceror);	npc[i]->loadPos(Xmax,Ymax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(Xmax,Ymax);}
		}
		MM = "woods.mp3";
	}
	if (Map == "dwoods5" || Map == "dwoods6")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ogre);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new troll);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new gspider);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			if(i % 5 == 1)
			{	npc.push_back(new ghost);		npc[i]->loadPos(Xmax,Ymax);}
			else
			{	npc.push_back(new raven);		npc[i]->loadPos(Xmax,Ymax);}
		}
		MM = "woods.mp3";
	}
	if(Map == "cemetary")
	{
		npc.push_back(new skel);	npc[0]->loadPos(Xmax,Ymax);
		npc.push_back(new ghoul);		npc[1]->loadPos(Xmax,Ymax);
		MM = "cemetary.mp3";
	}

	if (Map == "catacombs1")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghoul);		npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new phantom);		npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "cemetary.mp3";
	}
	if (Map == "catacombs2")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new phantom);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new ghost);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new ghoul);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "cemetary.mp3";
	}
	if (Map == "catacombs3")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new ghost);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new skel);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "cemetary.mp3";
	}
	if (Map == "catacombs4")
	{
		for(i=0; i<T; i++)
		{
			if(i == 0)
			{	npc.push_back(new vampire);		npc[i]->loadPos(Xmax,Ymax);}
			else
			{	npc.push_back(new ghost);		npc[i]->loadPos(Xmax,Ymax);}
			i++;
			npc.push_back(new phantom);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "cemetary.mp3";
	}
	if (Map == "catacombs5")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new vampire);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new vampire);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "cemetary.mp3";
	}


	if(Map == "island1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new giant);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new treeman);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new nymph);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new eagle);	npc[i]->loadPos(Xmax,Ymax);			
		}		
		MM = "island.mp3";
	}

	if(Map == "treealter" && !plot.Priest1)
	{
		npc.push_back(new woodpriest); npc[npc.size()-1]->loadPos(2,1);
		MM = "island.mp3";
	}

	if(Map == "icefield1" || Map == "icefield2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new pbear);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new frostgiant);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new snowman);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new iceelf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new iceorc);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "icefield.mp3";
	}
	if(Map == "icehall")
	{
			npc.push_back(new shrineguard);	npc[0]->loadPos(Xmax,Ymax);
			npc.push_back(new rockgolem);	npc[1]->loadPos(Xmax,Ymax);
			MM = "icehall.mp3";
	}

	if(Map == "iceshrine")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new rockgolem);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new shrineguard);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new icewizard);	npc[i]->loadPos(Xmax,Ymax);
		}
		if(!plot.Priest2)
			npc.push_back(new icepriest); npc[npc.size()-1]->loadPos(10,10);
		MM = "icehall.mp3";
	}
	if(Map == "icehall2" && !plot.BlueDragon)
	{
		npc.push_back(new bluedragon); npc[npc.size()-1]->loadPos(1,10);
		MM = "icehall.mp3";
	}

	if(Map == "mountainpath")
	{		
		npc.push_back(new fireorc);	npc[0]->loadPos(Xmax,Ymax);
		npc.push_back(new fireelf);	npc[1]->loadPos(Xmax,Ymax);
		npc.push_back(new cyclops);	npc[2]->loadPos(Xmax,Ymax);
		MM = "mountain.mp3";
	}
	if(Map == "cave1")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new firedemon);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new fireorc);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new magmaman);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "mountain.mp3";
	}
	if(Map == "mtaltar" && !plot.Priest3)
	{
		npc.push_back(new firepriest); npc[npc.size()-1]->loadPos(1,3);
		MM = "mountain.mp3";
	}

	if(Map == "cave2" && !plot.RedDragon)
	{
		npc.push_back(new reddragon); npc[npc.size()-1]->loadPos(10,2);
		MM = "mountain.mp3";
	}

	if(Map == "tunnel")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new fireorc);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new magmaman);npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new fireelf);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new cyclops);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new firedemon); npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "mountain.mp3";
	}
	if(Map == "island2")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new centipede);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wyvern);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new hydra);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new irongolem);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new wanderer);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new ranger);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new adventure); npc[i]->loadPos(Xmax,Ymax);	npc[i]->setmap(Map);
		}
		MM = "island.mp3";
	}

    if(Map == "island3")
	{
		T = T / 2;
		for(i=0; i<T; i++)
		{
			npc.push_back(new stormgiant);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new steelgolem);npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new minator);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			npc.push_back(new acolyte);	npc[i]->loadPos(Xmax,Ymax);
			i++;
			if(!plot.Priest4){
				npc.push_back(new windpriest); npc[i]->loadPos(Xmax,Ymax);}
			else{
				npc.push_back(new minator); npc[i]->loadPos(Xmax,Ymax);}
		}
		MM = "island.mp3";
	}

	if(Map == "temple")
	{
		for(i=0; i<T; i++)
		{
			npc.push_back(new gargoyle);	npc[i]->loadPos(Xmax,Ymax);
		}
		MM = "temple.mp3";
	}

	if(Map == "temple2")
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





