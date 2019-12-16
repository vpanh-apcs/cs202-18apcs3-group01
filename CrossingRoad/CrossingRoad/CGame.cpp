#include "CGame.h"

void CGAME::saveGame()
{
	
	time_t init = time(0);
	struct tm currentTime;
	localtime_s(&currentTime, &init);
	char str[26];
	asctime_s(str, sizeof str, &currentTime);
	string info = string(str);
	info.erase(info.end() - 1);
	info = people.getName() + " " + to_string(people.getScore()) + " " + to_string(level) + " " + info;
	string path = people.getName() + to_string(people.getScore()) + to_string(level) +
		to_string(currentTime.tm_hour) + to_string(currentTime.tm_min) + to_string(currentTime.tm_sec) +
		to_string(currentTime.tm_mday) + to_string(currentTime.tm_mon) + to_string(currentTime.tm_year);
	
	ofstream file;
	file.open("SavedGames.txt", ios::out | ios::app);
	file << info << endl;
	file << path << endl;
	file.close();

	file.open(path + ".txt", ios::out | ios::app);
	file << str;
	people.save(file);
	file << width << " " << height << endl;
	file << level << endl;
	for (int i = 0; i < height; i++)
		routes[i]->save(file);
	file.close();
}
void CGAME::loadGame(string patht)
{
	int inttemp;
	ifstream file;
	string temp;
	string path = patht + ".txt";
	file.open(path);
	getline(file, temp, '\n');
	people.load(file);
	file >> width >> height;
	file >> level;
	for (int i = 0; i < height; i++)
	{
		file >> inttemp;
		if (inttemp == 0)
			routes[i] = new LeDuong(i, width);
		else
			routes[i] = new Duong(i, width, 0);
		routes[i]->load(file);
	}
	file.close();
}



CGAME::CGAME()
{
};

void CGAME::init()
{
	GameSetting a;
	loadHighscore();
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
			routes[i] = new LeDuong(i, width);
			routes[i]->init(level);
			direction = Random(0, 1);
			queue = Random(2, 3);
		}
		else
		{
			queue--;
			routes[i] = new Duong(i, width, direction);
			routes[i]->init(level);
		}
	}
	GotoXY(0, 0);
}

void CGAME::displaySFML()
{
	Menu pauseMenu = Menu(640, 640, { "Resume","Save Game", "Main Menu" });
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
			if (event.type == sf::Event::EventType::KeyPressed && pause)
			{
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					switch (pauseMenu.GetPressedItem())
					{
					case 0: pauseGame(); break;
					case 1: saveGame(); break;
					case 2: window.close(); stop = true; break;
					}
				}
				pauseMenu.moveMenu(event);
			}
			
			if ((event.type == sf::Event::KeyPressed) && (!stop) && (!pause))
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::P: pauseGame(); break;
				case sf::Keyboard::Key::A:
				case sf::Keyboard::Key::Left:
					people.move('A', map); break;
				case sf::Keyboard::Key::S:
				case sf::Keyboard::Key::Down:
					people.setScore(level); 
					people.showinfo();
					if (people.getPos().x == 19)
					{
						nextLevel();
						Sleep(200);
					}
					else
						people.move('S', map);
					break;
				case sf::Keyboard::Key::W: 
				case sf::Keyboard::Key::Up: 
					people.move('W', map); break;
				case sf::Keyboard::Key::D:
				case sf::Keyboard::Key::Right:
					people.move('D', map); break;
				}
				people.setScore(level);
				if (map[people.getPos().x][people.getPos().y] >= 4)
				{
					deadGame();
				}
			}
		}
		window.clear();
		for (int i = 0; i < height; i++)
		{
			sf::Texture lane;
			sf::RectangleShape rLane(sf::Vector2f(16 * width, 16));
			int typeLane = routes[i]->getType();
			bool direction = 0, signal = 0;
			if (typeLane == 1)
			{
				lane.loadFromFile("image/grass.png");
				signal = routes[i]->getSignal();
			}
			else {
				lane.loadFromFile("image/road.png");
				direction = routes[i]->getDirection();
			}
			sf::Vector2u blocksize;
			blocksize.x = lane.getSize().x;
			blocksize.y = lane.getSize().y;
			lane.setRepeated(true);
			rLane.setTextureRect(sf::IntRect(0, 0,blocksize.x*width,blocksize.y ));
			rLane.setTexture(&lane);
			rLane.setPosition(0, i * 32);
			rLane.setScale(2.0f, 2.0f);
			window.draw(rLane);
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 0) continue;
				sf::Texture texture;
				switch (map[i][j])
				{
				case 3: texture.loadFromFile("image/tree.png"); break;
				case 4:
					if (!signal) texture.loadFromFile("image/trafficlight_green.png");
					else texture.loadFromFile("image/trafficlight_red.png");
					break;
				case 5:
					if (!direction) texture.loadFromFile("image/bikeright.png");
					else texture.loadFromFile("image/bikeleft.png");
					break;
				case 6:
					if (!direction) texture.loadFromFile("image/carright.png");
					else texture.loadFromFile("image/carleft.png");
					break;
				case 7:
					if (!direction) texture.loadFromFile("image/birdright.png");
					else texture.loadFromFile("image/birdleft.png");
					break;
				case 8:
					if (!direction) texture.loadFromFile("image/horseright.png");
					else texture.loadFromFile("image/horseleft.png");
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
		if (stop == true) displayHighscore(window);
		infoDisplay(window);
		rectPlayer.setPosition(people.getPos().y * 32 + 16, people.getPos().x * 32 + 32);
		window.draw(rectPlayer);
		if (pause) pauseMenu.draw(window);
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
		while ((pause)&&(!stop)) {}
		for (int i = 0; i < height; i++)
		{
			if (routes[i]->getType() == 1)
			{
				signal = routes[i]->getSignal();
				routes[i]->move(level);
			}
			else
				if (signal == false)
					routes[i]->move(level);
			routes[i]->updateMap(map);
		}
		if (map[people.getPos().x][people.getPos().y] >= 4)
		{
			deadGame();
		}
		//570-level*70<0 ? Sleep(1) : Sleep(570-level*70);

		(7 - level) * 101 <= 0 ? Sleep(101) : Sleep((7 - level) * 101);
	}
};

void CGAME::nextLevel()
{
	//GotoXY(5, 1);
	//cout << "Pass"<<endl;
	/*GotoXY(10, 0);
	cout << level << "  speed : "<< (7 - level) * 101 <<endl;*/
	//people.showinfo();
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
	pause = !pause;
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

//highscore

void CGAME::saveHighscore()
{
	ofstream fout;
	fout.open("highscore.txt");
	for (size_t i = 0; i < 5; i++)
	{
		fout << highScore[i] << endl;
	}
	fout.close();
}
void CGAME::loadHighscore()
{
	ifstream fin;
	fin.open("highscore.txt");
	int x;
	for (size_t i = 0; i < 5; i++)
	{
		fin >> x;
		highScore[i]=x;
	}
	fin.close();
}



int CGAME::topScore(int scr)
{
	if (scr > highScore[4])
	{
		if (highScore[0] <= scr)
		{
			highScore[0] = scr;
			return 1;
		}
		else
		{
			for (int i = 4; i >= 0; i--)
			{
				if (highScore[i] > scr)
				{
					highScore[i + 1] = scr;
					return i + 2;
				}
			}
		}
	}
	return NULL;
}

//--------------- display-----------------------------
void CGAME::infoDisplay(sf::RenderWindow& window)
{
	sf::Font font;
	sf::Text Level;
	font.loadFromFile("futur.ttf");
	Level.setString("LEVEL: " + to_string(level));
	Level.setFont(font);
	Level.setFillColor(sf::Color::White);
	Level.scale(0.75, 0.75);
	Level.setPosition(160.f / 3 + 640, window.getSize().y * 0.5f - 300);
	window.draw(Level);
	people.display(window);
}
void CGAME::displayHighscore(sf::RenderWindow& window)
{
	//vector<int> hs;
	float t = window.getSize().y * 0.5f - 200;
	//hs = loadHighscore();
	sf::Font font;
	sf::Text temp;
	font.loadFromFile("futur.ttf");
	temp.setString("HIGH SCORE");
	temp.setFont(font);
	temp.setFillColor(sf::Color::White);
	temp.scale(0.5, 0.5);
	temp.setPosition(160.f / 3 + 640, t + 100);
	window.draw(temp);
	int top = topScore(people.getScore());
	for (int i = 0; i < 5; i++)
	{
		font.loadFromFile("futur.ttf");
		temp.setString(to_string(highScore[i]));
		temp.setFont(font);
		temp.setFillColor(sf::Color::White);
		temp.setPosition(160.f / 3 + 640, t + (i + 3) * 50);
		window.draw(temp);
	}

	if (top != NULL)
	{
		if (top == 1)
			temp.setString("New highest score ");
		else
			temp.setString("You get top " + to_string(top));
		saveHighscore();
	}
	else
	{
		temp.setString("Try the next time");
	}

	temp.setPosition(160.f / 3 + 640 - 40, t + (5 + 3) * 50);
	window.draw(temp);
}
void CGAME::HighscoreBoard()
{
	loadHighscore();
	sf::RenderWindow window(sf::VideoMode(800, 640), "Crossing Road");
	sf::Font font;
	sf::Text temp;
	float t = window.getSize().y * 0.5f - 200;
	font.loadFromFile("futur.ttf");
	temp.setString("HIGH SCORE");
	temp.setFont(font);
	temp.setFillColor(sf::Color::White);
	temp.scale(0.5, 0.5);
	temp.setPosition(160.f / 3 + 300, t + 100);
	window.draw(temp);
	int top = topScore(people.getScore());
	for (int i = 0; i < 5; i++)
	{
		font.loadFromFile("futur.ttf");
		temp.setString(to_string(highScore[i]));
		temp.setFont(font);
		temp.setFillColor(sf::Color::White);
		temp.setPosition(160.f / 3 + 300, t + (i + 3) * 50);
		window.draw(temp);
	}
}
