#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include "Creature.h"




#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY

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

void Creature::Banter()
{
}

void Creature::DisplayInfo()
{
	#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
	text(Name,13,1,white);
	text("Level: ",13,2,white);
	text("HP:    ",13,3,white);
	text("Ka:    ",13,4,white);
	num(Level,20,2,white);
	num(HitPoints,17,3,white);
	num(Ka,17,4,white);


}

void Creature::Attack(Player *player,vector<Item*> &playerInventory,vector<Item*> &worldItems,string map)
{
	int Damage;
	Armor *arm;

	arm = player->GetArmor();
	Damage = rand()% Damage + DamageModifier;
	Damage -= arm->GetDefenseModifier();
	if(Damage < 0)
		Damage = 0;
	player->SetHitPoints(player->GetCurrentHitPoints()-Damage);
	text(GetName(),13,11,white);
	cout << " attacks you!";
	Sleep(player->GetPauseDuration());
	text("Enemies Damage: ",13,11,white);
	cout << Damage << "              ";
	Creature::DisplayDamage(Damage);
	player->DisplayInfo();
	clear();
}

void Creature::Win(Player *player)
{
	clear();
	text("After every enemy dies you get stuff!!!",13,9,green);
	text("Gold: ",13,11,green);
	text("Exp : ",13,12,green);
	num(Gold,20,11,green);
	num(Experience,20,12,green);
	player->SetTotalKills(player->GetTotalKills() + 1);
	player->SetGold(player->GetGold() + Gold);
	player->SetExperience(player->GetExperience() + Experience);
	player->DisplayInfo();
	text("",79,23,white);
	Sleep(3000);

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
	Damage = num;
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
	return Damage;
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
void Creature::DrawCursor(COORD position, WORD color, char cursor)
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



void Creature::DisplayDamage(int D)
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
void Creature::DisplayCure(int D)
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

bool Creature::DroppedItem()
{ return false; }


Item* Creature::Token(string Map)
{ Item *flag = new Item; return flag;}

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
char * Creature::GetMusic()
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






















