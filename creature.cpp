#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include "creature.h"




#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY

creature::creature()
{
	setdamage(1);
	setdamMod(1);
	setmhp(10);
	sethp(10);
	setevade(5);
	setexp(1);
	setgold(0);
	setname("ProblemLoading");
	def = 0;
	ka=mka=  0;
	state = 0;
	talkTo = false;
	runAway = false;
	dontmove = false;
	bant = false;
	type = "normal";
	weakness = "neutral";
	map = "none";
	music = "battle.mp3";
}

void creature::banter()
{
}

void creature::info()
{
	#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
	text(name,13,1,white);
	text("Level: ",13,2,white);
	text("HP:    ",13,3,white);
	text("Ka:    ",13,4,white);
	num(level,20,2,white);
	num(hp,17,3,white);
	num(ka,17,4,white);


}

void creature::attack(Player *p2,vector<item*> &pstuff,vector<item*> &stuff,string Map)
{
	int Damage;
	armor *arm;

	arm = p2->getarmor();
	Damage = rand()% damage + damMod;
	Damage -= arm->getdefMod();
	if(Damage < 0)
		Damage = 0;
	p2->setHP(p2->getHP()-Damage);
	text(getname(),13,11,white);
	cout << " attacks you!";
	Sleep(p2->getPause());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	creature::dam(Damage);
	p2->info();
	clear();
}

void creature::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(gold,20,11,green);
	num(exp,20,12,green);
	p2->setKills(p2->getKills() + 1);
	p2->setgold(p2->getgold() + gold);
	p2->setexp(p2->getexp() + exp);
	p2->info();
	text("",79,23,white);
	Sleep(3000);

}
string creature::getweakness()
{
	return weakness;
}
string creature::gettype()
{
	return type;
}
void creature::setdamage(int num)
{
	if(num < 0){num = 0;}
	damage = num;
}
void creature::setdamMod(int num)
{
	if(num < 0){num = 0;}
	damMod = num;
}
void creature::setevade(int num)
{
	if(num < 0){num = 0;}
	evade = num;
}
void creature::setexp(int num)
{
	if(num < 0){num = 0;}
	exp = num;
}
void creature::setgold(int num)
{
	if(num < 0){num = 0;}
	gold = num;
}
void creature::sethp(int num)
{
	if(num < 0){num = 0;}
	if(num > mhp){num = mhp;}
	hp = num;
}
void creature::setlevel(int num)
{
	if(num < 0){num = 0;}
	level = num;
}
void creature::setmhp(int num)
{
	if(num < 0){num = 0;}
	mhp = num;
	hp = mhp;
}
void creature::setX(int num)
{
	if(num < 1)
		num = 1;
	X = num;
}
void creature::setY(int num)
{
	if(num < 1)
		num = 1;
	Y = num;
}
void creature::setname(string szName)
{
	name = szName;
}
void creature::setka(int N)
{
	ka = N;
	if(ka > mka)
		ka = mka;
}
int creature::getdamage()
{
	return damage;
}
int creature::getdamMod()
{
	return damMod;
}
int creature::getdef()
{
	return def;
}
int creature::getevade()
{
	return evade;
}
int creature::getexp()
{
	return exp;
}
int creature::getgold()
{
	return gold;
}
int creature::gethp()
{
	return hp;
}
int creature::getmhp()
{
	return mhp;
}
int creature::getlevel()
{
	return level;
}
int creature::getX()
{
	return X;
}
int creature::getY()
{
	return Y;
}
string creature::getname()
{
	return name;
}
void creature::setTalkTo(bool T)
{
	talkTo = T;
}
bool creature::getTalkTo()
{
	return talkTo;
}
void creature::setrunAway(bool R)
{
	runAway = R;
}
bool creature::getrunAway()
{
	return runAway;
}
bool creature::getdontmove()
{
	return dontmove;
}
void creature::setstate(int N)
{
	state = N;
}
int creature::getstate()
{
	return state;
}
int creature::getmka()
{
	return mka;
}
int creature::getka()
{
	return ka;
}
int creature::getmagdef()
{
	return magdef;
}
void creature::setmagdef(int M)
{
}
void creature::setmap(string M)
{
	map = M;
}
string creature::getmap()
{
	return map;
}
void creature::setdontmove(bool B)
{
	dontmove = B;
}
void creature::DrawCurs(COORD pos, WORD color, char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << curs;
}

bool creature::MoveCurs(COORD &CursPos,bool &bSelect,int Ymin, int Ymax)
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
		//text("  ",OldCursPos.X, OldCursPos.Y,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		//PlaySound("beep.wav",NULL,SND_FILENAME | SND_ASYNC);
		return true;
	}
return false;

}



void creature::dam(int D)
{
	int X = 13;
	while(X < 50)
	{
		text("                                                            ",13,9,green);
		num(D,X,9,FOREGROUND_RED | FOREGROUND_INTENSITY);
		Sleep(50);
		X++;
		text("   ",X-1,9,FOREGROUND_RED);
	}
}
void creature::cure(int D)
{
	int X = 13;
	while(X < 50)
	{
		num(D,X,9,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(50);
		X++;
		text("   ",X-1,9,FOREGROUND_GREEN);
	}
}

bool creature::dropItem()
{ return false; }


item* creature::token(string Map)
{ item *flag = new item; return flag;}

void creature::loadPos(int X, int Y)
{
	if(!dontmove)
	{
		int Rx = rand()%X + 1;
		int Ry = rand()%Y + 1;
		setX(Rx);
		setY(Ry); 
	}
	else
	{
		setX(X);
		setY(Y);
	}
}

bool creature::talkto(Player *p2)
{
	return false;
}
char * creature::getMusic()
{
	return music;
}
void creature::slowDisp(string szText)
{
	unsigned int i;

	for(i=0;i < szText.size();i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}






















