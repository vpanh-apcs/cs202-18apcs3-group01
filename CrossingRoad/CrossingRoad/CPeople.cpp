#include "CPeople.h"
GameSetting game;
CPEOPLE::CPEOPLE(Pos t)
{
	name = "player";
	position = t;
	score = 0;
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
	cout << "Score : " << score;
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

string CPEOPLE::getName()
{
	return name;
}
void CPEOPLE::setName(string s)
{
	name = s;
}
int CPEOPLE::getScore()
{
	return score;
}
void CPEOPLE::setScore(int scr)
{
	score = scr;
}
void CPEOPLE::move(char key, int map[20][20])
{
	map[position.x][position.y] = 0;
	Pos lstPos = position;
	switch (key)
	{
	case 'W':  unshow(); Up(); break;
	case 'A':  unshow(); Left(); break;
	case 'S':  unshow(); Down(); break;
	case 'D':  unshow(); Right(); break;
	}
	/*show();
	GotoXY(40, 2);
	cout << lstPos.x << " " << lstPos.y;
	GotoXY(40, 4);
	cout << position.x << " " << position.y;*/
	if (position.x < 0 || position.x >=game.getGameHeight() || position.y < 0 || position.y>=game.getGameWidth() || map[position.x][position.y] == 3)
		position = lstPos;
}

void CPEOPLE::updateMap(int map[20][20])
{
	map[position.x][position.y] = 1;
}

void CPEOPLE::save(ofstream& file)
{
	file << name << endl;
	file << position.x << " " << position.y << endl;
	file << score << endl;
}
void CPEOPLE::load(ifstream &file)
{
	file >> name;
	file >> position.x >> position.y;
	file >> score;
}