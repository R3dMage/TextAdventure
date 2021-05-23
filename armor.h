#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
;
using namespace std;

void text(string szText,int X,int Y,WORD color);
void num(int num,int X,int Y,WORD color);

class armor : public item{
public:
	armor();
	void setdefMod(int);
	int getdefMod();
	void setevadMod(int);
	int getevadMod();
	bool getmod();

	virtual void display();
	void unload(string name);

private:
	int		defmod;
	int		evadMod;
	bool	mod;
};


#endif