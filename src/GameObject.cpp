
#include "GameObject.hpp"

GameObject::GameObject(sf::Vector2f loc){}
GameObject::~GameObject(){}

sf::FloatRect GameObject::getGlobalBounds(){
    return m_sprite.getGlobalBounds();}

sf::Vector2f GameObject::getPosition(){
    return m_sprite.getPosition();}

