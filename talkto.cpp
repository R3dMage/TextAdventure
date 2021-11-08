#include "Enemies.h"

//================================================================================================================
// This file contains all the code for all the random dialogue in the game. None of which should be very plot
// advancing, but who knows I might change that notion too. 2/21/05
//================================================================================================================


Greeting Elf::GetGreeting(Player *player)
{
	
	bool isHostile = player->GetReactionElf() < 2;
	int num = rand() % 4 + 1;
	string intro = "An elf stands before you.";
	string description;

	if(isHostile)
	{
		description = "You bastard, you've slaughtered my brethren!!!";
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			"Human, perhaps someday you will prove worthy...";			
			break;
		case 2:
			description = "The trees can teach you much about life...";			
			break;
		case 3:
			description = "The trees can teach you much about life...";			
			break;
		case 4:
			description = "The trees can teach you much about life...";			
			break;
		}
	}

	return Greeting(intro, description, isHostile);
}

Greeting ElvenMage::GetGreeting(Player *player)
{
	bool isHostile = player->GetReactionElf() < 2;
	int num = rand() % 4 + 1;
	string intro = "An elven mage stands before you.";
	string description;

	if(player->GetReactionElf() < 2)
	{
		description = "I will end your murderous ways, human!";	
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			description = "Your ways are far inferior to ours, human.";			
			break;
		case 2:
			description = "Your life is so fleeting human, you should treatsure it.";			
			break;
		case 3:
			description = "From the earth came all living things.";			
			break;
		case 4:
			description = "The trees can teach you much about life...";			
			break;
		}		
	}
	return Greeting(intro, description, isHostile);
}

Greeting ElvenWarrior::GetGreeting(Player *player)
{	
	bool isHostile = player->GetReactionElf() < 2;
	int num = rand() % 4 + 1;
	string intro = "An elven warrior stands before you.";
	string description;

	if(player->GetReactionElf() < 2)
	{
		switch(num)
		{
		case 1:
			description = "You bastard, you've slaughtered my brethren!!!";			
			break;
		case 2:
			description = "Vile human, you are reputed to kill elves, I will slay you";			
			break;
		case 3:
			description = "Mere death is too good for you!!!";			
			break;
		case 4:
			description = "Here you will die, human.";			
			break;
		}
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			description = "Human, your skills are dull.";			
			break;
		case 2:
			description = "What seek ye here?";			
			break;
		case 3:
			description = "Elven Warrior:...";			
			break;
		case 4:
			description = "The trees can teach you much about life...";			
			break;
		}		
	}
	if(player->GetReactionElf() > 2)
	{
		description = "Friend to the elves how can I assist you?";		
	}
	return Greeting(intro, description, isHostile);
}
//bool fireelf::GetGreeting(player *player)
//{
//	
//}
//bool iceelf::GetGreeting(player *player)
//{
//	
//}
//bool ranger::GetGreeting(player *player)
//{
//	
//}
Greeting Orc::GetGreeting(Player *player)
{
	bool isHostile = player->GetReactionOrc() < 2;
	int num = rand() % 4 + 1;
	string description;
	string intro = "An orc stands before you.";


	if(player->GetReactionOrc() < 2)
	{
		description = "Miserable wretch, today you die!";		
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			description = "Normally, I'd cut you human.";
			
			break;
		case 2:
			description = "Never forget the power of the ORCS!";
			
			break;
		case 3:
			description = "I once killed 3 elves in 1 day!";
			
			break;
		case 4:
			description = "Death... is glorious.";
			
			break;
		}
		
	}
	if(player->GetReactionOrc() > 2)
	{
		description = "Fare thee well elfslayer.";		
	}
	return Greeting(intro, description, isHostile);
}

Greeting OrcSorceror::GetGreeting(Player *player)
{
	bool isHostile = player->GetReactionOrc() < 2;
	int num = rand() % 4 + 1;
	string intro = "An orc sorceror stands before you.";
	string description;


	if(player->GetReactionOrc() < 2)
	{
		description = "Miserable wretch, today you die!";		
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			description = "Normally, I'd cut you human.";			
			break;
		case 2:
			description = "Never forget the power of the ORCS!";			
			break;
		case 3:
			description = "I once killed 3 elves in 1 day!";			
			break;
		case 4:
			description = "Death... is glorious.";			
			break;
		}		
	}
	if(player->GetReactionOrc() > 2)
	{
		description = "Fare thee well elfslayer.";		
	}
	return Greeting(intro, description, isHostile);
}

Greeting OrcSoldier::GetGreeting(Player *player)
{
	bool isHostile = player->GetReactionOrc() < 2;
	int num = rand() % 4 + 1;	
	string intro = "An orc soldier stands before you.";
	string description;

	if(player->GetReactionOrc() < 2)
	{
		description = "Miserable wretch, today you die!";		
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			description = "Normally, I'd cut you human.";			
			break;
		case 2:
			description = "Never forget the power of the ORCS!";			
			break;
		case 3:
			description = "I once killed 3 elves in 1 day!";			
			break;
		case 4:
			description = "Death... is glorious.";			
			break;
		}		
	}
	if(player->GetReactionOrc() > 2)
	{
		description = "Fare thee well elfslayer.";		
	}
	return Greeting(intro, description, isHostile);
}
//bool fireorc::GetGreeting(player *player)
//{
//	
//}
//bool iceorc::GetGreeting(player *player)
//{
//	
//}
//bool wanderer::GetGreeting(player *player)
//{
//	
//}
Greeting Human::GetGreeting(Player *player)
{
	bool isHostile = player->GetReactionHuman() < 2;
	int num = rand() % 8 + 1;
	int Y = player->RaceKillCounts.HumanKillCount * 100;

	string intro = "A " + this->GetName() + " stands before you.";
	string description;
	
	if(player->GetReactionHuman() < 2)
	{
		description = "Alright! Your head will bring me "; cout << Y << "Gold!!!";		
	}
	if(player->GetReactionHuman() == 2)
	{
		
	}
	if(player->GetReactionHuman() > 2)
	{
		switch(num)
		{	
		case 1:
			description = "The Orcs and the Elves war endlessly";
			break;
		case 2:
			description = "They say far to the west is the domain of the gods";
			break;
		case 3:
			description = "I once heard there was a magical way of travelling";
			break;
		case 4:
			description = "The gods don't choose their servants, the servants choose.";
			break;
		case 5:
			description = "The woods are home to certain creatures";
			break;
		case 6:
			description = "I've heard of a town where they pay really well for items";
			break;
		case 7:
			description = "If you kill one elf, the rest will avenge their brother";
			break;
		case 8:
			description = "Their were once temples that could magicaly teleport people";
			break;
		}		
	}
	return Greeting(intro, description, isHostile);
}