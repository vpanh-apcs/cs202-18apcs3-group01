#include "CGame.h"

CGAME::CGAME()
{	
};
 
void CGAME::init()
{
	GameSetting a;
	height = a.getGameHeight();
	width = a.getGameWidth();
	people = CPEOPLE(Pos(0, 0));
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			map[i][j] = 0;
	int direction = 0;
	int queue = 0;
	for (int i = 0; i < height; i++)
	{
		if (queue == 0)
		{
			routes[i] = new LeDuong(i,width);
			routes[i]->init();
			direction = Random(0, 1);
			queue = Random(1, 3);
		}
		else
		{
			queue--;
			routes[i] = new Duong(i,width,direction);
			routes[i]->init();
		}
	}
	GotoXY(0, 0);
}

void CGAME::drawGame()
{
	
}

void CGAME::displaySFML() 
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	while (window.isOpen()) 
	{
		
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::EventType::Closed) window.close();
			if (event.type == sf::Event::KeyPressed) 
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::P: pauseGame(); break;
				case sf::Keyboard::Key::A: 
				case sf::Keyboard::Key::S: 
				case sf::Keyboard::Key::W: 
				case sf::Keyboard::Key::D:
					people.move(event.key.code, map);
					if (!map[people.getPos().x][people.getPos().y] == 4)
					{
						stop = true;
						deadGame();
					}
					break;
				}
			}
		}
		drawGame();
		window.clear();
		for (int i = 0; i < height; i++)
		{
			sf::Texture lane;
			sf::RectangleShape rLane(sf::Vector2f(16 * width, 16));
			int typeLane = routes[i]->getType();
			bool direction = 0;
			if (typeLane == 1) lane.loadFromFile("image/grass.png");
			else {
				lane.loadFromFile("image/road.png");
				direction = routes[i]->getDirection();
			}
			lane.setRepeated(true);
			rLane.setTexture(&lane);
			rLane.setPosition(0, i * 32);
			rLane.setScale(2.0f, 2.0f);
			window.draw(rLane);
			for (int j = 0; j < width; j++) {
				if (map[i][j] == 0) continue;
				sf::Texture texture;
				switch (map[i][j]) {
				case 1: texture.loadFromFile("image/player_front.png"); break;
				case 3: texture.loadFromFile("image/tree.png"); break;
				case 4:
					if (!direction) texture.loadFromFile("image/player_right.png");
					else texture.loadFromFile("image/player_left.png");
					break;
				}
				sf::RectangleShape rect(sf::Vector2f(texture.getSize().x, texture.getSize().y));
				rect.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
				rect.setScale(2.0f, 2.0f);
				rect.setTexture(&texture);
				rect.setOrigin(texture.getSize().x * 0.5f, texture.getSize().y);
				rect.setPosition(j * 32 + 16, i * 32 + 32);
				window.draw(rect);
			}
		}
		window.display();
	}
}

void CGAME::routesMove()
{	
	for (int i = 0; i < height; i++)
		routes[i]->updateMap(map);
	while (!stop)
	{
		while (pause) {}
		for (int i = 0; i < height; i++)
		{
			routes[i]->move();
			routes[i]->updateMap(map);
		}	
		Sleep(200);
	}

};

void CGAME::pauseGame()
{
	pause = true;
	//menu pause game;
	Sleep(5000);
	pause = false;
}

void CGAME::deadGame()
{
	stop = true;
}

void CGAME::startGame()
{
	stop = false;
	pause = false;
	thread trdRoutes(&CGAME::routesMove, this);
	thread displayWinForm(&CGAME::displaySFML, this);
	displayWinForm.join();
	trdRoutes.join();
}

void CGAME::saveGame()
{
	ofstream file;
	time_t init = time(0);
	struct tm currentTime;
	localtime_s(&currentTime, &init);
	string path = "temp.txt";
	file.open(path, ios::out|ios::app);
	char str[26];
	asctime_s(str, sizeof str, &currentTime);
	file << str;
	people.save(file);
	file << width << " " << height << endl;
	for (int i = 0; i < height; i++)
		routes[i]->save(file);
	file.close();
}

void CGAME::loadGame()
{
	int inttemp;
	ifstream file;
	string temp;
	string path = "temp.txt";
	file.open(path);
	getline(file, temp, '\n');
	people.load(file);
	file >> width >> height;
	for (int i = 0; i < height; i++)
	{
		file >> inttemp;
		if (inttemp == 0)
			routes[i] = new LeDuong(i,width);
		else
			routes[i] = new Duong(i,width,0);
		routes[i]->load(file);
	}
	file.close();
}


