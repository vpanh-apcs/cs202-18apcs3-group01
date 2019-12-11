#include "CPeople.h"
CPEOPLE::CPEOPLE(Pos t)
{
	name = "player";
	position = t;
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

void CPEOPLE::show()
{
	GotoXY(position.y, position.x);
	cout << "P";
	GotoXY(position.y, position.x);
}

void CPEOPLE::unshow()
{
	GotoXY(position.y, position.x);
	cout << " ";
}

void CPEOPLE::Up()
{
	position.x -= 1;
}
void CPEOPLE::Down()
{
	position.x += 1;
}
void CPEOPLE::Left()
{
	position.y -= 1;
}
void CPEOPLE::Right()
{
	position.y += 1;
}

Pos CPEOPLE::getPos()
{
	return position;
}
void CPEOPLE::move(char key)
{
	switch (key)
	{
	case 'W': case 'w': unshow(); Up(); break;
	case 'A': case 'a': unshow(); Left(); break;
	case 'S': case 's': unshow(); Down(); break;
	case 'D': case 'd': unshow(); Right(); break;
	}
}
void CPEOPLE::save(ofstream& file)
{
	file << name << endl;
	file << position.x << " " << position.y << endl;
	file << highscore << endl;
}
void CPEOPLE::load(ifstream &file)
{
	file >> name;
	file >> position.x >> position.y;
	file >> highscore;
}