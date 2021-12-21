#include "Thorn.hpp"

Thorn::Thorn(sf::Vector2f loc ):StaticObjects(loc){
    setSprite(loc, "thorn.png");
}

bool Thorn::m_registerit = ObjectFactory::registerit(ObjectIndex::Thorn,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<Thorn>(loc); });
    
