#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings

#include "Enemies.h"
#include "World.h"

//=============================================================================================================
//												Elves
//=============================================================================================================

Elf::Elf()
{
	Name = "Elf";
	Level =		2;
	Damage =	6;
	DamageModifier =	5;
	HitPoints = MaxHP =  40;
	Ka = MaxKa =  10;
	Evade =		8;
	Gold =		30; 
	Experience =		25;
	CanTalkTo =	true; 
}

ElvenMage::ElvenMage()
{
	Name = "Elven Mage";
	Level =		4;
	Damage =	10;
	DamageModifier =	10;
	HitPoints = MaxHP =  58;
	Ka = MaxKa =	20;
	MagicDefense =	20;
	Evade =		10;
	Gold =		100;
	Experience =		100;
	CanTalkTo =	true;
}

ElvenWarrior::ElvenWarrior()
{
	Name = "Elven Warrior";
	Level =		4;
	Damage =	20;
	DamageModifier =	10;
	HitPoints = MaxHP =  65;
	Ka = MaxKa =  10;
	Defense =		3;
	MagicDefense =	5;
	Evade =		10;
	Gold =		100;
	Experience =		100;
	CanTalkTo =	true;
}
FireElf::FireElf()
{
	Name = "Fire Elf";
	Level =		8;
	Damage =	35;
	DamageModifier =	20;
	Defense =		10;
	HitPoints = MaxHP =  100;
	Ka = MaxKa =  25;
	Defense =		10;
	MagicDefense =	15;
	Evade =		10;
	Gold =		400;
	Experience =		400;
	CanTalkTo =	true;
	Weakness =	"ice";
}
IceElf::IceElf()
{
	Name = "Ice Elf";
	Level =		6;
	Damage =	20;
	DamageModifier =	20;
	Defense =		8;
	MagicDefense =	15;
	HitPoints = MaxHP =  85;
	Ka = MaxKa =  20;
	Defense =		6;
	Evade =		12;
	Gold =		300;
	Experience =		300;
	CanTalkTo =	true;
	Weakness =	"fire";
}
ranger::ranger()
{
	Name = "Elven Ranger";
	Level =		rand()% 3 + 6;
	switch(Level)
	{
	case 6:
	case 7:
		Damage = 15;	DamageModifier = 15;	Defense = 7; MagicDefense =	15;
		HitPoints = MaxHP = 110;	Gold = 190;	Experience = 225;
		break;
	case 8:
		Damage = 15; DamageModifier = 20;	Defense = 9; MagicDefense =	15;
		HitPoints = MaxHP = 180;	Gold = 260;	Experience = 350;
		break;
	case 9:
		Damage = 20; DamageModifier = 20;	Defense = 12; MagicDefense =	20;
		HitPoints = MaxHP = 200;	Gold = 400;	Experience = 400;
		break;
	}
	Ka = MaxKa =  20;
	Evade =		8;
	CanTalkTo =	true;
}
//=============================================================================================================
//												Orcs
//=============================================================================================================
Orc::Orc()
{
	Name = "Orc";
	Level =		2;
	Damage =	7;
	DamageModifier =	8;
	HitPoints = MaxHP =	40;
	Evade =		4;
	Gold =		60;
	Experience =		25;
	CanTalkTo =	true;
}

OrcSorceror::OrcSorceror()
{
	Name = "Orc Sorceror";
	Level =		4;
	Damage =	10;
	DamageModifier =	10;
	HitPoints = MaxHP =	58;
	Ka = MaxKa =	20;
	MagicDefense =	20;
	Evade =		4;
	Gold =		250;
	Experience =		100;
	CanTalkTo =	true;
}

OrcSoldier::OrcSoldier()
{
	Name = "Orc Soldier";
	Level =		4;
	Damage =	30;
	DamageModifier =	10;
	HitPoints = MaxHP =	65;
	Ka = MaxKa =  10;
	Evade =		4;
	Gold =		250;
	Experience =		100;
	Defense =		5;
	CanTalkTo =	true;
}
FireOrc::FireOrc()
{
	Name = "Fire Orc";
	Level = 8;
	Damage = 30;
	DamageModifier = 20;
	HitPoints = MaxHP = 200;
	Ka = MaxKa = 30;
	MagicDefense =	10;
	Evade = 10;
	Gold = 250;
	Experience = 185;
	Weakness = "ice";
}
IceOrc::IceOrc()
{
	Name = "Ice Orc";
	Level = 6;
	Damage = 20;
	DamageModifier = 20;
	HitPoints = MaxHP = 150;
	Ka = MaxKa = 20;
	MagicDefense =	10;
	Evade = 8;
	Gold = 100;
	Experience = 105;
	Weakness = "fire";
}
OrcWanderer::OrcWanderer()
{
	Name = "Orc Wanderer";
	Level =		rand()% 3 + 6;
	switch(Level)
	{
	case 6:
		Damage = 11;	DamageModifier = 10;	Defense = 7;
		HitPoints = MaxHP = 100;	Gold = 220;	Experience = 225;
		break;
	case 7:
	case 8:
		Damage = 15; DamageModifier = 15;	Defense = 9; MagicDefense =	5;
		HitPoints = MaxHP = 120;	Gold = 260;	Experience = 250;
		break;
	case 9:
		Damage = 20; DamageModifier = 20;	Defense = 11; MagicDefense =	10;
		HitPoints = MaxHP = 180;	Gold = 400;	Experience = 400;
		break;
	}
	Ka = MaxKa =  20;
	Evade =		4;
	CanTalkTo =	true;
}
//=============================================================================================================
//												Humans
//=============================================================================================================
Human::Human()
{
	Name = "Human Peasant";
	Level =		2;
	Damage =	8;
	DamageModifier =	3;
	HitPoints = MaxHP =	30;
	Ka = MaxKa =  0;
	Evade =		6;
	Gold =		20;
	Experience =		10;
	Defense =		0;
	CanTalkTo =	true;
}

Knight::Knight()
{
	Name = "Human Knight";
	Level =		rand()% 5 + 5;
	switch(Level)
	{
	case 5:
	case 6:
		Damage = 11;	DamageModifier = 6;	Defense = 7; MagicDefense =	10;
		HitPoints = MaxHP = 70;	Gold = 120;	Experience = 125;
		break;
	case 7:
	case 8:
		Damage = 15; DamageModifier = 8;	Defense = 9; MagicDefense =	15;
		HitPoints = MaxHP = 120;	Gold = 160;	Experience = 150;
		break;
	case 9:
	case 10:
		Damage = 20; DamageModifier = 10;	Defense = 11; MagicDefense =	20;
		HitPoints = MaxHP = 160;	Gold = 200;	Experience = 200;
		break;
	}
	Ka = MaxKa =  0;
	Evade =		4;
	CanTalkTo =	true;
}

Adventurer::Adventurer()
{	
	CanTalkTo =	true;
}

Wizard::Wizard()
{
	Name = "Human Wizard";
	Level =		6;
	Damage =	20;
	DamageModifier =	20;
	HitPoints = MaxHP =	90;
	Ka = MaxKa =  30;
	Evade =		6;
	Gold =		20;
	Experience =		10;
	Defense =		0;
	MagicDefense =	20;
	CanTalkTo =	true;
}
//=============================================================================================================
//											Semi-intelligent races
//=============================================================================================================
Goblin::Goblin()
{
	Name = "Goblin";
	Level =		1;
	Damage =	6;
	DamageModifier =	4;
	HitPoints = MaxHP = 10;
	Defense = 2;
	Evade =		4;
	Gold =		20;
	Experience =		5;
}
Ogre::Ogre()
{
	Name =		"Ogre";
	Level =		3;
	Damage =	10;
	DamageModifier =	10;
	HitPoints = MaxHP =	60;
	Defense = 10;
	MagicDefense = 5;
	Evade =		3;
	Gold =		45;
	Experience =		35;
}
Troll::Troll()
{
	Name =		"Troll";
	Level =		3;
	Damage =	10;
	DamageModifier =	5;
	HitPoints = MaxHP =	55;
	Defense = 5;
	MagicDefense = 10;
	Evade =		6;
	Gold =		40;
	Experience =		35;
}
Magmaman::Magmaman()
{
	Name = "Magma Man";
	Level = 8;
	Damage = 30;
	DamageModifier = 30;
	HitPoints = MaxHP = 350;
	Defense = 30;
	MagicDefense = 5;
	Evade = 3;
	Gold = 245;
	Experience = 300;
	Weakness = "ice";
}
Cyclops::Cyclops()
{
	Name = "Cyclops";
	Level = 9;
	Damage = 30;
	DamageModifier = 20;
	HitPoints = MaxHP = 200;
	Defense = 20;
	MagicDefense = 10;
	Evade = 5;
	Gold = 250;
	Experience = 350;
}
Giant::Giant()
{
	Name = "Giant";
	Level = 7;
	Damage = 20;
	DamageModifier = 10;
	HitPoints = MaxHP = 95;
	Defense = 15;
	Evade = 4;
	Gold = 200;
	Experience = 100;
}
FrostGiant::FrostGiant()
{
	Name = "Frost Giant";
	Level = 8;
	Damage = 27;
	DamageModifier = 13;
	HitPoints = MaxHP = 125;
	Defense = 25;
	MagicDefense = 35;
	Evade = 3;
	Gold = 225;
	Experience = 135;
	Weakness = "fire";
}
StormGiant::StormGiant()
{
	Name = "Storm Giant";
	Level = 12;
	Damage = 40;
	DamageModifier = 20;
	HitPoints = MaxHP = 400;
	Defense = 35;
	MagicDefense = 35;
	Evade = 3;
	Gold = 400;
	Experience = 500;
}
Nymph::Nymph()
{
	Name = "Forest Nymph";
	Level = 4;
	Damage = 10;
	DamageModifier = 10;
	HitPoints = MaxHP = 40;
	MagicDefense = 50;
	Evade = 10;
	Gold = 40;
	Experience = 60;
}
IceWizard::IceWizard()
{
	Name = "Ice Wizard";
	Level = 6;
	Damage = 10;
	DamageModifier = 1;
	HitPoints = MaxHP = 75;
	MagicDefense = 60;
	Evade = 8;
	Gold = 200;
	Experience = 75;
}
Snowman::Snowman()
{
	Name = "Snowman";
	Level = 5;
	Damage = 15;
	DamageModifier = 15;
	HitPoints = MaxHP = 100;
	Defense = 15;
	MagicDefense = 50;
	Evade = 5;
	Gold = 13;
	Experience = 65;
	Weakness = "fire";
}
ShrineGuard::ShrineGuard()
{
	Name = "Shrine Guardian";
	Level = 8;
	Damage = 25;
	DamageModifier = 20;
	Defense = 15;
	HitPoints = MaxHP = 125;
	Defense = 40;
	Evade = 15;
	Gold = 200;
	Experience = 175;
}
RockGolem::RockGolem()
{
	Name = "Rock Golem";
	Level = 7;
	Damage = 25;
	DamageModifier = 22;
	Defense = 10;
	HitPoints = MaxHP = 200;
	MagicDefense = 10;
	Evade = 1;
	Gold = 200;
	Experience = 165;
}
IronGolem::IronGolem()
{
	Name = "Iron Golem";
	Level = 9;
	Damage = 40;
	DamageModifier = 33;
	Defense = 30;
	HitPoints = MaxHP = 500;
	MagicDefense = 10;
	Evade = 1;
	Gold = 500;
	Experience = 450;
}
SteelGolem::SteelGolem()
{
	Name = "Steel Golem";
	Level = 16;
	Damage = 100;
	DamageModifier = 10;
	Defense = 50;
	HitPoints = MaxHP = 800;
	MagicDefense = 15;
	Evade = 1;
	Gold = 1000;
	Experience = 1000;
}
Treeman::Treeman()
{
	Name = "Treeman";
	Level = 6;
	Damage = 30;
	DamageModifier = 10;
	HitPoints = MaxHP = 75;
	Defense = 10;
	MagicDefense = 10;
	Evade = 3;
	Gold = 30;
	Experience = 80;
	Weakness = "fire";
}
Acolyte::Acolyte()
{
	Name = "Acolyte";
	Level = 1;
	Damage = 1;
	DamageModifier = 1;
	HitPoints = MaxHP = 1;
	Evade = 1;
	Gold = 1;
	Experience = 1;
}
//=============================================================================================================
//												Wild Life
//=============================================================================================================
GiantSpider::GiantSpider()
{
	Name = "Giant Spider";
	Level =		2;
	Damage =	7;
	DamageModifier =	4;
	HitPoints = MaxHP =  20;
	Evade =		5;
	Gold =		0;
	Experience =		10;
	Defense =		1;
}

Wolf::Wolf()
{
	Name = "Rabid Wolf";
	Level =		1;
	Damage =	6;
	DamageModifier =	3;
	HitPoints = MaxHP =	8;
	Evade =		5;
	Gold =		0;
	Experience =		5;
}

Raven::Raven()
{
	Name = "Wild Raven";
	Level =		1;
	Damage =	6;
	DamageModifier =	3;
	HitPoints = MaxHP =	8;
	Evade =		5;
	Gold =		0;
	Experience =		5;
}
Snake::Snake()
{
	Name = "Big Snake";
	Level =		1;
	Damage =	4;
	DamageModifier =	3;
	HitPoints = MaxHP =	10;
	Evade =		5;
	Gold =		0;
	Experience =		5;
}
Eagle::Eagle()
{
	Name = "Giant Eagle";
	Level =		4;
	Damage =	15;
	DamageModifier =	8;
	HitPoints = MaxHP =	45;
	Evade =		10;
	Gold =		0;
	Experience =		50;
}
PolarBear::PolarBear()
{
	Name = "Polar Bear";
	Level =		5;
	Damage =	23;
	DamageModifier =	13;
	HitPoints = MaxHP =	75;
	Evade =		5;
	Gold =		0;
	Experience =		100;
	Weakness = "fire";
}
Salamander::Salamander()
{
	Name = "Salamander";
	Level =		6;
	Damage =	20;
	DamageModifier =	25;
	HitPoints = MaxHP =	200;
	MagicDefense =	15;
	Evade =		5;
	Gold =		0;
	Experience =		250;
	Weakness =  "ice";
}
FireDemon::FireDemon()
{
	Name = "Fire Demon";
	Level =		10;
	Damage =	30;
	DamageModifier =	25;
	HitPoints = MaxHP =	250;
	Defense		=	20;
	MagicDefense	=	20;
	Evade =		5;
	Gold =		100;
	Experience =		300;
	Weakness =  "ice";
}
Centipede::Centipede()
{
	Name = "Giant Centipede";
	Level =		10;
	Damage =	40;
	DamageModifier =	40;
	HitPoints = MaxHP =	450;
	Evade =		5;
	Gold =		0;
	Experience =		500;
}
Wyvern::Wyvern()
{
	Name = "Wyvern";
	Level =		11;
	Damage =	40;
	DamageModifier =	40;
	HitPoints = MaxHP =	400;
	Defense =		20;
	MagicDefense =	20;
	Evade =		20;
	Gold =		0;
	Experience =		400;
}
Hydra::Hydra()
{
	Name = "Hydra";
	Level =		11;
	Damage =	60;
	DamageModifier =	40;
	HitPoints = MaxHP =	450;
	Defense =		35;
	MagicDefense =	35;
	Evade =		10;
	Gold =		0;
	Experience =		500;
}
Minotaur::Minotaur()
{
	Name = "Minotaur";
	Level =		14;
	Damage =	70;
	DamageModifier =	50;
	HitPoints = MaxHP =	565;
	Defense =		45;
	MagicDefense =	45;
	Evade =		5;
	Gold =		400;
	Experience =		560;
}
Gargoyle::Gargoyle()
{
	Name = "Gargoyle";
	Level =		6;
	Damage =	20;
	DamageModifier =	10;
	HitPoints = MaxHP =	100;
	Evade =		50;
	Gold =		28;
	Experience =		97;
}
Margoyle::Margoyle()
{
	Name = "Margoyle";
	Level = 12;
	Damage = 40;
	DamageModifier = 20;
	HitPoints = MaxHP = 200;
	Defense = 15;
	MagicDefense = 15;
	Evade = 25;
	Gold = 56;
	Experience = 250;
}
Stargoyle::Stargoyle()
{
	Name = "Stargoyle";
	Level = 24;
	Damage = 80;
	DamageModifier = 40;
	HitPoints = MaxHP = 400;
	Defense = 20;
	MagicDefense = 20;
	Evade = 12;
	Gold = 102;
	Experience = 1000;
	Weakness = "lightning";
}

//=============================================================================================================
//												Undead
//=============================================================================================================
Skeleton::Skeleton()
{
	Name = "Skeleton";
	Level =		2;
	Damage =	7;
	DamageModifier =	3;
	HitPoints = MaxHP =	20;
	Evade =		9;
	Gold =		0;
	Experience =		25;
	Type =		"undead";
}

Ghoul::Ghoul()
{
	Name = "Ghoul";
	Level =		2;
	Damage =	10;
	DamageModifier =	5;
	HitPoints = MaxHP = 25;
	Evade =		4;
	Gold =		0;
	Experience =		35;
	Type =		"undead";
}

Ghost::Ghost()
{
	Name = "Ghost";
	Level =		6;
	Damage =	10;
	DamageModifier =	10;
	HitPoints = MaxHP =	35;
	Evade =		40;
	Gold =		0;
	Experience =		150;
	Type =		"undead";
}

Phantom::Phantom()
{
	Name = "Phantom";
	Level = 4;
	Damage = 20;
	DamageModifier = 10;
	HitPoints = MaxHP = 70;
	Evade = 5;
	Gold = 0;
	Experience = 100;
	Type = "undead";
}

Vampire::Vampire()
{
	Name = "Vampire";
	Level = 12;
	Damage = 50;
	DamageModifier = 50;
	HitPoints = MaxHP = 275;
	MagicDefense = 75;
	Evade = 15;
	Gold = 500;
	Experience = 500;
	Type = "undead";
}

//=============================================================================================================
//												Bosses
//=============================================================================================================
WoodPriest::WoodPriest()
{
	Name = "Wood Priest";
	Level = 15;
	Damage = 25;
	DamageModifier = 25;
	HitPoints = MaxHP = 200;
	Ka = MaxKa = 35;
	Defense = 20;
	MagicDefense = 15;
	Evade = 15;
	Gold = 350;
	Experience = 400;
	DontMove = true;
	bant = true;
}

IcePriest::IcePriest()
{
	Name = "Ice Priest";
	Level = 20;
	Damage = 30;
	DamageModifier = 30;
	HitPoints = MaxHP = 400;
	Ka = MaxKa = 175;
	Defense = 25;
	MagicDefense = 20;
	Evade = 15;
	Gold = 500;
	Experience = 750;
	DontMove = true;
	bant = true;
}

FirePriest::FirePriest()
{
	Name = "Fire Priest";
	Level = 25;
	Damage = 50;
	DamageModifier = 50;
	HitPoints = MaxHP = 600;
	Ka = MaxKa = 225;
	Defense = 30;
	MagicDefense = 35;
	Evade = 15;
	Gold = 1000;
	Experience = 1500;
	DontMove = true;
	bant = true;
}

WindPriest::WindPriest()
{
	Name = "Wind Priest";
	Level = 30;
	Damage = 75;
	DamageModifier = 50;
	HitPoints = MaxHP = 800;
	Ka = MaxKa = 300;
	Defense = 35;
	MagicDefense = 40;
	Evade = 15;
	Gold = 2000;
	Experience = 2500;
	bant = true;
}

GodOfWar::GodOfWar()
{
	Name = "God of War";
	Level = 99;
	Damage = 200;
	DamageModifier = 50;
	Defense = 75;
	HitPoints = MaxHP = 4000;
	Ka = MaxKa = 300;
	Defense = 55;
	Evade = 15;
	Gold = 0;
	Experience = 0;
	DontMove = true;
	bant = true;
}

GodOfLife::GodOfLife()
{
	Name = "God of Life";
	Level = 99;
	Damage = 100;
	DamageModifier = 50;
	HitPoints = MaxHP = 3000;
	Ka = MaxKa = 300;
	Defense = 10;
	MagicDefense = 50;
	Ka = 200;
	Evade = 25;
	Gold = 0;
	Experience = 0;
	DontMove = true;
	bant = true;
}

GodOfChaos::GodOfChaos()
{
	Name = "God of Chaos";
	Level = 99;
	Damage = 100;
	DamageModifier = 50;
	HitPoints = MaxHP = 3500;
	Ka = MaxKa = 300;
	Ka = 100;
	Defense = 60;
	MagicDefense = 20;
	Evade = 15;
	Gold = 0;
	Experience = 0;
	DontMove = true;
	bant = true;
}

GodOfDeath::GodOfDeath()
{
	Name = "God of Death";
	Level = 99;
	Damage = 200;
	DamageModifier = 100;
	HitPoints = MaxHP = 5000;
	Ka = MaxKa = 200;
	Defense = 60;
	MagicDefense = 60;
	Evade = 15;
	Gold = 0;
	Experience = 0;
	DontMove = true;
	bant = true;
}


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

Monk::Monk()
{
	Name = "Peaceful Monk";
	Level = 69;
	Damage = 10;
	DamageModifier = 10;
	Defense = 75;
	HitPoints = MaxHP = 125;
	MagicDefense = 95;
	Evade = 95;
	Gold = 0;
	Experience = 9999;
	Map = "field2";
	bant = true;
}
Fly::Fly()
{
	Name = "Fly";
	Level = 0;
	Damage = 2;
	DamageModifier = 2;
	HitPoints = MaxHP = 10;
	Evade = 0;
	Gold = 0;
	Experience = 0;
}
GreenDragon::GreenDragon()
{
	Name = "Green Dragon";
	Level = 80;
	Damage = 50;
	DamageModifier = 50;
	HitPoints = MaxHP = 2000;
	Evade = 15;
	Defense = 50;
	MagicDefense = 50;
	Gold = 6000;
	Experience = 2000;
	DontMove = true;
	bant = true;
}

BlueDragon::BlueDragon()
{
	Name = "Blue Dragon";
	Level = 80;
	Damage = 50;
	DamageModifier = 50;
	HitPoints = MaxHP = 2000;
	Defense = 50;
	MagicDefense = 50;
	Evade = 15;
	Gold = 6000;
	Experience = 2000;
	DontMove = true;
	bant = true;
}

RedDragon::RedDragon()
{
	Name = "Red Dragon";
	Level = 80;
	Damage = 50;
	DamageModifier = 50;
	HitPoints = MaxHP = 2000;
	Defense = 50;
	MagicDefense = 50;
	Evade = 15;
	Gold = 6000;
	Experience = 2000;
	DontMove = true;
	bant = true;
}

/*
{
	name = ;
	level = ;
	damage = ;
	damMod = ;
	hp = mhp = ;
	evade = ;
	gold = ;
	exp = ;
}
*/