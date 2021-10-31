#include "world.h"

#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


void world::save(Player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map)
{
	string Savefile = p->GetName();
	Savefile = Savefile + ".svg";
	ofstream fout;

	fout.open(Savefile.c_str());

	p->Save(fout);
	MagikSave(spells,fout);
	InvenSave(pstuff,fout);
	GroundSave(stuff,fout);
	fout << "Map: " << map;

	fout.close();	
}


void world::load(Player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map)
{
	string fName;
	string temp;

	fName = GetFileName();
	fName = fName + ".svg";

	ifstream fin;
	fin.open(fName.c_str());
	if(fin.fail())
	{
		text("ERROR LOADING SAVED CHARACTER \n\n",13,11,FOREGROUND_RED);
		system("pause");
		exit(0);
	}
	p->Load(fin);
	loadMagik(spells,fin);
	loadInven(pstuff,fin);
	loadGround(stuff,fin);
	fin >> temp >> map;

	fin.close();

	clr(11);
	text("SAVE FILE SAFELY LOADED!!! \n\n",30,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 13, 23, FOREGROUND_GREEN);
	system("pause");
}

void world::load1(Player *p, vector<item*> &stuff, vector<item*> &pstuff, vector<magik*> &spells,string &map)
{
	string fName;
	string temp;

	fName = p->GetName();
	fName = fName + ".svg";

	ifstream fin;
	fin.open(fName.c_str());
	if(fin.fail())
	{
		text("ERROR LOADING SAVE FILE!!! \n\n",25,11,FOREGROUND_RED);
		system("pause");
		exit(0);
	}
	p->Load(fin);
	loadMagik(spells,fin);
	loadInven(pstuff,fin);
	loadGround(stuff,fin);
	fin >> temp >> map;

	fin.close();	

	system("cls");
	text("SAVE FILE SAFELY LOADED!!! \n\n",25,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 0, 24, FOREGROUND_GREEN);
	system("pause");
}

void world::InvenSave(vector<item*> &stuff, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(stuff.size()) << endl;

	for(i = 0;i < stuff.size(); i++)
	{
		fout << "inv" << i+1 << ": " << stuff[i]->getname() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getmap() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getX() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getY() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getCost() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getType() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getkeep() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getweap() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->getarm() << endl;
	}
}
void world::GroundSave(vector<item*> &stuff, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(stuff.size()) << endl;

	for(i = 0;i < stuff.size(); i++)
	{
		fout << "item" << i+1 << ": " << stuff[i]->getname() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getmap() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getX() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getY() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getCost() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getType() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getkeep() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getweap() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->getarm() << endl;
	}
}
void world::MagikSave(vector<magik*> &M, ofstream &fout)
{
	unsigned int i;
	fout << "#spells: "	<< static_cast<int>(M.size()) << endl;
	
	for(i = 0;i < M.size(); i++)
	{
		fout << "Spell"<< i+1 << ": " << M[i]->getname() << endl;
	}
}


void world::loadGround(vector<item*> &stuff,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	item *holder;
	string temp;
	string szHolder;

	stuff.clear();
	fin >> temp >> j;

	for(i=0; i < j; i++)
	{
		holder = new item;
		fin >> szHolder;	getline(fin,temp);	holder->setname(rotate(temp));
		fin >> szHolder >> temp;	holder->setmap(temp);
		fin >> szHolder >> Xtemp;	holder->setX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setType(Xtemp);
		fin >> szHolder >> Y;	holder->setkeep(Y);
		fin >> szHolder >> Y;	holder->setweap(Y);
		fin >> szHolder >> Y;	holder->setarm(Y);

		if(holder->getweap())
			stuff.push_back(loadWeapon(holder->getname()));
		else if(holder->getarm())
			stuff.push_back(loadArmor(holder->getname()));
		else
			stuff.push_back(holder);
	}
}

void world::loadInven(vector<item*> &pstuff,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	item *holder;
	string temp;
	string szHolder;

	pstuff.clear();
	fin >> temp >> j;

	for(i=0; i < j; i++)
	{
		holder = new item;
		fin >> szHolder;	getline(fin,temp);	holder->setname(rotate(temp));
		fin >> szHolder >> temp;	holder->setmap(temp);
		fin >> szHolder >> Xtemp;	holder->setX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->setType(Xtemp);
		fin >> szHolder >> Y;	holder->setkeep(Y);
		fin >> szHolder >> Y;	holder->setweap(Y);
		fin >> szHolder >> Y;	holder->setarm(Y);

		if(holder->getweap())
			pstuff.push_back(loadWeapon(holder->getname()));
		else if(holder->getarm())
			pstuff.push_back(loadArmor(holder->getname()));
		else
			pstuff.push_back(holder);
	}
}

void world::loadMagik(vector<magik*> &M,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	string temp;
	string N;
	fin >> temp >> j;
	if(j == 0)
		return;
	for(i=0;i < j; i++)
	{
		fin >> temp;
		getline(fin,N);
		M.push_back(getMagik(rotate(N)));
	}
}

string world::GetFileName()
{
	string X = "";
	text("Enter name of character: ",13,11,yellow);
	text("",38,11,white);
	cin >> X;

	return X;
}

magik* world::getMagik(string N)
{
 	magik *M = new magik;
	if(N == "Minor Heal")
		M = new minheal;
	if(N == "Major Heal")
		M = new majheal;
	if(N == "Briar Bush")
		M = new briar;
	if(N == "Snow")
		M = new snow;
	if(N == "PerfectStorm")
		M = new pstorm;
	if(N == "Drain Life")
		M = new dlife;
	if(N == "Drain Ka")
		M = new stealka;
	if(N == "Flame Arrow")
		M = new farrow;
	if(N == "Fire")
		M = new fire;
	if(N == "Lava")
		M = new lava;
	if(N == "Strength")
		M = new strength;
	if(N == "Dispel")
		M = new dispel;
	if(N == "Shock")
		M = new shock;
	if(N == "Acid Rain")
		M = new acidrain;
	if(N == "Lightning Bolt")
		M = new lightning;
	if(N == "Poison")
		M = new poison;
	if(N == "Summon Skeleton")
		M = new skeleton;
	if(N == "Dark Strike")
		M = new dstrike;
	if(N == "Critical")
		M = new critical;
	if(N == "Mind Control")
		M = new control;
	return M;
}












