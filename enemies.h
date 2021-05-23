#ifndef ENEMIES_H
#define ENEMIES_H

#include "creature.h"			
#include "player.h"

void clr();

//=============================================================================================================
//												Elves
//=============================================================================================================

class elf : public creature{
public:
	elf();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
	virtual void win(player *p2);	

};

class mage : public elf{
public:
	mage();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
};

class warrior : public elf{
public:
	warrior();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
};

class fireelf : public elf{
public:
	fireelf();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class iceelf : public elf{
public:
	iceelf();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class ranger : public elf{
public:
	ranger();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};
//=============================================================================================================
//												Orcs
//=============================================================================================================

class Orc : public creature{
public:
	Orc();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
	virtual void win(player *p2);
	
};

class sorceror : public Orc{
public:
	sorceror();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
};

class osoldier : public Orc{
public:
	osoldier();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual bool talkto(player *p2);
};

class fireorc : public Orc{
public:
	fireorc();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class iceorc : public Orc{
public:
	iceorc();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class wanderer : public Orc{
public:
	wanderer();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};
//=============================================================================================================
//												Humans
//=============================================================================================================

class human : public creature{
public:
	human();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void win(player *p2);
	virtual bool talkto(player *p2);
};
class knight : public human{
public:
	knight();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* token(string Map);
	//virtual bool talkto(player *p2);
};

class wizard : public human{
public:
	wizard();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* token(string Map);
	//virtual bool talkto(player *p2);
};

class adventure : public human{
public:
	adventure();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual bool dropItem();
	virtual item* token(string Map);
	virtual void setmap(string);
};
//=============================================================================================================
//												Wildlife
//=============================================================================================================

class gspider : public creature{
public:
	gspider();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
};

class wolf : public creature{
public:
	wolf();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
};

class raven : public creature{
public:
	raven();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
};
class snake : public creature{
public:
	snake();
	virtual creature* replenish() const;
	virtual item* body(string) const;
};
class eagle : public creature{
public:
	eagle();
	virtual creature* replenish() const;
	virtual item* body(string) const;
};
class pbear : public creature{
public:
	pbear();
	virtual creature* replenish() const;
	virtual item* body(string) const;
};
class salamander : public creature{
public:
	salamander();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
};
class firedemon : public creature{
public:
	firedemon();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};

class centipede : public creature{
public:
	centipede();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
};
class wyvern : public creature{
public:
	wyvern();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
};
class hydra : public creature{
public:
	hydra();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
};
class minator : public creature{
public:
	minator();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
};
class gargoyle : public creature{
public:
	gargoyle();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class margoyle : public creature{
public:
	margoyle();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class stargoyle : public creature{
public:
	stargoyle();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
};
	
//=============================================================================================================
//										Semi Intelligent Races
//=============================================================================================================

class goblin : public creature{
public:
	goblin();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class ogre : public creature{
public:
	ogre();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class troll : public creature{
public:
	troll();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};
class magmaman : public creature{
public:
	magmaman();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class cyclops : public creature{
public:
	cyclops();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class giant : public creature{
public:
	giant();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class frostgiant : public creature{
public:
	frostgiant();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class stormgiant : public creature{
public:
	stormgiant();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class nymph : public creature{
public:
	nymph();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class icewizard : public creature{
public:
	icewizard();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class snowman : public creature{
public:
	snowman();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;virtual bool dropItem();
	virtual item* token(string Map);
};
class shrineguard : public creature{
public:
	shrineguard();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class rockgolem : public creature{
public:
	rockgolem();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class irongolem : public creature{
public:
	irongolem();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class steelgolem : public creature{
public:
	steelgolem();
	virtual creature* replenish() const;
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class treeman : public creature{
public:
	treeman();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
class acolyte : public creature{
public:
	acolyte();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
	virtual bool dropItem();
	virtual item* token(string Map);
};
//=============================================================================================================
//												Undead
//=============================================================================================================

class ghoul : public creature{
public:
	ghoul();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class skel : public creature{
public:
	skel();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
};

class ghost : public creature{
public:
	ghost();
	virtual creature* replenish() const;
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual item* body(string Map) const;
};

class phantom : public creature{
public:
	phantom();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
};

class vampire : public creature{
public:
	vampire();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
};

//=============================================================================================================
//												Bosses
//=============================================================================================================

class woodpriest : public creature{
public:
	woodpriest();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* token(string Map);
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class icepriest : public creature{
public:
	icepriest();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* token(string Map);
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class firepriest : public creature{
public:
	firepriest();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* token(string Map);
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class windpriest : public creature{
public:
	windpriest();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* token(string Map);
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class godofwar : public creature{
public:
	godofwar();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class godoflife : public creature{
public:
	godoflife();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class godofchaos : public creature{
public:
	godofchaos();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};

class godofdeath : public creature{
public:
	godofdeath();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual void win(player *p2);
	void banter();
};


//=============================================================================================================
//										Optional High Level Encounters
//=============================================================================================================

class greendragon : public creature{
public:
	greendragon();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void win(player *p2);
	void banter();
};

class bluedragon : public creature{
public:
	bluedragon();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void win(player *p2);
	void banter();
};

class reddragon : public creature{
public:
	reddragon();
	virtual void attack(player *p2,vector<item*> &pstuff, vector<item*> &stuff,string Map);
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void win(player *p2);
	void banter();
};
	
class monk : public creature{
public:
	monk();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
	virtual item* token(string Map);
	virtual void win(player *p2);
	void banter();
};

class fly : public creature{
public: 
	fly();
	virtual creature* replenish() const;
	virtual bool dropItem();
	virtual item* body(string Map) const;
};

#endif