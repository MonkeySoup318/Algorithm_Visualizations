#pragma once

#include "ISortStrategy.hpp"

class MergeSort : public ISortStrategy {
public:
	virtual void Sort(ColumnManager* columnManager) override;
	virtual void DisplayInfo();

private:
	void ExecuteMergeSortAlgorithm(ColumnManager* columnManager);
	void MergeSortRecursion(ColumnManager* columnManager, int left, int right);
	void MergeSortedArrays(ColumnManager* columnManager, int left, int mid, int right);
	void PrintOLognInfo();
	void Render(ColumnManager* columnManager) const;

	int m_renderFrequency = 50;  // Render every 50 iterations
	int m_iterationCount = 0;
};
