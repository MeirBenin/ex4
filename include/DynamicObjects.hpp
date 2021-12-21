#pragma once
#include "StaticObjects.hpp"

class DynamicObjects: public StaticObjects{
public:
    DynamicObjects(sf::Vector2f);
    ~DynamicObjects();
    void notAvailable();
    void update(sf::Time)override;
    void draw(sf::RenderWindow&)override;
private:
    bool m_active = true;
};
