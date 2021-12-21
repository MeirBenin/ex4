#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectFactory.hpp"
#include "ObjectIndex.hpp"


class GameObject{
public:
    GameObject(sf::Vector2f);
    ~GameObject();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    virtual void draw(sf::RenderWindow&){};
    virtual void update(sf::Time){};
protected:
    sf::Sprite m_sprite;
};
