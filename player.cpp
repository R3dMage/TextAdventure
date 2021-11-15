#include "Player.h"

using namespace std;

Player::Player()
{
	MaxHP =	25;
	HP =	25;
	TotalKills =	0;
	Experience =	0;
	PositionX =		3;
	PositionY =		2;
	Level =	1;
	ExperienceNeededForNextLevel = 50;
	Evade = 5;
	Gold =  (rand()%25 + 25) * 8;
	Strength =	rand()%5 + 5;
	Mind =	rand()%5 + 5;
	Ka =	0;
	MaxKa =	Ka;
	HasSpells =	false;
	MemberHasJoined =	false;
	IsPoisoned =	false;
	IsAsleep =		false;
	Invisible = false;
	IsInFight = false;
	MagicStatus = 0;
	PauseDuration = 1500;
	RaceReactions.Elf =		2;
	RaceReactions.Human =	3;
	RaceReactions.Orc =		1;
	RaceKillCounts.ElfKillCount = 0;
	RaceKillCounts.HumanKillCount = 0;
	RaceKillCounts.OrcKillCount = 0;
	PlotEventStates.Priest1 = false;
	PlotEventStates.Priest2 = false;
	PlotEventStates.Priest3 = false;
	PlotEventStates.Priest4 = false;
	PlotEventStates.Monk = false;
	PlotEventStates.GreenDragon = false;
	PlotEventStates.BlueDragon = false;
	PlotEventStates.RedDragon = false;
	PlotEventStates.Start = false;
	IsLoaded = false;

	Armor armor;
	EquippedArmor = &armor;

	Weapon weapon;
	EquippedWeapon = &weapon;
}

void Player::SetArmor(Armor *newArmor)
{
	EquippedArmor = newArmor;
}
void Player::SetWeapon(Weapon *newWeapon)
{
	EquippedWeapon = newWeapon;
}
void Player::SetName(string name)
{
	Name = name;
}
void Player::SetExperience(int experience)
{
	Experience = experience;
}
void Player::SetGold(int gold)
{
	Gold = gold;
}
void Player::SetHitPoints(int hitPoints)
{
	if(hitPoints > MaxHP)
		hitPoints = MaxHP;
	HP = hitPoints;
}
void Player::SetMaxHitPoints(int maxHitPoints)
{
	MaxHP = maxHitPoints;
}
void Player::SetKa(int ka)
{
	if(ka > MaxKa)
		ka = MaxKa;
	Ka = ka;
}
void Player::SetMaxKa(int maxKa)
{
	MaxKa = maxKa;
}
void Player::SetLevel(int level)
{
	Level = level;
}
void Player::SetMind(int mind)
{
	Mind = mind;
}
void Player::SetStrength(int strength)
{
	Strength = strength;
}
void Player::SetPositionX(int newX)
{
	if(newX == 0)
		newX = 1;
	PositionX = newX;
}
void Player::SetPositionY(int newY)
{
	if(newY == 0)
		newY = 1;
	PositionY = newY;
}
void Player::SetExperienceNeeded(int experience)
{
	ExperienceNeededForNextLevel = experience;
}
void Player::SetEvade(int evd)
{
	Evade = evd;
}
void Player::SetTotalKills(int kills)
{
	TotalKills = kills		;
}

Armor* Player::GetArmor()
{
	return EquippedArmor;
}
Weapon* Player::GetWeapon()
{
	return EquippedWeapon;
}
string Player::GetName()
{
	return Name;
}
int Player::GetExperience()
{
	return Experience;
}
int Player::GetGold()
{
	return Gold;
}
int Player::GetCurrentHitPoints()
{
	return HP;
}
int Player::GetMaxHitPoints()
{
	return MaxHP;
}
int Player::GetCurrentKa()
{
	return Ka;
}
int Player::GetMaxKa()
{
	return MaxKa;
}
int Player::GetLevel()
{
	return Level;
}
int Player::GetMind()
{
	return Mind;
}
int Player::GetStrength()
{
	return Strength;
}
int Player::GetPositionX()
{
	return PositionX;
}
int Player::GetPositionY()
{
	return PositionY;
}
int Player::GetExperienceForNextLevel()
{
	return ExperienceNeededForNextLevel;
}
int Player::GetEvade()
{
	return Evade;
}
int Player::GetTotalKills()
{
	return TotalKills;
}
void Player::SetReactionElf(int reaction)
{	
	RaceReactions.Elf = reaction;	
}
int Player::GetReactionElf()
{
	return RaceReactions.Elf;
}
void Player::SetReactionHuman(int reaction)
{	
	RaceReactions.Human = reaction;
}
int Player::GetReactionHuman()
{
	return RaceReactions.Human;
}
void Player::SetReactionOrc(int reaction)
{	
	RaceReactions.Orc = reaction;
}
int Player::GetReactionOrc()
{
	return RaceReactions.Orc;
}
int Player::GetMagicStatus()
{
	return MagicStatus;
}
void Player::SetMagicStatus(int magicStatus)
{
	MagicStatus = magicStatus;
}
bool Player::HasLearnedSpells()
{
	return HasSpells;
}
void Player::SetHasSpells(bool hasSpells)
{
	if(hasSpells)
	{
		HasSpells = hasSpells;		// When a player gets spells he gets to have magic
		MaxKa = Mind / 2;      // power, ka. Mind / 2 is that starting point for it.
		Ka = MaxKa;
	}
	else
		HasSpells = hasSpells;
}
void Player::SetMemberHasJoined(bool memberHasJoined)
{
	MemberHasJoined = memberHasJoined;
}
bool Player::GetMemberHasJoined()
{
	return MemberHasJoined;
}
bool Player::GetIsPoisoned()
{
	return IsPoisoned;
}
void Player::SetIsPoisoned(bool poisoned)
{
	IsPoisoned = poisoned;
}
void Player::SetIsLoaded(bool loaded)
{
	IsLoaded = loaded;
}
bool Player:: GetIsLoaded()
{
	return IsLoaded;
}
void Player::SetIsAsleep(bool asleep)
{
	IsAsleep = asleep;
}
bool Player::GetIsAsleep()
{
	return IsAsleep;
}
void Player::SetIsInvisible(bool invisible)
{
	Invisible = invisible;
}
bool Player::GetIsInvisible()
{
	return Invisible;
}

bool Player::ReachedNextLevel()
{
	if(Experience >= ExperienceNeededForNextLevel)
		return true;
	else
		return false;
}

void Player::IncreaseLevel()
{
	srand(static_cast<unsigned int>(GetTickCount64()));
	double Num1;
	SetLevel(GetLevel() + 1);
	if(GetLevel() < 5)
	{
		Num1 = rand() % 10 + 11;
		SetMaxHitPoints(GetMaxHitPoints() + static_cast<int>(Num1));
	}
	else
	{
		Num1 = rand() % 10 + 20;
		Num1 = Num1 / 100;
		SetMaxHitPoints(GetMaxHitPoints() + (GetMaxHitPoints() * static_cast<int>(Num1)));
	}
	Evade += 1;
	Num1 = rand()% 3 + 2;
	SetStrength(GetStrength() + static_cast<int>(Num1));
	Num1 = rand()% 4 + 1;
	SetMind(GetMind() + static_cast<int>(Num1));
	Num1 = rand()% (GetMind()/2) + 1;
	SetMaxKa(GetMaxKa() + static_cast<int>(Num1));
	ExperienceNeededForNextLevel = Level * Level * 50;
}