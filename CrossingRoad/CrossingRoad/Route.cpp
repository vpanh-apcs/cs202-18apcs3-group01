#include "Route.h"
void LeDuong::draw()
{
	GotoXY(start.y, start.x);
	for (int i = start.y; i < end.y; i++)
	{
		cout << "_";
	}
	for (int i = 0; i < trees.size(); i++)
	{
		trees[i]->show();
	}
}

void LeDuong::updateMap(int map[10][10])
{
	for (int i = start.y; i < end.y; i++)
		map[start.x][i] = 0;
	for (int i = 0; i < trees.size(); i++)
	{
		map[trees[i]->getPos().x][trees[i]->getPos().y] = 3;
	}
}

LeDuong::LeDuong(Pos startt, Pos endt)
{
	start = startt;
	end = endt;
	int queuestart = 0;
	int queueend = 5;
	for (int i = start.y; i < end.y; i++)
	{
		int random = Random(queuestart, queueend);
		if (random < 3)
		{
			TREE* temp = new TREE(Pos(start.x, start.y - 1));
			trees.push_back(temp);
			queuestart++;
		}
		else
			queueend--;
		if (queuestart == queueend)
		{
			queuestart = 0;
			queueend = 5;
		}
		for (int i = trees.size() - 1; i >= 0; i--)
		{
			trees[i]->move();
			if (trees[i]->getPos().y >= end.y)
				trees.erase(trees.begin());
		}
	}
}

Duong::Duong(Pos startt, Pos endt, bool directiont)
{
	start = startt;
	end = endt;
	direction = directiont;
	int queuestart = 0;
	int queueend = 5;
	for (int i = start.y; i < end.y; i++)
	{
		move();
	}
}

void Duong::draw()
{
	GotoXY(start.y, start.x);
	for (int i = start.y; i < end.y; i++)
	{
		cout << "_";
	}
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->show();
	}
}

void Duong::move()
{

	int queuestart = 0;
	int queueend = 5;
	int random = Random(queuestart, queueend);
	if (random < 3)
	{
		int randoma = Random(0, 3);
		randoma = 0;
		Obstacle* temp;
		switch (randoma)
		{
		case(0): temp = new CTRUCK(Pos(start.x, direction == 0 ? start.y - 1 : end.y), direction);
			/*case(1): temp = new CCAR(Pos(start.x, start.y - 1));
			case(2): temp = new CBIRD(Pos(start.x, start.y - 1));
			case(3): temp = new CDINOSAUR(Pos(start.x, start.y - 1));*/
		}
		obstacles.push_back(temp);
		queuestart++;
	}
	else
		queueend--;
	if (queuestart == queueend)
	{
		queuestart = 0;
		queueend = 5;
	}
		for (int i = obstacles.size() - 1; i >= 0; i--)
		{
			obstacles[i]->move();
			if ((obstacles[i]->getPos().y >= end.y)|| (obstacles[i]->getPos().y < start.y))
				obstacles.erase(obstacles.begin());
		}
}

void Duong::updateMap(int map[10][10])
{
	for (int i = start.y; i < end.y; i++)
		map[start.x][i] = 0;
	for (int i = 0; i < obstacles.size(); i++)
	{
		map[obstacles[i]->getPos().x][obstacles[i]->getPos().y] = 2;
	}
}
