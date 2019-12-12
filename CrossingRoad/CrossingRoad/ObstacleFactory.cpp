#include "ObstacleFactory.h"

Obstacle* ObstacleFactory::getRandomMovingObstacle(Pos position, int direction)
{
	return getMovingObstacle(Random(5, 8), position, direction);
}

Obstacle* ObstacleFactory::getMovingObstacle(int id, Pos position, int direction)
{
	switch (id)
	{
	case 5: return new CTRUCK(position, direction);
	case 6: return new CCAR(position, direction);
	case 7: return new CBIRD(position, direction);
	case 8: return new CDINOSAUR(position, direction);
	}
}