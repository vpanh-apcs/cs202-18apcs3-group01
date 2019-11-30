#include "CPeople.h"
CPEOPLE::CPEOPLE()
{
	name = "player";
	position = Pos(0, 0);
	highscore = 0;
	deadstate = false;
}
void CPEOPLE::showinfo()
{
	int x = 35;
	DrawBoard(30, 30, 40, 20);
	GotoXY(x, x - 3);
	cout << "Name : " << name;
	GotoXY(x, x - 1);
	cout << "Location : " << position.x << "--" << position.y;
	GotoXY(x, x + 1);
	cout << "Score : " << highscore;
}
void CPEOPLE::Up()
{
	position.y += 1;
}
void CPEOPLE::Down()
{
	position.y -= 1;
}
void CPEOPLE::Left()
{
	position.x -= 1;
}
void CPEOPLE::Right()
{
	position.x += 1;
}

Pos CPEOPLE::getPos()
{
	return position;
}
void CPEOPLE::move(char key)
{
	while (deadstate)
	{
		if (key == 'W' || key == 'w')
			Up();
		else if (key == 'S' || key == 's')
			Down();
		else if (key == 'A' || key == 'a')
			Left();
		else if (key == 'D' || key == 'd')
			Right();
	}
}
bool CPEOPLE::blocked(Obstacle* a)
{
	if (position == a->getPos())
		return true;
	return false;
}
bool CPEOPLE::hit(Obstacle* a)
{
	if (position == a->getPos())
		return true;
	return false;
}
void CPEOPLE::save(ofstream &file)
{
	file.open( name + ".txt");
	if (file.fail())
		return;
	file << name << endl;
	file << position.x << " " << position.y << endl;
	file << highscore << endl;
	file << deadstate << endl;
	file.close();
}
void CPEOPLE::load(ifstream &file)
{
	file.open(name + "txt");
	if (file.fail())
		return;
	while (!file.eof())
	{
		file >> name;
		file >> position.x >> position.y;
		file >> highscore;
		file >> deadstate;
	}
	file.close();
}