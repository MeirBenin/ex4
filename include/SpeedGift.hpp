#pragma once
#include "DynamicObjects.hpp"

class SpeedGift: public DynamicObjects{
public:
    SpeedGift(sf::Vector2f);
private:
    static bool m_registerit;
};
