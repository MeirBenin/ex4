
#include "GameKey.hpp"

GameKey::GameKey(sf::Vector2f loc):DynamicObjects(loc){
    setSprite(loc, "gameKey.png");
}

bool GameKey::m_registerit = ObjectFactory::registerit(ObjectIndex::GameKey,
     [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
             { return std::make_unique<GameKey>(loc); });

