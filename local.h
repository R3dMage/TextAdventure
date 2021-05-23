#ifndef LOCAL_H
#define LOCAL_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
;
using namespace std;
//=====================================================================================================
// A local object is designed to get the summary for the surrounding locations and display them
//=====================================================================================================
class local {
public:
	local();
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setscript(string);
	string getscript();
	void setup(string);

private:
	int X;
	int Y;
	string script;
}

#endif
