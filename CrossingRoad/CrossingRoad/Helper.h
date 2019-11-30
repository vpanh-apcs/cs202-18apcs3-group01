#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<thread>
#include<vector>
#include<fstream>
#include<stdio.h>
using namespace std;

const int size = 4;
const int with = 0;
const int height = 0;

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
