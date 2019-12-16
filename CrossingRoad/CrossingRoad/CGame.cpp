#include "CGame.h"

CGAME::CGAME()
{	
};
 
void CGAME::init()
{
	GameSetting a;
	height = a.getGameHeight();
	width = a.getGameWidth();
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			map[i][j] = 0;
	routes[0] = new LeDuong(0, width);
	int direction = Random(0, 1);
	int queue = Random(2, 3);
	for (int i = 1; i < height; i++)
	{
		if (queue == 0)
		{
			routes[i] = new LeDuong(i,width);
			routes[i]->init(level);
			direction = Random(0, 1);
			queue = Random(2, 3);
		}
		else
		{
			queue--;
			routes[i] = new Duong(i,width,direction);
			routes[i]->init(level);
		}
	}
	GotoXY(0, 0);
}

void CGAME::displaySFML() 
{
	sf::Texture player;
	player.loadFromFile("image/player_front.png");
	sf::RectangleShape rectPlayer(sf::Vector2f(player.getSize().x, player.getSize().y));
	rectPlayer.setTextureRect(sf::IntRect(0, 0, player.getSize().x, player.getSize().y));
	rectPlayer.setScale(2.0f, 2.0f);
	rectPlayer.setTexture(&player);
	rectPlayer.setOrigin(player.getSize().x * 0.5f, player.getSize().y);
	sf::RenderWindow window(sf::VideoMode(800, 640), "Crossing Road");
	while (window.isOpen()) 
	{
		//updateLevel();
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
				stop = true;
			}
			if (event.type == sf::Event::KeyPressed) 
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::P: pauseGame(); break;
				case sf::Keyboard::Key::A: people.move('A', map); break;
				case sf::Keyboard::Key::S:
					people.setScore(level);
					if (people.getPos().x == 19)
					{
						nextLevel();
					}
					else
						people.move('S', map); 
					break;
				case sf::Keyboard::Key::W: people.move('W', map); break;
				case sf::Keyboard::Key::D: people.move('D', map); break;
				}
					/*people.move(char(event.key.code), map);
					people.show();*/
				/*GotoXY(10, 10);
				cout << people.getPos().x;*/
				people.setScore(level);
				//sf::Font font;
				//sf::String name(people.getName());

				//name.setPosition(60, 10);
				
				
				
				//break;
				
			
				//while (event.type != sf::Event::KeyReleased) {};
			}
		}
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
		rectPlayer.setPosition(people.getPos().y * 32 + 16, people.getPos().x * 32 + 32);
		window.draw(rectPlayer);
		window.display();
	}
}

void CGAME::routesMove()
{	
	for (int i = 0; i < height; i++)
		routes[i]->updateMap(map);
	bool signal = false;
	while (!stop)
	{
		while (pause) {}
		for (int i = 0; i < height; i++)
		{
			if ((routes[i]->getType() == 1) || (routes[i]->getType() == 2) && (signal == false))
			{
				routes[i]->move(level);
				signal = routes[i]->getSignal();
			}
			routes[i]->updateMap(map);
		}	
		if (map[people.getPos().x][people.getPos().y] >= 4)
		{
			//deadGame();
		}
		//570-level*70<0 ? Sleep(1) : Sleep(570-level*70);
		(7 - level) * 101 <= 0 ?   Sleep(101):Sleep((7 - level ) * 101);
	}
};

void CGAME::nextLevel()
{
	//GotoXY(5, 1);
	//cout << "Pass"<<endl;
	/*GotoXY(10, 0);
	cout << level << "  speed : "<< (7 - level) * 101 <<endl;*/
	people.showinfo();
	map[people.getPos().x][people.getPos().y] = 0;
	people.setPos(Pos(0, people.getPos().y));
	for (size_t i = 0; i < 20; i++)
	{
		routes[i]->~Route();
	}
	level++;
	//Sleep(500);
	init();
	people.updateMap(map);
	
	//displaySFML();

	/*GotoXY(10, 2);
	cout << level << "  speed : " << (7 - level) * 101 << endl;*/
}

void CGAME::pauseGame()
{
	pause = true;
	//menu pause game;
	//Sleep(5000);
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
	people.updateMap(map);
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


void CGAME::test()
{

}