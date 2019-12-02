#include "Startup.h"

int main()
{
	/*FixConsoleWindow();
	Startup::mainMenu();*/
	CGAME a(Pos(0,0),10,10);
	a.startGame();
	system("pause");
	return 0;
}
