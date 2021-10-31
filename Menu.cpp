#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

#include "World.h"
#include "Creature.h"
#include "Enemies.h"
#include "Item.h"
#include "Location.h"
#include "Player.h"

#define box FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define brown FOREGROUND_RED | FOREGROUND_GREEN
#define green FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define dkgreen FOREGROUND_GREEN
#define blue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define ftext BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

void World::HandleMainMenu(Player *player, vector<Magic*> &spells,vector<Item*> &worldItems, vector<Item*> &playerInventory,string &map)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition; 

	while(!escapeWasPressed)
	{
		ClearTextBottomRight(11);
		player->DisplayInfo();	
		ground(worldItems,map,player->GetPositionX(),player->GetPositionY());
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Inv.   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Status |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Magic  |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Options|",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("           ",1,17,blue);

		DrawCursor(cursorPosition,yellow,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,15))
			{
				DrawCursor(cursorPosition,yellow,175);
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch(choice)
		{
		case 12:
			HandleInventory(player,worldItems,playerInventory,map);
			break;
		case 13:
			player->DisplayStatus();
			break;
		case 14:
			if(player->HasLearnedSpells())
				MagicMenu(player,spells);
			else
			{
				text("You have no magic",13,11,white);
				Sleep(player->GetPauseDuration());
				text("                 ",13,11,white);
			}
			break;
		case 15:
			Options(player,worldItems,playerInventory,spells,map);
			break;		
		}
	}// End of While(escapeWasPressed)


}
void World::HandleInventory(Player *player,vector<Item*> &worldItems, vector<Item*> &playerInventory,string map)
{
	unsigned int offset;
	int choice = 0;
	int Y = 11;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool wasUsed = false;
	bool pickup;
	bool selectedUse;
	COORD cursorPosition = {2,12};

	while(!escapeWasPressed)
	{		
		ground(worldItems,map,player->GetPositionX(),player->GetPositionY());
		DisplayPlayerItems(playerInventory);
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		pickup = false;
		selectedUse = false;
		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  PickUp |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Utilize|",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|         |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|         |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCursor(cursorPosition,yellow,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,13))
			{
				DrawCursor(cursorPosition,yellow,175);
			}
			text("",79,23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch(choice)
		{
		case 12:
			pickup = true;
			break;
		case 13:
			selectedUse = true;
			break;
		}

		if(pickup)
		{
			Item *temp;
			if(playerInventory.size() < 12)
			{
				for(offset = 0;offset < worldItems.size();offset++)
				{
					if(worldItems[offset]->GetPositionY() == player->GetPositionY() && worldItems[offset]->GetPositionX() == player->GetPositionX() && worldItems[offset]->GetMapName() == map)
					{
						playerInventory.push_back(worldItems[offset]);
						temp = worldItems[worldItems.size()-1];
						worldItems[worldItems.size()-1] = worldItems[offset];
						worldItems[offset] = temp;
						worldItems.pop_back();
						break;
					}
				}
				clrtop(2);
			}
			else
			{
				text("You do not have enough room!",13,9,white);
				Sleep(3000);
				text("                            ",13,9,white);
			}
		}
		if(selectedUse)
		{
			choice = 0;
			escapeWasPressed = false;
			selectionWasMade = false;
			bool bFight = false;
			
			while(!escapeWasPressed)
			{
				//clr();
				//clrtop();
				DisplayPlayerItems(playerInventory);
				ground(worldItems,map,player->GetPositionX(),player->GetPositionY());
				cursorPosition.X = 2;
				cursorPosition.Y = 12;
				selectionWasMade = false;
				text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				text("|  Use    |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				text("|  Equip  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				text("|  Drop   |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				text("|  XXXX   |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

				DrawCursor(cursorPosition,yellow,175);
				do
				{
					if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,15))
					{
						DrawCursor(cursorPosition,yellow,175);
					}
					text(" ", 79, 23,white);
				}while(!selectionWasMade);
				if(escapeWasPressed)
					break;
				choice = cursorPosition.Y;
				switch(choice)
				{
				case 12:
					if(playerInventory.size() > 0)
						Use(player,playerInventory,wasUsed,bFight);
					else
					{
						text("You have nothing to use",13,11,white);
						Sleep(player->GetPauseDuration());
					}
					break;
				case 13:
					if(playerInventory.size() > 0)
						Equip(player,playerInventory);
					else
					{
						text("You have nothing to equip",13,12,white);
						Sleep(player->GetPauseDuration());
					}
					break;
				case 14:
					if(playerInventory.size() > 0)
						Drop(player,worldItems,playerInventory,map);
					else
					{
						text("You have nothing to drop",13,12,white);
						Sleep(player->GetPauseDuration());
					}
					break;
				case 15:
					if(playerInventory.size() > 0)
						DeleteItem(playerInventory);
					else
					{
						text("You have nothing to dispose of",13,12,white);
						Sleep(player->GetPauseDuration());
					}
					break;
				}//--------End Switch
			}//------------End While escapeWasPressed
			ClearTextBottomRight(12);
		}//----------------End if(Use)
	}//--------------------End While escapeWasPressed
}//------------------------End Inventory function

void World::DisplayPlayerItems(vector<Item*> &playerInventory)
{
	//clr();
	unsigned int offset = 0;
	text(" [---Items---] ",13,11,brown);
	while(offset < playerInventory.size())
	{		
		text(playerInventory[offset]->GetName(),15,12+offset,yellow);
		offset++;
		if(offset >= 12)
			break;
	}
}

void World::Equip(Player *player,vector<Item*> &playerInventory)
{
	unsigned int Offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	Item *temp;
	COORD cursorPosition;

	while(!selectionWasMade)
	{
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		Offset = cursorPosition.Y - 12;
		DrawCursor(cursorPosition,yellow,175);
		playerInventory[Offset]->Display();
		do
		{
			choice = static_cast<int>(11+playerInventory.size());
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,choice))
			{
				DrawCursor(cursorPosition,yellow,175);
				Offset = cursorPosition.Y - 12;
				playerInventory[Offset]->Display();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
		{
			text("          ",1,22,white);
			text("          ",1,23,white);
			clrbottom();
			DisplayPlayerItems(playerInventory);
			return;
		}
	}// End While selectionWasMade
	Offset = cursorPosition.Y - 12;
	temp = playerInventory[Offset];
	if(!temp->GetIsArmor() && !temp->GetIsWeapon())
	{
		text("You cannot equip that.",13,9,white);
		Sleep(player->GetPauseDuration());
	}
	if(temp->GetIsArmor())
	{
		playerInventory.push_back(player->GetArmor());
		player->SetArmor(loadArmor(temp->GetName()));
		playerInventory[Offset] = playerInventory[playerInventory.size()-1];
		playerInventory[playerInventory.size()-1] = temp;
		playerInventory.pop_back();		
	}
	if(temp->GetIsWeapon())
	{
		playerInventory.push_back(player->GetWeapon());
		player->SetWeapon(loadWeapon(temp->GetName()));
		playerInventory[Offset] = playerInventory[playerInventory.size()-1];
		playerInventory[playerInventory.size()-1] = temp;
		playerInventory.pop_back();		
	}
	text("              ",cursorPosition.X,cursorPosition.Y,white);
	player->DisplayInfo();
	DisplayPlayerItems(playerInventory);
	text("                                           ",175,11,white);
	text("           ",1,22,white);
	text("           ",1,23,white);
}

void World::Drop(Player *player,vector<Item*> &worldItems,vector<Item*> &playerInventory,string map)
{
	unsigned int Offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	//item *temp;
	COORD cursorPosition;

	
	while(!escapeWasPressed)
	{
		ground(worldItems,map,player->GetPositionX(),player->GetPositionY());
		DisplayPlayerItems(playerInventory);
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition,yellow,175);
		do
		{
			choice = static_cast<int>(11+playerInventory.size());
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,choice))
			{
				DrawCursor(cursorPosition,yellow,175);
				Offset = cursorPosition.Y - 12;
				playerInventory[Offset]->Display();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
		{
			text("          ",1,22,white);
			text("          ",1,23,white);
			clrbottom();
			DisplayPlayerItems(playerInventory);
			return;
		}
	

		Offset = cursorPosition.Y - 12;
		playerInventory[Offset]->SetMapName(map);
		playerInventory[Offset]->SetPositionX(player->GetPositionX());
		playerInventory[Offset]->SetPositionY(player->GetPositionY());
		worldItems.push_back(playerInventory[Offset]);
		SlideDown(playerInventory,Offset);
		playerInventory.pop_back();	
		text("  ",13,12,white);
		text("                    ",13,12+Offset,white);
		text("                    ",13,static_cast<int>(12+playerInventory.size()),white);
		if(playerInventory.size() < 1)
			return;
	}//end While escapeWasPressed
}
void World::DeleteItem(vector<Item*> &playerInventory)
{
	unsigned int offset = 0;
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	//item *temp;
	COORD cursorPosition;

	while(!escapeWasPressed)
	{
		DisplayPlayerItems(playerInventory);
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition,yellow,175);
		do
		{
			choice = static_cast<int>(11 + playerInventory.size());
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,choice))
			{
				DrawCursor(cursorPosition,yellow,175);
				offset = cursorPosition.Y - 12;
				playerInventory[offset]->Display();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
		{
			text("          ",1,22,white);
			text("          ",1,23,white);
			clrbottom();
			DisplayPlayerItems(playerInventory);
			return;
		}
			
		offset = cursorPosition.Y - 12;
		selectionWasMade = false;
		text(playerInventory[offset]->GetName(),15,cursorPosition.Y,FOREGROUND_RED | FOREGROUND_INTENSITY);
		do
		{
			
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,cursorPosition.Y,cursorPosition.Y))
			{
				DrawCursor(cursorPosition,yellow,175);
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			return;
		SlideDown(playerInventory,offset);
		playerInventory.pop_back();
		ClearTextBottomRight(12);
		text("                    ",13,static_cast<int>(12+playerInventory.size()),white);
		if(playerInventory.size() < 1)
			return;

	}// End While escapeWasPressed
	
}

void World::Options(Player *player, vector<Item*> &worldItems,vector<Item*> &playerInventory,vector<Magic*> &M, string &Map)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition; 

	while(!escapeWasPressed)
	{
		//clear();       For smooth look remarked out 2/15/06
		player->DisplayInfo();	
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Save   |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Load   |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Setup  |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Quit   |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		DrawCursor(cursorPosition,yellow,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,15))
			{
				DrawCursor(cursorPosition,yellow,175);
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch(choice)
		{
		case 12:
			text("Saving game ",13,11,yellow);
			SaveGame(player,worldItems,playerInventory,M,Map);
			Sleep(player->GetPauseDuration());
			text("            ",13,11,yellow);
			break;
		case 13:
			Load(player,worldItems,playerInventory,M,Map);
			break;
		case 14:
			OptionsMenu(player,worldItems,playerInventory,M,Map);		
			break;
		case 15:
			system("cls");
			text("See you next time.",13,11,yellow);
			Sleep(player->GetPauseDuration());
			exit(0);
			break;		
		}
	}// End of While(escapeWasPressed)
}
/*=====================================================================================
	Input for the setup of the game. Music, speed, etc.
=====================================================================================*/
void World::OptionsMenu(Player *player, vector<Item*> &worldItems,vector<Item*> &playerInventory,vector<Magic*> &availableMagic, string &Map)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition; 

	while(!escapeWasPressed)
	{
		player->DisplayInfo();	
		cursorPosition.X = 2;
		cursorPosition.Y = 12;
		selectionWasMade = false;
		text("/---------\\",1,11,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Music  |",1,12,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Speed  |",1,13,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Invis  |",1,14,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("|  Drive  |",1,15,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		text("\\---------/",1,16,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		/*=======================================
		Displays the current music status
		========================================*/
		if(cursorPosition.Y == 12 && player->GetIsMusicOn())
			text("Music: On    ",13,12,yellow);
		else if(cursorPosition.Y == 12 && !player->GetIsMusicOn())
			text("Music: Off   ",13,12,yellow);
		//========================================
		DrawCursor(cursorPosition,yellow,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,15))
			{
				//clr(11);
				DrawCursor(cursorPosition,yellow,175);
				/*=======================================
				Displays the current music status
				========================================*/
				if(cursorPosition.Y == 12 && player->GetIsMusicOn())
					text("Music: On     ",13,12,yellow);
				else if(cursorPosition.Y == 12 && !player->GetIsMusicOn())
					text("Music: Off    ",13,12,yellow);
				/*========================================
				Displays current player pause duration
				========================================*/
				if(cursorPosition.Y == 13){
					text("Speed: ",13,12,yellow);
					cout << player->GetPauseDuration();}
				/*========================================
				Displays the current invisibility status
				=========================================*/
				if(cursorPosition.Y == 14 && player->GetIsInvisible())
					text("Invis: On     ",13,12,yellow);
				else if(cursorPosition.Y == 14 && !player->GetIsInvisible())
					text("Invis: Off    ",13,12,yellow);
				//========================================
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			break;

		choice = cursorPosition.Y;
		switch(choice)
		{
		case 12:
			text("Changing Music.",13,11,yellow);
			player->ToggleMusic();
			Sleep(player->GetPauseDuration());
			text("               ",13,11,yellow);
			break;
		case 13:
			text("Changing Speed?",13,11,yellow);
			Sleep(player->GetPauseDuration());
			text("               ",13,11,yellow);
			break;
		case 14:
			text("To be added later.",13,11,yellow);
			Sleep(player->GetPauseDuration());
			text("               ",13,11,yellow);
			break;
		case 15:
			text("To be added later.",13,11,yellow);
			Sleep(player->GetPauseDuration());
			text("               ",13,11,yellow);
			break;		
		}
	}// End of While(escapeWasPressed)
}
void World::UseItem(Player *player,vector<Item*> &worldItems,vector<Item*> &playerInventory, bool &bFight,bool &bLeave,string map)
{
	int choice = 0;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	bool Iused = false;
	COORD cursorPosition;
	
	while(!escapeWasPressed)
	{		
		ClearTextBottomRight(12);
		if(bFight && Iused)
			break;		
		player->DisplayInfo();
		DisplayPlayerItems(playerInventory);
		if(!bFight)
			ground(worldItems,map,player->GetPositionX(),player->GetPositionY());
		cursorPosition.X = 2;
		cursorPosition.Y = 15;
		selectionWasMade = false;
		text("/---------\\",1,14,ftext);
		text("|  Use    |",1,15,ftext);
		text("|  Equip  |",1,16,ftext);
		text("|  Drop   |",1,17,ftext);
		text("|  XXXX   |",1,18,ftext);
		text("\\---------/",1,19,ftext);

		DrawCursor(cursorPosition,ftext,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,15,18))
			{
				DrawCursor(cursorPosition,ftext,175);
			}
			text("", 79, 23,ftext);
		}while(!selectionWasMade);
		if(escapeWasPressed)
		{
			bLeave = true;
			break;
		}
		choice = cursorPosition.Y;
		switch(choice)
		{
		case 15:
			if(playerInventory.size() > 0)
				Use(player,playerInventory,Iused,bFight);			
			else
			{
				text("You have no items.",13,11,white);
				Sleep(player->GetPauseDuration());
			}
			break;
		case 16:
			if(playerInventory.size() > 0)
				Equip(player,playerInventory);
			else
			{
				text("You have nothing to equip",13,12,white);
				Sleep(player->GetPauseDuration());
			}
			break;
		case 17:
			if(playerInventory.size() > 0)
				Drop(player,worldItems,playerInventory,map);
			else
			{
				text("You have nothing to drop",13,12,white);
				Sleep(player->GetPauseDuration());
			}
			break;
		case 18:
			if(playerInventory.size() > 0)
				DeleteItem(playerInventory);
			else
			{
				text("You have nothing to dispose of",13,12,white);
				Sleep(player->GetPauseDuration());
			}
			break;
		}//--------End Switch
	}//------------End While escapeWasPressed
	ClearTextBottomRight(12);
}
void World::Use(Player *player,vector<Item*> &playerInventory,bool &itemWasUsed,bool isFighting)
{
	Weapon weapon;
	Armor  armor;
	Item* itemUsed;
	unsigned int offset = 0;
	int choice = 0;
	int Num;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition;

	
	while(!escapeWasPressed && playerInventory.size() > 0)
	{
		clritems();
		DisplayPlayerItems(playerInventory);
		player->DisplayInfo();

		if(itemWasUsed && isFighting)
			break;
		escapeWasPressed = false;
		selectionWasMade = false;
		cursorPosition.X = 13;
		cursorPosition.Y = 12;
		DrawCursor(cursorPosition,yellow,175);
		
		playerInventory[offset]->Display();
		do
		{
			choice = static_cast<int>(11+playerInventory.size());
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,12,choice))
			{
				DrawCursor(cursorPosition,yellow,175);				
				offset = cursorPosition.Y - 12;
				playerInventory[offset]->Display();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
	
		if(escapeWasPressed)
		{
			text("          ",1,22,white);
			text("          ",1,23,white);
			clrbottom();
			DisplayPlayerItems(playerInventory);
			return;
		}
		offset = cursorPosition.Y - 12;
		itemUsed = playerInventory[offset];
		if(!escapeWasPressed)
		{	
			if(!itemUsed->GetKeep())
			{
				SlideDown(playerInventory,offset);
				playerInventory.pop_back();
				text("                   ",13,static_cast<int>(12+playerInventory.size()),white);
			}


			switch(itemUsed->GetType())
			{
			case 0:
				Num = 25; 
				player->SetHitPoints(player->GetCurrentHitPoints()+Num);
				text("You were healed: ",13,8,white); cout << Num;
				cure(Num);
				break;
			case 1:
				Num = 15;
				player->SetKa(player->GetCurrentKa()+Num);
				text("Ka recovered: ",13,8,white); cout << Num;
				cure(Num);
				break;
			case 2:
				Num = rand()%5 + 1;
				player->SetStrength(player->GetStrength()+Num);
				text("Your strength has increased",13,8,white);
				Sleep(player->GetPauseDuration());
				break;
			case 3:
				Num = rand()%5 + 1;
				player->SetMind(player->GetMind()+Num);
				text("Your mind powers have increased",13,8,white);
				Sleep(player->GetPauseDuration());
				break;
			case 4:
				Num = 75; 
				player->SetHitPoints(player->GetCurrentHitPoints()+Num);
				text("You were healed: ",13,8,white); cout << Num;
				cure(Num);
				break;
			case 5:
				Num = 150; 
				player->SetHitPoints(player->GetCurrentHitPoints()+Num);
				text("You were healed: ",13,8,white); cout << Num;
				cure(Num);
				break;
			case 6:
				Num = player->GetMaxHitPoints() - player->GetCurrentHitPoints();
				player->SetHitPoints(player->GetMaxHitPoints());
				text("You were healed: ",13,8,white); cout << Num;
				cure(Num);
			default:
				text("This item does nothing",13,8,white);
				Sleep(player->GetPauseDuration());
				break;
			}
			itemWasUsed = true;
			clrtop(2);
			if(isFighting)
				escapeWasPressed = true;
		}	
		
	}// End While escapeWasPressed && playerInventory.size() > 0
	clrbottom();
}
void World::MagicMenu(Player *player,vector<Magic*> &spells)
{
	int choice = 0;
	int offset = 0;
	unsigned int i;
	bool escapeWasPressed = false;
	bool selectionWasMade = false;
	COORD cursorPosition; 
	goblin A;
	creature *guy = &A;

	while(!escapeWasPressed)
	{
		clear();
		player->DisplayInfo();	
		cursorPosition.X = 14;
		cursorPosition.Y = 13;
		selectionWasMade = false;
		text("/----------------\\",13,12,green);
		text("|                |",13,13,green);
		text("|                |",13,14,green);
		text("|                |",13,15,green);
		text("|                |",13,16,green);
		text("|                |",13,17,green);
		text("|                |",13,18,green);
		text("|                |",13,19,green);
		text("|                |",13,20,green);
		text("|                |",13,21,green);
		text("|                |",13,22,green);
		text("\\----------------/",13,23,green);
		

		for(i = 0;i < spells.size();i++)
		{
			if(spells[i]->GetIsInFight() || player->GetCurrentKa() < spells[i]->GetCost())
			{
				spells[i]->DisplayName(i+13,dkgreen);
			}
			else
				spells[i]->DisplayName(i+13,green);
		}
		DrawCursor(cursorPosition,yellow,175);
		offset = cursorPosition.Y - 13;
		spells[offset]->DisplayCastingCost();
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,escapeWasPressed,13,12 + static_cast<int>(spells.size())))
			{
				DrawCursor(cursorPosition,yellow,175);
				offset = cursorPosition.Y - 13;
				spells[offset]->DisplayCastingCost();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(escapeWasPressed)
			return;
		offset = cursorPosition.Y - 13;
		if(spells[offset]->GetIsInFight())
		{
			text("That spell can only be used in battle",13,9,white);
			Sleep(player->GetPauseDuration());
		}
		else if(player->GetCurrentKa() < spells[offset]->GetCost())
		{
			text("Not enough Ka",13,9,white);
			Sleep(player->GetPauseDuration());
		}
		else
			spells[offset]->Cast(player,guy);
	}//==================================End of While loop==================================
}

void World::InFightMagicMenu(Player *player,creature *enemy,vector<Magic*> &spells,bool &pressedEscape)
{
	int choice = 0;
	int offset = 0;
	unsigned int i;
	bool selectionWasMade = false;
	COORD cursorPosition; 
	goblin A;
	creature *guy = &A;

	pressedEscape = false;
	while(!pressedEscape)
	{
		cursorPosition.X = 14;
		cursorPosition.Y = 13;
		selectionWasMade = false;
		text("/----------------\\",13,12,green);
		text("|                |",13,13,green);
		text("|                |",13,14,green);
		text("|                |",13,15,green);
		text("|                |",13,16,green);
		text("|                |",13,17,green);
		text("|                |",13,18,green);
		text("|                |",13,19,green);
		text("|                |",13,20,green);
		text("|                |",13,21,green);
		text("|                |",13,22,green);
		text("\\----------------/",13,23,green);
		
		for(i = 0;i < spells.size();i++)
		{
			if(player->GetCurrentKa() < spells[i]->GetCost())
			{
				spells[i]->DisplayName(i+13,dkgreen);
			}
			else
				spells[i]->DisplayName(i+13,green);
		}
		spells[offset]->DisplayCastingCost();
		DrawCursor(cursorPosition,yellow,175);
		do
		{
			if(MoveCursor(cursorPosition,selectionWasMade,pressedEscape,13,12 + static_cast<int>(spells.size())))
			{
				DrawCursor(cursorPosition,yellow,175);
				offset = cursorPosition.Y - 13;
				spells[offset]->DisplayCastingCost();
			}
			text(" ", 79, 23,white);
		}while(!selectionWasMade);
		if(pressedEscape)
			return;
		offset = cursorPosition.Y - 13;
		if(player->GetCurrentKa() < spells[offset]->GetCost())
		{
			text("Not enough Ka",13,9,white);
			Sleep(player->GetPauseDuration());
		}
		else
		{
			ClearTextBottomRight(11);
			spells[offset]->Cast(player,enemy);
			return;
		}
	}//==================================End of While loop==================================
}


void World::ClearTextBottomRight(int Y)
{
	while(Y < 24)
			{
				text("                                                                 ",13,Y,FOREGROUND_BLUE);
				Y++;
			}
}
//=========================================================================================================
//	This function moves all the elements of the playerInventory DOWN by one.
//After taking element X and putting it aside. It then puts element X at the end.
//Usually to pop the last element off.
//=========================================================================================================
void World::SlideDown(vector<Item*> &playerInventory,int X)
{
	int Y = X + 1;
	Item *temp;

	temp = playerInventory[X];
	while(Y <= static_cast<int>(playerInventory.size()-1))
	{
		playerInventory[X] = playerInventory[Y];
		X++;
		Y++;
	}
	playerInventory[playerInventory.size()-1] = temp;
}