#include "CGame.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

class Startup
{
public:
	static void drawTitle();
	static void mainMenu();
	static void CreateMenu(vector<string> text, int& ChooseCase, Pos topLeft_Menu);

	static void DrawBoard(vector<string> text, int Len, Pos p)
	{
		int length = (int)text[0].size();
		int nText = text.size();

		for (int i = 0; i < nText; ++i)
		{
			if (i == 0)
			{
				GotoXY(p.x, p.y);
				cout << char(218);
				for (int i = 0; i < length; ++i) 
					cout << char(196);
				if (Len != 0) cout << char(194);
				else cout << char(191);
				for (int i = 0; i < Len; ++i)
				{
					cout << char(196);
					if (i == Len - 1) cout << char(191);
				}
				GotoXY(p.x, ++p.y);
				cout << char(179) << text[i] << char(179);
				for (int i = 0; i < Len; ++i) {
					cout << " ";
					if (i == Len - 1) cout << char(179);
				}
				GotoXY(p.x, ++p.y);
			}
			else
			{
				GotoXY(p.x, p.y);
				cout << char(195);
				for (int i = 0; i < length; ++i) cout << char(196);
				if (Len > 0) cout << char(197);
				else cout << char(180);
				for (int i = 0; i < Len; ++i)
				{
					cout << char(196);
					if (i == Len - 1) cout << char(180);
				}
				GotoXY(p.x, ++p.y);
				cout << char(179) << text[i] << char(179);
				for (int i = 0; i < Len; ++i)
				{
					cout << " ";
					if (i == Len - 1) cout << char(179);
				}
				GotoXY(p.x, ++p.y);
			}
			if (i == nText - 1)
			{
				GotoXY(p.x, p.y);
				cout << char(192);
				for (int i = 0; i < length; ++i) cout << char(196);
				if (Len > 0) cout << char(193);
				else cout << char(217);
				for (int i = 0; i < Len; ++i)
				{
					cout << char(196);
					if (i == Len - 1) cout << char(217);
				}
				GotoXY(p.x, ++p.y);
			}
		}
	}

};