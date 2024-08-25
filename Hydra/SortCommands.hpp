#pragma once

#include "ICommand.hpp"
#include "ColumnManager.hpp"
#include "Menu.hpp"

//**********************************************
//
//  Concrete commands for User Menu
//
//**********************************************

// Concrete command for selecting menu items
class SelectOptionCommand : public ICommand {
public:
    SelectOptionCommand(Menu* menu, int option) : m_menu(menu), m_option(option) {}
    void Execute() override;

private:
    Menu* m_menu;
    int m_option;
};

// Concrete command for selecting the back option
class GoBackCommand : public ICommand {
public:
    GoBackCommand(Menu* menu, int option) : m_menu(menu), m_option(option) {}
    void Execute() override;

private:
    Menu* m_menu;
    int m_option;
};

// Concrete command for selecting the exit option
class ExitCommand : public ICommand {
public:
    ExitCommand() {}
    void Execute() override;

};

//**********************************************
//
//  Concrete commands for Sorting Algorithms
//
//**********************************************

// Concrete command for bubble sort
class BubbleSortCommand : public ICommand {
public:
    BubbleSortCommand(ColumnManager* cm) : m_columnManager(cm) {}
    void Execute() override;

private:
    ColumnManager* m_columnManager;
};

// Concrete command for quick sort
class QuickSortCommand : public ICommand {
public:
    QuickSortCommand(ColumnManager* cm) : m_columnManager(cm) {}
    void Execute() override;

private:
    ColumnManager* m_columnManager;
};

// Concrete command for selection sort
class SelectionSortCommand : public ICommand {
public:
    SelectionSortCommand(ColumnManager* cm) : m_columnManager(cm) {}
    void Execute() override;

private:
    ColumnManager* m_columnManager;
};

// Concrete command for insertion sort
class InsertionSortCommand : public ICommand {
public:
    InsertionSortCommand(ColumnManager* cm) : m_columnManager(cm) {}
    void Execute() override;

private:
    ColumnManager* m_columnManager;
};

// Concrete command for merge sort
class MergeSortCommand : public ICommand {
public:
    MergeSortCommand(ColumnManager* cm) : m_columnManager(cm) {}
    void Execute() override;

private:
    ColumnManager* m_columnManager;
};

