#include "CGame.h"

CGAME::CGAME()
{	
	for (int i = 0; i < br.x - tl.x; i++)
		for (int j = 0; j < br.y - tl.y; j++)
			map[i][j] = 0;

	int temp = 4, direction = 0;
	for (int i = 0; i < br.x - tl.x; i++)
	{
		int random = Random(0, temp);
		if (random == 0)
		{
			routes[i] = new LeDuong(Pos(tl.x + i, tl.y), Pos(tl.x + i, br.y));
			temp = 4;
			direction = Random(0, 1);
		}
		else
		{
			routes[i] = new Duong(Pos(tl.x + i, tl.y), Pos(tl.x + i, br.y), direction);
		}
		if (temp == 0) 
			temp = 4; 
		else 
			temp--;
	}
	GotoXY(0, 0);
};
 
void CGAME::drawGame()
{
	system("CLS");
	for (int i = 0; i < br.x - tl.x; i++)
		routes[i]->draw();
};

void CGAME::routesMove()
{	
	while (!this->stop)
	{
		for (int i = 0; i < br.x - tl.x; i++)
		{
			routes[i]->move();
			routes[i]->draw();
			routes[i]->updateMap(map,tl.x,tl.y);
		}
		Sleep(300);
	}
};

void CGAME::pauseGame()
{
	GotoXY(tl.y*2 - 10, tl.x*2);
	cout << "Paused" << endl;
	int temp;
	char key = 'a';
	while (key != 'p')
	{
		temp = _getch();
		key = (char)temp;
	}
	GotoXY(tl.y * 2 - 10, tl.x * 2);
	cout << "      " << endl;
	startGame();
}

void CGAME::controller()
{	
	thread trdRoutes(&CGAME::routesMove, this);
	
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
	trdRoutes.join();
}



void CGAME::startGame()
{
	stop = false;
	
	thread getKey(&CGAME::controller, this);
	
	getKey.join();
}