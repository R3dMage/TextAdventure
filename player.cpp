#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For loading/saving
#include "player.h"

using namespace std;
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

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
	PauseDuration = 1500;
	SetWeapon(loadWeapon("Dagger"));
	SetArmor(loadArmor("Clothes"));
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
	MusicIsOn = true;
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
void Player::SetPauseDuration(int pauseDuration)
{
	PauseDuration = pauseDuration;
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
int Player::GetPauseDuration()
{
	return PauseDuration;
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
void Player::SetMusicIsOn(bool musicOn)
{
	MusicIsOn = musicOn;
}
bool Player::GetIsMusicOn()
{ return MusicIsOn;		}

void Player::SetMusicFilename(char * filename)
{ MusicFilename = filename;	}
char * Player::GetMusicFilename()
{ return MusicFilename;	}

/*==================================
	Plays the game music
===================================*/
void Player::PlayMusic(char *filename)
{
	char* music = new char[strlen(filename) + 7];
	strcpy(music, "./data/");
	strcat(music, filename);

	if( music )
	{
		if( !MapMusic.Init(music) )
		{
			text("MUSIC FILE PROBLEMS!!!",13,12,yellow);
			exit(1);
		}
		MapMusic.PlaySong();
	}
	else
		MapMusic.FreeSound();
}

void Player::ToggleMusic()
/* ==========================
	Turns music on/off
============================*/
{ 
	if(MusicIsOn)
	{
		MusicIsOn = false;
		MapMusic.FreeSound();
		MapMusic.FreeSoundSystem();
	}
	else
	{
		MusicIsOn = true;
		PlayMusic(MusicFilename);
	}
}


void Player::DisplayStatus()
{
	text("Name:   ",13,11,white);
	cout << Name;
	text("HP:     ",13,12,white); 
	cout << HP << "/" << MaxHP;
	text("Str:    ",13,13,white);
	cout << Strength;
	text("Mind:   ",13,14,white);
	cout << Mind;
	text("%Evade: ",13,15,white);
	cout << Evade;
	text("Kills:  ",13,16,white);
	cout << TotalKills;
	text("Weapon Damage: ",13,17,white);
	cout << EquippedWeapon->GetDamageModifier() << " to " << EquippedWeapon->GetDamageModifier() + EquippedWeapon->GetDamage() - 1;
	text("Total Damage:  ",13,18,white);
	cout << EquippedWeapon->GetDamageModifier() + 2 << " to " << EquippedWeapon->GetDamage() + EquippedWeapon->GetDamageModifier() + Strength/2 - 1; 
	text("Level:  ",31,12,white);
	cout << Level;
	text("Exp:    ",31,13,white);
	cout << Experience;
	text("NxtLev: ",31,14,white);
	cout << ExperienceNeededForNextLevel;
	text("Gold:   ",31,15,white);
	cout << Gold;
	text("Orc Kills: ",45,12,white);
	cout << RaceKillCounts.OrcKillCount;
	text("Elf Kills: ",45,13,white);
	cout << RaceKillCounts.ElfKillCount;
	text("Hmn Kills: ",45,14,white);
	cout << RaceKillCounts.HumanKillCount;
	text("",13,23,white);
	system("pause");
}



void Player::DisplayInfo()
{
	if(IsPoisoned)
		text(Name,1,1,green);
	else
		text(Name,1,1,white);
	text("HP:    ",1,2,white);
	text("Ka:    ",1,3,white);
	text("GP:    ",1,4,white);
	num(HP,5,2,white);
	text("/",8,2,white);
	num(MaxHP,9,2,white);
	num(Ka,5,3,white);
	text("/",8,3,white);
	num(MaxKa,9,3,white);
	num(Gold,5,4,white);
	text("X:   ",1,6,white);
	text("Y:   ",1,7,white);
	num(GetPositionX(),3,6,white);
	num(GetPositionY(),3,7,white);
	text("           ",1,8,white);
	text("           ",1,9,white);
	text(EquippedWeapon->GetName(),1,8,white);
	text(EquippedArmor->GetName(),1,9,white);

}

void Player::DrawCursor(COORD position, WORD color, char cursorCharacter)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,position);

	cout << cursorCharacter;
}

bool Player::MoveCursor(COORD &cursorPosition,bool &hasSelection,bool &escapeWasPressed, int Ymin, int Ymax)
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
			hasSelection = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
		{
			bCursMov = false;
			hasSelection = true;
		}
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bCursMov = false;
			hasSelection = true;
			escapeWasPressed = true;
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

bool Player::ReachedNextLevel()
{
	if(Experience >= ExperienceNeededForNextLevel)
		return true;
	else
		return false;
}

void Player::IncreaseLevel()
{
	srand(GetTickCount());
	double Num1;
	clear();
	SetLevel(GetLevel() + 1);
	if(GetLevel() < 5)
	{
		Num1 = rand()%10 + 11;
		SetMaxHitPoints(GetMaxHitPoints() + static_cast<int>(Num1));
	}
	else
	{
		Num1 = rand()%10 + 20;
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
	text("You have gone up in level!!",13,11,FOREGROUND_GREEN);
	text("",79,23,white);
	Sleep(PauseDuration);
}

void Player::Save(ofstream &fout)
{
	fout << "Name: "	<< Name << endl;
	fout << "HP: "		<< HP << endl;
	fout << "MHP: "		<< MaxHP << endl;
	fout << "Ka: "		<< Ka << endl;
	fout << "MKa: "		<< MaxKa << endl;
	fout << "Gold: "	<< Gold << endl;
	fout << "Exp: "		<< Experience << endl;
	fout << "Next: "	<< ExperienceNeededForNextLevel << endl;
	fout << "Lvl: "		<< Level << endl;
	fout << "Evade: "	<< Evade << endl;
	fout << "Str: "		<< Strength << endl;
	fout << "Mind: "	<< Mind << endl;
	fout << "X: "		<< PositionX << endl;
	fout << "Y: "		<< PositionY << endl;
	fout << "Kills: "	<< TotalKills << endl;
	fout << "bSpells: "	<< HasSpells << endl;
	fout << "bjoined: "	<< MemberHasJoined << endl;
	fout << "Invis: "   << Invisible << endl;
	fout << "Weapon: "	<< EquippedWeapon->GetName() << endl;
	fout << "Armor: "   << EquippedArmor->GetName() << endl;
	fout << "elf: "		<< RaceReactions.Elf << endl;
	fout << "orc: "		<< RaceReactions.Orc << endl;
	fout << "hum: "		<< RaceReactions.Human << endl;
	fout << "elfk: "	<< RaceKillCounts.ElfKillCount << endl;
	fout << "orck: "	<< RaceKillCounts.OrcKillCount << endl;
	fout << "humk: "	<< RaceKillCounts.HumanKillCount << endl;
	fout << "start: "	<< PlotEventStates.Start << endl;
	fout << "P1: "		<< PlotEventStates.Priest1 << endl;
	fout << "P2: "		<< PlotEventStates.Priest2 << endl;
	fout << "P3: "		<< PlotEventStates.Priest3 << endl;
	fout << "P4: "		<< PlotEventStates.Priest4 << endl;
	fout << "Grn: "		<< PlotEventStates.GreenDragon << endl;
	fout << "Blu: "		<< PlotEventStates.BlueDragon << endl;
	fout << "Red: "		<< PlotEventStates.RedDragon << endl;
	fout << "Mnk: "		<< PlotEventStates.Monk << endl;
	fout << "Music: "   << MusicIsOn << endl;
}

void Player::Load(ifstream &fin)
{
	string temp;
	string A;
	string W;
	fin >> temp >> Name;
	fin >> temp >> HP;
	fin >> temp >> MaxHP;
	fin >> temp >> Ka;
	fin >> temp >> MaxKa;
	fin >> temp >> Gold;
	fin >> temp >> Experience;
	fin >> temp >> ExperienceNeededForNextLevel;
	fin >> temp >> Level;
	fin >> temp >> Evade;
	fin >> temp >> Strength;
	fin >> temp >> Mind;
	fin >> temp >> PositionX;
	fin >> temp >> PositionY;
	fin >> temp >> TotalKills;
	fin >> temp >> HasSpells;
	fin >> temp >> MemberHasJoined;
	fin >> temp >> Invisible;
	fin >> temp;
	getline(fin,W);	W = rotate(W);
	fin >> temp;
	getline(fin,A);	A = rotate(A);
	fin >> temp >> RaceReactions.Elf;
	fin >> temp >> RaceReactions.Orc;
	fin >> temp >> RaceReactions.Human;
	fin >> temp >> RaceKillCounts.ElfKillCount;
	fin >> temp >> RaceKillCounts.OrcKillCount;
	fin >> temp >> RaceKillCounts.HumanKillCount;
	fin >> temp >> PlotEventStates.Start;
	fin >> temp >> PlotEventStates.Priest1;
	fin >> temp >> PlotEventStates.Priest2;
	fin >> temp >> PlotEventStates.Priest3;
	fin >> temp >> PlotEventStates.Priest4;
	fin >> temp >> PlotEventStates.GreenDragon;
	fin >> temp >> PlotEventStates.BlueDragon;
	fin >> temp >> PlotEventStates.RedDragon;
	fin >> temp >> PlotEventStates.Monk;
	fin >> temp >> MusicIsOn;
	EquippedWeapon = loadWeapon(W);
	EquippedArmor = loadArmor(A);
	IsLoaded = true;
}

void Player::StopMusic()
{
	MapMusic.FreeSound();
}
