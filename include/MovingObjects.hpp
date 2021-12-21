#pragma once
#include "GameObject.hpp"
#include "Resources.hpp"

class MovingObjects: public GameObject{
public:
    MovingObjects(sf::Vector2f);
    virtual ~MovingObjects();
    
    void update(sf::Time)override;
    
    void fixMove(int,int);
    void onTheGraund();
    sf::FloatRect getLastLegalLoc();
    virtual void deth()=0;
protected:
    
    virtual void move(sf::Time)=0;
    void gravity(sf::Time);
    void setSprite(sf::Vector2f, std::string);
protected:
    float m_objectSpeed ;
    float m_gravityPower;
    int m_jumps = 0;
    bool isJump = false;
    sf::Clock m_clock;
    sf::FloatRect m_LastLegalLoc;
};
