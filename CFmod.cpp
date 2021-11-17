#include <iostream>								// Include the standard input output stream
#include "CFmod.h"								// Include our header file for Fmod prototypes
#include <fmod_errors.h>
using namespace std;							// Include the standard namespace


///////////////////////////////// CFMOD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This is if you want to create a global variable and not init the sound system
/////
///////////////////////////////// CFMOD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

CFmod::CFmod()
{
	// Clear the file name
	memset(m_strName, 0, sizeof(char));

	// Set the current song module to NULL
	m_pSound = nullptr;
	m_pFmodSystem = nullptr;
	FMOD_RESULT result = FMOD::System_Create(&m_pFmodSystem);
	CheckError(result);	
}


///////////////////////////////// ~CFMOD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This will clean up memory and close the sound system
/////
///////////////////////////////// ~CFMOD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

CFmod::~CFmod()
{
	// Free the sound pointer that loaded our song if it's valid
	FreeSound();

	// Now free the whole sound system
	FreeSoundSystem();
}

void CFmod::Init()
{

	// ==========================================================================================
	// INIT SOUND SYSTEM
	// ==========================================================================================
	
	// We want our mix rate to be to be 44100mhz (Good CD Quality), and we pass in 32 for
	// the max software channels, then FSOUND_INIT_GLOBALFOCUS to show we want it to play
	// no matter what window is in focus.
	
	// Initialize our FMod Sound System with good quality sound and a global focus
	FMOD_RESULT result = m_pFmodSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	CheckError(result);	
}

bool CFmod::LoadSong(const char *strName)
{
	if(!strName)
		return false;

	m_pSound->release();

	FMOD_RESULT result = m_pFmodSystem->createSound(strName, FMOD_DEFAULT, 0, &m_pSound);
	CheckError(result);

	result = m_pSound->setMode(FMOD_LOOP_NORMAL);
	CheckError(result);

	strcpy_s(m_strName, strName);

	return true;
}


void CFmod::PlaySong()
{
	FMOD_RESULT result = m_pFmodSystem->playSound(m_pSound, 0, false, &m_soundChannel);
	CheckError(result);
}

void CFmod::CheckError(FMOD_RESULT result)
{
	if (result != FMOD_RESULT::FMOD_OK)
		cout << FMOD_ErrorString(result) << endl;
}

void CFmod::FreeSound()
{
	m_pSound->release();
}

void CFmod::FreeSoundSystem()
{
	m_pFmodSystem->close();
	m_pFmodSystem->release();
}