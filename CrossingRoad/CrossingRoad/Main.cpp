#include "Startup.h"

int main()
{
	FixConsoleWindow();
	//Startup::mainMenu();
	
	CGAME a;
	a.init();
	a.startGame();
	system("pause");
	return 0;
}
