#pragma once
#include<SFML/Graphics.hpp>
class Entity: public sf::CircleShape,sf::RectangleShape
{
protected:
	float posX = 0.0, posY = 0.0;
	float dx = 0, dy = 0;
	float Radius = 0;
	sf::Color Color;
	sf::RenderWindow Environment;
public:
	Entity(float,float,float,sf::Color);
	Entity(float, float, float, int,int,int);
	~Entity();
	virtual Entity* Update(float, float);
};


