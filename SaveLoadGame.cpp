#include "SaveLoadGame.h"

using namespace std;

SaveLoadGame::SaveLoadGame(ItemRepository* itemRepository, GameDisplay* gameDisplay)
{
	Items = itemRepository;
	Display = gameDisplay;
}

void SaveLoadGame::SaveGame(GameState* gameState)
{
	string Savefile = gameState->GetPlayer()->GetName();
	Savefile = Savefile + ".svg";
	ofstream fout;

	fout.open(Savefile.c_str());

	SavePlayer(gameState->GetPlayer(), fout);
	SaveMagic(gameState->GetPlayerSpells(), fout);
	SaveInventory(gameState->GetPlayerInventory(), fout);
	SaveGround(gameState->GetWorldItems(), fout);
	fout << "Map: " << gameState->GetMapName();

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
}

void SaveLoadGame::SaveOptions(MusicPlayer* musicPlayer, ofstream& fout)
{
	fout << "Music: " << musicPlayer->GetIsMusicOn() << endl;
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

void SaveLoadGame::LoadGame(string filename, GameState* gameState)
{
	string fName = filename + ".svg";
	string temp;
	string mapName;

	ifstream fin;
	fin.open(fName.c_str());
	if (fin.fail())
	{
		Display->DisplayError("ERROR LOADING SAVED CHARACTER");
		exit(0);
	};
	LoadPlayer(gameState->GetPlayer(), fin);
	LoadMagic(gameState->GetPlayerSpells(), fin);
	LoadInventory(gameState->GetPlayerInventory(), fin);
	LoadGround(gameState->GetWorldItems(), fin);
	fin >> temp >> mapName;
	gameState->SetMapName(mapName);

	fin.close();
}

void SaveLoadGame::LoadPlayer(Player* player, ifstream& fin)
{
	string temp;
	string value;
	int number;
	bool truth;
	string armorName;
	string weaponName;
	fin >> temp >> value;
	player->SetName(value);
	fin >> temp >> number;
	player->SetHitPoints(number);
	fin >> temp >> number;
	player->SetMaxHitPoints(number);
	fin >> temp >> number;
	player->SetKa(number);
	fin >> temp >> number;
	player->SetMaxKa(number);
	fin >> temp >> number;
	player->SetGold(number);
	fin >> temp >> number;
	player->SetExperience(number);
	fin >> temp >> number;
	player->SetExperienceNeeded(number);
	fin >> temp >> number;
	player->SetLevel(number);
	fin >> temp >> number;
	player->SetEvade(number);
	fin >> temp >> number;
	player->SetStrength(number);
	fin >> temp >> number;
	player->SetMind(number);
	fin >> temp >> number;
	player->SetPositionX(number);
	fin >> temp >> number;
	player->SetPositionY(number);
	fin >> temp >> number;
	player->SetTotalKills(number);
	fin >> temp >> truth;
	player->SetHasSpells(truth);
	fin >> temp >> truth;
	player->SetMemberHasJoined(truth);
	fin >> temp >> truth;
	player->SetIsInvisible(truth);
	fin >> temp;
	fin.get();
	getline(fin, weaponName);
	fin >> temp;
	fin.get();
	getline(fin, armorName);
	fin >> temp >> number;
	player->SetReactionElf(number);
	fin >> temp >> number;
	player->SetReactionOrc(number);
	fin >> temp >> number;
	player->SetReactionHuman(number);
	fin >> temp >> number;;
	player->RaceKillCounts.ElfKillCount = number;
	fin >> temp >> number;
	player->RaceKillCounts.OrcKillCount = number;
	fin >> temp >> number;
	player->RaceKillCounts.HumanKillCount = number;
	fin >> temp >> truth;
	player->PlotEventStates.Start = truth;
	fin >> temp >> truth;
	player->PlotEventStates.Priest1 = truth;
	fin >> temp >> truth;
	player->PlotEventStates.Priest2 = truth;
	fin >> temp >> truth;
	player->PlotEventStates.Priest3 = truth;
	fin >> temp >> truth;
	player->PlotEventStates.Priest4 = truth;
	fin >> temp >> truth;
	player->PlotEventStates.GreenDragon = truth;
	fin >> temp >> truth;
	player->PlotEventStates.BlueDragon = truth;
	fin >> temp >> truth;
	player->PlotEventStates.RedDragon = truth;
	fin >> temp >> truth;
	player->PlotEventStates.Monk = truth;
	player->SetWeapon(Items->GetWeapon(weaponName));
	player->SetArmor(Items->GetArmor(armorName));
	player->SetIsLoaded(true);
}

void SaveLoadGame::LoadOptions(MusicPlayer* musicPlayer, ifstream& fin)
{
	bool truth;
	string temp;
	fin >> temp >> truth;
	musicPlayer->SetIsMusicOn(truth);
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
		fin >> szHolder;
		fin.get();
		getline(fin, temp);
		holder->SetName(temp);
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
		fin >> szHolder;
		fin.get();
		getline(fin, temp);
		holder->SetName(temp);
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
	string spellName;
	fin >> temp >> j;
	if (j == 0)
		return;
	for (i = 0; i < j; i++)
	{
		fin >> temp;
		fin.get();
		getline(fin, spellName);
		spells.push_back(GetMagic(spellName));
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