#include "DynamicObjects.hpp"

DynamicObjects::DynamicObjects(sf::Vector2f loc):StaticObjects(loc){};
DynamicObjects::~DynamicObjects(){};


void DynamicObjects::update(sf::Time frameTime){
    
}

void DynamicObjects::notAvailable(){
    m_active = false;
}

void DynamicObjects::draw(sf::RenderWindow& window){
    if(m_active)
        window.draw(m_sprite);
}
