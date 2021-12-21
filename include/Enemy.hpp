#pragma once
#include "BaseEnemy.hpp"

class Enemy: public BaseEnemy{
public:
    Enemy(sf::Vector2f);
    void move(sf::Time)override;
private:
    static bool m_registerit;
};

