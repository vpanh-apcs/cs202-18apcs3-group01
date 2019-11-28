#include "CGame.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

class Startup
{
public:
	static void drawTitle() {
		ifstream FileTitle;
		FileTitle.open("title.txt");

		vector<string> sTitle;

		while (FileTitle.good()) {
			string line;
			getline(FileTitle, line);
			if (line != "\0")
				sTitle.push_back(line);
		}

		int n = (int)sTitle.size();
		string line, leftMargin;
		leftMargin.resize(28, ' ');
		for (int i = n - 1; i >= 0; --i) {
			line = leftMargin + sTitle[i] + "\n" + line;
			GotoXY(0, 0);
			cout << line << endl;
			Sleep(100);
		}

		vector<string> tmpTitle(7);
		/*for (int i = 0; i < n; ++i) {
			tmpTitle[i] = "Hello";
		}*/
		
		for (int i = 64; i >= 4; i-=5) {
			string col;
			for (int j = 0; j < n; ++j) {				
				tmpTitle[j].insert(tmpTitle[j].begin(), sTitle[j][i]);
				tmpTitle[j].insert(tmpTitle[j].begin(), sTitle[j][i - 1LL]);
				tmpTitle[j].insert(tmpTitle[j].begin(), sTitle[j][i - 2LL]);
				tmpTitle[j].insert(tmpTitle[j].begin(), sTitle[j][i - 3LL]);
				tmpTitle[j].insert(tmpTitle[j].begin(), sTitle[j][i - 4LL]);
				col += tmpTitle[j] + "\n";
			}
			GotoXY(0, 15);
			cout << col;
			Sleep(100);
		}
		string tmp;
		tmp.resize(100, 's');
		cout << tmp << endl;
		/*string col = "a";
		col += "\n";
		col += "b";
		col += "\n";
		col += "c";
		cout << col << endl;*/
	}

	static void mainMenu() {
		ifstream FileTitle1, FileTitle2;
		FileTitle1.open("tmp1.txt");
		FileTitle2.open("tmp2.txt");

		vector<string> title1, title2;
		for (int i = 0; i < 7; ++i) {
			title1.push_back("");
			title1[i].resize(65, ' ');
		}

		while (FileTitle1.good()) {
			string input;
			getline(FileTitle1, input);
			if (input != "\0")
				title1.push_back(input);
		}

		while (FileTitle2.good()) {
			string input;
			getline(FileTitle2, input);
			if (input != "\0")
				title2.push_back(input);
		}

		for (int i = 0; i < (int)title2.size(); ++i) {
			cout << title2[i] << endl;
			Sleep(100);
		}
		
		int n = (int)title1.size();
		string line, leftMargin;
		leftMargin.resize(25, ' ');

		vector<string> tmp(7);
		line = leftMargin + title1[0] + "\n";
		cout << line << endl;
		for (int i = n - 2; i >= 0; --i) {
			line = leftMargin + title1[i] + "\n" + line;
			string col;

			GotoXY(0, 0);
			cout << line << endl;

			Sleep(100);
		}

		for (int i = (int)tmp[0].size() - 1; i >= 1; i -= 2) {
			string col;
			for (int j = 0; j < 7; ++j) {
				tmp[j].insert(tmp[j].begin(), title2[j][i]);
				tmp[j].insert(tmp[j].begin(), title2[j][i - 1LL]);
				//tmp[j].insert(tmp[j].begin(), title2[6 + j][i - 2LL]);
				//tmp[j].insert(tmp[j].begin(), title2[6 + j][i - 3LL]);
				//tmp[j].insert(tmp[j].begin(), title2[6 + j][i - 4LL]);
				col += tmp[j] + "\n";
			}
			GotoXY(0, 25);
			cout << col;
			Sleep(100);
		}

		FileTitle1.close();
		FileTitle2.close();
	}
	void CreateMenu(string text[], int nText, int& position, int x, int y) {
		DrawBoard(text, nText - 1, 0, x - 1, y - 1);
		while (true) {
			textcolor(15);
			//cout << "Main Menu\n\n";
			for (int i = 0; i < nText; ++i) {
				gotoxy(x, y + 2 * i);
				if (i == position) {
					textcolor(11);
					cout << text[i];
				}
				else {
					textcolor(15);
					cout << text[i];
				}
			}

			int key = _getch();
			switch (key)
			{
			case 13://ENTER
				++position;
				return;
			case 72://UP
				position -= 1;
				if (position == -1) position = nText - 2;
				break;
			case 80://DOWN
				position += 1;
				if (position == nText - 1) position = 0;
				break;
			}
		}
	}
};
