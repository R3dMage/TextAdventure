#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <iostream>
#include <string>

#include "Creature.h"
#include "GameDisplay.h"

class Magic{
public:
	Magic();
	int GetCost();
	bool GetIsInFight();
	string GetName();
	string GetIncantation();
	string GetDescription();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);


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
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class MajorHeal : public Magic{
public:
	MajorHeal();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class BriarBush : public Magic{
public:
	BriarBush();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Blizzard : public Magic{
public:
	Blizzard();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class PerfectStorm : public Magic{
public:
	PerfectStorm();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class DrainLife : public Magic{
public:
	DrainLife();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class StealKa : public Magic{
public:
	StealKa();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class FireArrow : public Magic{
public:
	FireArrow();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Fire : public Magic{
public:
	Fire();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Lava : public Magic{
public:
	Lava();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Might : public Magic{
public:
	Might();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Dispel : public Magic{
public:
	Dispel();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Shock : public Magic{
public:
	Shock();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class AcidRain : public Magic{
public:
	AcidRain();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class LightningBolt : public Magic{
public: 
	LightningBolt();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Poison : public Magic{
public:
	Poison();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class RaiseSkeleton : public Magic{
public:
	RaiseSkeleton();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class DarkStrike : public Magic{
public:
	DarkStrike();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Critical : public Magic{
public:
	Critical();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};
class Control : public Magic{
public:
	Control();
	virtual void Cast(Player* player, Creature* enemy, GameDisplay* display);
};

#endif 