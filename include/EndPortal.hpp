#pragma once
#include "StaticObjects.hpp"

class EndPortal: public StaticObjects{
public:
    EndPortal(sf::Vector2f);
    void update(sf::Time frameTime){}
private:
    static bool m_registerit;
};

