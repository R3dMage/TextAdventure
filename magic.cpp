//====================================================================================================
//	This file houses all the functions for the magic, and how it works. The class Magic exists as a 
//vector within the game, much like the ground, and inventory, it gets pulled to where it needs to be
//it contains all the spells that the player may learn.
//====================================================================================================


#include "Magic.h"


#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


Magic::Magic()
{
	Attribute = "none";
	Cost = 0;
}
void Magic::Cast(Player*,Creature *)
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
void Magic::DisplayCastingCost()
{
	text("       ",1,23,white);
	num(Cost,1,23,white);
	text("ka",4,23,white);
}
void Magic::DisplayIncantation()
{
	text("",13,9,white);
	SlowDisplay(Incantation);
	text(Description,13,11,white);
	Sleep(1500);
}
void Magic::SlowDisplay(string szText)
{
	unsigned int i;

	for(i=0;i < szText.size();i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}
void Magic::DisplayName(int Y, WORD color)
{
	text(Name,16,Y,color);
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
void MinorHeal::Cast(Player *p2,Creature *enemy)
{
	int multi = p2->GetMind()/7;
	int cur = rand()% 30 + 10;
	cur += multi;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	p2->SetHitPoints(p2->GetCurrentHitPoints() + cur);
	text("You were healed: ",13,8,white); cout << cure;
	cure(cur);
}
MajorHeal::MajorHeal()
{
	Name =		  "Major Heal";
	Incantation = "Great god of the land, heal thy servant!";
	Description = "You feel warmed and nourished!";
	Cost		= 10;
	IsInFight = false;
}
void MajorHeal::Cast(Player *p2,Creature *enemy)
{
	int multi = p2->GetMind()/7;
	int cur = rand()% 60 + 30;
	cur *= multi;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	p2->SetHitPoints(p2->GetCurrentHitPoints() + cur);
	text("You were healed: ",13,8,white); cout << cure;
	cure(cur);
}

BriarBush::BriarBush()
{
	Name =		  "Briar Bush";
	Incantation = "I summon the plants of the forest, destroy my foe!";
	Description = "From the earth fly spikey plants raking open your opponents skin";
	//			  text("                                                                ",13,11,white);	
	Cost		= 10;
	IsInFight	= true;
}
void BriarBush::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
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
void Blizzard::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	Damage = rand()%40 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

PerfectStorm::PerfectStorm()
{
	Name =		  "PerfectStorm";
	Incantation = "Powers of nature heed me, and strike down my foe!!!";
	Description = "Lightning,hail,ice,snow,all you see before you avert your eyes";
	Cost		= 40;
	IsInFight = true;
}
void PerfectStorm::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;	
	Damage = rand()%100 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

DrainLife::DrainLife()
{
	Name =		  "Drain Life";
	Incantation = "What once was yours is now mine!";
	Description = "Your enemy winces in pain as his life is sucked away.";
	Cost		= 10;
	IsInFight = true;
}
void DrainLife::Cast(Player *p2, Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	text("                                                                ",13,9,white);
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
	Sleep(p2->GetPauseDuration());
	p2->SetHitPoints(p2->GetCurrentHitPoints() + Damage);
	text("You were healed: ",13,8,white); cout << Damage;
	cure(Damage);
}

StealKa::StealKa()
{
	Name =		  "Drain Ka";
	Incantation = "";
	Description = "";
	Cost		= 0;
	IsInFight = true;
}
void StealKa::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	int KA = enemy->getka();
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%15 + 5;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	enemy->setka(KA - Damage);
	text("                                                                ",13,11,white);
	p2->SetKa(p2->GetCurrentKa() + Damage);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
FireArrow::FireArrow()
{
	Name =		  "Flame Arrow";
	Incantation = "Underworld flames burn my enemy to ashes!";
	Description = "An arrow of fire strikes your enemy engulfing him in flames";
	Cost		= 10;
	IsInFight = true;
}
void FireArrow::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%30 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

Fire::Fire()
{
	Name =		  "Fire";
	Incantation = "Unholy fire, BURN! CONSUME! DESTROY!!!";
	Description = "Ungodly flames streak forward consuming your enemy.";
	Cost		= 18;
	IsInFight = true;
}
void Fire::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%50 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

Lava::Lava()
{
	Name =		  "Lava";
	Incantation = "Demons lend me your liquid fire!";
	Description = "Lava bursts forth from the ground,smothering your foe.";
	Cost		= 25;
	IsInFight = true;
}
void Lava::Cast(Player *p2, Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%150 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

Might::Might()
{
	Name =		  "Strength";
	Incantation = "god of war grant me strength!!";
	Description = "You become stronger";
	Cost		= 4;
	IsInFight = true;
}
void Might::Cast(Player *p2,Creature *)
{
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	p2->SetMagicStatus(1);
	p2->SetStrength(p2->GetStrength() + 10);
}
Dispel::Dispel()
{
	Name =		  "Dispel";
	Incantation = "Universe, set yourself to rights, the way you should be.";
	Description = "Your enemy's magical enhancements are gone.";
	Cost		= 4;
	IsInFight = true;
}
void Dispel::Cast(Player *p2,Creature *enemy)
{
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	enemy->setstate(0);
}
Shock::Shock()
{
	Name =		  "Shock";
	Incantation = "";
	Description = "";
	Cost		= 4;
	IsInFight = true;
}
void Shock::Cast(Player * p2, Creature * enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%20 + 10;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);			
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
AcidRain::AcidRain()
{
	Name =		  "Acid Rain";
	Incantation = "";
	Description = "";
	Cost		= 10;
	IsInFight = true;
}
void AcidRain::Cast(Player *p2, Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
LightningBolt::LightningBolt()
{
	Name =		  "Lightning Bolt";
	Incantation = "";
	Description = "";
	Cost		= 15;
	IsInFight = true;
}
void LightningBolt::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int Damage;
	int multi = p2->GetMind()/7;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	DisplayIncantation();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
Poison::Poison()
{
	Name =		  "Poison";
	Incantation = "Plagues of the past eat my foe from within!";
	Description = "Your enemy looks sickly now.";
	Cost		= 10;
	IsInFight = true;
}
void Poison::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage = rand()% 10 + 10;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	DisplayIncantation();
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
	enemy->setstate(3);
}
RaiseSkeleton::RaiseSkeleton()
{
	Name =		  "Summon Skeleton";
	Incantation = "Bones which death hath taken, aid me in my struggle";
	Description = "From the soil skeletal hands strike your opponent";
	Cost		= 10;
	IsInFight = true;
}
void RaiseSkeleton::Cast(Player * p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	DisplayIncantation();
	Damage -= (enemy->getdef());
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
	enemy->setstate(2);
}
DarkStrike::DarkStrike()
{
	Name =		  "Dark Strike";
	Incantation = "Lord of the Abyss join your sword with mine";
	Description = "An aura of darkness surrounds your sword as you drive it home.";
	Cost		= 15;
	IsInFight = true;
}
void DarkStrike::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	DisplayIncantation();
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

Critical::Critical()
{
	Name =		  "Critical";
	Incantation = "All hopes, all dreams, will die tonight";
	Description = "Your blow slices to the heart.";
	Cost		= 20;
	IsInFight = true;
}
void Critical::Cast(Player *p2,Creature *enemy)
{
	int X = rand()%100 + 1;
	int Damage = enemy->gethp() - enemy->gethp()/8;
	p2->SetKa(p2->GetCurrentKa() - Cost);
	enemy->sethp(enemy->gethp()/8);
	text("Your Damage: ",13,11,white);
	text("                                                                ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

Control::Control()
{
	Name =		  "Mind Control";
	Incantation = "Lord of the abyss give his mind to ME!";
	Description = "Your opponent has opted to join you.";
	Cost		= 30;
	IsInFight = false;
}
void Control::Cast(Player *p2, Creature *enemy)
{
}