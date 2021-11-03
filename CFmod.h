#ifndef _CFMOD_H
#define _CFMOD_H

#include "fmod.hpp"

// This class allows you to initialize, load and play a MP3 or WAV sound
class CFmod {

public:

	CFmod();

	~CFmod();

	bool Init(char*);

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

	bool LoadSong(char *strName);

	signed char m_loop;
};

#endif