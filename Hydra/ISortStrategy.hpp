#pragma once

#include "ColumnManager.hpp"

class ISortStrategy {
public:
	virtual ~ISortStrategy() = default;
	virtual void Sort(ColumnManager* columnManager) = 0;
	virtual void DisplayInfo() = 0;
};

