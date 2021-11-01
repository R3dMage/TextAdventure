#ifndef ENEMIES_H
#define ENEMIES_H

#include "Creature.h"			
#include "Player.h"

void clr();

//=============================================================================================================
//												Elves
//=============================================================================================================

class elf : public Creature{
public:
	elf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
	virtual void win(Player *p2);	

};

class mage : public elf{
public:
	mage();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class warrior : public elf{
public:
	warrior();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class fireelf : public elf{
public:
	fireelf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class iceelf : public elf{
public:
	iceelf();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class ranger : public elf{
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

class sorceror : public Orc{
public:
	sorceror();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class osoldier : public Orc{
public:
	osoldier();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual bool talkto(Player *p2);
};

class fireorc : public Orc{
public:
	fireorc();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class iceorc : public Orc{
public:
	iceorc();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class wanderer : public Orc{
public:
	wanderer();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};
//=============================================================================================================
//												Humans
//=============================================================================================================

class human : public Creature{
public:
	human();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	virtual bool talkto(Player *p2);
};
class knight : public human{
public:
	knight();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	//virtual bool talkto(player *p2);
};

class wizard : public human{
public:
	wizard();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* token(string Map);
	//virtual bool talkto(player *p2);
};

class adventure : public human{
public:
	adventure();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual void setmap(string);
};
//=============================================================================================================
//												Wildlife
//=============================================================================================================

class gspider : public Creature{
public:
	gspider();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};

class wolf : public Creature{
public:
	wolf();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};

class raven : public Creature{
public:
	raven();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class snake : public Creature{
public:
	snake();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class eagle : public Creature{
public:
	eagle();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class pbear : public Creature{
public:
	pbear();
	virtual Creature* replenish() const;
	virtual Item* body(string) const;
};
class salamander : public Creature{
public:
	salamander();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class firedemon : public Creature{
public:
	firedemon();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};

class centipede : public Creature{
public:
	centipede();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};
class wyvern : public Creature{
public:
	wyvern();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class hydra : public Creature{
public:
	hydra();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};
class minator : public Creature{
public:
	minator();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
};
class gargoyle : public Creature{
public:
	gargoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class margoyle : public Creature{
public:
	margoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class stargoyle : public Creature{
public:
	stargoyle();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
};
	
//=============================================================================================================
//										Semi Intelligent Races
//=============================================================================================================

class goblin : public Creature{
public:
	goblin();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class ogre : public Creature{
public:
	ogre();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class troll : public Creature{
public:
	troll();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};
class magmaman : public Creature{
public:
	magmaman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class cyclops : public Creature{
public:
	cyclops();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class giant : public Creature{
public:
	giant();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class frostgiant : public Creature{
public:
	frostgiant();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class stormgiant : public Creature{
public:
	stormgiant();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class nymph : public Creature{
public:
	nymph();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class icewizard : public Creature{
public:
	icewizard();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class snowman : public Creature{
public:
	snowman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;virtual bool dropItem();
	virtual Item* token(string Map);
};
class shrineguard : public Creature{
public:
	shrineguard();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class rockgolem : public Creature{
public:
	rockgolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class irongolem : public Creature{
public:
	irongolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class steelgolem : public Creature{
public:
	steelgolem();
	virtual Creature* replenish() const;
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class treeman : public Creature{
public:
	treeman();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
class acolyte : public Creature{
public:
	acolyte();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
	virtual bool dropItem();
	virtual Item* token(string Map);
};
//=============================================================================================================
//												Undead
//=============================================================================================================

class ghoul : public Creature{
public:
	ghoul();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class skel : public Creature{
public:
	skel();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
};

class ghost : public Creature{
public:
	ghost();
	virtual Creature* replenish() const;
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Item* body(string Map) const;
};

class phantom : public Creature{
public:
	phantom();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
};

class vampire : public Creature{
public:
	vampire();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
};

//=============================================================================================================
//												Bosses
//=============================================================================================================

class woodpriest : public Creature{
public:
	woodpriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class icepriest : public Creature{
public:
	icepriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class firepriest : public Creature{
public:
	firepriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class windpriest : public Creature{
public:
	windpriest();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* token(string Map);
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class godofwar : public Creature{
public:
	godofwar();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class godoflife : public Creature{
public:
	godoflife();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class godofchaos : public Creature{
public:
	godofchaos();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual void win(Player *p2);
	void banter();
};

class godofdeath : public Creature{
public:
	godofdeath();
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

class greendragon : public Creature{
public:
	greendragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class bluedragon : public Creature{
public:
	bluedragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class reddragon : public Creature{
public:
	reddragon();
	virtual void attack(Player *p2,vector<Item*> &pstuff, vector<Item*> &stuff,string Map);
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};
	
class monk : public Creature{
public:
	monk();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
	virtual Item* token(string Map);
	virtual void win(Player *p2);
	void banter();
};

class fly : public Creature{
public: 
	fly();
	virtual Creature* replenish() const;
	virtual bool dropItem();
	virtual Item* body(string Map) const;
};

#endif