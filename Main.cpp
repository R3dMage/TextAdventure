#include "GameDisplay.h"
#include "SaveLoadGame.h"
#include "World.h"

using namespace std;

void main()
{
	srand(static_cast<unsigned int>(GetTickCount64()));
	
	GameSettings* gameSettings = new GameSettings();
	GameDisplay* gameDisplay = new GameDisplay(gameSettings);
	ItemRepository* itemRepository = new ItemRepository(gameDisplay);
	MusicPlayer* musicPlayer = new MusicPlayer(gameDisplay);
	SaveLoadGame* gameLoader = new SaveLoadGame(itemRepository, gameDisplay);
	
	gameDisplay->BoxScreen();

	VirtualMap* virtualMap = new VirtualMap("valesh");

	World globe(gameDisplay, itemRepository, musicPlayer, virtualMap, gameSettings);

	while (true)
	{
		globe.TitleScreen();
		globe.SetupGame();
		globe.PlayGame();
	}
}