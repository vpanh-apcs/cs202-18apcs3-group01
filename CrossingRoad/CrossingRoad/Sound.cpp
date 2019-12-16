#include<iostream>
#include<windows.h>
#include<string>
#include<thread>
#include<vector>
#include<fstream>
#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <list>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <limits>
#include "Sound.h"

using namespace std;

MusicPlayer::MusicPlayer()
	: mMusic()
	, mFilenames()
{	
	mFilenames[Music::MenuTheme] = "sound/MenuTheme.wav";
	mFilenames[Music::MissionTheme] = "sound/MissionTheme.wav";
}

MusicPlayer* MusicPlayer::getInstance()
{
	if (sInstance == nullptr)
		return new MusicPlayer();
	return sInstance;
}

void MusicPlayer::play(Music::ID theme)
{
	string filename = sInstance->mFilenames[theme];
	if (!sInstance->mMusic.openFromFile(filename))
		throw runtime_error("Music " + filename + " could not beloaded.");
	sInstance->mMusic.setLoop(true);
	sInstance->mMusic.play();
}

void MusicPlayer::stop()
{
	sInstance->mMusic.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		sInstance->mMusic.pause();
	else
		sInstance->mMusic.play();
}

///////
SoundPlayerEffect* SoundPlayerEffect::getInstance()
{
	if (sInstance == nullptr)
		return new SoundPlayerEffect();
	return sInstance;
}

SoundPlayerEffect::SoundPlayerEffect()
	:mMusic()
	, mFilenames()
{
	isOn = true;
	mFilenames[SoundEffect::LevelUp]    = "soundeffect/levelup.wav";
	mFilenames[SoundEffect::VehicleHit] = "soundeffect/vehiclehit.wav";
	mFilenames[SoundEffect::AnimalHit]  = "soundeffect/animalhit.wav";
	mFilenames[SoundEffect::PlayerDies] = "soundeffect/playerdies.wav";
	mFilenames[SoundEffect::Win]        = "soundeffect/win.wav";
}
void SoundPlayerEffect::play(SoundEffect::ID theme)
{
	if (sInstance->isOn) {
		string filename = sInstance->mFilenames[theme];
		if (!sInstance->mMusic.openFromFile(filename))
			throw runtime_error("Music " + filename + " could not beloaded.");
		sInstance->mMusic.play();
	}
}
void SoundPlayerEffect::setState(bool state)
{
	sInstance->isOn = state;
}