#include "Obstacle.h"

CVEHICLE::CVEHICLE(Pos a, bool directiont)
{
	position = a;
	direction = directiont;
}

CTRUCK::CTRUCK(Pos a, bool directiont)
{
	position = a;
	direction = directiont;
}

void CTRUCK::show()
{
	GotoXY(position.y, position.x);
	cout << "A";
}


//CCAR::CCAR(Pos a)
//{
//	position = a;
//}
//
//CTRUCK::CTRUCK(Pos a)
//{
//}
//
//CTRUCK::CTRUCK(Pos a)
//{
//	position = a;
//}