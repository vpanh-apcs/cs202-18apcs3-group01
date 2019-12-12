#include "Helper.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <limits>

class GameSetting
{
	static int GameWidth;
	static int GameHeight;
	static int GameSize;
	static Pos GameLocation;
public:
    int getGameWidth();
	void setGameWidth(int a);
    int getGameHeight();
	void setGameHeight(int a);                                                                                         
	int getGameSize();
	void setGameSize(int a);
	Pos getGameLocation();
	void setGameLocation(int a);
};

