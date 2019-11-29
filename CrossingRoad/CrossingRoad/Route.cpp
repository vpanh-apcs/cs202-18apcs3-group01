#include "Route.h"
void LeDuong::draw()
{
	GotoXY(start.x, start.y);
	for (int i = start.y; i < end.y; i++)
	{
		cout << "_";
	}
	for (int i = 0; i < trees.size(); i++)
	{
		trees[i]->show();
	}
}

LeDuong::LeDuong(Pos startt, Pos endt)
{
	start = startt;
	end = endt;
	for (int i = start.y; i < end.y; i++)
	{
		int random = Random(0, queue);
		if (random == 0)
		{
			TREE* temp = new TREE(Pos(start.x, start.y - 1));
			trees.push_back(temp);
		}
		if (queue == 0)
			queue = 3;
		else
			queue--;
		for (int i = trees.size() - 1; i >= 0; i--)
		{
			trees[i]->move();
			if (trees[i]->getPos().y >= end.y)
				trees.erase(trees.begin());
		}
	}
	draw();
}

Duong::Duong(Pos startt, Pos endt)
{
	start = startt;
	end = endt;
	for (int i = start.y; i < end.y; i++)
	{
		int random = Random(0, queue);
		if (random == 0)
		{
			int randoma = Random(0, 3);
			randoma = 0;
			Obstacle* temp;
			switch (randoma)
			{
			case(0): temp = new CTRUCK(Pos(start.x, start.y - 1));
			/*case(1): temp = new CCAR(Pos(start.x, start.y - 1));
			case(2): temp = new CBIRD(Pos(start.x, start.y - 1));
			case(3): temp = new CDINOSAUR(Pos(start.x, start.y - 1));*/
			}
			obstacles.push_back(temp);
		}
		if (queue == 0)
			queue = 3;
		else
			queue--;
		for (int i = obstacles.size() - 1; i >= 0; i--)
		{
			obstacles[i]->move();
			if (obstacles[i]->getPos().y >= end.y)
				obstacles.erase(obstacles.begin());
		}
	}
	draw();
}

void Duong::draw()
{
	GotoXY(start.x, start.y);
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
	{
		Sleep(400);
		int random = Random(0, queue);
		if (random == 0)
		{
			int randoma = Random(0, 3);
			randoma = 0;
			Obstacle* temp;
			switch (randoma)
			{
			case(0): temp = new CTRUCK(Pos(start.x, start.y - 1));
				/*case(1): temp = new CCAR(Pos(start.x, start.y - 1));
				case(2): temp = new CBIRD(Pos(start.x, start.y - 1));
				case(3): temp = new CDINOSAUR(Pos(start.x, start.y - 1));*/
			}
			obstacles.push_back(temp);
		}
		if (queue == 0)
			queue = 3;
		else
			queue--;
		for (int i = obstacles.size() - 1; i >= 0; i--)
		{
			obstacles[i]->move();
			if (obstacles[i]->getPos().y >= end.y)
				obstacles.erase(obstacles.begin());
		}
		draw();
	}
}
