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
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
	virtual void Win(Player *player);	

};

class ElvenMage : public Elf{
public:
	ElvenMage();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
};

class ElvenWarrior : public Elf{
public:
	ElvenWarrior();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
};

class FireElf : public Elf{
public:
	FireElf();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class IceElf : public Elf{
public:
	IceElf();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class ranger : public Elf{
public:
	ranger();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};
//=============================================================================================================
//												Orcs
//=============================================================================================================

class Orc : public Creature{
public:
	Orc();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
	virtual void Win(Player *player);
	
};

class OrcSorceror : public Orc{
public:
	OrcSorceror();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
};

class OrcSoldier : public Orc{
public:
	OrcSoldier();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual bool TalkTo(Player *player);
};

class FireOrc : public Orc{
public:
	FireOrc();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class IceOrc : public Orc{
public:
	IceOrc();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class OrcWanderer : public Orc{
public:
	OrcWanderer();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};
//=============================================================================================================
//												Humans
//=============================================================================================================

class Human : public Creature{
public:
	Human();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Win(Player *player);
	virtual bool TalkTo(Player *player);
};
class Knight : public Human{
public:
	Knight();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	//virtual bool TalkTo(player *player);
};

class Wizard : public Human{
public:
	Wizard();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	//virtual bool TalkTo(player *player);
};

class Adventurer : public Human{
public:
	Adventurer();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	virtual void setmap(string);
};
//=============================================================================================================
//												Wildlife
//=============================================================================================================

class GiantSpider : public Creature{
public:
	GiantSpider();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
};

class Wolf : public Creature{
public:
	Wolf();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
};

class Raven : public Creature{
public:
	Raven();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
};
class Snake : public Creature{
public:
	Snake();
	virtual Creature* Replenish() const;
	virtual Item* Body(string) const;
};
class Eagle : public Creature{
public:
	Eagle();
	virtual Creature* Replenish() const;
	virtual Item* Body(string) const;
};
class PolarBear : public Creature{
public:
	PolarBear();
	virtual Creature* Replenish() const;
	virtual Item* Body(string) const;
};
class Salamander : public Creature{
public:
	Salamander();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
};
class FireDemon : public Creature{
public:
	FireDemon();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};

class Centipede : public Creature{
public:
	Centipede();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
};
class Wyvern : public Creature{
public:
	Wyvern();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
};
class Hydra : public Creature{
public:
	Hydra();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
};
class Minotaur : public Creature{
public:
	Minotaur();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
};
class Gargoyle : public Creature{
public:
	Gargoyle();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Margoyle : public Creature{
public:
	Margoyle();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Stargoyle : public Creature{
public:
	Stargoyle();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
};
	
//=============================================================================================================
//										Semi Intelligent Races
//=============================================================================================================

class Goblin : public Creature{
public:
	Goblin();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Ogre : public Creature{
public:
	Ogre();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Troll : public Creature{
public:
	Troll();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};
class Magmaman : public Creature{
public:
	Magmaman();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Cyclops : public Creature{
public:
	Cyclops();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Giant : public Creature{
public:
	Giant();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class FrostGiant : public Creature{
public:
	FrostGiant();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class StormGiant : public Creature{
public:
	StormGiant();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Nymph : public Creature{
public:
	Nymph();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class IceWizard : public Creature{
public:
	IceWizard();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Snowman : public Creature{
public:
	Snowman();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class ShrineGuard : public Creature{
public:
	ShrineGuard();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class RockGolem : public Creature{
public:
	RockGolem();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class IronGolem : public Creature{
public:
	IronGolem();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class SteelGolem : public Creature{
public:
	SteelGolem();
	virtual Creature* Replenish() const;
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Treeman : public Creature{
public:
	Treeman();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
class Acolyte : public Creature{
public:
	Acolyte();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
};
//=============================================================================================================
//												Undead
//=============================================================================================================

class Ghoul : public Creature{
public:
	Ghoul();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Skeleton : public Creature{
public:
	Skeleton();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

class Ghost : public Creature{
public:
	Ghost();
	virtual Creature* Replenish() const;
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Item* Body(string map) const;
};

class Phantom : public Creature{
public:
	Phantom();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
};

class Vampire : public Creature{
public:
	Vampire();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
};

//=============================================================================================================
//												Bosses
//=============================================================================================================

class WoodPriest : public Creature{
public:
	WoodPriest();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class IcePriest : public Creature{
public:
	IcePriest();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class FirePriest : public Creature{
public:
	FirePriest();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class WindPriest : public Creature{
public:
	WindPriest();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Token(string map);
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class GodOfWar : public Creature{
public:
	GodOfWar();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class GodOfLife : public Creature{
public:
	GodOfLife();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class GodOfChaos : public Creature{
public:
	GodOfChaos();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};

class GodOfDeath : public Creature{
public:
	GodOfDeath();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual void Win(Player *player);
	void banter();
};


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

class GreenDragon : public Creature{
public:
	GreenDragon();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Win(Player *player);
	void banter();
};

class BlueDragon : public Creature{
public:
	BlueDragon();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Win(Player *player);
	void banter();
};

class RedDragon : public Creature{
public:
	RedDragon();
	virtual void Attack(Player *player,vector<Item*> &playerInventory, vector<Item*> &worldItems,string map);
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Win(Player *player);
	void banter();
};
	
class Monk : public Creature{
public:
	Monk();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
	virtual Item* Token(string map);
	virtual void Win(Player *player);
	void banter();
};

class Fly : public Creature{
public: 
	Fly();
	virtual Creature* Replenish() const;
	virtual bool DroppedItem();
	virtual Item* Body(string map) const;
};

#endif