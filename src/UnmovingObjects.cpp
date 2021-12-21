#include "UnmovingObjects.hpp"

UnmovingObjects::UnmovingObjects(sf::Vector2f loc ):GameObject(loc){}
UnmovingObjects::~UnmovingObjects(){}

void UnmovingObjects::setSprite(sf::Vector2f loc ,std::string fileName){
    m_sprite.setTexture(Resources::instance().getTexture(fileName));
   
    auto spriteSize = sf::Vector2f(m_sprite.getLocalBounds().width,
                                   m_sprite.getLocalBounds().height);
   // m_sprite.setOrigin(spriteSize.x/2, spriteSize.y/2);
    m_sprite.setPosition(loc.x * 150, loc.y * 150);
    m_sprite.scale(150/spriteSize.x, 150/spriteSize.y);
}
