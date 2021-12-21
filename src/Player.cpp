#include "Player.hpp"

Player::Player(sf::Vector2f loc ):MovingObjects(loc){
    setSprite(loc, "player.png");
}

void Player::move(sf::Time delta){
    if(m_clock.getElapsedTime().asMilliseconds() < 50)return;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        m_sprite.move(-m_objectSpeed,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        m_sprite.move(m_objectSpeed,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(m_jumps < 10)
        {
        isJump = true;
        m_sprite.move(0,-m_objectSpeed);
            m_jumps++;
        }
        else isJump = false;
    }
    if(m_jumpTime.getElapsedTime().asMilliseconds() > 500){
        isJump = false;
        m_jumpTime.restart();
        
    }
    
    
    m_clock.restart();
}

void Player::draw(sf::RenderWindow& window){window.draw(m_sprite);}
void Player::deth(){m_life--;}
void Player::setPosition(sf::Vector2f loc){m_sprite.setPosition(loc);}
void Player::done(){ m_done = true;}
bool Player::isDone(){return m_done;}

void Player::addLife(){m_life++;}
void Player::addKey(){m_keys++;}
void Player::addSpeed(){}
void Player::addCoin(){m_coins++;}

bool Player::isDead(){return m_life <= 0 ? true:false;}

bool Player::m_registerit = ObjectFactory::registerit(ObjectIndex::Player,
         [](sf::Vector2f loc) -> std::unique_ptr<GameObject>
                 { return std::make_unique<Player>(loc); });
    
