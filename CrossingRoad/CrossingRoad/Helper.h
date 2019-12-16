#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<thread>
#include<vector>
#include<fstream>
#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <limits>
using namespace std;

const int unitsize = 4;

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

void DrawBoard(int x, int y, int width, int height);



//class Button
//{
//};
//
//class BoxList
//{
//	vector<Button> a;
//};
