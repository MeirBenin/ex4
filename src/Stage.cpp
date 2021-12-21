#include "Stage.hpp"
#include "Resources.hpp"

Stage::Stage(Window& window):m_window(window){
    m_readFromFile.read(m_dataStruct);
    m_player = ((Player*)m_dataStruct.front().get());
    setBackgrund();
}

void Stage::setBackgrund(){
    m_backgrund.setTexture(Resources::instance().getTexture("background.png"));
    auto windowSize = m_window.GetRenderWindow().getSize();
    auto backgrundSize = sf::Vector2f(m_backgrund.getLocalBounds().width,
                                     m_backgrund.getLocalBounds().height);
    m_backgrund.setOrigin(backgrundSize.x/2, backgrundSize.y/2);
    m_backgrund.scale(windowSize.x/backgrundSize.x, windowSize.y/backgrundSize.y);
    
}
    


void Stage::playStage(){
    while (!m_window.IsDone())
    {
    sf::Clock gameClock;
    auto delta = gameClock.restart();
        if (m_player->isDead()) {break;}
        if (m_player->isDone()) {break;}
    update(delta);
    m_window.Update();
    render();
    }
}


void Stage::update(sf::Time delta){
    for (auto& object : m_dataStruct) {
        object -> update(delta);
    }
    collisionHandling();
}


void Stage::render(){
    m_window.BeginDraw();
    setView();
    draw();
    m_window.EndDraw();
}



//void  Stage::victoryOrDath(){
//    if (((Player*)m_dataStruct->front().get())->getKeys() == m_keys){
//        ((Player*)m_dataStruct->front().get())->getKeys() = 0;
//        m_done = true;
//        m_status = true;
//    }
//    if (((Player*)m_dataStruct->front().get())->getLife() <= 0){
//        ((Player*)m_dataStruct->front().get())->getKeys() = 3;
//        m_done = true;
//        m_status = false;
//    }
//
//}
//



void Stage::setView(){
    auto playerPosition = m_dataStruct.front() -> getPosition();
    auto view = m_window.GetRenderWindow().getDefaultView();
    view.setCenter(playerPosition);
    m_window.GetRenderWindow().setView(view);
    m_backgrund.setPosition(playerPosition);
}

void Stage::draw(){
    m_window.GetRenderWindow().draw(m_backgrund);
    for (auto& object : m_dataStruct) {
        object -> draw(m_window.GetRenderWindow());
    }
}

void Stage::collisionHandling(){
  
    for_each_pair(m_dataStruct.begin(), m_dataStruct.end(), [this](auto& a, auto& b){
        if (m_collisionHandl.isCollide(a, b))
            m_collisionHandl.processCollision(a, b);
    });
}

