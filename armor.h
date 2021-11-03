#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

using namespace std;

void text(string szText,int X,int Y,WORD color);
void num(int num,int X,int Y,WORD color);

class Armor : public Item{
public:
	Armor();
	void SetDefenseModifier(int);
	int GetDefenseModifier();
	void SetEvadeModifier(int);
	int GetEvadeModifier();

	virtual void Display();
	void Save(string name);

private:
	int		DefenseModifier;
	int		EvadeModifier;
};


#endif