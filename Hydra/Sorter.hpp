#pragma once

#include "ISortStrategy.hpp"

class Sorter {
public:
	Sorter(ISortStrategy* strategy) : strategy(strategy) {}

	void Sort(ColumnManager* columnManager) {
		strategy->Sort(columnManager);
	}

	void DisplayInfo() {
		strategy->DisplayInfo();
	}

private:
	ISortStrategy* strategy;
};
