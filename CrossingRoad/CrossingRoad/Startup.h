#include "CGame.h"

class Startup
{
	CGAME* game = NULL;
public:
	Startup();
	CGAME* LoadGame();
	void highScoreBoard();
	~Startup()
	{
		delete game;
	};
};