#include "GameSetting.h"

int GameSetting::GameHeight = 10;
int GameSetting::GameWidth = 20;
int GameSetting::GameSize = 1;
Pos GameSetting::GameLocation = Pos(0, 0);

int GameSetting::getGameHeight()
{
	return GameHeight;
}

int GameSetting::getGameWidth()
{
	return GameWidth;
}

int GameSetting::getGameSize()
{
	return GameSize;
}

Pos GameSetting::getGameLocation()
{
	return GameLocation;
}