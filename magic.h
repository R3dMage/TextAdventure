#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <iostream>
#include <string>

#include "Creature.h"

class Magic{
public:
	Magic();
	void SlowDisplay(string szText);
	void DisplayName(int,WORD);
	void DisplayIncantation();
	void DisplayCastingCost();
	int GetCost();
	bool GetIsInFight();
	string GetName();
	virtual void Cast(Player *, Creature *);


protected:
	string Name;
	string Incantation;
	string Description;
	string Attribute;
	int Cost;
	bool IsInFight;
	
};
class MinorHeal : public Magic{
public:
	MinorHeal();
	virtual void Cast(Player *,Creature*);
};
class MajorHeal : public Magic{
public:
	MajorHeal();
	virtual void Cast(Player *,Creature *);
};
class BriarBush : public Magic{
public:
	BriarBush();
	virtual void Cast(Player *,Creature*);
};
class Blizzard : public Magic{
public:
	Blizzard();
	virtual void Cast(Player *, Creature*);
};
class PerfectStorm : public Magic{
public:
	PerfectStorm();
	virtual void Cast(Player *, Creature*);
};
class DrainLife : public Magic{
public:
	DrainLife();
	virtual void Cast(Player *, Creature*);
};
class StealKa : public Magic{
public:
	StealKa();
	virtual void Cast(Player *, Creature*);
};
class FireArrow : public Magic{
public:
	FireArrow();
	virtual void Cast(Player *, Creature*);
};
class Fire : public Magic{
public:
	Fire();
	virtual void Cast(Player *, Creature*);
};
class Lava : public Magic{
public:
	Lava();
	virtual void Cast(Player *, Creature*);
};
class Might : public Magic{
public:
	Might();
	virtual void Cast(Player *,Creature *);
};
class Dispel : public Magic{
public:
	Dispel();
	virtual void Cast(Player *,Creature *);
};
class Shock : public Magic{
public:
	Shock();
	virtual void Cast(Player *, Creature*);
};
class AcidRain : public Magic{
public:
	AcidRain();
	virtual void Cast(Player *, Creature*);
};
class LightningBolt : public Magic{
public: 
	LightningBolt();
	virtual void Cast(Player *, Creature*);
};
class Poison : public Magic{
public:
	Poison();
	virtual void Cast(Player *, Creature*);
};
class RaiseSkeleton : public Magic{
public:
	RaiseSkeleton();
	virtual void Cast(Player *, Creature*);
};
class DarkStrike : public Magic{
public:
	DarkStrike();
	virtual void Cast(Player *, Creature*);
};
class Critical : public Magic{
public:
	Critical();
	virtual void Cast(Player *, Creature*);
};
class Control : public Magic{
public:
	Control();
	virtual void Cast(Player *,Creature *);
};

#endif 