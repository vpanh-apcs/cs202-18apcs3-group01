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
	GotoXY(position.y*2, position.x*2);
	cout << "AA";
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