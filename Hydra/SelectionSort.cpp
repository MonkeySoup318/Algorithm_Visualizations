#include <cstdlib>

#include "SelectionSort.hpp"

void SelectionSort::Sort(ColumnManager* columnManager) {
	ExecuteSelectionSortAlgorithm(columnManager);
	columnManager->Render();
}

void SelectionSort::DisplayInfo() {
	PrintOLognInfo();
}

void SelectionSort::ExecuteSelectionSortAlgorithm(ColumnManager* columnManager) {
	int length = columnManager->GetNumber();
	for (int i = 0; i < length; i++) {
		int minPosition = i;
		for (int j = i + 1; j < length; j++) {
			columnManager->Highlight(j, minPosition);
			if (columnManager->GetValue(j) < columnManager->GetValue(minPosition)) {
				minPosition = j;
			}
		}
		if (minPosition != i) {
			columnManager->Swap(i, minPosition);
		}
		m_iterationCount++;
		Render(columnManager);
	}
	columnManager->HighlightAll();
}

void SelectionSort::PrintOLognInfo() {
	system("cls");
	std::cout << "Name: " << "" << std::endl;
	std::cout << "Class: " << "" << std::endl;
	std::cout << "Data structure: " << "" << std::endl;
	std::cout << "Worst-case perf:" << "" << std::endl;
	std::cout << "Best-case perf: " << "" << std::endl;
	std::cout << "Avg. perf: " << "" << std::endl;
	std::cout << "Worst-case OLogn: " << "" << std::endl;
	std::cout << "Optimal: " << std::endl;
}

void SelectionSort::Render(ColumnManager* columnManager) const {
	if (m_iterationCount % m_renderFrequency == 0) {
		columnManager->Render();
		// Adjust delay as needed
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));  
	}
}
