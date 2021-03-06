#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

using namespace std;

class Weapon : public Item{
public:
	Weapon();
	void SetHitsTwice(bool);
	bool GetHitsTwice();
	void SetStealsLife(bool);
	bool HasLifeSteal();
	void SetDamage(int);
	int GetDamage();
	void SetDamageModifier(int);
	int GetDamageModifier();
	string GetAttribute1();
	void SetAttribute1(string);
	string GetAttribute2();
	void SetAttribute2(string);

	virtual std::string Display();
	void Save(string name);
private:
	string Attribute1;
	string Attribute2;
	bool	HitsTwice;
	bool	StealsLife;
	int		Damage;
	int		DamageModifier;
};

#endif