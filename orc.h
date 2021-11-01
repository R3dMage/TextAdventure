#include <string>			//For Strings
#include "Creature.h"			//For base class
#include "Player.h"


;using namespace std;




class Orc : public Creature{
public:
	Orc();
	virtual void attack(Player *p2,vector<Item> &pstuff, vector<Item> &stuff,string Map);

}