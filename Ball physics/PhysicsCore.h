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
	public: 
		Physics(std::vector<Ball>);
		~Physics();
		void PreProcessing(sf::RenderWindow&);
};

