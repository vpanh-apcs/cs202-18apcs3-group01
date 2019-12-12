#include "Startup.h"

int main()
{
	FixConsoleWindow();
	//Startup::mainMenu();
	
	CGAME a;
	a.init();
	a.startGame();

	/*CGAME b;
	b.loadGame();
	b.startGame();*/
	system("pause");
	return 0;
}
