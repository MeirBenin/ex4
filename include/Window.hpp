#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Window{
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void Update();
    void BeginDraw();
    void EndDraw();
	bool IsDone();
	void Close();

	sf::RenderWindow& GetRenderWindow();
	sf::Vector2u GetWindowSize();
private:
	void Setup(const std::string& title, const sf::Vector2u& size);
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
    bool m_isDone;
};
