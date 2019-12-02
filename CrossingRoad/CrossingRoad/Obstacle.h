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
	virtual ~Obstacle() {};
	virtual void move();
	virtual void unshow() {};
	//virtual void midair() {};
	virtual void show() {};
	virtual void save(ofstream& file) ;
	virtual void load(ifstream& file) ;
	virtual Pos getPos();
	virtual Pos MoveOnMap(Pos p);
};

class TREE : public Obstacle
{
public:
	TREE(Pos positiont);
	void show();
	void save(ofstream& file);
	void load(ifstream& file);
};

class CVEHICLE : public Obstacle
{
public:
	CVEHICLE() = default;
	//virtual void unshow() {};
	virtual void show() {};
	virtual void save(ofstream& file);
	virtual void load(ifstream& file);
	CVEHICLE(Pos a, bool directiont);
};

class CANIMAL : public Obstacle
{
	CANIMAL() = default;
	CANIMAL(Pos a, bool directiont);
	//virtual void unshow() {};
	virtual void show() {};
	virtual void save(ofstream& file);
	virtual void load(ifstream& file);
	virtual void tell() {};
};

class CTRUCK : public CVEHICLE
{ 
public:
	CTRUCK(Pos a, bool directiont);
	void show();
	void save(ofstream& file);
	void load(ifstream& file);
	//void unshow();
};

class CCAR : public CVEHICLE
{
public:
	CCAR(Pos a, bool directiont);
	void show();
	void save(ofstream& file);
	void load(ifstream& file);
	//void unshow();
};

class CBIRD : public CANIMAL
{
public:
	CBIRD(Pos a, bool directiont);
	void show();
	void save(ofstream& file);
	void load(ifstream& file);

};

class CDINOSAUR :public CANIMAL
{
public:
	CDINOSAUR(Pos a, bool directiont);
	void show();
	void save(ofstream& file);
	void load(ifstream& file);
};
