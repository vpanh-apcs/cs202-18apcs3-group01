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
public:
	CPEOPLE(Pos t);
	void updateMap(int map[20][20]);
	void move(char key,int map[20][20]);
	Pos getPos();
	void setPos(Pos p);
	string getName();
	void setName(string s);
	int getScore();
	void setScore(int level);
	void save(ofstream& file);
	void load(ifstream &file);
	void display(sf::RenderWindow& window);
};
