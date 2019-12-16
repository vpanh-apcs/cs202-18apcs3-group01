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
	file >> position.x >> position.y >> direction >> hitbox;
	//file.close();
}
CVEHICLE::CVEHICLE(Pos a, bool directiont) :Obstacle(a, directiont) {}
CTRUCK::CTRUCK(Pos a, bool directiont) :CVEHICLE(a, directiont) {}
CCAR::CCAR(Pos a, bool directiont) : CVEHICLE(a, directiont) {}
CANIMAL::CANIMAL(Pos a, bool directiont) : Obstacle(a, directiont) {}
CDINOSAUR::CDINOSAUR(Pos a, bool directiont) : CANIMAL(a, directiont) {}
CBIRD::CBIRD(Pos a, bool directiont) : CANIMAL(a, directiont) {}

void TREE::save(ofstream& file)
{
	file << 3 << " " << position.x << " " << position.y << endl;
}
void CCAR::save(ofstream& file)
{
	file << 6 << " " << position.x << " " << position.y << endl;
}
void CTRUCK::save(ofstream& file)
{
	file << 5 << " " << position.x << " " << position.y << endl;
}
void CBIRD::save(ofstream& file)
{
	file << 7 << " " << position.x << " " << position.y << endl;
}
void CDINOSAUR::save(ofstream& file)
{
	file << 8 << " " << position.x << " " << position.y << endl;
}

void TREE::load(ifstream& file)
{
}
void CCAR::load(ifstream& file)
{
}
void CTRUCK::load(ifstream& file)
{
}
void CBIRD::load(ifstream& file)
{
}
void CDINOSAUR::load(ifstream& file)
{
}