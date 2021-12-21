
#include "Coin.hpp"

Coin::Coin(sf::Vector2f loc):DynamicObjects(loc){
    setSprite(loc, "coin.png");
}




bool Coin::m_registerit = ObjectFactory::registerit(ObjectIndex::Coin,
     [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
             { return std::make_unique<Coin>(loc); });


