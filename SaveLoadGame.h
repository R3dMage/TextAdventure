#pragma once
#include <vector>
#include <fstream>
#include "ISaveLoadGame.h"
#include "ItemRepository.h"
#include "GameDisplay.h"

class SaveLoadGame :
    public ISaveLoadGame
{
public:
	SaveLoadGame(ItemRepository* itemRepository, GameDisplay* gameDisplay);
	virtual void SaveGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map) override;
	virtual void LoadGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map, string filename) override;
	
protected:
	void SavePlayer(Player* player, ofstream& fout);
	void SaveInventory(vector<Item*>& inventory, ofstream& fout);
	void SaveGround(vector<Item*>& worldItems, ofstream& fout);
	void SaveMagic(vector<Magic*>& spells, ofstream& fout);
	void LoadPlayer(Player* player, ifstream& fin);
	void LoadInventory(vector<Item*>& playerInventory, ifstream& fin);
	void LoadGround(vector<Item*>& worldInventory, ifstream& fin);
	void LoadMagic(vector<Magic*>& spells, ifstream& fin);
	Magic* GetMagic(string spellName);

	ItemRepository* Items;
	GameDisplay* Display;
};