#include "CGame.h"

class Startup
{
	CGAME* game = NULL;
public:
	Startup();
	void Settings();
	CGAME* LoadGame();
	void highScoreBoard();
	~Startup()
	{
		delete game;
	};
};
