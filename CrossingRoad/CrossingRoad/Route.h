#include "CPeople.h"
#include "TrafficLight.h"

class Route
{
protected:
	int index, length;
	friend class CGAME;
public:
	//virtual void init(int indext, int lengtht) {};
	//virtual void init(int indext, int lengtht, bool direction) {};
	virtual void init() = 0;
	virtual void updateMap(int map[][20]) = 0;
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
	void init();
	void updateMap(int map[][20]);
	void draw();
	void save(ofstream& file);
	void load(ifstream& file);
	int getType() { return 1; }
};

class Duong : public Route
{
	bool direction = 0;
	vector<Obstacle*> obstacles;
public:
	Duong(int indext, int lengtht, bool direction);
	void init();
	void move();
	void updateMap(int map[][20]);
	void save(ofstream& file);
	void load(ifstream& file);
	int getType() { return 2; }
};


