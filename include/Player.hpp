#pragma once
#include "MovingObjects.hpp"

const int life = 3;

class Player: public MovingObjects{
public:
    Player(sf::Vector2f);
    void move(sf::Time) override;
    void draw(sf::RenderWindow&)override;
    void deth()override;
    
    void addLife();
    void addKey();
    void addSpeed();
    void addCoin();
    bool isDead();
    void done();
    bool isDone();
    void setPosition(sf::Vector2f);
private:
    sf::Clock m_jumpTime;
    int m_life = life;
    int m_keys = 0;
    int m_coins = 0;
    bool m_done = false;
    bool m_status = false;
    static bool m_registerit;
};

