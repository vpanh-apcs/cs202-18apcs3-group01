#include "Startup.h"
#include "Sound.h"

MusicPlayer* MusicPlayer::sInstance = MusicPlayer::getInstance();
SoundPlayerEffect* SoundPlayerEffect::sInstance = SoundPlayerEffect::getInstance();

Startup::Startup()
{
	FixConsoleWindow();
	//Startup::mainMenu();
	MusicPlayer::sInstance->play(Music::MissionTheme);
	sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	window.setMouseCursorVisible(false);
	Menu mainMenu = Menu(640, 640, { "New Game","Load Game","high Scores","Settings","Quit" });
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
					Settings();
					break;
				case 4: // Quit
					window.close();
					break;
				}
			}
			mainMenu.moveMenu(event);
		}
		window.clear();
		mainMenu.draw(window);
		window.display();
	}
}

CGAME Startup::LoadGame()
{
	string temp;
	ifstream file;
	vector<string> tempvector;
	file.open("SavedGames.txt");
	while (!file.eof())
	{
		getline(file, temp, '\n');
		tempvector.push_back(temp);
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
				a.loadGame(tempvector[loadMenu.GetPressedItem()]);
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

void Startup::Settings()
{
	vector<string> mChildren = {"BGM: ON", "SFX: ON", "Back"};
	Menu settingMenu = Menu(640, 640, mChildren);
	sf::RenderWindow window(sf::VideoMode(640, 640), "Crossing Road");
	window.setMouseCursorVisible(false);
	int selectedItemIndex;
	sf::Font font;
	vector<sf::Text> menu;
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}
	menu.resize(mChildren.size());

	for (int i = 0; i < mChildren.size(); ++i) {
		menu[i].setFont(font);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Red);
		else
			menu[i].setFillColor(sf::Color::White);
		menu[i].setString(mChildren[i]);
		menu[i].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (mChildren.size() + 1) * (i + 1)));
	}

	selectedItemIndex = 0;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed &&
				event.key.code == sf::Keyboard::Key::Enter)
			{
				switch (selectedItemIndex)
				{
				case 0: // Music
					if (mChildren[0] == "BGM: ON")
					{
						mChildren[0] = "BGM: OFF";
						MusicPlayer::sInstance->stop();
					}
					else {
						mChildren[0] = "BGM: ON";
						MusicPlayer::sInstance->play(Music::MissionTheme);
					}
					menu[0].setString(mChildren[0]);
					break;
				case 1: // Sound Effect
					if (mChildren[1] == "SFX: ON")
					{
						mChildren[1] = "SFX: OFF";
						SoundPlayerEffect::sInstance->setState(false);
					}
					else {
						mChildren[1] = "SFX: ON";
						SoundPlayerEffect::sInstance->setState(true);
					}
					menu[1].setString(mChildren[1]);
					break;
				case 2: // Quit
					window.close();
					break;
				}
			}
			if (event.type == sf::Event::EventType::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Up:
					if (selectedItemIndex - 1 >= 0)
					{
						menu[selectedItemIndex].setFillColor(sf::Color::White);
						selectedItemIndex--;
						menu[selectedItemIndex].setFillColor(sf::Color::Red);
					}
					break;
				case sf::Keyboard::Key::Down:
					if (selectedItemIndex + 1 < menu.size())
					{
						menu[selectedItemIndex].setFillColor(sf::Color::White);
						selectedItemIndex++;
						menu[selectedItemIndex].setFillColor(sf::Color::Red);
					}
					break;
				}
			}
		}
		window.clear();
		for (int i = 0; i < menu.size(); i++)
		{
			window.draw(menu[i]);
		}
		window.display();
	}
}