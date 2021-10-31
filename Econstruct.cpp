#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"
#include "World.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define blue FOREGROUND_BLUE

//=============================================================================================================
//												Elves
//=============================================================================================================

elf::elf()
{
	name = "Elf";
	level =		2;
	damage =	6;
	damMod =	5;
	hp = mhp =  40;
	ka = mka =  10;
	evade =		8;
	gold =		30; 
	exp =		25;
	talkTo =	true; 
}

mage::mage()
{
	name = "Elven Mage";
	level =		4;
	damage =	10;
	damMod =	10;
	hp = mhp =  58;
	ka = mka =	20;
	magdef =	20;
	evade =		10;
	gold =		100;
	exp =		100;
	talkTo =	true;
}

warrior::warrior()
{
	name = "Elven Warrior";
	level =		4;
	damage =	20;
	damMod =	10;
	hp = mhp =  65;
	ka = mka =  10;
	def =		3;
	magdef =	5;
	evade =		10;
	gold =		100;
	exp =		100;
	talkTo =	true;
}
fireelf::fireelf()
{
	name = "Fire Elf";
	level =		8;
	damage =	35;
	damMod =	20;
	def =		10;
	hp = mhp =  100;
	ka = mka =  25;
	def =		10;
	magdef =	15;
	evade =		10;
	gold =		400;
	exp =		400;
	talkTo =	true;
	weakness =	"ice";
}
iceelf::iceelf()
{
	name = "Ice Elf";
	level =		6;
	damage =	20;
	damMod =	20;
	def =		8;
	magdef =	15;
	hp = mhp =  85;
	ka = mka =  20;
	def =		6;
	evade =		12;
	gold =		300;
	exp =		300;
	talkTo =	true;
	weakness =	"fire";
}
ranger::ranger()
{
	name = "Elven Ranger";
	level =		rand()% 3 + 6;
	switch(level)
	{
	case 6:
	case 7:
		damage = 15;	damMod = 15;	def = 7; magdef =	15;
		hp = mhp = 110;	gold = 190;	exp = 225;
		break;
	case 8:
		damage = 15; damMod = 20;	def = 9; magdef =	15;
		hp = mhp = 180;	gold = 260;	exp = 350;
		break;
	case 9:
		damage = 20; damMod = 20;	def = 12; magdef =	20;
		hp = mhp = 200;	gold = 400;	exp = 400;
		break;
	}
	ka = mka =  20;
	evade =		8;
	talkTo =	true;
}
//=============================================================================================================
//												Orcs
//=============================================================================================================
Orc::Orc()
{
	name = "Orc";
	level =		2;
	damage =	7;
	damMod =	8;
	hp = mhp =	40;
	evade =		4;
	gold =		60;
	exp =		25;
	talkTo =	true;
}

sorceror::sorceror()
{
	name = "Orc Sorceror";
	level =		4;
	damage =	10;
	damMod =	10;
	hp = mhp =	58;
	ka = mka =	20;
	magdef =	20;
	evade =		4;
	gold =		250;
	exp =		100;
	talkTo =	true;
}

osoldier::osoldier()
{
	name = "Orc Soldier";
	level =		4;
	damage =	30;
	damMod =	10;
	hp = mhp =	65;
	ka = mka =  10;
	evade =		4;
	gold =		250;
	exp =		100;
	def =		5;
	talkTo =	true;
}
fireorc::fireorc()
{
	name = "Fire Orc";
	level = 8;
	damage = 30;
	damMod = 20;
	hp = mhp = 200;
	ka = mka = 30;
	magdef =	10;
	evade = 10;
	gold = 250;
	exp = 185;
	weakness = "ice";
}
iceorc::iceorc()
{
	name = "Ice Orc";
	level = 6;
	damage = 20;
	damMod = 20;
	hp = mhp = 150;
	ka = mka = 20;
	magdef =	10;
	evade = 8;
	gold = 100;
	exp = 105;
	weakness = "fire";
}
wanderer::wanderer()
{
	name = "Orc Wanderer";
	level =		rand()% 3 + 6;
	switch(level)
	{
	case 6:
		damage = 11;	damMod = 10;	def = 7;
		hp = mhp = 100;	gold = 220;	exp = 225;
		break;
	case 7:
	case 8:
		damage = 15; damMod = 15;	def = 9; magdef =	5;
		hp = mhp = 120;	gold = 260;	exp = 250;
		break;
	case 9:
		damage = 20; damMod = 20;	def = 11; magdef =	10;
		hp = mhp = 180;	gold = 400;	exp = 400;
		break;
	}
	ka = mka =  20;
	evade =		4;
	talkTo =	true;
}
//=============================================================================================================
//												Humans
//=============================================================================================================
human::human()
{
	name = "Human Peasant";
	level =		2;
	damage =	8;
	damMod =	3;
	hp = mhp =	30;
	ka = mka =  0;
	evade =		6;
	gold =		20;
	exp =		10;
	def =		0;
	talkTo =	true;
}

knight::knight()
{
	name = "Human Knight";
	level =		rand()% 5 + 5;
	switch(level)
	{
	case 5:
	case 6:
		damage = 11;	damMod = 6;	def = 7; magdef =	10;
		hp = mhp = 70;	gold = 120;	exp = 125;
		break;
	case 7:
	case 8:
		damage = 15; damMod = 8;	def = 9; magdef =	15;
		hp = mhp = 120;	gold = 160;	exp = 150;
		break;
	case 9:
	case 10:
		damage = 20; damMod = 10;	def = 11; magdef =	20;
		hp = mhp = 160;	gold = 200;	exp = 200;
		break;
	}
	ka = mka =  0;
	evade =		4;
	talkTo =	true;
}

adventure::adventure()
{	
	talkTo =	true;
}

wizard::wizard()
{
	name = "Human Wizard";
	level =		6;
	damage =	20;
	damMod =	20;
	hp = mhp =	90;
	ka = mka =  30;
	evade =		6;
	gold =		20;
	exp =		10;
	def =		0;
	magdef =	20;
	talkTo =	true;
}
//=============================================================================================================
//											Semi-intelligent races
//=============================================================================================================
goblin::goblin()
{
	name = "Goblin";
	level =		1;
	damage =	6;
	damMod =	4;
	hp = mhp = 10;
	def = 2;
	evade =		4;
	gold =		20;
	exp =		5;
}
ogre::ogre()
{
	name =		"Ogre";
	level =		3;
	damage =	10;
	damMod =	10;
	hp = mhp =	60;
	def = 10;
	magdef = 5;
	evade =		3;
	gold =		45;
	exp =		35;
}
troll::troll()
{
	name =		"Troll";
	level =		3;
	damage =	10;
	damMod =	5;
	hp = mhp =	55;
	def = 5;
	magdef = 10;
	evade =		6;
	gold =		40;
	exp =		35;
}
magmaman::magmaman()
{
	name = "Magma Man";
	level = 8;
	damage = 30;
	damMod = 30;
	hp = mhp = 350;
	def = 30;
	magdef = 5;
	evade = 3;
	gold = 245;
	exp = 300;
	weakness = "ice";
}
cyclops::cyclops()
{
	name = "Cyclops";
	level = 9;
	damage = 30;
	damMod = 20;
	hp = mhp = 200;
	def = 20;
	magdef = 10;
	evade = 5;
	gold = 250;
	exp = 350;
}
giant::giant()
{
	name = "Giant";
	level = 7;
	damage = 20;
	damMod = 10;
	hp = mhp = 95;
	def = 15;
	evade = 4;
	gold = 200;
	exp = 100;
}
frostgiant::frostgiant()
{
	name = "Frost Giant";
	level = 8;
	damage = 27;
	damMod = 13;
	hp = mhp = 125;
	def = 25;
	magdef = 35;
	evade = 3;
	gold = 225;
	exp = 135;
	weakness = "fire";
}
stormgiant::stormgiant()
{
	name = "Storm Giant";
	level = 12;
	damage = 40;
	damMod = 20;
	hp = mhp = 400;
	def = 35;
	magdef = 35;
	evade = 3;
	gold = 400;
	exp = 500;
}
nymph::nymph()
{
	name = "Forest Nymph";
	level = 4;
	damage = 10;
	damMod = 10;
	hp = mhp = 40;
	magdef = 50;
	evade = 10;
	gold = 40;
	exp = 60;
}
icewizard::icewizard()
{
	name = "Ice Wizard";
	level = 6;
	damage = 10;
	damMod = 1;
	hp = mhp = 75;
	magdef = 60;
	evade = 8;
	gold = 200;
	exp = 75;
}
snowman::snowman()
{
	name = "Snowman";
	level = 5;
	damage = 15;
	damMod = 15;
	hp = mhp = 100;
	def = 15;
	magdef = 50;
	evade = 5;
	gold = 13;
	exp = 65;
	weakness = "fire";
}
shrineguard::shrineguard()
{
	name = "Shrine Guardian";
	level = 8;
	damage = 25;
	damMod = 20;
	def = 15;
	hp = mhp = 125;
	def = 40;
	evade = 15;
	gold = 200;
	exp = 175;
}
rockgolem::rockgolem()
{
	name = "Rock Golem";
	level = 7;
	damage = 25;
	damMod = 22;
	def = 10;
	hp = mhp = 200;
	magdef = 10;
	evade = 1;
	gold = 200;
	exp = 165;
}
irongolem::irongolem()
{
	name = "Iron Golem";
	level = 9;
	damage = 40;
	damMod = 33;
	def = 30;
	hp = mhp = 500;
	magdef = 10;
	evade = 1;
	gold = 500;
	exp = 450;
}
steelgolem::steelgolem()
{
	name = "Steel Golem";
	level = 16;
	damage = 100;
	damMod = 10;
	def = 50;
	hp = mhp = 800;
	magdef = 15;
	evade = 1;
	gold = 1000;
	exp = 1000;
}
treeman::treeman()
{
	name = "Treeman";
	level = 6;
	damage = 30;
	damMod = 10;
	hp = mhp = 75;
	def = 10;
	magdef = 10;
	evade = 3;
	gold = 30;
	exp = 80;
	weakness = "fire";
}
acolyte::acolyte()
{
	name = "Acolyte";
	level = 1;
	damage = 1;
	damMod = 1;
	hp = mhp = 1;
	evade = 1;
	gold = 1;
	exp = 1;
}
//=============================================================================================================
//												Wild Life
//=============================================================================================================
gspider::gspider()
{
	name = "Giant Spider";
	level =		2;
	damage =	7;
	damMod =	4;
	hp = mhp =  20;
	evade =		5;
	gold =		0;
	exp =		10;
	def =		1;
}

wolf::wolf()
{
	name = "Rabid Wolf";
	level =		1;
	damage =	6;
	damMod =	3;
	hp = mhp =	8;
	evade =		5;
	gold =		0;
	exp =		5;
}

raven::raven()
{
	name = "Wild Raven";
	level =		1;
	damage =	6;
	damMod =	3;
	hp = mhp =	8;
	evade =		5;
	gold =		0;
	exp =		5;
}
snake::snake()
{
	name = "Big Snake";
	level =		1;
	damage =	4;
	damMod =	3;
	hp = mhp =	10;
	evade =		5;
	gold =		0;
	exp =		5;
}
eagle::eagle()
{
	name = "Giant Eagle";
	level =		4;
	damage =	15;
	damMod =	8;
	hp = mhp =	45;
	evade =		10;
	gold =		0;
	exp =		50;
}
pbear::pbear()
{
	name = "Polar Bear";
	level =		5;
	damage =	23;
	damMod =	13;
	hp = mhp =	75;
	evade =		5;
	gold =		0;
	exp =		100;
	weakness = "fire";
}
salamander::salamander()
{
	name = "Salamander";
	level =		6;
	damage =	20;
	damMod =	25;
	hp = mhp =	200;
	magdef =	15;
	evade =		5;
	gold =		0;
	exp =		250;
	weakness =  "ice";
}
firedemon::firedemon()
{
	name = "Fire Demon";
	level =		10;
	damage =	30;
	damMod =	25;
	hp = mhp =	250;
	def		=	20;
	magdef	=	20;
	evade =		5;
	gold =		100;
	exp =		300;
	weakness =  "ice";
}
centipede::centipede()
{
	name = "Giant Centipede";
	level =		10;
	damage =	40;
	damMod =	40;
	hp = mhp =	450;
	evade =		5;
	gold =		0;
	exp =		500;
}
wyvern::wyvern()
{
	name = "Wyvern";
	level =		11;
	damage =	40;
	damMod =	40;
	hp = mhp =	400;
	def =		20;
	magdef =	20;
	evade =		20;
	gold =		0;
	exp =		400;
}
hydra::hydra()
{
	name = "Hydra";
	level =		11;
	damage =	60;
	damMod =	40;
	hp = mhp =	450;
	def =		35;
	magdef =	35;
	evade =		10;
	gold =		0;
	exp =		500;
}
minator::minator()
{
	name = "Minotaur";
	level =		14;
	damage =	70;
	damMod =	50;
	hp = mhp =	565;
	def =		45;
	magdef =	45;
	evade =		5;
	gold =		400;
	exp =		560;
}
gargoyle::gargoyle()
{
	name = "Gargoyle";
	level =		6;
	damage =	20;
	damMod =	10;
	hp = mhp =	100;
	evade =		50;
	gold =		28;
	exp =		97;
}
margoyle::margoyle()
{
	name = "Margoyle";
	level = 12;
	damage = 40;
	damMod = 20;
	hp = mhp = 200;
	def = 15;
	magdef = 15;
	evade = 25;
	gold = 56;
	exp = 250;
}
stargoyle::stargoyle()
{
	name = "Stargoyle";
	level = 24;
	damage = 80;
	damMod = 40;
	hp = mhp = 400;
	def = 20;
	magdef = 20;
	evade = 12;
	gold = 102;
	exp = 1000;
	weakness = "lightning";
}

//=============================================================================================================
//												Undead
//=============================================================================================================
skel::skel()
{
	name = "Skeleton";
	level =		2;
	damage =	7;
	damMod =	3;
	hp = mhp =	20;
	evade =		9;
	gold =		0;
	exp =		25;
	type =		"undead";
}

ghoul::ghoul()
{
	name = "Ghoul";
	level =		2;
	damage =	10;
	damMod =	5;
	hp = mhp = 25;
	evade =		4;
	gold =		0;
	exp =		35;
	type =		"undead";
}

ghost::ghost()
{
	name = "Ghost";
	level =		6;
	damage =	10;
	damMod =	10;
	hp = mhp =	35;
	evade =		40;
	gold =		0;
	exp =		150;
	type =		"undead";
}

phantom::phantom()
{
	name = "Phantom";
	level = 4;
	damage = 20;
	damMod = 10;
	hp = mhp = 70;
	evade = 5;
	gold = 0;
	exp = 100;
	type = "undead";
}

vampire::vampire()
{
	name = "Vampire";
	level = 12;
	damage = 50;
	damMod = 50;
	hp = mhp = 275;
	magdef = 75;
	evade = 15;
	gold = 500;
	exp = 500;
	type = "undead";
}

//=============================================================================================================
//												Bosses
//=============================================================================================================
woodpriest::woodpriest()
{
	name = "Wood Priest";
	level = 15;
	damage = 25;
	damMod = 25;
	hp = mhp = 200;
	ka = mka = 35;
	def = 20;
	magdef = 15;
	evade = 15;
	gold = 350;
	exp = 400;
	dontmove = true;
	bant = true;
}

icepriest::icepriest()
{
	name = "Ice Priest";
	level = 20;
	damage = 30;
	damMod = 30;
	hp = mhp = 400;
	ka = mka = 175;
	def = 25;
	magdef = 20;
	evade = 15;
	gold = 500;
	exp = 750;
	dontmove = true;
	bant = true;
}

firepriest::firepriest()
{
	name = "Fire Priest";
	level = 25;
	damage = 50;
	damMod = 50;
	hp = mhp = 600;
	ka = mka = 225;
	def = 30;
	magdef = 35;
	evade = 15;
	gold = 1000;
	exp = 1500;
	dontmove = true;
	bant = true;
}

windpriest::windpriest()
{
	name = "Wind Priest";
	level = 30;
	damage = 75;
	damMod = 50;
	hp = mhp = 800;
	ka = mka = 300;
	def = 35;
	magdef = 40;
	evade = 15;
	gold = 2000;
	exp = 2500;
	bant = true;
}

godofwar::godofwar()
{
	name = "God of War";
	level = 99;
	damage = 200;
	damMod = 50;
	def = 75;
	hp = mhp = 4000;
	ka = mka = 300;
	def = 55;
	evade = 15;
	gold = 0;
	exp = 0;
	dontmove = true;
	bant = true;
}

godoflife::godoflife()
{
	name = "God of Life";
	level = 99;
	damage = 100;
	damMod = 50;
	hp = mhp = 3000;
	ka = mka = 300;
	def = 10;
	magdef = 50;
	ka = 200;
	evade = 25;
	gold = 0;
	exp = 0;
	dontmove = true;
	bant = true;
}

godofchaos::godofchaos()
{
	name = "God of Chaos";
	level = 99;
	damage = 100;
	damMod = 50;
	hp = mhp = 3500;
	ka = mka = 300;
	ka = 100;
	def = 60;
	magdef = 20;
	evade = 15;
	gold = 0;
	exp = 0;
	dontmove = true;
	bant = true;
}

godofdeath::godofdeath()
{
	name = "God of Death";
	level = 99;
	damage = 200;
	damMod = 100;
	hp = mhp = 5000;
	ka = mka = 200;
	def = 60;
	magdef = 60;
	evade = 15;
	gold = 0;
	exp = 0;
	dontmove = true;
	bant = true;
}


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

monk::monk()
{
	name = "Peaceful Monk";
	level = 69;
	damage = 10;
	damMod = 10;
	def = 75;
	hp = mhp = 125;
	magdef = 95;
	evade = 95;
	gold = 0;
	exp = 9999;
	map = "field2";
	bant = true;
}
fly::fly()
{
	name = "Fly";
	level = 0;
	damage = 2;
	damMod = 2;
	hp = mhp = 10;
	evade = 0;
	gold = 0;
	exp = 0;
}
greendragon::greendragon()
{
	name = "Green Dragon";
	level = 80;
	damage = 50;
	damMod = 50;
	hp = mhp = 2000;
	evade = 15;
	def = 50;
	magdef = 50;
	gold = 6000;
	exp = 2000;
	dontmove = true;
	bant = true;
}

bluedragon::bluedragon()
{
	name = "Blue Dragon";
	level = 80;
	damage = 50;
	damMod = 50;
	hp = mhp = 2000;
	def = 50;
	magdef = 50;
	evade = 15;
	gold = 6000;
	exp = 2000;
	dontmove = true;
	bant = true;
}

reddragon::reddragon()
{
	name = "Red Dragon";
	level = 80;
	damage = 50;
	damMod = 50;
	hp = mhp = 2000;
	def = 50;
	magdef = 50;
	evade = 15;
	gold = 6000;
	exp = 2000;
	dontmove = true;
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















