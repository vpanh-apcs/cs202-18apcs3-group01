#include "CGame.h"

class Startup
{
	CGAME* game = NULL;
public:
	Startup();
	CGAME* LoadGame();
	CGAME* highScoreBoard();
	~Startup()
	{
		delete game;
	};
};