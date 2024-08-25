#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>
#include <numeric>

#include "ColumnManager.hpp"

ColumnManager::ColumnManager(int columnsNumber, WindowManager *windowManager) {
	this->m_windowManager = windowManager;
	this->m_columnsNumber = columnsNumber;
	//columns.resize(columnsNumber);
	this->m_width = (windowManager->GetWindowSize().x * 1.0) / (columnsNumber * 1.0);
	this->m_originalWindowHeight = windowManager->GetInitialWindowSize().y;
	Generate(2456);
}

void ColumnManager::Generate(int sortType) {
	m_columns.clear();
	Create();
	SetMaxHeight();
	SetColorByHeight();
	Shuffle();
	Render(); // Render once after all initialization
}

void ColumnManager::Shuffle() {
	srand(time(NULL));
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_columns.begin(), m_columns.end(), g);
}

void ColumnManager::Swap(int index1, int index2) {
	std::iter_swap(m_columns.begin() + index1, m_columns.begin() + index2);
}

void ColumnManager::Highlight(int index1, int index2) {
	sf::Color color_index1 = m_columns[index1].getFillColor();
	sf::Color color_index2 = m_columns[index2].getFillColor();
	m_columns[index1].setFillColor(sf::Color::Red);
	m_columns[index2].setFillColor(sf::Color::Red);
	m_columns[index1].setFillColor(color_index1);
	m_columns[index2].setFillColor(color_index2);
}

void ColumnManager::Highlight(int index) {
	sf::Color color = m_columns[index].getFillColor();
	m_columns[index].setFillColor(sf::Color::Green);
	Render();
	m_windowManager->UpdateWindow();
}

void ColumnManager::HighlightAll() {
	for (int index = 0; index < GetNumber(); index++) {
		m_columns[index].setFillColor(sf::Color::Green);
	}
}

void ColumnManager::RenderAsync() {
	sf::Context context;
	std::thread renderThread(&ColumnManager::Render, this);
	renderThread.join();
}

void ColumnManager::Render() {
	m_windowManager->ClearWindow();
	for (int i = 0; i < m_columnsNumber; i++) {
		double posX = m_width * i;
		m_columns[i].setPosition(posX, m_originalWindowHeight - m_columns[i].getSize().y);
		m_windowManager->RenderWindow(m_columns[i]);
	}
	m_windowManager->DisplayWindow();
}

std::vector<sf::RectangleShape> ColumnManager::GetColumns() {
	return m_columns;
}

int ColumnManager::GetNumber() const {
	return m_columnsNumber;
}

int ColumnManager::GetValue(int index) {
	return m_columns[index].getSize().y;
}

int ColumnManager::GetValueR(int index) {
	// Unused
	return 0;
}

void ColumnManager::SetValue(int index, int value) {
	m_columns[index].setSize(sf::Vector2f(m_width, value));
	m_columns[index].setPosition(0, m_windowManager->GetWindowSize().y - value);
	UpdateMaxHeight(value);
	SetColorByHeight(index);
}

void ColumnManager::SetMaxHeight() {
	for (const auto& column : m_columns) {
		m_maxHeight = std::max(m_maxHeight, static_cast<int>(column.getSize().y));
	}
}

void ColumnManager::UpdateMaxHeight(int newHeight) {
	m_maxHeight = std::max(m_maxHeight, newHeight);
}

void ColumnManager::SetColorByHeight() {
	for (auto& column : m_columns) {
		float normalizedHeight = static_cast<float>(column.getSize().y) / m_maxHeight;
		sf::Uint8 red = static_cast<sf::Uint8>(normalizedHeight * 255);
		sf::Uint8 blue = static_cast<sf::Uint8>((1.0f - normalizedHeight) * 255);
		sf::Uint8 green = static_cast<sf::Uint8>(normalizedHeight * 255);
		column.setFillColor(sf::Color(red, green, blue));
	}
}

void ColumnManager::SetColorByHeight(int index) {
	float normalizedHeight = static_cast<float>(m_columns[index].getSize().y) / m_maxHeight;
	sf::Uint8 red = static_cast<sf::Uint8>(normalizedHeight * 255);
	sf::Uint8 blue = static_cast<sf::Uint8>((1.0f - normalizedHeight) * 255);
	sf::Uint8 green = static_cast<sf::Uint8>(normalizedHeight * 255);
	m_columns[index].setFillColor(sf::Color(red, green, blue));
}

void ColumnManager::Create() {
	for (int i = 0; i < m_columnsNumber; i++) {
		sf::RectangleShape column;
		m_columns.push_back(column);
		double ratio = (m_originalWindowHeight * 1.0) / (m_columnsNumber * 1.0);
		double height = ratio * (i + 1);
		m_columns[i].setSize(sf::Vector2f(m_width, height));
		m_columns[i].setPosition(0, m_originalWindowHeight - height);
		if (this->m_width > 10) {
			m_columns[i].setOutlineThickness(1);
			m_columns[i].setOutlineColor(sf::Color::Black);
		}
		m_columns[i].setFillColor(sf::Color::White);
	}
}