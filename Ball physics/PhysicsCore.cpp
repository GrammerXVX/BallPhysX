#include "PhysicsCore.h"
#include "Ball.h"
Physics::Physics(std::vector<Ball> Objects) {
    this->Objects = Objects;
}
void Physics::PreProcessing(sf::RenderWindow &window) {


    for (size_t i = 0; i < Objects.size(); i++)
    {
        if (Objects.at(i).dx == 0)
            Objects.at(i).SetAcceleration();
        float d,Dx,Dy,s,e;
        int CurrentObject=0;
        Objects.at(i).posX += Objects.at(i).dx;
        Objects.at(i).posY += Objects.at(i).dy;
        if ((Objects.at(i).posX + Objects.at(i).Radius > window.getSize().x) || (Objects.at(i).posX - Objects.at(i).Radius < 0)) {
            Objects.at(i).dx = -Objects.at(i).dx;
        }
        if ((Objects.at(i).posY + Objects.at(i).Radius > window.getSize().y) || (Objects.at(i).posY - Objects.at(i).Radius < 0)) {
            Objects.at(i).dy = -Objects.at(i).dy;
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
            float Vn1 = Objects.at(CurrentObject).dx * s + Objects.at(CurrentObject).dy * e;
            float Vn2 = Objects.at(i).dx * s + Objects.at(i).dy * e;
            float dt = (Objects.at(CurrentObject).Radius + Objects.at(i).Radius - d) / (Vn1 - Vn2);
            if (dt > 0.6) dt = 0.6;
            if (dt < -0.6) dt = -0.6;
            Objects.at(i).posX -= Objects.at(i).dx * dt;
            Objects.at(i).posY -= Objects.at(i).dy * dt;
            Objects.at(CurrentObject).posX -= Objects.at(CurrentObject).dx * dt;
            Objects.at(CurrentObject).posY -= Objects.at(CurrentObject).dy * dt;
            Dx = Objects.at(i).posX - Objects.at(CurrentObject).posX;
            Dy = Objects.at(i).posY - Objects.at(CurrentObject).posY;
            d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
            s = Dx / d; // sin
            e = Dy / d; // cos
            Vn1 = Objects.at(CurrentObject).dx * s + Objects.at(CurrentObject).dy * e;
            Vn2 = Objects.at(i).dx * s + Objects.at(i).dy * e;
            float Vt1 = -Objects.at(CurrentObject).dx * e + Objects.at(CurrentObject).dy * s;
            float Vt2 = -Objects.at(i).dx * e + Objects.at(i).dy * s;

            float o = Vn2;
            Vn2 = Vn1;
            Vn1 = o;

            Objects.at(i).dx = Vn2 * s - Vt2 * e;
            Objects.at(i).dy = Vn2 * e + Vt2 * s;
            Objects.at(CurrentObject).dx = Vn1 * s - Vt1 * e;
            Objects.at(CurrentObject).dy = Vn1 * e + Vt1 * s;
            Objects.at(i).posX += Objects.at(i).dx * dt;
            Objects.at(i).posY += Objects.at(i).dy * dt;
            Objects.at(CurrentObject).posX += Objects.at(CurrentObject).dx * dt;
            Objects.at(CurrentObject).posY += Objects.at(CurrentObject).dy * dt;
        }
        Objects.at(i).Update();
        window.draw(Objects.at(i).basicShape);
    }
}
Physics::~Physics() {
    this->Objects.clear();
    this->Objects.~vector();
}
