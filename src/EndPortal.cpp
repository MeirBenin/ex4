#include "EndPortal.hpp"

EndPortal::EndPortal(sf::Vector2f loc ):StaticObjects(loc){
    setSprite(loc, "endPortal.png");
}

bool EndPortal::m_registerit = ObjectFactory::registerit(ObjectIndex::EndPortal,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<EndPortal>(loc); });
    
