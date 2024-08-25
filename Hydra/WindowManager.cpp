#include "WindowManager.hpp"

WindowManager::WindowManager(const std::string& windowTitle, const sf::Vector2u& windowSize) {
	SetupWindow(windowTitle, windowSize);
}

WindowManager::~WindowManager() {
	DestroyWindow();
}

void WindowManager::ClearWindow() {
	this->m_window.clear(sf::Color::Black);
}

void WindowManager::DisplayWindow() {
	m_window.display();
}

void WindowManager::UpdateWindow() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isRunning = false;
			std::exit(1);
		} 
		else if (event.type == sf::Event::Resized) {
			if (GetWindowSize().x < 400 || GetWindowSize().y < 250) {
				SetWindowSize(sf::Vector2u(400, 250));
			}				
		}
	}
}

bool WindowManager::IsRunning() const {
	return this->m_isRunning;
}

bool WindowManager::IsFullscreen() const {
	return this->m_isFullscreen;
}

sf::Vector2u WindowManager::GetWindowSize() const {
	return this->m_window.getSize();
}

sf::Vector2u WindowManager::GetInitialWindowSize() const {
	return this->m_initialWindowSize;
}

sf::RenderWindow *WindowManager::GetRenderWindow() {
	return &(this->m_window);
}

sf::Time WindowManager::GetElapsed() const {
	return this->m_elapsed;
}

void WindowManager::RestartClock() {
	this->m_elapsed = m_clock.restart();
}

void WindowManager::SetWindowSize(sf::Vector2u size) {
	this->m_window.setSize(sf::Vector2u(size));
}

void WindowManager::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	DestroyWindow();
	CreateWindow();
}

void WindowManager::RenderWindow(const sf::Drawable& drawable) {
	m_window.draw(drawable);
}

void WindowManager::SetupWindow(const std::string& windowTitle, const sf::Vector2u& windowSize) {
	m_windowTitle = windowTitle;
	m_initialWindowSize = windowSize;
	m_windowSize = windowSize;
	m_isFullscreen = false;
	m_isRunning = true;
}

void WindowManager::DestroyWindow() {
	m_isRunning = false;
	m_window.close();
}

void WindowManager::CreateWindow() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create( { m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style );
	m_window.setFramerateLimit(144);
	m_window.setVerticalSyncEnabled(true);
}

void WindowManager::SetFrameRate(const int fps) {
	m_window.setFramerateLimit(fps);
}
