#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include "Creature.h"

Creature::Creature()
{
	SetDamage(1);
	SetDamageModifier(1);
	SetMaxHitPoints(10);
	SetHitPoints(10);
	SetEvade(5);
	SetExperience(1);
	SetGold(0);
	SetName("ProblemLoading");
	Defense = 0;
	Ka=MaxKa=  0;
	State = 0;
	CanTalkTo = false;
	RunAway = false;
	DontMove = false;
	bant = false;
	Type = "normal";
	Weakness = "neutral";
	Map = "none";
	Music = "battle.mp3";
}

vector<string> Creature::Banter()
{
	return vector<string>();
}

void Creature::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	Armor *arm;

	arm = player->GetArmor();
	damage = rand()% BaseDamage + DamageModifier;
	damage -= arm->GetDefenseModifier();
	if(damage < 0)
		damage = 0;
	player->SetHitPoints(player->GetCurrentHitPoints()-damage);
	text(GetName(),13,11,white);
	cout << " attacks you!";
	Sleep(player->GetPauseDuration());
	text("Enemies Damage: ",13,11,white);
	cout << damage << "              ";
	Creature::DisplayDamage(damage);
}

void Creature::Win(Player *player)
{
}
string Creature::GetWeakness()
{
	return Weakness;
}
string Creature::GetType()
{
	return Type;
}
void Creature::SetDamage(int num)
{
	if(num < 0){num = 0;}
	BaseDamage = num;
}
void Creature::SetDamageModifier(int num)
{
	if(num < 0){num = 0;}
	DamageModifier = num;
}
void Creature::SetEvade(int num)
{
	if(num < 0){num = 0;}
	Evade = num;
}
void Creature::SetExperience(int num)
{
	if(num < 0){num = 0;}
	Experience = num;
}
void Creature::SetGold(int num)
{
	if(num < 0){num = 0;}
	Gold = num;
}
void Creature::SetHitPoints(int num)
{
	if(num < 0){num = 0;}
	if(num > MaxHP){num = MaxHP;}
	HitPoints = num;
}
void Creature::SetLevel(int num)
{
	if(num < 0){num = 0;}
	Level = num;
}
void Creature::SetMaxHitPoints(int num)
{
	if(num < 0){num = 0;}
	MaxHP = num;
	HitPoints = MaxHP;
}
void Creature::SetX(int num)
{
	if(num < 1)
		num = 1;
	X = num;
}
void Creature::SetY(int num)
{
	if(num < 1)
		num = 1;
	Y = num;
}
void Creature::SetName(string szName)
{
	Name = szName;
}
void Creature::SetKa(int N)
{
	Ka = N;
	if(Ka > MaxKa)
		Ka = MaxKa;
}
int Creature::GetDamage()
{
	return BaseDamage;
}
int Creature::GetDamageModifier()
{
	return DamageModifier;
}
int Creature::GetDefense()
{
	return Defense;
}
int Creature::GetEvade()
{
	return Evade;
}
int Creature::GetExperience()
{
	return Experience;
}
int Creature::GetGold()
{
	return Gold;
}
int Creature::GetHitPoints()
{
	return HitPoints;
}
int Creature::GetMaxHitPoints()
{
	return MaxHP;
}
int Creature::GetLevel()
{
	return Level;
}
int Creature::GetX()
{
	return X;
}
int Creature::GetY()
{
	return Y;
}
string Creature::GetName()
{
	return Name;
}
void Creature::SetTalkTo(bool T)
{
	CanTalkTo = T;
}
bool Creature::GetTalkTo()
{
	return CanTalkTo;
}
void Creature::SetRunAway(bool R)
{
	RunAway = R;
}
bool Creature::GetRunAway()
{
	return RunAway;
}
bool Creature::GetDontMove()
{
	return DontMove;
}
Greeting Creature::GetGreeting(Player* player)
{
	return Greeting(string(), string(), false);
}
void Creature::SetState(int N)
{
	State = N;
}
int Creature::GetState()
{
	return State;
}
int Creature::GetMaxKa()
{
	return MaxKa;
}
int Creature::GetKa()
{
	return Ka;
}
int Creature::GetMagicDefense()
{
	return MagicDefense;
}
void Creature::SetMagicDefense(int M)
{
}
void Creature::SetMap(string M)
{
	Map = M;
}
string Creature::GetMap()
{
	return Map;
}
void Creature::SetDontMove(bool B)
{
	DontMove = B;
}
void Creature::DrawCursor(COORD position, WORD color, unsigned char cursor)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,position);

	cout << cursor;
}

bool Creature::MoveCursor(COORD &cursorPosition,bool &wasSelected,int Ymin, int Ymax)
{
	INPUT_RECORD InputRecord;
	COORD OldCursPos = cursorPosition;
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
			if(cursorPosition.Y < Ymax)
			{
				cursorPosition.Y++;
                bCursMov = true;
			}
			else
			{
				cursorPosition.Y = Ymin;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
		{
			if(cursorPosition.Y > Ymin)
			{
				cursorPosition.Y--;
				bCursMov = true;
			}
			else
			{
				cursorPosition.Y = Ymax;
				bCursMov = true;
			}
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			bCursMov = false;
			//cout << "-";
			wasSelected = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			wasSelected = true;
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

bool Creature::DroppedItem()
{ return false; }


string Creature::Token()
{ return string(); }

void Creature::LoadPosition(int X, int Y)
{
	if(!DontMove)
	{
		int Rx = rand()%X + 1;
		int Ry = rand()%Y + 1;
		SetX(Rx);
		SetY(Ry); 
	}
	else
	{
		SetX(X);
		SetY(Y);
	}
}

bool Creature::TalkTo(Player *player)
{
	return false;
}
string Creature::GetMusic()
{
	return Music;
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

void Creature::clr()
{
	int Y = 11;
	while (Y < 24)
	{
		text("                                                                 ", 13, Y, FOREGROUND_BLUE);
		Y++;
	}
}

void Creature::text(string szText, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << szText;
}

void Creature::num(int num, short X, short Y, WORD color)
{
	HANDLE OutputH;
	COORD pos = { X, Y };

	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	SetConsoleCursorPosition(OutputH, pos);

	cout << num;
}

void Creature::DisplayDamage(int amount)
{
	DisplayHitPointUpdate(amount, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void Creature::DisplayCure(int amount)
{
	DisplayHitPointUpdate(amount, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Creature::DisplayHitPointUpdate(int amount, WORD color)
{
	int X = 13;
	while (X < 50)
	{
		num(amount, X, 9, color);
		Sleep(50);
		X++;
		text("   ", X - 1, 9, color);
	}
}