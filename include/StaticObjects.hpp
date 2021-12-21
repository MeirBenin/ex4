#pragma once
#include "UnmovingObjects.hpp"
#include "Resources.hpp"

class StaticObjects: public UnmovingObjects{
public:
    StaticObjects(sf::Vector2f);
    virtual ~StaticObjects();
    
    void update(sf::Time)override;
    void draw(sf::RenderWindow&)override;

};
