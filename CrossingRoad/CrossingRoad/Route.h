#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	int index, length;
public:
	virtual void updateMap(int map[10][20]) = 0;
	virtual void move() {};
	virtual void draw() {};
	virtual void save(ofstream& file) = 0;
	virtual void load(ifstream& file) = 0;
};

class LeDuong : public Route
{
	vector<TREE*> trees;
	TrafficLight trafficlight;
public:
	LeDuong(int indext, int lengtht);
	void updateMap(int map[10][20]);
	void draw();
	void save(ofstream& file);
	void load(ifstream& file);
};

class Duong : public Route
{
	bool direction = 0;
	vector<Obstacle*> obstacles;
public:
	Duong(int indext, int lengtht, bool directiont);
	void updateMap(int map[10][20]);
	void move();
	void draw();
	void save(ofstream& file);
	void load(ifstream& file) {};
};


