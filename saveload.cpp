#include "world.h"

#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


void world::save(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map)
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


void world::load(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map)
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

void world::load1(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<magik*> &spells,string &map)
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

void world::InvenSave(vector<Item*> &stuff, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(stuff.size()) << endl;

	for(i = 0;i < stuff.size(); i++)
	{
		fout << "inv" << i+1 << ": " << stuff[i]->GetName() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetMapName() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetPositionX() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetPositionY() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetCost() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetType() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetKeep() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetIsWeapon() << endl;
		fout << "inv" << i+1 << ": " << stuff[i]->GetIsArmor() << endl;
	}
}
void world::GroundSave(vector<Item*> &stuff, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(stuff.size()) << endl;

	for(i = 0;i < stuff.size(); i++)
	{
		fout << "item" << i+1 << ": " << stuff[i]->GetName() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetMapName() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetPositionX() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetPositionY() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetCost() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetType() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetKeep() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetIsWeapon() << endl;
		fout << "item" << i+1 << ": " << stuff[i]->GetIsArmor() << endl;
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


void world::loadGround(vector<Item*> &stuff,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item *holder;
	string temp;
	string szHolder;

	stuff.clear();
	fin >> temp >> j;

	for(i=0; i < j; i++)
	{
		holder = new Item;
		fin >> szHolder;	getline(fin,temp);	holder->SetName(rotate(temp));
		fin >> szHolder >> temp;	holder->SetMapName(temp);
		fin >> szHolder >> Xtemp;	holder->SetPositionX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetPositionY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetType(Xtemp);
		fin >> szHolder >> Y;	holder->SetKeep(Y);
		fin >> szHolder >> Y;	holder->SetIsWeapon(Y);
		fin >> szHolder >> Y;	holder->SetIsArmor(Y);

		if(holder->GetIsWeapon())
			stuff.push_back(loadWeapon(holder->GetName()));
		else if(holder->GetIsArmor())
			stuff.push_back(loadArmor(holder->GetName()));
		else
			stuff.push_back(holder);
	}
}

void world::loadInven(vector<Item*> &pstuff,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item *holder;
	string temp;
	string szHolder;

	pstuff.clear();
	fin >> temp >> j;

	for(i=0; i < j; i++)
	{
		holder = new Item;
		fin >> szHolder;	getline(fin,temp);	holder->SetName(rotate(temp));
		fin >> szHolder >> temp;	holder->SetMapName(temp);
		fin >> szHolder >> Xtemp;	holder->SetPositionX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetPositionY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetType(Xtemp);
		fin >> szHolder >> Y;	holder->SetKeep(Y);
		fin >> szHolder >> Y;	holder->SetIsWeapon(Y);
		fin >> szHolder >> Y;	holder->SetIsArmor(Y);

		if(holder->GetIsWeapon())
			pstuff.push_back(loadWeapon(holder->GetName()));
		else if(holder->GetIsArmor())
			pstuff.push_back(loadArmor(holder->GetName()));
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












