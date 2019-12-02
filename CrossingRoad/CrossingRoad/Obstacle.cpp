#include "Obstacle.h"
Pos Obstacle::getPos() 
{ 
	return position; 
};

void Obstacle::move() 
{
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

void Obstacle::save(ofstream& file)
{
	//file.open("Obstacle.txt");
	file << position.x << " " << position.y <<" "<< direction<<" " << hitbox;
	//file.close();
}
void Obstacle::load(ifstream& file)
{
	//file.open("Obstacle.txt");
	if (file.fail())
		return;
	file >> position.x >> position.y >> direction >> hitbox;
	//file.close();
}
CVEHICLE::CVEHICLE(Pos a, bool directiont) :Obstacle(a, directiont) {}
CTRUCK::CTRUCK(Pos a, bool directiont) :CVEHICLE(a, directiont) {}
CCAR::CCAR(Pos a, bool directiont) : CVEHICLE(a, directiont) {}
CANIMAL::CANIMAL(Pos a, bool directiont) : Obstacle(a, directiont) {}
//CDINOSAUR::CDINOSAUR(Pos a, bool directiont) : CANIMAL(a, directiont) {}
//CBIRD::CBIRD(Pos a, bool directiont) : CANIMAL(a, directiont) {}

void TREE::save(ofstream& file)
{
	file.open("Tree.txt");
	Obstacle::save(file);
	file.close();
}
void CCAR::save(ofstream& file)
{
	file.open("Car.txt");
	Obstacle::save(file);
	file.close();
}
void CTRUCK::save(ofstream& file)
{
	file.open("Truck.txt");
	Obstacle::save(file);
	file.close();
}
void CBIRD::save(ofstream& file)
{
	file.open("Bird.txt");
	Obstacle::save(file);
	file.close();
}
void CDINOSAUR::save(ofstream& file)
{
	file.open("DINOSAUR.txt");
	Obstacle::save(file);
	file.close();
}

void TREE::load(ifstream& file)
{
	file.open("Tree.txt");
	Obstacle::load(file);
	file.close();
}
void CCAR::load(ifstream& file)
{
	file.open("Car.txt");
	Obstacle::load(file);
	file.close();
}
void CTRUCK::load(ifstream& file)
{
	file.open("Truck.txt");
	Obstacle::load(file);
	file.close();
}
void CBIRD::load(ifstream& file)
{
	file.open("Bird.txt");
	Obstacle::load(file);
	file.close();
}
void CDINOSAUR::load(ifstream& file)
{
	file.open("DINOSAUR.txt");
	Obstacle::load(file);
	file.close();
}