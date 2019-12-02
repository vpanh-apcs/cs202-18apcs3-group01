#include "CGame.h"

CGAME::CGAME(Pos locationt, int heightt, int widtht)
{	
	location = locationt;
	height = heightt;
	width = widtht;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			map[i][j] = 0;
	int direction = 0;
	int queue = 0;
	for (int i = 0; i < width; i++)
	{
		if (queue == 0)
		{
			routes[i] = new LeDuong(i, width);
			direction = Random(0, 1);
			queue = Random(1, 3);
		}
		else
		{
			queue--;
			routes[i] = new Duong(i, width, direction);
		}
	}
	GotoXY(0, 0);
};
 
void CGAME::drawGame()
{
	system("CLS");
	for (int i = 0; i < height; i++)
		routes[i]->draw();
};

void CGAME::routesMove()
{	
	while (!stop)
	{
		for (int i = 0; i < 10; i++)
		{
			routes[i]->move();
			routes[i]->draw();
			routes[i]->updateMap(map);
		}
		GotoXY(0, 15);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << map[i][j];
			cout << endl;
		}
		Sleep(300);
	}
};

void CGAME::pauseGame()
{
	int temp;
	char key = 'a';
	while (key != 'p')
	{
		temp = _getch();
		key = (char)temp;
	}
	startGame();
}

void CGAME::controller()
{	
	
	
	int temp;
	char key = 'a';
	people.show();
	while (key != 'p')
	{
		temp = _getch();
		key = (char)temp;
		switch (key)
		{
		case'w': case'a': case's': case'd':
			people.move(key);
			people.show();
			break;
		}
	}
	stop = true;
	pauseGame();
	
}



void CGAME::startGame()
{
	stop = false;
	thread trdRoutes(&CGAME::routesMove, this);
	thread getKey(&CGAME::controller, this);
	trdRoutes.join();
	getKey.join();
}