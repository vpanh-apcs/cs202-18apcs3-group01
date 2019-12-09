#include "Obstacle.h"
void Obstacle::unshow()
{
	Pos newPos = MoveOnMap(position);
	GotoXY(newPos.y, newPos.x);
	cout << " ";
}

void Obstacle::show()
{
	Pos newPos = MoveOnMap(position);
	GotoXY(newPos.y, newPos.x);
}

Pos Obstacle::MoveOnMap(Pos p)
{
	GameSetting a;
	Pos tmp;
	tmp.x = a.getGameLocation().x + (1 + p.x)*a.getGameSize();
	tmp.y = a.getGameLocation().y + (2 + p.y)*a.getGameSize();
	return tmp;
}

void TREE::show()
{
	Obstacle::show();
	cout << "T";
}
void CCAR::show()
{
	Obstacle::show();
	cout << "C";
}
void CTRUCK::show()
{
	Obstacle::show();
	cout << "U";
}
void CBIRD::show()
{
	Obstacle::show();
	cout << "I";
}
void CDINOSAUR::show()
{
	Obstacle::show();
	cout << "O";
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