#include "CGame.h"

class Startup
{
	CGAME* game = NULL;
public:
	Startup();
	CGAME* LoadGame();
	~Startup()
	{
		delete game;
	};
};