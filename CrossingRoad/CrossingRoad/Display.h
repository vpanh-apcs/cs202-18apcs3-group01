#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class Display
{
private:
	Display()
		: mWindow(sf::VideoMode(640, 640), "Crossing Road")

	{ 
	}
	static Display* sInstance;
	
public:
	sf::RenderWindow mWindow;
	static Display* getInstance() {
		if (sInstance == nullptr)
			return new Display();
		return sInstance;
	}



};

