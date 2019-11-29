#include "Obstacle.h"

class CPEOPLE
{
	string name;
	Pos position;
	int attempt;
	int highscore;
	int moves;
public:
	void show();
	void showinfo() {};
	CPEOPLE() {};
	void GetInfo() {};
	void move(int Direction) {};
	Pos getPos() {};
	void hit() {};
	void save(ostream file) {};
	void load(ostream file) {};
};
