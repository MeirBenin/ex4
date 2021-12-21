#pragma once
#include "DynamicObjects.hpp"

class Coin: public DynamicObjects{
public:
    Coin(sf::Vector2f);
private:
    static bool m_registerit;
};
