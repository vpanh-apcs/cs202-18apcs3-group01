#include "Helper.h"

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

int Random(int start, int end)
{
	srand(time(NULL));
	return start + rand() % (end - start + 1);
}

Pos::Pos()
{
	x = 0; 
	y = 0;
}

Pos::Pos(int xt, int yt)
{
	x = xt;
	y = yt;
}