#include "CGame.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <iomanip>

class Startup
{
public:
	static void drawTitle();
	static void mainMenu();
	static void CreateMenu(vector<string> text, int& ChooseCase, Pos topLeft_Menu);
	static void DrawBoard(vector<string> text, int Len, Pos p);

};