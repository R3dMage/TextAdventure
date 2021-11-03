#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files
#include "Screen.h"

using namespace std;

/*void inv(item& a,item& emty, item& cur1,item& cur2,item& cur3,item& str,item& Vgem)
{

	if(a.getID() == 0){a = emty;}
	else if(a.getID() == 1){a = cur1;}
	else if(a.getID() == 2){a = cur2;}
	else if(a.getID() == 3){a = cur3;}
	else if(a.getID() == 4){a = str;}
	else if(a.getID() == 5){a = Vgem;}
}
*/

void pause()
{
	system("pause");
}

void cls()
{
	system("cls");
}

void DrawEnemyDies(int gold, int Exp, int X, int Y, WORD color)
{
	HANDLE OutputH;
	COORD position = {X, Y};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "You got: " << gold << " GP and " << Exp << " Experience";
}

void DrawPlayerDamage(string name, int damage, int X, int Y, WORD color, WORD color2)
{
	HANDLE OutputH;
	COORD position = {X, Y};
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "                                                             ";

	SetConsoleCursorPosition(OutputH, position);
	
	cout << "You inflicted " <<damage <<" damage with your "<<name << endl;

	COORD pos2 = {X+14, Y};
	SetConsoleTextAttribute(OutputH, color2);
	SetConsoleCursorPosition(OutputH, pos2);

	cout << damage;
}

void MagicDamage(string name, int damage, int X, int Y, WORD color, WORD color2)
{
	HANDLE OutputH;
	COORD position = {X, Y};
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "                                                             ";
	SetConsoleCursorPosition(OutputH, position);

	cout << damage << " points of damage were inflicted by " << name;

	SetConsoleTextAttribute(OutputH, color2);
	SetConsoleCursorPosition(OutputH, position);
	cout << damage;
}


void PlayerCure(int cure, int X, int Y, WORD color, WORD color2)
{
	HANDLE OutputH;
	COORD position = {X, Y};
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "                                           ";

    SetConsoleCursorPosition(OutputH, position);
	cout << "You have been healed " << cure << " points";

	COORD position2 = {X+21, Y};
	SetConsoleTextAttribute(OutputH,color2);
	SetConsoleCursorPosition(OutputH,position2);

	cout << cure;
}

void DrawEnemyDamage(int damage, int X, int Y, WORD color, WORD color2)
{
	HANDLE OutputH;
	COORD position = {X, Y};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "                                                       ";

	SetConsoleCursorPosition(OutputH, position);
	cout << "Your enemy dealt " <<damage <<" damage to you!" <<endl ;

	COORD pos2 = {X+17,Y};
	SetConsoleTextAttribute(OutputH, color2);
	SetConsoleCursorPosition(OutputH, pos2);
	cout <<damage;
}

void DrawStats(string name, string weapon, string armor,int KA, int MKA, int MHP, int HP, int gold, int str, int exp, int level, int X, int Y, WORD color)
{
	HANDLE OutputH;
	COORD position = {X, Y};
	COORD pos2     = {X, Y+1};
	COORD pos3		={X, Y+2};
	COORD pos4		={X, Y+3};
	COORD pos5		={X, Y+4};
	COORD pos6		={X, Y+5};
	COORD pos7		={X, Y+6};
	COORD pos8		={X, Y+7};
	COORD pos9		={X, Y+8};
	COORD pos11		={X, Y+10};
	COORD pos12		={X, Y+11};
	COORD clear		={X+8,Y+1};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);

	if(HP < 10)
	{
		SetConsoleCursorPosition(OutputH, clear);
		cout << "  ";
	}
	if(MHP > 100)
	{
		if(HP < 100)
		{
			SetConsoleCursorPosition(OutputH, clear);
			cout << "   ";
		}
	}

	SetConsoleCursorPosition(OutputH, position);
	cout << name;
	
	SetConsoleCursorPosition(OutputH, pos2);
	cout << "HP: " << HP << "/" << MHP;

	SetConsoleCursorPosition(OutputH, pos3);
	cout << "Ka: " << KA << "/" << MKA;

	SetConsoleCursorPosition(OutputH, pos4);
	cout << gold << " GP";

	SetConsoleCursorPosition(OutputH, pos5);
	//cout << "Str: " << str;

	SetConsoleCursorPosition(OutputH, pos8);
	cout << weapon;

	SetConsoleCursorPosition(OutputH, pos9);
	cout << armor;

	SetConsoleCursorPosition(OutputH,pos11);
	cout << "Lvl: " << level;

	SetConsoleCursorPosition(OutputH,pos12);
	cout << "Xp: " << exp;
}

void DrawEStats(string name, int level, int MHP, int HP, int X, int Y, WORD color)
{
	HANDLE OutputH;
	COORD position = {X, Y};
	COORD pos2     = {X+27, Y};
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, position);
	cout << "                                                ";

	SetConsoleCursorPosition(OutputH, position);
	cout << "Lvl " << level << "  " << name;

	
	SetConsoleCursorPosition(OutputH, pos2);
	cout << HP << "/" << MHP;
}

void DrawStat2(string weapon, string armor, int level, int X, int Y, WORD color)
{
	HANDLE OutputH;
	COORD pos  = {X, Y};
	COORD pos2 = {X+15, Y};
	COORD pos3 = {X+30, Y};
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);
	cout << weapon;

	SetConsoleCursorPosition(OutputH, pos2);
	cout << armor;

	SetConsoleCursorPosition(OutputH, pos3);
	cout << "Level: "<< level;
}

void Number(int num, int X, int Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = {X, Y};

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << num;
}

void DrawCurs(COORD pos, WORD color, char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << curs;
}

bool MoveCurs(COORD &CursPos, bool &bSelect, int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursPos;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			if(CursPos.Y < Ymax)
			{
				CursPos.Y++;
                bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymin;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if(CursPos.Y > Ymin)
			{
				CursPos.Y--;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymax;
				bCursMov = true;
			}
		}

		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			//cout << "-";
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			bSelect = true;
		}
	}

	
	if(bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH,OldCursPos);
		cout << "  ";
		//PlaySound("beep.wav",NULL,SND_FILENAME | SND_ASYNC);
		return true;
		

	}

return false;

}

bool MoveCurs2(COORD &CursPos, bool &bSelect, bool &bEscape, int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursPos;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			if(CursPos.Y < Ymax)
			{
				CursPos.Y++;
                bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymin;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if(CursPos.Y > Ymin)
			{
				CursPos.Y--;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymax;
				bCursMov = true;
			}
		}

		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bEscape = true;
			bCursMov = false;
			bSelect = true;
		}
	}

	
	if(bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH,OldCursPos);
		cout << "  ";
		return true;
		

	}

return false;

}

bool MoveCurs3(COORD &CursPos, bool &bSelect, bool &bEscape, int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = CursPos;
	DWORD Events = 0;
	HANDLE hInput;
	bool bCursMov = false;
	int bKeyDown = 0;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	ReadConsoleInput(hInput, &InputRecord,1,&Events);
	bKeyDown = InputRecord.Event.KeyEvent.bKeyDown;
	if(InputRecord.EventType == KEY_EVENT && bKeyDown)
	{
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
		{
			if(CursPos.Y < Ymax)
			{
				CursPos.Y++;
                bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymin;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if(CursPos.Y > Ymin)
			{
				CursPos.Y--;
				bCursMov = true;
			}
			else
			{
				CursPos.Y = Ymax;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
		{
			if(CursPos.X == 51)
			{
				CursPos.X += 10;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
		{
			if(CursPos.X == 61)
			{
				CursPos.X -= 10;
				bCursMov = true;
			}
		}

		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			bSelect = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bEscape = true;
			bCursMov = false;
			bSelect = true;
		}
	}

	
	if(bCursMov)
	{
		HANDLE	OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(OutputH,OldCursPos);
		cout << "  ";
		return true;
		

	}

return false;

}
/*
void EndScreen()
{
	text("",13,23,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
*/

void pause2(int X)
{
	Sleep(X);
}
/*
void SaveGame()
{
	text("Saving game",13,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int X = 0;
	do
	{
		text("   ",24,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(250);
		text("",24,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
		X++;
	}while(X < 5);
}

void LoadGame()
{
	text("Loading game",13,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int X = 0;
	do
	{
		text("   ",25,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(250);
		text("",25,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
		X++;
	}while(X < 5);
}
*/

void ClrMagic()
{
	text("                                                       ",13,11,FOREGROUND_BLUE);	
	text("                        ",50,14,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("                        ",50,15,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("                        ",50,16,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("                        ",50,17,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	text("                        ",50,18,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//text("|                      |",50,19,blue);
	//text("|                      |",50,20,blue);
	text("                        ",50,19,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void cls2()
{
	text("                                         ",13,11,FOREGROUND_BLUE);
	text("                                         ",13,12,FOREGROUND_BLUE);
	text("                                         ",13,13,FOREGROUND_BLUE);
	text("                                         ",13,14,FOREGROUND_BLUE);
	text("                                         ",13,15,FOREGROUND_BLUE);
	text("                                         ",13,16,FOREGROUND_BLUE);
	text("                                         ",13,17,FOREGROUND_BLUE);
	text("                                         ",13,18,FOREGROUND_BLUE);
	text("                                         ",13,19,FOREGROUND_BLUE);
	text("                                         ",13,20,FOREGROUND_BLUE);
	text("                                         ",13,21,FOREGROUND_BLUE);
	text("                                         ",13,22,FOREGROUND_BLUE);
	text("                                         ",13,23,FOREGROUND_BLUE);
	text("                                         ",15,11,FOREGROUND_BLUE);
	text("                                         ",15,12,FOREGROUND_BLUE);
	text("                                         ",15,13,FOREGROUND_BLUE);
	text("                                         ",15,14,FOREGROUND_BLUE);
	text("                                         ",15,15,FOREGROUND_BLUE);
	text("                                         ",13,2,FOREGROUND_BLUE);
	text("                                         ",13,3,FOREGROUND_BLUE);
	text("                                         ",13,4,FOREGROUND_BLUE);
	text("                                         ",13,5,FOREGROUND_BLUE);
	text("                                         ",13,6,FOREGROUND_BLUE);
	text("                                         ",13,7,FOREGROUND_BLUE);


}

void DrawStatus(string name, int HP, int MHP, int gold, int str, int mind,int evd,int kills,int lev, int exp, int nxtlev)
{
	text("Name:   ",13,11,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << name;
	text("HP:     ",13,12,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
	cout << HP << "/" << MHP;
	text("Str:    ",13,13,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << str;
	text("Mind:   ",13,14,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << mind;
	text("%Evade: ",13,15,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << evd;
	text("Kills:  ",13,16,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << kills;
	text("Level:  ",31,12,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << lev;
	text("Exp:    ",31,13,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << exp;
	text("NxtLev: ",31,14,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << nxtlev;
	text("Gold:   ",31,15,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << gold;
}


string rotate(string pStr)
{
	string rStr;
	rStr = pStr.substr(1,pStr.length()-1);
	return rStr;
}
/*
creature loadGuy(string name)
{
	#define red  FOREGROUND_RED | FOREGROUND_INTENSITY
	creature guy;
	int num;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool bVal;
	bool nameFound = false;
	ifstream fin;
	fin.open("enemies.txt");

	if(fin.fail())
	{  
		text("ERROR: could not find enemy file",13,11,red);
		EndScreen();
		pause();
		exit(0);
	}


	do
	{
		fin >> szName;
		if(name == szName)
		{
			nameFound = true;
			fin >> szWord;
			getline(fin,temp);
			guy.setname(rotate(temp));
			fin >> szWord >> num;
			guy.setdamage(num);
			fin >> szWord >> num;
			guy.setdamMod(num);
			fin >> szWord >> num;
			guy.setmhp(num);
			fin >> szWord >> num;
			guy.setevade(num);
			fin >> szWord >> num;
			guy.setgold(num);
			fin >> szWord >> num;
			guy.setexp(num);
			fin >> szWord >> num;
			guy.setitem(num);
			fin >> szWord >> bVal;
			guy.setsteal(bVal);
			fin >> szWord >> bVal;
			guy.setlsteal(bVal);
			fin >> szWord >> bVal;
			guy.setdragon(bVal);
		}
		else
		{
			fin >> szWord;
			getline(fin,szWord2);
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
		}
	}while(!nameFound);
	fin.close();
	return guy;
}

weapon loadWeapon(string name)
{
	weapon holder;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	bool bVal;
	int num;
	ifstream fin;
	fin.open("weapon.def");

	do
	{
		fin >> szName;
		if(name == szName)
		{
			nameFound = true;
			fin >> szWord;
			getline(fin,temp);
			holder.setname(rotate(temp));
			fin >> szWord >> num;
			holder.setdamage(num);
			fin >> szWord >> num;
			holder.setdamMod(num);
			fin >> szWord >> bVal; 
			holder.set2hits(bVal);
			fin >> szWord >> bVal;
			holder.setlsteal(bVal);
			fin >> szWord >> bVal;
			holder.setflare(bVal);
		}
		else
		{
			fin >> szWord;
			getline(fin,szWord2);
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;		
		}
	}while(!nameFound);
	return holder;
}
item loadItem(string name)
{
	item holder;
	string szName;
	string szWord;
	string szWord2;
	string temp;
	bool nameFound = false;
	bool bVal;
	int num;
	ifstream fin;
	fin.open("item.def");
		
	do
	{
		fin >> szName;
		if(name == szName)
		{
			nameFound = true;
			fin >> szWord;
			getline(fin,temp);
			holder.setname(rotate(temp));
			getline(fin,temp);
			holder.seteffect(rotate(temp));
			fin >> szWord >> num;
			holder.setDamage(num);
			fin >> szWord >> num;
			holder.setDamMod(num);
			fin >> szWord >> num;
			holder.setID(num);
			fin >> szWord >> bVal; 
			holder.setKeep(bVal);
			fin >> szWord >> bVal;
			holder.setUsed(bVal);
		}
		else
		{
			fin >> szWord;
			getline(fin,szWord2);
			fin >> szWord;
			getline(fin,szWord2);
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;
			fin >> szWord >> szWord2;		
		}		
	}while(!nameFound);
	return holder;
}


void Einv(int a,item& b,item& emty, item& cur1,item& cur2,item& cur3,item& str,item& Vgem)
{

	if(a == 0){b = emty;}
	else if(a == 1){b = cur1;}
	else if(a == 2){b = cur2;}
	else if(a == 3){b = cur3;}
	else if(a == 4){b = str;}
	else if(a == 5){b = Vgem;}
}
*/

//void Einv(int a,item& b,item& emty, item& cur1,item& cur2,item& cur3,item& str,item& Vgem);
string rotate();
//weapon loadWeapon(string);
//creature loadGuy(string);
//void inv(item);
void LoadGame();
void SaveGame();
void EndScreen();
void pause();
void pause2(int);
void cls();
void ClrMagic();
void DrawEStats(string name, int level, int MHP, int HP, int X, int Y, WORD color);
void DrawPlayerDamage(string, int  , int  , int  , WORD, WORD  );
void MagicDamage(string , int , int , int , WORD, WORD );
void PlayerCure(int , int , int , WORD , WORD );
void DrawEnemyDamage(int  , int  , int  , WORD, WORD  );
void DrawStatus(string, int, int, int, int, int, int, int,int,int,int);
void DrawStats(string,string,string,int, int,int,int,int,int,int,int,int,int,WORD);
void DrawStat2(string, string, int, int, int, WORD);
void DrawEnemyDies(int, int, int, int, WORD);
bool MoveCurs2(COORD &CursPos, bool &bSelect, bool &bEscape, int Ymin, int Ymax);
bool MoveCurs(COORD &CursPos, bool &bSelect,int Ymin, int Ymax);
void Number(int num, int X, int Y, WORD color);
void DrawCurs(COORD pos, WORD color);
void cls2();