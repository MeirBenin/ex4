#include "StaticBrick.hpp"

StaticBrick::StaticBrick(sf::Vector2f loc ):StaticObjects(loc){
    setSprite(loc, "brick.png");
}

bool StaticBrick::m_registerit = ObjectFactory::registerit(ObjectIndex::StaticBrick,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<StaticBrick>(loc); });
    
