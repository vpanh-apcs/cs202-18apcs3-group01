#include "Helper.h"
class Menu
{
public:
	Menu(float width, float height, vector<string> items);
	virtual ~Menu();
	void draw(sf::RenderWindow& window);
	void moveMenu(sf::Event& event);
	int GetPressedItem() { return selectedItemIndex; }

protected:
	vector<string> mChildren;
	int selectedItemIndex;
	sf::Font font;
	vector<sf::Text> menu;
};