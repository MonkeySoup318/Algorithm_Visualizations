#include "SortCommands.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "Sorter.hpp"

//**********************************************
//
//  Concrete commands for User Menu
//
//**********************************************

void SelectOptionCommand::Execute() {
    m_menu->SelectOption(m_option);
}

void GoBackCommand::Execute() {
    m_menu->SelectGoBack();
}

void ExitCommand::Execute() {
    std::exit(1);
}

//**********************************************
//
//  Concrete commands for Sorting Algorithms
//
//**********************************************

void BubbleSortCommand::Execute() {
    m_columnManager->Shuffle();
    BubbleSort bubbleSort;
    Sorter sortingAlgorithm(&bubbleSort);
    sortingAlgorithm.DisplayInfo();
    sortingAlgorithm.Sort(m_columnManager);
}

void QuickSortCommand::Execute() {
    m_columnManager->Shuffle();
    QuickSort quickSort;
    Sorter sortingAlgorithm(&quickSort);
    sortingAlgorithm.DisplayInfo();
    sortingAlgorithm.Sort(m_columnManager);
}

void SelectionSortCommand::Execute() {
    m_columnManager->Shuffle();
    SelectionSort selectionSort;
    Sorter sortingAlgorithm(&selectionSort);
    sortingAlgorithm.DisplayInfo();
    sortingAlgorithm.Sort(m_columnManager);
}

void InsertionSortCommand::Execute() {
    m_columnManager->Shuffle();
    InsertionSort insertionSort;
    Sorter sortingAlgorithm(&insertionSort);
    sortingAlgorithm.DisplayInfo();
    sortingAlgorithm.Sort(m_columnManager);
}

void MergeSortCommand::Execute() {
    m_columnManager->Shuffle();
    MergeSort mergeSort;
    Sorter sortingAlgorithm(&mergeSort);
    sortingAlgorithm.DisplayInfo();
    sortingAlgorithm.Sort(m_columnManager);
}