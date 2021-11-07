#include "SaveLoadGame.h"

using namespace std;

SaveLoadGame::SaveLoadGame(ItemRepository* itemRepository, GameDisplay* gameDisplay)
{
	Items = itemRepository;
	Display = gameDisplay;
}

void SaveLoadGame::SaveGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map)
{
	string Savefile = player->GetName();
	Savefile = Savefile + ".svg";
	ofstream fout;

	fout.open(Savefile.c_str());

	SavePlayer(player, fout);
	SaveMagic(spells, fout);
	SaveInventory(playerInventory, fout);
	SaveGround(worldItems, fout);
	fout << "Map: " << map;

	fout.close();
}

void SaveLoadGame::SavePlayer(Player* player, ofstream& fout)
{
	fout << "Name: " << player->GetName() << endl;
	fout << "HP: " << player->GetCurrentHitPoints() << endl;
	fout << "MHP: " << player->GetMaxHitPoints() << endl;
	fout << "Ka: " << player->GetCurrentKa() << endl;
	fout << "MKa: " << player->GetMaxKa() << endl;
	fout << "Gold: " << player->GetGold() << endl;
	fout << "Exp: " << player->GetExperience() << endl;
	fout << "Next: " << player->GetExperienceForNextLevel() << endl;
	fout << "Lvl: " << player->GetLevel() << endl;
	fout << "Evade: " << player->GetEvade() << endl;
	fout << "Str: " << player->GetStrength() << endl;
	fout << "Mind: " << player->GetMind() << endl;
	fout << "X: " << player->GetPositionX() << endl;
	fout << "Y: " << player->GetPositionY() << endl;
	fout << "Kills: " << player->GetTotalKills() << endl;
	fout << "bSpells: " << player->HasLearnedSpells() << endl;
	fout << "bjoined: " << player->GetMemberHasJoined() << endl;
	fout << "Invis: " << player->GetIsInvisible() << endl;
	fout << "Weapon: " << player->GetWeapon()->GetName() << endl;
	fout << "Armor: " << player->GetArmor()->GetName() << endl;
	fout << "elf: " << player->RaceReactions.Elf << endl;
	fout << "orc: " << player->RaceReactions.Orc << endl;
	fout << "hum: " << player->RaceReactions.Human << endl;
	fout << "elfk: " << player->RaceKillCounts.ElfKillCount << endl;
	fout << "orck: " << player->RaceKillCounts.OrcKillCount << endl;
	fout << "humk: " << player->RaceKillCounts.HumanKillCount << endl;
	fout << "start: " << player->PlotEventStates.Start << endl;
	fout << "P1: " << player->PlotEventStates.Priest1 << endl;
	fout << "P2: " << player->PlotEventStates.Priest2 << endl;
	fout << "P3: " << player->PlotEventStates.Priest3 << endl;
	fout << "P4: " << player->PlotEventStates.Priest4 << endl;
	fout << "Grn: " << player->PlotEventStates.GreenDragon << endl;
	fout << "Blu: " << player->PlotEventStates.BlueDragon << endl;
	fout << "Red: " << player->PlotEventStates.RedDragon << endl;
	fout << "Mnk: " << player->PlotEventStates.Monk << endl;
	fout << "Music: " << player->GetIsMusicOn() << endl;
}

void SaveLoadGame::LoadGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map, string filename)
{
	string fName = filename + ".svg";
	string temp;

	ifstream fin;
	fin.open(fName.c_str());
	if (fin.fail())
	{
		Display->DisplayError("ERROR LOADING SAVED CHARACTER");
		exit(0);
	};
	LoadPlayer(player, fin);
	LoadMagic(spells, fin);
	LoadInventory(playerInventory, fin);
	LoadGround(worldItems, fin);
	fin >> temp >> map;

	fin.close();	
}

void SaveLoadGame::SaveInventory(vector<Item*>& inventory, ofstream& fout)
{
	unsigned int i;
	fout << "#items: " << static_cast<int>(inventory.size()) << endl;

	for (i = 0; i < inventory.size(); i++)
	{
		fout << "inv" << i + 1 << ": " << inventory[i]->GetName() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetMapName() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetPositionX() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetPositionY() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetCost() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetType() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetKeep() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetIsWeapon() << endl;
		fout << "inv" << i + 1 << ": " << inventory[i]->GetIsArmor() << endl;
	}
}
void SaveLoadGame::SaveGround(vector<Item*>& worldItems, ofstream& fout)
{
	unsigned int i;
	fout << "#items: " << static_cast<int>(worldItems.size()) << endl;

	for (i = 0; i < worldItems.size(); i++)
	{
		fout << "item" << i + 1 << ": " << worldItems[i]->GetName() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetMapName() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetPositionX() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetPositionY() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetCost() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetType() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetKeep() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetIsWeapon() << endl;
		fout << "item" << i + 1 << ": " << worldItems[i]->GetIsArmor() << endl;
	}
}
void SaveLoadGame::SaveMagic(vector<Magic*>& spells, ofstream& fout)
{
	unsigned int i;
	fout << "#spells: " << static_cast<int>(spells.size()) << endl;

	for (i = 0; i < spells.size(); i++)
	{
		fout << "Spell" << i + 1 << ": " << spells[i]->GetName() << endl;
	}
}

void SaveLoadGame::LoadPlayer(Player* player, ifstream& fin)
{
	string Temp;
	string Value;
	int Number;
	bool Truth;
	string A;
	string W;
	fin >> Temp >> Value;
	player->SetName(Value);
	fin >> Temp >> Number;
	player->SetHitPoints(Number);
	fin >> Temp >> Number;
	player->SetMaxHitPoints(Number);
	fin >> Temp >> Number;
	player->SetKa(Number);
	fin >> Temp >> Number;
	player->SetMaxKa(Number);
	fin >> Temp >> Number;
	player->SetGold(Number);
	fin >> Temp >> Number;
	player->SetExperience(Number);
	fin >> Temp >> Number;
	player->SetExperienceNeeded(Number);
	fin >> Temp >> Number;
	player->SetLevel(Number);
	fin >> Temp >> Number;
	player->SetEvade(Number);
	fin >> Temp >> Number;
	player->SetStrength(Number);
	fin >> Temp >> Number;
	player->SetMind(Number);
	fin >> Temp >> Number;
	player->SetPositionX(Number);
	fin >> Temp >> Number;
	player->SetPositionY(Number);
	fin >> Temp >> Number;
	player->SetTotalKills(Number);
	fin >> Temp >> Truth;
	player->SetHasSpells(Truth);
	fin >> Temp >> Truth;
	player->SetMemberHasJoined(Truth);
	fin >> Temp >> Truth;
	player->SetIsInvisible(Truth);
	fin >> Temp;
	getline(fin, W);	W = ItemRepository::rotate(W);
	fin >> Temp;
	getline(fin, A);	A = ItemRepository::rotate(A);
	fin >> Temp >> Number;
	player->SetReactionElf(Number);
	fin >> Temp >> Number;
	player->SetReactionOrc(Number);
	fin >> Temp >> Number;
	player->SetReactionHuman(Number);
	fin >> Temp >> Number;;
	player->RaceKillCounts.ElfKillCount = Number;
	fin >> Temp >> Number;
	player->RaceKillCounts.OrcKillCount = Number;
	fin >> Temp >> Number;
	player->RaceKillCounts.HumanKillCount = Number;
	fin >> Temp >> Truth;
	player->PlotEventStates.Start = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.Priest1 = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.Priest2 = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.Priest3 = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.Priest4 = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.GreenDragon = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.BlueDragon = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.RedDragon = Truth;
	fin >> Temp >> Truth;
	player->PlotEventStates.Monk = Truth;
	fin >> Temp >> Truth;
	player->SetMusicIsOn(Truth);
	player->SetWeapon(Items->GetWeapon(W));
	player->SetArmor(Items->GetArmor(A));
	player->SetIsLoaded(true);
}

void SaveLoadGame::LoadInventory(vector<Item*>& playerInventory, ifstream& fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item* holder;
	string temp;
	string szHolder;

	playerInventory.clear();
	fin >> temp >> j;

	for (i = 0; i < j; i++)
	{
		holder = new Item;
		fin >> szHolder;	getline(fin, temp);	holder->SetName(ItemRepository::rotate(temp));
		fin >> szHolder >> temp;	holder->SetMapName(temp);
		fin >> szHolder >> Xtemp;	holder->SetPositionX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetPositionY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetType(Xtemp);
		fin >> szHolder >> Y;	holder->SetKeep(Y);
		fin >> szHolder >> Y;	holder->SetIsWeapon(Y);
		fin >> szHolder >> Y;	holder->SetIsArmor(Y);

		if (holder->GetIsWeapon())
			playerInventory.push_back(Items->GetWeapon(holder->GetName()));
		else if (holder->GetIsArmor())
			playerInventory.push_back(Items->GetArmor(holder->GetName()));
		else
			playerInventory.push_back(holder);
	}
}

void SaveLoadGame::LoadGround(vector<Item*>& worldInventory, ifstream& fin)
{
	unsigned int i;
	unsigned int j;
	int Xtemp;
	bool Y;
	Item* holder;
	string temp;
	string szHolder;

	worldInventory.clear();
	fin >> temp >> j;

	for (i = 0; i < j; i++)
	{
		holder = new Item;
		fin >> szHolder;	getline(fin, temp);	holder->SetName(ItemRepository::rotate(temp));
		fin >> szHolder >> temp;	holder->SetMapName(temp);
		fin >> szHolder >> Xtemp;	holder->SetPositionX(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetPositionY(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetCost(Xtemp);
		fin >> szHolder >> Xtemp;	holder->SetType(Xtemp);
		fin >> szHolder >> Y;	holder->SetKeep(Y);
		fin >> szHolder >> Y;	holder->SetIsWeapon(Y);
		fin >> szHolder >> Y;	holder->SetIsArmor(Y);

		if (holder->GetIsWeapon())
			worldInventory.push_back(Items->GetWeapon(holder->GetName()));
		else if (holder->GetIsArmor())
			worldInventory.push_back(Items->GetArmor(holder->GetName()));
		else
			worldInventory.push_back(holder);
	}
}

void SaveLoadGame::LoadMagic(vector<Magic*>& spells, ifstream& fin)
{
	unsigned int i;
	unsigned int j;
	string temp;
	string N;
	fin >> temp >> j;
	if (j == 0)
		return;
	for (i = 0; i < j; i++)
	{
		fin >> temp;
		getline(fin, N);
		spells.push_back(GetMagic(ItemRepository::rotate(N)));
	}
}

Magic* SaveLoadGame::GetMagic(string spellName)
{
	Magic* M = new Magic;
	if (spellName == "Minor Heal")
		M = new MinorHeal;
	if (spellName == "Major Heal")
		M = new MajorHeal;
	if (spellName == "Briar Bush")
		M = new BriarBush;
	if (spellName == "Snow")
		M = new Blizzard;
	if (spellName == "PerfectStorm")
		M = new PerfectStorm;
	if (spellName == "Drain Life")
		M = new DrainLife;
	if (spellName == "Drain Ka")
		M = new StealKa;
	if (spellName == "Flame Arrow")
		M = new FireArrow;
	if (spellName == "Fire")
		M = new Fire;
	if (spellName == "Lava")
		M = new Lava;
	if (spellName == "Strength")
		M = new Might;
	if (spellName == "Dispel")
		M = new Dispel;
	if (spellName == "Shock")
		M = new Shock;
	if (spellName == "Acid Rain")
		M = new AcidRain;
	if (spellName == "Lightning Bolt")
		M = new LightningBolt;
	if (spellName == "Poison")
		M = new Poison;
	if (spellName == "Summon Skeleton")
		M = new RaiseSkeleton;
	if (spellName == "Dark Strike")
		M = new DarkStrike;
	if (spellName == "Critical")
		M = new Critical;
	if (spellName == "Mind Control")
		M = new Control;
	return M;
}