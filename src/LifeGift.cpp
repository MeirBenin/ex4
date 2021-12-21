
#include "LifeGift.hpp"

LifeGift::LifeGift(sf::Vector2f loc):DynamicObjects(loc){
    setSprite(loc, "lifeGift.png");
}


bool LifeGift::m_registerit = ObjectFactory::registerit(ObjectIndex::LifeGift,
     [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
             { return std::make_unique<LifeGift>(loc); });


