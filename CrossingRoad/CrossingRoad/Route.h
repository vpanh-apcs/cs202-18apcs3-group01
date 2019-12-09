#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	bool direction = 0;
	int index, length;
public:
	virtual void updateMap(int map[10][20]) = 0;
	virtual void move() {};
	virtual void draw() {};
};

class LeDuong : public Route
{
	vector<TREE*> trees;
	TrafficLight trafficlight;
public:
	LeDuong(int indext, int lengtht);
	void updateMap(int map[10][20]);
	void draw();
};

class Duong : public Route
{
	vector<Obstacle*> obstacles;
public:
	Duong(int indext, int lengtht, bool directiont);
	void updateMap(int map[10][20]);
	void move();
	void draw();
};


