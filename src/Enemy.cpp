#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f loc):BaseEnemy(loc){
    setSprite(loc, "enemy.png");
}

void Enemy::move(sf::Time delta){
    if (m_clock.getElapsedTime().asMilliseconds()<500)return;
    m_sprite.move(m_enemyDir);
    m_clock.restart();
}

bool Enemy::m_registerit = ObjectFactory::registerit(ObjectIndex::Enemy,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<Enemy>(loc); });
    
