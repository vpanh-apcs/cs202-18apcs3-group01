#include "Vehicle.h"


void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(Position pos)
{
	COORD coord;
	coord.X = pos.x;
	coord.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Vehicle::Vehicle(Position pos)
{	
	Count++;
	Exist = true;
	Stop = false;
	Pos = pos;	
	SpeedRate = 1;
}
Vehicle::~Vehicle()
{
	Count--;
}
int Vehicle::GetCount()
{
	return Count;
//	return 0;
}
int Vehicle::GetSpeedRate()
{
	return SpeedRate;
}
bool Vehicle::IsExist()
{
	return Exist;
}
bool Vehicle::IsStop()
{
	return Stop;
}
void Vehicle::SetSpeedRate(int rate)
{
	SpeedRate = rate;
}
Position Vehicle::GetPosition()
{
	return Pos;
}
void Vehicle::Display()
{
	GotoXY(Pos);
	cout << Pos.x << "--" << Pos.y;
}
void Vehicle::Move(Position pos)
{
	Pos = pos;
	GotoXY(Pos);
}
void Vehicle::StopMove()
{

}
void Vehicle::Left()
{
	Pos.x = Pos.x - 1 * SpeedRate;
	GotoXY(Pos);
}
void Vehicle::Left(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		Left();
	}
}
void Vehicle::Right()
{
	Pos.x = Pos.x + 1*SpeedRate;
	GotoXY(Pos);
}
void Vehicle::Right(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		Right();
	}
}

Truck::Truck(Position pos) : Vehicle(pos) 
{
	SetSpeedRate(2);
}
//void Truck::Move(Position& pos)
//{
//	Vehicle::Move(pos);
//}
//void Truck::Left()
//{
//
//}
//void Truck::Right();
//void Truck::Display();

