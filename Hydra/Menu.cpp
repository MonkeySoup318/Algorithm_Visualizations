#include "Menu.hpp"

Menu::Menu(std::string name, Menu* parent) : m_name(name), m_parent(parent) {}

Menu::~Menu() {
	for (auto& child : m_children) {
		delete child.second;
	}
}

void Menu::AddChild(std::string name, Menu* child) {
    m_children[name] = child;
}

void Menu::Display() {
    ClearMenu();
    int count = 1;
    std::cout << "====================================" << std::endl;
    std::cout << "\t" << m_name << std::endl;
    std::cout << "====================================" << std::endl;
    for (auto& child : m_children) {
        std::cout << "[ " << count << " ] " << child.first << std::endl;
        count++;
    }
    if (m_parent != nullptr) {
        std::cout << "[ " << count << " ] " << "Back" << std::endl;
    }   
    std::cout << std::endl;
}

void Menu::ClearMenu() {
    system("cls");
}

std::string Menu::GetName() const {
    return m_name;
}

Menu* Menu::GetParent() {
    return m_parent;
}

Menu* Menu::SelectOption(int option) {
    auto iter = m_children.begin();
    std::advance(iter, option - 1);
    return iter->second;
}

void Menu::SelectGoBack() {
    GetParent();
}

Menu* Menu::SelectionHandler(int option) {
    if (option > 0 && option <= m_children.size()) {
        // Node or Leaf regulars
        SelectOption(option);
    } 
    else if (option > 0 && option == m_children.size() + 1 && m_parent != nullptr) {
        // Back Leaf
        SelectGoBack();
    }
    else {
        std::cout << "Invalid user input" << std::endl;
        return this;
    }
}
