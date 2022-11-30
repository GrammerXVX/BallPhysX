#include "Entity.h"
Entity::Entity(float posX,float posY,float Radius,sf::Color color) {
	this->Radius = Radius;
	this->posX = posX;
	this->posY = posY;
	this->Color = color;
}

Entity::Entity(float posX, float posY, float Radius, int Red,int Green, int Blue) {
	this->Radius = Radius;
	this->posX = posX;
	this->posY = posY;
	this->Color = sf::Color(Red,Green,Blue);
}

Entity* Entity::Update(float, float)
{
	return this;
}
Entity::~Entity() {
	
}
