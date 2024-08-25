#pragma once

#include "ISortStrategy.hpp"

class SelectionSort : public ISortStrategy {
public:
	virtual void Sort(ColumnManager* columnManager) override;
	virtual void DisplayInfo();

private:
	void ExecuteSelectionSortAlgorithm(ColumnManager* columnManager);
	void PrintOLognInfo();

	void Render(ColumnManager* columnManager) const;

	int m_renderFrequency = 5;  // Render every 5 iterations
	int m_iterationCount = 0;
};
