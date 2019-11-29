#include "Obstacle.h"

CTRUCK::CTRUCK(Pos a)
{
	position = a;
}

void CTRUCK::show()
{
	GotoXY(position.x, position.y);
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