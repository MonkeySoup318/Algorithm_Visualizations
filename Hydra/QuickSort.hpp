#pragma once

#include "ISortStrategy.hpp"

class QuickSort : public ISortStrategy {
public:
	virtual void Sort(ColumnManager* columnManager) override;
	virtual void DisplayInfo();

private:
	void ExecuteQuickSortAlgorithm(ColumnManager* columnManager);
	void QuickSortRecursion(ColumnManager* columnManager, int min, int max);
	int Partition(ColumnManager* columnManager, int min, int max);
	void PrintOLognInfo();

	void Render(ColumnManager* columnManager) const;

	int m_renderFrequency = 100;  // Render every 5 iterations
	int m_iterationCount = 0;
};
