#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsCore.h"
class Menu
{
	sf::Texture menuTexture1,menuTexture2, menuTexture3, menuTexture4, menuBackground,background, menuChoose1,menuChoose2;
	std::vector<Ball>* Objects;
	int menuNum;
public:
	Menu();
	~Menu();
	void callMenu(sf::RenderWindow &window);
	void MenuInProgress(sf::RenderWindow &window,int menuNum);
	void push( Physics&, sf::RenderWindow& , sf::Color);
	void pop(Physics& a);
};

