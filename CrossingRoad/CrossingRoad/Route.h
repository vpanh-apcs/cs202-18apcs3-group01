#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	bool direction = 0;
	Pos start, end;
	int queue = 3;
public:
	void updateMap(int map[11][11]) {};
	virtual void draw() = 0;
	virtual void move() = 0;
};

class LeDuong : public Route
{
	vector<TREE*> trees;
	TrafficLight trafficlight;
public:
	LeDuong(Pos startt, Pos endt);
	void draw();
	void move() {};
};

class Duong : public Route
{
	vector<Obstacle*> obstacles;
public:
	Duong(Pos startt, Pos endt);
	void move();
	void draw();
};


