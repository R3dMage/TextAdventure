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
	HasBanter = false;
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
	display->DisplayTextAndPause(GetName() + " attacks you!", 13, 11, white);
	display->DisplayText("Enemies Damage: ",13,11,white);
	cout << damage << "              ";
	display->DisplayDamage(damage);
}

void Creature::Win(Player *player, TextDisplay* display)
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
bool Creature::GetHasBanter()
{
	return HasBanter;
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

void Creature::Replenish()
{
	HitPoints = MaxHP;
	Ka = MaxKa;
}

bool Creature::TalkTo(Player *player)
{
	return false;
}
string Creature::GetMusic()
{
	return Music;
}