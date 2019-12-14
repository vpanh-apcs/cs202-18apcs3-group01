#include "GameSetting.h"


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
	virtual void save(ofstream& file) ;
	virtual void load(ifstream& file) ;
	virtual Pos getPos();
};

class TREE : public Obstacle
{
public:
	TREE() = default;
	TREE(Pos positiont) : Obstacle(positiont) {};
	void save(ofstream& file);
	void load(ifstream& file);
};

class CVEHICLE : public Obstacle
{
public:
	CVEHICLE() = default;
	//virtual void unshow() {};
	virtual void save(ofstream& file) {};
	virtual void load(ifstream& file) {};
	CVEHICLE(Pos a, bool directiont);
};

class CANIMAL : public Obstacle
{
public:
	CANIMAL() = default;
	CANIMAL(Pos a, bool directiont);
	//virtual void unshow() {};
	virtual void save(ofstream& file) {};
	virtual void load(ifstream& file) {};
	virtual void tell() {};
};

class CTRUCK : public CVEHICLE
{ 
public:
	CTRUCK(Pos a, bool directiont);
	void save(ofstream& file);
	void load(ifstream& file);
	//void unshow();
};

class CCAR : public CVEHICLE
{
public:
	CCAR(Pos a, bool directiont);
	void save(ofstream& file);
	void load(ifstream& file);
	//void unshow();
};

class CBIRD : public CANIMAL
{
public:
	CBIRD(Pos a, bool directiont);
	void save(ofstream& file);
	void load(ifstream& file);
};

class CDINOSAUR :public CANIMAL
{
public:
	CDINOSAUR(Pos a, bool directiont);
	void save(ofstream& file);
	void load(ifstream& file);
};
