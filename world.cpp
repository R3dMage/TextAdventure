#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

#include "world.h"
#include "enemies.h"
#include "location.h"



#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY




world::world()
{
}

world::~world()
{
}

void world::locations(string Map, Player *p2,bool load)
{	
	unsigned int i;
	int Xmax = 0;
	int Ymax = 0;
	int time = 0;
	int choice;
	int total;
	int T=0;
	COORD CursPos;
//	INPUT_RECORD InputRecord;

	char *MM = "town.mp3";
    char *MapMusic = "town.mp3";

	string description;
	string d1;
	string d2;
	string d3;
	string summary;
	string szHolder;
	string oldMap = Map;
	string MapName;
	string ShopType;
	string szPlot;

	string north;
	string south;
	string east;
	string west;

	bool bSel;
	bool bEsc;
	bool bTown = false;





//==============================================================================================================
//		These are the vectors that are used throughout the game to maintain inventory, items on the ground
// locations on the virtual maps in memory, AND what magic spells the character has.
//===============================================================================================================

	vector< creature* > mk(0);					//This is a seperate vector for THE monk.


	vector< item* > Globals(0);						//Globals will contain ALL the items in the world
	vector< item* > inv(0);							//inv is the players inventory
	vector< creature* > encounter(0);				//encounter holds all the enemies on a certain map
	vector< location* > Vmap(0);					//Vmap holds the Map in memory, so no running around
													//taking up time looking in map files. Well we look once. Then keep it in memory
	vector<magik*> spells(0);						//Magik will hold all the spells granted to the player


//===========================================================================================================
//  This sets up the items in their starting places for the player to find. It uses the if(load) to prevent
// them from being loaded into their places again before they are loaded from the players save file.
//===========================================================================================================
	if(!load)
	{
//==============================================================================================================
//			This section of code creates the items that will be placed throughout the game
//==============================================================================================================

		item *vial;
		vial = new item;
		vial->setname("Empty Vial");
		vial->setmap("forest1");
		vial->setX(5);
		vial->setY(5);
		vial->setkeep(true);	

		item *horseshoe;
		horseshoe = new item;
		horseshoe->setname("Horseshoe");
		horseshoe->setmap("field");
		horseshoe->setX(5);
		horseshoe->setY(5);
		horseshoe->setkeep(true);
//==============================================================================================================
//			This section of code pushes them into their proper vectors =)
//==============================================================================================================

		inv.push_back(loaditem("Potion"));
		inv.push_back(loaditem("Potion"));
		Globals.push_back(vial);
		Globals.push_back(horseshoe);	

		mk.push_back(new monk);						//This puts in THE only monk in the game.

		intro();									//Calls the games intro
	}


	if(load)
	{
		load1(p2,Globals,inv,spells,Map);
	}






//==============================================================================================================
//		A slight cheat to test out how the spells work real quick. You can change them up however you like =)
//==============================================================================================================
	
	if(p2->getname() == "rex" && !load)
	{
		//p2->setInvis(true);
		p2->setbspells(true);
		spells.push_back(new minheal);
		spells.push_back(new majheal);
		spells.push_back(new briar);
		spells.push_back(new snow);
		spells.push_back(new pstorm);
		Map = "island1";
		p2->setmka(100);
		p2->setka(100);
		p2->setX(5);
		p2->setY(9);
		inv.push_back(loadWeapon("+1 Scimitar"));
		inv.push_back(loadWeapon("DeathSword"));
		inv.push_back(loadArmor("RedMail"));
	}

    clear();


	

	

	ifstream fin;									//fin is what I use as an ifstream operator
	MapName = "./data/" + Map + ".tgm";				//This adds the extensions we need to access Map Files
	fin.open(MapName.c_str());
	if(fin.fail())
	{
		text("ERROR LOADING MAP",13,11,FOREGROUND_RED);	//Errors that tell you what went wrong are useful
		system("pause");
		exit(0);
	}
	fin.close();
	loadmap(Vmap,MapName,Xmax,Ymax,bTown);		//This function loads all the map places into the V(irtual)map in memory
	npcSetup(encounter,Map,Xmax,Ymax,p2->plot,p2->react,MM,MapMusic);	//This function sets up the enemies according to the map
	if(musicCmp(MM,MapMusic))
		MapMusic = MM;
	music(MapMusic,p2);
	



	while(p2->getHP() > 0)							//This is THE while loop for the game
	{
		
		bSel   = false;
		bEsc   = false; 

		if(!p2->plot.monk)
			mk.push_back(new monk);					//This puts in THE only monk in the game.
		else
			mk.push_back(new fly);

		

//======================================================================================================
//					Code for loading up the descriptions, Map Changes, Plots, and Shops!
//Feb.2005 Added virtual map so as not to access the file EVERY time you move
//======================================================================================================
		

		total = Xmax * Ymax;
		T = (p2->getY()-1) * Xmax + p2->getX() - 1;
		
		if(Vmap[T]->getbMC())
		{
			p2->setX(Vmap[T]->getNeoX());
			p2->setY(Vmap[T]->getNeoY());
			Map = Vmap[T]->getszMC();
			MapName = "./data/" + Map + ".tgm";
			loadmap(Vmap,MapName,Xmax,Ymax,bTown);
			npcSetup(encounter,Map,Xmax,Ymax,p2->plot,p2->react,MM,MapMusic);
			if(musicCmp(MM,MapMusic))
				MapMusic = MM;
			music(MapMusic,p2);

			total = Xmax * Ymax;
			T = (p2->getY()-1) * Xmax + p2->getX() - 1;
		}
		if(Vmap[T]->getbPlot())
		{
			clear();
			p2->info();
			plot(Map,Vmap[T]->getszP());
		}
		if(Vmap[T]->getbShop())
		{
			ShopType = Vmap[T]->getszShop();
			if(ShopType == "armory")
				armory(inv,p2,Map);
			if(ShopType == "inn")
				inn(p2,Map);
			if(ShopType == "magic")
				magicshop(inv,p2,Map);
			if(ShopType == "buy")
				buyer(p2,inv,Map);
		}		

		mk[0]->loadPos(Xmax,Ymax);

//=============================================================================================================
//										loads up the proper summaries
//=============================================================================================================
		if(T + Xmax >= total)
			north = "There is no path to follow";
		else
			north = Vmap[T + Xmax]->getszSum();
		if(T - Xmax < 0)
			south = "There is no path to follow";
		else
			south = Vmap[T - Xmax]->getszSum();
		if(T % Xmax == Xmax-1)
			east = "There is no path to follow";
		else
			east = Vmap[T + 1]->getszSum();
		if(T % Xmax == 0)
			west = "There is no path to follow";
		else
			west = Vmap[T - 1]->getszSum();
		description = Vmap[T]->getszLoc();

//============================================================================================================= 
//									Puts location descriptions on the screen!
//=============================================================================================================
		clr(11);
		if(description.length() > 65)
		{
			DescriptDisplay(description,d1,d2,d3);
			text(d1,13,11,white);
			text(d2,13,12,white);
			text(d3,13,13,white);
			d1 = d2 = d3 = "";
		}
		else
		{
			text(description,13,11,white);
		}

		text("North",13,15,yellow);		text(north,19,15,white);
		text("South",13,16,yellow);		text(south,19,16,white);
		text("East",13,17,yellow);		text(east,18,17,white);
		text("West",13,18,yellow);		text(west,18,18,white);	
//=============================================================================================================
		if((T+Xmax) < static_cast<int>(Vmap.size()) && Vmap[T + Xmax]->getbMC())
			text("North",13,15,green);
		if((T-Xmax) > 0 && Vmap[T - Xmax]->getbMC())
			text("South",13,16,green);
		if((T % Xmax != Xmax-1) && (T + 1 < total) && (Vmap[T+1]->getbMC()))
			text("East ",13,17,green);
		if((T % Xmax != 0) && (T - 1 >= 0) && (Vmap[T-1]->getbMC()))
			text("West",13,18,green);

		p2->info();

//=============================================================================================================
//		Debugging: displays mapname, Vmap#, and number of encounters in the map
// Adding Map size 5/16/05.
// Rem. Out encounter size and # of squares for beta version 6/14/05
//=============================================================================================================
		text("          ",2,22,white);
		num(Xmax,2,22,white);
		text("x",4,22,white);
		num(Ymax,5,22,white);
		text("          ",2,19,white);
		text(Map,2,19,yellow);			
//		num(T,2,20,yellow);			T = 0;
//		num(static_cast<int>(encounter.size()),2,21,blue);
//=============================================================================================================
//								 Code that displays enemies grid locations
// Rem. out Enemy grid locations 6/14/05
//=============================================================================================================
		//int k = 0;
		//for(i=0;i < encounter.size() && i < 20;i++)
		//{
		//	int j = 16;
		//	text("X: ",13,8,white);
		//	text("Y: ",13,9,white);
		//	num(encounter[i]->getX(),j+i+k,8,white);
		//	num(encounter[i]->getY(),j+i+k,9,white);
		//	k += 2;
		//}
//===========================================================================================================
//											Compass box display code
// The letters are a darker color when the player is on the edge of a map. To let the player know that they 
// can't go that way anymore.
//===========================================================================================================


		CursPos.X = 2;
		CursPos.Y = 12;

		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|         |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|    |    |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("| ---+--- |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|    |    |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|         |",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		if(p2->getY() == Ymax)
			text("N",6,12,FOREGROUND_BLUE);
		else
			text("N",6,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(p2->getY() == 1)
			text("S",6,16,FOREGROUND_BLUE);
		else
			text("S",6,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(p2->getX() == Xmax)
		{
			text("E",10,14,FOREGROUND_BLUE);
		}
		else		
		{
			text("E",10,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		
		if(p2->getX() == 1)
		{
			text("W",2,14,FOREGROUND_BLUE);
		}
		else
		{
			text("W",2,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
//================================================================================================================

//		This function clears the items that WERE on the ground		
		clrtop(2);
//		Function that displays what's on the ground =)
		ground(Globals,Map,p2->getX(),p2->getY());


		while(!bSel)
		{
			if(load)
				load = false;			
			//num(time,15,5,ftext);
			walk(bSel,bEsc,p2,Xmax,Ymax,time);
			//time++;
		}
		bSel = false;

        if(bEsc)//=================>  This is the code that calls the player menu for advanced fun
				//   Basically, Press Esc for the menu
		{
			//clear();                    For smooth look remarked out on 2/15/06
			menu(p2,spells,Globals,inv,Map);
			if(p2->getLoaded())
			{
				MapName = "./data/" + Map + ".tgm";						//This adds the extensions we need to access Map Files
				fin.open(MapName.c_str());
				if(fin.fail())
				{
					text("ERROR LOADING MAP \n\n",13,11,FOREGROUND_RED);
					system("pause");
					exit(0);
				}
				
				loadmap(Vmap,MapName,Xmax,Ymax,bTown);
				npcSetup(encounter,Map,Xmax,Ymax,p2->plot,p2->react,MM,MapMusic);
				if(musicCmp(MM,MapMusic))
					MapMusic = MM;
				music(MapMusic,p2);
				p2->setLoaded(false);
			}
			choice = 0;
		}
//=======[Function to check, and change plots]======================
		p2->plots(Map);
//===============================================================================================
//							This section will be checking player location
//	If the player hasn't defeated the 4 priests, then he can't enter the temple sanctum 
//  So, if the player tries, it warps them away! Or at least outside the temple. Maybe later it 
//  will check other places, I don't know yet 6/12/05.
//===============================================================================================

		
		if(Map == "templehall" && p2->getX() == 1 && p2->getY() == 10)
		{
			text("You are not yet powerful enough to enter here.",13,11,white);
			Sleep(3000);
			Map = "field";
			p2->setX(17);
			p2->setY(1);
			MapName = "./data/" + Map + ".tgm";
			loadmap(Vmap,MapName,Xmax,Ymax,bTown);
			npcSetup(encounter,Map,Xmax,Ymax,p2->plot,p2->react,MM,MapMusic);
			if(musicCmp(MM,MapMusic))
				MapMusic = MM;
			music(MapMusic,p2);

		}

//=================================================================================================================
//											Enemy Encounter Code
//Cycles through encounter[] checking if any encounter are at the players current location.
//==================================================================================================================

		if(!p2->getLoaded())//								This makes sure that you're not attacked when you load the game.
		{
			for(i = 0; i < encounter.size();i++)
			{
				if(p2->getX() == encounter[i]->getX() && p2->getY() == encounter[i]->getY() && encounter[i]->gethp() != 0)
				{			
					if(!encounter[i]->getTalkTo())
						fight(p2,encounter[i],inv,Globals,spells,Map);	
					else
					{
						//clear();
						p2->info();
						if(encounter[i]->talkto(p2))
							fight(p2,encounter[i],inv,Globals,spells,Map);
					}
					if(encounter[i]->gethp() <= 0)							
					{
						Globals.push_back(encounter[i]->body(Map));		//Drops enemy unique item if the enemy is dead
					}
					magicCheck(p2,spells);
//===========================================================================================================
//					Replenishes the dead enemies, so we don't run out of them on a map
//Moved to inside the for loop 6/14/05
//===========================================================================================================
					for(i = 0; i < encounter.size();i++)
					{
						if(encounter[i]->gethp() <= 0 && !encounter[i]->getdontmove())
						{				
							Eplenish(encounter,i);							
							encounter[encounter.size()-1]->loadPos(Xmax,Ymax);
						}
					}
					if(mk[0]->gethp() <= 0)
					{
						Eplenish(mk,i);							
						mk[mk.size()-1]->loadPos(Xmax,Ymax);
					}

				}
			}
		}
		if(p2->getLoaded())
			p2->setLoaded(false);

		if(mk[0]->getX() == p2->getX() && mk[0]->getY() == p2->getY() && Map == "field2")
			fight(p2,mk[0],inv,Globals,spells,Map);


//===============================================================================================
//									Function for moving enemies around on the map
//===============================================================================================

		move(encounter,Xmax,Ymax);
	}// -------------------------------->End Walking Loop
}
//===================================================================================================================
//                                              End Function
//===================================================================================================================


//				Function to draw the cusor to the screen
void world::DrawCurs(COORD pos, WORD color, char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << curs;
}
//				Function to move the cursor up and down
bool world::MoveCurs(COORD &CursPos,bool &bSelect,bool &bEsc, int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursPos;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			if(CursPos.Y < Ymax)
			{
				CursPos.Y++;
                bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymin;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if(CursPos.Y > Ymin)
			{
				CursPos.Y--;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymax;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			//cout << "-";
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bCursMov = false;
			bSelect = true;
			bEsc = true;
		}
	}	
	if(bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH,OldCursPos);
		cout << "  ";
		return true;
	}
return false;	
}

//==========================================================================================================
//	Function for walking around the map. It returns true if you've moved (that is pressed a movement key)
//	to load up the description of the place you've moved to. Also it takes the bEsc variable to see if you
//  hit Esc key to enter the menu.
//==========================================================================================================
bool world::walk(bool &bSel, bool &bEsc, Player *p2,int Xmax, int Ymax, int &T)
{
	T++;
	INPUT_RECORD InputRecord;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		// If you hit up, go up! But not if your as up as you can go on the map.
		{
			p2->setY(p2->getY()+1);
			if(p2->getY() > Ymax)
				p2->setY(Ymax);
			bSel = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		// If you hit down, go down! The Player Class prevents Y from being 0.
		{
			p2->setY(p2->getY()-1);
			bSel = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
		// If you hit right, go right! But not if your as right as you can go on the map.
		{
			p2->setX(p2->getX()+1);
			if(p2->getX() > Xmax)
				p2->setX(Xmax);
			bSel = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
		// If you hit left, go left! The player class prevents X from being 0.
		{
			p2->setX(p2->getX()-1);
			bSel = true;
		}
		
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		// This changes bEsc, so that the main loop knows to go into the menu function
		{
			bEsc = true;
			bSel = true;
		}
	}	
	text(" ", 79, 23,white);
return false;	
}
//				This is the shop where you buy weapons and armor
void world::armory(vector<item*> &pstuff,Player *p2,string Map)
{
	int choice = 0;
	bool bEsc = false;
	bool bSel = false;
	bool funds = true;
	COORD CursPos; 
	weapon *wsell1;
	weapon *wsell2;
	weapon *wsell3;
	armor *asell1;
	armor *asell2;
	armor *asell3;

	if(Map == "valesh")
	{
		wsell1 = loadWeapon("Rapier");
		wsell2 = loadWeapon("Longsword");
		wsell3 = loadWeapon("Scimitar");
		asell1 = loadArmor("Padded");
		asell2 = loadArmor("Leather");
		asell3 = loadArmor("Lt.Chain");
	}
	if(Map == "elvencity")
	{
		wsell1 = loadWeapon("+1 Rapier");
		wsell2 = loadWeapon("+1Longsword");
		wsell3 = loadWeapon("+1 Scimitar");
		asell1 = loadArmor("Padded");
		asell2 = loadArmor("Leather");
		asell3 = loadArmor("Elvenchain");
	}
	if(Map == "marintown")
	{
		wsell1 = loadWeapon("Scimitar");
		wsell2 = loadWeapon("Claymore");
		wsell3 = loadWeapon("Spitfire");
		asell1 = loadArmor("Leather");
		asell2 = loadArmor("Lt.Chain");
		asell3 = loadArmor("SteelMail");
	}
	if(Map == "yamashi")
	{
		wsell1 = loadWeapon("Spitfire");
		wsell2 = loadWeapon("Hammer");
		wsell3 = loadWeapon("Katana");
		asell1 = loadArmor("Leather");
		asell2 = loadArmor("Lt.Chain");
		asell3 = loadArmor("SteelMail");
	}

	while(!bEsc)
	{		
		
		CursPos.X = 13;
		CursPos.Y = 2;
		bSel = false;
		funds = true;
		clear();
		p2->info();
		items(pstuff);

		text("[-----For Sale-----]",13,1,yellow);
		text(wsell1->getname(),15,2,white);		num(wsell1->getCost(),28,2,white);
		text(wsell2->getname(),15,3,white);		num(wsell2->getCost(),28,3,white);
		text(wsell3->getname(),15,4,white);		num(wsell3->getCost(),28,4,white);
		text(asell1->getname(),15,5,white);		num(asell1->getCost(),28,5,white);
		text(asell2->getname(),15,6,white);		num(asell2->getCost(),28,6,white);
		text(asell3->getname(),15,7,white);		num(asell3->getCost(),28,7,white);

		DrawCurs(CursPos,yellow,175);
		wsell1->display();
		do
		{
			if(MoveCurs(CursPos,bSel,bEsc,2,7))
			{
				DrawCurs(CursPos,yellow,175);
				choice = CursPos.Y;
				switch(choice)
				{
				case 2:
					wsell1->display();
					break;
				case 3:
					wsell2->display();
					break;
				case 4:
					wsell3->display();
					break;
				case 5:
					asell1->display();
					break;
				case 6:
					asell2->display();
					break;
				case 7:
					asell3->display();
					break;
				}
			}
			text(" ", 79, 23,white);
		}while(!bSel);
		if(bEsc)
			break;

		choice = CursPos.Y;
		switch(choice)
		{
		case 2:
			if(p2->getgold() < wsell1->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(wsell1);
				p2->setgold(p2->getgold()-wsell1->getCost());
			}
			break;
		case 3:
			if(p2->getgold() < wsell2->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(wsell2);
				p2->setgold(p2->getgold()-wsell2->getCost());
			}
			break;
		case 4:
			if(p2->getgold() < wsell3->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(wsell3);
				p2->setgold(p2->getgold()-wsell3->getCost());
			}
			break;
		case 5:
			if(p2->getgold() < asell1->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(asell1);
				p2->setgold(p2->getgold()-asell1->getCost());
			}
			break;
		case 6:
			if(p2->getgold() < asell2->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(asell2);
				p2->setgold(p2->getgold()-asell2->getCost());
			}
			break;
		case 7:
			if(p2->getgold() < asell3->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(asell3);
				p2->setgold(p2->getgold()-asell3->getCost());
			}
			break;
		}
		if(!funds)
		{
			text("You do not have sufficient funds",13,9,white);
			Sleep(1500);
		}
		
	}
	clear();
}

//==========================================================================================================
//	Function for what happens when you go to an inn.
//==========================================================================================================
void world::inn(Player *p2,string Map)
{
	int choice = 0;
	int price = 0;
	bool bEsc = false;
	bool bSel = false;
	COORD CursPos; 
	string name;

	if(Map == "valesh")					//Price and name of the inn in Valesh
	{
		price = 55;
		name = "Inn of the Lucky Whale";
	}
	if(Map == "elvencity")				//Price and name of the inn in ElvenCity
	{
		price = 105;
		name = "Inn of warm dreams";
	}

	if(Map == "marintown")				//Price and name of the inn in Marintown
	{
		price = 155;
		name = "Inn of Soft Love";
	}

	if(Map == "yamashi")				//Price and name of the inn in Yamashi
	{
		price = 255;
		name = "Inn of the Mountain";
	}
	while(!bEsc)
	{
		clear();
		p2->info();	
		CursPos.X = 2;
		CursPos.Y = 12;
		bSel = false;
		text("Will you be spending the night?",13,11,white);
		text("[---",13,1,brown);	cout << name << "--]";
		text("One night: ",13,2,white); num(price,24,2,yellow);
		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Yes    |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  No     |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCurs(CursPos,yellow,175);
		do
		{
			if(MoveCurs(CursPos,bSel,bEsc,12,13))
			{
				DrawCurs(CursPos,yellow,175);
			}
			text(" ", 79, 23,white);
		}while(!bSel);
		if(bEsc)
			break;

		choice = CursPos.Y;
		switch(choice)
		{
		case 12:
			if(p2->getgold() < price)
			{
				text("You have insufficient funds",13,11,yellow);
				Sleep(p2->getPause());
			}
			else
			{
				p2->setgold(p2->getgold() - price);
				p2->setHP(p2->getMHP());
				p2->setka(p2->getmka());
				text("Pleasure doing business with you!",13,11,white);
				Sleep(p2->getPause());
				bEsc = true;
			}
			break;
		case 13:
			text("Sorry, maybe next time.                   ",13,11,white);
			Sleep(p2->getPause());
			bEsc = true;
			break;
		}
	}//--------End while bEsc
	clear();
}

void world::magicshop(vector<item*> &pstuff,Player *p2,string Map)
{
	int choice = 0;
	bool bEsc = false;
	bool bSel = false;
	bool funds = true;
	COORD CursPos; 
	item *isell1;
	item *isell2;
	item *isell3;
	item *isell4;
	item *isell5;
	item *isell6;

	if(Map == "valesh")
	{
		isell1 = loaditem("Potion");
		isell2 = loaditem("Potion");
		isell3 = loaditem("Potion");
		isell4 = loaditem("Potion");
		isell5 = loaditem("Potion");
		isell6 = loaditem("Potion");
	}
	if(Map == "elvencity")
	{
		isell1 = loaditem("Potion");
		isell2 = loaditem("Potion");
		isell3 = loaditem("Potion2");
		isell4 = loaditem("Refresh");
		isell5 = loaditem("Refresh");
		isell6 = loaditem("Refresh");
	}

	if(Map == "marintown")
	{
		isell1 = loaditem("Potion");
		isell2 = loaditem("Potion2");
		isell3 = loaditem("Potion3");
		isell4 = loaditem("Refresh");
		isell5 = loaditem("Refresh");
		isell6 = loaditem("RedVial");
	}

	if(Map == "yamashi")
	{
		isell1 = loaditem("Potion2");
		isell2 = loaditem("Potion3");
		isell3 = loaditem("Potion3");
		isell4 = loaditem("Refresh");
		isell5 = loaditem("Refresh");
		isell6 = loaditem("BlueVial");
	}
	while(!bEsc)
	{		
		
		CursPos.X = 13;
		CursPos.Y = 2;
		bSel = false;
		funds = true;
		clear();
		p2->info();
		items(pstuff);

		text("[-----For Sale-----]",13,1,yellow);
		text(isell1->getname(),15,2,white);		num(isell1->getCost(),28,2,white);
		text(isell2->getname(),15,3,white);		num(isell2->getCost(),28,3,white);
		text(isell3->getname(),15,4,white);		num(isell3->getCost(),28,4,white);
		text(isell4->getname(),15,5,white);		num(isell4->getCost(),28,5,white);
		text(isell5->getname(),15,6,white);		num(isell5->getCost(),28,6,white);
		text(isell6->getname(),15,7,white);		num(isell6->getCost(),28,7,white);

		DrawCurs(CursPos,yellow,175);
		isell1->display();
		do
		{
			if(MoveCurs(CursPos,bSel,bEsc,2,7))
			{
				DrawCurs(CursPos,yellow,175);
				choice = CursPos.Y;
				switch(choice)
				{
				case 2:
					isell1->display();
					break;
				case 3:
					isell2->display();
					break;
				case 4:
					isell3->display();
					break;
				case 5:
					isell4->display();
					break;
				case 6:
					isell5->display();
					break;
				case 7:
					isell6->display();
					break;
				}
			}
			text(" ", 79, 23,white);
		}while(!bSel);
		if(bEsc)
			break;

		choice = CursPos.Y;
		switch(choice)
		{
		case 2:
			if(p2->getgold() < isell1->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell1);
				p2->setgold(p2->getgold()-isell1->getCost());
			}
			break;
		case 3:
			if(p2->getgold() < isell2->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell2);
				p2->setgold(p2->getgold()-isell2->getCost());
			}
			break;
		case 4:
			if(p2->getgold() < isell3->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell3);
				p2->setgold(p2->getgold()-isell3->getCost());
			}
			break;
		case 5:
			if(p2->getgold() < isell4->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell4);
				p2->setgold(p2->getgold()-isell4->getCost());
			}
			break;
		case 6:
			if(p2->getgold() < isell5->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell5);
				p2->setgold(p2->getgold()-isell5->getCost());
			}
			break;
		case 7:
			if(p2->getgold() < isell6->getCost())
				funds = false;
			if(funds)
			{
				pstuff.push_back(isell6);
				p2->setgold(p2->getgold()-isell6->getCost());
			}
			break;
		}
		if(!funds)
		{
			text("You do not have sufficient funds",13,9,white);
			Sleep(1500);
		}		
	}// End while bEsc
	clear();
}

void world::buyer(Player *p2, vector<item*> &pstuff,string Map)
{
	//item *temp;
	item *iUsed;
	unsigned int Offset = 0;
	int choice = 0;
	int num;
	double X = .75;
	bool bEsc = false;
	bool bSel = false;
	bool bLeave = false;
	item holder;
	COORD CursPos;
	

	if(Map == "valesh")
		X = .5;
	if(Map == "elvencity")
		X = .6;
	if(Map == "marintown")
		X = .75;
	if(Map == "yamashi")
		X = .85;
	while(!bLeave)
	{
		bSel = false;
		clrbottom();
		clrtop(3);
		p2->info();
		text("[---We buy STUFF!---]",13,1,brown);
		if(pstuff.size() < 1)
		{
			text("You have nothing to sell!!!",13,3,white);
			Sleep(p2->getPause());
			return;
		}
		else
			text("What would you like to sell?",13,3,white);

		items(pstuff);
		while(!bSel)
		{
			bEsc = false;
			bSel = false;
			CursPos.X = 13;
			CursPos.Y = 12;

			DrawCurs(CursPos,yellow,175);			
			Offset = CursPos.Y - 12;
			pstuff[Offset]->display();
			do
			{
				choice = static_cast<int>(11+pstuff.size());
				if(MoveCurs(CursPos,bSel,bEsc,12,choice))
				{
					DrawCurs(CursPos,yellow,175);
					Offset = CursPos.Y - 12;
					pstuff[Offset]->display();
				}
				text(" ", 79, 23,white);
			}while(!bSel);
		}// End While bSel
		if(bEsc)
		{
			clrbottom();
			clrtop(1);
			return;
		}
		Offset = CursPos.Y - 12;
		iUsed = pstuff[Offset];
		bSel = false;
		
		num = static_cast<int>(iUsed->getCost() * X);
		text(pstuff[Offset]->getname(),15,CursPos.Y,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("This Item?                  ",13,3,white);
		text(iUsed->getname(),13,5,white);
		cout << "   " << num << "GP";
		do
		{
			
			if(MoveCurs(CursPos,bSel,bEsc,CursPos.Y,CursPos.Y))
			{
				DrawCurs(CursPos,yellow,175);
			}
			text(" ", 79, 23,white);
		}while(!bSel);
		if(bEsc)
		{
			return;
		}
		bSel = false;
		p2->setgold(p2->getgold() + num);
//==========================================CODE TO REMOVE ITEM=====================================
		//temp = pstuff[pstuff.size()-1];
		//pstuff[pstuff.size()-1] = pstuff[Offset];
		//pstuff[Offset] = temp;
		//pstuff.pop_back();
//==================================================================================================

//======================================NEW CODE TO REMOVE ITEM=====================================
		slidedown(pstuff,Offset);
		pstuff.pop_back();
//==================================================================================================
		clrbottom();
		p2->info();
		text("There you go!",13,3,white);
		Sleep(p2->getPause());

	}//----------------------------------->End While bLeave	
}//--------------------------------------->End Buyer function




//==========================================================================================================
//	Function for replenishing enemies
//==========================================================================================================
void world::Eplenish(vector<creature*> &enemies, int num)
{
	creature *temp;

	temp = enemies[enemies.size()-1];				//Saves off the last in the vector
	enemies[enemies.size()-1] = enemies[num];		//Moves the killed enemy to the last slot
	enemies[num] = temp;							//Moves saved last into the slot of slain enemy
	temp = enemies[enemies.size()-1];				//Saves off slain enemy to use its replenish function
	enemies.pop_back();
	enemies.push_back(temp->replenish());			//Dynamically replenishes the enemy with a new one!

//  Well not too dynamically. It's all taken care of by the classes replenish funcion which just returns a new
//  Member of its own class. What fun.
}


//==========================================================================================================
//	This function was designed to check the number of items in inventory. If you were going to go over the 
//	limit of 10 it would tell you you're out of room. Not yet implemented 5/11/05
//==========================================================================================================
bool world::Overflow(int size)
{
	if(size >= 10)
	{
		text("You do not have enough room!",13,12,white);
		Sleep(3000);
		return true;
	}
	else
		return false;
}


//==========================================================================================================
//	This function splits up the description string, into 3 strings of text. Sort of text wrapping.
//==========================================================================================================
void world::DescriptDisplay(string disp, string &first, string &second, string &third)
{
	int i = 0;
	int j = 0;
	j = static_cast<int>(disp.size() / 65);
	i = static_cast<int>(disp.size() % 65);

	first = disp.substr(0,65);
	second = disp.substr(65,i);
	
	if(j > 1)	//If there is more than 130 characters in the description
	{
		first = disp.substr(0,65);		//Creates a string out of the first 65 characters
		second = disp.substr(65,65);	//Creates a string out of the second 65 characters
        third = disp.substr(130,i);		//Creates a string out of the third 65 characters
	}
}

void world::loadmap(vector< location* > &g, string &Map,int &Xmax, int &Ymax, bool &bTown)
{
	ifstream fin;
	string szHolder;

	COORD max = {0,0};
	int t;
	int i = 0;

	fin.open(Map.c_str());
	g.clear();
	fin >> szHolder >> bTown;
	fin >> szHolder >> szHolder;
	while(!fin.eof())
	{		
		g.push_back(new location);
		fin >> szHolder; 
		if(szHolder == "P:")
		{
			g[i]->setbPlot(true);
			fin >> szHolder;	g[i]->setszP(szHolder);
			fin >> szHolder;
		}
		if(szHolder == "MC:")
		{
			g[i]->setbMC(true);
			getline(fin,szHolder);
			g[i]->setszMC(rotate(szHolder));
			fin >> szHolder;
			fin >> t;
			g[i]->setNeoX(t);
			fin >> szHolder;
			fin >> t;
			g[i]->setNeoY(t);
			fin >> szHolder;
		}
		if(szHolder == "Shop:")
		{
			g[i]->setbShop(true);
			getline(fin,szHolder);
			g[i]->setszShop(rotate(szHolder));
			fin >> szHolder;
		}
		if(szHolder == "X:")
		{
			fin >> t;
			if(t > max.X)
				max.X = t;
			g[i]->setX(t);
			fin >> szHolder;
		}
		if(szHolder == "Y:")
		{
			fin >> t;
			if(t > max.Y)
				max.Y = t;
			g[i]->setY(t);
			fin >> szHolder;
		}
		if(szHolder == "L:")
		{
			getline(fin,szHolder);
			g[i]->setszLoc(rotate(szHolder));
			fin >> szHolder;
		}
		if(szHolder == "S:")
		{
			getline(fin,szHolder);
			g[i]->setszSum(rotate(szHolder));
		}
		i++;
	}
	Xmax = max.X;
	Ymax = max.Y;
}
//==========================================================================================================
//	This function runs through the vector of creatures, moving them around the map in a random fashion
//  5/10/05
//==========================================================================================================
void world::move(vector<creature*> &encounter,int Xmax, int Ymax)
{
	int RND;
	unsigned int i;
	for(i=0;i < encounter.size();i++)
		{
			RND = rand()%4+1;
			if(encounter[i]->getdontmove())
				RND = 5;
			switch(RND)
			{
			case 1:
				encounter[i]->setX(encounter[i]->getX()+1);
				if(encounter[i]->getX() > Xmax)
					encounter[i]->setX(Xmax);
				break;
			case 2:
				encounter[i]->setX(encounter[i]->getX()-1);
				break;
			case 3:
				encounter[i]->setY(encounter[i]->getY()+1);
				if(encounter[i]->getY() > Ymax)
					encounter[i]->setY(Ymax);
				break;
			case 4:
				encounter[i]->setY(encounter[i]->getY()-1);
				break;
			default:
				break;
			}//---------End Switch
		}//-----------------End For loop
}
//==========================================================================================================
//	This function checks to see if Player is eligable for any magics, and checks so not to give the same
//  one twice. REM added 1/5/06
//==========================================================================================================
void world::magicCheck(Player *p2,vector<magik*> &M)
{
	if(p2->kill.Okills == 5 && p2->kill.Ekills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Minor Heal"))
			return;
		//p2->setbspells(true);             Just there to test when to give ka
		text("The god of life has rewarded you with a magic spell!",13,9,white);
		M.push_back(new minheal);
		Sleep(p2->getPause());
	}
	if(p2->kill.Okills == 10 && p2->kill.Ekills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Briar Bush"))
			return;
		text("The god of life has rewarded you with a magic spell!",13,9,white);
		M.push_back(new briar);
		Sleep(p2->getPause());
	}
	if(p2->kill.Okills == 20 && p2->kill.Ekills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Major Heal"))
			return;
		text("The god of life has rewarded you with a magic spell!",13,9,white);
		M.push_back(new majheal);
		Sleep(p2->getPause());
	}
	if(p2->kill.Okills == 40 && p2->kill.Ekills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Snow"))
			return;
		text("The god of life has rewarded you with a magic spell!",13,9,white);
		M.push_back(new snow);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills == 5 && p2->kill.Okills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Drain Life"))
			return;
		p2->setbspells(true);
		text("The god of chaos has rewarded you with a magic spell!",13,9,white);
		M.push_back(new dlife);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills == 10 && p2->kill.Okills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Flame Arrow"))
			return;
		text("The god of chaos has rewarded you with a magic spell!",13,9,white);
		M.push_back(new farrow);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills == 20 && p2->kill.Okills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Steal Ka"))
			return;
		text("The god of chaos has rewarded you with a magic spell!",13,9,white);
		M.push_back(new stealka);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills == 40 && p2->kill.Okills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Fire"))
			return;
		text("The god of chaos has rewarded you with a magic spell!",13,9,white);
		M.push_back(new fire);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 4 && p2->kill.Okills > 4 &&  p2->kill.Hkills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Strength"))
			return;
		p2->setbspells(true);
		text("The god of war has rewarded you with a magic spell!",13,9,white);
		M.push_back(new strength);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 8 && p2->kill.Okills > 8 &&  p2->kill.Hkills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Dispel"))
			return;
		text("The god of war has rewarded you with a magic spell!",13,9,white);
		M.push_back(new dispel);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 12 && p2->kill.Okills > 12 &&  p2->kill.Hkills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Shock"))
			return;
		text("The god of war has rewarded you with a magic spell!",13,9,white);
		M.push_back(new shock);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 15 && p2->kill.Okills > 15 &&  p2->kill.Hkills == 0 && M.size() < 10)
	{
		if(hasMagic(M,"Acid Rain"))
			return;
		text("The god of war has rewarded you with a magic spell!",13,9,white);
		M.push_back(new acidrain);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 3 && p2->kill.Okills > 3 &&  p2->kill.Hkills > 3 && M.size() < 10)
	{
		if(hasMagic(M,"Poison"))
			return;
		p2->setbspells(true);
		text("The god of death has rewarded you with a magic spell!",13,9,white);
		M.push_back(new poison);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 10 && p2->kill.Okills > 10 &&  p2->kill.Hkills > 10 && M.size() < 10)
	{
		if(hasMagic(M,"Skeleton"))
			return;
		text("The god of death has rewarded you with a magic spell!",13,9,white);
		M.push_back(new skeleton);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 15 && p2->kill.Okills > 15 &&  p2->kill.Hkills > 15 && M.size() < 10)
	{
		if(hasMagic(M,"Dark Strike"))
			return;
		text("The god of death has rewarded you with a magic spell!",13,9,white);
		M.push_back(new dstrike);
		Sleep(p2->getPause());
	}
	if(p2->kill.Ekills > 20 && p2->kill.Okills > 20 &&  p2->kill.Hkills > 20 && M.size() < 10)
	{
		if(hasMagic(M,"Critical"))
			return;
		text("The god of death has rewarded you with a magic spell!",13,9,white);
		M.push_back(new critical);
		Sleep(p2->getPause());
	}

	
}

bool world::hasMagic(vector<magik*> M,string name)
{
	unsigned int i;
	for(i=0;i<M.size();i++)
	{
		if(name == M[i]->getname())
			return true;		
	}
	return false;
}
//==========================================================================================================
//	Intro to the game!
//==========================================================================================================
void world::intro()
{
	text("In the past when gods could be bested by mortal men, ",13,2,white);
	text("four priests are keeping the pantheon at bay and ruling",13,3,white);
	text("the world for their own evil schemes. If the priests were ",13,4,white);
	text("out of the picture however...",13,5,white);
	text(" ", 79, 23,white);
	system("pause");
}
/*==========================================================================================================
	A string comparison function. Yeah I wrote my own, wanna fight about it?
============================================================================================================*/
bool world::musicCmp(char* string1,char* string2)
{
	if(string1 == string2)
		return false;
	else
		return true;	
}

/*===========================================
This function will play music of the game
=============================================*/
void world::music(char * mapMusic, Player *p2)
{
/*================================================
    copy the map music into the player's music
    otherwise, there are problems. sheesh. 1/9/07
=================================================*/
	p2->setMusicFilename(mapMusic);

	if(p2->getMusic())
	{
		p2->playMusic(mapMusic);
	}
}


















