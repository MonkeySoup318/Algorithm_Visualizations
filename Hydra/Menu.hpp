#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include "ICommand.hpp"

class Menu {
public:
	enum struct MenuOption {
		Exit,
		BubbleSort,
		QuickSort,
		InsertionSort,
		MergeSort,
		SelectionSort,
		Invalid
	};

public:
	Menu(std::string name, Menu* parent = nullptr);
	~Menu();

	void AddChild(std::string name, Menu* child);
	void Display();
	void ClearMenu();
	std::string GetName() const;
	Menu* GetParent();
	Menu* SelectOption(int option);
	void SelectGoBack();
	Menu* SelectionHandler(int option);

private:
	std::string m_name;
	std::map<std::string, Menu*> m_children;
	Menu* m_parent;
};

#endif // MENU_H