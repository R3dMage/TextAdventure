#ifndef ENEMIES_H
#define ENEMIES_H

#include "Creature.h"			
#include "Player.h"

void clr();

//=============================================================================================================
//												Elves
//=============================================================================================================

class Elf : public Creature{
public:
	Elf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
	virtual void win(Player *p2);	

};

class ElvenMage : public Elf{
public:
	ElvenMage();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class ElvenWarrior : public Elf{
public:
	ElvenWarrior();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class FireElf : public Elf{
public:
	FireElf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class IceElf : public Elf{
public:
	IceElf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class ranger : public Elf{
public:
	ranger();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};
//=============================================================================================================
//												Orcs
//=============================================================================================================

class Orc : public Creature{
public:
	Orc();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
	virtual void win(Player *p2);
	
};

class OrcSorceror : public Orc{
public:
	OrcSorceror();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class OrcSoldier : public Orc{
public:
	OrcSoldier();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class FireOrc : public Orc{
public:
	FireOrc();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class IceOrc : public Orc{
public:
	IceOrc();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class OrcWanderer : public Orc{
public:
	OrcWanderer();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};
//=============================================================================================================
//												Humans
//=============================================================================================================

class Human : public Creature{
public:
	Human();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	virtual bool talkto(Player *p2);
};
class Knight : public Human{
public:
	Knight();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	//virtual bool talkto(player *p2);
};

class Wizard : public Human{
public:
	Wizard();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* token(string Map);
	//virtual bool talkto(player *p2);
};

class Adventurer : public Human{
public:
	Adventurer();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual void setmap(string);
};
//=============================================================================================================
//												Wildlife
//=============================================================================================================

class GiantSpider : public Creature{
public:
	GiantSpider();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};

class Wolf : public Creature{
public:
	Wolf();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};

class Raven : public Creature{
public:
	Raven();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class Snake : public Creature{
public:
	Snake();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class Eagle : public Creature{
public:
	Eagle();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class PolarBear : public Creature{
public:
	PolarBear();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class Salamander : public Creature{
public:
	Salamander();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class FireDemon : public Creature{
public:
	FireDemon();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};

class Centipede : public Creature{
public:
	Centipede();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};
class Wyvern : public Creature{
public:
	Wyvern();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class Hydra : public Creature{
public:
	Hydra();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};
class Minotaur : public Creature{
public:
	Minotaur();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class Gargoyle : public Creature{
public:
	Gargoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Margoyle : public Creature{
public:
	Margoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Stargoyle : public Creature{
public:
	Stargoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
};
	
//=============================================================================================================
//										Semi Intelligent Races
//=============================================================================================================

class Goblin : public Creature{
public:
	Goblin();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Ogre : public Creature{
public:
	Ogre();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Troll : public Creature{
public:
	Troll();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};
class Magmaman : public Creature{
public:
	Magmaman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Cyclops : public Creature{
public:
	Cyclops();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Giant : public Creature{
public:
	Giant();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class FrostGiant : public Creature{
public:
	FrostGiant();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class StormGiant : public Creature{
public:
	StormGiant();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Nymph : public Creature{
public:
	Nymph();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class IceWizard : public Creature{
public:
	IceWizard();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Snowman : public Creature{
public:
	Snowman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;virtual bool dropItem();
	virtual Item* token(string Map);
};
class ShrineGuard : public Creature{
public:
	ShrineGuard();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class RockGolem : public Creature{
public:
	RockGolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class IronGolem : public Creature{
public:
	IronGolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class SteelGolem : public Creature{
public:
	SteelGolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Treeman : public Creature{
public:
	Treeman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class Acolyte : public Creature{
public:
	Acolyte();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
//=============================================================================================================
//												Undead
//=============================================================================================================

class Ghoul : public Creature{
public:
	Ghoul();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Skeleton : public Creature{
public:
	Skeleton();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
};

class Ghost : public Creature{
public:
	Ghost();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};

class Phantom : public Creature{
public:
	Phantom();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class Vampire : public Creature{
public:
	Vampire();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
};

//=============================================================================================================
//												Bosses
//=============================================================================================================

class WoodPriest : public Creature{
public:
	WoodPriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class IcePriest : public Creature{
public:
	IcePriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class FirePriest : public Creature{
public:
	FirePriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class WindPriest : public Creature{
public:
	WindPriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class GodOfWar : public Creature{
public:
	GodOfWar();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class GodOfLife : public Creature{
public:
	GodOfLife();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class GodOfChaos : public Creature{
public:
	GodOfChaos();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class GodOfDeath : public Creature{
public:
	GodOfDeath();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

class GreenDragon : public Creature{
public:
	GreenDragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class BlueDragon : public Creature{
public:
	BlueDragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class RedDragon : public Creature{
public:
	RedDragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};
	
class Monk : public Creature{
public:
	Monk();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class Fly : public Creature{
public: 
	Fly();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
};

#endif