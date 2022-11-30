#include "Physics.h"
Physics::Physics(std::vector<Entity> Objects) {
    this->Objects = &Objects;
}
void Physics::Processing(sf::RenderWindow window) {

}
Physics::~Physics() {
    this->Objects->clear();
    this->Objects->~vector();
}
