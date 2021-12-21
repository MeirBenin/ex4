#include "MovingObjects.hpp"

MovingObjects::MovingObjects(sf::Vector2f loc):GameObject(loc){
    m_gravityPower = 10;
    m_objectSpeed = 50;
}

MovingObjects::~MovingObjects(){}

void MovingObjects::setSprite(sf::Vector2f loc , std::string fileName){
    m_sprite.setTexture(Resources::instance().getTexture(fileName));

    auto spriteSize = sf::Vector2f(m_sprite.getLocalBounds().width,
                                   m_sprite.getLocalBounds().height);
    // m_sprite.setOrigin(spriteSize.x/2, spriteSize.y/2);
    m_sprite.scale(150/spriteSize.x, 150/spriteSize.y);
     m_sprite.setPosition(loc.x * 150, loc.y * 150);
  
   
}

void MovingObjects::fixMove(int x,int y){
    m_sprite.move(x,y);
}

void MovingObjects::onTheGraund(){
    m_jumps = 0;
}

void MovingObjects::gravity(sf::Time delta){
  if(!isJump) m_sprite.move(0,m_gravityPower);
}

sf::FloatRect MovingObjects::getLastLegalLoc(){
    return m_LastLegalLoc;
}


void MovingObjects::update(sf::Time delta){
    m_LastLegalLoc = m_sprite.getGlobalBounds();
    gravity(delta);
    move(delta);
}
