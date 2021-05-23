#include <string>			//For Strings
#include "creature.h"			//For base class
#include "player.h"


;using namespace std;




class Orc : public creature{
public:
	Orc();
	virtual void attack(player *p2,vector<item> &pstuff, vector<item> &stuff,string Map);

}