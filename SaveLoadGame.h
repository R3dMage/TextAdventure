#pragma once
#include <vector>
#include <fstream>
#include "ISaveLoadGame.h"

class SaveLoadGame :
    public ISaveLoadGame
{
public:
	virtual void SaveGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map) override;
	virtual void LoadGame(Player* player, vector<Item*>& worldItems, vector<Item*>& playerInventory, vector<Magic*>& spells, string& map, string filename) override;
	
protected:
	void SaveInventory(vector<Item*>& inventory, ofstream& fout);
	void SaveGround(vector<Item*>& worldItems, ofstream& fout);
	void SaveMagic(vector<Magic*>& spells, ofstream& fout);
	void LoadInventory(vector<Item*>& playerInventory, ifstream& fin);
	void LoadGround(vector<Item*>& worldInventory, ifstream& fin);
	void LoadMagic(vector<Magic*>& spells, ifstream& fin);
	Magic* GetMagic(string spellName);
};

