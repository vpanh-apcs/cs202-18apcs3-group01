#include "Startup.h"

int main()
{
	//FixConsoleWindow();
	//Startup::mainMenu();
	//Startup game();
	/*CGAME a;
	a.init();
	a.startGame();*/
	//int temp = 0;
	//CGAME a;
	//FixConsoleWindow();
	////Startup::mainMenu();
	//sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	//window.setMouseCursorVisible(false);
	//sf::Texture background;

	//background.loadFromFile("image/background.png");
	//sf::RectangleShape bg;
	//sf::Vector2f bgs;
	//bgs.x = background.getSize().x;
	//bgs.y = background.getSize().y;

	//bg.setSize(bgs);
	//bg.setOrigin(bgs.x * 0.5f, bgs.y * 0.5f);
	//bg.setTextureRect(sf::IntRect(0, 0, bgs.x, bgs.y));
	//bg.setTexture(&background);
	//bg.setPosition(window.getSize().x * 0.5f, window.getSize().y * 0.5f);
	//
	//Menu mainMenu = Menu(640, 640, {"New Game","Load Game","high Scores","Settings","Quit"});
	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::EventType::KeyPressed &&
	//			event.key.code == sf::Keyboard::Key::Enter)
	//		{
	//			switch (mainMenu.GetPressedItem())
	//			{
	//			case 0: // New Game
	//				temp = 0;
	//				window.close();
	//				break;
	//			case 1: // Load Game
	//				temp = 1;
	//				window.close();
	//				break;
	//			case 2: // High Scores
	//				temp = 2;
	//				window.close();
	//				break;
	//			case 3: // Settings
	//				temp = 3;
	//				window.close();
	//				break;
	//			case 4: // Quit
	//				temp = 4;
	//				window.close();
	//				break;
	//			}
	//		}
	//		mainMenu.moveMenu(event);
	//	}
	//	window.clear();
	//	window.draw(bg);
	//	mainMenu.draw(window);
	//	window.display();
	//}
	//switch (temp)
	//{
	//case 0:
	//	a.init();
	//	a.startGame();
	//	break;
	//case 1:
	//	a.loadGame();
	//	a.startGame();
	//	break;
	//}
	Startup a;
	return 0;
}
