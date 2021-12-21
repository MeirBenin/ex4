

#include "BaseEnemy.hpp"

BaseEnemy::BaseEnemy(sf::Vector2f loc):MovingObjects(loc){
    m_enemyDir = sf::Vector2f(m_objectSpeed,0);
}
void BaseEnemy::reDirction(){
    m_enemyDir.x *= -1;
}

void BaseEnemy::draw(sf::RenderWindow& window){
    if(m_active)
        window.draw(m_sprite);
}
void BaseEnemy::deth(){m_active = false;}
bool BaseEnemy::isActive(){return m_active;}
