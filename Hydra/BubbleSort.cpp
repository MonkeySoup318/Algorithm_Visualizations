#include <cstdlib>

#include "BubbleSort.hpp"

void BubbleSort::Sort(ColumnManager* columnManager) {
	ExecuteBubbleSortAlgorithm(columnManager);
	columnManager->Render();
}

void BubbleSort::DisplayInfo() {
	PrintOLognInfo();
}

void BubbleSort::ExecuteBubbleSortAlgorithm(ColumnManager* columnManager) {
	bool swapped;
	int i = 0;
	do {
		swapped = false;
		for (int j = 0; j < columnManager->GetNumber() - 1 - i; j++) {
			if (columnManager->GetValue(j) > columnManager->GetValue(j + 1)) {
				columnManager->Swap(j, j + 1);
				columnManager->Highlight(j, j + 1);
				swapped = true;
			}
		}
		i++;
		m_iterationCount++;
		Render(columnManager);
	} while (swapped);
	columnManager->HighlightAll();
}

void BubbleSort::PrintOLognInfo() {
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

void BubbleSort::Render(ColumnManager* columnManager) const {
	if (m_iterationCount % m_renderFrequency == 0) {
		columnManager->Render();
		// Adjust delay as needed
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));  
	}
}
