#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include<vector>
#include"Ball.h"
#include"PhysicsCore.h"
#include"Menu.h"
const int W = 900;
const int H = 600;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "My SFML WORKS!!!");

    
    sf::Vector2f velocity(sf::Vector2f(0, 0));

    sf::RectangleShape rect(sf::Vector2f(20,20));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Blue);

    float moveSpeed = 1.0f, jumpSpeed = 10.0f;


    sf::Color col1 = sf::Color(255, 0, 255);
    sf::Color col2 = sf::Color(255, 255, 0);
    std::vector<Ball> MyObjects = {
        Ball(W / 4.f,H / 2.f,50.f,col1),
        Ball(W / 4.f * 0.50,H / 2.f,50.f,col2),
        Ball(W / 4.f * 1.5,H / 2.f,50.f,0,255,255),
        Ball(W / 4.f * 2,H / 2.f,50.f,255,255,255),
        Ball(W / 4.f * 2.5,H / 2.f,50.f,0,255,0),
    };
    Ball b = Ball(W / 4.f, H / 2.f, 50.f, col1);
    Physics a = Physics(MyObjects, window);
    //Конец Тестовых значений
    sf::Clock clock;
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);

    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
       window.clear();
       a.PreProcessing(window);
       window.display();
    }
    return 0;
}