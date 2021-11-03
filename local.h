#ifndef LOCAL_H
#define LOCAL_H

#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings

using namespace std;

//=====================================================================================================
// A local object is designed to get the summary for the surrounding locations and display them
//=====================================================================================================
class Surroundings {
public:
	Surroundings();
	void SetPositionX(int);
	int GetPositionX();
	void SetPositionY(int);
	int GetPositionY();
	void SetScript(string);
	string GetScript();
	void Setup(string);

private:
	int PositionX;
	int PositionY;
	string Script;
};
#endif