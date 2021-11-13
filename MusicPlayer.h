#pragma once
#include "TextDisplay.h"
#include "CFmod.h"

class MusicPlayer
{
public:
	MusicPlayer(TextDisplay* Display);
	void SetIsMusicOn(bool isMusicOn);
	bool GetIsMusicOn();
	void SetMusicFilename(char*);
	char* GetMusicFilename();
	void PlayMusic(const char*);
	void StopMusic();
	void ToggleMusic();

private:
	TextDisplay* Display;
	CFmod MapMusic;
	char* MusicFilename;
	bool MusicIsOn;
};