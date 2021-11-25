#pragma once
#include <vector>
#include <fstream>
#include "ISaveLoadGame.h"
#include "ItemRepository.h"
#include "GameDisplay.h"
#include "MusicPlayer.h"

class SaveLoadGame :
    public ISaveLoadGame
{
public:
	SaveLoadGame(ItemRepository* itemRepository, GameDisplay* gameDisplay);
	virtual void SaveGame(GameState* gameState) override;
	virtual void LoadGame(string filename, GameState* gameState) override;
	virtual void SaveSettings(GameSettings* gameSettings) override;
	virtual void LoadSettings(GameSettings* gameSettings) override;
	
protected:
	void SavePlayer(Player* player, ofstream& fout);
	void SaveOptions(MusicPlayer* musicPlayer, ofstream& fout);
	void SaveInventory(vector<Item*>& inventory, ofstream& fout);
	void SaveGround(vector<Item*>& worldItems, ofstream& fout);
	void SaveMagic(vector<Magic*>& spells, ofstream& fout);
	void LoadPlayer(Player* player, ifstream& fin);
	void LoadOptions(MusicPlayer* musicPlayer, ifstream& fin);
	void LoadInventory(vector<Item*>& playerInventory, ifstream& fin);
	void LoadGround(vector<Item*>& worldInventory, ifstream& fin);
	void LoadMagic(vector<Magic*>& spells, ifstream& fin);
	Magic* GetMagic(string spellName);

	ItemRepository* Items;
	GameDisplay* Display;
};