#pragma once
#include <string>
#include "TextDisplay.h"
#include "CFmod.h"

class MusicPlayer
{
public:
	MusicPlayer(TextDisplay* Display);
	void SetIsMusicOn(bool isMusicOn);
	bool GetIsMusicOn();
	void SetVolume(int volume);
	void SetMusicFilename(std::string fileName);
	std::string GetMusicFilename();
	void PlayMusic(std::string fileName);
	void StopMusic();
	void ToggleMusic();

private:
	TextDisplay* Display;
	CFmod MapMusic;
	std::string MusicFilename;
	bool MusicIsOn;
};