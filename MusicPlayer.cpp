#include "MusicPlayer.h"

using namespace std;

MusicPlayer::MusicPlayer(TextDisplay* display)
{
	Display = display;
	MusicIsOn = true;
	MusicFilename = "";
	MapMusic.Init();
}

void MusicPlayer::SetIsMusicOn(bool musicOn)
{
	MusicIsOn = musicOn;
}
bool MusicPlayer::GetIsMusicOn()
{
	return MusicIsOn;
}

void MusicPlayer::SetVolume(int volume)
{
	MapMusic.SetVolume(volume);
}

void MusicPlayer::SetMusicFilename(string filename)
{
	if (MusicFilename != filename)
	{
		MusicFilename = filename;
		if (MusicIsOn)
			PlayMusic(MusicFilename);
	}
}

string MusicPlayer::GetMusicFilename()
{
	return MusicFilename;
}

/*==================================
	Plays the game music
===================================*/
void MusicPlayer::PlayMusic(string filename)
{
	const char* dataPath = "./data/";

	string fullPath = dataPath;
	fullPath.append(filename);

	if (fullPath.c_str())
	{
		if (!MapMusic.LoadSong(fullPath.c_str()))
		{
			// text("MUSIC FILE PROBLEMS!!!",13,12,yellow);
			Display->DisplayError("MUSIC FILE LOAD FAILED!!!");
			exit(1);
		}
		MapMusic.PlaySong();
	}
	else
		MapMusic.FreeSound();
}

void MusicPlayer::ToggleMusic()
{
	if (MusicIsOn)
	{
		MusicIsOn = false;
		MapMusic.FreeSound();
	}
	else
	{
		MusicIsOn = true;
		PlayMusic(MusicFilename.c_str());
	}
}

void MusicPlayer::StopMusic()
{
	MapMusic.FreeSound();
}