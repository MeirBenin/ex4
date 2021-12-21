#include "Window.hpp"

Window::Window(){ 
	Setup("Window", sf::Vector2u(sf::VideoMode::getDesktopMode().width,
                                 sf::VideoMode::getDesktopMode().height));
}

Window::Window(const std::string& title, const sf::Vector2u& size){ 
	Setup(title,size);
}

Window::~Window(){ m_window.close(); }

void Window::Setup(const std::string& title, const sf::Vector2u& size){
	m_windowTitle = title;
	m_windowSize = size;
	m_isDone = false;
	Create();
}

void Window::Create(){
	m_window.create(sf::VideoMode(m_windowSize.x,m_windowSize.y),m_windowTitle);
}

bool Window::IsDone(){ return m_isDone; }

sf::RenderWindow& Window::GetRenderWindow(){ return m_window; }
 
sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }

void Window::Close(){ m_isDone = true; }

void Window::Update(){
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed) {
            Close();
        }

        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            Close();
        }
    }
    

}

void Window::BeginDraw(){ m_window.clear(sf::Color::White); }


void Window::EndDraw(){
    m_window.display();
}
