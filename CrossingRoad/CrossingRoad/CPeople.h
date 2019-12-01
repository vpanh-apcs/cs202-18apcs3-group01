#include "Obstacle.h"
class CPEOPLE
{
	string name;
	Pos position;
	int highscore;
	bool deadstate;
public:
	CPEOPLE();
	void Up();
	void Down();
	void Left();
	void Right();
	void showinfo();
	void move(char key);
	Pos getPos();
	bool blocked(Obstacle* a);
	bool hit(Obstacle* a);
	void save(ofstream &file);
	void load(ifstream &file);
};
