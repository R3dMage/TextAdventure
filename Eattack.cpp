#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"

//============================================================================================
// Elf
//============================================================================================
void Elf::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string heal = "Great god of the land, heal thy servant!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		display->text("                                                            ", 13, 9, white);
		display->text("The Elf is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->text("                          ", 13, 8, white);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "              ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Elven Mage
//============================================================================================
void ElvenMage::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		display->text("                                                            ", 13, 9, white);
		display->text("The Elf is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->text("                                                            ", 13, 8, white);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(snow);
			display->text(GetName(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 20 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->text(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Elven Warrior
//============================================================================================
void ElvenWarrior::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";

	if (HitPoints <= 10 && Ka >= 4)
	{
		damage = rand() % 20 + 10;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->SlowDisplay(strike);
		display->text("The Elven Warrior strikes out with immense speed!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// Ice Elf
//============================================================================================
void IceElf::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->text("The Ice Elf hurls a magical icicle at you!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			display->text("You narrowly escape the frozen pointy thing!", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}

		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                 ";
			display->DisplayDamage(damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// Fire Elf
//============================================================================================
void FireElf::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->text("The Fire Elf sprays fire from his hand!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			display->text("You narrowly escape superheated doom!", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                 ";
			display->DisplayDamage(damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// Elven Ranger
//============================================================================================
void ranger::Attack(Player *player, TextDisplay* display)
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
			display->text("", 13, 9, white);
			display->SlowDisplay(strike);
			display->text("The Elven Ranger strikes out with immense speed!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			display->text("                                                            ", 13, 9, white);
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                             ";
			display->DisplayDamage(damage);
			SetKa(Ka - 10);
			break;
		case 8:
		case 9:
			damage = rand() % 30 + 30;
			display->text("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->text(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
			break;
		}
	}
	else if (HitPoints <= 35 && Ka >= 4)
	{
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		display->text("                                                            ", 13, 9, white);
		display->text("The Elf is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
		display->text("                                                            ", 13, 8, white);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Orc
//============================================================================================
void Orc::Attack(Player *player, TextDisplay* display)
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
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Orc Sorceror
//============================================================================================
void OrcSorceror::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(drain);
		display->text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		damage = rand() % 20 + 20;
		cure = damage;
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                       ";
		display->DisplayDamage(damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("                                                            ", 13, 9, white);
		display->text("The Orc Sorceror is healed: ", 13, 8, white);
		display->num(cure, 41, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(fire);
			display->text(GetName(), 13, 11, white);
			cout << " cast Fire";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 30 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(arrow);
			display->text(GetName(), 13, 11, white);
			cout << " cast flame arrow";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Orc Soldier
//============================================================================================
void OrcSoldier::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Pathetic human feel the wrath of the orcs!!!";

	if (HitPoints <= 10 && Ka >= 5)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->SlowDisplay(strike);
		display->text("The Orc Soldier strikes out with immense power!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Fire Orc
//============================================================================================
void FireOrc::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(strike);
		display->text("You are pelted with scalding hot rocks from above", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 10);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Ice Orc
//============================================================================================
void IceOrc::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(strike);
		display->text("Wind colder than what seems possible chills you to the bones", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 10);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Orc Wanderer
//============================================================================================
void OrcWanderer::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(drain);
		display->text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		damage = rand() % 35 + 20;
		cure = damage;
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                       ";
		display->DisplayDamage(damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("                                                            ", 13, 9, white);
		display->text("The Adventurer is healed: ", 13, 8, white);
		display->num(cure, 41, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 50;
			display->text("", 13, 9, white);
			display->SlowDisplay(fire);
			display->text("The Orc Wanderer casts fire!", 13, 11, white);
			Sleep(player->GetPauseDuration());
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
			display->text(GetName(), 13, 11, white);
			cout << " strikes out at you!";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Human Wizard
//============================================================================================
void Wizard::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(arain);
		display->text("Acid rain falls from the sky!!!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X > 50 && player->GetMagicStatus() == 1)
		{
			damage = 0;
			display->text("", 13, 9, white);
			display->SlowDisplay(D);
			player->SetMagicStatus(0);
			display->text(GetName(), 13, 11, white);
			cout << " cast Dispel";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
			nodam = true;
		}
		else if (X < 50 && Ka > 4)
		{
			damage = rand() % 40 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(szshock);
			display->text("Electricy flies toward you, and your muscles tense", 13, 11, white);
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}

		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		if (!nodam)
		{
			damage -= arm->GetDefenseModifier();
			if (damage < 0)
				damage = 1;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                    ";
			display->DisplayDamage(damage);
		}
	}
}

//============================================================================================
// Human Adventurer
//============================================================================================
void Adventurer::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(drain);
		display->text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		damage = rand() % 20 + 20;
		cure = damage;
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                       ";
		display->DisplayDamage(damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("                                                            ", 13, 9, white);
		display->text("The Adventurer is healed: ", 13, 8, white);
		display->num(cure, 41, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else if (State == 0 && Ka >= 4 && Level > 2)
	{
		damage = 0;
		display->text("", 13, 9, white);
		display->SlowDisplay(str);
		State = 1;
		display->text(GetName(), 13, 11, white);
		cout << " has become visably stronger!!";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
		nodam = true;
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10 && Level > 5)
		{
			damage = rand() % 50 + 50;
			display->text("", 13, 9, white);
			display->SlowDisplay(skel);
			display->text("Skeletal hands strike from the soil!", 13, 11, white);
			Sleep(player->GetPauseDuration());
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
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you!";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// Stargoyle
//============================================================================================
void Stargoyle::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 85)
	{
		damage = rand() % 100 + 100;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Stargoyle points at the heavens and laughs", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("You see a huge meteor tearing through the atmosphere, at you!", 13, 11, white);
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Giant Spider
//============================================================================================
void GiantSpider::Attack(Player *player, TextDisplay* display)
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
	display->text(GetName(), 13, 11, white);
	cout << " Attacks you!";
	Sleep(player->GetPauseDuration());
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "              ";
	display->DisplayDamage(damage);
	//player->DisplayInfo();
	
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			display->text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}


//============================================================================================
// Ghost
//============================================================================================
void Ghost::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The ghost reaches out and touches you, with hands like ice.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                            ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// Magmaman
//============================================================================================
void Magmaman::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 35 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Magmaman blasts searing hot wind at you from his mouth", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}


//============================================================================================
// Frost Giant
//============================================================================================
void FrostGiant::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Frost Giant blows bone-chilling wind at you from his mouth", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Storm Giant
//============================================================================================
void StormGiant::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 60 + 30;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Storm Giant strikes you with lightning!!!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Nymph
//============================================================================================
void Nymph::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	int R = 0;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 50 && !player->GetIsAsleep())
	{
		display->text("The Nymph embraces you lovingly...", 13, 11, white);
		Sleep(player->GetPauseDuration());
		R = rand() % 100 + 1;
		if (R > player->GetMind())
		{
			player->SetIsAsleep(true);
			display->text("", 13, 9, white);
			display->text("The Nymph lulls you to sleep in her arms...", 13, 11, white);
			Sleep(player->GetPauseDuration());
			display->text("                                                           ", 13, 9, white);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " stabs you with her long dagger!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
	if (player->GetIsAsleep())
	{
		R = rand() % 100 + 1;
		if (R < player->GetMind())
		{
			display->text("", 13, 9, white);
			display->text("You shake yourself free of her loveliness!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			display->text("                                                           ", 13, 9, white);
		}
	}
}

//============================================================================================
// Ice Wizard
//============================================================================================
void IceWizard::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(breeze);
		display->text("A slight breeze revitalizes the Ice Wizard.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		display->text("                                                            ", 13, 9, white);
		display->text("The Ice Wizard is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(avalanche);
			display->text(GetName(), 13, 11, white);
			cout << " Snow avalanches out of nowhere!!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(chill);
			display->text(GetName(), 13, 11, white);
			cout << " icy wind rips into you!";
			Sleep(player->GetPauseDuration());
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Snowman
//============================================================================================
void Snowman::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Snowman throws a big, icy snowball at you!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cout << "And laughs!";
		display->text("                                                           ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Treeman
//============================================================================================
void Treeman::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the Treeman in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 16;
		display->text("                                                            ", 13, 9, white);
		display->text("The Treeman is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka >= 10)
		{
			damage = rand() % 40 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(slam);
			display->text(GetName(), 13, 11, white);
			cout << "Branches reach down, pick you up and slam you hard into the ground";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		else if (X > 10 && X < 50 && Ka > 5)
		{
			damage = rand() % 20 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->text(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			Ka -= 5;
		}
		else
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " bashes you with heavy limbs!";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}


//============================================================================================
// Fire Demon
//============================================================================================
void FireDemon::Attack(Player *player, TextDisplay* display)
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
			display->text("", 13, 9, white);
			display->text("The Fire Demon throws a big fireball at you!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			cout << "And laughs!";
			display->text("                                                           ", 13, 9, white);
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                 ";
			display->DisplayDamage(damage);
		}
		else
		{
			damage = rand() % 20 + 40;
			player->SetHitPoints(player->GetCurrentHitPoints() - damage);
			display->text("", 13, 9, white);
			display->text("The Fire Demon grabs you, and engulfs you in flames!!!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			display->text("Enemies Damage: ", 13, 11, white);
			cout << damage << "                                 ";
			display->DisplayDamage(damage);
		}
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Hydra
//============================================================================================
void Hydra::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && Ka >= 4)
	{
		damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("", 13, 9, white);
		display->text("The Hydra breathes noxious gas in your direction!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		display->text("                                                           ", 13, 9, white);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                 ";
		display->DisplayDamage(damage);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text(GetName(), 13, 11, white);
		cout << " bites you!";
		Sleep(player->GetPauseDuration());
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                             ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Centipede
//============================================================================================
void Centipede::Attack(Player *player, TextDisplay* display)
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
	display->text(GetName(), 13, 11, white);
	cout << " Attacks you!";
	Sleep(player->GetPauseDuration());
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "              ";
	display->DisplayDamage(damage);
	// player->DisplayInfo();
	
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			display->text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Vampire
//============================================================================================
void Vampire::Attack(Player *player, TextDisplay* display)
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
	display->text(GetName(), 13, 11, white);
	cout << " Attacks you!";
	Sleep(player->GetPauseDuration());
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "              ";
	display->DisplayDamage(damage);
	damage = damage / 4;
	SetHitPoints(GetHitPoints() + damage);
	//player->DisplayInfo();
	if (Poison < 15)
	{
		if (!player->GetIsPoisoned())
		{
			display->text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Acolyte
//============================================================================================
void Acolyte::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string windstorm = "Wind! Strikedown my opponent!";
	string cyclone = "Wind! Destroy my enemies!!!";
	string heal = "Gentle zephyr caress, and heal my wounds.";

	if (HitPoints <= 40 && Ka >= 10)
	{
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("A slight breeze wafts through the fight.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 50 + 21;
		display->text("                                                            ", 13, 9, white);
		display->text("The Acolyte is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(cyclone);
			display->text(GetName(), 13, 11, white);
			cout << " cast Cyclone!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 20 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(windstorm);
			display->text(GetName(), 13, 11, white);
			cout << " cast Windstorm!";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}


//============================================================================================
// Wood Priest
//============================================================================================
void WoodPriest::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 40 + 11;
		display->text("                                                            ", 13, 9, white);
		display->text("The priest is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 40 + 35;
			display->text("", 13, 9, white);
			display->SlowDisplay(snow);
			display->text(GetName(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X < 50 && Ka > 4)
		{
			damage = rand() % 30 + 25;
			display->text("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->text(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Ice Priest
//============================================================================================
void IcePriest::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(breeze);
		display->text("A slight breeze revitalizes the priest.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		display->text("                                                            ", 13, 9, white);
		display->text("The priest is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(avalanche);
			cout << "A glacier falls on you out of nowhere!!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(chill);
			cout << "Ice punctures and tears at you!";
			Sleep(player->GetPauseDuration());
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Fire Priest
//============================================================================================
void FirePriest::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(potion);
		display->text("The priest chugs a potion", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		display->text("                                                            ", 13, 9, white);
		display->text("The priest is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 50 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(landslide);
			cout << "Boulders fall on you from high above";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 20;
			display->text("", 13, 9, white);
			display->SlowDisplay(flame);
			cout << "Flames fly from his fingers torching you";
			Sleep(player->GetPauseDuration());
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Wind Priest
//============================================================================================
void WindPriest::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		display->text("                                                            ", 13, 9, white);
		display->text("The priest is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 10)
		{
			damage = rand() % 60 + 50;
			display->text("", 13, 9, white);
			display->SlowDisplay(lightning);
			cout << "A bolt of lightning strikes you!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 10 && X <= 80 && Ka > 5)
		{
			damage = rand() % 30 + 30;
			display->text("", 13, 9, white);
			display->SlowDisplay(arain);
			cout << "Acid rain falls upon you burning, and scalding you";
			Sleep(player->GetPauseDuration());
			Ka -= 5;
		}
		else if (X > 80)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// God of Life
//============================================================================================
void GodOfLife::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(heal);
		display->text("Light shines down from above engulfing the god in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 100 + 101;
		display->text("                                                            ", 13, 9, white);
		display->text("The god is healed: ", 13, 8, white);
		display->num(cure, 32, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && Ka > 20)
		{
			damage = rand() % 80 + 50;
			display->text("", 13, 9, white);
			display->SlowDisplay(lifestop);
			display->text(GetName(), 13, 11, white);
			cout << " cast Pain!";
			Sleep(player->GetPauseDuration());
			Ka -= 20;
		}
		if (X < 20 && Ka > 10)
		{
			damage = rand() % 60 + 30;
			display->text("", 13, 9, white);
			display->SlowDisplay(snow);
			display->text(GetName(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			Ka -= 10;
		}
		if (X > 20 && X < 80 && Ka > 4)
		{
			damage = rand() % 40 + 40;
			display->text("", 13, 9, white);
			display->SlowDisplay(briarbush);
			display->text(GetName(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			Ka -= 4;
		}
		else if (X > 50)
		{
			damage = rand() % BaseDamage + DamageModifier;
			display->text(GetName(), 13, 11, white);
			cout << " Attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}
//============================================================================================
// God of Chaos
//============================================================================================
void GodOfChaos::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->SlowDisplay(magma);
		display->text(GetName(), 13, 11, white);
		cout << " cast Pain!";
		Sleep(player->GetPauseDuration());
		Ka -= 20;
	}
	if (X < 20 && Ka > 10)
	{
		damage = rand() % 60 + 30;
		display->text("", 13, 9, white);
		display->SlowDisplay(snow);
		display->text(GetName(), 13, 11, white);
		cout << " cast Snow!";
		Sleep(player->GetPauseDuration());
		Ka -= 10;
	}
	if (X > 20 && X < 80 && Ka > 4)
	{
		damage = rand() % 40 + 40;
		display->text("", 13, 9, white);
		display->SlowDisplay(fire);
		display->text(GetName(), 13, 11, white);
		cout << " cast flame";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you with his staff";
		Sleep(player->GetPauseDuration());
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "                                    ";
	display->DisplayDamage(damage);
}
//============================================================================================
// God of War
//============================================================================================
void GodOfWar::Attack(Player *player, TextDisplay* display)
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
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " swings his massive hammer at you";
		Sleep(player->GetPauseDuration());
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " Attacks with his battle axe";
		Sleep(player->GetPauseDuration());
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " swings his sword";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " punches you!";
		Sleep(player->GetPauseDuration());
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "                                    ";
	display->DisplayDamage(damage);
}

//============================================================================================
// God of Death
//============================================================================================
void GodOfDeath::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string drain = "What was yours is now mine!";

	if (HitPoints <= 50 && Ka >= 20)
	{
		display->text("", 13, 9, white);
		display->SlowDisplay(drain);
		display->text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		damage = rand() % 100 + 90;
		cure = damage;
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                       ";
		display->DisplayDamage(damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("                                                            ", 13, 9, white);
		display->text("The god of death is healed: ", 13, 8, white);
		display->num(cure, 41, 8, green);
		display->DisplayCure(cure);
		SetHitPoints(GetHitPoints() + cure);
		SetKa(Ka - 4);
	}
	else
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " Attacks you with his scythe";
		Sleep(player->GetPauseDuration());

		damage -= arm->GetDefenseModifier();
		if (damage < 0)
			damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - damage);
		display->text("Enemies Damage: ", 13, 11, white);
		cout << damage << "                                    ";
		display->DisplayDamage(damage);
	}
}

//============================================================================================
// Peaceful Monk
//============================================================================================

// He's getting regular Attack patterns, cuz all he's going to do is Attack when he can.

//============================================================================================
// Green Dragon
//============================================================================================
void GreenDragon::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 100 + 60;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes a superheated fire at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes fire at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "                                    ";
	display->DisplayDamage(damage);
}

//============================================================================================
// Blue Dragon
//============================================================================================
void BlueDragon::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 100 + 60;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes a superchilled ice at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes icy wind at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "                                    ";
	display->DisplayDamage(damage);
}

//============================================================================================
// Red Dragon
//============================================================================================
void RedDragon::Attack(Player *player, TextDisplay* display)
{
	int damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		damage = rand() % 200 + 100;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes liquified steel fire at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 20;
	}
	if (X < 20)
	{
		damage = rand() % 60 + 30;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " breathes lava at you!";
		Sleep(player->GetPauseDuration());
		Ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		damage = rand() % 40 + 40;
		display->text("", 13, 9, white);
		display->text(GetName(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		Ka -= 4;
	}
	else if (X > 50)
	{
		damage = rand() % BaseDamage + DamageModifier;
		display->text(GetName(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	damage -= arm->GetDefenseModifier();
	if (damage < 0)
		damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - damage);
	display->text("Enemies Damage: ", 13, 11, white);
	cout << damage << "                                    ";
	display->DisplayDamage(damage);
}