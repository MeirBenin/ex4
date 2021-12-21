#pragma once
#include "StaticObjects.hpp"

class TopBrick: public StaticObjects{
public:
    TopBrick(sf::Vector2f);
    void update(sf::Time frameTime){}
private:
    static bool m_registerit;
};

