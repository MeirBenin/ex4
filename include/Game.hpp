#pragma once
#include "Window.hpp"
#include "Stage.hpp"

class Game{
public:
	Game();
	~Game();
    void run();

private:
	Window m_window;
    Stage m_stage;
};
