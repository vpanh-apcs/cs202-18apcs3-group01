#include "Startup.h"

void Startup::drawTitle()
{
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

	int n = (int)title1.size();
	int m = (int)title2.size();
	int length_n = (int)title1[0].size();
	int length_m = (int)title2[0].size();

	string line, leftMargin;
	leftMargin.resize(25, ' ');

	vector<string> tmp(title2.size());
	for (long long i = n - 1ll; i >= 0; --i) {
		line = leftMargin + title1[i] + "\n" + line;
		string col;
		for (long long j = 0; j < m; ++j) {
			tmp[j].insert(tmp[j].begin(), title2[j][(i + 1LL) * 5LL - 1LL]);
			tmp[j].insert(tmp[j].begin(), title2[j][(i + 1LL) * 5LL - 2LL]);
			tmp[j].insert(tmp[j].begin(), title2[j][(i + 1LL) * 5LL - 3LL]);
			tmp[j].insert(tmp[j].begin(), title2[j][(i + 1LL) * 5LL - 4LL]);
			tmp[j].insert(tmp[j].begin(), title2[j][(i + 1LL) * 5LL - 5LL]);
			col += tmp[j] + "\n";
		}

		GotoXY(0, 0);
		cout << line << endl;
		GotoXY(0, 13);
		cout << col;
		Sleep(100);
	}

	FileTitle1.close();
	FileTitle2.close();
}

void Startup::mainMenu() 
{
	Startup::drawTitle();
	vector<string> text = { "NEW GAME", "LOAD GAME", "HIGH SCORES", "SETTINGS", "QUIT", " " };

	Pos topLeft_Menu(25 + 28, 21);
	int Case = 0;
	Startup::CreateMenu(text, Case, topLeft_Menu);
}

void Startup::CreateMenu(vector<string> text, int& ChooseCase, Pos topLeft_Menu) {
	DrawBoard(text, 50, topLeft_Menu);
	int nText = (int)text.size();
	while (true) {
		textcolor(15);
		//cout << "Main Menu\n\n";
		for (int i = 0; i < nText; ++i) {
			GotoXY(topLeft_Menu.x, topLeft_Menu.y + 2 * i);
			if (i == ChooseCase) {
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
			++ChooseCase;
			return;
		case 72://UP
			ChooseCase -= 1;
			if (ChooseCase == -1) 
				ChooseCase = nText - 2;
			break;
		case 80://DOWN
			ChooseCase += 1;
			if (ChooseCase == nText - 1) 
				ChooseCase = 0;
			break;
		}
	}
}
