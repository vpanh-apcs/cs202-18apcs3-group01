#include <iostream>
#include <stdio.h>
#include <SFML/Audio.hpp>

namespace Music
{
	enum ID
	{
		MenuTheme,
		MissionTheme,
	};
}

class MusicPlayer : private sf::NonCopyable
{
public:
	static MusicPlayer* getInstance();
	static void play(Music::ID theme);
	static void stop();
	static void setPaused(bool paused);
	static MusicPlayer* sInstance;
private:
	MusicPlayer();

	sf::Music mMusic;
	std::map<Music::ID, std::string> mFilenames;
};

namespace SoundEffect
{
	enum ID
	{
		PlayerDies,
		LevelUp,
		Win,
		AnimalHit,
		VehicleHit
	};
}

class SoundPlayerEffect : private sf::NonCopyable
{
public:
	static SoundPlayerEffect* getInstance();
	static void play(SoundEffect::ID theme);
	static void setState(bool state);
	static SoundPlayerEffect* sInstance;
private:
	SoundPlayerEffect();
	sf::Music mMusic;
	std::map<SoundEffect::ID, std::string> mFilenames;
	bool isOn;
};