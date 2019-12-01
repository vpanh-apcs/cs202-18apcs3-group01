#include "Obstacle.h"

Pos Obstacle::getPos() 
{ 
	return position; 
};

void Obstacle::move() {
	if (direction == 0)
		position.y++;
	else
		position.y--;
};

Obstacle::Obstacle(Pos pos)
{
	position = pos;
}

Obstacle::Obstacle(Pos pos, bool directiont)
{
	position = pos;
	direction = directiont;
}