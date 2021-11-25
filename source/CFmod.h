#ifndef _CFMOD_H
#define _CFMOD_H

#pragma warning( disable : 26812)
#include "fmod.hpp"
#pragma warning( default : 26812)

// This class allows you to initialize, load and play a MP3 or WAV sound
class CFmod {

public:

	CFmod();

	~CFmod();

	void Init();
	bool LoadSong(const char *strName);
	void PlaySong();
	bool LoadSound(const char* soundFile);
	void PlaySoundFile();
	void FreeSound();
	void FreeSoundSystem();
	void SetVolume(int volume);
	FMOD::Sound* GetSound() {	return m_BgmSound;			}
	char *GetFileName()	{ return m_strName;					}

private:

	FMOD::Sound* m_BgmSound;
	FMOD::Sound* m_SfxSound;
	FMOD::System* m_pFmodSystem;
	char m_strName[255];
	FMOD::Channel* m_BgmChannel;
	FMOD::Channel* m_SfxChannel;
	signed char m_loop;
	float Volume;
	void CheckError(FMOD_RESULT result);
};

#endif