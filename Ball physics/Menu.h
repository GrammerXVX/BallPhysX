#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
	sf::Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuBackground;
public:
	Menu();
	~Menu();
	void callMenu(sf::RenderWindow &window);
};

