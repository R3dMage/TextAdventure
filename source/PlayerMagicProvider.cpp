#include "PlayerMagicProvider.h"

PlayerMagicProvider::PlayerMagicProvider(TextDisplay* display)
{
	Display = display;
}

void PlayerMagicProvider::CheckMagic(Player* player, vector<Magic*>& spells)
{
	switch (player->PlotEventStates.GodChoice)
	{
	case DeitySelection::CHAOS:
		CheckChaos(player, spells);
		break;
	case DeitySelection::DEATH:
		CheckDeath(player, spells);
		break;
	case DeitySelection::NONE:
		break;
	case DeitySelection::ORDER:
		CheckOrder(player, spells);
		break;
	case DeitySelection::WAR:
		CheckWar(player, spells);
		break;
	}
}

bool PlayerMagicProvider::HasMagic(string spellName, vector<Magic*>& spells)
{
	for (unsigned int i = 0; i < spells.size(); i++)
	{
		if (spells[i]->GetName() == spellName)
			return true;
	}

	return false;
}

void PlayerMagicProvider::CheckChaos(Player* player, vector<Magic*>& spells)
{
	int totalKills = player->GetTotalKills() + 2 * player->RaceKillCounts.ElfKillCount;

	if (totalKills > 20 && totalKills < 40)
	{
		if (HasMagic("Drain Life", spells))
			return;
		spells.push_back(new DrainLife);
		player->SetHasSpells(true);
		Display->DisplayTextAndPause("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 40 && totalKills < 60)
	{
		if (HasMagic("Flame Arrow", spells))
			return;
		spells.push_back(new FireArrow);
		Display->DisplayTextAndPause("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 60 && totalKills < 80)
	{
		if (HasMagic("Steal Ka", spells))
			return;
		spells.push_back(new StealKa);
		Display->DisplayTextAndPause("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 80 && totalKills < 100)
	{
		if (HasMagic("Fire", spells))
			return;
		spells.push_back(new Fire);
		Display->DisplayTextAndPause("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
	}
}

void PlayerMagicProvider::CheckDeath(Player* player, vector<Magic*>& spells)
{
	int totalKills = player->GetTotalKills() / 2;

	if (totalKills > 20 && totalKills < 40)
	{
		if (HasMagic("Poison", spells))
			return;
		player->SetHasSpells(true);
		spells.push_back(new Poison);
		Display->DisplayTextAndPause("The god of death has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 40 && totalKills < 60)
	{
		if (HasMagic("Skeleton", spells))
			return;
		spells.push_back(new RaiseSkeleton);
		Display->DisplayTextAndPause("The god of death has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 60 && totalKills < 80)
	{
		if (HasMagic("Dark Strike", spells))
			return;
		spells.push_back(new DarkStrike);
		Display->DisplayTextAndPause("The god of death has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 80 && totalKills < 100)
	{
		if (HasMagic("Critical", spells))
			return;
		spells.push_back(new Critical);
		Display->DisplayTextAndPause("The god of death has rewarded you with a magic spell!", 13, 9, white);
	}
}

void PlayerMagicProvider::CheckOrder(Player* player, vector<Magic*>& spells)
{
	int totalKills = player->GetTotalKills() + 2 * player->RaceKillCounts.OrcKillCount;

	if (totalKills > 20 && totalKills < 40)
	{
		if (HasMagic("Minor Heal", spells))
			return;
		spells.push_back(new MinorHeal);
		Display->DisplayTextAndPause("The god of order has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 40 && totalKills < 60)
	{
		if (HasMagic("Briar Bush", spells))
			return;
		spells.push_back(new BriarBush);
		Display->DisplayTextAndPause("The god of order has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 60 && totalKills < 80)
	{
		if (HasMagic("Major Heal", spells))
			return;
		spells.push_back(new MajorHeal);
		Display->DisplayTextAndPause("The god of order has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 80 && totalKills < 100)
	{
		if (HasMagic("Snow", spells))
			return;
		spells.push_back(new Blizzard);
		Display->DisplayTextAndPause("The god of order has rewarded you with a magic spell!", 13, 9, white);
	}
}

void PlayerMagicProvider::CheckWar(Player* player, vector<Magic*>& spells)
{
	int totalKills = player->GetTotalKills() + 2 * player->RaceKillCounts.HumanKillCount;

	if (totalKills > 20 && totalKills < 40)
	{
		if (HasMagic("Strength", spells))
			return;
		player->SetHasSpells(true);
		spells.push_back(new Might);
		Display->DisplayTextAndPause("The god of war has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 40 && totalKills < 60)
	{
		if (HasMagic("Dispel", spells))
			return;
		spells.push_back(new Dispel);
		Display->DisplayTextAndPause("The god of war has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 60 && totalKills < 80)
	{
		if (HasMagic("Shock", spells))
			return;
		spells.push_back(new Shock);
		Display->DisplayTextAndPause("The god of war has rewarded you with a magic spell!", 13, 9, white);
	}
	if (totalKills > 80 && totalKills < 100)
	{
		if (HasMagic("Acid Rain", spells))
			return;
		spells.push_back(new AcidRain);
		Display->DisplayTextAndPause("The god of war has rewarded you with a magic spell!", 13, 9, white);
	}
}
