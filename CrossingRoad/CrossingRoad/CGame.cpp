#include "CGame.h"

CGAME::CGAME()
{	
};
 
void CGAME::init()
{
	GameSetting a;
	height = a.getGameHeight();
	width = a.getGameWidth();
	people = CPEOPLE(Pos(0, 0));
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			map[i][j] = 0;
	int direction = 0;
	int queue = 0;
	for (int i = 0; i < height; i++)
	{
		if (queue == 0)
		{
			routes[i] = new LeDuong(i,width);
			routes[i]->init();
			direction = Random(0, 1);
			queue = Random(1, 3);
		}
		else
		{
			queue--;
			routes[i] = new Duong(i,width,direction);
			routes[i]->init();
		}
	}
	GotoXY(0, 0);
}

void CGAME::drawGame()
{
	for (int i = 0; i < height; i++)
		routes[i]->draw();
};

void CGAME::routesMove()
{	
	for (int i = 0; i < height; i++)
			routes[i]->updateMap(map);
	while (!stop)
	{	
		for (int i = 0; i < height; i++)
		{
			routes[i]->move();
			routes[i]->updateMap(map);
			GotoXY(0, 15);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
					cout << map[i][j];
				cout << endl;
			}
		}
		switch (key)
		{
		case 'p': case 'e':
			pauseGame();
			key = '0';
			break;
		}
		Sleep(200);
	}
};

void CGAME::pauseGame()
{
	
	key = '0';
	while ((key != 'p') && (key != 'e'))
	{
		if (key == 'o')
		{
			saveGame();
			key = '0';
		}
	}
	if (key == 'e')
		stop = true;
}

void CGAME::getKey()
{	
	int temp;
	while (!stop)
	{
		temp = _getch();
		key = (char)temp;	
		switch (key)
		{
		case'w': case'a': case's': case'd':
			people.move(key);
			people.show();
			key = '0';
			break;
		}
	}
}

void CGAME::startGame()
{
	stop = false;
	drawGame();
	system("pause");
	thread getKey(&CGAME::getKey, this);
	thread trdRoutes(&CGAME::routesMove, this);
	trdRoutes.join();
	getKey.join();
}

void CGAME::saveGame()
{
	ofstream file;
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);
	string path = "temp.txt";
	file.open(path, ios::out|ios::app);
	file << asctime(ti);
	people.save(file);
	file << width << " " << height << endl;
	for (int i = 0; i < height; i++)
		routes[i]->save(file);
	file.close();
}

void CGAME::loadGame()
{
	int inttemp;
	ifstream file;
	string temp;
	string path = "temp.txt";
	file.open(path);
	getline(file, temp, '\n');
	people.load(file);
	file >> width >> height;
	for (int i = 0; i < height; i++)
	{
		file >> inttemp;
		if (inttemp == 0)
			routes[i] = new LeDuong(i,width);
		else
			routes[i] = new Duong(i,width,0);
		routes[i]->load(file);
	}
	file.close();
}


