#include "Ball.h"
#include <ctime>
Ball::Ball(float posX, float posY, float Radius, sf::Color color) {
	this->Radius = Radius;
	this->posX = posX;
	this->posY = posY;
	this->Color = color;
}

Ball::Ball(float posX, float posY, float Radius, int Red, int Green, int Blue) {
	this->Radius = Radius;
	this->posX = posX;
	this->posY = posY;
	this->Color = sf::Color(Red, Green, Blue);
}
void Ball::Update(float NewPosX, float NewPosY) 
{
    this->setRadius(Radius);
    this->setOrigin(Radius, Radius);
    this->setPosition(NewPosX, NewPosY);
    this->setFillColor(Color);

} 
void Ball::Update()
{
	basicShape.setRadius(Radius);
	basicShape.setOrigin(Radius, Radius);
	basicShape.setPosition(posX, posY);
	basicShape.setFillColor(Color);
}
void Ball::SetAcceleration() {
	//srand(time(0));
	dx = 1+rand() % 10;
	dy = 1+rand() % 10;
}
