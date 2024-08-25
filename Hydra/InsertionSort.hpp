#pragma once

#include "ISortStrategy.hpp"

class InsertionSort : public ISortStrategy {
public:
	virtual void Sort(ColumnManager* columnManager) override;
	virtual void DisplayInfo();

private:
	void ExecuteInsertionSortAlgorithm(ColumnManager* columnManager);
	void PrintOLognInfo();

	void Render(ColumnManager* columnManager) const;

	int m_renderFrequency = 1000;  // Render every 5 iterations
	int m_iterationCount = 0;
};