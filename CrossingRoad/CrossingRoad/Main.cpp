#include "Startup.h"

int main()
{
	FixConsoleWindow();
	//Startup::mainMenu();
	for (size_t i = 0; i < 8; i++)
	{
		cout << i  << "  " << (i-1)/1.25<<endl;
	}


	CGAME a;
	a.init();
	a.startGame();


	
	/*CGAME b;
	b.loadGame();
	b.startGame();*/
	system("pause");
	return 0;
}
