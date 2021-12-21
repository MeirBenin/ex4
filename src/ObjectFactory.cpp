
#include "ObjectFactory.hpp"
#include "GameObject.hpp"



creatFuncPtr ObjectFactory::create(ObjectIndex index) {
    auto it = getMap().find(index);
    if (it == getMap().end())
        return nullptr;
    return it->second;
}


map& ObjectFactory::getMap(){
    static map map;
    return map;
}

bool ObjectFactory::registerit(ObjectIndex index,
                               creatFuncPtr func) {

    getMap().insert(std::make_pair(index, func));
    return true;
}
