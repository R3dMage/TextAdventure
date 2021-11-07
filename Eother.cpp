#include <Windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"
#include "World.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
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
string Elf::Token()
{
	return "Potion";
}

void Elf::Win(Player *p2)
{	
	p2->SetReactionElf(1);
	p2->RaceKillCounts.ElfKillCount += 1;
	if(p2->RaceKillCounts.OrcKillCount == 0)
		p2->SetReactionOrc(3);
	
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
string ElvenMage::Token()
{
	return "Refresh";
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
string ElvenWarrior::Token()
{
	return "Elvenchain";
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
string FireElf::Token()
{
	return "Potion2";
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
string IceElf::Token()
{
	return "Potion2";
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
string ranger::Token()
{
	int num = rand()% 6 + 1;
	string token;
	switch(num)
	{
	case 1:
		token = "elvenchain";
		break;
	case 2:
		token = "ElfBlade";
		break;
	case 3:
	default:
		token = "Potion2";
		break;
	}

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
string Orc::Token()
{
	return "Potion";
}

void Orc::Win(Player *p2)
{
	p2->SetReactionOrc(1);
	p2->RaceKillCounts.OrcKillCount += 1;
	if(p2->RaceKillCounts.ElfKillCount == 0)
		p2->SetReactionElf(3);
	
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
string OrcSorceror::Token()
{
	return "Refresh";
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
string OrcSoldier::Token()
{
	return "Orc_Mail";
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
string FireOrc::Token()
{
	return "Potion2";
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
string IceOrc::Token()
{
	return "Potion2";
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
string OrcWanderer::Token()
{
	int num = rand()% 6 + 1;
	string token;
	switch(num)
	{
	case 1:
		token = "OrcMail";
		break;
	case 2:
		token = "OrcBlade";
		break;
	case 3:
	default:
		token = "Potion2";
		break;
	}
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
string Human::Token()
{
	return "Potion";
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
	p2->RaceKillCounts.HumanKillCount += 1;
	if(p2->RaceKillCounts.HumanKillCount == 5)
	{//                                       65
		text("                                                           ",13,9,white);
		text("A price has now been put on your head. You're a wanted man.",13,9,white);
		Sleep(3000);
		
		p2->SetReactionHuman(1);
	}
	
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
string Knight::Token()
{
	int num = rand()% 3 + 1;
	string token;
	switch (num)
	{
	case 1:
		token = "Hvy.Chain";
		break;
	case 2:
		token = "Claymore";
		break;
	case 3:
		token = "Potion2";
		break;
	}
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
string Adventurer::Token()
{
	int num = rand()% 3 + 1;
	string token;
	switch(num)
	{
	case 1:
		token = "Hvy.Chain";
		break;
	case 2:
		token = "+1 Claymore";
		break;
	case 3:
		token = "Potion2";
		break;
	}
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
string Wizard::Token()
{
	return "Refresh";
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
string Goblin::Token()
{
	return "Potion";
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
string Gargoyle::Token()
{
	return "Potion";
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
string Margoyle::Token()
{
	return "Potion3";
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
string Stargoyle::Token()
{
	return "Potion4";
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
 string Ogre::Token()
{
	 return "Potion2";
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
string Troll::Token()
{
	return "TrollSword";
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
string Magmaman::Token()
{
	return "Potion3";
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
string Cyclops::Token()
{
	return "Potion2";
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
string Giant::Token()
{
	return "Potion2";
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
string FrostGiant::Token()
{
	return "Potion2";
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
string StormGiant::Token()
{
	int R = rand()% 4 + 1;
	string token;
	if(R == 4)
		token = "Storm Shroud";
	if(R < 4)
		token = "StormSword";
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
string Nymph::Token()
{
	return "Refresh";
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
string IceWizard::Token()
{
	return "Refresh";
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
string Snowman::Token()
{
	return "Refresh";
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
string ShrineGuard::Token()
{
	return "IceChain";
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
string RockGolem::Token()
{
	return "Potion2";
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
string IronGolem::Token()
{
	return "Potion2";
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
string SteelGolem::Token()
{
	return "Potion3";
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
string Treeman::Token()
{
	return "Potion2";
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
string Acolyte::Token()
{
	return "SoulCatcher";
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
string FireDemon::Token()
{
	return "Potion3";
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
	return false;	
}
 Item* Ghoul::Body(string map) const
{
	Item *left = new Item;

	int num = rand() % 100 + 1;
	if (num < 11)
	{
		left->SetName("Ghoul's Eye");
		left->SetMapName(map);
		left->SetPositionX(X);
		left->SetPositionY(Y);
		left->SetKeep(true);
		left->SetCost(1000);
	}
	else
	{
		left->SetName("Mangled Flesh");
		left->SetMapName(map);
		left->SetPositionX(X);
		left->SetPositionY(Y);
		left->SetKeep(true);
		left->SetCost(0);
	}

	return left;
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
	return false;
}
Item* Phantom::Body(string map) const
{
	Item *left = new Item;

	int num = rand() % 100 + 1;
	if (num < 15)
	{
		left->SetName("Ruby Gem");
		left->SetMapName(map);
		left->SetPositionX(X);
		left->SetPositionY(Y);
		left->SetKeep(true);
		left->SetCost(1000);
	}		
	else
	{
		left->SetName("Onyx Stone");
		left->SetMapName(map);
		left->SetPositionX(X);
		left->SetPositionY(Y);
		left->SetKeep(true);
		left->SetCost(200);
	}
		

	return left;
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

string Vampire::Token()
{
	return "Potion4";
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
 string WoodPriest::Token()
{
	return "Slicer";
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
vector<string> WoodPriest::Banter()
{
	vector<string> speech;
	speech.push_back("Who are you!?");
	speech.push_back("You insignificant maggot. So you think you can aid the");
	speech.push_back("gods? Your fate will be decided now!");
	speech.push_back("When I CRUSH YOU!!!");
	return speech;
}

//==========================================================================
//   Ice Priest
//==========================================================================
bool IcePriest::DroppedItem()
{
	return true;	
}
 string IcePriest::Token()
{
	return "Ice Sword";
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
vector<string> IcePriest::Banter()
{
	vector<string> speech;
	speech.push_back("So... You defeated the priest of the wood.");
	speech.push_back("You may be formidable, but you are no match for me.");
	speech.push_back("And anyway, I thought you would be...");
	speech.push_back("       ...taller.");
	return speech;
}
//==========================================================================
//   Fire Priest
//==========================================================================
bool FirePriest::DroppedItem()
{
	return true;	
}
 string FirePriest::Token()
{
	return "Fire Sword";
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
vector<string> FirePriest::Banter()
{
	vector<string> speech;
	speech.push_back("You are disrupting everything! You fool! Don't you realize!?");
	speech.push_back("Your power comes from the gods. They can take it away from you");
	speech.push_back("once you've accomplished their goals! You're being USED!!!!");
	return speech;
}
//==========================================================================
//   Wind Priest
//==========================================================================
bool WindPriest::DroppedItem()
{
	return true;	
}
 string WindPriest::Token()
{
	return "Potion4";
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

vector<string> WindPriest::Banter()
{
	vector<string> speech;
	speech.push_back("Your power may be great, however, you will not last long.");
	speech.push_back("This devilish island will be your grave.");
	return speech;
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
vector<string> GodOfWar::Banter()
{
	vector<string> speech;
	speech.push_back("You have served me well human. However, your power is now");
	speech.push_back("far too great. Becuase you threaten the power of the gods");
	speech.push_back("I must now dispose of you. Kind of like a paper plate!");
	return speech;
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

vector<string> GodOfLife::Banter()
{
	vector<string> speech;
	speech.push_back("Your power has become great. I believe you can rule the gods!");
	speech.push_back("To test your mettle, you must defeat me, and take my place as");
	speech.push_back("the god of life. Only then can you ensure peace for all.");
	return speech;
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
vector<string> GodOfChaos::Banter()
{
	vector<string> speech;
	speech.push_back("Our alliance was an uneasy one from the beginning.");
	speech.push_back("Now is the time to see who can really rule the world!");
	return speech;
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

vector<string> GodOfDeath::Banter()
{
	vector<string> speech;
	speech.push_back("I usually reward my servants well. You, however, have grown quite");
	speech.push_back("powerful. If I were to slay you and absorb your power...");
	speech.push_back("... I could rise from my pit and rule the overworld as well!");
	speech.push_back("So, don't think of it as betrayal. Think of it as another fight.");
	return speech;
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
string GreenDragon::Token()
{
	return "GreenMail";
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
string BlueDragon::Token()
{
	return "BlueMail";
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
string RedDragon::Token()
{
	return "RedMail";
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
string Monk::Token()
{
	return "Potion";
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

vector<string> Monk::Banter()
{
	vector<string> speech;
	speech.push_back("You could find no peaceful way?");
	return speech;
}