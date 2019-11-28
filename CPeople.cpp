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
	cout <<"Name : "<< name;
	GotoXY(x, x - 1);
	cout << "Location : " << position.x << "--" << position.y;
	GotoXY(x, x + 1);
	cout <<"Score : "<< highscore;
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
void CPEOPLE::move(char key, const vector<bool>& block)
{
	if ((key == 'W' || key == 'w') && block[0] == false)
		Up();
	else if ((key == 'S' || key == 's') && block[1]==false)
		Down();
	else if ((key == 'A' || key == 'a' )&& block[2]==false)
		Left();
	else if ((key == 'D' || key == 'd') && block[3] == false)
		Right();
}
bool CPEOPLE::blocked(Obstacle* a)
{
	if (position == a->getPos())
		return true;
	return false;
}
vector<bool> CPEOPLE::blockedDirection(const vector<Obstacle*>& a) //list cac cay
{
	vector<bool> block{ false,false,false,false }; //  [0] Up , [1] Down , [2] Left, [3] Right
	for (int i = 0; i < a.size(); i++)
	{
		if (position.x == a[i]->getPos().x && position.y == a[i]->getPos().y - 1) //blocked when Up
			block[0]=true;
		if (position.x == a[i]->getPos().x && position.y == a[i]->getPos().y + 1)//blocked when Down
			block[1]=true;
		if (position.y == a[i]->getPos().y && position.x == a[i]->getPos().x + 1)//blocked when Left
			block[2] = true;
		if (position.y == a[i]->getPos().y && position.x == a[i]->getPos().x - 1)//blocked when Right
			block[3] = true;
	}
	return block;
}
bool CPEOPLE::hit(Obstacle* a)
{
	if (position == a->getPos())
		return true;
	return false;
}
bool CPEOPLE::hit(const vector<Obstacle*>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->getPos() == position)
			return true;
	}
	return false;
}
void CPEOPLE::save(ofstream &file)
{
	file.open("\\CPEOPLE\\"+name+".txt");
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