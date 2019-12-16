#include "CPeople.h"
class TrafficLight : TREE
{
	bool signal = false;
	int queue;
	int rate;
public:
	TrafficLight() = default;
	TrafficLight(Pos x, int y) : TREE(x), rate(y) { queue = Random(0, rate); };
	void save(ofstream& file)
	{
		file << position.x << " " << position.y << " " << signal << " " << rate << endl;
	}
	void changeSignal()
	{
		signal = !signal;
	}
	void adjustSignal()
	{
		if (queue == 0)
		{
			queue = rate;
			changeSignal();
		}
		if (queue > 0) queue--;
		else queue = 4;
	}
	bool getSignal()
	{
		return signal;
	}
	Pos getPos()
	{
		return Obstacle::getPos();
	}
	void move()
	{
		Obstacle::move();
	}
};
