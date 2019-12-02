#include "Route.h"

LeDuong::LeDuong(int indext, int lengtht)
{
	index = indext;
	length = lengtht;
	for (int i = 0; i < length; i++)
	{
		int random = Random(0, 3);
		if (random < 2)
		{
			TREE* temp = new TREE(Pos(index, -1));
			trees.push_back(temp);
		}
		for (int j = trees.size() - 1; j >= 0; j--)
			trees[j]->move();
	}
}

void LeDuong::draw()
{
	for (int i = 0; i < trees.size(); i++)
	{
		trees[i]->show();
	}
}

void LeDuong::updateMap(int map[10][10])
{
	for (int i = 0; i < length; i++)
		map[index][i] = 0;
	for (int i = 0; i < trees.size(); i++)
	{
		map[index][trees[i]->getPos().y] = 3;
	}
}


Duong::Duong(int indext, int lengtht , bool directiont)
{
	index = indext;
	length = lengtht;
	direction = directiont;
	for (int i = 0; i < length; i++)
		move();
}

void Duong::draw()
{
	/*for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->show();
	}*/
}

void Duong::move()
{
	int random = Random(0, 3);
	if (random < 2)
	{
		int randoma = Random(0, 3);
		randoma = 0;
		Obstacle* temp;
		switch (randoma)
		{
		case(0): temp = new CTRUCK(Pos(index, direction == 0 ? -1 : length), direction);
			/*case(1): temp = new CCAR(Pos(start.x, start.y - 1));
			case(2): temp = new CBIRD(Pos(start.x, start.y - 1));
			case(3): temp = new CDINOSAUR(Pos(start.x, start.y - 1));*/
		}
		obstacles.push_back(temp);
	}
	for (int i = obstacles.size() - 1; i >= 0; i--)
	{
		
		obstacles[i]->move();
		obstacles[i]->unshow();
		if ((obstacles[i]->getPos().y >= length) || (obstacles[i]->getPos().y < 0))
			obstacles.erase(obstacles.begin());
		else
			obstacles[i]->show();
	}
}

void Duong::updateMap(int map[10][10])
{
	for (int i = 0; i < length; i++)
		map[index][i] = 0;
	for (int i = 0; i < obstacles.size(); i++)
	{
		map[index][obstacles[i]->getPos().y] = 4;
	}
}
