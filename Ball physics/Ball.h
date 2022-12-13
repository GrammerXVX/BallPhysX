#pragma once
#include"SFML/Graphics.hpp"
class Ball:public sf::CircleShape
{
public:
	sf::CircleShape basicShape;
	float posX = 0.0, posY = 0.0;
	sf::Vector2f velocity;
	bool isMove = false;
	float Radius = 0;
	sf::Color Color;
	Ball(float, float, float, sf::Color);
	Ball(float, float, float, int, int, int);
	void Update(float,float);
	void Update();
	void SetAcceleration();
};

