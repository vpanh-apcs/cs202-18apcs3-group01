#include "Route.h"


LeDuong::LeDuong(int indext, int lengtht)
{
	index = indext;
	length = lengtht;
}
void LeDuong::init(int level)
{
	for (int i = 0; i < length; i++)
	{
		if ((Random(35, 71)==71) && (TF == false))
		{
			trafficlight = TrafficLight(Pos(index, -1), Random(4,6));
			TF = true;
		}
		else
		{
			if (queue == 0)
			{
				TREE* temp = new TREE(Pos(index, -1));
				trees.push_back(temp);
				queue = Random(3, 6);
			}
		}
		if (queue > 0) queue--;
		for (int j = trees.size() - 1; j >= 0; j--)
		{
			trees[j]->move();
		}
		trafficlight.move();
	}
}

void LeDuong::updateMap(int map[10][20])
{
	for (int i = 0; i < length; i++)
		map[index][i] = map[index][i] == 1 ? 1 : 0;
	if (TF)
		map[index][trafficlight.getPos().y] = 4;
	for (int i = 0; i < trees.size(); i++)
	{
		map[index][trees[i]->getPos().y] = 3;
	}
}
void LeDuong::save(ofstream& file)
{
	file << 0 << " " << trees.size() << endl;
	file << TF << endl;
	if (TF)
	{
		trafficlight.save(file);
	}
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
	file >> TF;
	if (TF)
	{
		bool signal;
		int rate;
		file >> x >> y >> signal >> rate;
		trafficlight = TrafficLight(Pos(x,y), rate);
		if (trafficlight.getSignal() != signal)
			trafficlight.changeSignal();
	}
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
void Duong::init(int level)
{
	for (int i = 0; i < length; i++)
	{
		if ((queue == 0) && (obstacles.size() < level+int(level/1.25)))
		{
			obstacles.push_back(ObstacleFactory::getRandomMovingObstacle(Pos(index, direction == 0 ? -1 : length), direction));
			queue = Random(2, 10);
		}
		if (queue > 0) queue--;
		for (int j = obstacles.size() - 1; j >= 0; j--)
		{
			obstacles[j]->move();	
		}
	}
}
void Duong::move(int level)
{
	if ((queue == 0) && (obstacles.size() < level + int(level / 1.25)))
	{
		obstacles.push_back(ObstacleFactory::getRandomMovingObstacle(Pos(index, direction == 0 ? -1 : length), direction));
		//queue = Random(1, int(sqrt(level*Random(1,3))));
		queue = Random(1, 10);
	}
	if (queue > 0) queue--;
	for (int i = 0; i < obstacles.size(); i++)
	{
		//obstacles[i]->unshow();
		obstacles[i]->move();
		if ((obstacles[i]->getPos().y >= length) || (obstacles[i]->getPos().y < 0))
		{
			Obstacle* temp = obstacles[i];
			delete temp;
			//obstacles[i]->~Obstacle();
			obstacles.erase(obstacles.begin());
			i--;
		}
		//else
			//obstacles[i]->show();
	}
}
void Duong::updateMap(int map[10][20])
{
	for (int i = 0; i < length; i++)
		map[index][i] = map[index][i] == 1 ? 1 : 0;
	for (int i = 0; i < obstacles.size(); i++)
	{
		map[index][obstacles[i]->getPos().y] = obstacles[i]->getType();
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
Duong::~Duong()
{
	for (int i = obstacles.size() - 1; i >= 0; i--)
	{
		delete obstacles[i];
	}
	obstacles.clear();
}
LeDuong::~LeDuong()
{
	for (int i = trees.size() - 1; i >= 0; i--)
	{
		delete trees[i];
	}
	trees.clear();
}