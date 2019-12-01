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
bool Pos:: operator==(const Pos& p)
{
	if (x == p.x && y == p.y)
		return true;
	return false;
}
void DrawBoard(int x, int y, int width, int height)//height %6 =0
{
	//char goc1 = 218, goc2 = 191, goc3 = 217, goc4 = 192, doc = 179, ngang = 196;
	//Ve Khung
	GotoXY(x, y);
	cout << char(218);
	int k = 1;
	for (int i = 0; i < width; i++)
	{
		GotoXY(x + k, y);
		cout << char(196);
		GotoXY(x + k, y + height);
		cout << char(196);
		k++;
	}
	GotoXY(x + width, y);
	cout << char(191);
	k = 1;
	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + k);
		cout << char(179);
		GotoXY(x + width, y + k);
		cout << char(179);;
		k++;
	}
	GotoXY(x + width, y + height);
	cout << char(217);
	GotoXY(x, y + height);
	cout << char(192);

}