#include "World.h"

#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


void World::SaveGame(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<Magic*> &spells,string &map)
{
	string Savefile = p->GetName();
	Savefile = Savefile + ".svg";
	ofstream fout;

	fout.open(Savefile.c_str());

	p->Save(fout);
	SaveMagic(spells,fout);
	SaveInventory(pstuff,fout);
	SaveGround(stuff,fout);
	fout << "Map: " << map;

	fout.close();	
}


void World::Load(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<Magic*> &spells,string &map)
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
	LoadMagic(spells,fin);
	LoadInventory(pstuff,fin);
	LoadGround(stuff,fin);
	fin >> temp >> map;

	fin.close();

	ClearTextBottomRight(11);
	text("SAVE FILE SAFELY LOADED!!! \n\n",30,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 13, 23, FOREGROUND_GREEN);
	system("pause");
}

void World::load1(Player *p, vector<Item*> &stuff, vector<Item*> &pstuff, vector<Magic*> &spells,string &map)
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
	LoadMagic(spells,fin);
	LoadInventory(pstuff,fin);
	LoadGround(stuff,fin);
	fin >> temp >> map;

	fin.close();	

	system("cls");
	text("SAVE FILE SAFELY LOADED!!! \n\n",25,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 0, 24, FOREGROUND_GREEN);
	system("pause");
}

void World::SaveInventory(vector<Item*> &stuff, ofstream &fout)
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
void World::SaveGround(vector<Item*> &stuff, ofstream &fout)
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
void World::SaveMagic(vector<Magic*> &M, ofstream &fout)
{
	unsigned int i;
	fout << "#spells: "	<< static_cast<int>(M.size()) << endl;
	
	for(i = 0;i < M.size(); i++)
	{
		fout << "Spell"<< i+1 << ": " << M[i]->GetName() << endl;
	}
}


void World::LoadGround(vector<Item*> &stuff,ifstream &fin)
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

void World::LoadInventory(vector<Item*> &pstuff,ifstream &fin)
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

void World::LoadMagic(vector<Magic*> &M,ifstream &fin)
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
		M.push_back(GetMagic(rotate(N)));
	}
}

string World::GetFileName()
{
	string X = "";
	text("Enter name of character: ",13,11,yellow);
	text("",38,11,white);
	cin >> X;

	return X;
}

Magic* World::GetMagic(string N)
{
 	Magic *M = new Magic;
	if(N == "Minor Heal")
		M = new MinorHeal;
	if(N == "Major Heal")
		M = new MajorHeal;
	if(N == "Briar Bush")
		M = new BriarBush;
	if(N == "Snow")
		M = new Blizzard;
	if(N == "PerfectStorm")
		M = new PerfectStorm;
	if(N == "Drain Life")
		M = new DrainLife;
	if(N == "Drain Ka")
		M = new StealKa;
	if(N == "Flame Arrow")
		M = new FireArrow;
	if(N == "Fire")
		M = new Fire;
	if(N == "Lava")
		M = new Lava;
	if(N == "Strength")
		M = new Might;
	if(N == "Dispel")
		M = new Dispel;
	if(N == "Shock")
		M = new Shock;
	if(N == "Acid Rain")
		M = new AcidRain;
	if(N == "Lightning Bolt")
		M = new LightningBolt;
	if(N == "Poison")
		M = new Poison;
	if(N == "Summon Skeleton")
		M = new Skeleton;
	if(N == "Dark Strike")
		M = new DarkStrike;
	if(N == "Critical")
		M = new Critical;
	if(N == "Mind Control")
		M = new Control;
	return M;
}












