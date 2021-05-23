#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "enemies.h"
#include "world.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN
#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define blue FOREGROUND_BLUE

//============================================================================================
// Elf
//============================================================================================
void elf::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	armor *arm;
	arm = p2->getarmor();
	string heal = "Great god of the land, heal thy servant!";

	if(hp <= 10 && ka >= 4)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 11;
		text("                                                            ",13,9,white);
		text("The Elf is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                          ",13,8,white);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "              ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Elven Mage
//============================================================================================
void mage::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";
	
	if(hp <= 10 && ka >= 4)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 11;
		text("                                                            ",13,9,white);
		text("The Elf is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                                                            ",13,8,white);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 40 + 20;
			text("",13,9,white);
			slowDisp(snow);
			text(getname(),13,11,white);
			cout << " cast Snow!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X < 50 && ka > 4)
		{
			Damage = rand()% 20 + 20;
			text("",13,9,white);
			slowDisp(briarbush);			
			text(getname(),13,11,white);
			cout << " cast briar-bush!";
			Sleep(p2->getPause());
			ka -= 4;
		}
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Elven Warrior
//============================================================================================
void warrior::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	armor *arm;
	arm = p2->getarmor();
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";

	if(hp <= 10 && ka >= 4)
	{
		Damage = rand()% 20 + 10;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		slowDisp(strike);
		text("The Elven Warrior strikes out with immense speed!",13,11,white);
		Sleep(p2->getPause());
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}
//============================================================================================
// Ice Elf
//============================================================================================
void iceelf::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	int dodge  = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	 
	if(choice > 75 && ka >= 6)
	{
		Damage = rand()% 20 + 28;
		setka(ka - 6);
		text("",13,9,white);
		text("The Ice Elf hurls a magical icicle at you!",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		if(p2->getEvd() < dodge)
		{
			text("You narrowly escape the frozen pointy thing!",13,11,white);
			Sleep(p2->getPause());
		}
	
		else
		{
			p2->setHP(p2->getHP()-Damage);
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                 ";
			creature::dam(Damage);
		}  
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}
//============================================================================================
// Fire Elf
//============================================================================================
void fireelf::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	int dodge  = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	 
	if(choice > 75 && ka >= 10)
	{
		Damage = rand()% 30 + 48;
		setka(ka - 10);
		text("",13,9,white);
		text("The Fire Elf sprays fire from his hand!",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		if(p2->getEvd() < dodge)
		{
			text("You narrowly escape superheated doom!",13,11,white);
			Sleep(p2->getPause());		
		}
		else
		{
			p2->setHP(p2->getHP()-Damage);
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                 ";
			creature::dam(Damage);
		}	  
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}
//============================================================================================
// Elven Ranger
//============================================================================================
void ranger::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int choice = rand()% 100 +1;
	int dodge  = rand()% 100 +1;
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";
	string heal = "Great god of the land, heal thy servant!";
	armor *arm;
	arm = p2->getarmor();
	 
	if(choice > 75 && ka >= 10 && hp > 35)
	{
		switch(level)
		{
		case 6:
		case 7:
			Damage = rand()% 25 + 20;
			p2->setHP(p2->getHP()-Damage);
			text("",13,9,white);
			slowDisp(strike);
			text("The Elven Ranger strikes out with immense speed!",13,11,white);
			Sleep(p2->getPause());
			text("                                                            ",13,9,white);
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                             ";
			creature::dam(Damage);
			setka(ka - 10);
			break;
		case 8:
		case 9:
			Damage = rand()% 30 + 30;
			text("",13,9,white);
			slowDisp(briarbush);			
			text(getname(),13,11,white);
			cout << " cast briar-bush!";
			Sleep(p2->getPause());
			ka -= 10;
			break;		  
		}
	}
	else if(hp <= 35 && ka >= 4)
	{  
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 11;
		text("                                                            ",13,9,white);
		text("The Elf is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                                                            ",13,8,white);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Orc
//============================================================================================
void Orc::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	armor *arm;

	if(hp < 10)
		runAway = true;
	else
	{
		arm = p2->getarmor();
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
		p2->info();
		clear();
	}
}

//============================================================================================
// Orc Sorceror
//============================================================================================
void sorceror::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string arrow = "Missle strike your mark with accuracy!";
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";
	
	if(hp <= 10 && ka >= 4)
	{
		text("",13,9,white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.",13,11,white);
		Sleep(p2->getPause());
		Damage = rand()% 20 + 20;
		cure = Damage;
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                       ";
		creature::dam(Damage);
		p2->setHP(p2->getHP() - Damage);
		text("                                                            ",13,9,white);
		text("The Orc Sorceror is healed: ",13,8,white);
		num(cure,41,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 50 + 20;
			text("",13,9,white);
			slowDisp(fire);
			text(getname(),13,11,white);
			cout << " cast Fire";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X < 50 && ka > 4)
		{
			Damage = rand()% 30 + 20;
			text("",13,9,white);
			slowDisp(arrow);			
			text(getname(),13,11,white);
			cout << " cast flame arrow";
			Sleep(p2->getPause());
			ka -= 4;
		}
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Orc Soldier
//============================================================================================
void osoldier::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	armor *arm;
	arm = p2->getarmor();
	string strike = "Pathetic human feel the wrath of the orcs!!!";

	if(hp <= 10 && ka >= 5)
	{
		Damage = rand()% 15 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		slowDisp(strike);
		text("The Orc Soldier strikes out with immense power!",13,11,white);
		Sleep(p2->getPause());
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Fire Orc
//============================================================================================
void fireorc::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	string strike = "Fire falls from the sky!!!";

	if(choice > 75 && ka >= 10)
	{
		Damage = rand()% 35 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		slowDisp(strike);
		text("You are pelted with scalding hot rocks from above",13,11,white);
		Sleep(p2->getPause());
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 10);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Ice Orc
//============================================================================================
void iceorc::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	string strike = "NOW! Deep freeze wind!";

	if(choice > 75 && ka >= 10)
	{
		Damage = rand()% 25 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		slowDisp(strike);
		text("Wind colder than what seems possible chills you to the bones",13,11,white);
		Sleep(p2->getPause());
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 10);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Orc Wanderer
//============================================================================================
void wanderer::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	//bool nodam;
	armor *arm;
	arm = p2->getarmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";

	
	if(hp <= 10 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.",13,11,white);
		Sleep(p2->getPause());
		Damage = rand()% 35 + 20;
		cure = Damage;
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                       ";
		creature::dam(Damage);
		p2->setHP(p2->getHP() - Damage);
		text("                                                            ",13,9,white);
		text("The Adventurer is healed: ",13,8,white);
		num(cure,41,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 50 + 50;
			text("",13,9,white);
			slowDisp(fire);
			text("The Orc Wanderer casts fire!",13,11,white);
			Sleep(p2->getPause());
			ka -= 10;
		}
		else 
		{
			Damage = rand()% damage + damMod;
			if(state == 1)
				X = Damage / 8;
			else
				X = 0;
			Damage += X;
			text(getname(),13,11,white);
			cout << " strikes out at you!";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Human Wizard
//============================================================================================
void wizard::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	bool nodam = false;
	armor *arm;
	arm = p2->getarmor();
	string arain = "Tainted water, pour from the sky!";
	string szshock = "Electricity flow forth and electrify my opponent!";
	string D = "Universe, set yourself to rights, the way you should be.";
	
	if(hp <= 10 && ka >= 10)
	{
		Damage = rand()% 20 + 20;
		text("",13,9,white);
		slowDisp(arain);
		text("Acid rain falls from the sky!!!",13,11,white);
		Sleep(p2->getPause());
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X > 50 && p2->getstate() == 1)
		{
			Damage = 0;
			text("",13,9,white);
			slowDisp(D);	
			p2->setstate(0);
			text(getname(),13,11,white);
			cout << " cast Dispel";
			Sleep(p2->getPause());
			ka -= 4;
			nodam = true;
		}
		else if(X < 50 && ka > 4)
		{
			Damage = rand()% 40 + 20;
			text("",13,9,white);
			slowDisp(szshock);
			text("Electricy flies toward you, and your muscles tense",13,11,white);
			Sleep(p2->getPause());
			ka -= 4;
		}
		
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		if(!nodam)
		{
			Damage -= arm->getdefMod();
			if(Damage < 0)
			Damage = 1;
			p2->setHP(p2->getHP()-Damage);
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                    ";
			creature::dam(Damage);
		}
	}
}

//============================================================================================
// Human Adventurer
//============================================================================================
void adventure::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	bool nodam;
	armor *arm;
	arm = p2->getarmor();
	string skel = "Bones which death hath taken, aid me in my struggle";
	string str = "god of war grant me strength!";
	string drain = "Everything is free for the taking!";

	
	if(hp <= 10 && ka >= 4 && level > 3)
	{
		text("",13,9,white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.",13,11,white);
		Sleep(p2->getPause());
		Damage = rand()% 20 + 20;
		cure = Damage;
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                       ";
		creature::dam(Damage);
		p2->setHP(p2->getHP() - Damage);
		text("                                                            ",13,9,white);
		text("The Adventurer is healed: ",13,8,white);
		num(cure,41,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else if(state == 0 && ka >= 4 && level > 2)
	{
		Damage = 0;
		text("",13,9,white);
		slowDisp(str);	
		state = 1;
		text(getname(),13,11,white);
		cout << " has become visably stronger!!";
		Sleep(p2->getPause());
		ka -= 4;
		nodam = true;
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10 && level > 5)
		{
			Damage = rand()% 50 + 50;
			text("",13,9,white);
			slowDisp(skel);
			text("Skeletal hands strike from the soil!",13,11,white);
			Sleep(p2->getPause());
			ka -= 10;
		}
		else 
		{
			Damage = rand()% damage + damMod;
			if(state == 1)
				X = Damage / 8;
			else
				X = 0;
			Damage += X;
			text(getname(),13,11,white);
			cout << " attacks you!";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}
//============================================================================================
// Stargoyle
//============================================================================================
void stargoyle::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	
	if(choice > 85)
	{
		Damage = rand()% 100 + 100;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Stargoyle points at the heavens and laughs",13,11,white);
		Sleep(p2->getPause());
		text("You see a huge meteor tearing through the atmosphere, at you!",13,11,white);
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Giant Spider
//============================================================================================
void gspider::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int Poison = rand()% 100 + 1;
	armor *arm;

	arm = p2->getarmor();
	Damage = rand()% damage + damMod;
	Damage -= arm->getdefMod();
	if(Damage < 0)
		Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text(getname(),13,11,white);
	cout << " attacks you!";
	Sleep(p2->getPause());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	creature::dam(Damage);
	p2->info();
	//clear();
	if(Poison < 25)
	{
		if(!p2->getpoisoned())
		{
			text("You have been poisoned.",13,11,white);
			Sleep(p2->getPause());
		}
		p2->setpoisoned(true);
	}	
}


//============================================================================================
// Ghost
//============================================================================================
void ghost::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	
	if(choice > 75)
	{
		Damage = rand()% 15 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The ghost reaches out and touches you, with hands like ice.",13,11,white);
		Sleep(p2->getPause());
		text("                                                            ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
			Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}
//============================================================================================
// Magmaman
//============================================================================================
void magmaman::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75 && ka >= 4)
	{
		Damage = rand()% 35 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Magmaman blasts searing hot wind at you from his mouth",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}


//============================================================================================
// Frost Giant
//============================================================================================
void frostgiant::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75 && ka >= 4)
	{
		Damage = rand()% 15 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Frost Giant blows bone-chilling wind at you from his mouth",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Storm Giant
//============================================================================================
void stormgiant::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75 && ka >= 4)
	{
		Damage = rand()% 60 + 30;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Storm Giant strikes you with lightning!!!",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Nymph
//============================================================================================
void nymph::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	int R = 0;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 50 && !p2->getSleep())
	{
		text("The Nymph embraces you lovingly...",13,11,white);
		Sleep(p2->getPause());
		R = rand()% 100 + 1;
		if(R > p2->getmind())
		{
			p2->setSleep(true);
			text("",13,9,white);
			text("The Nymph lulls you to sleep in her arms...",13,11,white);
			Sleep(p2->getPause());
			text("                                                           ",13,9,white);
		}
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " stabs you with her long dagger!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
	if(p2->getSleep())
	{
		R = rand()% 100 + 1;
		if(R < p2->getmind())
		{
			text("",13,9,white);
			text("You shake yourself free of her loveliness!",13,11,white);
			Sleep(p2->getPause());
			text("                                                           ",13,9,white);
		}
	}
}

//============================================================================================
// Ice Wizard
//============================================================================================
void icewizard::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Frigid wind sting my enemy!";
	string avalanche = "Snow! Consume my foe!";
	
	if(hp <= 28 && ka >= 4)
	{
		text("",13,9,white);
		slowDisp(breeze);
		text("A slight breeze revitalizes the Ice Wizard.",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 21;
		text("                                                            ",13,9,white);
		text("The Ice Wizard is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 50 + 20;
			text("",13,9,white);
			slowDisp(avalanche);
			text(getname(),13,11,white);
			cout << " Snow avalanches out of nowhere!!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand()% 30 + 20;
			text("",13,9,white);
			slowDisp(chill);			
			text(getname(),13,11,white);
			cout << " icy wind rips into you!";
			Sleep(p2->getPause());
			ka -= 5;
		}
		else if(X > 80)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Snowman
//============================================================================================
void snowman::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75 && ka >= 4)
	{
		Damage = rand()% 20 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Snowman throws a big, icy snowball at you!",13,11,white);
		Sleep(p2->getPause());
		cout << "And laughs!";
		text("                                                           ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Treeman
//============================================================================================
void treeman::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string slam = "Now, face pain human!";
	string heal = "Great god of the land, heal thy servant!";
	
	if(hp <= 20 && ka >= 5)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the Treeman in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 16;
		text("                                                            ",13,9,white);
		text("The Treeman is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka >= 10)
		{
			Damage = rand()% 40 + 20;
			text("",13,9,white);
			slowDisp(slam);
			text(getname(),13,11,white);
			cout << "Branches reach down, pick you up and slam you hard into the ground";
			Sleep(p2->getPause());
			ka -= 10;
		}
		else if(X > 10 && X < 50 && ka > 5)
		{
			Damage = rand()% 20 + 20;
			text("",13,9,white);
			slowDisp(briarbush);			
			text(getname(),13,11,white);
			cout << " cast briar-bush!";
			Sleep(p2->getPause());
			ka -= 5;
		}
		else
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " bashes you with heavy limbs!";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}


//============================================================================================
// Fire Demon
//============================================================================================
void firedemon::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75)
	{
		choice = rand()% 100 + 1;
		if(choice < 50)
		{
			Damage = rand()% 20 + 30;
			p2->setHP(p2->getHP()-Damage);
			text("",13,9,white);
			text("The Fire Demon throws a big fireball at you!",13,11,white);
			Sleep(p2->getPause());
			cout << "And laughs!";
			text("                                                           ",13,9,white);
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                 ";
			creature::dam(Damage);
		}
		else
		{
			Damage = rand()% 20 + 40;
			p2->setHP(p2->getHP()-Damage);
			text("",13,9,white);
			text("The Fire Demon grabs you, and engulfs you in flames!!!",13,11,white);
			Sleep(p2->getPause());
			text("Enemies Damage: ",13,11,white);
			cout << Damage << "                                 ";
			creature::dam(Damage);
		}
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " attacks you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Hydra
//============================================================================================
void hydra::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int choice = rand()% 100 +1;
	armor *arm;
	arm = p2->getarmor();
	if(choice > 75 && ka >= 4)
	{
		Damage = rand()% 20 + 20;
		p2->setHP(p2->getHP()-Damage);
		text("",13,9,white);
		text("The Hydra breathes noxious gas in your direction!",13,11,white);
		Sleep(p2->getPause());
		text("                                                           ",13,9,white);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                 ";
		creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand()% damage + damMod;
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text(getname(),13,11,white);
		cout << " bites you!";
		Sleep(p2->getPause());
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                             ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Centipede
//============================================================================================
void centipede::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int Poison = rand()% 100 + 1;
	armor *arm;

	arm = p2->getarmor();
	Damage = rand()% damage + damMod;
	Damage -= arm->getdefMod();
	if(Damage < 0)
		Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text(getname(),13,11,white);
	cout << " attacks you!";
	Sleep(p2->getPause());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	creature::dam(Damage);
	p2->info();
	//clear();
	if(Poison < 25)
	{
		if(!p2->getpoisoned())
		{
			text("You have been poisoned.",13,11,white);
			Sleep(p2->getPause());
		}
		p2->setpoisoned(true);
	}
}

//============================================================================================
// Vampire
//============================================================================================
void vampire::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int Poison = rand()% 100 + 1;
	armor *arm;

	arm = p2->getarmor();
	Damage = rand()% damage + damMod;
	Damage -= arm->getdefMod();
	if(Damage < 0)
		Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text(getname(),13,11,white);
	cout << " attacks you!";
	Sleep(p2->getPause());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	creature::dam(Damage);
	Damage = Damage / 4;
	sethp(gethp()+Damage);
	p2->info();
	if(Poison < 15)
	{
		if(!p2->getpoisoned())
		{
			text("You have been poisoned.",13,11,white);
			Sleep(p2->getPause());
		}
		p2->setpoisoned(true);
	}
}

//============================================================================================
// Acolyte
//============================================================================================
void acolyte::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string windstorm = "Wind! Strikedown my opponent!";
	string cyclone = "Wind! Destroy my enemies!!!";
	string heal = "Gentle zephyr caress, and heal my wounds.";
	
	if(hp <= 40 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("A slight breeze wafts through the fight.",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 50 + 21;
		text("                                                            ",13,9,white);
		text("The Acolyte is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 40 + 20;
			text("",13,9,white);
			slowDisp(cyclone);
			text(getname(),13,11,white);
			cout << " cast Cyclone!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X < 50 && ka > 4)
		{
			Damage = rand()% 20 + 20;
			text("",13,9,white);
			slowDisp(windstorm);			
			text(getname(),13,11,white);
			cout << " cast Windstorm!";
			Sleep(p2->getPause());
			ka -= 4;
		}
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}


//============================================================================================
// Wood Priest
//============================================================================================
void woodpriest::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";
	
	if(hp <= 25 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the priest in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 40 + 11;
		text("                                                            ",13,9,white);
		text("The priest is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 40 + 35;
			text("",13,9,white);
			slowDisp(snow);
			text(getname(),13,11,white);
			cout << " cast Snow!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X < 50 && ka > 4)
		{
			Damage = rand()% 30 + 25;
			text("",13,9,white);
			slowDisp(briarbush);			
			text(getname(),13,11,white);
			cout << " cast briar-bush!";
			Sleep(p2->getPause());
			ka -= 4;
		}
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Ice Priest
//============================================================================================
void icepriest::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Ice!! Deep freeze this fool!";
	string avalanche = "Glacier, move at my command!";
	
	if(hp <= 28 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(breeze);
		text("A slight breeze revitalizes the priest.",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 21;
		text("                                                            ",13,9,white);
		text("The priest is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 50 + 20;
			text("",13,9,white);
			slowDisp(avalanche);
			cout << "A glacier falls on you out of nowhere!!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand()% 30 + 20;
			text("",13,9,white);
			slowDisp(chill);			
			cout << "Ice punctures and tears at you!";
			Sleep(p2->getPause());
			ka -= 5;
		}
		else if(X > 80)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Fire Priest
//============================================================================================
void firepriest::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string potion = "Ah, a potion. These are great!";
	string flame = "Fire!!! Show no mercy to this man!";
	string landslide = "Stones fall from above!!!";
	
	if(hp <= 30)
	{
		text("",13,9,white);
		slowDisp(potion);
		text("The priest chugs a potion",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 21;
		text("                                                            ",13,9,white);
		text("The priest is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 50 + 20;
			text("",13,9,white);
			slowDisp(landslide);
			cout << "Boulders fall on you from high above";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand()% 30 + 20;
			text("",13,9,white);
			slowDisp(flame);			
			cout << "Flames fly from his fingers torching you";
			Sleep(p2->getPause());
			ka -= 5;
		}
		else if(X > 80)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Wind Priest
//============================================================================================
void windpriest::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string heal = "Great god of the land, heal thy servant!";
	string arain = "Tainted water, pour from the sky!";
	string lightning = "Powers above smite my enemy!";
	
	if(hp <= 60 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the priest in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 30 + 21;
		text("                                                            ",13,9,white);
		text("The priest is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 10)
		{
			Damage = rand()% 60 + 50;
			text("",13,9,white);
			slowDisp(lightning);
			cout << "A bolt of lightning strikes you!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand()% 30 + 30;
			text("",13,9,white);
			slowDisp(arain);			
			cout << "Acid rain falls upon you burning, and scalding you";
			Sleep(p2->getPause());
			ka -= 5;
		}
		else if(X > 80)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// God of Life
//============================================================================================
void godoflife::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string lifestop = "Great land put cast off your pain to this man!";
	string heal = "Great land of mine, lend me your energy!";
	
	if(hp <= 40 && ka >= 10)
	{
		text("",13,9,white);
		slowDisp(heal);
		text("Light shines down from above engulfing the god in brightness",13,11,white);
		Sleep(p2->getPause());
		cure = rand() % 100 + 101;
		text("                                                            ",13,9,white);
		text("The god is healed: ",13,8,white);
		num(cure,32,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if(X < 10 && ka > 20)
		{
			Damage = rand()% 80 + 50;
			text("",13,9,white);
			slowDisp(lifestop);
			text(getname(),13,11,white);
			cout << " cast Pain!";
			Sleep(p2->getPause());
			ka -= 20;
		}
		if(X < 20 && ka > 10)
		{
			Damage = rand()% 60 + 30;
			text("",13,9,white);
			slowDisp(snow);
			text(getname(),13,11,white);
			cout << " cast Snow!";
			Sleep(p2->getPause());
			ka -= 10;
		}
		if(X > 20 && X < 80 && ka > 4)
		{
			Damage = rand()% 40 + 40;
			text("",13,9,white);
			slowDisp(briarbush);			
			text(getname(),13,11,white);
			cout << " cast briar-bush!";
			Sleep(p2->getPause());
			ka -= 4;
		}
		else if(X > 50)
		{
			Damage = rand()% damage + damMod;
			text(getname(),13,11,white);
			cout << " attacks you with his staff";
			Sleep(p2->getPause());
		}
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}
//============================================================================================
// God of Chaos
//============================================================================================
void godofchaos::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string magma = "Earth unleash your pure fury!";
	
	X = rand() % 100 + 1;
	if(X < 10 && ka > 20)
	{
		Damage = rand()% 80 + 50;
		text("",13,9,white);
		slowDisp(magma);
		text(getname(),13,11,white);
		cout << " cast Pain!";
		Sleep(p2->getPause());
		ka -= 20;
	}
	if(X < 20 && ka > 10)
	{
		Damage = rand()% 60 + 30;
		text("",13,9,white);
		slowDisp(snow);
		text(getname(),13,11,white);
		cout << " cast Snow!";
		Sleep(p2->getPause());
		ka -= 10;
	}
	if(X > 20 && X < 80 && ka > 4)
	{
		Damage = rand()% 40 + 40;
		text("",13,9,white);
		slowDisp(fire);			
		text(getname(),13,11,white);
		cout << " cast flame";
		Sleep(p2->getPause());
		ka -= 4;
	}
	else if(X > 50)
	{
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " attacks you with his staff";
		Sleep(p2->getPause());
	}
	Damage -= arm->getdefMod();
	if(Damage < 0)
	Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "                                    ";
	creature::dam(Damage);
}
//============================================================================================
// God of War
//============================================================================================
void godofwar::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	armor *arm;
	arm = p2->getarmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string hammer = "Earth unleash your pure fury!";
	
	X = rand() % 100 + 1;
	if(X < 10)
	{
		Damage = rand()% 90 + 60;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " swings his massive hammer at you";
		Sleep(p2->getPause());
		ka -= 20;
	}
	if(X < 20)
	{
		Damage = rand()% 60 + 30;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " attacks with his battle axe";
		Sleep(p2->getPause());
		ka -= 10;
	}
	if(X > 20 && X < 80)
	{
		Damage = rand()% 40 + 40;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " swings his sword";
		Sleep(p2->getPause());
		ka -= 4;
	}
	else if(X > 50)
	{
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " punches you!";
		Sleep(p2->getPause());
	}
	Damage -= arm->getdefMod();
	if(Damage < 0)
	Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "                                    ";
	creature::dam(Damage);
}

//============================================================================================
// God of Death
//============================================================================================
void godofdeath::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int cure;
	armor *arm;
	arm = p2->getarmor();
	string drain = "What was yours is now mine!";
	
	if(hp <= 50 && ka >= 20)
	{
		text("",13,9,white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.",13,11,white);
		Sleep(p2->getPause());
		Damage = rand()% 100 + 90;
		cure = Damage;
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                       ";
		creature::dam(Damage);
		p2->setHP(p2->getHP() - Damage);
		text("                                                            ",13,9,white);
		text("The god of death is healed: ",13,8,white);
		num(cure,41,8,green);
		creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{		
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " attacks you with his scythe";
		Sleep(p2->getPause());
		
		Damage -= arm->getdefMod();
		if(Damage < 0)
		Damage = 1;
		p2->setHP(p2->getHP()-Damage);
		text("Enemies Damage: ",13,11,white);
		cout << Damage << "                                    ";
		creature::dam(Damage);
	}
}

//============================================================================================
// Peaceful Monk
//============================================================================================

// He's getting regular attack patterns, cuz all he's going to do is attack when he can.

//============================================================================================
// Green Dragon
//============================================================================================
void greendragon::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	armor *arm;
	arm = p2->getarmor();
	
	X = rand() % 100 + 1;
	if(X < 10)
	{
		Damage = rand()% 100 + 60;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes a superheated fire at you!";
		Sleep(p2->getPause());
		ka -= 20;
	}
	if(X < 20)
	{
		Damage = rand()% 60 + 30;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes fire at you!";
		Sleep(p2->getPause());
		ka -= 10;
	}
	if(X > 20 && X < 80)
	{
		Damage = rand()% 40 + 40;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " strikes you with his tail!";
		Sleep(p2->getPause());
		ka -= 4;
	}
	else if(X > 50)
	{
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " slashes at you with his claws!";
		Sleep(p2->getPause());
	}
	Damage -= arm->getdefMod();
	if(Damage < 0)
	Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "                                    ";
	creature::dam(Damage);
}

//============================================================================================
// Blue Dragon
//============================================================================================
void bluedragon::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	armor *arm;
	arm = p2->getarmor();
	
	X = rand() % 100 + 1;
	if(X < 10)
	{
		Damage = rand()% 100 + 60;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes a superchilled ice at you!";
		Sleep(p2->getPause());
		ka -= 20;
	}
	if(X < 20)
	{
		Damage = rand()% 60 + 30;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes icy wind at you!";
		Sleep(p2->getPause());
		ka -= 10;
	}
	if(X > 20 && X < 80)
	{
		Damage = rand()% 40 + 40;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " strikes you with his tail!";
		Sleep(p2->getPause());
		ka -= 4;
	}
	else if(X > 50)
	{
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " slashes at you with his claws!";
		Sleep(p2->getPause());
	}
	Damage -= arm->getdefMod();
	if(Damage < 0)
	Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "                                    ";
	creature::dam(Damage);
}

//============================================================================================
// Red Dragon
//============================================================================================
void reddragon::attack(player *p2,vector<item*> &pstuff,vector<item*> &stuff, string Map)
{
	int Damage = 0;
	int X;
	armor *arm;
	arm = p2->getarmor();
	
	X = rand() % 100 + 1;
	if(X < 10)
	{
		Damage = rand()% 200 + 100;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes liquified steel fire at you!";
		Sleep(p2->getPause());
		ka -= 20;
	}
	if(X < 20)
	{
		Damage = rand()% 60 + 30;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " breathes lava at you!";
		Sleep(p2->getPause());
		ka -= 10;
	}
	if(X > 20 && X < 80)
	{
		Damage = rand()% 40 + 40;
		text("",13,9,white);
		text(getname(),13,11,white);
		cout << " strikes you with his tail!";
		Sleep(p2->getPause());
		ka -= 4;
	}
	else if(X > 50)
	{
		Damage = rand()% damage + damMod;
		text(getname(),13,11,white);
		cout << " slashes at you with his claws!";
		Sleep(p2->getPause());
	}
	Damage -= arm->getdefMod();
	if(Damage < 0)
	Damage = 1;
	p2->setHP(p2->getHP()-Damage);
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "                                    ";
	creature::dam(Damage);
}
















