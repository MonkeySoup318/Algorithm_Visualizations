#include <cstdlib>
#include <chrono>

#include "MergeSort.hpp"

void MergeSort::DisplayInfo() {
    PrintOLognInfo();
}

void MergeSort::Sort(ColumnManager* columnManager) {
    ExecuteMergeSortAlgorithm(columnManager);
    columnManager->HighlightAll();
    columnManager->Render();  // Final render
}

void MergeSort::ExecuteMergeSortAlgorithm(ColumnManager* columnManager) {
    int left = 0;
    int right = columnManager->GetNumber() - 1;
    MergeSortRecursion(columnManager, left, right);
}

void MergeSort::MergeSortRecursion(ColumnManager* columnManager, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSortRecursion(columnManager, left, mid);
        MergeSortRecursion(columnManager, mid + 1, right);
        MergeSortedArrays(columnManager, left, mid, right);
    }
}

void MergeSort::MergeSortedArrays(ColumnManager* columnManager, int left, int mid, int right) {
    int max = columnManager->GetNumber();
    int* temp = new int[max];
    int leftIndex = left;
    int rightIndex = mid + 1;
    int tempIndex = left;

    while (leftIndex <= mid && rightIndex <= right) {
        columnManager->Highlight(leftIndex, rightIndex);
        if (columnManager->GetValue(leftIndex) <= columnManager->GetValue(rightIndex)) {
            temp[tempIndex] = columnManager->GetValue(leftIndex);
            leftIndex++;
        }
        else {
            temp[tempIndex] = columnManager->GetValue(rightIndex);
            rightIndex++;
        }
        tempIndex++;

        m_iterationCount++;
        Render(columnManager);
    }

    while (leftIndex <= mid) {
        columnManager->Highlight(leftIndex, mid);
        temp[tempIndex] = columnManager->GetValue(leftIndex);
        tempIndex++;
        leftIndex++;

        m_iterationCount++;
        Render(columnManager);
    }

    while (rightIndex <= right) {
        columnManager->Highlight(rightIndex, right);
        temp[tempIndex] = columnManager->GetValue(rightIndex);
        tempIndex++;
        rightIndex++;

        m_iterationCount++;
        Render(columnManager);
    }

    for (int i = left; i < tempIndex; i++) {
        columnManager->SetValue(i, temp[i]);
        m_iterationCount++;
        Render(columnManager);
    }

    delete[] temp;
}

void MergeSort::Render(ColumnManager* columnManager) const {
    if (m_iterationCount % m_renderFrequency == 0) {
        columnManager->Render();
        //std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Adjust delay as needed
    }
}

void MergeSort::PrintOLognInfo() {
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
