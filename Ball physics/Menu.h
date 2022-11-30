#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
	sf::Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuBackground,background;
	int menuNum;
public:
	Menu();
	~Menu();
	void callMenu(sf::RenderWindow &window);
	void MenuInProgress(sf::RenderWindow &window,int menuNum);
};

