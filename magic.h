#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <iostream>
#include <string>

#include "creature.h"

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
	virtual void use(player *, creature *);


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
	virtual void use(player *,creature*);
};
class majheal : public magik{
public:
	majheal();
	virtual void use(player *,creature *);
};
class briar : public magik{
public:
	briar();
	virtual void use(player *,creature*);
};
class snow : public magik{
public:
	snow();
	virtual void use(player *,creature*);
};
class pstorm : public magik{
public:
	pstorm();
	virtual void use(player *,creature*);
};
class dlife : public magik{
public:
	dlife();
	virtual void use(player *,creature*);
};
class stealka : public magik{
public:
	stealka();
	virtual void use(player *,creature*);
};
class farrow : public magik{
public:
	farrow();
	virtual void use(player *,creature*);
};
class fire : public magik{
public:
	fire();
	virtual void use(player *,creature*);
};
class lava : public magik{
public:
	lava();
	virtual void use(player *,creature*);
};
class strength : public magik{
public:
	strength();
	virtual void use(player *,creature *);
};
class dispel : public magik{
public:
	dispel();
	virtual void use(player *,creature *);
};
class shock : public magik{
public:
	shock();
	virtual void use(player *,creature*);
};
class acidrain : public magik{
public:
	acidrain();
	virtual void use(player *,creature*);
};
class lightning : public magik{
public: 
	lightning();
	virtual void use(player *,creature*);
};
class poison : public magik{
public:
	poison();
	virtual void use(player *,creature*);
};
class skeleton : public magik{
public:
	skeleton();
	virtual void use(player *,creature*);
};
class dstrike : public magik{
public:
	dstrike();
	virtual void use(player *,creature*);
};
class critical : public magik{
public:
	critical();
	virtual void use(player *,creature*);
};
class control : public magik{
public:
	control();
	virtual void use(player *,creature *);
};



#endif 

