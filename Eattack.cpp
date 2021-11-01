#include <windows.h>		//I'm not sure
#include <iostream>			//Always needed
#include <string>			//For Strings
#include <fstream>			//For reading/writing files

#include "Enemies.h"
#include "World.h"


#define red FOREGROUND_RED | FOREGROUND_INTENSITY
#define green FOREGROUND_GREEN
#define white FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define blue FOREGROUND_BLUE

//============================================================================================
// Elf
//============================================================================================
void Elf::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string heal = "Great god of the land, heal thy servant!";

	if (hp <= 10 && ka >= 4)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		text("                                                            ", 13, 9, white);
		text("The Elf is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                          ", 13, 8, white);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "              ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Elven Mage
//============================================================================================
void ElvenMage::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";

	if (hp <= 10 && ka >= 4)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		text("                                                            ", 13, 9, white);
		text("The Elf is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                                                            ", 13, 8, white);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 40 + 20;
			text("", 13, 9, white);
			slowDisp(snow);
			text(getname(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X < 50 && ka > 4)
		{
			Damage = rand() % 20 + 20;
			text("", 13, 9, white);
			slowDisp(briarbush);
			text(getname(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}
		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Elven Warrior
//============================================================================================
void ElvenWarrior::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";

	if (hp <= 10 && ka >= 4)
	{
		Damage = rand() % 20 + 10;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		slowDisp(strike);
		text("The Elven Warrior strikes out with immense speed!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// Ice Elf
//============================================================================================
void IceElf::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && ka >= 6)
	{
		Damage = rand() % 20 + 28;
		setka(ka - 6);
		text("", 13, 9, white);
		text("The Ice Elf hurls a magical icicle at you!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			text("You narrowly escape the frozen pointy thing!", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}

		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                 ";
			Creature::dam(Damage);
		}
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// Fire Elf
//============================================================================================
void FireElf::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && ka >= 10)
	{
		Damage = rand() % 30 + 48;
		setka(ka - 10);
		text("", 13, 9, white);
		text("The Fire Elf sprays fire from his hand!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		if (player->GetEvade() < dodge)
		{
			text("You narrowly escape superheated doom!", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		else
		{
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                 ";
			Creature::dam(Damage);
		}
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// Elven Ranger
//============================================================================================
void ranger::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int choice = rand() % 100 + 1;
	int dodge = rand() % 100 + 1;
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string strike = "Spirits of the wood guide my blade. POWER STRIKE!!!";
	string heal = "Great god of the land, heal thy servant!";
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75 && ka >= 10 && hp > 35)
	{
		switch (level)
		{
		case 6:
		case 7:
			Damage = rand() % 25 + 20;
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("", 13, 9, white);
			slowDisp(strike);
			text("The Elven Ranger strikes out with immense speed!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			text("                                                            ", 13, 9, white);
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                             ";
			Creature::dam(Damage);
			setka(ka - 10);
			break;
		case 8:
		case 9:
			Damage = rand() % 30 + 30;
			text("", 13, 9, white);
			slowDisp(briarbush);
			text(getname(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
			break;
		}
	}
	else if (hp <= 35 && ka >= 4)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the elf in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 11;
		text("                                                            ", 13, 9, white);
		text("The Elf is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
		text("                                                            ", 13, 8, white);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Orc
//============================================================================================
void Orc::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	Armor* arm;

	if (hp < 10)
		runAway = true;
	else
	{
		arm = player->GetArmor();
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
		player->DisplayInfo();
		clear();
	}
}

//============================================================================================
// Orc Sorceror
//============================================================================================
void OrcSorceror::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string arrow = "Missle strike your mark with accuracy!";
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";

	if (hp <= 10 && ka >= 4)
	{
		text("", 13, 9, white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		Damage = rand() % 20 + 20;
		cure = Damage;
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                       ";
		Creature::dam(Damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("                                                            ", 13, 9, white);
		text("The Orc Sorceror is healed: ", 13, 8, white);
		num(cure, 41, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 50 + 20;
			text("", 13, 9, white);
			slowDisp(fire);
			text(getname(), 13, 11, white);
			cout << " cast Fire";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X < 50 && ka > 4)
		{
			Damage = rand() % 30 + 20;
			text("", 13, 9, white);
			slowDisp(arrow);
			text(getname(), 13, 11, white);
			cout << " cast flame arrow";
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}
		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Orc Soldier
//============================================================================================
void OrcSoldier::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Pathetic human feel the wrath of the orcs!!!";

	if (hp <= 10 && ka >= 5)
	{
		Damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		slowDisp(strike);
		text("The Orc Soldier strikes out with immense power!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Fire Orc
//============================================================================================
void FireOrc::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "Fire falls from the sky!!!";

	if (choice > 75 && ka >= 10)
	{
		Damage = rand() % 35 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		slowDisp(strike);
		text("You are pelted with scalding hot rocks from above", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 10);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Ice Orc
//============================================================================================
void IceOrc::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	string strike = "NOW! Deep freeze wind!";

	if (choice > 75 && ka >= 10)
	{
		Damage = rand() % 25 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		slowDisp(strike);
		text("Wind colder than what seems possible chills you to the bones", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 10);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Orc Wanderer
//============================================================================================
void OrcWanderer::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	//bool nodam;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string drain = "Everything is free for the taking!";


	if (hp <= 10 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		Damage = rand() % 35 + 20;
		cure = Damage;
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                       ";
		Creature::dam(Damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("                                                            ", 13, 9, white);
		text("The Adventurer is healed: ", 13, 8, white);
		num(cure, 41, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 50 + 50;
			text("", 13, 9, white);
			slowDisp(fire);
			text("The Orc Wanderer casts fire!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		else
		{
			Damage = rand() % damage + damMod;
			if (state == 1)
				X = Damage / 8;
			else
				X = 0;
			Damage += X;
			text(getname(), 13, 11, white);
			cout << " strikes out at you!";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Human Wizard
//============================================================================================
void Wizard::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	bool nodam = false;
	Armor* arm;
	arm = player->GetArmor();
	string arain = "Tainted water, pour from the sky!";
	string szshock = "Electricity flow forth and electrify my opponent!";
	string D = "Universe, set yourself to rights, the way you should be.";

	if (hp <= 10 && ka >= 10)
	{
		Damage = rand() % 20 + 20;
		text("", 13, 9, white);
		slowDisp(arain);
		text("Acid rain falls from the sky!!!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X > 50 && player->GetMagicStatus() == 1)
		{
			Damage = 0;
			text("", 13, 9, white);
			slowDisp(D);
			player->SetMagicStatus(0);
			text(getname(), 13, 11, white);
			cout << " cast Dispel";
			Sleep(player->GetPauseDuration());
			ka -= 4;
			nodam = true;
		}
		else if (X < 50 && ka > 4)
		{
			Damage = rand() % 40 + 20;
			text("", 13, 9, white);
			slowDisp(szshock);
			text("Electricy flies toward you, and your muscles tense", 13, 11, white);
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}

		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		if (!nodam)
		{
			Damage -= arm->GetDefenseModifier();
			if (Damage < 0)
				Damage = 1;
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                    ";
			Creature::dam(Damage);
		}
	}
}

//============================================================================================
// Human Adventurer
//============================================================================================
void Adventurer::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	bool nodam;
	Armor* arm;
	arm = player->GetArmor();
	string skel = "Bones which death hath taken, aid me in my struggle";
	string str = "god of war grant me strength!";
	string drain = "Everything is free for the taking!";


	if (hp <= 10 && ka >= 4 && level > 3)
	{
		text("", 13, 9, white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		Damage = rand() % 20 + 20;
		cure = Damage;
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                       ";
		Creature::dam(Damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("                                                            ", 13, 9, white);
		text("The Adventurer is healed: ", 13, 8, white);
		num(cure, 41, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else if (state == 0 && ka >= 4 && level > 2)
	{
		Damage = 0;
		text("", 13, 9, white);
		slowDisp(str);
		state = 1;
		text(getname(), 13, 11, white);
		cout << " has become visably stronger!!";
		Sleep(player->GetPauseDuration());
		ka -= 4;
		nodam = true;
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10 && level > 5)
		{
			Damage = rand() % 50 + 50;
			text("", 13, 9, white);
			slowDisp(skel);
			text("Skeletal hands strike from the soil!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		else
		{
			Damage = rand() % damage + damMod;
			if (state == 1)
				X = Damage / 8;
			else
				X = 0;
			Damage += X;
			text(getname(), 13, 11, white);
			cout << " attacks you!";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// Stargoyle
//============================================================================================
void Stargoyle::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 85)
	{
		Damage = rand() % 100 + 100;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Stargoyle points at the heavens and laughs", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("You see a huge meteor tearing through the atmosphere, at you!", 13, 11, white);
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Giant Spider
//============================================================================================
void GiantSpider::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	Damage = rand() % damage + damMod;
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text(getname(), 13, 11, white);
	cout << " attacks you!";
	Sleep(player->GetPauseDuration());
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "              ";
	Creature::dam(Damage);
	player->DisplayInfo();
	//clear();
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}


//============================================================================================
// Ghost
//============================================================================================
void Ghost::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();

	if (choice > 75)
	{
		Damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The ghost reaches out and touches you, with hands like ice.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                            ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// Magmaman
//============================================================================================
void Magmaman::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && ka >= 4)
	{
		Damage = rand() % 35 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Magmaman blasts searing hot wind at you from his mouth", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}


//============================================================================================
// Frost Giant
//============================================================================================
void FrostGiant::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && ka >= 4)
	{
		Damage = rand() % 15 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Frost Giant blows bone-chilling wind at you from his mouth", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Storm Giant
//============================================================================================
void StormGiant::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && ka >= 4)
	{
		Damage = rand() % 60 + 30;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Storm Giant strikes you with lightning!!!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Nymph
//============================================================================================
void Nymph::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	int R = 0;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 50 && !player->GetIsAsleep())
	{
		text("The Nymph embraces you lovingly...", 13, 11, white);
		Sleep(player->GetPauseDuration());
		R = rand() % 100 + 1;
		if (R > player->GetMind())
		{
			player->SetIsAsleep(true);
			text("", 13, 9, white);
			text("The Nymph lulls you to sleep in her arms...", 13, 11, white);
			Sleep(player->GetPauseDuration());
			text("                                                           ", 13, 9, white);
		}
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " stabs you with her long dagger!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
	if (player->GetIsAsleep())
	{
		R = rand() % 100 + 1;
		if (R < player->GetMind())
		{
			text("", 13, 9, white);
			text("You shake yourself free of her loveliness!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			text("                                                           ", 13, 9, white);
		}
	}
}

//============================================================================================
// Ice Wizard
//============================================================================================
void IceWizard::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Frigid wind sting my enemy!";
	string avalanche = "Snow! Consume my foe!";

	if (hp <= 28 && ka >= 4)
	{
		text("", 13, 9, white);
		slowDisp(breeze);
		text("A slight breeze revitalizes the Ice Wizard.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		text("                                                            ", 13, 9, white);
		text("The Ice Wizard is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 50 + 20;
			text("", 13, 9, white);
			slowDisp(avalanche);
			text(getname(), 13, 11, white);
			cout << " Snow avalanches out of nowhere!!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand() % 30 + 20;
			text("", 13, 9, white);
			slowDisp(chill);
			text(getname(), 13, 11, white);
			cout << " icy wind rips into you!";
			Sleep(player->GetPauseDuration());
			ka -= 5;
		}
		else if (X > 80)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Snowman
//============================================================================================
void Snowman::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && ka >= 4)
	{
		Damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Snowman throws a big, icy snowball at you!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cout << "And laughs!";
		text("                                                           ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Treeman
//============================================================================================
void Treeman::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string slam = "Now, face pain human!";
	string heal = "Great god of the land, heal thy servant!";

	if (hp <= 20 && ka >= 5)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the Treeman in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 16;
		text("                                                            ", 13, 9, white);
		text("The Treeman is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka >= 10)
		{
			Damage = rand() % 40 + 20;
			text("", 13, 9, white);
			slowDisp(slam);
			text(getname(), 13, 11, white);
			cout << "Branches reach down, pick you up and slam you hard into the ground";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		else if (X > 10 && X < 50 && ka > 5)
		{
			Damage = rand() % 20 + 20;
			text("", 13, 9, white);
			slowDisp(briarbush);
			text(getname(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			ka -= 5;
		}
		else
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " bashes you with heavy limbs!";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}


//============================================================================================
// Fire Demon
//============================================================================================
void FireDemon::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75)
	{
		choice = rand() % 100 + 1;
		if (choice < 50)
		{
			Damage = rand() % 20 + 30;
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("", 13, 9, white);
			text("The Fire Demon throws a big fireball at you!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			cout << "And laughs!";
			text("                                                           ", 13, 9, white);
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                 ";
			Creature::dam(Damage);
		}
		else
		{
			Damage = rand() % 20 + 40;
			player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
			text("", 13, 9, white);
			text("The Fire Demon grabs you, and engulfs you in flames!!!", 13, 11, white);
			Sleep(player->GetPauseDuration());
			text("Enemies Damage: ", 13, 11, white);
			cout << Damage << "                                 ";
			Creature::dam(Damage);
		}
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " attacks you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Hydra
//============================================================================================
void Hydra::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int choice = rand() % 100 + 1;
	Armor* arm;
	arm = player->GetArmor();
	if (choice > 75 && ka >= 4)
	{
		Damage = rand() % 20 + 20;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("", 13, 9, white);
		text("The Hydra breathes noxious gas in your direction!", 13, 11, white);
		Sleep(player->GetPauseDuration());
		text("                                                           ", 13, 9, white);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                 ";
		Creature::dam(Damage);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text(getname(), 13, 11, white);
		cout << " bites you!";
		Sleep(player->GetPauseDuration());
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                             ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Centipede
//============================================================================================
void Centipede::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	Damage = rand() % damage + damMod;
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text(getname(), 13, 11, white);
	cout << " attacks you!";
	Sleep(player->GetPauseDuration());
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "              ";
	Creature::dam(Damage);
	player->DisplayInfo();
	//clear();
	if (Poison < 25)
	{
		if (!player->GetIsPoisoned())
		{
			text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Vampire
//============================================================================================
void Vampire::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int Poison = rand() % 100 + 1;
	Armor* arm;

	arm = player->GetArmor();
	Damage = rand() % damage + damMod;
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text(getname(), 13, 11, white);
	cout << " attacks you!";
	Sleep(player->GetPauseDuration());
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "              ";
	Creature::dam(Damage);
	Damage = Damage / 4;
	sethp(gethp() + Damage);
	player->DisplayInfo();
	if (Poison < 15)
	{
		if (!player->GetIsPoisoned())
		{
			text("You have been poisoned.", 13, 11, white);
			Sleep(player->GetPauseDuration());
		}
		player->SetIsPoisoned(true);
	}
}

//============================================================================================
// Acolyte
//============================================================================================
void Acolyte::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string windstorm = "Wind! Strikedown my opponent!";
	string cyclone = "Wind! Destroy my enemies!!!";
	string heal = "Gentle zephyr caress, and heal my wounds.";

	if (hp <= 40 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("A slight breeze wafts through the fight.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 50 + 21;
		text("                                                            ", 13, 9, white);
		text("The Acolyte is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 40 + 20;
			text("", 13, 9, white);
			slowDisp(cyclone);
			text(getname(), 13, 11, white);
			cout << " cast Cyclone!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X < 50 && ka > 4)
		{
			Damage = rand() % 20 + 20;
			text("", 13, 9, white);
			slowDisp(windstorm);
			text(getname(), 13, 11, white);
			cout << " cast Windstorm!";
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}
		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}


//============================================================================================
// Wood Priest
//============================================================================================
void WoodPriest::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string heal = "Great god of the land, heal thy servant!";

	if (hp <= 25 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 40 + 11;
		text("                                                            ", 13, 9, white);
		text("The priest is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 40 + 35;
			text("", 13, 9, white);
			slowDisp(snow);
			text(getname(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X < 50 && ka > 4)
		{
			Damage = rand() % 30 + 25;
			text("", 13, 9, white);
			slowDisp(briarbush);
			text(getname(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}
		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Ice Priest
//============================================================================================
void IcePriest::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string breeze = "Icy breeze refresh me!";
	string chill = "Ice!! Deep freeze this fool!";
	string avalanche = "Glacier, move at my command!";

	if (hp <= 28 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(breeze);
		text("A slight breeze revitalizes the priest.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		text("                                                            ", 13, 9, white);
		text("The priest is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 50 + 20;
			text("", 13, 9, white);
			slowDisp(avalanche);
			cout << "A glacier falls on you out of nowhere!!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand() % 30 + 20;
			text("", 13, 9, white);
			slowDisp(chill);
			cout << "Ice punctures and tears at you!";
			Sleep(player->GetPauseDuration());
			ka -= 5;
		}
		else if (X > 80)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Fire Priest
//============================================================================================
void FirePriest::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string potion = "Ah, a potion. These are great!";
	string flame = "Fire!!! Show no mercy to this man!";
	string landslide = "Stones fall from above!!!";

	if (hp <= 30)
	{
		text("", 13, 9, white);
		slowDisp(potion);
		text("The priest chugs a potion", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		text("                                                            ", 13, 9, white);
		text("The priest is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 50 + 20;
			text("", 13, 9, white);
			slowDisp(landslide);
			cout << "Boulders fall on you from high above";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand() % 30 + 20;
			text("", 13, 9, white);
			slowDisp(flame);
			cout << "Flames fly from his fingers torching you";
			Sleep(player->GetPauseDuration());
			ka -= 5;
		}
		else if (X > 80)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Wind Priest
//============================================================================================
void WindPriest::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string heal = "Great god of the land, heal thy servant!";
	string arain = "Tainted water, pour from the sky!";
	string lightning = "Powers above smite my enemy!";

	if (hp <= 60 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the priest in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 30 + 21;
		text("                                                            ", 13, 9, white);
		text("The priest is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 10)
		{
			Damage = rand() % 60 + 50;
			text("", 13, 9, white);
			slowDisp(lightning);
			cout << "A bolt of lightning strikes you!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 10 && X <= 80 && ka > 5)
		{
			Damage = rand() % 30 + 30;
			text("", 13, 9, white);
			slowDisp(arain);
			cout << "Acid rain falls upon you burning, and scalding you";
			Sleep(player->GetPauseDuration());
			ka -= 5;
		}
		else if (X > 80)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// God of Life
//============================================================================================
void GodOfLife::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string briarbush = "I summon the plants of the forest, destroy my foe!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string lifestop = "Great land put cast off your pain to this man!";
	string heal = "Great land of mine, lend me your energy!";

	if (hp <= 40 && ka >= 10)
	{
		text("", 13, 9, white);
		slowDisp(heal);
		text("Light shines down from above engulfing the god in brightness", 13, 11, white);
		Sleep(player->GetPauseDuration());
		cure = rand() % 100 + 101;
		text("                                                            ", 13, 9, white);
		text("The god is healed: ", 13, 8, white);
		num(cure, 32, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 10);
	}
	else
	{
		X = rand() % 100 + 1;
		if (X < 10 && ka > 20)
		{
			Damage = rand() % 80 + 50;
			text("", 13, 9, white);
			slowDisp(lifestop);
			text(getname(), 13, 11, white);
			cout << " cast Pain!";
			Sleep(player->GetPauseDuration());
			ka -= 20;
		}
		if (X < 20 && ka > 10)
		{
			Damage = rand() % 60 + 30;
			text("", 13, 9, white);
			slowDisp(snow);
			text(getname(), 13, 11, white);
			cout << " cast Snow!";
			Sleep(player->GetPauseDuration());
			ka -= 10;
		}
		if (X > 20 && X < 80 && ka > 4)
		{
			Damage = rand() % 40 + 40;
			text("", 13, 9, white);
			slowDisp(briarbush);
			text(getname(), 13, 11, white);
			cout << " cast briar-bush!";
			Sleep(player->GetPauseDuration());
			ka -= 4;
		}
		else if (X > 50)
		{
			Damage = rand() % damage + damMod;
			text(getname(), 13, 11, white);
			cout << " attacks you with his staff";
			Sleep(player->GetPauseDuration());
		}
		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}
//============================================================================================
// God of Chaos
//============================================================================================
void GodOfChaos::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string magma = "Earth unleash your pure fury!";

	X = rand() % 100 + 1;
	if (X < 10 && ka > 20)
	{
		Damage = rand() % 80 + 50;
		text("", 13, 9, white);
		slowDisp(magma);
		text(getname(), 13, 11, white);
		cout << " cast Pain!";
		Sleep(player->GetPauseDuration());
		ka -= 20;
	}
	if (X < 20 && ka > 10)
	{
		Damage = rand() % 60 + 30;
		text("", 13, 9, white);
		slowDisp(snow);
		text(getname(), 13, 11, white);
		cout << " cast Snow!";
		Sleep(player->GetPauseDuration());
		ka -= 10;
	}
	if (X > 20 && X < 80 && ka > 4)
	{
		Damage = rand() % 40 + 40;
		text("", 13, 9, white);
		slowDisp(fire);
		text(getname(), 13, 11, white);
		cout << " cast flame";
		Sleep(player->GetPauseDuration());
		ka -= 4;
	}
	else if (X > 50)
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " attacks you with his staff";
		Sleep(player->GetPauseDuration());
	}
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "                                    ";
	Creature::dam(Damage);
}
//============================================================================================
// God of War
//============================================================================================
void GodOfWar::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();
	string fire = "Infernal flames of hell consume my enemy!";
	string snow = "Ice and snow freeze my enemy where he stands!";
	string hammer = "Earth unleash your pure fury!";

	X = rand() % 100 + 1;
	if (X < 10)
	{
		Damage = rand() % 90 + 60;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " swings his massive hammer at you";
		Sleep(player->GetPauseDuration());
		ka -= 20;
	}
	if (X < 20)
	{
		Damage = rand() % 60 + 30;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " attacks with his battle axe";
		Sleep(player->GetPauseDuration());
		ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		Damage = rand() % 40 + 40;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " swings his sword";
		Sleep(player->GetPauseDuration());
		ka -= 4;
	}
	else if (X > 50)
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " punches you!";
		Sleep(player->GetPauseDuration());
	}
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "                                    ";
	Creature::dam(Damage);
}

//============================================================================================
// God of Death
//============================================================================================
void GodOfDeath::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int cure;
	Armor* arm;
	arm = player->GetArmor();
	string drain = "What was yours is now mine!";

	if (hp <= 50 && ka >= 20)
	{
		text("", 13, 9, white);
		slowDisp(drain);
		text("You grow cold, and feel like something was taken.", 13, 11, white);
		Sleep(player->GetPauseDuration());
		Damage = rand() % 100 + 90;
		cure = Damage;
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                       ";
		Creature::dam(Damage);
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("                                                            ", 13, 9, white);
		text("The god of death is healed: ", 13, 8, white);
		num(cure, 41, 8, green);
		Creature::cure(cure);
		sethp(gethp() + cure);
		setka(ka - 4);
	}
	else
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " attacks you with his scythe";
		Sleep(player->GetPauseDuration());

		Damage -= arm->GetDefenseModifier();
		if (Damage < 0)
			Damage = 1;
		player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
		text("Enemies Damage: ", 13, 11, white);
		cout << Damage << "                                    ";
		Creature::dam(Damage);
	}
}

//============================================================================================
// Peaceful Monk
//============================================================================================

// He's getting regular attack patterns, cuz all he's going to do is attack when he can.

//============================================================================================
// Green Dragon
//============================================================================================
void GreenDragon::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		Damage = rand() % 100 + 60;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes a superheated fire at you!";
		Sleep(player->GetPauseDuration());
		ka -= 20;
	}
	if (X < 20)
	{
		Damage = rand() % 60 + 30;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes fire at you!";
		Sleep(player->GetPauseDuration());
		ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		Damage = rand() % 40 + 40;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		ka -= 4;
	}
	else if (X > 50)
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "                                    ";
	Creature::dam(Damage);
}

//============================================================================================
// Blue Dragon
//============================================================================================
void BlueDragon::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		Damage = rand() % 100 + 60;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes a superchilled ice at you!";
		Sleep(player->GetPauseDuration());
		ka -= 20;
	}
	if (X < 20)
	{
		Damage = rand() % 60 + 30;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes icy wind at you!";
		Sleep(player->GetPauseDuration());
		ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		Damage = rand() % 40 + 40;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		ka -= 4;
	}
	else if (X > 50)
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "                                    ";
	Creature::dam(Damage);
}

//============================================================================================
// Red Dragon
//============================================================================================
void RedDragon::attack(Player* player, vector<Item*>& playerInventory, vector<Item*>& worldItems, string map)
{
	int Damage = 0;
	int X;
	Armor* arm;
	arm = player->GetArmor();

	X = rand() % 100 + 1;
	if (X < 10)
	{
		Damage = rand() % 200 + 100;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes liquified steel fire at you!";
		Sleep(player->GetPauseDuration());
		ka -= 20;
	}
	if (X < 20)
	{
		Damage = rand() % 60 + 30;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " breathes lava at you!";
		Sleep(player->GetPauseDuration());
		ka -= 10;
	}
	if (X > 20 && X < 80)
	{
		Damage = rand() % 40 + 40;
		text("", 13, 9, white);
		text(getname(), 13, 11, white);
		cout << " strikes you with his tail!";
		Sleep(player->GetPauseDuration());
		ka -= 4;
	}
	else if (X > 50)
	{
		Damage = rand() % damage + damMod;
		text(getname(), 13, 11, white);
		cout << " slashes at you with his claws!";
		Sleep(player->GetPauseDuration());
	}
	Damage -= arm->GetDefenseModifier();
	if (Damage < 0)
		Damage = 1;
	player->SetHitPoints(player->GetCurrentHitPoints() - Damage);
	text("Enemies Damage: ", 13, 11, white);
	cout << Damage << "                                    ";
	Creature::dam(Damage);
}