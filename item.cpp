#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <fstream>			//For file accessing
#include <string>			//For Strings

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#include "item.h"

;
using namespace std;
 
item::item()
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
int item::getType()
{
	return type;
}
void item::setType(int T)
{
	type = T;
}
void item::setarm(bool A)
{
	arm = A;
}
bool item::getarm()
{
	return arm;
}
void item::setweap(bool A)
{
	weap = A;
}
bool item::getweap()
{
	return weap;
}
void item::setCost(int C)
{
	cost = C;
}
int item::getCost()
{
	return cost;
}
void item::setname(string N)
{
	name = N;
}
string item::getname()
{
	return name;
}
void item::setmap(string M)
{
	map = M;
}
string item::getmap()
{
	return map;
}
void item::setX(int neoX)
{
	X = neoX;
}
int item::getX()
{
	return X;
}
void item::setY(int neoY)
{
	Y = neoY;
}
int item::getY()
{
	return Y;
}
void item::setkeep(bool K)
{
	keep = K;
}
bool item::getkeep()
{
	return keep;
}

void item::display()
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

void item::showcost()
{
	text("Value: ",1,22,white);
	num(cost,2,23,white);
	cout << " GP  ";
}



		

		