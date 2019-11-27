#include<iostream>
#include <windows.h>
#include<string>
#include<thread>
#include<vector>
using namespace std;


//CONST int size = 4;
//CONST int with = 0;
//CONST int height = 0;

int Random(int start, int end);

void GotoXY(int x, int y);
void FixConsoleWindow();

struct Pos
{
	int x;
	int y;
	Pos();
	Pos(int xt,int yt);
};



//class Button
//{
//};
//
//class BoxList
//{
//	vector<Button> a;
//};
