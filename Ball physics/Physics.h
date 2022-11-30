#pragma once
#include"Entity.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<stdio.h>
#include<stdarg.h>
class Physics 
{
	private:
		std::vector<Entity> *Objects;
	public: 
		Physics(std::vector<Entity>);
		~Physics();
		void Processing(sf::RenderWindow);
};

