#include "ObstacleFactory.h"
class CPEOPLE
{
	string name;
	Pos position;
	int score;
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
	void move(char key,int map[20][20]);
	Pos getPos();
	bool getDead();
	void setDead(bool dead);
	string getName();
	void setName(string s);
	int getScore();
	void setScore(int scr);
	void save(ofstream& file);
	void load(ifstream &file);
};
