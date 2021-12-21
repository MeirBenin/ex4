#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ObjectIndex.hpp"
class GameObject;

using std::make_unique;
using std::unique_ptr;
using creatFuncPtr = std::unique_ptr<GameObject>(*)(sf::Vector2f);
using map = std::map<ObjectIndex, creatFuncPtr>;

class ObjectFactory {
public:
    static creatFuncPtr create(ObjectIndex);
    static bool registerit(ObjectIndex, creatFuncPtr);
private:
    static map& getMap();
};

