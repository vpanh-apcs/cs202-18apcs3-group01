#include "Helper.h"

class Obstacle
{
	Pos position;
	int direction;
	int hitbox;
	virtual void show(Pos start, Pos end) = 0;
public:
	Obstacle(Pos a);
	~Obstacle();
	void move();
	Pos getPos() { return position; };
	virtual void save();
	virtual void load();
};

class CVEHICLE : public Obstacle
{
};

class CANIMAL : public Obstacle
{
};

class CTRUCK : public CVEHICLE
{ 

};

class CCAR : public CVEHICLE
{

};

class CBIRD : public CANIMAL
{

};

class CDINOSAUR : public CANIMAL
{

};
