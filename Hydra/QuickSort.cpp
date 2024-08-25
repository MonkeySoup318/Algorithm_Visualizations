#include <cstdlib>

#include "QuickSort.hpp"

void QuickSort::Sort(ColumnManager* columnManager) {
    ExecuteQuickSortAlgorithm(columnManager);
}

void QuickSort::DisplayInfo() {
    PrintOLognInfo();
}

void QuickSort::ExecuteQuickSortAlgorithm(ColumnManager* columnManager) {
    int min = 0;
    int max = columnManager->GetNumber() - 1;
    QuickSortRecursion(columnManager, min, max);
    columnManager->HighlightAll();
    columnManager->Render();
}

void QuickSort::QuickSortRecursion(ColumnManager* columnManager, int min, int max) {
    if (min < max) {
		int pivot = Partition(columnManager, min, max);
		QuickSortRecursion(columnManager, min, pivot-1);
		QuickSortRecursion(columnManager, pivot+1, max);     
	}  
}

int QuickSort::Partition(ColumnManager* columnManager, int min, int max) {
    double pivot = columnManager->GetValue(max);
    int i = min-1;
    for (int j = min; j < max; ++j) {     
        double currentValue = columnManager->GetValue(j);
        columnManager->Highlight(j, max);
        if (currentValue <= pivot) {
            i++;
            columnManager->Swap(i, j);  
        }
        m_iterationCount++;
        Render(columnManager);      
    }
    columnManager->Swap(i + 1, max);
    return i+1;
}

void QuickSort::PrintOLognInfo() {
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

void QuickSort::Render(ColumnManager* columnManager) const {
    if (m_iterationCount % m_renderFrequency == 0) {
        columnManager->Render();
        //std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Adjust delay as needed
    }
}
