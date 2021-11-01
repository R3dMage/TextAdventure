#include "World.h"

#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


void World::SaveGame(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map)
{
	string Savefile = player->GetName();
	Savefile = Savefile + ".svg";
	ofstream fout;

	fout.open(Savefile.c_str());

	player->Save(fout);
	SaveMagic(spells,fout);
	SaveInventory(playerInventory,fout);
	SaveGround(worldItems,fout);
	fout << "Map: " << map;

	fout.close();	
}


void World::Load(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map)
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
	player->Load(fin);
	LoadMagic(spells,fin);
	LoadInventory(playerInventory,fin);
	LoadGround(worldItems,fin);
	fin >> temp >> map;

	fin.close();

	ClearTextBottomRight(11);
	text("SAVE FILE SAFELY LOADED!!! \n\n",30,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 13, 23, FOREGROUND_GREEN);
	system("pause");
}

void World::load1(Player *player, vector<Item*> &worldItems, vector<Item*> &playerInventory, vector<Magic*> &spells,string &map)
{
	string fName;
	string temp;

	fName = player->GetName();
	fName = fName + ".svg";

	ifstream fin;
	fin.open(fName.c_str());
	if(fin.fail())
	{
		text("ERROR LOADING SAVE FILE!!! \n\n",25,11,FOREGROUND_RED);
		system("pause");
		exit(0);
	}
	player->Load(fin);
	LoadMagic(spells,fin);
	LoadInventory(playerInventory,fin);
	LoadGround(worldItems,fin);
	fin >> temp >> map;

	fin.close();	

	system("cls");
	text("SAVE FILE SAFELY LOADED!!! \n\n",25,11,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("", 0, 24, FOREGROUND_GREEN);
	system("pause");
}

void World::SaveInventory(vector<Item*> &inventory, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(inventory.size()) << endl;

	for(i = 0;i < inventory.size(); i++)
	{
		fout << "inv" << i+1 << ": " << inventory[i]->GetName() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetMapName() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetPositionX() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetPositionY() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetCost() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetType() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetKeep() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetIsWeapon() << endl;
		fout << "inv" << i+1 << ": " << inventory[i]->GetIsArmor() << endl;
	}
}
void World::SaveGround(vector<Item*> &worldItems, ofstream &fout)
{
	unsigned int i;
	fout << "#items: "	<< static_cast<int>(worldItems.size()) << endl;

	for(i = 0;i < worldItems.size(); i++)
	{
		fout << "item" << i+1 << ": " << worldItems[i]->GetName() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetMapName() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetPositionX() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetPositionY() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetCost() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetType() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetKeep() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetIsWeapon() << endl;
		fout << "item" << i+1 << ": " << worldItems[i]->GetIsArmor() << endl;
	}
}
void World::SaveMagic(vector<Magic*> &spells, ofstream &fout)
{
	unsigned int i;
	fout << "#spells: "	<< static_cast<int>(spells.size()) << endl;
	
	for(i = 0;i < spells.size(); i++)
	{
		fout << "Spell"<< i+1 << ": " << spells[i]->GetName() << endl;
	}
}


void World::LoadGround(vector<Item*> &worldInventory,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item *holder;
	string temp;
	string szHolder;

	worldInventory.clear();
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
			worldInventory.push_back(loadWeapon(holder->GetName()));
		else if(holder->GetIsArmor())
			worldInventory.push_back(loadArmor(holder->GetName()));
		else
			worldInventory.push_back(holder);
	}
}

void World::LoadInventory(vector<Item*> &playerInventory,ifstream &fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item *holder;
	string temp;
	string szHolder;

	playerInventory.clear();
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
			playerInventory.push_back(loadWeapon(holder->GetName()));
		else if(holder->GetIsArmor())
			playerInventory.push_back(loadArmor(holder->GetName()));
		else
			playerInventory.push_back(holder);
	}
}

void World::LoadMagic(vector<Magic*> &spells,ifstream &fin)
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
		spells.push_back(GetMagic(rotate(N)));
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

Magic* World::GetMagic(string spellName)
{
 	Magic *M = new Magic;
	if(spellName == "Minor Heal")
		M = new MinorHeal;
	if(spellName == "Major Heal")
		M = new MajorHeal;
	if(spellName == "Briar Bush")
		M = new BriarBush;
	if(spellName == "Snow")
		M = new Blizzard;
	if(spellName == "PerfectStorm")
		M = new PerfectStorm;
	if(spellName == "Drain Life")
		M = new DrainLife;
	if(spellName == "Drain Ka")
		M = new StealKa;
	if(spellName == "Flame Arrow")
		M = new FireArrow;
	if(spellName == "Fire")
		M = new Fire;
	if(spellName == "Lava")
		M = new Lava;
	if(spellName == "Strength")
		M = new Might;
	if(spellName == "Dispel")
		M = new Dispel;
	if(spellName == "Shock")
		M = new Shock;
	if(spellName == "Acid Rain")
		M = new AcidRain;
	if(spellName == "Lightning Bolt")
		M = new LightningBolt;
	if(spellName == "Poison")
		M = new Poison;
	if(spellName == "Summon Skeleton")
		M = new Skeleton;
	if(spellName == "Dark Strike")
		M = new DarkStrike;
	if(spellName == "Critical")
		M = new Critical;
	if(spellName == "Mind Control")
		M = new Control;
	return M;
}












