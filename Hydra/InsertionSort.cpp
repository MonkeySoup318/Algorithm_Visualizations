#include <cstdlib>

#include "InsertionSort.hpp"

void InsertionSort::Sort(ColumnManager* columnManager) {
	ExecuteInsertionSortAlgorithm(columnManager);
}

void InsertionSort::DisplayInfo() {
	PrintOLognInfo();
}

void InsertionSort::ExecuteInsertionSortAlgorithm(ColumnManager* columnManager) {
	int length = columnManager->GetNumber();
	for (int i = 1; i < length; i++) {
		int j = i - 1;
		while (j >= 0 && columnManager->GetValue(j) > columnManager->GetValue(j + 1)) {
			columnManager->Highlight(j, i);
			columnManager->Swap(j, j + 1);
			j = j - 1;
			m_iterationCount++;
			Render(columnManager);
		}
		m_iterationCount++;
		//Render(columnManager);
	}
	columnManager->HighlightAll();
}

void InsertionSort::PrintOLognInfo() {
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

void InsertionSort::Render(ColumnManager* columnManager) const {
	if (m_iterationCount % m_renderFrequency == 0) {
		columnManager->Render();
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Adjust delay as needed
	}
}
