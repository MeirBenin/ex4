#pragma once
#include "StaticObjects.hpp"

class Thorn: public StaticObjects{
public:
    Thorn(sf::Vector2f);
    void update(sf::Time frameTime){}
private:
    static bool m_registerit;
};

