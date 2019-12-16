#include "CGame.h"

class Startup
{
	CGAME* game = NULL;
public:
	Startup();
	void Settings();
	CGAME* LoadGame();
	CGAME* highScoreBoard();
	~Startup()
	{
		delete game;
	};
};
