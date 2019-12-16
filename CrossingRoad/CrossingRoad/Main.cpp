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
<<<<<<< HEAD


	
	/*CGAME b;
	b.loadGame();
	b.startGame();*/
=======
>>>>>>> 409de0c4af819af24d3568fa7ae57da6cbedd4ea
	system("pause");
	return 0;
}
