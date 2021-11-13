#include "GameDisplay.h"
#include "World.h"

using namespace std;

void main()
{
	srand(static_cast<unsigned int>(GetTickCount64()));
	
	GameDisplay* gameDisplay = new GameDisplay();
	gameDisplay->BoxScreen();
	
	ItemRepository* itemRepository = new ItemRepository(gameDisplay);
	MusicPlayer* musicPlayer = new MusicPlayer(gameDisplay);

	World globe(gameDisplay, itemRepository, musicPlayer);
		
	globe.StartGame();
}