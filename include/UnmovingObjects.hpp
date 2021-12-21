#pragma once
#include "GameObject.hpp"
#include "Resources.hpp"

class UnmovingObjects: public GameObject{
public:
    UnmovingObjects(sf::Vector2f);
    virtual ~UnmovingObjects();

protected:
    void setSprite(sf::Vector2f, std::string);
};
