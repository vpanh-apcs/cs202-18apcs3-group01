#include "Helper.h"

class Obstacle
{
protected:
	Pos position;
	bool direction = 0;
	int hitbox = 1;
public:
	Obstacle() = default;
	Obstacle(Pos a);
	Obstacle(Pos a, bool directiont);
	~Obstacle() {};
	void move();
	virtual void unshow() {};
	virtual void midair() {};
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
public:
	CVEHICLE() = default;
	virtual void unshow() {};
	virtual void show() {};
	CVEHICLE(Pos a, bool directiont);
};

class CANIMAL : public Obstacle
{
};

class CTRUCK : public CVEHICLE
{ 
public:
	CTRUCK(Pos a, bool directiont);
	void show();
	void unshow();
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
