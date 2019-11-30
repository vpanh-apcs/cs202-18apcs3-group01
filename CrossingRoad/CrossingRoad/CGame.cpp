#include "CGame.h"

CGAME::CGAME()
{	
	level = 1;
	tl = Pos(0,0);
	br = Pos(10,10);
	for (int i = 0; i < br.x; i++)
		for (int j = 0; j < br.y; j++)
			map[i][j] = 0;

	int temp = 4;
	for (int i = 0; i < br.x; i++)
	{
		int random = Random(0, temp);
		if (random == 0)
		{
			routes[i] = new LeDuong(Pos(tl.x + i, tl.y), Pos(tl.x + i, br.y));
			temp = 4;
		}
		else
		{
			routes[i] = new Duong(Pos(tl.x + i, tl.y), Pos(tl.x + i, br.y));
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
	for (int i = 0; i < br.x; i++)
		routes[i]->draw();
};

void CGAME::routesMove()
{
	while (stop)
	{
		for (int i = 0; i < 10; i++)
		{
			routes[i]->move();
			routes[i]->draw();
		}
		Sleep(500);
	}
};

void CGAME::startGame()
{
	thread trdRoutes(&CGAME::routesMove, *this);
	trdRoutes.join();
}