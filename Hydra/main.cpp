#include "Menu.hpp"
#include "WindowManager.hpp"
#include "ColumnManager.hpp"
#include "SortCommands.hpp"
#include "Invoker.hpp"

Menu* categories;
Menu* fractals;
Menu* sortingAlgorithms;
Menu* searchAlgorithms;
Menu* pathfindingAlgorithms;

bool algorithmSelected = false;
int userInput;

int COLUMNS_NUM = 5000;
std::string APP_NAME = "Algorithm Visualizer";
int WIN_X = 1920;
int WIN_Y = 1080;

static void InstantiateMenus(Menu& rootMenu) {
    categories = new Menu("Categories", &rootMenu);
    rootMenu.AddChild("Categories", categories);
    rootMenu.AddChild("Exit", &rootMenu);

    fractals = new Menu("Fractals", categories);
    fractals->AddChild("Dummy_1", new Menu("Dummy_1", fractals));
    fractals->AddChild("Dummy_2", new Menu("Dummy_2", fractals));
    fractals->AddChild("Dummy_3", new Menu("Dummy_3", fractals));
    categories->AddChild("Fractals", fractals);

    sortingAlgorithms = new Menu("Sorting Algorithms", categories);
    sortingAlgorithms->AddChild("Bubble Sort", new Menu("Bubble Sort", sortingAlgorithms));
    sortingAlgorithms->AddChild("Insertion Sort", new Menu("Insertion Sort", sortingAlgorithms));
    sortingAlgorithms->AddChild("Merge Sort", new Menu("Merge Sort", sortingAlgorithms));
    sortingAlgorithms->AddChild("Quick Sort", new Menu("Quick Sort", sortingAlgorithms));
    sortingAlgorithms->AddChild("Selection Sort", new Menu("Selection Sort", sortingAlgorithms));
    categories->AddChild("Sorting Algorithms", sortingAlgorithms);

    searchAlgorithms = new Menu("Search Algorithms", categories);
    searchAlgorithms->AddChild("Dummy_1", new Menu("Dummy_1", searchAlgorithms));
    searchAlgorithms->AddChild("Dummy_2", new Menu("Dummy_2", searchAlgorithms));
    searchAlgorithms->AddChild("Dummy_3", new Menu("Dummy_3", searchAlgorithms));
    categories->AddChild("Search Algorithms", searchAlgorithms);

    pathfindingAlgorithms = new Menu("Pathfinding Algorithms", categories);
    pathfindingAlgorithms->AddChild("Dummy_1", new Menu("Dummy_1", pathfindingAlgorithms));
    pathfindingAlgorithms->AddChild("Dummy_2", new Menu("Dummy_2", pathfindingAlgorithms));
    pathfindingAlgorithms->AddChild("Dummy_3", new Menu("Dummy_3", pathfindingAlgorithms));
    categories->AddChild("Pathfinding Algorithms", pathfindingAlgorithms);
}

static Menu::MenuOption StringToMenuOption(const std::string& str) {
    if (str == "Exit") return Menu::MenuOption::Exit;
    else if (str == "Bubble Sort") return Menu::MenuOption::BubbleSort;
    else if (str == "Quick Sort") return Menu::MenuOption::QuickSort;
    else if (str == "Insertion Sort") return Menu::MenuOption::InsertionSort;
    else if (str == "Merge Sort") return Menu::MenuOption::MergeSort;
    else if (str == "Selection Sort") return Menu::MenuOption::SelectionSort;
    else return Menu::MenuOption::Invalid;
}

static void InvokeCommand(Invoker& invoker, ICommand* command) {
    invoker.SetCommand(command);
    invoker.ExecuteCommand();
}

static void InvokeDestructorCommand(ICommand* command) {
    delete command;
}

static void ExecuteWindowRenderingLoop(WindowManager& windowManager, ColumnManager& columnManager) {
    while (windowManager.IsRunning()) {
        windowManager.UpdateWindow();
        columnManager.Render();
    }
}

static void RunVisualization(Invoker& invoker, ICommand* actionItemCommand, WindowManager& windowManager, ColumnManager& columnManager) {
    if (actionItemCommand != nullptr) {
        InvokeCommand(invoker, actionItemCommand);
        ExecuteWindowRenderingLoop(windowManager, columnManager);
        InvokeDestructorCommand(actionItemCommand);
    }
}

static void UserInputHandler(Menu& rootMenu) {
    Menu* currentMenu = &rootMenu;
    Menu* selectedItem = nullptr;
    WindowManager windowManager(APP_NAME, sf::Vector2u(WIN_X, WIN_Y));
    Invoker invoker;

    while (true) {       
        currentMenu->Display();
        std::cout << "Enter option: ";
        std::cin >> userInput;
        currentMenu = currentMenu->SelectionHandler(userInput);
        selectedItem = currentMenu;
        ICommand* actionItemCommand = nullptr;
        Menu::MenuOption option = StringToMenuOption(selectedItem->GetName());

        switch (option) {
        case Menu::MenuOption::Exit:
            actionItemCommand = new ExitCommand();
            InvokeCommand(invoker, actionItemCommand);
            break;
        case Menu::MenuOption::BubbleSort:
        case Menu::MenuOption::QuickSort:
        case Menu::MenuOption::InsertionSort:
        case Menu::MenuOption::MergeSort:
        case Menu::MenuOption::SelectionSort: {
            windowManager.CreateWindow();
            ColumnManager columnManager(COLUMNS_NUM, &windowManager);

            switch (option) {
            case Menu::MenuOption::BubbleSort:
                actionItemCommand = new BubbleSortCommand(&columnManager);
                break;
            case Menu::MenuOption::QuickSort:
                actionItemCommand = new QuickSortCommand(&columnManager);
                break;
            case Menu::MenuOption::InsertionSort:
                actionItemCommand = new InsertionSortCommand(&columnManager);
                break;
            case Menu::MenuOption::MergeSort:
                actionItemCommand = new MergeSortCommand(&columnManager);
                break;
            case Menu::MenuOption::SelectionSort:
                actionItemCommand = new SelectionSortCommand(&columnManager);
                break;
            default:
                break;
            }
            RunVisualization(invoker, actionItemCommand, windowManager, columnManager);
            break;
        }
        default: 
            // Handle invalid option
            std::cout << "Invalid option selected." << std::endl;
            break;
        }
    }
}

int main() {
    Menu rootMenu("Root");
    InstantiateMenus(rootMenu);
    UserInputHandler(rootMenu);

    return 0;
}