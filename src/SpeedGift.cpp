
#include "SpeedGift.hpp"

SpeedGift::SpeedGift(sf::Vector2f loc):DynamicObjects(loc){
    setSprite(loc, "speedGift.png");
}



bool SpeedGift::m_registerit = ObjectFactory::registerit(ObjectIndex::SpeedGift,
     [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
             { return std::make_unique<SpeedGift>(loc); });

