#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class WindowManager {
public:
	WindowManager(const std::string& windowTitle, const sf::Vector2u& windowSize);
	~WindowManager();

	void ClearWindow(); 
	void DisplayWindow();
	void UpdateWindow();
	void DestroyWindow();
	bool IsRunning() const;
	bool IsFullscreen() const;
	sf::Vector2u GetWindowSize() const;
	sf::Vector2u GetInitialWindowSize() const;
	sf::RenderWindow *GetRenderWindow();
	sf::Time GetElapsed() const;
	void RestartClock();
	void SetWindowSize(sf::Vector2u size);
	void ToggleFullscreen();
	void RenderWindow(const sf::Drawable& drawable);
	void CreateWindow();

private:
	void SetupWindow(const std::string& windowTitle, const sf::Vector2u& windowSize);	
	void SetFrameRate(const int fps);

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	sf::Vector2u m_initialWindowSize;
	sf::String m_windowTitle;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	bool m_isRunning;
	bool m_isFullscreen;
};