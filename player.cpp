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
	X =		3;
	Y =		2;
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
	setweapon(loadWeapon("Dagger"));
	setarmor(loadArmor("Clothes"));
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

void Player::setarmor(armor *parm)
{
	EquippedArmor = parm;
}
void Player::setweapon(weapon *pweap)
{
	EquippedWeapon = pweap;
}
void Player::setname(string pname)
{
	Name = pname;
}
void Player::setexp(int pex)
{
	Experience = pex;
}
void Player::setgold(int pgold)
{
	Gold = pgold;
}
void Player::setHP(int php)
{
	if(php > MaxHP)
		php = MaxHP;
	HP = php;
}
void Player::setMHP(int pmhp)
{
	MaxHP = pmhp;
}
void Player::setka(int pka)
{
	if(pka > MaxKa)
		pka = MaxKa;
	Ka = pka;
}
void Player::setmka(int pmka)
{
	MaxKa = pmka;
}
void Player::setlev(int plev)
{
	Level = plev;
}
void Player::setmind(int pmind)
{
	Mind = pmind;
}
void Player::setstr(int pstr)
{
	Strength = pstr;
}
void Player::setX(int pX)
{
	if(pX == 0)
		pX = 1;
	X = pX;
}
void Player::setY(int pY)
{
	if(pY == 0)
		pY = 1;
	Y = pY;
}
void Player::setNext(int next)
{
	ExperienceNeededForNextLevel = next;
}
void Player::setEvd(int evd)
{
	Evade = evd;
}
void Player::setKills(int K)
{
	TotalKills = K;
}
void Player::setPause(int P)
{
	PauseDuration = P;
}

armor* Player::getarmor()
{
	return EquippedArmor;
}
weapon* Player::getweapon()
{
	return EquippedWeapon;
}
string Player::getname()
{
	return Name;
}
int Player::getexp()
{
	return Experience;
}
int Player::getgold()
{
	return Gold;
}
int Player::getHP()
{
	return HP;
}
int Player::getMHP()
{
	return MaxHP;
}
int Player::getka()
{
	return Ka;
}
int Player::getmka()
{
	return MaxKa;
}
int Player::getlev()
{
	return Level;
}
int Player::getmind()
{
	return Mind;
}
int Player::getstr()
{
	return Strength;
}
int Player::getX()
{
	return X;
}
int Player::getY()
{
	return Y;
}
int Player::getNext()
{
	return ExperienceNeededForNextLevel;
}
int Player::getEvd()
{
	return Evade;
}
int Player::getKills()
{
	return TotalKills;
}
int Player::getPause()
{
	return PauseDuration;
}
void Player::setelf(int N)
{	
	RaceReactions.Elf = N;	
}
int Player::getelf()
{
	return RaceReactions.Elf;
}
void Player::sethuman(int N)
{	
	RaceReactions.Human = N;	
}
int Player::gethuman()
{
	return RaceReactions.Human;
}
void Player::setorc(int N)
{	
	RaceReactions.Orc = N;	
}
int Player::getorc()
{
	return RaceReactions.Orc;
}
int Player::getstate()
{
	return HealthState;
}
void Player::setstate(int N)
{
	HealthState = N;
}
bool Player::getbspells()
{
	return HasSpells;
}
void Player::setbspells(bool M)
{
	if(M)
	{
		HasSpells = M;		// When a player gets spells he gets to have magic
		MaxKa = Mind / 2;      // power, ka. Mind / 2 is that starting point for it.
		Ka = MaxKa;
	}
	else
		HasSpells = M;
}
void Player::setbjoined(bool M)
{
	MemberHasJoined = M;
}
bool Player::getbjoined()
{
	return MemberHasJoined;
}
bool Player::getpoisoned()
{
	return IsPoisoned;
}
void Player::setpoisoned(bool P)
{
	IsPoisoned = P;
}
void Player::setLoaded(bool B)
{
	IsLoaded = B;
}
bool Player:: getLoaded()
{
	return IsLoaded;
}
void Player::setSleep(bool B)
{
	IsAsleep = B;
}
bool Player::getSleep()
{
	return IsAsleep;
}
void Player::setInvis(bool B)
{
	Invisible = B;
}
bool Player::getInvis()
{
	return Invisible;
}
void Player::setMusic(bool M)
{
	MusicIsOn = M;
}
bool Player::getMusic()
{ return MusicIsOn;		}
void Player::setMusicFilename(char * MF)
{ MusicFilename = MF;	}
char * Player::getMusicFilename()
{ return MusicFilename;	}

/*==================================
	Plays the game music
===================================*/
void Player::playMusic(char *M)
{
	char* music = new char[strlen(M) + 7];
	strcpy(music, "./data/");
	strcat(music, M);

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

void Player::changeMusic()
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
		playMusic(MusicFilename);
	}
}


void Player::status()
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
	cout << EquippedWeapon->getdamMod() << " to " << EquippedWeapon->getdamMod() + EquippedWeapon->getdamage() - 1;
	text("Total Damage:  ",13,18,white);
	cout << EquippedWeapon->getdamMod() + 2 << " to " << EquippedWeapon->getdamage() + EquippedWeapon->getdamMod() + Strength/2 - 1; 
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



void Player::info()
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
	num(getX(),3,6,white);
	num(getY(),3,7,white);
	text("           ",1,8,white);
	text("           ",1,9,white);
	text(EquippedWeapon->getname(),1,8,white);
	text(EquippedArmor->getname(),1,9,white);

}

void Player::DrawCurs(COORD position, WORD color, char cursorCharacter)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,position);

	cout << cursorCharacter;
}

bool Player::MoveCurs(COORD &cursorPosition,bool &hasSelection,bool &escapeWasPressed, int Ymin, int Ymax)
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

bool Player::LevUp()
{
	if(Experience >= ExperienceNeededForNextLevel)
		return true;
	else
		return false;
}

void Player::raiseLev()
{
	srand(GetTickCount());
	double Num1;
	clear();
	setlev(getlev() + 1);
	if(getlev() < 5)
	{
		Num1 = rand()%10 + 11;
		setMHP(getMHP() + static_cast<int>(Num1));
	}
	else
	{
		Num1 = rand()%10 + 20;
		Num1 = Num1 / 100;
		setMHP(getMHP() + (getMHP() * static_cast<int>(Num1)));
	}
	Evade += 1;
	Num1 = rand()% 3 + 2;
	setstr(getstr() + static_cast<int>(Num1));
	Num1 = rand()% 4 + 1;
	setmind(getmind() + static_cast<int>(Num1));
	Num1 = rand()% (getmind()/2) + 1;
	setmka(getmka() + static_cast<int>(Num1));
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
	fout << "X: "		<< X << endl;
	fout << "Y: "		<< Y << endl;
	fout << "Kills: "	<< TotalKills << endl;
	fout << "bSpells: "	<< HasSpells << endl;
	fout << "bjoined: "	<< MemberHasJoined << endl;
	fout << "Invis: "   << Invisible << endl;
	fout << "Weapon: "	<< EquippedWeapon->getname() << endl;
	fout << "Armor: "   << EquippedArmor->getname() << endl;
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
	fin >> temp >> X;
	fin >> temp >> Y;
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

void Player::stopMusic()
{
	MapMusic.FreeSound();
}
