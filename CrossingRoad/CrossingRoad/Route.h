#include "TrafficLight.h"

class Route
{
protected:
	int index, length;
	friend class CGAME;
public:
	//virtual void init(int indext, int lengtht) {};
	//virtual void init(int indext, int lengtht, bool direction) {};
	virtual bool getSignal() { return false; };
	virtual void init(int level) {};
	virtual void updateMap(int map[][20]) = 0;
	virtual void move(int level) {};
	virtual void save(ofstream& file) = 0;
	virtual void load(ifstream& file) = 0;
	virtual int getType() = 0;
	virtual bool getDirection() { return false; }
	virtual ~Route() {};
};

class LeDuong : public Route
{
	int queue = Random(1, 5);
	vector<TREE*> trees;
	TrafficLight trafficlight;
	bool TF = false;
public:
	LeDuong(int indext, int lengtht);
	void init(int level);
	void updateMap(int map[10][20]);
	void save(ofstream& file);
	void load(ifstream& file);
	int getType() { return 1; }
	void move(int level)
	{ 
		if (TF) trafficlight.adjustSignal(); 
	};
	bool getSignal() 
	{ 
		if (TF) return trafficlight.getSignal();
		return false;
	};
	~LeDuong();
};

class Duong : public Route
{
	int queue = Random(1,10);
	bool direction = 0;
	vector<Obstacle*> obstacles;
public:
	Duong(int indext, int lengtht, bool direction);
	bool getDirection() { return direction; }
	void init(int level);
	void move(int level);
	void updateMap(int map[10][20]);
	void save(ofstream& file);
	void load(ifstream& file);
	int getType() { return 2; }
	~Duong();
};


