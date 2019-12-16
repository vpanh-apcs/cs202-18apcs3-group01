#include "Startup.h"

Startup::Startup()
{
	FixConsoleWindow();
	//Startup::mainMenu();
	sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	window.setMouseCursorVisible(false);
	Menu mainMenu = Menu(640, 640, { "New Game","Load Game","high Scores","Settings","Quit" });
	sf::Texture background;

	background.loadFromFile("image/background.png");
	sf::RectangleShape bg;
	sf::Vector2f bgs;
	bgs.x = background.getSize().x;
	bgs.y = background.getSize().y;

	bg.setSize(bgs);
	bg.setOrigin(bgs.x * 0.5f, bgs.y * 0.5f);
	bg.setTextureRect(sf::IntRect(0, 0, bgs.x, bgs.y));
	bg.setTexture(&background);
	bg.setPosition(window.getSize().x * 0.5f, window.getSize().y * 0.5f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed &&
				event.key.code == sf::Keyboard::Key::Enter)
			{
				switch (mainMenu.GetPressedItem())
				{
				case 0: // New Game
				{
					CGAME a;
					a.init();
					a.startGame();
				}
					//window.close();
					break;
				case 1: // Load Game
				{
					CGAME a = LoadGame();
					a.startGame();
				}
					break;
				case 2: // High Scores
					break;
				case 3: // Settings
					break;
				case 4: // Quit
					window.close();
					break;
				}
			}
			mainMenu.moveMenu(event);
		}
		window.clear();
		window.draw(bg);
		mainMenu.draw(window);
		window.display();
	}
}

CGAME Startup::LoadGame()
{
	string temp;
	ifstream file;
	vector<string> tempvector;
	vector<string> paths;
	file.open("SavedGames.txt");
	while (!file.eof())
	{
		getline(file, temp, '\n');
		tempvector.push_back(temp);
		getline(file, temp, '\n');
		paths.push_back(temp);
	}
	Menu loadMenu = Menu(640, 640, tempvector);
	sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	window.setMouseCursorVisible(false);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed &&
				event.key.code == sf::Keyboard::Key::Enter)
			{
				CGAME a;
				a.loadGame(paths[loadMenu.GetPressedItem()]);
				window.close();
				return a;
			}
			loadMenu.moveMenu(event);
		}
		window.clear();
		loadMenu.draw(window);
		window.display();
	}
	file.close();
}