#ifndef CREATURE_H
#define CREATURE_H

#include <windows.h>
#include <iostream>
#include <string>

#include "GameDisplay.h"
#include "Greeting.h"
#include "Player.h"
#include "Item.h"

class Creature{
public:
	Creature();

	void SetLevel(int);
	int GetLevel();
	void SetHitPoints(int);
	int GetHitPoints();
	void SetMaxHitPoints(int);
	int GetMaxHitPoints();
	void SetExperience(int);
	int GetExperience();
	void SetDamage(int);
	int GetDamage();
	void SetDamageModifier(int);
	int GetDamageModifier();
	int GetDefense();
	void SetEvade(int);
	int GetEvade();
	void SetGold(int);
	int GetGold();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	void SetMagicDefense(int);
	int GetMagicDefense();
	void SetName(std::string);
	bool GetHasBanter();
	void SetTalkTo(bool);
	bool GetTalkTo();
	void SetRunAway(bool);
	void SetKa(int);
	int GetKa();
	int GetMaxKa();
	void SetState(int);
	int GetState();
	bool GetRunAway();
	void SetDontMove(bool);
	bool GetDontMove();
	std::string GetType();
	std::string GetName();
	std::string GetWeakness();
	std::string GetMap();
	std::string GetMusic();
	virtual Greeting GetGreeting(Player* player);
	virtual void SetMap(std::string);

	void LoadPosition(int X, int Y);
	virtual void Replenish();
	virtual Item* Body(std::string) const = 0;
	virtual void Win(Player *player, GameDisplay* display);
	virtual bool DroppedItem();
	virtual void Attack(Player *player, GameDisplay* display);
	virtual string Token();
	virtual bool TalkTo(Player *player);
	virtual std::vector<std::string> Banter();

protected:
	int 	Level;
	int		HitPoints;
	int		MaxHP;
	int		Experience;
	int		BaseDamage;
	int		DamageModifier;
	int		Defense;
	int		MagicDefense;
	int		Evade;
	int		Gold;
	int		X;
	int		Y;
	int		Ka;
	int		MaxKa;
	int		State;
	bool	HasBanter;
	bool	CanTalkTo;
	bool	RunAway;
	bool	DontMove;
	bool	IsAsleep;
	bool	IsPoisoned;
	std::string  Type;
	std::string	Name;
	std::string  Map;
	std::string  Weakness;
	std::string  Music;

};
#endif 