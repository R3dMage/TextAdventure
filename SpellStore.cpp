#include "SpellStore.h"

SpellStore::SpellStore(TextDisplay* display)
{
	Display = display;
}

void SpellStore::AddSpell(Magic* newSpell)
{
	if (HasMagic(newSpell->GetName()))
		return;

	Spells.push_back(newSpell);
}

void SpellStore::CheckMagic(PlayerKillCounts killCounts, Player* player)
{
	if (killCounts.OrcKillCount == 5 && killCounts.ElfKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Minor Heal"))
			return;
		Spells.push_back(new MinorHeal);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.OrcKillCount == 10 && killCounts.ElfKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Briar Bush"))
			return;
		Spells.push_back(new BriarBush);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.OrcKillCount == 20 && killCounts.ElfKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Major Heal"))
			return;
		Spells.push_back(new MajorHeal);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.OrcKillCount == 40 && killCounts.ElfKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Snow"))
			return;
		Spells.push_back(new Blizzard);
		Display->DisplayText("The god of life has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount == 5 && killCounts.OrcKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Drain Life"))
			return;
		Spells.push_back(new DrainLife);
		player->SetHasSpells(true);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount == 10 && killCounts.OrcKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Flame Arrow"))
			return;
		Spells.push_back(new FireArrow);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount == 20 && killCounts.OrcKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Steal Ka"))
			return;
		Spells.push_back(new StealKa);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount == 40 && killCounts.OrcKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Fire"))
			return;
		Spells.push_back(new Fire);
		Display->DisplayText("The god of chaos has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 4 && killCounts.OrcKillCount > 4 && killCounts.HumanKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Strength"))
			return;
		player->SetHasSpells(true);
		Spells.push_back(new Might);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 8 && killCounts.OrcKillCount > 8 && killCounts.HumanKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Dispel"))
			return;
		Spells.push_back(new Dispel);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 12 && killCounts.OrcKillCount > 12 && killCounts.HumanKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Shock"))
			return;
		Spells.push_back(new Shock);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 15 && killCounts.OrcKillCount > 15 && killCounts.HumanKillCount == 0 && Spells.size() < 10)
	{
		if (HasMagic("Acid Rain"))
			return;
		Spells.push_back(new AcidRain);
		Display->DisplayText("The god of war has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 3 && killCounts.OrcKillCount > 3 && killCounts.HumanKillCount > 3 && Spells.size() < 10)
	{
		if (HasMagic("Poison"))
			return;
		player->SetHasSpells(true);
		Spells.push_back(new Poison);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 10 && killCounts.OrcKillCount > 10 && killCounts.HumanKillCount > 10 && Spells.size() < 10)
	{
		if (HasMagic("Skeleton"))
			return;
		Spells.push_back(new RaiseSkeleton);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 15 && killCounts.OrcKillCount > 15 && killCounts.HumanKillCount > 15 && Spells.size() < 10)
	{
		if (HasMagic("Dark Strike"))
			return;
		Spells.push_back(new DarkStrike);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
	if (killCounts.ElfKillCount > 20 && killCounts.OrcKillCount > 20 && killCounts.HumanKillCount > 20 && Spells.size() < 10)
	{
		if (HasMagic("Critical"))
			return;
		Spells.push_back(new Critical);
		Display->DisplayText("The god of death has rewarded you with a magic spell!", 13, 9, white);
		Sleep(player->GetPauseDuration());
	}
}

bool SpellStore::HasMagic(string spellName)
{
	for (unsigned int i; i < Spells.size(); i++)
	{
		if (Spells[i]->GetName() == spellName)
			return true;
	}

	return false;
}