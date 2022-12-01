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

//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(W, H), "My SFML WORKS!!!");
//    float x1 = W / 4;
//    float y1 = H / 2;
//    float x2 = W / 4 * 3;
//    float y2 = H / 2;
//    float r1 = 50;
//    float r2 = 50;
//    float dx1 = rand() % 10;
//    float dy1 = rand() % 10;
//    float dx2 = rand() % 10;
//    float dy2 = rand() % 10;
//    sf::Color col1 = sf::Color(255, 0, 255);
//    sf::Color col2 = sf::Color(255, 255, 0);
//   
//    sf::CircleShape shape(0);
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            window.close();
//        }
//
//
//        x1 += dx1;
//        y1 += dy1;
//        if ((x1 + r1 > W) || (x1 - r1 < 0)) {
//            dx1 = -dx1;
//        }
//        if ((y1 + r1 > H) || (y1 - r1 < 0)) {
//            dy1 = -dy1;
//        }
//        x2 += dx2;
//        y2 += dy2;
//        if ((x2 + r2 > W) || (x2 - r2 < 0)) {
//            dx2 = -dx2;
//        }
//        if ((y2 + r2 > H) || (y2 - r2 < 0)) {
//            dy2 = -dy2;
//        }
//
//
//        float Dx = x1 - x2;
//        float Dy = y1 - y2;
//        float d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
//        float s = Dx / d; // sin
//        float e = Dy / d; // cos
//        if (d < r1 + r2) {
//            float Vn1 = dx2 * s + dy2 * e;
//            float Vn2 = dx1 * s + dy1 * e;
//            float dt = (r2 + r1 - d) / (Vn1 - Vn2);
//            if (dt > 0.6) dt = 0.6;
//            if (dt < -0.6) dt = -0.6;
//            x1 -= dx1 * dt;
//            y1 -= dy1 * dt;
//            x2 -= dx2 * dt;
//            y2 -= dy2 * dt;
//            Dx = x1 - x2;
//            Dy = y1 - y2;
//            d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
//            s = Dx / d; // sin
//            e = Dy / d; // cos
//            Vn1 = dx2 * s + dy2 * e;
//            Vn2 = dx1 * s + dy1 * e;
//            float Vt1 = -dx2 * e + dy2 * s;
//            float Vt2 = -dx1 * e + dy1 * s;
//
//
//            float o = Vn2;
//            Vn2 = Vn1;
//            Vn1 = o;
//
//
//            dx1 = Vn2 * s - Vt2 * e;
//            dy1 = Vn2 * e + Vt2 * s;
//            dx2 = Vn1 * s - Vt1 * e;
//            dy2 = Vn1 * e + Vt1 * s;
//            x1 += dx1 * dt;
//            y1 += dy1 * dt;
//            x2 += dx2 * dt;
//            y2 += dy2 * dt;
//        }
//
//
//
//
//
//        window.clear();
//
//        shape.setRadius(r1);
//        shape.setOrigin(r1, r1);
//        shape.setPosition(x1, y1);
//        shape.setFillColor(col1);
//        window.draw(shape);
//
//        shape.setRadius(r2);
//        shape.setOrigin(r2, r2);
//        shape.setPosition(x2, y2);
//        shape.setFillColor(col2);
//        window.draw(shape);
//
//
//        window.display();
//        sf::sleep(sf::milliseconds(int(1000 / 120)));
//    }
//
//    return 0;
//}
int main()
{
    //!!!Коменты предыдущего main НЕ УДАЛЯТЬ!!!
    sf::RenderWindow window(sf::VideoMode(W, H), "My SFML WORKS!!!");
    //Начало Тестовые значение
    sf::Color col1 = sf::Color(255, 0, 255);
    sf::Color col2 = sf::Color(255, 255, 0);
    std::vector<Ball> MyObjects = {
        Ball(W / 4.f,H / 2.f,50.f,col1),
        Ball(W / 4.f * 0.50,H / 2.f,50.f,col2),
        Ball(W / 4.f * 1.5,H / 2.f,50.f,0,255,255),
        Ball(W / 4.f * 2,H / 2.f,50.f,255,255,255),
        Ball(W / 4.f * 2.5,H / 2.f,50.f,0,255,0),
    };
    Physics a = Physics(MyObjects);
    //Конец Тестовых значений
    sf::Clock clock;
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
       window.clear();
       a.PreProcessing(window);//Тест
       window.display();
       //sf::sleep(sf::milliseconds(int(1000 / 30)));
    }
    return 0;
}