#include <Windows.h>		//I'm not sure
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
bool Elf::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Elf::Body(string map) const 
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50);
	return left;
}
Item* Elf::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}

void Elf::Win(Player *p2)
{
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
Creature* Elf::Replenish() const
{
	return new Elf;
}
//====================================================== Elven Mage ================================================
bool ElvenMage::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* ElvenMage::Body(string map) const 
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* ElvenMage::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* ElvenMage::Replenish() const
{
	return new ElvenMage;
}
//====================================================== Elven Warrior ==============================================
bool ElvenWarrior::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* ElvenWarrior::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* ElvenWarrior::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("Elvenchain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* ElvenWarrior::Replenish() const
{
	return new ElvenWarrior;
}
//====================================================== Fire Elf ==============================================
bool FireElf::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* FireElf::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Red Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* FireElf::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* FireElf::Replenish() const
{
	return new FireElf;
}
//====================================================== Ice Elf ==============================================
bool IceElf::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
	return true;
	else
	return false;
}
Item* IceElf::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Bluewhite Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* IceElf::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* IceElf::Replenish() const
{
	return new IceElf;
}
//====================================================== Elven Ranger ==============================================
bool ranger::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
	return true;
	else
	return false;
}
Item* ranger::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Elven Lock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50 * Level);
	return left;
}
Item* ranger::Token(string map)
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
	token->SetMapName(map);
	return token;
}
Creature* ranger::Replenish() const
{
	return new ranger;
}
//======================================================{ ORC ==================================================

bool Orc::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else 
		return false;	
}
Item* Orc::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(75);
	return left;
}
Item* Orc::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}

void Orc::Win(Player *p2)
{
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
Creature* Orc::Replenish() const
{
	return new Orc;
}
//====================================================== Orc Sorceror ===========================================
bool OrcSorceror::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 85)
		return true;
	else 
		return false;	
}
Item* OrcSorceror::Body(string map) const 
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(300);
	return left;
}
Item* OrcSorceror::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* OrcSorceror::Replenish() const
{
	return new OrcSorceror;
}
//======================================================= Orc Soldier ==========================================
bool OrcSoldier::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* OrcSoldier::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Orc Ear");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(150);
	return left;
}
Item* OrcSoldier::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("Orc_Mail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* OrcSoldier::Replenish() const
{
	return new OrcSoldier;
}
//====================================================== Fire Orc ==================================================

bool FireOrc::DroppedItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* FireOrc::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Red Orc Ear");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
Item* FireOrc::Token(string map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(map);
 return token;
}
Creature* FireOrc::Replenish() const
{
 return new FireOrc;
}
//====================================================== Ice Orc ==================================================
bool IceOrc::DroppedItem()
{
 int num = rand()% 100 + 1;
 if(num < 85)
  return true;
 else
  return false;
}
Item* IceOrc::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Blue Orc Ear");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
Item* IceOrc::Token(string map)
{
 Item *token = new Item;
 token = loaditem("Potion2");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(map);
 return token;
}
Creature* IceOrc::Replenish() const
{
 return new IceOrc;
}
//====================================================== Orc Wanderer ==================================================
bool OrcWanderer::DroppedItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* OrcWanderer::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Orc Ear");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
Item* OrcWanderer::Token(string map)
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
	token->SetMapName(map);
	return token;
}
Creature* OrcWanderer::Replenish() const
{
	return new OrcWanderer;
}
//====================================================== Human ==================================================
bool Human::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Human::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Item* Human::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Last Will");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost((rand()% 100 + 1) * Level);
	return left;
}

void Human::Win(Player *p2)
{
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
Creature* Human::Replenish() const
{
	return new Human;
}
//====================================================== Human Knight ============================================
bool Knight::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Knight::Token(string map)
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
	token->SetMapName(map);
	return token;
}
Creature* Knight::Replenish() const
{
	return new Knight;
}
//====================================================== Human Adventurer ===========================================
bool Adventurer::DroppedItem()
{
	return true;
}
Item* Adventurer::Token(string map)
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
	token->SetMapName(map);
	return token;
}
Creature* Adventurer::Replenish() const
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
bool Wizard::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;	
}
Item* Wizard::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Wizard::Replenish() const
{
	return new Wizard;
}
//====================================================== ==================================================

//======================================================{ GOBLIN_________________________________
bool Goblin::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 35)
		return true;
	else 
		return false;	
}
Item*Goblin::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Goblin Claw");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* Goblin::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Goblin::Replenish() const
{
	return new Goblin;
}
//================================================ Giant Spider ===============================================

Item* GiantSpider::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Spider Silk");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(50);
	return left;
}
Creature* GiantSpider::Replenish() const
{
	return new GiantSpider;
}
//======================================================< WOLF-------------------------------->>>

Item* Wolf::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Wolf pelt");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(15);
	return left;
}
Creature* Wolf::Replenish() const
{
	return new Wolf;
}
//====================================================== Raven ============================================
Item*Raven::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Black Feather");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Creature* Raven::Replenish() const
{
	return new Raven;
}
//====================================================== Snake ============================================
Item* Snake::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Snake Skin");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(20);
	return left;
}
Creature* Snake::Replenish() const
{
	return new Snake;
}
//====================================================== Eagle ============================================
Item* Eagle::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Talon");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(50);
 return left;
}
Creature* Eagle::Replenish() const
{
 return new Eagle;
}
//====================================================== Polar Bear ============================================
Item* PolarBear::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Polar Paw");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(100);
 return left;
}
Creature* PolarBear::Replenish() const
{
 return new PolarBear;
}
//====================================================== Salamander ============================================
Item* Salamander::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Salamander Tongue");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(200);
 return left;
}
Creature* Salamander::Replenish() const
{
 return new Salamander;
}
//====================================================== Centipede ============================================
Item* Centipede::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Insectoid Leg");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(150);
 return left;
}
Creature* Centipede::Replenish() const
{
 return new Centipede;
}
//====================================================== Wyvern ============================================
Item* Wyvern::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Wyvern Wing");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
Creature* Wyvern::Replenish() const
{
 return new Wyvern;
}
//====================================================== Hydra ============================================
Item* Hydra::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Hydra Scale");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(300);
 return left;
}
Creature* Hydra::Replenish() const
{
 return new Hydra;
}
//====================================================== Minotaur ============================================
Item* Minotaur::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Minotaur Horn");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(250);
 return left;
}
Creature* Minotaur::Replenish() const
{
 return new Minotaur;
}
//====================================================== Gargoyle ============================================
bool Gargoyle::DroppedItem()
{
 int num = rand()% 100 + 1;
 if(num < 25)
  return true;
 else
  return false;
}
Item* Gargoyle::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Rock Hand");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(10);
 return left;
}
Item* Gargoyle::Token(string map)
{
 Item *token = new Item;
 token = loaditem("Potion");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(map);
 return token;
}
Creature* Gargoyle::Replenish() const
{
 return new Margoyle;
}
// Make gargoyles return more powerful form of gargoyle so hunting them is harder and more fun???
//========================================================================================================
//   Margoyle
//========================================================================================================
bool Margoyle::DroppedItem()
{
 int num = rand()% 100 + 1;
 if(num < 50)
  return true;
 else
  return false;
}
Item* Margoyle::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Rock Foot");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(100);
 return left;
}
Item* Margoyle::Token(string map)
{
 Item *token = new Item;
 token = loaditem("Potion3");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(map);
 return token;
}
Creature* Margoyle::Replenish() const
{
 return new Stargoyle;
}

//========================================================================================================
//   Stargoyle
//========================================================================================================
bool Stargoyle::DroppedItem()
{
	return true;
}
Item* Stargoyle::Body(string map) const
{
 Item *left = new Item;
 left->SetName("Rock Horn");
 left->SetMapName(map);
 left->SetPositionX(X);
 left->SetPositionY(Y);
 left->SetKeep(true);
 left->SetCost(10);
 return left;
}
Item* Stargoyle::Token(string map)
{
 Item *token = new Item;
 token = loaditem("Potion4");
 token->SetPositionX(X);
 token->SetPositionY(Y);
 token->SetMapName(map);
 return token;
}
Creature* Stargoyle::Replenish() const
{
 return new Gargoyle;
}
//====================================================== Ogre ==================================================
bool Ogre::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;	
}
Item* Ogre::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Ogre Skull");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
 Item* Ogre::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Ogre::Replenish() const
{
	return new Ogre;
}
//====================================================== Troll ============================================
bool Troll::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else 
		return false;
}
 Item* Troll::Token(string map)
{
	Item *token = new Item;
	token = loadWeapon("TrollSword");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
 Item* Troll::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Troll Heart");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Creature* Troll::Replenish() const
{
	return new Troll;
}
//==============================================  Magmaman  =========================================================
bool Magmaman::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else 
		return false;
}
 Item* Magmaman::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
 Item* Magmaman::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Red Rock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(150);
	return left;
}
Creature* Magmaman::Replenish() const
{
	return new Troll;
}
//========================================================================================================
//   Cyclops
//========================================================================================================

bool Cyclops::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Cyclops::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Giant Eye");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* Cyclops::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Cyclops::Replenish() const
{
	return new Cyclops;
}
//========================================================================================================
//   Giant
//==========================================================================
bool Giant::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Giant::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Giant Nose");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* Giant::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Giant::Replenish() const
{
	return new Giant;
}
//========================================================================================================
//   Frost Giant
//==========================================================================

bool FrostGiant::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*FrostGiant::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Frostbite Finger");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(10);
	return left;
}
Item* FrostGiant::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* FrostGiant::Replenish() const
{
	return new FrostGiant;
}
//========================================================================================================
//   Storm Giant
//==========================================================================
bool StormGiant::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item* StormGiant::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Giant Toe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(false);
	left->SetCost(10);
	return left;
}
Item* StormGiant::Token(string map)
{
	int R = rand()% 4 + 1;
		Item *token = new Item;
	if(R == 4)
		token = loadArmor("Storm Shroud");
	if(R < 4)
		token = loadWeapon("StormSword");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* StormGiant::Replenish() const
{
	 return new StormGiant;
}
//========================================================================================================
//   Nymph
//==========================================================================
bool Nymph::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Nymph::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Crown of Laurels");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(175);
	return left;
}
Item* Nymph::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Nymph::Replenish() const
{
	return new Nymph;
}
//========================================================================================================
//   Ice Wizard
//==========================================================================
bool IceWizard::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*IceWizard::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Wizard's Beard");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
Item* IceWizard::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* IceWizard::Replenish() const
{
	 return new IceWizard;
}
//========================================================================================================
//   Snowman
//==========================================================================
bool Snowman::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item* Snowman::Body(string map) const
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
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(30);
	return left;
}
Item* Snowman::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Refresh");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Snowman::Replenish() const
{
	return new Snowman;
}
//========================================================================================================
//   Shrine Guard
//==========================================================================
bool ShrineGuard::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*ShrineGuard::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Ice Shrine Crest");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* ShrineGuard::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("IceChain");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* ShrineGuard::Replenish() const
{
	return new ShrineGuard;
}
//========================================================================================================
//   Rock Golem
//==========================================================================
bool RockGolem::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*RockGolem::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Chunk of Rock");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}
Item* RockGolem::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* RockGolem::Replenish() const
{
	return new RockGolem;
}
//========================================================================================================
//   Iron Golem
//==========================================================================
bool IronGolem::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*IronGolem::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Hunk of Iron");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(400);
	return left;
}
Item* IronGolem::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* IronGolem::Replenish() const
{
	return new IronGolem;
}
//========================================================================================================
//   Steel Golem
//==========================================================================
bool SteelGolem::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*SteelGolem::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Lump of Steel");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(800);
	return left;
}
Item* SteelGolem::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* SteelGolem::Replenish() const
{
	return new SteelGolem;
}
//========================================================================================================
//   Treeman
//==========================================================================
bool Treeman::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 75)
		return true;
	else
		return false;
}
Item*Treeman::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Lumber");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* Treeman::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion2");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Treeman::Replenish() const
{
	return new Treeman;
}
//========================================================================================================
//   Acolyte
//==========================================================================
bool Acolyte::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 50)
		return true;
	else
		return false;
}
Item*Acolyte::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Acolyte's Soul");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
Item* Acolyte::Token(string map)
{
	Item *token = new Item;
	token = loaditem("SoulCatcher");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Acolyte::Replenish() const
{
	return new Acolyte;
}

//========================================================================================================
//   Fire Demon
//==========================================================================
bool FireDemon::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 25)
		return true;
	else
		return false;
}
Item*FireDemon::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Fire Horn");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(100);
	return left;
}
Item* FireDemon::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion3");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* FireDemon::Replenish() const
{
	return new FireDemon;
}
// Watch out for new items while testing. Make sure you put them into the items file

//====================================================== ==================================================
//======================================================< skeleton >==========================================

bool Skeleton::DroppedItem()
{	
		return false;	
}
 Item* Skeleton::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Rib Bone");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
Creature* Skeleton::Replenish() const
{
	return new Skeleton;
}
//======================================================< Ghoul >==========================================

bool Ghoul::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 11)
		return true;
	else 
		return false;	
}
 Item* Ghoul::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Mangled Flesh");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
 Item* Ghoul::Token(string map)
{
	Item *token = new Item;
	token->SetName("Ghoul's Eye");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	token->SetCost(1000);
	return token;
}
Creature* Ghoul::Replenish() const
{
	return new Ghoul;
}
//====================================================== Ghost ================================================

 Item* Ghost::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Disembodied Soul");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
Creature* Ghost::Replenish() const
{
	return new Ghost;
}

//====================================================== Phantom ================================================
bool Phantom::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* Phantom::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Onyx Stone");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}

Item* Phantom::Token(string map)
{
	Item *token = new Item;
	token->SetName("Ruby Gem");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	token->SetCost(1000);
	return token;
}
Creature* Phantom::Replenish() const
{
	return new Phantom;
}
//====================================================== Vampire ==============================================
bool Vampire::DroppedItem()
{
	int num = rand()% 100 + 1;
	if(num < 15)
		return true;
	else 
		return false;	
}
Item* Vampire::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Vampire Fang");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(200);
	return left;
}

Item* Vampire::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
Creature* Vampire::Replenish() const
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

bool WoodPriest::DroppedItem()
{
	return true;	
}
 Item* WoodPriest::Token(string map)
{
	Item *token = new Item;
	token = loadWeapon("Slicer");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* WoodPriest::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void WoodPriest::Win(Player *p2)
{
	Creature::Win(p2);
	text("After defeating the Wood Priest you must travel north.",13,11,white);
	text("Past the forests to the frozen tundra.",13,12,white);
	p2->PlotEventStates.Priest1 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* WoodPriest::Replenish() const
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
bool IcePriest::DroppedItem()
{
	return true;	
}
 Item* IcePriest::Token(string map)
{
	Item *token = new Item;
	token = loadWeapon("Ice Sword");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* IcePriest::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void IcePriest::Win(Player *p2)
{
	Creature::Win(p2);
	text("After defeating the Ice Priest you must travel west.",13,11,white);
	text("Into the mountain and defeat the Fire Priest.",13,12,white);
	p2->PlotEventStates.Priest2 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* IcePriest::Replenish() const
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
bool FirePriest::DroppedItem()
{
	return true;	
}
 Item* FirePriest::Token(string map)
{
	Item *token = new Item;
	token = loadWeapon("Fire Sword");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* FirePriest::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void FirePriest::Win(Player *p2)
{
	Creature::Win(p2);
	text("After defeating the Fire Priest you must warp to the middle island.",13,11,white);
	text("Beneath the cemetary lies the teleporter.",13,12,white);
	p2->PlotEventStates.Priest3 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* FirePriest::Replenish() const
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
bool WindPriest::DroppedItem()
{
	return true;	
}
 Item* WindPriest::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion4");
	token->SetMapName(map);
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetKeep(true);
	return token;
}
Item* WindPriest::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void WindPriest::Win(Player *p2)
{
	Creature::Win(p2);
	text("After defeating the the 4 priests. You must find the truth.",13,11,white);
	text("Go thee to the ancient water temple.",13,12,white);
	p2->PlotEventStates.Priest4 = true;
	text("",79,23,white);
	Sleep(5000);	
}
Creature* WindPriest::Replenish() const
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
bool GodOfWar::DroppedItem()
{
	return false;	
}
Item* GodOfWar::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Sword");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void GodOfWar::Win(Player *p2)
{
	Creature::Win(p2);
	Sleep(3000);	
}

Creature* GodOfWar::Replenish() const
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
bool GodOfLife::DroppedItem()
{
	return false;	
}
Item* GodOfLife::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}

void GodOfLife::Win(Player *p2)
{
	Creature::Win(p2);
	Sleep(3000);	
}

Creature* GodOfLife::Replenish() const
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
bool GodOfChaos::DroppedItem()
{
	return false;	
}
Item* GodOfChaos::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void GodOfChaos::Win(Player *p2)
{
	Creature::Win(p2);
	Sleep(3000);	
}

Creature* GodOfChaos::Replenish() const
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
bool GodOfDeath::DroppedItem()
{
	return false;	
}
Item* GodOfDeath::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Robe");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
void GodOfDeath::Win(Player *p2)
{
	Creature::Win(p2);
	Sleep(3000);	
}

Creature* GodOfDeath::Replenish() const
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
bool GreenDragon::DroppedItem()
{
	return true;
}
Item*GreenDragon::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Green Scale");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* GreenDragon::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("GreenMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
void GreenDragon::Win(Player *p2)
{
	Creature::Win(p2);
	text("The Green Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the island.",13,12,white);
	Sleep(3000);	
}

Creature* GreenDragon::Replenish() const
{
	return new Goblin;
}

void GreenDragon::banter()
{
}
//==========================================================================
//   Blue Dragon
//==========================================================================
bool BlueDragon::DroppedItem()
{
	return true;
}
Item*BlueDragon::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Blue Scale");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* BlueDragon::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("BlueMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
void BlueDragon::Win(Player *p2)
{
	Creature::Win(p2);
	text("The Blue Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the tundra.",13,12,white);
	Sleep(3000);	
}
Creature* BlueDragon::Replenish() const
{
	return new Goblin;
}
void BlueDragon::banter()
{
}
//==========================================================================
//   Red Dragon
//==========================================================================
bool RedDragon::DroppedItem()
{
	return true;
}
Item*RedDragon::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Red Scale");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* RedDragon::Token(string map)
{
	Item *token = new Item;
	token = loadArmor("RedMail");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
void RedDragon::Win(Player *p2)
{
	Creature::Win(p2);
	text("The Red Dragon lies vanquished. ",13,11,white);
	text("Peace begins to return to the mountains.",13,12,white);
	Sleep(3000);	
}
Creature* RedDragon::Replenish() const
{
	return new Goblin;
}
void RedDragon::banter()
{
}
//==========================================================================
//  Fly
//==========================================================================
bool Fly::DroppedItem()
{
	return false;
}
Item*Fly::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Dead Fly");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(0);
	return left;
}
Creature* Fly::Replenish() const
{
	return new Fly;
}
//==========================================================================
//   Monk
//==========================================================================
bool Monk::DroppedItem()
{
	return true;
}
Item*Monk::Body(string map) const
{
	Item *left = new Item;
	left->SetName("Monk's Cowl");
	left->SetMapName(map);
	left->SetPositionX(X);
	left->SetPositionY(Y);
	left->SetKeep(true);
	left->SetCost(5000);
	return left;
}
Item* Monk::Token(string map)
{
	Item *token = new Item;
	token = loaditem("Potion");
	token->SetPositionX(X);
	token->SetPositionY(Y);
	token->SetMapName(map);
	return token;
}
void Monk::Win(Player *p2)
{
	Creature::Win(p2);
	text("The peaceful monk lies vanquished. ",13,11,white);
	text("Don't you feel better about yourself now?",13,11,white);
	Sleep(3000);	
}
Creature* Monk::Replenish() const
{
	return new Fly;
}

void Monk::banter()
{
}