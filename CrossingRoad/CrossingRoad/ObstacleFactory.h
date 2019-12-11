#include "Obstacle.h"

class ObstacleFactory
{
public:
	static TREE* getTree(Pos position);
	static Obstacle* getMovingObstacle(int id, Pos position, int direction);
	static Obstacle* getRandomMovingObstacle(Pos position, int direction);
};
