#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "CollisionHandling.hpp"
#include "GameObject.hpp"
#include "Window.hpp"
#include "Player.hpp"
#include "ReadFromFile.hpp"

class Stage {
public:
    Stage(Window&);
   
    void playStage();
private:
    void update(sf::Time);
    void render();
    void draw();
    void collisionHandling();
    void setView();
    void setBackgrund();
    //void victoryOrDath();
    template <typename FwdIt, typename Fn>
    void for_each_pair(FwdIt, FwdIt, Fn);
//============================================
    std::vector<std::unique_ptr<GameObject>> m_dataStruct;
    CollisionHandling m_collisionHandl;
    ReadFromFile m_readFromFile;
    Player* m_player;
    Window& m_window;
    sf::Sprite m_backgrund;
    
    bool m_done = false;
    bool m_status = false;
    
};

template <typename FwdIt, typename Fn>
void Stage::for_each_pair(FwdIt begin, FwdIt end, Fn fn){
    for(; begin != end; ++begin)
        for(auto second = begin+1; second != end; ++second)
            fn(*begin, *second);
}
