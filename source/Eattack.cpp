#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"

//============================================================================================
// Elf
//============================================================================================
void Elf::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string heal = "Great god of the land, heal thy servant!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayTextAndPause("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		cure = rand() % 30 + 11;
		display->DisplayCure("The Elf is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->DisplayText("                          ", 13, 8, white);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayTextAndPause(GetName() + " attacks you", 13, 11, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Elven Mage
//============================================================================================
void ElvenMage::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayTextAndPause("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		cure = rand() % 30 + 11;
		display->DisplayCure("The Elf is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->DisplayText("                                                            ", 13, 8, white);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(snow);
			display->DisplayTextAndPause(GetName() + " cast Snow!", 13, 11, white);
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 20 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Elven Warrior
//============================================================================================
void ElvenWarrior::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		damage = rand() % 20 + 10;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(strike);
		display->DisplayText("The Elven Warrior strikes out with immense speed!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                            ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// Ice Elf
//============================================================================================
void IceElf::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && Ka >= 6)
	{
		damage = rand() % 20 + 28;
		SetKa(Ka - 6);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Ice Elf hurls a magical icicle at you!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			display->DisplayText("You narrowly escape the frozen pointy thing!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
		}

		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayDamage("Enemy's Damage:", damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// Fire Elf
//============================================================================================
void FireElf::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && Ka >= 10)
	{
		damage = rand() % 30 + 48;
		SetKa(Ka - 10);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Fire Elf sprays fire from his hand!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			display->DisplayText("You narrowly escape superheated doom!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
		}
		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayDamage("Enemy's Damage:", damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// Elven Ranger
//============================================================================================
void ranger::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";
	string heal = "Great god of the land, heal thy servant!";
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && Ka >= 10 && HitPoints > 35)
	{
		switch (Level)
		{
		case 6:
		case 7:
			damage = rand() % 25 + 20;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(strike);
			display->DisplayText("The Elven Ranger strikes out with immense speed!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			display->DisplayText("                                                            ", 13, 9, white);
			display->DisplayDamage("Enemy's Damage:", damage);
			SetKa(Ka - 10);
			break;
		case 8:
		case 9:
			damage = rand() % 30 + 30;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
			break;
		}
	}
	else if (HitPoints <= 35 && Ka >= 4)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 11;
		display->DisplayCure("The Elf is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->DisplayText("                                                            ", 13, 8, white);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Orc
//============================================================================================
void Orc::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	Armor* arm;

	if (HitPoints < 10)
		RunAway = true;
	else
	{
		arm = player->GetArmor();
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Orc Sorceror
//============================================================================================
void OrcSorceror::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string arrow = "Missle strike your mark with accuracy!";
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(drain);
		display->DisplayText("You grow cold, and feel like something was taken.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		damage = rand() % 20 + 20;
		cure = damage;
		display->DisplayDamage("Enemy's Damage:", damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayCure("The Orc Sorceror is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(fire);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Fire";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 30 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(arrow);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast flame arrow";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Orc Soldier
//============================================================================================
void OrcSoldier::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Pathetic human feel the wrath of the orcs!!!";

	if (HitPoints <= 10 && Ka >= 5)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(strike);
		display->DisplayText("The Orc Soldier strikes out with immense power!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                            ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Fire Orc
//============================================================================================
void FireOrc::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Fire falls from the sky!!!";

	if (choice > 75 && Ka >= 10)
	{
		damage = rand() % 35 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(strike);
		display->DisplayText("You are pelted with scalding hot rocks from above", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                            ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 10);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Ice Orc
//============================================================================================
void IceOrc::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "NOW! Deep freeze wind!";

	if (choice > 75 && Ka >= 10)
	{
		damage = rand() % 25 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(strike);
		display->DisplayText("Wind colder than what seems possible chills you to the bones", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                            ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 10);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Orc Wanderer
//============================================================================================
void OrcWanderer::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	//bool nodam;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";


	if (HitPoints <= 10 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(drain);
		display->DisplayText("You grow cold, and feel like something was taken.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		damage = rand() % 35 + 20;
		cure = damage;
		display->DisplayDamage("Enemy's Damage:", damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayCure("The Orc Wanderer is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 50;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(fire);
			display->DisplayText("The Orc Wanderer casts fire!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		else
		{
			damage = rand() % BaseDamage + DamageModifier;
			if (State == 1)
				X = damage / 8;
			else
				X = 0;
			damage += X;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " strikes out at you!";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Human Wizard
//============================================================================================
void Wizard::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	bool nodam = false;
	Armor* arm;
	arm = player->GetArmor();
	string arain = "Tainted water, pour from the sky!";
	string szshock = "Electricity flow forth and electrify my opponent!";
	string D = "Universe, set yourself to rights, the way you should be.";

	if (HitPoints <= 10 && Ka >= 10)
	{
		damage = rand() % 20 + 20;
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(arain);
		display->DisplayText("Acid rain falls from the sky!!!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X > 50 && player->GetMagicStatus() == 1)
		{
			damage = 0;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(D);
			player->SetMagicStatus(0);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Dispel";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
			nodam = true;
		}
		else if (X < 50 && Ka > 4)
		{
			damage = rand() % 40 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(szshock);
			display->DisplayText("Electricy flies toward you, and your muscles tense", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}

		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		if (!nodam)
		{
			damage -= arm->GetDefenseModifier();
			if (damage < 0)
				damage = 1;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayDamage("Enemy's Damage:", damage);
		}
	}
}

//============================================================================================
// Human Adventurer
//============================================================================================
void Adventurer::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	bool nodam;
	Armor* arm;
	arm = player->GetArmor();
	string skel = "Bones which death hath taken, aid me in my struggle";
	string str = "god of war grant me strength!";
	string drain = "Everything is free for the taking!";


	if (HitPoints <= 10 && Ka >= 4 && Level > 3)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(drain);
		display->DisplayText("You grow cold, and feel like something was taken.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		damage = rand() % 20 + 20;
		cure = damage;
		display->DisplayDamage("Enemy's Damage:", damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayCure("The Adventurer is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else if (State == 0 && Ka >= 4 && Level > 2)
	{
		damage = 0;
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(str);
		State = 1;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " has become visably stronger!!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
		nodam = true;
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10 && Level > 5)
		{
			damage = rand() % 50 + 50;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(skel);
			display->DisplayText("Skeletal hands strike from the soil!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		else
		{
			damage = rand() % BaseDamage + DamageModifier;
			if (State == 1)
				X = damage / 8;
			else
				X = 0;
			damage += X;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you!";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// Stargoyle
//============================================================================================
void Stargoyle::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 85)
	{
		damage = rand() % 100 + 100;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Stargoyle points at the heavens and laughs", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("You see a huge meteor tearing through the atmosphere, at you!", 13, 11, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Giant Spider
//============================================================================================
void GiantSpider::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	damage = rand() % BaseDamage + DamageModifier;
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayText(GetName(), 13, 11, white);
	cout << " Attacks you!";
	display->DisplayTextAndPause("", 79, 29, white);
	display->DisplayDamage("Enemy's Damage:", damage);
	//player->DisplayInfo();
	
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			display->DisplayText("You have been poisoned.", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
		}
		player->SetIsPoisoned(true);
	}
}


//============================================================================================
// Ghost
//============================================================================================
void Ghost::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The ghost reaches out and touches you, with hands like ice.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                            ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// Magmaman
//============================================================================================
void Magmaman::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 35 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Magmaman blasts searing hot wind at you from his mouth", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}


//============================================================================================
// Frost Giant
//============================================================================================
void FrostGiant::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Frost Giant blows bone-chilling wind at you from his mouth", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Storm Giant
//============================================================================================
void StormGiant::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 60 + 30;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Storm Giant strikes you with lightning!!!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Nymph
//============================================================================================
void Nymph::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	int R = 0;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 50 && !player->GetIsAsleep())
	{
		display->DisplayText("The Nymph embraces you lovingly...", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		R = rand() % 100 + 1;
		if (R > player->GetMind())
		{
			player->SetIsAsleep(true);
			display->DisplayText("", 13, 9, white);
			display->DisplayText("The Nymph lulls you to sleep in her arms...", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			display->DisplayText("                                                           ", 13, 9, white);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " stabs you with her long dagger!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
	if (player->GetIsAsleep())
	{
		R = rand() % 100 + 1;
		if (R < player->GetMind())
		{
			display->DisplayText("", 13, 9, white);
			display->DisplayText("You shake yourself free of her loveliness!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			display->DisplayText("                                                           ", 13, 9, white);
		}
	}
}

//============================================================================================
// Ice Wizard
//============================================================================================
void IceWizard::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Frigid wind sting my enemy!";
	string avalanche = "Snow! Consume my foe!";

	if (HitPoints <= 28 && Ka >= 4)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(breeze);
		display->DisplayText("A slight breeze revitalizes the Ice Wizard.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 21;
		display->DisplayCure("The Ice Wizard is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(avalanche);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Snow avalanches out of nowhere!!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(chill);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " icy wind rips into you!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Snowman
//============================================================================================
void Snowman::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Snowman throws a big, icy snowball at you!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cout << "And laughs!";
		display->DisplayText("                                                           ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Treeman
//============================================================================================
void Treeman::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string slam = "Now, face pain human!";
	string heal = "Great god of the land, heal thy servant!";

	if (HitPoints <= 20 && Ka >= 5)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("Light shines down from above engulfing the Treeman in brightness", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 16;
		display->DisplayCure("The Treeman is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka >= 10)
		{
			damage = rand() % 40 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(slam);
			display->DisplayText(GetName(), 13, 11, white);
			cout << "Branches reach down, pick you up and slam you hard into the ground";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		else if (X > 10 && X < 50 && Ka > 5)
		{
			damage = rand() % 20 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 5;
		}
		else
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " bashes you with heavy limbs!";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}


//============================================================================================
// Fire Demon
//============================================================================================
void FireDemon::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75)
	{
		choice = rand() % 100 + 1;
		if (choice < 50)
		{
			damage = rand() % 20 + 30;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayText("", 13, 9, white);
			display->DisplayText("The Fire Demon throws a big fireball at you!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			cout << "And laughs!";
			display->DisplayText("                                                           ", 13, 9, white);
			display->DisplayDamage("Enemy's Damage:", damage);
		}
		else
		{
			damage = rand() % 20 + 40;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->DisplayText("", 13, 9, white);
			display->DisplayText("The Fire Demon grabs you, and engulfs you in flames!!!", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
			display->DisplayDamage("Enemy's Damage:", damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Hydra
//============================================================================================
void Hydra::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText("", 13, 9, white);
		display->DisplayText("The Hydra breathes noxious gas in your direction!", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayText("                                                           ", 13, 9, white);
		display->DisplayDamage("Enemy's Damage:", damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " bites you!";
		display->DisplayTextAndPause("", 79, 29, white);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Centipede
//============================================================================================
void Centipede::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	damage = rand() % BaseDamage + DamageModifier;
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayText(GetName(), 13, 11, white);
	cout << " Attacks you!";
	display->DisplayTextAndPause("", 79, 29, white);
	display->DisplayDamage("Enemy's Damage:", damage);
	// player->DisplayInfo();
	
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			display->DisplayText("You have been poisoned.", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Vampire
//============================================================================================
void Vampire::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	damage = rand() % BaseDamage + DamageModifier;
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayText(GetName(), 13, 11, white);
	cout << " Attacks you!";
	display->DisplayTextAndPause("", 79, 29, white);
	display->DisplayDamage("Enemy's Damage:", damage);
	damage = damage / 4;
	SetHitPoints(GetHitPoints() + damage);
	//player->DisplayInfo();
	if (Poison < 15)
	{
		if (!player->GetIsPoisoned())
		{
			display->DisplayText("You have been poisoned.", 13, 11, white);
			display->DisplayTextAndPause("", 79, 29, white);
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Acolyte
//============================================================================================
void Acolyte::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string windstorm = "Wind! Strikedown my opponent!";
	string cyclone = "Wind! Destroy my Enemy's!!!";
	string heal = "Gentle zephyr caress, and heal my wounds.";

	if (HitPoints <= 40 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("A slight breeze wafts through the fight.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 50 + 21;
		display->DisplayCure("The Acolyte is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(cyclone);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Cyclone!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 20 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(windstorm);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Windstorm!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}


//============================================================================================
// Wood Priest
//============================================================================================
void WoodPriest::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";

	if (HitPoints <= 25 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 40 + 11;
		display->DisplayCure("The priest is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 35;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(snow);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Snow!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 30 + 25;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Ice Priest
//============================================================================================
void IcePriest::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Ice!! Deep freeze this fool!";
	string avalanche = "Glacier, move at my command!";

	if (HitPoints <= 28 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(breeze);
		display->DisplayText("A slight breeze revitalizes the priest.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 21;
		display->DisplayCure("The priest is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(avalanche);
			cout << "A glacier falls on you out of nowhere!!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(chill);
			cout << "Ice punctures and tears at you!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Fire Priest
//============================================================================================
void FirePriest::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string potion = "Ah, a potion. These are great!";
	string flame = "Fire!!! Show no mercy to this man!";
	string landslide = "Stones fall from above!!!";

	if (HitPoints <= 30)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(potion);
		display->DisplayText("The priest chugs a potion", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 21;
		display->DisplayCure("The priest is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(landslide);
			cout << "Boulders fall on you from high above";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(flame);
			cout << "Flames fly from his fingers torching you";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Wind Priest
//============================================================================================
void WindPriest::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string heal = "Great god of the land, heal thy servant!";
	string arain = "Tainted water, pour from the sky!";
	string lightning = "Powers above smite my enemy!";

	if (HitPoints <= 60 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 30 + 21;
		display->DisplayCure("The priest is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 60 + 50;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(lightning);
			cout << "A bolt of lightning strikes you!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 30;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(arain);
			cout << "Acid rain falls upon you burning, and scalding you";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// God of Life
//============================================================================================
void GodOfLife::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string lifestop = "Great land put cast off your pain to this man!";
	string heal = "Great land of mine, lend me your energy!";

	if (HitPoints <= 40 && Ka >= 10)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(heal);
		display->DisplayText("Light shines down from above engulfing the god in brightness", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		cure = rand() % 100 + 101;
		display->DisplayCure("The god is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 20)
		{
			damage = rand() % 80 + 50;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(lifestop);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Pain!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 20;
		}
		if (X < 20 && Ka > 10)
		{
			damage = rand() % 60 + 30;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(snow);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast Snow!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 10;
		}
		if (X > 20 && X < 80 && Ka > 4)
		{
			damage = rand() % 40 + 40;
			display->DisplayText("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->DisplayText(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			display->DisplayTextAndPause("", 79, 29, white);
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->DisplayText(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			display->DisplayTextAndPause("", 79, 29, white);
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}
//============================================================================================
// God of Chaos
//============================================================================================
void GodOfChaos::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string magma = "Earth unleash your pure fury!";

	X = rand() % 100 + 1;
	if (X < 10 && Ka > 20)
	{
		damage = rand() % 80 + 50;
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(magma);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " cast Pain!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 20;
	}
	if (X < 20 && Ka > 10)
	{
		damage = rand() % 60 + 30;
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(snow);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " cast Snow!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 10;
	}
	if (X > 20 && X < 80 && Ka > 4)
	{
		damage = rand() % 40 + 40;
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(fire);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " cast flame";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you with his staff";
		display->DisplayTextAndPause("", 79, 29, white);
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayDamage("Enemy's Damage:", damage);
}
//============================================================================================
// God of War
//============================================================================================
void GodOfWar::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string hammer = "Earth unleash your pure fury!";

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 90 + 60;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " swings his massive hammer at you";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks with his battle axe";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " swings his sword";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " punches you!";
		display->DisplayTextAndPause("", 79, 29, white);
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayDamage("Enemy's Damage:", damage);
}

//============================================================================================
// God of Death
//============================================================================================
void GodOfDeath::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string drain = "What was yours is now mine!";

	if (HitPoints <= 50 && Ka >= 20)
	{
		display->DisplayText("", 13, 9, white);
		display->SlowDisplay(drain);
		display->DisplayText("You grow cold, and feel like something was taken.", 13, 11, white);
		display->DisplayTextAndPause("", 79, 29, white);
		damage = rand() % 100 + 90;
		cure = damage;
		display->DisplayDamage("Enemy's Damage:", damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayCure("The god of death is healed:", cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " Attacks you with his scythe";
		display->DisplayTextAndPause("", 79, 29, white);

		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->DisplayDamage("Enemy's Damage:", damage);
	}
}

//============================================================================================
// Peaceful Monk
//============================================================================================

// He's getting regular Attack patterns, cuz all he's going to do is Attack when he can.

//============================================================================================
// Green Dragon
//============================================================================================
void GreenDragon::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 100 + 60;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes a superheated fire at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes fire at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		display->DisplayTextAndPause("", 79, 29, white);
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayDamage("Enemy's Damage:", damage);
}

//============================================================================================
// Blue Dragon
//============================================================================================
void BlueDragon::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 100 + 60;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes a superchilled ice at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes icy wind at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		display->DisplayTextAndPause("", 79, 29, white);
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayDamage("Enemy's Damage:", damage);
}

//============================================================================================
// Red Dragon
//============================================================================================
void RedDragon::Attack(Player *player, GameDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 200 + 100;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes liquified steel fire at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " breathes lava at you!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->DisplayText("", 13, 9, white);
		display->DisplayText(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		display->DisplayTextAndPause("", 79, 29, white);
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->DisplayText(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		display->DisplayTextAndPause("", 79, 29, white);
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->DisplayDamage("Enemy's Damage:", damage);
}