#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a menu item (either a main menu or submenu)
class MenuItem {
public:
    string name;            // Name of the menu item
    vector<MenuItem> subMenu; // Submenus that are part of this menu item

    // Constructor to initialize a menu item with its name
    MenuItem(string itemName) : name(itemName) {}

    // Function to add a submenu to the current menu item
    void addSubMenu(MenuItem menu) {
        subMenu.push_back(menu);
    }
};

// Class to represent the menu structure
class Menu {
private:
    vector<MenuItem> menuItems; // List of items in the current menu
    int currentLevel = 0; // Keeps track of the current menu level (0 for main menu)

public:
    // Function to add a menu item to the main menu
    void addMenuItem(MenuItem item) {
        menuItems.push_back(item);
    }

    // Function to display the current menu
    void displayMenu() {
        cout << "Current Menu: \n";
        for (int i = 0; i < menuItems.size(); i++) {
            cout << i + 1 << ". " << menuItems[i].name << "\n";
        }
    }

    // Navigate down into the submenu (if available)
    void navigateDown(int selection) {
        if (selection >= 1 && selection <= menuItems.size()) {
            cout << "Entering: " << menuItems[selection - 1].name << "\n";
            currentLevel++;
        } else {
            cout << "Invalid selection.\n";
        }
    }

    // Go back to the previous menu
    void goBack() {
        if (currentLevel > 0) {
            cout << "Going back to the main menu...\n";
            currentLevel--;
        }
    }

    // Function to handle user interactions with the menu
    void interact() {
        int choice;
        while (true) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                navigateDown(choice);
            } else if (choice == 2) {
                goBack();
            } else {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
};

int main() {
    // Create the main menu
    Menu mainMenu;

    // Add main menu items with submenus
    MenuItem settings("Settings");
    settings.addSubMenu(MenuItem("Display Settings"));
    settings.addSubMenu(MenuItem("Audio Settings"));

    MenuItem media("Media");
    media.addSubMenu(MenuItem("Radio"));
    media.addSubMenu(MenuItem("Bluetooth Audio"));

    // Add menu items to the main menu
    mainMenu.addMenuItem(settings);
    mainMenu.addMenuItem(media);

    // Start the menu interaction
    mainMenu.interact();

    return 0;
}
