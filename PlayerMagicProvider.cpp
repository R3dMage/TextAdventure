#include "PlayerMagicProvider.h"

PlayerMagicProvider::PlayerMagicProvider(TextDisplay* display)
{
	Display = display;
}

void PlayerMagicProvider::CheckMagic(Player* player, vector<Magic*>& spells)
{
	if (player->RaceKillCounts.OrcKillCount == 5 && player->RaceKillCounts.ElfKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Minor Heal", spells))
			return;
		spells.push_back(new MinorHeal);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.OrcKillCount == 10 && player->RaceKillCounts.ElfKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Briar Bush", spells))
			return;
		spells.push_back(new BriarBush);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.OrcKillCount == 20 && player->RaceKillCounts.ElfKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Major Heal", spells))
			return;
		spells.push_back(new MajorHeal);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.OrcKillCount == 40 && player->RaceKillCounts.ElfKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Snow", spells))
			return;
		spells.push_back(new Blizzard);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount == 5 && player->RaceKillCounts.OrcKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Drain Life", spells))
			return;
		spells.push_back(new DrainLife);
		player->SetHasSpells(true);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount == 10 && player->RaceKillCounts.OrcKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Flame Arrow", spells))
			return;
		spells.push_back(new FireArrow);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount == 20 && player->RaceKillCounts.OrcKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Steal Ka", spells))
			return;
		spells.push_back(new StealKa);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount == 40 && player->RaceKillCounts.OrcKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Fire", spells))
			return;
		spells.push_back(new Fire);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 4 && player->RaceKillCounts.OrcKillCount > 4 && player->RaceKillCounts.HumanKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Strength", spells))
			return;
		player->SetHasSpells(true);
		spells.push_back(new Might);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 8 && player->RaceKillCounts.OrcKillCount > 8 && player->RaceKillCounts.HumanKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Dispel", spells))
			return;
		spells.push_back(new Dispel);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 12 && player->RaceKillCounts.OrcKillCount > 12 && player->RaceKillCounts.HumanKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Shock", spells))
			return;
		spells.push_back(new Shock);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 15 && player->RaceKillCounts.OrcKillCount > 15 && player->RaceKillCounts.HumanKillCount == 0 && spells.size() < 10)
	{
		if (HasMagic("Acid Rain", spells))
			return;
		spells.push_back(new AcidRain);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 3 && player->RaceKillCounts.OrcKillCount > 3 && player->RaceKillCounts.HumanKillCount > 3 && spells.size() < 10)
	{
		if (HasMagic("Poison", spells))
			return;
		player->SetHasSpells(true);
		spells.push_back(new Poison);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 10 && player->RaceKillCounts.OrcKillCount > 10 && player->RaceKillCounts.HumanKillCount > 10 && spells.size() < 10)
	{
		if (HasMagic("Skeleton", spells))
			return;
		spells.push_back(new RaiseSkeleton);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 15 && player->RaceKillCounts.OrcKillCount > 15 && player->RaceKillCounts.HumanKillCount > 15 && spells.size() < 10)
	{
		if (HasMagic("Dark Strike", spells))
			return;
		spells.push_back(new DarkStrike);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (player->RaceKillCounts.ElfKillCount > 20 && player->RaceKillCounts.OrcKillCount > 20 && player->RaceKillCounts.HumanKillCount > 20 && spells.size() < 10)
	{
		if (HasMagic("Critical", spells))
			return;
		spells.push_back(new Critical);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
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