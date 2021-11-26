//====================================================================================================
//	This file houses all the functions for the magic, and how it works. The class Magic exists as a 
//vector within the game, much like the ground, and inventory, it gets pulled to where it needs to be
//it contains all the spells that the player may learn.
//====================================================================================================

#include "Magic.h"

Magic::Magic()
{
	Attribute = "none";
	Cost = 0;
}
void Magic::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
}
int Magic::GetCost()
{
	return Cost;
}
string Magic::GetName()
{
	return Name;
}

string Magic::GetDescription()
{
	return Description;
}

string Magic::GetIncantation()
{
	return Incantation;
}

bool Magic::GetIsInFight()
{
	return IsInFight;
}
MinorHeal::MinorHeal()
{
	Name		= "Minor Heal";
	Incantation = "Great god of the land, heal thy servant!";
	Description = "You feel warmed and nourished!";
	Cost		= 5;
	IsInFight	= false;
}
void MinorHeal::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int multi = player->GetMind()/7;
	int cur = rand()% 30 + 10;
	cur += multi;
	player->SetKa(player->GetCurrentKa() - Cost);	
	player->SetHitPoints(player->GetCurrentHitPoints() + cur);
	display->DisplayCure("You were healed:", cur);
}
MajorHeal::MajorHeal()
{
	Name =		  "Major Heal";
	Incantation = "Great god of the land, heal thy servant!";
	Description = "You feel warmed and nourished!";
	Cost		= 10;
	IsInFight = false;
}
void MajorHeal::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int multi = player->GetMind()/7;
	int cur = rand()% 60 + 30;
	cur *= multi;
	player->SetKa(player->GetCurrentKa() - Cost);	
	player->SetHitPoints(player->GetCurrentHitPoints() + cur);
	display->DisplayCure("You were healed:", cur);
}

BriarBush::BriarBush()
{
	Name =		  "Briar Bush";
	Incantation = "I summon the plants of the forest, destroy my foe!";
	Description = "From the earth fly spikey plants raking open your opponents skin";
	//			  display->text("                                                                ",13,11,white);	
	Cost		= 10;
	IsInFight	= true;
}
void BriarBush::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	player->SetKa(player->GetCurrentKa() - Cost);	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
}

Blizzard::Blizzard()
{
	Name =		  "Snow";
	Incantation = "Ice and snow freeze my enemy where he stands!";
	Description = "Ice,wind, and snow bring the enemy briefly to his knees";
	Attribute   = "ice";
	Cost		= 20;
	IsInFight = true;
}
void Blizzard::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	Damage = rand()%40 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	player->SetKa(player->GetCurrentKa() - Cost);
	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);		
	display->DisplayDamage("Your Damage:", Damage);
}

PerfectStorm::PerfectStorm()
{
	Name =		  "PerfectStorm";
	Incantation = "Powers of nature heed me, and strike down my foe!!!";
	Description = "Lightning,hail,ice,snow,all you see before you avert your eyes";
	Cost		= 40;
	IsInFight = true;
}
void PerfectStorm::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;	
	Damage = rand()%100 + 50;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	player->SetKa(player->GetCurrentKa() - Cost);
	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);	
	display->DisplayText("                                                                ",13,11,white);
	display->DisplayDamage("Your Damage:", Damage);
}

DrainLife::DrainLife()
{
	Name =		  "Drain Life";
	Incantation = "What once was yours is now mine!";
	Description = "Your enemy winces in pain as his life is sucked away.";
	Cost		= 10;
	IsInFight = true;
}
void DrainLife::Cast(Player *player, Creature *enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);	
	player->SetHitPoints(player->GetCurrentHitPoints() + Damage);
	
	display->DisplayDamage("Your Damage:", Damage);
	display->DisplayCure("You were healed:", Damage);
}

StealKa::StealKa()
{
	Name =		  "Drain Ka";
	Incantation = "";
	Description = "";
	Cost		= 0;
	IsInFight = true;
}
void StealKa::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	int KA = enemy->GetKa();
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%15 + 5;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	enemy->SetKa(KA - Damage);
	display->DisplayText("                                                                ",13,11,white);
	player->SetKa(player->GetCurrentKa() + Damage);
	display->DisplayDamage("Your Damage:", Damage);
}
FireArrow::FireArrow()
{
	Name =		  "Flame Arrow";
	Incantation = "Underworld flames burn my enemy to ashes!";
	Description = "An arrow of fire strikes your enemy engulfing him in flames";
	Cost		= 10;
	IsInFight = true;
}
void FireArrow::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%30 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);	
	display->DisplayDamage("Your Damage:", Damage);
}

Fire::Fire()
{
	Name =		  "Fire";
	Incantation = "Unholy fire, BURN! CONSUME! DESTROY!!!";
	Description = "Ungodly flames streak forward consuming your enemy.";
	Cost		= 18;
	IsInFight = true;
}
void Fire::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%50 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);		
	display->DisplayDamage("Your Damage:", Damage);
}

Lava::Lava()
{
	Name =		  "Lava";
	Incantation = "Demons lend me your liquid fire!";
	Description = "Lava bursts forth from the ground,smothering your foe.";
	Cost		= 25;
	IsInFight = true;
}
void Lava::Cast(Player *player, Creature *enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%150 + 50;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	Damage -= enemy->GetDefense();
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);		
	display->DisplayDamage("Your Damage:", Damage);
}

Might::Might()
{
	Name =		  "Strength";
	Incantation = "god of war grant me strength!!";
	Description = "You become stronger";
	Cost		= 4;
	IsInFight = true;
}
void Might::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	player->SetKa(player->GetCurrentKa() - Cost);
	
	player->SetMagicStatus(1);
	player->SetStrength(player->GetStrength() + 10);
}
Dispel::Dispel()
{
	Name =		  "Dispel";
	Incantation = "Universe, set yourself to rights, the way you should be.";
	Description = "Your enemy's magical enhancements are gone.";
	Cost		= 4;
	IsInFight = true;
}
void Dispel::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	player->SetKa(player->GetCurrentKa() - Cost);
	
	enemy->SetState(0);
}
Shock::Shock()
{
	Name =		  "Shock";
	Incantation = "";
	Description = "";
	Cost		= 4;
	IsInFight = true;
}
void Shock::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%20 + 10;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
}
AcidRain::AcidRain()
{
	Name =		  "Acid Rain";
	Incantation = "";
	Description = "";
	Cost		= 10;
	IsInFight = true;
}
void AcidRain::Cast(Player *player, Creature *enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
}
LightningBolt::LightningBolt()
{
	Name =		  "Lightning Bolt";
	Incantation = "";
	Description = "";
	Cost		= 15;
	IsInFight = true;
}
void LightningBolt::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int Damage;
	int multi = player->GetMind()/7;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	
	Damage -= (enemy->GetMaxKa() / 4);
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);	
	display->DisplayDamage("Your Damage:", Damage);
}
Poison::Poison()
{
	Name =		  "Poison";
	Incantation = "Plagues of the past eat my foe from within!";
	Description = "Your enemy looks sickly now.";
	Cost		= 10;
	IsInFight = true;
}
void Poison::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage = rand()% 10 + 10;
	player->SetKa(player->GetCurrentKa() - Cost);
	
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
	enemy->SetState(3);
}
RaiseSkeleton::RaiseSkeleton()
{
	Name =		  "Summon Skeleton";
	Incantation = "Bones which death hath taken, aid me in my struggle";
	Description = "From the soil skeletal hands strike your opponent";
	Cost		= 10;
	IsInFight = true;
}
void RaiseSkeleton::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	
	Damage -= (enemy->GetDefense());
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
	enemy->SetState(2);
}
DarkStrike::DarkStrike()
{
	Name =		  "Dark Strike";
	Incantation = "Lord of the Abyss join your sword with mine";
	Description = "An aura of darkness surrounds your sword as you drive it home.";
	Cost		= 15;
	IsInFight = true;
}
void DarkStrike::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int multi = player->GetMind()/7;
	int Damage;
	player->SetKa(player->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	
	if(X < enemy->GetMagicDefense())
		Damage = Damage - Damage/4;
	enemy->SetHitPoints(enemy->GetHitPoints() - Damage);
	display->DisplayDamage("Your Damage:", Damage);
}

Critical::Critical()
{
	Name =		  "Critical";
	Incantation = "All hopes, all dreams, will die tonight";
	Description = "Your blow slices to the heart.";
	Cost		= 20;
	IsInFight = true;
}
void Critical::Cast(Player* player, Creature* enemy, GameDisplay* display)
{
	int X = rand()%100 + 1;
	int Damage = enemy->GetHitPoints() - enemy->GetHitPoints()/8;
	player->SetKa(player->GetCurrentKa() - Cost);
	enemy->SetHitPoints(enemy->GetHitPoints()/8);
	display->DisplayDamage("Your Damage:", Damage);
}

Control::Control()
{
	Name =		  "Mind Control";
	Incantation = "Lord of the abyss give his mind to ME!";
	Description = "Your opponent has opted to join you.";
	Cost		= 30;
	IsInFight = false;
}
void Control::Cast(Player *player, Creature *enemy, GameDisplay* display)
{
}