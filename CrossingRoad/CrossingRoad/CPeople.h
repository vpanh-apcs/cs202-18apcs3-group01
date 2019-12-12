#include "Obstacle.h"


class CPEOPLE
{
	string name;
	Pos position;
	int highscore;
	bool deadstate;
	void Up();
	void Down();
	void Left();
	void Right();
	void unshow();
public:
	CPEOPLE(Pos t);
	void show();
	void showinfo();
	void move(char key);
	Pos getPos();
	void save(ofstream &file);
	void load(ifstream &file);
};
