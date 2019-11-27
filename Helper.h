#pragma once //update by Phun
#include<iostream>
#include <windows.h>
#include<string>
#include<thread>
#include<vector>
#include <fstream> // update by Phun
#include <conio.h> //update by Phun
using namespace std;


//CONST int size = 4;
//CONST int with = 0;
//CONST int height = 0;
struct Pos
{
	int x;
	int y;
	Pos();
	Pos(int xt, int yt);
};
int Random(int start, int end);

void GotoXY(int x, int y);
void GotoXY(Pos p);
void FixConsoleWindow();


void DrawBoard(int x, int y, int width, int height);

//class Button
//{
//};
//
//class BoxList
//{
//	vector<Button> a;
//};
