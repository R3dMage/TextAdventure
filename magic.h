#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <iostream>
#include <string>

#include "Creature.h"

class magik{
public:
	magik();
	void slowDisp(string szText);
	void tout(int,WORD);
	void cast();
	void Disp();
	void setname(string);
	void setincant(string);
	void setdesc(string);
	void setcost(int);
	void setbInfight(bool);
	int getcost();
	bool getbInfight();
	string getname();
	virtual void use(Player *, creature *);


protected:
	string name;
	string incantation;
	string description;
	string attribute;
	int cost;
	bool bInfight;
	
};
class minheal : public magik{
public:
	minheal();
	virtual void use(Player *,creature*);
};
class majheal : public magik{
public:
	majheal();
	virtual void use(Player *,creature *);
};
class briar : public magik{
public:
	briar();
	virtual void use(Player *,creature*);
};
class snow : public magik{
public:
	snow();
	virtual void use(Player *,creature*);
};
class pstorm : public magik{
public:
	pstorm();
	virtual void use(Player *,creature*);
};
class dlife : public magik{
public:
	dlife();
	virtual void use(Player *,creature*);
};
class stealka : public magik{
public:
	stealka();
	virtual void use(Player *,creature*);
};
class farrow : public magik{
public:
	farrow();
	virtual void use(Player *,creature*);
};
class fire : public magik{
public:
	fire();
	virtual void use(Player *,creature*);
};
class lava : public magik{
public:
	lava();
	virtual void use(Player *,creature*);
};
class strength : public magik{
public:
	strength();
	virtual void use(Player *,creature *);
};
class dispel : public magik{
public:
	dispel();
	virtual void use(Player *,creature *);
};
class shock : public magik{
public:
	shock();
	virtual void use(Player *,creature*);
};
class acidrain : public magik{
public:
	acidrain();
	virtual void use(Player *,creature*);
};
class lightning : public magik{
public: 
	lightning();
	virtual void use(Player *,creature*);
};
class poison : public magik{
public:
	poison();
	virtual void use(Player *,creature*);
};
class skeleton : public magik{
public:
	skeleton();
	virtual void use(Player *,creature*);
};
class dstrike : public magik{
public:
	dstrike();
	virtual void use(Player *,creature*);
};
class critical : public magik{
public:
	critical();
	virtual void use(Player *,creature*);
};
class control : public magik{
public:
	control();
	virtual void use(Player *,creature *);
};



#endif 

