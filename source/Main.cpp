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
	
	SaveLoadGame gameLoader(itemRepository, gameDisplay);
	gameLoader.LoadSettings(gameSettings);
	musicPlayer->SetVolume(gameSettings->GetVolume());

	VirtualMap* virtualMap = new VirtualMap("valesh");

	World globe(gameDisplay, itemRepository, musicPlayer, virtualMap, gameSettings);

	while (true)
	{
		system("cls");
		gameDisplay->BoxScreen();
		globe.TitleScreen();
		globe.SetupGame();
		globe.PlayGame();
	}
}