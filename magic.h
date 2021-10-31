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
	virtual void Cast(Player *, creature *);


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
	virtual void Cast(Player *,creature*);
};
class MajorHeal : public Magic{
public:
	MajorHeal();
	virtual void Cast(Player *,creature *);
};
class BriarBush : public Magic{
public:
	BriarBush();
	virtual void Cast(Player *,creature*);
};
class Blizzard : public Magic{
public:
	Blizzard();
	virtual void Cast(Player *, creature*);
};
class PerfectStorm : public Magic{
public:
	PerfectStorm();
	virtual void Cast(Player *, creature*);
};
class DrainLife : public Magic{
public:
	DrainLife();
	virtual void Cast(Player *, creature*);
};
class StealKa : public Magic{
public:
	StealKa();
	virtual void Cast(Player *, creature*);
};
class FireArrow : public Magic{
public:
	FireArrow();
	virtual void Cast(Player *, creature*);
};
class Fire : public Magic{
public:
	Fire();
	virtual void Cast(Player *, creature*);
};
class Lava : public Magic{
public:
	Lava();
	virtual void Cast(Player *, creature*);
};
class Might : public Magic{
public:
	Might();
	virtual void Cast(Player *,creature *);
};
class Dispel : public Magic{
public:
	Dispel();
	virtual void Cast(Player *,creature *);
};
class Shock : public Magic{
public:
	Shock();
	virtual void Cast(Player *, creature*);
};
class AcidRain : public Magic{
public:
	AcidRain();
	virtual void Cast(Player *, creature*);
};
class LightningBolt : public Magic{
public: 
	LightningBolt();
	virtual void Cast(Player *, creature*);
};
class Poison : public Magic{
public:
	Poison();
	virtual void Cast(Player *, creature*);
};
class Skeleton : public Magic{
public:
	Skeleton();
	virtual void Cast(Player *, creature*);
};
class DarkStrike : public Magic{
public:
	DarkStrike();
	virtual void Cast(Player *, creature*);
};
class Critical : public Magic{
public:
	Critical();
	virtual void Cast(Player *, creature*);
};
class Control : public Magic{
public:
	Control();
	virtual void Cast(Player *,creature *);
};

#endif 