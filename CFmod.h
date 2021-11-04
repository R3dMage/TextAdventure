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

	void FreeSound();

	void FreeSoundSystem();

	FMOD::Sound* GetSound() {	return m_pSound;			}

	//char *GetSongName()	{ return m_pSound->getName(); }

	char *GetFileName()	{ return m_strName;					}

private:

	FMOD::Sound *m_pSound;

	FMOD::System* m_pFmodSystem;

	char m_strName[255];

	FMOD::Channel *m_soundChannel;

	void CheckError(FMOD_RESULT result);

	signed char m_loop;
};

#endif