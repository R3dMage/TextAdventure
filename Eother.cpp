#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "enemies.h"
#include "world.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define blue FOREGROUND_BLUE
//======================================================  ELF  ==========================================
bool elf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* elf::body(string Map) const 
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50);
	return left;
}
Item* elf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}

void elf::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(gold,20,11,green);
	num(exp,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + gold);
	p2->SetExperience(p2->GetExperience() + exp);
	p2->SetReactionElf(1);
	p2->RaceKillCounts.ElfKillCount += 1;
	if(p2->RaceKillCounts.OrcKillCount == 0)
		p2->SetReactionOrc(3);
	p2->DisplayInfo();
	Sleep(3000);
	if(p2->RaceKillCounts.ElfKillCount < 4)
	{
		text("                                                               ",13,9,white);
		text("                                                               ",13,8,white);
		text("",13,8,white);
		slowDisp("You have slain an elf, one of the god of life's most treasured ");		
		text("",13,9,white);
		slowDisp("beings...");
		text("",79,23,white);
		Sleep(3000);
	}
	
	
}
creature* elf::replenish() const
{
	return new elf;
}
//====================================================== Elven Mage ================================================
bool mage::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* mage::body(string Map) const 
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* mage::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* mage::replenish() const
{
	return new mage;
}
//====================================================== Elven Warrior ==============================================
bool warrior::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* warrior::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* warrior::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("Elvenchain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* warrior::replenish() const
{
	return new warrior;
}
//====================================================== Fire Elf ==============================================
bool fireelf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* fireelf::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Red Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* fireelf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* fireelf::replenish() const
{
	return new fireelf;
}
//====================================================== Ice Elf ==============================================
bool iceelf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* iceelf::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Bluewhite Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* iceelf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* iceelf::replenish() const
{
	return new iceelf;
}
//====================================================== Elven Ranger ==============================================
bool ranger::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
	return true;
	else
	return false;
}
Item* ranger::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50 * level);
	return left;
}
Item* ranger::token(string Map)
{
	int num = rand()% 6 + 1;
	Item *token = new Item;
	switch(num)
	{
	case 1:
		token = loadArmor("elvenchain");
		break;
	case 2:
		token = loadWeapon("ElfBlade");
		break;
	case 3:
	default:
		token = loaditem("Potion2");
		break;
	}

	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* ranger::replenish() const
{
	return new ranger;
}
//======================================================{ ORC ==================================================

bool Orc::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else 
		return false;	
}
Item* Orc::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(75);
	return left;
}
Item* Orc::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}

void Orc::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(gold,20,11,green);
	num(exp,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + gold);
	p2->SetExperience(p2->GetExperience() + exp);
	p2->SetReactionOrc(1);
	p2->RaceKillCounts.OrcKillCount += 1;
	if(p2->RaceKillCounts.ElfKillCount == 0)
		p2->SetReactionElf(3);
	p2->DisplayInfo();
	Sleep(3000);
	if(p2->RaceKillCounts.OrcKillCount < 4)
	{
		text("                                                                ",13,9,white);
		text("                                                                ",13,8,white);
		text("",13,8,white);
		slowDisp("You have slain an orc, one of the god of chaos's most treasured ");		
		text("",13,9,white);
		slowDisp("beings...");
		text("",79,23,white);
		Sleep(3000);
	}
}
creature* Orc::replenish() const
{
	return new Orc;
}
//====================================================== Orc Sorceror ===========================================
bool sorceror::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 85)
		return true;
	else 
		return false;	
}
Item* sorceror::body(string Map) const 
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(300);
	return left;
}
Item* sorceror::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* sorceror::replenish() const
{
	return new sorceror;
}
//======================================================= Orc Soldier ==========================================
bool osoldier::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* osoldier::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(150);
	return left;
}
Item* osoldier::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("Orc_Mail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* osoldier::replenish() const
{
	return new osoldier;
}
//====================================================== Fire Orc ==================================================

bool fireorc::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* fireorc::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Red Orc Ear");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
Item* fireorc::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
creature* fireorc::replenish() const
{
 return new fireorc;
}
//====================================================== Ice Orc ==================================================
bool iceorc::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* iceorc::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Blue Orc Ear");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
Item* iceorc::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
creature* iceorc::replenish() const
{
 return new iceorc;
}
//====================================================== Orc Wanderer ==================================================
bool wanderer::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* wanderer::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Orc Ear");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
Item* wanderer::token(string Map)
{
	int num = rand()% 6 + 1;
	Item *token = new Item;
	switch(num)
	{
	case 1:
		token = loadArmor("OrcMail");
		break;
	case 2:
		token = loadWeapon("OrcBlade");
		break;
	case 3:
	default:
		token = loaditem("Potion2");
		break;
	}

	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* wanderer::replenish() const
{
	return new wanderer;
}
//====================================================== Human ==================================================
bool human::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* human::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Item* human::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Last Will");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost((rand()% 100 + 1) * level);
	return left;
}

void human::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(gold,20,11,green);
	num(exp,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + gold);
	p2->SetExperience(p2->GetExperience() + exp);
	p2->RaceKillCounts.HumanKillCount += 1;
	if(p2->RaceKillCounts.HumanKillCount == 5)
	{//                                       65
		text("                                                           ",13,9,white);
		text("A price has now been put on your head. You're a wanted man.",13,9,white);
		Sleep(3000);
		
		p2->SetReactionHuman(1);
	}
	p2->DisplayInfo();
	Sleep(3000);
	text("",79,23,white);
	if(p2->RaceKillCounts.HumanKillCount < 5)
	{
		text("                                                                ",13,9,white);
		text("                                                                ",13,8,white);
		text("",13,8,white);
		slowDisp("You have slain a human, one of the god of wars most treasured");
		text("",13,9,white);
		slowDisp("beings...");
		text("",79,23,white);
		Sleep(3000);		
	}
}
creature* human::replenish() const
{
	return new human;
}
//====================================================== Human Knight ============================================
bool knight::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* knight::token(string Map)
{
	int num = rand()% 3 + 1;
	Item *token = new Item;
	switch(num)
	{
	case 1:
		token = loadArmor("Hvy.Chain");
		break;
	case 2:
		token = loadWeapon("Claymore");
		break;
	case 3:
		token = loaditem("Potion2");
		break;
	}
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* knight::replenish() const
{
	return new knight;
}
//====================================================== Human Adventurer ===========================================
bool adventure::dropItem()
{
	return true;
}
Item* adventure::token(string Map)
{
	int num = rand()% 3 + 1;
	Item *token = new Item;
	switch(num)
	{
	case 1:
		token = loadArmor("Hvy.Chain");
		break;
	case 2:
		token = loadWeapon("+1 Claymore");
		break;
	case 3:
		token = loaditem("Potion2");
		break;
	}
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* adventure::replenish() const
{
	return new adventure;
}
void adventure::setmap(string M)
{
	map = M;
	int L = 1;
	int Lmod = 1;
	name = "Human Adventurer";
	
	if(map == "field1" || map == "road1")
	{
		L		= 3;
		Lmod	= 3;
	}
	if(map == "field2" || map == "road2")
	{
		L		= 6;
		Lmod	= 3;
	}
	if(map == "island2")
	{
		L		= 4;
		Lmod	= 9;
	}

	level =		rand()% L + Lmod;
	switch(level)
	{
	case 1:
		damage = 5;
		damMod = 5;
		hp = mhp = 25;
		evade = 3;
		gold = 25;
		exp = 15;
		break;
	case 2:
		damage = 6;
		damMod = 6;
		hp = mhp = 40;
		evade = 5;
		gold = 50;
		exp = 30;
		break;
	case 3:
		damage = 8;
		damMod = 8;
		hp = mhp = 65;
		ka = mka = 10;
		evade = 7;
		gold = 75;
		exp = 50;
		break;
	case 4:
		damage = 10;
		damMod = 10;
		hp = mhp = 90;
		ka = mka = 12;
		def		= 5;
		evade = 9;
		gold = 100;
		exp = 85;
		break;
	case 5:
		damage = 12;
		damMod = 12;
		hp = mhp = 120;
		ka = mka = 15;
		def		= 7;
		evade = 10;
		gold = 150;
		exp = 100;
		break;
	case 6:
		damage = 15;
		damMod = 15;
		hp = mhp = 150;
		ka = mka = 20;
		def		= 9;
		evade = 10;
		gold = 175;
		exp = 125;
		break;
	case 7:
		damage = 18;
		damMod = 18;
		hp = mhp = 160;
		ka = mka = 25;
		def		= 10;
		evade = 10;
		gold = 200;
		exp = 150;
	case 8:
		damage = 20;
		damMod = 20;
		hp = mhp = 170;
		ka = mka = 30;
		def		= 12;
		evade = 10;
		gold = 225;
		exp = 175;
		break;
	case 9:
		damage = 22;
		damMod = 22;
		hp = mhp = 200;
		ka = mka = 35;
		def		= 14;
		evade = 10;
		gold = 250;
		exp = 200;
		break;
	case 10:
		damage = 25;
		damMod = 25;
		hp = mhp = 220;
		ka = mka = 40;
		def		= 15;
		evade = 10;
		gold = 275;
		exp = 250;
		break;
	}
}
//====================================================== Human Wizard =============================================
bool wizard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* wizard::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* wizard::replenish() const
{
	return new wizard;
}
//====================================================== ==================================================

//======================================================{ GOBLIN_________________________________
bool goblin::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 35)
		return true;
	else 
		return false;	
}
Item*goblin::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Goblin Claw");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* goblin::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* goblin::replenish() const
{
	return new goblin;
}
//================================================ Giant Spider ===============================================

Item* gspider::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Spider Silk");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50);
	return left;
}
creature* gspider::replenish() const
{
	return new gspider;
}
//======================================================< WOLF-------------------------------->>>

Item* wolf::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Wolf pelt");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(15);
	return left;
}
creature* wolf::replenish() const
{
	return new wolf;
}
//====================================================== Raven ============================================
Item*raven::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Black Feather");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
creature* raven::replenish() const
{
	return new raven;
}
//====================================================== Snake ============================================
Item* snake::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Snake Skin");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(20);
	return left;
}
creature* snake::replenish() const
{
	return new snake;
}
//====================================================== Eagle ============================================
Item* eagle::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Talon");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(50);
 return left;
}
creature* eagle::replenish() const
{
 return new eagle;
}
//====================================================== Polar Bear ============================================
Item* pbear::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Polar Paw");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(100);
 return left;
}
creature* pbear::replenish() const
{
 return new pbear;
}
//====================================================== Salamander ============================================
Item* salamander::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Salamander Tongue");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
creature* salamander::replenish() const
{
 return new salamander;
}
//====================================================== Centipede ============================================
Item* centipede::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Insectoid Leg");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(150);
 return left;
}
creature* centipede::replenish() const
{
 return new centipede;
}
//====================================================== Wyvern ============================================
Item* wyvern::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Wyvern Wing");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
creature* wyvern::replenish() const
{
 return new wyvern;
}
//====================================================== Hydra ============================================
Item* hydra::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Hydra Scale");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(300);
 return left;
}
creature* hydra::replenish() const
{
 return new hydra;
}
//====================================================== Minotaur ============================================
Item* minator::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Minotaur Horn");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
creature* minator::replenish() const
{
 return new minator;
}
//====================================================== Gargoyle ============================================
bool gargoyle::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 25)
  return true;
 else
  return false;
}
Item* gargoyle::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Rock Hand");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(10);
 return left;
}
Item* gargoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
creature* gargoyle::replenish() const
{
 return new margoyle;
}
// Make gargoyles return more powerful form of gargoyle so hunting them is harder and more fun???
//========================================================================================================
//   Margoyle
//========================================================================================================
bool margoyle::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* margoyle::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Rock Foot");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(100);
 return left;
}
Item* margoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion3");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
creature* margoyle::replenish() const
{
 return new stargoyle;
}

//========================================================================================================
//   Stargoyle
//========================================================================================================
bool stargoyle::dropItem()
{
	return true;
}
Item* stargoyle::body(string Map) const
{
 Item *left = new Item;
 left->SetName("Rock Horn");
 left->SetMapName(Map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(10);
 return left;
}
Item* stargoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion4");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
creature* stargoyle::replenish() const
{
 return new gargoyle;
}
//====================================================== Ogre ==================================================
bool ogre::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* ogre::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Ogre Skull");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
 Item* ogre::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* ogre::replenish() const
{
	return new ogre;
}
//====================================================== Troll ============================================
bool troll::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;
}
 Item* troll::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("TrollSword");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
 Item* troll::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Troll Heart");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
creature* troll::replenish() const
{
	return new troll;
}
//==============================================  Magmaman  =========================================================
bool magmaman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;
}
 Item* magmaman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
 Item* magmaman::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Red Rock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(150);
	return left;
}
creature* magmaman::replenish() const
{
	return new troll;
}
//========================================================================================================
//   Cyclops
//========================================================================================================

bool cyclops::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*cyclops::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Giant Eye");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* cyclops::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* cyclops::replenish() const
{
	return new cyclops;
}
//========================================================================================================
//   Giant
//==========================================================================
bool giant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*giant::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Giant Nose");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* giant::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* giant::replenish() const
{
	return new giant;
}
//========================================================================================================
//   Frost Giant
//==========================================================================

bool frostgiant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*frostgiant::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Frostbite Finger");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* frostgiant::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* frostgiant::replenish() const
{
	return new frostgiant;
}
//========================================================================================================
//   Storm Giant
//==========================================================================
bool stormgiant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item* stormgiant::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Giant Toe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(false);
	left->SetCost(10);
	return left;
}
Item* stormgiant::token(string Map)
{
	int R = rand()% 4 + 1;
		Item *token = new Item;
	if(R = 4)
		token = loadArmor("Storm Shroud");
	if(R < 4)
		token = loadWeapon("StormSword");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* stormgiant::replenish() const
{
	 return new stormgiant;
}
//========================================================================================================
//   Nymph
//==========================================================================
bool nymph::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*nymph::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Crown of Laurels");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(175);
	return left;
}
Item* nymph::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* nymph::replenish() const
{
	return new nymph;
}
//========================================================================================================
//   Ice Wizard
//==========================================================================
bool icewizard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*icewizard::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Wizard's Beard");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
Item* icewizard::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* icewizard::replenish() const
{
	 return new icewizard;
}
//========================================================================================================
//   Snowman
//==========================================================================
bool snowman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item* snowman::body(string Map) const
{
	int R = rand()% 3 + 1;
	Item *left = new Item;
	switch(R)
	{
	case 1:
		left->SetName("Carrot");
		break;
	case 2:
		left->SetName("Corncob Pipe");
		break;
	case 3:
		left->SetName("Piece of Coal");
		break;
	}
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
Item* snowman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* snowman::replenish() const
{
	return new snowman;
}
//========================================================================================================
//   Shrine Guard
//==========================================================================
bool shrineguard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*shrineguard::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Ice Shrine Crest");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* shrineguard::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("IceChain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* shrineguard::replenish() const
{
	return new shrineguard;
}
//========================================================================================================
//   Rock Golem
//==========================================================================
bool rockgolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*rockgolem::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Chunk of Rock");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* rockgolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* rockgolem::replenish() const
{
	return new rockgolem;
}
//========================================================================================================
//   Iron Golem
//==========================================================================
bool irongolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*irongolem::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Hunk of Iron");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(400);
	return left;
}
Item* irongolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* irongolem::replenish() const
{
	return new irongolem;
}
//========================================================================================================
//   Steel Golem
//==========================================================================
bool steelgolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*steelgolem::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Lump of Steel");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(800);
	return left;
}
Item* steelgolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* steelgolem::replenish() const
{
	return new steelgolem;
}
//========================================================================================================
//   Treeman
//==========================================================================
bool treeman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else
		return false;
}
Item*treeman::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Lumber");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* treeman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* treeman::replenish() const
{
	return new treeman;
}
//========================================================================================================
//   Acolyte
//==========================================================================
bool acolyte::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*acolyte::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Acolyte's Soul");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
Item* acolyte::token(string Map)
{
	Item *token = new Item;
	token = loaditem("SoulCatcher");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* acolyte::replenish() const
{
	return new acolyte;
}

//========================================================================================================
//   Fire Demon
//==========================================================================
bool firedemon::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item*firedemon::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Fire Horn");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* firedemon::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* firedemon::replenish() const
{
	return new firedemon;
}
// Watch out for new items while testing. Make sure you put them into the items file

//====================================================== ==================================================
//======================================================< skeleton >==========================================

bool skel::dropItem()
{	
		return false;	
}
 Item* skel::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Rib Bone");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
creature* skel::replenish() const
{
	return new skel;
}
//======================================================< Ghoul >==========================================

bool ghoul::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 11)
		return true;
	else 
		return false;	
}
 Item* ghoul::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Mangled Flesh");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
 Item* ghoul::token(string Map)
{
	Item *token = new Item;
	token->SetName("Ghoul's Eye");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	token->SetCost(1000);
	return token;
}
creature* ghoul::replenish() const
{
	return new ghoul;
}
//====================================================== Ghost ================================================

 Item* ghost::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Disembodied Soul");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
creature* ghost::replenish() const
{
	return new ghost;
}

//====================================================== Phantom ================================================
bool phantom::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* phantom::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Onyx Stone");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}

Item* phantom::token(string Map)
{
	Item *token = new Item;
	token->SetName("Ruby Gem");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	token->SetCost(1000);
	return token;
}
creature* phantom::replenish() const
{
	return new phantom;
}
//====================================================== Vampire ==============================================
bool vampire::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* vampire::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Vampire Fang");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}

Item* vampire::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
creature* vampire::replenish() const
{
	return new vampire;
}

//			---------------------------------------------------------------------------------
//========================================================================================================
//													Bosses!!!
//========================================================================================================
//			----------------------------------------------------------------------------------



//==========================================================================
//   Wood Priest
//==========================================================================

bool woodpriest::dropItem()
{
	return true;	
}
 Item* woodpriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Slicer");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* woodpriest::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void woodpriest::win(Player *p2)
{
	creature::win(p2);
	text("After defeating the Wood Priest you must travel north.",13,11,white);
	text("Past the forests to the frozen tundra.",13,12,white);
	p2->PlotEventStates.Priest1 = true;
	text("",79,23,white);
	Sleep(5000);	
}
creature* woodpriest::replenish() const
{
	return new wolf;
}
void woodpriest::banter()
{
	clrtop(1);
	text("Who are you!?",13,2,white);
	text("You insignificant maggot. So you think you can aid the",13,3,white);
	text("gods? Your fate will be decided now!",13,4,white);
	text("When I CRUSH YOU!!!",13,5,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}

//==========================================================================
//   Ice Priest
//==========================================================================
bool icepriest::dropItem()
{
	return true;	
}
 Item* icepriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Ice Sword");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* icepriest::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void icepriest::win(Player *p2)
{
	creature::win(p2);
	text("After defeating the Ice Priest you must travel west.",13,11,white);
	text("Into the mountain and defeat the Fire Priest.",13,12,white);
	p2->PlotEventStates.Priest2 = true;
	text("",79,23,white);
	Sleep(5000);	
}
creature* icepriest::replenish() const
{
	return new pbear;
}
void icepriest::banter()
{
	clrtop(1);
	text("So... You defeated the priest of the wood.",13,2,white);
	text("You may be formidable, but you are no match for me.",13,3,white);
	text("And anyway, I thought you would be...",13,4,white);
	text("       ...taller.",13,5,white);
	text("",13,23,white);;
	system("pause");
	clrtop(1);
}
//==========================================================================
//   Fire Priest
//==========================================================================
bool firepriest::dropItem()
{
	return true;	
}
 Item* firepriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Fire Sword");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* firepriest::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void firepriest::win(Player *p2)
{
	creature::win(p2);
	text("After defeating the Fire Priest you must warp to the middle island.",13,11,white);
	text("Beneath the cemetary lies the teleporter.",13,12,white);
	p2->PlotEventStates.Priest3 = true;
	text("",79,23,white);
	Sleep(5000);	
}
creature* firepriest::replenish() const
{
	return new salamander;
}
void firepriest::banter()
{
	clrtop(1);
	text("You are disrupting everything! You fool! Don't you realize!?",13,2,white);
	text("Your power comes from the gods. They can take it away from you",13,3,white);
	text("once you've accomplished their goals! You're being USED!!!!",13,4,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}
//==========================================================================
//   Wind Priest
//==========================================================================
bool windpriest::dropItem()
{
	return true;	
}
 Item* windpriest::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* windpriest::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void windpriest::win(Player *p2)
{
	creature::win(p2);
	text("After defeating the the 4 priests. You must find the truth.",13,11,white);
	text("Go thee to the ancient water temple.",13,12,white);
	p2->PlotEventStates.Priest4 = true;
	text("",79,23,white);
	Sleep(5000);	
}
creature* windpriest::replenish() const
{
	return new wyvern;
}

void windpriest::banter()
{
	clrtop(1);
	text("Your power may be great, however, you will not last long.",13,2,white);
	text("This devilish island will be your grave.",13,3,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}
//==========================================================================
//   God of War
//==========================================================================
bool godofwar::dropItem()
{
	return false;	
}
Item* godofwar::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Sword");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void godofwar::win(Player *p2)
{
	creature::win(p2);
	Sleep(3000);	
}

creature* godofwar::replenish() const
{
	return new goblin;
}
void godofwar::banter()
{
	clrtop(1);
	text("You have served me well human. However, your power is now",13,2,white);
	text("far too great. Becuase you threaten the power of the gods",13,3,white);
	text("I must now dispose of you. Kind of like a paper plate!",13,4,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}
//==========================================================================
//   God of Life
//==========================================================================
bool godoflife::dropItem()
{
	return false;	
}
Item* godoflife::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}

void godoflife::win(Player *p2)
{
	creature::win(p2);
	Sleep(3000);	
}

creature* godoflife::replenish() const
{
	return new goblin;
}

void godoflife::banter()
{
	clrtop(1);
	text("Your power has become great. I believe you can rule the gods!",13,2,white);
	text("To test your mettle, you must defeat me, and take my place as",13,3,white);
	text("the god of life. Only then can you ensure peace for all.",13,4,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}
//==========================================================================
//   God of Chaos
//==========================================================================
bool godofchaos::dropItem()
{
	return false;	
}
Item* godofchaos::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void godofchaos::win(Player *p2)
{
	creature::win(p2);
	Sleep(3000);	
}

creature* godofchaos::replenish() const
{
	return new goblin;
}
void godofchaos::banter()
{
	clrtop(1);
	text("Our alliance was an uneasy one from the beginning.",13,2,white);
	text("Now is the time to see who can really rule the world!",13,3,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}

//==========================================================================
//   God of Death
//==========================================================================
bool godofdeath::dropItem()
{
	return false;	
}
Item* godofdeath::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void godofdeath::win(Player *p2)
{
	creature::win(p2);
	Sleep(3000);	
}

creature* godofdeath::replenish() const
{
	return new goblin;
}

void godofdeath::banter()
{
	clrtop(1);
	text("I usually reward my servants well. You, however, have grown quite",13,2,white);
	text("powerful. If I were to slay you and absorb your power...",13,3,white);
	text("... I could rise from my pit and rule the overworld as well!",13,4,white);
	text("So, don't think of it as betrayal. Think of it as another fight.", 79, 23,white);
	text("",13,23,white);
	system("pause");
	clrtop(1);
}
//==========================================================================
//   Green Dragon
//==========================================================================
bool greendragon::dropItem()
{
	return true;
}
Item*greendragon::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Green Scale");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* greendragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("GreenMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void greendragon::win(Player *p2)
{
	creature::win(p2);
	text("The Green Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the island.",13,12,white);
	Sleep(3000);	
}

creature* greendragon::replenish() const
{
	return new goblin;
}

void greendragon::banter()
{
}
//==========================================================================
//   Blue Dragon
//==========================================================================
bool bluedragon::dropItem()
{
	return true;
}
Item*bluedragon::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Blue Scale");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* bluedragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("BlueMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void bluedragon::win(Player *p2)
{
	creature::win(p2);
	text("The Blue Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the tundra.",13,12,white);
	Sleep(3000);	
}
creature* bluedragon::replenish() const
{
	return new goblin;
}
void bluedragon::banter()
{
}
//==========================================================================
//   Red Dragon
//==========================================================================
bool reddragon::dropItem()
{
	return true;
}
Item*reddragon::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Red Scale");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* reddragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("RedMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void reddragon::win(Player *p2)
{
	creature::win(p2);
	text("The Red Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the mountains.",13,12,white);
	Sleep(3000);	
}
creature* reddragon::replenish() const
{
	return new goblin;
}
void reddragon::banter()
{
}
//==========================================================================
//  Fly
//==========================================================================
bool fly::dropItem()
{
	return false;
}
Item*fly::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Dead Fly");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
creature* fly::replenish() const
{
	return new fly;
}
//==========================================================================
//   Monk
//==========================================================================
bool monk::dropItem()
{
	return true;
}
Item*monk::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Monk's Cowl");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* monk::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void monk::win(Player *p2)
{
	creature::win(p2);
	text("The peaceful monk lies vanquished. ",13,11,white);
	text("Don't you feel better about yourself now?",13,11,white);
	Sleep(3000);	
}
creature* monk::replenish() const
{
	return new fly;
}

void monk::banter()
{
}



