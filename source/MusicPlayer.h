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
	void StopMusic();
	void ToggleMusic();
	void PlaySoundFile(std::string fileName);

private:
	TextDisplay* Display;
	CFmod SoundSystem;
	std::string MusicFilename;
	bool MusicIsOn;
	void PlayMusic(std::string fileName);
};