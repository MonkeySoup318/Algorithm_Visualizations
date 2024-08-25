#pragma once

#include <thread>
#include <future>

#include "WindowManager.hpp"

class ColumnManager {
public:
	ColumnManager(int columnsNumber, WindowManager *windowManager);

	void Shuffle();
	void Swap(int index1, int index2);
	void Highlight(int index1, int index2);
	void Highlight(int index);
	void HighlightAll();
	void RenderAsync();
	void Render();
	std::vector<sf::RectangleShape> GetColumns();
	int GetNumber() const;
	int GetValue(int index);
	int GetValueR(int index);
	void SetValue(int index, int value);

	void SetMaxHeight();
	void UpdateMaxHeight(int newHeight);

	void SetColorByHeight();
	void SetColorByHeight(int index);

private:
	void Generate(int sortType);
	void Create();
	

	int m_columnsNumber;
	double m_width;
	int m_maxHeight;
	int m_originalWindowHeight;
	WindowManager* m_windowManager;
	std::vector<sf::RectangleShape> m_columns;
};
