#pragma once
#include "StaticObjects.hpp"

class StaticBrick: public StaticObjects{
public:
    StaticBrick(sf::Vector2f);
    void update(sf::Time frameTime){}
private:
    static bool m_registerit;
};

