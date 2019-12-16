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
	int x = 10;
	int y = 1;
	DrawBoard(x, y, 40, 20);
	GotoXY(x+1, y + 3);
	cout << "Name : " << name;
	GotoXY(x+1, y + 6);
	cout << "Score : " << score;
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

void CPEOPLE::setPos(Pos p)
{
	position = p;
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
void CPEOPLE::setScore(int level)
{
	int temp = (position.x + (level-1) * 19) * level * 100;
	//GotoXY(4, 2);
	//cout << level;
	//GotoXY(4, 4);
	//cout << score;
	//GotoXY(4, 6);
	//cout << temp;
	if (temp > score)
		score = temp;
}
void CPEOPLE::move(char key, int map[20][20])
{
	map[position.x][position.y] = 0;
	Pos lstPos = position;
	switch (key)
	{
	case 'W':  Up(); break;
	case 'A':  Left(); break;
	case 'S':  Down(); break;
	case 'D':  Right(); break;
	}
	//show();
	/*GotoXY(20, 2);
	cout << lstPos.x << " " << lstPos.y;
	GotoXY(20, 4);
	cout << position.x << " " << position.y;*/
	if (position.x < 0 || position.x >=game.getGameHeight() || position.y < 0 || position.y>=game.getGameWidth() || map[position.x][position.y] == 3 || map[position.x][position.y] == 4)
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
void CPEOPLE::display(sf::RenderWindow& window)
{
	sf::Vector2f wSize(window.getSize());

	sf::Text pName;
	sf::Text Score;
	sf::Font font;

	font.loadFromFile("futur.ttf");
	pName.setFont(font);
	pName.setScale(0.5, 0.5);
	pName.setFillColor(sf::Color::White);

	Score.setFont(font);
	Score.setScale(0.5, 0.5);
	Score.setFillColor(sf::Color::White);

	Score.setString("Score: " + to_string(score));
	pName.setString(name);

	pName.setPosition(160.f / 3 + 640, wSize.y * 0.5f - 250);
	Score.setPosition(160.f / 3 + 640, wSize.y * 0.5f - 200);
	window.draw(pName);
	window.draw(Score);
}