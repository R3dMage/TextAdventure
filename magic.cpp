//====================================================================================================
//	This file houses all the functions for the magic, and how it works. The class magik exists as a 
//vector within the game, much like the ground, and inventory, it gets pulled to where it needs to be
//it contains all the spells that the player may learn.
//====================================================================================================


#include "Magic.h"


#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


magik::magik()
{
	attribute = "none";
	cost = 0;
}
void magik::use(Player*,creature *)
{
}
int magik::getcost()
{
	return cost;
}
string magik::getname()
{
	return name;
}
void magik::Disp()
{
	text("       ",1,23,white);
	num(cost,1,23,white);
	text("ka",4,23,white);
}
void magik::cast()
{
	text("",13,9,white);
	slowDisp(incantation);
	text(description,13,11,white);
	Sleep(1500);
}
void magik::slowDisp(string szText)
{
	unsigned int i;

	for(i=0;i < szText.size();i++)
	{
		cout << szText[i];
		Sleep(75);
	}
}
void magik::tout(int Y, WORD color)
{
	text(name,16,Y,color);
}

bool magik::getbInfight()
{
	return bInfight;
}
minheal::minheal()
{
	name		= "Minor Heal";
	incantation = "Great god of the land, heal thy servant!";
	description = "You feel warmed and nourished!";
	cost		= 5;
	bInfight	= false;
}
void minheal::use(Player *p2,creature *enemy)
{
	int multi = p2->GetMind()/7;
	int cur = rand()% 30 + 10;
	cur += multi;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	p2->SetHitPoints(p2->GetCurrentHitPoints() + cur);
	text("You were healed: ",13,8,white); cout << cure;
	cure(cur);
}
majheal::majheal()
{
	name =		  "Major Heal";
	incantation = "Great god of the land, heal thy servant!";
	description = "You feel warmed and nourished!";
	cost		= 10;
	bInfight = false;
}
void majheal::use(Player *p2,creature *enemy)
{
	int multi = p2->GetMind()/7;
	int cur = rand()% 60 + 30;
	cur *= multi;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	p2->SetHitPoints(p2->GetCurrentHitPoints() + cur);
	text("You were healed: ",13,8,white); cout << cure;
	cure(cur);
}

briar::briar()
{
	name =		  "Briar Bush";
	incantation = "I summon the plants of the forest, destroy my foe!";
	description = "From the earth fly spikey plants raking open your opponents skin";
	//			  text("                                                                ",13,11,white);	
	cost		= 10;
	bInfight	= true;
}
void briar::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

snow::snow()
{
	name =		  "Snow";
	incantation = "Ice and snow freeze my enemy where he stands!";
	description = "Ice,wind, and snow bring the enemy briefly to his knees";
	attribute   = "ice";
	cost		= 20;
	bInfight = true;
}
void snow::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	Damage = rand()%40 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

pstorm::pstorm()
{
	name =		  "PerfectStorm";
	incantation = "Powers of nature heed me, and strike down my foe!!!";
	description = "Lightning,hail,ice,snow,all you see before you avert your eyes";
	cost		= 40;
	bInfight = true;
}
void pstorm::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;	
	Damage = rand()%100 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

dlife::dlife()
{
	name =		  "Drain Life";
	incantation = "What once was yours is now mine!";
	description = "Your enemy winces in pain as his life is sucked away.";
	cost		= 10;
	bInfight = true;
}
void dlife::use(Player *p2, creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	text("                                                                ",13,9,white);
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
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

stealka::stealka()
{
	name =		  "Drain Ka";
	incantation = "";
	description = "";
	cost		= 0;
	bInfight = true;
}
void stealka::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	int KA = enemy->getka();
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%15 + 5;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	enemy->setka(KA - Damage);
	text("                                                                ",13,11,white);
	p2->SetKa(p2->GetCurrentKa() + Damage);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
farrow::farrow()
{
	name =		  "Flame Arrow";
	incantation = "Underworld flames burn my enemy to ashes!";
	description = "An arrow of fire strikes your enemy engulfing him in flames";
	cost		= 10;
	bInfight = true;
}
void farrow::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%30 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

fire::fire()
{
	name =		  "Fire";
	incantation = "Unholy fire, BURN! CONSUME! DESTROY!!!";
	description = "Ungodly flames streak forward consuming your enemy.";
	cost		= 18;
	bInfight = true;
}
void fire::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%50 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

lava::lava()
{
	name =		  "Lava";
	incantation = "Demons lend me your liquid fire!";
	description = "Lava bursts forth from the ground,smothering your foe.";
	cost		= 25;
	bInfight = true;
}
void lava::use(Player *p2, creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%150 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	Damage -= enemy->getdef();
	enemy->sethp(enemy->gethp() - Damage);		
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

strength::strength()
{
	name =		  "Strength";
	incantation = "god of war grant me strength!!";
	description = "You become stronger";
	cost		= 4;
	bInfight = true;
}
void strength::use(Player *p2,creature *)
{
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	p2->SetMagicStatus(1);
	p2->SetStrength(p2->GetStrength() + 10);
}
dispel::dispel()
{
	name =		  "Dispel";
	incantation = "Universe, set yourself to rights, the way you should be.";
	description = "Your enemy's magical enhancements are gone.";
	cost		= 4;
	bInfight = true;
}
void dispel::use(Player *p2,creature *enemy)
{
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	enemy->setstate(0);
}
shock::shock()
{
	name =		  "Shock";
	incantation = "";
	description = "";
	cost		= 4;
	bInfight = true;
}
void shock::use(Player * p2, creature * enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%20 + 10;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);			
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
acidrain::acidrain()
{
	name =		  "Acid Rain";
	incantation = "";
	description = "";
	cost		= 10;
	bInfight = true;
}
void acidrain::use(Player *p2, creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%20 + 20;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
lightning::lightning()
{
	name =		  "Lightning Bolt";
	incantation = "";
	description = "";
	cost		= 15;
	bInfight = true;
}
void lightning::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int Damage;
	int multi = p2->GetMind()/7;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	cast();
	Damage -= (enemy->getmka() / 4);
	enemy->sethp(enemy->gethp() - Damage);	
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}
poison::poison()
{
	name =		  "Poison";
	incantation = "Plagues of the past eat my foe from within!";
	description = "Your enemy looks sickly now.";
	cost		= 10;
	bInfight = true;
}
void poison::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage = rand()% 10 + 10;
	p2->SetKa(p2->GetCurrentKa() - cost);
	cast();
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
	enemy->setstate(3);
}
skeleton::skeleton()
{
	name =		  "Summon Skeleton";
	incantation = "Bones which death hath taken, aid me in my struggle";
	description = "From the soil skeletal hands strike your opponent";
	cost		= 10;
	bInfight = true;
}
void skeleton::use(Player * p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	cast();
	Damage -= (enemy->getdef());
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
	enemy->setstate(2);
}
dstrike::dstrike()
{
	name =		  "Dark Strike";
	incantation = "Lord of the Abyss join your sword with mine";
	description = "An aura of darkness surrounds your sword as you drive it home.";
	cost		= 15;
	bInfight = true;
}
void dstrike::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int multi = p2->GetMind()/7;
	int Damage;
	p2->SetKa(p2->GetCurrentKa() - cost);
	Damage = rand()%50 + 50;
	Damage *= multi;
	cast();
	if(X < enemy->getmagdef())
		Damage = Damage - Damage/4;
	enemy->sethp(enemy->gethp() - Damage);
	text("                                                                ",13,11,white);
	text("Your Damage: ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

critical::critical()
{
	name =		  "Critical";
	incantation = "All hopes, all dreams, will die tonight";
	description = "Your blow slices to the heart.";
	cost		= 20;
	bInfight = true;
}
void critical::use(Player *p2,creature *enemy)
{
	int X = rand()%100 + 1;
	int Damage = enemy->gethp() - enemy->gethp()/8;
	p2->SetKa(p2->GetCurrentKa() - cost);
	enemy->sethp(enemy->gethp()/8);
	text("Your Damage: ",13,11,white);
	text("                                                                ",13,11,white);
	cout << Damage;
	enemy->dam(Damage);
}

control::control()
{
	name =		  "Mind Control";
	incantation = "Lord of the abyss give his mind to ME!";
	description = "Your opponent has opted to join you.";
	cost		= 30;
	bInfight = false;
}
void control::use(Player *p2, creature *enemy)
{
}








