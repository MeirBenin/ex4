#include "StaticObjects.hpp"

StaticObjects::StaticObjects(sf::Vector2f loc ):UnmovingObjects(loc){}
StaticObjects::~StaticObjects(){}

void StaticObjects::update(sf::Time){
}

void StaticObjects::draw(sf::RenderWindow& window){
    window.draw(m_sprite);
}
