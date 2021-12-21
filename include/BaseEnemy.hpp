#pragma once
#include "MovingObjects.hpp"

class BaseEnemy: public MovingObjects{
public:
    BaseEnemy(sf::Vector2f);
    void draw(sf::RenderWindow&)override;
    void deth()override;
    void reDirction();
    bool isActive();
protected:
    bool  m_active = true;
    sf::Vector2f m_enemyDir;
};
