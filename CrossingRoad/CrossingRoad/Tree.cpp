#include "Obstacle.h"


TREE::TREE(Pos positiont)
{
	position = positiont;
	hitbox = 1;
};

void TREE::show() 
{ 
	GotoXY(position.y, position.x); 
	cout << "T"; 
}