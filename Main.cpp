#include "MainHeader.h"

int main()
{
	FixConsoleWindow();
	//Startup a;
	//a.run();
//	DrawBoard(30, 30, 40, 20);
	CPEOPLE x;
	x.showinfo();
	ofstream file;
	x.save(file);
	_getch(); 
	//system("pause");
	return 0;
}