#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"
#include "World.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define blue FOREGROUND_BLUE
//======================================================  ELF  ==========================================
bool Elf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Elf::body(string Map) const 
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
Item* Elf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}

void Elf::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(Gold,20,11,green);
	num(Experience,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + Gold);
	p2->SetExperience(p2->GetExperience() + Experience);
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
Creature* Elf::replenish() const
{
	return new Elf;
}
//====================================================== Elven Mage ================================================
bool ElvenMage::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* ElvenMage::body(string Map) const 
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
Item* ElvenMage::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* ElvenMage::replenish() const
{
	return new ElvenMage;
}
//====================================================== Elven Warrior ==============================================
bool ElvenWarrior::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* ElvenWarrior::body(string Map) const
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
Item* ElvenWarrior::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("Elvenchain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* ElvenWarrior::replenish() const
{
	return new ElvenWarrior;
}
//====================================================== Fire Elf ==============================================
bool FireElf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* FireElf::body(string Map) const
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
Item* FireElf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* FireElf::replenish() const
{
	return new FireElf;
}
//====================================================== Ice Elf ==============================================
bool IceElf::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* IceElf::body(string Map) const
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
Item* IceElf::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* IceElf::replenish() const
{
	return new IceElf;
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
	left->SetCost(50 * Level);
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
Creature* ranger::replenish() const
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
	num(Gold,20,11,green);
	num(Experience,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + Gold);
	p2->SetExperience(p2->GetExperience() + Experience);
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
Creature* Orc::replenish() const
{
	return new Orc;
}
//====================================================== Orc Sorceror ===========================================
bool OrcSorceror::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 85)
		return true;
	else 
		return false;	
}
Item* OrcSorceror::body(string Map) const 
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
Item* OrcSorceror::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* OrcSorceror::replenish() const
{
	return new OrcSorceror;
}
//======================================================= Orc Soldier ==========================================
bool OrcSoldier::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* OrcSoldier::body(string Map) const
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
Item* OrcSoldier::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("Orc_Mail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* OrcSoldier::replenish() const
{
	return new OrcSoldier;
}
//====================================================== Fire Orc ==================================================

bool FireOrc::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* FireOrc::body(string Map) const
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
Item* FireOrc::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
Creature* FireOrc::replenish() const
{
 return new FireOrc;
}
//====================================================== Ice Orc ==================================================
bool IceOrc::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* IceOrc::body(string Map) const
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
Item* IceOrc::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
Creature* IceOrc::replenish() const
{
 return new IceOrc;
}
//====================================================== Orc Wanderer ==================================================
bool OrcWanderer::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* OrcWanderer::body(string Map) const
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
Item* OrcWanderer::token(string Map)
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
Creature* OrcWanderer::replenish() const
{
	return new OrcWanderer;
}
//====================================================== Human ==================================================
bool Human::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Human::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Item* Human::body(string Map) const
{
	Item *left = new Item;
	left->SetName("Last Will");
	left->SetMapName(Map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost((rand()% 100 + 1) * Level);
	return left;
}

void Human::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(Gold,20,11,green);
	num(Experience,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + Gold);
	p2->SetExperience(p2->GetExperience() + Experience);
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
Creature* Human::replenish() const
{
	return new Human;
}
//====================================================== Human Knight ============================================
bool Knight::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Knight::token(string Map)
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
Creature* Knight::replenish() const
{
	return new Knight;
}
//====================================================== Human Adventurer ===========================================
bool Adventurer::dropItem()
{
	return true;
}
Item* Adventurer::token(string Map)
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
Creature* Adventurer::replenish() const
{
	return new Adventurer;
}
void Adventurer::setmap(string M)
{
	Map = M;
	int L = 1;
	int Lmod = 1;
	Name = "Human Adventurer";
	
	if(Map == "field1" || Map == "road1")
	{
		L		= 3;
		Lmod	= 3;
	}
	if(Map == "field2" || Map == "road2")
	{
		L		= 6;
		Lmod	= 3;
	}
	if(Map == "island2")
	{
		L		= 4;
		Lmod	= 9;
	}

	Level =		rand()% L + Lmod;
	switch(Level)
	{
	case 1:
		Damage = 5;
		DamageModifier = 5;
		HitPoints = MaxHP = 25;
		Evade = 3;
		Gold = 25;
		Experience = 15;
		break;
	case 2:
		Damage = 6;
		DamageModifier = 6;
		HitPoints = MaxHP = 40;
		Evade = 5;
		Gold = 50;
		Experience = 30;
		break;
	case 3:
		Damage = 8;
		DamageModifier = 8;
		HitPoints = MaxHP = 65;
		Ka = MaxKa = 10;
		Evade = 7;
		Gold = 75;
		Experience = 50;
		break;
	case 4:
		Damage = 10;
		DamageModifier = 10;
		HitPoints = MaxHP = 90;
		Ka = MaxKa = 12;
		Defense		= 5;
		Evade = 9;
		Gold = 100;
		Experience = 85;
		break;
	case 5:
		Damage = 12;
		DamageModifier = 12;
		HitPoints = MaxHP = 120;
		Ka = MaxKa = 15;
		Defense		= 7;
		Evade = 10;
		Gold = 150;
		Experience = 100;
		break;
	case 6:
		Damage = 15;
		DamageModifier = 15;
		HitPoints = MaxHP = 150;
		Ka = MaxKa = 20;
		Defense		= 9;
		Evade = 10;
		Gold = 175;
		Experience = 125;
		break;
	case 7:
		Damage = 18;
		DamageModifier = 18;
		HitPoints = MaxHP = 160;
		Ka = MaxKa = 25;
		Defense		= 10;
		Evade = 10;
		Gold = 200;
		Experience = 150;
	case 8:
		Damage = 20;
		DamageModifier = 20;
		HitPoints = MaxHP = 170;
		Ka = MaxKa = 30;
		Defense		= 12;
		Evade = 10;
		Gold = 225;
		Experience = 175;
		break;
	case 9:
		Damage = 22;
		DamageModifier = 22;
		HitPoints = MaxHP = 200;
		Ka = MaxKa = 35;
		Defense		= 14;
		Evade = 10;
		Gold = 250;
		Experience = 200;
		break;
	case 10:
		Damage = 25;
		DamageModifier = 25;
		HitPoints = MaxHP = 220;
		Ka = MaxKa = 40;
		Defense		= 15;
		Evade = 10;
		Gold = 275;
		Experience = 250;
		break;
	}
}
//====================================================== Human Wizard =============================================
bool Wizard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* Wizard::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Wizard::replenish() const
{
	return new Wizard;
}
//====================================================== ==================================================

//======================================================{ GOBLIN_________________________________
bool Goblin::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 35)
		return true;
	else 
		return false;	
}
Item*Goblin::body(string Map) const
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
Item* Goblin::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Goblin::replenish() const
{
	return new Goblin;
}
//================================================ Giant Spider ===============================================

Item* GiantSpider::body(string Map) const
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
Creature* GiantSpider::replenish() const
{
	return new GiantSpider;
}
//======================================================< WOLF-------------------------------->>>

Item* Wolf::body(string Map) const
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
Creature* Wolf::replenish() const
{
	return new Wolf;
}
//====================================================== Raven ============================================
Item*Raven::body(string Map) const
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
Creature* Raven::replenish() const
{
	return new Raven;
}
//====================================================== Snake ============================================
Item* Snake::body(string Map) const
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
Creature* Snake::replenish() const
{
	return new Snake;
}
//====================================================== Eagle ============================================
Item* Eagle::body(string Map) const
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
Creature* Eagle::replenish() const
{
 return new Eagle;
}
//====================================================== Polar Bear ============================================
Item* PolarBear::body(string Map) const
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
Creature* PolarBear::replenish() const
{
 return new PolarBear;
}
//====================================================== Salamander ============================================
Item* Salamander::body(string Map) const
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
Creature* Salamander::replenish() const
{
 return new Salamander;
}
//====================================================== Centipede ============================================
Item* Centipede::body(string Map) const
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
Creature* Centipede::replenish() const
{
 return new Centipede;
}
//====================================================== Wyvern ============================================
Item* Wyvern::body(string Map) const
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
Creature* Wyvern::replenish() const
{
 return new Wyvern;
}
//====================================================== Hydra ============================================
Item* Hydra::body(string Map) const
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
Creature* Hydra::replenish() const
{
 return new Hydra;
}
//====================================================== Minotaur ============================================
Item* Minotaur::body(string Map) const
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
Creature* Minotaur::replenish() const
{
 return new Minotaur;
}
//====================================================== Gargoyle ============================================
bool Gargoyle::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 25)
  return true;
 else
  return false;
}
Item* Gargoyle::body(string Map) const
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
Item* Gargoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
Creature* Gargoyle::replenish() const
{
 return new Margoyle;
}
// Make gargoyles return more powerful form of gargoyle so hunting them is harder and more fun???
//========================================================================================================
//   Margoyle
//========================================================================================================
bool Margoyle::dropItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* Margoyle::body(string Map) const
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
Item* Margoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion3");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
Creature* Margoyle::replenish() const
{
 return new Stargoyle;
}

//========================================================================================================
//   Stargoyle
//========================================================================================================
bool Stargoyle::dropItem()
{
	return true;
}
Item* Stargoyle::body(string Map) const
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
Item* Stargoyle::token(string Map)
{
 Item *token = new Item;
 token = loaditem("Potion4");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(Map);
 return token;
}
Creature* Stargoyle::replenish() const
{
 return new Gargoyle;
}
//====================================================== Ogre ==================================================
bool Ogre::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Ogre::body(string Map) const
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
 Item* Ogre::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Ogre::replenish() const
{
	return new Ogre;
}
//====================================================== Troll ============================================
bool Troll::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;
}
 Item* Troll::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("TrollSword");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
 Item* Troll::body(string Map) const
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
Creature* Troll::replenish() const
{
	return new Troll;
}
//==============================================  Magmaman  =========================================================
bool Magmaman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;
}
 Item* Magmaman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
 Item* Magmaman::body(string Map) const
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
Creature* Magmaman::replenish() const
{
	return new Troll;
}
//========================================================================================================
//   Cyclops
//========================================================================================================

bool Cyclops::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Cyclops::body(string Map) const
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
Item* Cyclops::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Cyclops::replenish() const
{
	return new Cyclops;
}
//========================================================================================================
//   Giant
//==========================================================================
bool Giant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Giant::body(string Map) const
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
Item* Giant::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Giant::replenish() const
{
	return new Giant;
}
//========================================================================================================
//   Frost Giant
//==========================================================================

bool FrostGiant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*FrostGiant::body(string Map) const
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
Item* FrostGiant::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* FrostGiant::replenish() const
{
	return new FrostGiant;
}
//========================================================================================================
//   Storm Giant
//==========================================================================
bool StormGiant::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item* StormGiant::body(string Map) const
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
Item* StormGiant::token(string Map)
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
Creature* StormGiant::replenish() const
{
	 return new StormGiant;
}
//========================================================================================================
//   Nymph
//==========================================================================
bool Nymph::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Nymph::body(string Map) const
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
Item* Nymph::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Nymph::replenish() const
{
	return new Nymph;
}
//========================================================================================================
//   Ice Wizard
//==========================================================================
bool IceWizard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*IceWizard::body(string Map) const
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
Item* IceWizard::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* IceWizard::replenish() const
{
	 return new IceWizard;
}
//========================================================================================================
//   Snowman
//==========================================================================
bool Snowman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item* Snowman::body(string Map) const
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
Item* Snowman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Snowman::replenish() const
{
	return new Snowman;
}
//========================================================================================================
//   Shrine Guard
//==========================================================================
bool ShrineGuard::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*ShrineGuard::body(string Map) const
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
Item* ShrineGuard::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("IceChain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* ShrineGuard::replenish() const
{
	return new ShrineGuard;
}
//========================================================================================================
//   Rock Golem
//==========================================================================
bool RockGolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*RockGolem::body(string Map) const
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
Item* RockGolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* RockGolem::replenish() const
{
	return new RockGolem;
}
//========================================================================================================
//   Iron Golem
//==========================================================================
bool IronGolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*IronGolem::body(string Map) const
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
Item* IronGolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* IronGolem::replenish() const
{
	return new IronGolem;
}
//========================================================================================================
//   Steel Golem
//==========================================================================
bool SteelGolem::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*SteelGolem::body(string Map) const
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
Item* SteelGolem::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* SteelGolem::replenish() const
{
	return new SteelGolem;
}
//========================================================================================================
//   Treeman
//==========================================================================
bool Treeman::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else
		return false;
}
Item*Treeman::body(string Map) const
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
Item* Treeman::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Treeman::replenish() const
{
	return new Treeman;
}
//========================================================================================================
//   Acolyte
//==========================================================================
bool Acolyte::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Acolyte::body(string Map) const
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
Item* Acolyte::token(string Map)
{
	Item *token = new Item;
	token = loaditem("SoulCatcher");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Acolyte::replenish() const
{
	return new Acolyte;
}

//========================================================================================================
//   Fire Demon
//==========================================================================
bool FireDemon::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item*FireDemon::body(string Map) const
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
Item* FireDemon::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* FireDemon::replenish() const
{
	return new FireDemon;
}
// Watch out for new items while testing. Make sure you put them into the items file

//====================================================== ==================================================
//======================================================< skeleton >==========================================

bool Skeleton::dropItem()
{	
		return false;	
}
 Item* Skeleton::body(string Map) const
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
Creature* Skeleton::replenish() const
{
	return new Skeleton;
}
//======================================================< Ghoul >==========================================

bool Ghoul::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 11)
		return true;
	else 
		return false;	
}
 Item* Ghoul::body(string Map) const
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
 Item* Ghoul::token(string Map)
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
Creature* Ghoul::replenish() const
{
	return new Ghoul;
}
//====================================================== Ghost ================================================

 Item* Ghost::body(string Map) const
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
Creature* Ghost::replenish() const
{
	return new Ghost;
}

//====================================================== Phantom ================================================
bool Phantom::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* Phantom::body(string Map) const
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

Item* Phantom::token(string Map)
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
Creature* Phantom::replenish() const
{
	return new Phantom;
}
//====================================================== Vampire ==============================================
bool Vampire::dropItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* Vampire::body(string Map) const
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

Item* Vampire::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
Creature* Vampire::replenish() const
{
	return new Vampire;
}

//			---------------------------------------------------------------------------------
//========================================================================================================
//													Bosses!!!
//========================================================================================================
//			----------------------------------------------------------------------------------



//==========================================================================
//   Wood Priest
//==========================================================================

bool WoodPriest::dropItem()
{
	return true;	
}
 Item* WoodPriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Slicer");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* WoodPriest::body(string Map) const
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
void WoodPriest::win(Player *p2)
{
	Creature::win(p2);
	text("After defeating the Wood Priest you must travel north.",13,11,white);
	text("Past the forests to the frozen tundra.",13,12,white);
	p2->PlotEventStates.Priest1 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* WoodPriest::replenish() const
{
	return new Wolf;
}
void WoodPriest::banter()
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
bool IcePriest::dropItem()
{
	return true;	
}
 Item* IcePriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Ice Sword");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* IcePriest::body(string Map) const
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
void IcePriest::win(Player *p2)
{
	Creature::win(p2);
	text("After defeating the Ice Priest you must travel west.",13,11,white);
	text("Into the mountain and defeat the Fire Priest.",13,12,white);
	p2->PlotEventStates.Priest2 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* IcePriest::replenish() const
{
	return new PolarBear;
}
void IcePriest::banter()
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
bool FirePriest::dropItem()
{
	return true;	
}
 Item* FirePriest::token(string Map)
{
	Item *token = new Item;
	token = loadWeapon("Fire Sword");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* FirePriest::body(string Map) const
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
void FirePriest::win(Player *p2)
{
	Creature::win(p2);
	text("After defeating the Fire Priest you must warp to the middle island.",13,11,white);
	text("Beneath the cemetary lies the teleporter.",13,12,white);
	p2->PlotEventStates.Priest3 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* FirePriest::replenish() const
{
	return new Salamander;
}
void FirePriest::banter()
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
bool WindPriest::dropItem()
{
	return true;	
}
 Item* WindPriest::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetMapName(Map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* WindPriest::body(string Map) const
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
void WindPriest::win(Player *p2)
{
	Creature::win(p2);
	text("After defeating the the 4 priests. You must find the truth.",13,11,white);
	text("Go thee to the ancient water temple.",13,12,white);
	p2->PlotEventStates.Priest4 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* WindPriest::replenish() const
{
	return new Wyvern;
}

void WindPriest::banter()
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
bool GodOfWar::dropItem()
{
	return false;	
}
Item* GodOfWar::body(string Map) const
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
void GodOfWar::win(Player *p2)
{
	Creature::win(p2);
	Sleep(3000);	
}

Creature* GodOfWar::replenish() const
{
	return new Goblin;
}
void GodOfWar::banter()
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
bool GodOfLife::dropItem()
{
	return false;	
}
Item* GodOfLife::body(string Map) const
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

void GodOfLife::win(Player *p2)
{
	Creature::win(p2);
	Sleep(3000);	
}

Creature* GodOfLife::replenish() const
{
	return new Goblin;
}

void GodOfLife::banter()
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
bool GodOfChaos::dropItem()
{
	return false;	
}
Item* GodOfChaos::body(string Map) const
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
void GodOfChaos::win(Player *p2)
{
	Creature::win(p2);
	Sleep(3000);	
}

Creature* GodOfChaos::replenish() const
{
	return new Goblin;
}
void GodOfChaos::banter()
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
bool GodOfDeath::dropItem()
{
	return false;	
}
Item* GodOfDeath::body(string Map) const
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
void GodOfDeath::win(Player *p2)
{
	Creature::win(p2);
	Sleep(3000);	
}

Creature* GodOfDeath::replenish() const
{
	return new Goblin;
}

void GodOfDeath::banter()
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
bool GreenDragon::dropItem()
{
	return true;
}
Item*GreenDragon::body(string Map) const
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
Item* GreenDragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("GreenMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void GreenDragon::win(Player *p2)
{
	Creature::win(p2);
	text("The Green Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the island.",13,12,white);
	Sleep(3000);	
}

Creature* GreenDragon::replenish() const
{
	return new Goblin;
}

void GreenDragon::banter()
{
}
//==========================================================================
//   Blue Dragon
//==========================================================================
bool BlueDragon::dropItem()
{
	return true;
}
Item*BlueDragon::body(string Map) const
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
Item* BlueDragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("BlueMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void BlueDragon::win(Player *p2)
{
	Creature::win(p2);
	text("The Blue Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the tundra.",13,12,white);
	Sleep(3000);	
}
Creature* BlueDragon::replenish() const
{
	return new Goblin;
}
void BlueDragon::banter()
{
}
//==========================================================================
//   Red Dragon
//==========================================================================
bool RedDragon::dropItem()
{
	return true;
}
Item*RedDragon::body(string Map) const
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
Item* RedDragon::token(string Map)
{
	Item *token = new Item;
	token = loadArmor("RedMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void RedDragon::win(Player *p2)
{
	Creature::win(p2);
	text("The Red Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the mountains.",13,12,white);
	Sleep(3000);	
}
Creature* RedDragon::replenish() const
{
	return new Goblin;
}
void RedDragon::banter()
{
}
//==========================================================================
//  Fly
//==========================================================================
bool Fly::dropItem()
{
	return false;
}
Item*Fly::body(string Map) const
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
Creature* Fly::replenish() const
{
	return new Fly;
}
//==========================================================================
//   Monk
//==========================================================================
bool Monk::dropItem()
{
	return true;
}
Item*Monk::body(string Map) const
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
Item* Monk::token(string Map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(Map);
	return token;
}
void Monk::win(Player *p2)
{
	Creature::win(p2);
	text("The peaceful monk lies vanquished. ",13,11,white);
	text("Don't you feel better about yourself now?",13,11,white);
	Sleep(3000);	
}
Creature* Monk::replenish() const
{
	return new Fly;
}

void Monk::banter()
{
}



