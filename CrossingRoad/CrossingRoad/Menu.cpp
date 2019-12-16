#include "Menu.h"

Menu::Menu(float width, float height, vector<string> items)
{
	if (!font.loadFromFile("futur.ttf"))
	{
		// handle error
	}
	float t = (height / (5 + 1)) + 70;
	mChildren = items;
	menu.resize(mChildren.size());

	for (int i = 0; i < mChildren.size(); ++i) {
		menu[i].setFont(font);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Red);
		else
			menu[i].setFillColor(sf::Color::White);
		menu[i].setString(mChildren[i]);
		menu[i].setPosition(sf::Vector2f(width * 0.5f - 90, t + 50 * i));
	}

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < menu.size(); i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveMenu(sf::Event& event)
{
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