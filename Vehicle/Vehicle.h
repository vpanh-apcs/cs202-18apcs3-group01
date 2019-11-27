#pragma once
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
struct Position
{
	int x;
	int y;
};
void GotoXY(int x, int y);
void GotoXY(Position pos);
class Vehicle
{
	
private:
	Position Pos;
	bool Exist;
	bool Stop;
	int SpeedRate;
	static int Count;
public:
	Vehicle(Position pos);
	static int GetCount();
	void SetSpeedRate(int rate);
	bool IsExist();
	Position GetPosition();
	bool IsStop();
	virtual void StopMove();
	virtual void Move(Position pos);
	virtual void Left();
	virtual void Right();
	virtual void Left(int n);
	virtual void Right(int n);
	virtual void Display();
    int GetSpeedRate();
	~Vehicle();
	//bool Crash(People &people);
};
class Truck : public Vehicle
{
public:
	Truck(Position pos);
	/*void Move(Position& pos);
	void Left();
	void Right();*/
	//void Display();
};
class Car : public Vehicle
{
public:
	Car(Position pos);
	//void Move(Position& pos);
	//void Left();
	//void Right();
	//void Display();
};