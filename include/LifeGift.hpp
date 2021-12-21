#pragma once
#include "DynamicObjects.hpp"

class LifeGift: public DynamicObjects{
public:
    LifeGift(sf::Vector2f);
private:
    static bool m_registerit;
};

