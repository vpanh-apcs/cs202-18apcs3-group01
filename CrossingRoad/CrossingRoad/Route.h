#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	bool direction = 0;
	Pos start, end;
public:
	virtual void updateMap(int map[10][10]) = 0;
	virtual void draw() = 0;
	virtual void move() {};
};

class LeDuong : public Route
{
	vector<TREE*> trees;
	TrafficLight trafficlight;
public:
	LeDuong(Pos startt, Pos endt);
	void updateMap(int map[10][10]);
	void draw();
};

class Duong : public Route
{
	vector<Obstacle*> obstacles;
public:
	Duong(Pos startt, Pos endt, bool directiont);
	void updateMap(int map[10][10]);
	void move();
	void draw();
};


