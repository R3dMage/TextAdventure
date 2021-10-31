#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

;
using namespace std;

void text(string szText,int X,int Y,WORD color);
void num(int num,int X,int Y,WORD color);

class weapon : public Item{
public:
	weapon();
	void set2hits(bool);
	bool get2hits();
	void setlsteal(bool);
	bool getlsteal();
	void setdamage(int);
	int getdamage();
	void setdamMod(int);
	int getdamMod();
	bool getmod();
	void setmod(bool);
	string getAttribute1();
	void setAttribute1(string);
	string getAttribute2();
	void setAttribute2(string);

	virtual void display();
	void unload(string name);
private:
	string attribute1;
	string attribute2;
	bool	twohits;
	bool	lifesteal;
	bool	mod;
	int		damage;
	int		damMod;
};

#endif