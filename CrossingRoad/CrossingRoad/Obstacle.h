#include "Helper.h"

class Obstacle
{
protected:
	Pos position;
	bool direction = 0;
	int hitbox;
public:
	Obstacle() {};
	Obstacle(Pos a);
	~Obstacle() {};
	void move();	
	virtual void show() {};
	virtual void save() {};
	virtual void load() {};
	Pos getPos();
};

class TREE : public Obstacle
{
public:
	TREE(Pos positiont);
	void show();
};

class CVEHICLE : public Obstacle
{
};

class CANIMAL : public Obstacle
{
};

class CTRUCK : public CVEHICLE
{ 
public:
	CTRUCK(Pos a);
	void show();
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
