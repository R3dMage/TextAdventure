#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item{
public:
	Armor();
	void SetDefenseModifier(int);
	int GetDefenseModifier();
	void SetEvadeModifier(int);
	int GetEvadeModifier();

	virtual std::string Display();
	void Save(std::string name);

private:
	int		DefenseModifier;
	int		EvadeModifier;
};

#endif