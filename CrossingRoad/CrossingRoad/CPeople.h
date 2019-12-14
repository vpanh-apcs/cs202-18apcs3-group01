#include "ObstacleFactory.h"

class CPEOPLE
{
	string name;
	Pos position;
	int score;
	void Up();
	void Down();
	void Left();
	void Right();
	void unshow();
public:
	CPEOPLE(Pos t);
	void show();
	void showinfo();
	void updateMap(int map[20][20]);
	void move(char key,int map[20][20]);
	Pos getPos();
	string getName();
	void setName(string s);
	int getScore();
	void setScore(int scr);
	void save(ofstream& file);
	void load(ifstream &file);
};
