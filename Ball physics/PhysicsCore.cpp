#include "PhysicsCore.h"
#include "Ball.h"
#include <iostream>
Physics::Physics(std::vector<Ball> Objects, sf::RenderWindow& renderWindow) {
    this->Objects = Objects;
    groundHeight = renderWindow.getSize().y;
}
void Physics::PreProcessing(sf::RenderWindow& window) {
    int NumberFixBall;
    bool isMove = false;
    float dX = 0;
    float dY = 0;
    sf::Color colorTmp;
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
    sf::Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
    //std::cout << pixelPos.x << "\n";//смотрим на координату Х позиции курсора в консоли (она не будет больше ширины окна)
    //std::cout << pos.x << "\n";//смотрим на Х,которая преобразовалась в мировые координаты
    sf::Event event;
    float currentBall;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) //если нажата клавиша мыши
        {
            if (event.key.code == sf::Mouse::Left)//а именно левая
            {
                for (size_t j = 0; j < Objects.size(); j++)
                {
                    currentBall = sqrt(pow((Objects.at(j).posX - pos.x), 2) + pow((Objects.at(j).posY - pos.y), 2));
                    if (currentBall <= Objects.at(j).Radius)//и при этом координата курсора попадает в спрайт
                    {
                        Objects.at(j).velocity = sf::Vector2f(0, 0);
                        std::cout << "isClicked!\n";//выводим в консоль сообщение об этом
                        dX = pos.x - Objects.at(j).posX;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
                        dY = pos.y - Objects.at(j).posY;//тоже самое по игреку
                        Objects.at(j).isMove = true;//можем двигать спрайт			
                        colorTmp= Objects.at(j).Color;
                        Objects.at(j).setFillColor(sf::Color::White);
                        NumberFixBall = j;
                        //}

                    }
                }

            }
        }


        if (event.type == sf::Event::MouseButtonReleased)//если отпустили клавишу
            if (event.key.code == sf::Mouse::Left) {//а именно левую
                for (size_t j = 0; j < Objects.size(); j++)
                {
                    if (Objects.at(j).isMove) {
                        Objects.at(j).setFillColor(colorTmp); //и даем ему прежний цвет
                        Objects.at(j).isMove = false;
                    }
                        
                }
            }
        for (size_t j = 0; j < Objects.size(); j++)
        {
            if (Objects.at(j).isMove) {//если можем двигать
                Objects.at(j).setFillColor(sf::Color::Green);//красим спрайт в зеленый 
                Objects.at(j).posX = pos.x;//двигаем спрайт по Х
                Objects.at(j).posY = pos.y;//двигаем по Y
            }
        }
    }
    for (size_t i = 0; i < Objects.size(); i++)
    {
        if (!Objects.at(i).isMove)
        {
            if (Objects.at(i).posY + Objects.at(i).Radius < groundHeight || Objects.at(i).velocity.y < 0) {
                if (!Objects.at(i).isMove)
                    Objects.at(i).velocity.y += gravity;
            }
            else {
                Objects.at(i).setPosition(Objects.at(i).getPosition().x, groundHeight - Objects.at(i).Radius);
                Objects.at(i).velocity.y = 0;
            }
        }
        /*if (Objects.at(i).velocity.x == 0)
            Objects.at(i).SetAcceleration();*/
        float d, Dx, Dy, s, e;
        int CurrentObject = 0;
        if (!Objects.at(i).isMove)
        {
            Objects.at(i).posX += Objects.at(i).velocity.x;
            Objects.at(i).posY += Objects.at(i).velocity.y;
        }
        if (!Objects.at(i).isMove)
        {
            if ((Objects.at(i).posX + Objects.at(i).Radius > window.getSize().x) || (Objects.at(i).posX - Objects.at(i).Radius < 0)) {
                Objects.at(i).velocity.x = -Objects.at(i).velocity.x;
            }
            if ((Objects.at(i).posY + Objects.at(i).Radius > window.getSize().y) || (Objects.at(i).posY - Objects.at(i).Radius < 0)) {
                Objects.at(i).velocity.y = -Objects.at(i).velocity.y;
            }

        }
        for (size_t j = 0; j < Objects.size(); j++)
        {
            if (i == j)
                continue;

            Dx = Objects.at(i).posX - Objects.at(j).posX;
            Dy = Objects.at(i).posY - Objects.at(j).posY;
            d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
            s = Dx / d; // sin
            e = Dy / d; // cos
            if (d < Objects.at(i).Radius + Objects.at(j).Radius) {
                CurrentObject = j;
                break;
            }
        }
        if (d < Objects.at(i).Radius + Objects.at(CurrentObject).Radius) {
            float Vn1 = Objects.at(CurrentObject).velocity.x * s + Objects.at(CurrentObject).velocity.y * e;
            float Vn2 = Objects.at(i).velocity.x * s + Objects.at(i).velocity.y * e;
            float dt = (Objects.at(CurrentObject).Radius + Objects.at(i).Radius - d) / (Vn1 - Vn2);
            if (dt > 0.6) dt = 0.6;
            if (dt < -0.6) dt = -0.6;
            if (!Objects.at(i).isMove)
            {
                Objects.at(i).posX -= Objects.at(i).velocity.x * dt;
                Objects.at(i).posY -= Objects.at(i).velocity.y * dt;
            }
            if (!Objects.at(CurrentObject).isMove)
            {
                Objects.at(CurrentObject).posX -= Objects.at(CurrentObject).velocity.x * dt;
                Objects.at(CurrentObject).posY -= Objects.at(CurrentObject).velocity.y * dt;
            }
            Dx = Objects.at(i).posX - Objects.at(CurrentObject).posX;
            Dy = Objects.at(i).posY - Objects.at(CurrentObject).posY;
            d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
            s = Dx / d; // sin
            e = Dy / d; // cos
            Vn1 = Objects.at(CurrentObject).velocity.x * s + Objects.at(CurrentObject).velocity.y * e;
            Vn2 = Objects.at(i).velocity.x * s + Objects.at(i).velocity.y * e;
            float Vt1 = -Objects.at(CurrentObject).velocity.x * e + Objects.at(CurrentObject).velocity.y * s;
            float Vt2 = -Objects.at(i).velocity.x * e + Objects.at(i).velocity.y * s;

            float o = Vn2;
            Vn2 = Vn1;
            Vn1 = o;
            if (!Objects.at(i).isMove)
            {
                Objects.at(i).velocity.x = Vn2 * s - Vt2 * e;
                Objects.at(i).velocity.y = Vn2 * e + Vt2 * s;
                Objects.at(CurrentObject).posX += Objects.at(CurrentObject).velocity.x * dt;
                Objects.at(CurrentObject).posY += Objects.at(CurrentObject).velocity.y * dt;
            }
            if (!Objects.at(CurrentObject).isMove)
            {
                Objects.at(CurrentObject).velocity.x = Vn1 * s - Vt1 * e;
                Objects.at(CurrentObject).velocity.y = Vn1 * e + Vt1 * s;
                Objects.at(i).posX += Objects.at(i).velocity.x * dt;
                Objects.at(i).posY += Objects.at(i).velocity.y * dt;
            }
        }
        Objects.at(i).Update();
        window.draw(Objects.at(i).basicShape);
    }
}

Physics::~Physics() {
    this->Objects.clear();
    this->Objects.~vector();
}
