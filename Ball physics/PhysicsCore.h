#pragma once
#include"Ball.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<stdio.h>
#include<stdarg.h>
class Physics 
{
	private:
		std::vector<Ball> Objects;
		const float gravity = 1;
		int groundHeight;
	public: 
		Physics(std::vector<Ball>, sf::RenderWindow&);
		~Physics();
		void PreProcessing(sf::RenderWindow&);
};

