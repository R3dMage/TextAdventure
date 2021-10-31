#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <iostream>
#include <string>

#include "Creature.h"

class Magic{
public:
	Magic();
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
class minheal : public Magic{
public:
	minheal();
	virtual void use(Player *,creature*);
};
class majheal : public Magic{
public:
	majheal();
	virtual void use(Player *,creature *);
};
class briar : public Magic{
public:
	briar();
	virtual void use(Player *,creature*);
};
class snow : public Magic{
public:
	snow();
	virtual void use(Player *,creature*);
};
class pstorm : public Magic{
public:
	pstorm();
	virtual void use(Player *,creature*);
};
class dlife : public Magic{
public:
	dlife();
	virtual void use(Player *,creature*);
};
class stealka : public Magic{
public:
	stealka();
	virtual void use(Player *,creature*);
};
class farrow : public Magic{
public:
	farrow();
	virtual void use(Player *,creature*);
};
class fire : public Magic{
public:
	fire();
	virtual void use(Player *,creature*);
};
class lava : public Magic{
public:
	lava();
	virtual void use(Player *,creature*);
};
class strength : public Magic{
public:
	strength();
	virtual void use(Player *,creature *);
};
class dispel : public Magic{
public:
	dispel();
	virtual void use(Player *,creature *);
};
class shock : public Magic{
public:
	shock();
	virtual void use(Player *,creature*);
};
class acidrain : public Magic{
public:
	acidrain();
	virtual void use(Player *,creature*);
};
class lightning : public Magic{
public: 
	lightning();
	virtual void use(Player *,creature*);
};
class poison : public Magic{
public:
	poison();
	virtual void use(Player *,creature*);
};
class skeleton : public Magic{
public:
	skeleton();
	virtual void use(Player *,creature*);
};
class dstrike : public Magic{
public:
	dstrike();
	virtual void use(Player *,creature*);
};
class critical : public Magic{
public:
	critical();
	virtual void use(Player *,creature*);
};
class control : public Magic{
public:
	control();
	virtual void use(Player *,creature *);
};

#endif 