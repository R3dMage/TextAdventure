#ifndef ITEM_H
#define ITEM_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <vector>



using namespace std;

void text(string,int,int,WORD);
void num(int,int,int,WORD);

class Item {
public:
	Item();
	void setname(string N);
	string getname();
	void setmap(string M);
	string getmap();
	void setX(int neoX);
	int getX();
	void setY(int neoY);
	int getY();
	void setCost(int);
	int getCost();
	void setarm(bool);
	bool getarm();
	void setweap(bool);
	bool getweap();
	void setkeep(bool);
	bool getkeep();
	int getType();
	void setType(int);

	virtual void display();

protected:
	string name;
	string map;
	int duration;
	int X;
	int Y;
	int cost;
	int type;
	int time;
	int lifetime;
	bool keep;
	bool weap;
	bool arm;

	void showcost();

};



#endif 