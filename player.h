#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <time.h>
#include "Weapon.h"
#include "Armor.h"

struct RaceReactionIndex{
	int Elf;
	int Human;
	int Orc;
};
struct PlayerKillCounts{
	int ElfKillCount;
	int HumanKillCount;
	int OrcKillCount;
};
struct GameEvents{
	bool Start;
	bool Priest1;
	bool Priest2;
	bool Priest3;
	bool Priest4;
	bool GreenDragon;
	bool BlueDragon;
	bool RedDragon;
	bool Monk;
};

class Player {

public:
	Player();

	void SetName(string);
	string GetName();
	void SetWeapon(Weapon*);
	Weapon* GetWeapon();
	void SetArmor(Armor*);
	Armor* GetArmor();
	void SetPositionX(int);
	int GetPositionX();
	void SetPositionY(int);
	int GetPositionY();
	void SetStrength(int);
	int GetStrength();
	void SetMind(int);
	int GetMind();
	void SetGold(int);
	int GetGold();
	void SetMaxHitPoints(int);
	int GetMaxHitPoints();
	void SetHitPoints(int);
	int GetCurrentHitPoints();
	void SetExperience(int);
	int GetExperience();
	void SetLevel(int);
	int GetLevel();
	void SetKa(int);
	int GetCurrentKa();
	void SetMaxKa(int);
	int GetMaxKa();
	void SetExperienceNeeded(int);
	int GetExperienceForNextLevel();
	void SetEvade(int);
	int GetEvade();
	void SetTotalKills(int);
	int GetTotalKills();
	void SetPauseDuration(int);
	int GetPauseDuration();
	void SetReactionElf(int);
	int GetReactionElf();
	void SetReactionHuman(int);
	int GetReactionHuman();
	void SetReactionOrc(int);
	int GetReactionOrc();
	void SetMagicStatus(int);
	int GetMagicStatus();
	bool HasLearnedSpells();
	void SetHasSpells(bool);
	bool GetMemberHasJoined();
	void SetMemberHasJoined(bool);
	void SetIsPoisoned(bool);
	bool GetIsPoisoned();
	void SetIsLoaded(bool);
	bool GetIsLoaded();
	void SetIsAsleep(bool);
	bool GetIsAsleep();
	void SetIsInvisible(bool);
	bool GetIsInvisible();

	bool ReachedNextLevel();
	void IncreaseLevel();

	PlayerKillCounts RaceKillCounts;
	GameEvents PlotEventStates;
	RaceReactionIndex RaceReactions;
	

private:
	//time_h	p_time;						// Time in game
	string	Name;							// Player's Name
	Weapon*	EquippedWeapon;					// Current Weapon
	Armor*	EquippedArmor;					// Current Armor
	int		PositionX;								// Players X coordinate on the current map
	int		PositionY;								// Players Y coordinate on the current map
	int		Strength;						// Strength
	int		Mind;							// Mental Ability
	int		Gold;							// Um, Gold
	int		Evade;							// Chance to evade an attack
	int		MaxHP;							// Max Hit Points
	int		HP;								// Current Hit Points
	int		Experience;						// Experience
	int		Level;							// Level	
	int		Ka;								// Current Magic Points
	int		MaxKa;							// Max Magic Points
	int		ExperienceNeededForNextLevel;	// Experience for next level
	int		TotalKills;						// # of kills
	int		PauseDuration;					// Pause duration in milliseconds
	int		MagicStatus;					// Current state
	bool	IsInFight;						// To determine if there is a fight
	bool	IsPoisoned;						// Poison status
	bool	IsAsleep;						// Sleep Status
	bool	HasSpells;						// Whether or not player has spells
	bool	MemberHasJoined;				// ???
	bool	IsLoaded;						// Whether or not a character has been loaded

/* =========================================================
   These will be player specific options that can be changed
   in the option menu should the player so choose. 
   =========================================================*/

	bool	Invisible;		// Sometimes you want to be invisible to enemies
};
#endif