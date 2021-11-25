#include "MusicPlayer.h"

using namespace std;

MusicPlayer::MusicPlayer(TextDisplay* display)
{
	Display = display;
	MusicIsOn = true;
	MusicFilename = "";
	SoundSystem.Init();
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
	SoundSystem.SetVolume(volume);
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
	string fullPath = "./data/";

	fullPath.append(filename);

	if (fullPath.c_str())
	{
		if (!SoundSystem.LoadSong(fullPath.c_str()))
		{
			// text("MUSIC FILE PROBLEMS!!!",13,12,yellow);
			Display->DisplayError("MUSIC FILE LOAD FAILED!!!");
			exit(1);
		}
		SoundSystem.PlaySong();
	}
	else
		SoundSystem.FreeSound();
}

void MusicPlayer::ToggleMusic()
{
	if (MusicIsOn)
	{
		MusicIsOn = false;
		SoundSystem.FreeSound();
	}
	else
	{
		MusicIsOn = true;
		PlayMusic(MusicFilename.c_str());
	}
}

void MusicPlayer::PlaySoundFile(std::string fileName)
{
	string fullPath = "./data/";

	fullPath.append(fileName);

	if (fullPath.c_str())
	{
		if (!SoundSystem.LoadSound(fullPath.c_str()))
		{
			// text("MUSIC FILE PROBLEMS!!!",13,12,yellow);
			Display->DisplayError("SOUND FILE LOAD FAILED!!!");
			exit(1);
		}
		SoundSystem.PlaySoundFile();
	}
}

void MusicPlayer::StopMusic()
{
	SoundSystem.FreeSound();
}