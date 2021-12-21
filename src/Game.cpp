#include "Game.hpp"

Game::Game():m_stage(m_window){}
Game::~Game(){}


void Game::run(){
    m_stage.playStage();
}
