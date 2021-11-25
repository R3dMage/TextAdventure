#ifndef ENEMIES_H
#define ENEMIES_H

#include "Creature.h"			
#include "Player.h"

//=============================================================================================================
//												Elves
//=============================================================================================================

class Elf : public Creature{
public:
	Elf();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
	virtual void Win(Player* player, TextDisplay* display);

};

class ElvenMage : public Elf{
public:
	ElvenMage();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
};

class ElvenWarrior : public Elf{
public:
	ElvenWarrior();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
};

class FireElf : public Elf{
public:
	FireElf();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class IceElf : public Elf{
public:
	IceElf();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class ranger : public Elf{
public:
	ranger();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};
//=============================================================================================================
//												Orcs
//=============================================================================================================

class Orc : public Creature{
public:
	Orc();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
	virtual void Win(Player* player, TextDisplay* display);
	
};

class OrcSorceror : public Orc{
public:
	OrcSorceror();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
};

class OrcSoldier : public Orc{
public:
	OrcSoldier();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual Greeting GetGreeting(Player *player);
};

class FireOrc : public Orc{
public:
	FireOrc();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class IceOrc : public Orc{
public:
	IceOrc();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class OrcWanderer : public Orc{
public:
	OrcWanderer();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};
//=============================================================================================================
//												Humans
//=============================================================================================================

class Human : public Creature{
public:
	Human();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Win(Player* player, TextDisplay* display);
	virtual Greeting GetGreeting(Player *player);
};
class Knight : public Human{
public:
	Knight();
	virtual bool DroppedItem();
	virtual string Token();
	//virtual Greeting GetGreeting(player *player);
};

class Wizard : public Human{
public:
	Wizard();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	//virtual Greeting GetGreeting(player *player);
};

class Adventurer : public Human{
public:
	Adventurer();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	virtual void setmap(string);
};
//=============================================================================================================
//												Wildlife
//=============================================================================================================

class GiantSpider : public Creature{
public:
	GiantSpider();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
};

class Wolf : public Creature{
public:
	Wolf();
	virtual Item* Body(string map) const;
};

class Raven : public Creature{
public:
	Raven();
	virtual Item* Body(string map) const;
};
class Snake : public Creature{
public:
	Snake();
	virtual Item* Body(string) const;
};
class Eagle : public Creature{
public:
	Eagle();
	virtual Item* Body(string) const;
};
class PolarBear : public Creature{
public:
	PolarBear();
	virtual Item* Body(string) const;
};
class Salamander : public Creature{
public:
	Salamander();
	virtual Item* Body(string map) const;
};
class FireDemon : public Creature{
public:
	FireDemon();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};

class Centipede : public Creature{
public:
	Centipede();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
};
class Wyvern : public Creature{
public:
	Wyvern();
	virtual Item* Body(string map) const;
};
class Hydra : public Creature{
public:
	Hydra();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
};
class Minotaur : public Creature{
public:
	Minotaur();
	virtual Item* Body(string map) const;
};
class Gargoyle : public Creature{
public:
	Gargoyle();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class Margoyle : public Creature{
public:
	Margoyle();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class Stargoyle : public Creature{
public:
	Stargoyle();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Attack(Player *player, TextDisplay* display);
};
	
//=============================================================================================================
//										Semi Intelligent Races
//=============================================================================================================

class Goblin : public Creature{
public:
	Goblin();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class Ogre : public Creature{
public:
	Ogre();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};

class Troll : public Creature{
public:
	Troll();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
};
class Magmaman : public Creature{
public:
	Magmaman();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Cyclops : public Creature{
public:
	Cyclops();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Giant : public Creature{
public:
	Giant();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class FrostGiant : public Creature{
public:
	FrostGiant();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class StormGiant : public Creature{
public:
	StormGiant();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Nymph : public Creature{
public:
	Nymph();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class IceWizard : public Creature{
public:
	IceWizard();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Snowman : public Creature{
public:
	Snowman();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;virtual bool DroppedItem();
	virtual string Token();
};
class ShrineGuard : public Creature{
public:
	ShrineGuard();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class RockGolem : public Creature{
public:
	RockGolem();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class IronGolem : public Creature{
public:
	IronGolem();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class SteelGolem : public Creature{
public:
	SteelGolem();
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Treeman : public Creature{
public:
	Treeman();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
class Acolyte : public Creature{
public:
	Acolyte();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual string Token();
};
//=============================================================================================================
//												Undead
//=============================================================================================================

class Ghoul : public Creature{
public:
	Ghoul();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

class Skeleton : public Creature{
public:
	Skeleton();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

class Ghost : public Creature{
public:
	Ghost();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual Item* Body(string map) const;
};

class Phantom : public Creature{
public:
	Phantom();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

class Vampire : public Creature{
public:
	Vampire();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Attack(Player *player, TextDisplay* display);
};

//=============================================================================================================
//												Bosses
//=============================================================================================================

class WoodPriest : public Creature{
public:
	WoodPriest();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class IcePriest : public Creature{
public:
	IcePriest();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class FirePriest : public Creature{
public:
	FirePriest();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class WindPriest : public Creature{
public:
	WindPriest();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual string Token();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class GodOfWar : public Creature{
public:
	GodOfWar();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class GodOfLife : public Creature{
public:
	GodOfLife();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class GodOfChaos : public Creature{
public:
	GodOfChaos();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class GodOfDeath : public Creature{
public:
	GodOfDeath();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

class GreenDragon : public Creature{
public:
	GreenDragon();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Win(Player* player, TextDisplay* display);
};

class BlueDragon : public Creature{
public:
	BlueDragon();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Win(Player* player, TextDisplay* display);
};

class RedDragon : public Creature{
public:
	RedDragon();
	virtual void Attack(Player *player, TextDisplay* display);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Win(Player* player, TextDisplay* display);
};
	
class Monk : public Creature{
public:
	Monk();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual string Token();
	virtual void Win(Player* player, TextDisplay* display);
	virtual vector<string> Banter();
};

class Fly : public Creature{
public: 
	Fly();
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

#endif