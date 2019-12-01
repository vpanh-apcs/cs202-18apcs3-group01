#include "Startup.h"

int main()
{
	FixConsoleWindow();
	Startup::mainMenu();
	CGAME a;
	a.startGame();
	system("pause");
	return 0;
}
