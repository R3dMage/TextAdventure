#include <iostream>
#include "Enemies.h"

#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY 
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY

//================================================================================================================
// This file contains all the code for all the random dialogue in the game. None of which should be very plot
// advancing, but who knows I might change that notion too. 2/21/05
//================================================================================================================

void clr();

bool Elf::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	string intro = "An " + this->GetName() + " stands before you.";

	text(intro,13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;
		
	}


	if(player->GetReactionElf() < 2)
	{
		text("You bastard, you've slaughtered my brethren!!!",13,9,white);
		Sleep(player->GetPauseDuration());
		return true;
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Human, perhaps someday you will prove worthy...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("The trees can teach you much about life...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("The trees can teach you much about life...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("The trees can teach you much about life...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	else return false;
}

bool ElvenMage::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	text("An Elven Mage stands before you.",13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;
		
	}


	if(player->GetReactionElf() < 2)
	{
		text("I will end your murderous ways, human!",13,9,white);
		Sleep(player->GetPauseDuration());	
		return true;
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Your ways are far inferior to ours, human.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("Your life is so fleeting human, you should treatsure it.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("From the earth came all living things.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("The trees can teach you much about life...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	else return false;
}

bool ElvenWarrior::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	text("An Elven Warrior stands before you.",13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;
		
	}


	if(player->GetReactionElf() < 2)
	{
		switch(num)
		{
		case 1:
			text("You bastard, you've slaughtered my brethren!!!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("Vile human, you are reputed to kill elves, I will slay you",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("Mere death is too good for you!!!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("Here you will die, human.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return true;
	}
	if(player->GetReactionElf() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Human, your skills are dull.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("What seek ye here?",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("Elven Warrior:...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("The trees can teach you much about life...",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	if(player->GetReactionElf() > 2)
	{
		text("Friend to the elves how can I assist you?",13,9,white);
		Sleep(player->GetPauseDuration());
		text("                                                             ",13,9,white);
		return false;
	}
	else return false;
}
//bool fireelf::TalkTo(player *player)
//{
//	return true;
//}
//bool iceelf::TalkTo(player *player)
//{
//	return true;
//}
//bool ranger::TalkTo(player *player)
//{
//	return true;
//}
bool Orc::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	text("An Orc stands before you.",13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;
		
	}


	if(player->GetReactionOrc() < 2)
	{
		text("Miserable wretch, today you die!",13,9,white);
		Sleep(player->GetPauseDuration());	
		return true;
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Normally, I'd cut you human.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("Never forget the power of the ORCS!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("I once killed 3 elves in 1 day!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("Death... is glorious.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	if(player->GetReactionOrc() > 2)
	{
		text("Fare thee well elfslayer.",13,9,white);
		Sleep(player->GetPauseDuration());
		text("                                                             ",13,9,white);
		return false;
	}
	else return false;	
}

bool OrcSorceror::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	text("An Orc Sorceror stands before you.",13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;
		
	}


	if(player->GetReactionOrc() < 2)
	{
		text("Miserable wretch, today you die!",13,9,white);
		Sleep(player->GetPauseDuration());	
		return true;
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Normally, I'd cut you human.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("Never forget the power of the ORCS!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("I once killed 3 elves in 1 day!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("Death... is glorious.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	if(player->GetReactionOrc() > 2)
	{
		text("Fare thee well elfslayer.",13,9,white);
		Sleep(player->GetPauseDuration());
		return false;
	}
	else return false;
}

bool OrcSoldier::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 4 + 1;
	int X = 13;
	bool bSel;
	COORD CursPos;
	
	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	text("An Orc Soldier stands before you.",13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;		
	}
	if(player->GetReactionOrc() < 2)
	{
		text("Miserable wretch, today you die!",13,9,white);
		Sleep(player->GetPauseDuration());	
		return true;
	}
	if(player->GetReactionOrc() == 2)
	{
		switch(num)
		{	
		case 1:
			text("Normally, I'd cut you human.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 2:
			text("Never forget the power of the ORCS!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 3:
			text("I once killed 3 elves in 1 day!",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		case 4:
			text("Death... is glorious.",13,9,white);
			Sleep(player->GetPauseDuration());
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	if(player->GetReactionOrc() > 2)
	{
		text("Fare thee well elfslayer.",13,9,white);
		Sleep(player->GetPauseDuration());
		return false;
	}
	else return false;
}
//bool fireorc::TalkTo(player *player)
//{
//	return true;
//}
//bool iceorc::TalkTo(player *player)
//{
//	return true;
//}
//bool wanderer::TalkTo(player *player)
//{
//	return true;
//}
bool Human::TalkTo(Player *player)
{
	int choice;
	int num = rand() % 8 + 1;
	int X = 13;
	int Y = player->RaceKillCounts.HumanKillCount * 100;
	bool bSel;
	COORD CursPos;

	clr();
	CursPos.X = 2;
	CursPos.Y = 12;
	bSel = false;
	string intro = "A " + this->GetName() + " stands before you.";

	text(intro,13,11,white);
	text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Talk   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|  Fight  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	text("           ",1,17,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	DrawCursor(CursPos,yellow,175);
	do
	{
		if(MoveCursor(CursPos,bSel,12,X))
		{
			DrawCursor(CursPos,yellow,175);
		}
		text(" ", 79, 23,white);
	}while(!bSel);
	choice = CursPos.Y;
	switch(choice)
	{
	case 12:
		break;
	case 13:
		return true;
		break;		
	}
	if(player->GetReactionHuman() < 2)
	{
		text("Alright! Your head will bring me ",13,9,white); cout << Y << "Gold!!!";
		Sleep(player->GetPauseDuration());	
		return true;
	}
	if(player->GetReactionHuman() == 2)
	{
		return false;
	}
	if(player->GetReactionHuman() > 2)
	{
		switch(num)
		{	
		case 1:
			text("The Orcs and the Elves war endlessly",13,9,white);
			Sleep(3000);
			break;
		case 2:
			text("They say far to the west is the domain of the gods",13,9,white);
			Sleep(3000);
			break;
		case 3:
			text("I once heard there was a magical way of travelling",13,9,white);
			Sleep(3000);
			break;
		case 4:
			text("The gods don't choose their servants, the servants choose.",13,9,white);
			Sleep(3000);
			break;
		case 5:
			text("The woods are home to certain creatures",13,9,white);
			Sleep(3000);
			break;
		case 6:
			text("I've heard of a town where they pay really well for items",13,9,white);
			Sleep(3000);
			break;
		case 7:
			text("If you kill one elf, the rest will avenge their brother",13,9,white);
			Sleep(3000);
			break;
		case 8:
			text("Their were once temples that could magicaly teleport people",13,9,white);
			Sleep(3000);
			break;
		}
		text("                                                             ",13,9,white);
		return false;
	}
	else return false;
}