#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <fstream>			//For file accessing
#include <string>			//For Strings

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#include "item.h"

;
using namespace std;
 
Item::Item()
{
	X = 0;
	Y = 0;
	name = "Ghost";
	map = "field";
	weap = false;
	arm = false;
	keep = false;
	cost = 0;
	type = -1;
}
int Item::getType()
{
	return type;
}
void Item::setType(int T)
{
	type = T;
}
void Item::setarm(bool A)
{
	arm = A;
}
bool Item::getarm()
{
	return arm;
}
void Item::setweap(bool A)
{
	weap = A;
}
bool Item::getweap()
{
	return weap;
}
void Item::setCost(int C)
{
	cost = C;
}
int Item::getCost()
{
	return cost;
}
void Item::setname(string N)
{
	name = N;
}
string Item::getname()
{
	return name;
}
void Item::setmap(string M)
{
	map = M;
}
string Item::getmap()
{
	return map;
}
void Item::setX(int neoX)
{
	X = neoX;
}
int Item::getX()
{
	return X;
}
void Item::setY(int neoY)
{
	Y = neoY;
}
int Item::getY()
{
	return Y;
}
void Item::setkeep(bool K)
{
	keep = K;
}
bool Item::getkeep()
{
	return keep;
}

void Item::display()
{
	switch(type)
	{
	case -1:
		text("                                           ",30,11,white);
		break;
	case 0:
		text("Heals 25 points of life                    ",30,11,white);
		break;
	case 1:
		text("Restores 5 to 10 point of ka",30,11,white);
		break;
	case 2:
		text("Increases Strength 1-5 points              ",30,11,white);
		break;
	case 3:
		text("Increases Mind 1-5 points                  ",30,11,white);
		break;
	case 4:
		text("Heals 75 points of life              ",30,11,white);
		break;
	case 5:
		text("Heals 150 points of life              ",30,11,white);
		break;
	case 6:
		text("Heals all of your life              ",30,11,white);
		break;
	}
	showcost();
}

void Item::showcost()
{
	text("Value: ",1,22,white);
	num(cost,2,23,white);
	cout << " GP  ";
}



		

		