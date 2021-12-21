#include "TopBrick.hpp"

TopBrick::TopBrick(sf::Vector2f loc ):StaticObjects(loc){
    setSprite(loc, "topBrick.png");
}

bool TopBrick::m_registerit = ObjectFactory::registerit(ObjectIndex::TopBrick,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<TopBrick>(loc); });
    
