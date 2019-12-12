#include "Route.h"


LeDuong::LeDuong(int indext, int lengtht)
{
	index = indext;
	length = lengtht;
}
void LeDuong::init()
{
	int queue = 3;
	for (int i = 0; i < length; i++)
	{
		if (queue > 1)
		{
			queue--;
			TREE* temp = new TREE(Pos(index, -1));
			trees.push_back(temp);
		}
		queue--;
		if (queue == -1) queue = Random(2, 3);
		for (int j = trees.size() - 1; j >= 0; j--)
			trees[j]->move();
	}
}
void LeDuong::draw()
{
	for (int i = trees.size() - 1; i >= 0; i--)
		trees[i]->show();
}
void LeDuong::updateMap(int map[10][20])
{
	for (int i = 0; i < length; i++)
		map[index][i] = 0;
	for (int i = 0; i < trees.size(); i++)
	{
		map[index][trees[i]->getPos().y] = 3;
	}
}
void LeDuong::save(ofstream& file)
{
	file << 0 << " " << trees.size() << endl;
	for (int i = 0; i < trees.size(); i++)
	{
		trees[i]->save(file);
	}
}
void LeDuong::load(ifstream& file)
{
	int size, x, y, type;
	file >> size;
	trees.resize(size);
	for (int i = 0; i < trees.size(); i++)
	{
		file >> type >> x >> y;
		trees[i] = new TREE(Pos(x, y));
	}
}

Duong::Duong(int indext, int lengtht, bool directiont)
{
	index = indext;
	length = lengtht;
	direction = directiont;
}
void Duong::init()
{
	
	for (int i = 0; i < length; i++)
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
		for (int j = obstacles.size() - 1; j >= 0; j--)
		{
			obstacles[j]->move();
		}
	}
}
void Duong::move()
{
	int random = Random(0, 3);
	if (random < 2)
	{
		obstacles.push_back(ObstacleFactory::getRandomMovingObstacle(Pos(index, direction == 0 ? -1 : length), direction));
	}
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->unshow();
		obstacles[i]->move();
		if ((obstacles[i]->getPos().y >= length) || (obstacles[i]->getPos().y < 0))
		{
			//delete obstacles[i];
			obstacles.erase(obstacles.begin());
		}
		else
			obstacles[i]->show();
	}
}
void Duong::draw()
{
	for (int j = obstacles.size() - 1; j >= 0; j--)
		obstacles[j]->show();
}
void Duong::updateMap(int map[10][20])
{
	for (int i = 0; i < length; i++)
		map[index][i] = 0;
	for (int i = 0; i < obstacles.size(); i++)
	{
		map[index][obstacles[i]->getPos().y] = 4;
	}
}
void Duong::save(ofstream& file)
{
	file << 1 << " " << obstacles.size() << " " << direction <<endl;
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->save(file);
	}
}
void Duong::load(ifstream& file)
{
	int size, x, y, type;
	file >> size >> direction;
	obstacles.resize(size);
	for (int i = 0; i < obstacles.size(); i++)
	{
		file >> type >> x >> y;
		obstacles[i] = ObstacleFactory::getMovingObstacle(type, Pos(x, y), direction);
	}
}
