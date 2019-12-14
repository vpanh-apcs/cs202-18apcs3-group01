#include "CPeople.h"
class TrafficLight : TREE
{
	bool signal = false;
	int rate;
public:
	TrafficLight() = default;
	TrafficLight(Pos x, int y) : TREE(x), rate(y) {};
	void changeSignal()
	{
		signal = !signal;
	}
	void adjustSignal()
	{
		if (rate == 0)
			changeSignal();
		if (rate > 0) rate--;
		else rate = 4;
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
