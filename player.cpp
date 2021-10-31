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
	MHP =	25;
	HP =	25;
	kills =	0;
	exp =	0;
	X =		3;
	Y =		2;
	lev =	1;
	NextLev = 50;
	evade = 5;
	gold =  (rand()%25 + 25) * 8;
	str =	rand()%5 + 5;
	mind =	rand()%5 + 5;
	ka =	0;
	mka =	ka;
	bspells =	false;
	bjoined =	false;
	poisoned =	false;
	sleep =		false;
	Invisible = false;
	pause = 1500;
	setweapon(loadWeapon("Dagger"));
	setarmor(loadArmor("Clothes"));
	react.elf =		2;
	react.human =	3;
	react.orc =		1;
	kill.Ekills = 0;
	kill.Hkills = 0;
	kill.Okills = 0;
	plot.priest1 = false;
	plot.priest2 = false;
	plot.priest3 = false;
	plot.priest4 = false;
	plot.monk = false;
	plot.gd = false;
	plot.bd = false;
	plot.rd = false;
	plot.start = false;
	Loaded = false;
	music = true;
}

void Player::setarmor(armor *parm)
{
	arm = parm;
}
void Player::setweapon(weapon *pweap)
{
	weap = pweap;
}
void Player::setname(string pname)
{
	name = pname;
}
void Player::setexp(int pex)
{
	exp = pex;
}
void Player::setgold(int pgold)
{
	gold = pgold;
}
void Player::setHP(int php)
{
	if(php > MHP)
		php = MHP;
	HP = php;
}
void Player::setMHP(int pmhp)
{
	MHP = pmhp;
}
void Player::setka(int pka)
{
	if(pka > mka)
		pka = mka;
	ka = pka;
}
void Player::setmka(int pmka)
{
	mka = pmka;
}
void Player::setlev(int plev)
{
	lev = plev;
}
void Player::setmind(int pmind)
{
	mind = pmind;
}
void Player::setstr(int pstr)
{
	str = pstr;
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
	NextLev = next;
}
void Player::setEvd(int evd)
{
	evade = evd;
}
void Player::setKills(int K)
{
	kills = K;
}
void Player::setPause(int P)
{
	pause = P;
}

armor* Player::getarmor()
{
	return arm;
}
weapon* Player::getweapon()
{
	return weap;
}
string Player::getname()
{
	return name;
}
int Player::getexp()
{
	return exp;
}
int Player::getgold()
{
	return gold;
}
int Player::getHP()
{
	return HP;
}
int Player::getMHP()
{
	return MHP;
}
int Player::getka()
{
	return ka;
}
int Player::getmka()
{
	return mka;
}
int Player::getlev()
{
	return lev;
}
int Player::getmind()
{
	return mind;
}
int Player::getstr()
{
	return str;
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
	return NextLev;
}
int Player::getEvd()
{
	return evade;
}
int Player::getKills()
{
	return kills;
}
int Player::getPause()
{
	return pause;
}
void Player::setelf(int N)
{	
	react.elf = N;	
}
int Player::getelf()
{
	return react.elf;
}
void Player::sethuman(int N)
{	
	react.human = N;	
}
int Player::gethuman()
{
	return react.human;
}
void Player::setorc(int N)
{	
	react.orc = N;	
}
int Player::getorc()
{
	return react.orc;
}
int Player::getstate()
{
	return state;
}
void Player::setstate(int N)
{
	state = N;
}
bool Player::getbspells()
{
	return bspells;
}
void Player::setbspells(bool M)
{
	if(M)
	{
		bspells = M;		// When a player gets spells he gets to have magic
		mka = mind / 2;      // power, ka. Mind / 2 is that starting point for it.
		ka = mka;
	}
	else
		bspells = M;
}
void Player::setbjoined(bool M)
{
	bjoined = M;
}
bool Player::getbjoined()
{
	return bjoined;
}
bool Player::getpoisoned()
{
	return poisoned;
}
void Player::setpoisoned(bool P)
{
	poisoned = P;
}
void Player::setLoaded(bool B)
{
	Loaded = B;
}
bool Player:: getLoaded()
{
	return Loaded;
}
void Player::setSleep(bool B)
{
	sleep = B;
}
bool Player::getSleep()
{
	return sleep;
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
	music = M;
}
bool Player::getMusic()
{ return music;		}
void Player::setMusicFilename(char * MF)
{ musicFilename = MF;	}
char * Player::getMusicFilename()
{ return musicFilename;	}

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
		if( !mapMusic.Init(music) )
		{
			text("MUSIC FILE PROBLEMS!!!",13,12,yellow);
			exit(1);
		}
		mapMusic.PlaySong();
	}
	else
		mapMusic.FreeSound();
}

void Player::changeMusic()
/* ==========================
	Turns music on/off
============================*/
{ 
	if(music)
	{
		music = false;
		mapMusic.FreeSound();
		mapMusic.FreeSoundSystem();
	}
	else
	{
		music = true;
		playMusic(musicFilename);
	}
}


void Player::status()
{
	text("Name:   ",13,11,white);
	cout << name;
	text("HP:     ",13,12,white); 
	cout << HP << "/" << MHP;
	text("Str:    ",13,13,white);
	cout << str;
	text("Mind:   ",13,14,white);
	cout << mind;
	text("%Evade: ",13,15,white);
	cout << evade;
	text("Kills:  ",13,16,white);
	cout << kills;
	text("Weapon Damage: ",13,17,white);
	cout << weap->getdamMod() << " to " << weap->getdamMod() + weap->getdamage() - 1;
	text("Total Damage:  ",13,18,white);
	cout << weap->getdamMod() + 2 << " to " << weap->getdamage() + weap->getdamMod() + str/2 - 1; 
	text("Level:  ",31,12,white);
	cout << lev;
	text("Exp:    ",31,13,white);
	cout << exp;
	text("NxtLev: ",31,14,white);
	cout << NextLev;
	text("Gold:   ",31,15,white);
	cout << gold;
	text("Orc Kills: ",45,12,white);
	cout << kill.Okills;
	text("Elf Kills: ",45,13,white);
	cout << kill.Ekills;
	text("Hmn Kills: ",45,14,white);
	cout << kill.Hkills;
	text("",13,23,white);
	system("pause");
}



void Player::info()
{
	if(poisoned)
		text(name,1,1,green);
	else
		text(name,1,1,white);
	text("HP:    ",1,2,white);
	text("Ka:    ",1,3,white);
	text("GP:    ",1,4,white);
	num(HP,5,2,white);
	text("/",8,2,white);
	num(MHP,9,2,white);
	num(ka,5,3,white);
	text("/",8,3,white);
	num(mka,9,3,white);
	num(gold,5,4,white);
	text("X:   ",1,6,white);
	text("Y:   ",1,7,white);
	num(getX(),3,6,white);
	num(getY(),3,7,white);
	text("           ",1,8,white);
	text("           ",1,9,white);
	text(weap->getname(),1,8,white);
	text(arm->getname(),1,9,white);

}

void Player::DrawCurs(COORD pos, WORD color, char curs)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH,color);
	SetConsoleCursorPosition(OutputH,pos);

	cout << curs;
}

bool Player::MoveCurs(COORD &CursPos,bool &bSelect,bool &bEsc, int Ymin, int Ymax)
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
		else if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		{
			bCursMov = false;
			bSelect = true;
			bEsc = true;
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
	if(exp >= NextLev)
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
	evade += 1;
	Num1 = rand()% 3 + 2;
	setstr(getstr() + static_cast<int>(Num1));
	Num1 = rand()% 4 + 1;
	setmind(getmind() + static_cast<int>(Num1));
	Num1 = rand()% (getmind()/2) + 1;
	setmka(getmka() + static_cast<int>(Num1));
	NextLev = lev * lev * 50;
	text("You have gone up in level!!",13,11,FOREGROUND_GREEN);
	text("",79,23,white);
	Sleep(pause);
}

void Player::Save(ofstream &fout)
{
	fout << "Name: "	<< name << endl;
	fout << "HP: "		<< HP << endl;
	fout << "MHP: "		<< MHP << endl;
	fout << "Ka: "		<< ka << endl;
	fout << "MKa: "		<< mka << endl;
	fout << "Gold: "	<< gold << endl;
	fout << "Exp: "		<< exp << endl;
	fout << "Next: "	<< NextLev << endl;
	fout << "Lvl: "		<< lev << endl;
	fout << "Evade: "	<< evade << endl;
	fout << "Str: "		<< str << endl;
	fout << "Mind: "	<< mind << endl;
	fout << "X: "		<< X << endl;
	fout << "Y: "		<< Y << endl;
	fout << "Kills: "	<< kills << endl;
	fout << "bSpells: "	<< bspells << endl;
	fout << "bjoined: "	<< bjoined << endl;
	fout << "Invis: "   << Invisible << endl;
	fout << "Weapon: "	<< weap->getname() << endl;
	fout << "Armor: "   << arm->getname() << endl;
	fout << "elf: "		<< react.elf << endl;
	fout << "orc: "		<< react.orc << endl;
	fout << "hum: "		<< react.human << endl;
	fout << "elfk: "	<< kill.Ekills << endl;
	fout << "orck: "	<< kill.Okills << endl;
	fout << "humk: "	<< kill.Hkills << endl;
	fout << "start: "	<< plot.start << endl;
	fout << "P1: "		<< plot.priest1 << endl;
	fout << "P2: "		<< plot.priest2 << endl;
	fout << "P3: "		<< plot.priest3 << endl;
	fout << "P4: "		<< plot.priest4 << endl;
	fout << "Grn: "		<< plot.gd << endl;
	fout << "Blu: "		<< plot.bd << endl;
	fout << "Red: "		<< plot.rd << endl;
	fout << "Mnk: "		<< plot.monk << endl;
	fout << "Music: "   << music << endl;
}

void Player::Load(ifstream &fin)
{
	string temp;
	string A;
	string W;
	fin >> temp >> name;
	fin >> temp >> HP;
	fin >> temp >> MHP;
	fin >> temp >> ka;
	fin >> temp >> mka;
	fin >> temp >> gold;
	fin >> temp >> exp;
	fin >> temp >> NextLev;
	fin >> temp >> lev;
	fin >> temp >> evade;
	fin >> temp >> str;
	fin >> temp >> mind;
	fin >> temp >> X;
	fin >> temp >> Y;
	fin >> temp >> kills;
	fin >> temp >> bspells;
	fin >> temp >> bjoined;
	fin >> temp >> Invisible;
	fin >> temp;
	getline(fin,W);	W = rotate(W);
	fin >> temp;
	getline(fin,A);	A = rotate(A);
	fin >> temp >> react.elf;
	fin >> temp >> react.orc;
	fin >> temp >> react.human;
	fin >> temp >> kill.Ekills;
	fin >> temp >> kill.Okills;
	fin >> temp >> kill.Hkills;
	fin >> temp >> plot.start;
	fin >> temp >> plot.priest1;
	fin >> temp >> plot.priest2;
	fin >> temp >> plot.priest3;
	fin >> temp >> plot.priest4;
	fin >> temp >> plot.gd;
	fin >> temp >> plot.bd;
	fin >> temp >> plot.rd;
	fin >> temp >> plot.monk;
	fin >> temp >> music;
	weap = loadWeapon(W);
	arm = loadArmor(A);
	Loaded = true;
}

void Player::stopMusic()
{
	mapMusic.FreeSound();
}

















































