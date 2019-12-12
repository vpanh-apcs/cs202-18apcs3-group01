#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	bool direction = 0;
	int index, length;
	friend class CGAME;
public:
	virtual void updateMap(int map[20][20]) = 0;
	virtual void move() {};
	virtual void draw() {};
	virtual int getType() = 0;
};

class LeDuong : public Route
{
	vector<TREE*> trees;
	TrafficLight trafficlight;
public:
	LeDuong(int indext, int lengtht);
	void updateMap(int map[20][20]);
	void draw();
	int getType() { return 1; }
};

class Duong : public Route
{
	vector<Obstacle*> obstacles;
public:
	Duong(int indext, int lengtht, bool directiont);
	void updateMap(int map[20][20]);
	void move();
	void draw();
	int getType() { return 2; }
};


