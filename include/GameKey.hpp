#pragma once
#include "DynamicObjects.hpp"


class GameKey: public DynamicObjects{
public:
    GameKey(sf::Vector2f);
private:
    static bool m_registerit;
};
