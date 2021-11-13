#include "GameDisplay.h"
#include "World.h"

using namespace std;

void main()
{
	srand(static_cast<unsigned int>(GetTickCount64()));
	
	GameSettings* gameSettings = new GameSettings();
	GameDisplay* gameDisplay = new GameDisplay(gameSettings);
	gameDisplay->BoxScreen();
	
	ItemRepository* itemRepository = new ItemRepository(gameDisplay);
	MusicPlayer* musicPlayer = new MusicPlayer(gameDisplay);
	VirtualMap* virtualMap = new VirtualMap("valesh");

	World globe(gameDisplay, itemRepository, musicPlayer, virtualMap, gameSettings);

	globe.StartGame();
}