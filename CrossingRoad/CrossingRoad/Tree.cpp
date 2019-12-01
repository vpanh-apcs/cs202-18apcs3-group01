#include "Obstacle.h"


TREE::TREE(Pos positiont)
{
	position = positiont;
	hitbox = 1;
};

void TREE::show() 
{ 
	GotoXY(position.y*2, position.x*2); 
	cout << "TT"; 
}