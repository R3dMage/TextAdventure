#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include "Creature.h"




#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY

Creature::Creature()
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

void Creature::banter()
{
}

void Creature::info()
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

void Creature::attack(Player *p2,vector<Item*> &pstuff,vector<Item*> &stuff,string Map)
{
	int Damage;
	Armor *arm;

	arm = p2->GetArmor();
	Damage = rand()% damage + damMod;
	Damage -= arm->GetDefenseModifier();
	if(Damage < 0)
		Damage = 0;
	p2->SetHitPoints(p2->GetCurrentHitPoints()-Damage);
	text(getname(),13,11,white);
	cout << " attacks you!";
	Sleep(p2->GetPauseDuration());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	Creature::dam(Damage);
	p2->DisplayInfo();
	clear();
}

void Creature::win(Player *p2)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(gold,20,11,green);
	num(exp,20,12,green);
	p2->SetTotalKills(p2->GetTotalKills() + 1);
	p2->SetGold(p2->GetGold() + gold);
	p2->SetExperience(p2->GetExperience() + exp);
	p2->DisplayInfo();
	text("",79,23,white);
	Sleep(3000);

}
string Creature::getweakness()
{
	return weakness;
}
string Creature::gettype()
{
	return type;
}
void Creature::setdamage(int num)
{
	if(num < 0){num = 0;}
	damage = num;
}
void Creature::setdamMod(int num)
{
	if(num < 0){num = 0;}
	damMod = num;
}
void Creature::setevade(int num)
{
	if(num < 0){num = 0;}
	evade = num;
}
void Creature::setexp(int num)
{
	if(num < 0){num = 0;}
	exp = num;
}
void Creature::setgold(int num)
{
	if(num < 0){num = 0;}
	gold = num;
}
void Creature::sethp(int num)
{
	if(num < 0){num = 0;}
	if(num > mhp){num = mhp;}
	hp = num;
}
void Creature::setlevel(int num)
{
	if(num < 0){num = 0;}
	level = num;
}
void Creature::setmhp(int num)
{
	if(num < 0){num = 0;}
	mhp = num;
	hp = mhp;
}
void Creature::setX(int num)
{
	if(num < 1)
		num = 1;
	X = num;
}
void Creature::setY(int num)
{
	if(num < 1)
		num = 1;
	Y = num;
}
void Creature::setname(string szName)
{
	name = szName;
}
void Creature::setka(int N)
{
	ka = N;
	if(ka > mka)
		ka = mka;
}
int Creature::getdamage()
{
	return damage;
}
int Creature::getdamMod()
{
	return damMod;
}
int Creature::getdef()
{
	return def;
}
int Creature::getevade()
{
	return evade;
}
int Creature::getexp()
{
	return exp;
}
int Creature::getgold()
{
	return gold;
}
int Creature::gethp()
{
	return hp;
}
int Creature::getmhp()
{
	return mhp;
}
int Creature::getlevel()
{
	return level;
}
int Creature::getX()
{
	return X;
}
int Creature::getY()
{
	return Y;
}
string Creature::getname()
{
	return name;
}
void Creature::setTalkTo(bool T)
{
	talkTo = T;
}
bool Creature::getTalkTo()
{
	return talkTo;
}
void Creature::setrunAway(bool R)
{
	runAway = R;
}
bool Creature::getrunAway()
{
	return runAway;
}
bool Creature::getdontmove()
{
	return dontmove;
}
void Creature::setstate(int N)
{
	state = N;
}
int Creature::getstate()
{
	return state;
}
int Creature::getmka()
{
	return mka;
}
int Creature::getka()
{
	return ka;
}
int Creature::getmagdef()
{
	return magdef;
}
void Creature::setmagdef(int M)
{
}
void Creature::setmap(string M)
{
	map = M;
}
string Creature::getmap()
{
	return map;
}
void Creature::setdontmove(bool B)
{
	dontmove = B;
}
void Creature::DrawCurs(COORD pos, WORD color, char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << curs;
}

bool Creature::MoveCurs(COORD &CursPos,bool &bSelect,int Ymin, int Ymax)
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



void Creature::dam(int D)
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
void Creature::cure(int D)
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

bool Creature::dropItem()
{ return false; }


Item* Creature::token(string Map)
{ Item *flag = new Item; return flag;}

void Creature::loadPos(int X, int Y)
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

bool Creature::talkto(Player *p2)
{
	return false;
}
char * Creature::getMusic()
{
	return music;
}
void Creature::slowDisp(string szText)
{
	unsigned int i;

	for(i=0;i < szText.size();i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}






















