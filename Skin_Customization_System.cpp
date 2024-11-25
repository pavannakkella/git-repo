#include <iostream>
#include <string>
#include <map>

using namespace std;

// Class to represent a theme
class Theme {
private:
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;

public:
    // Constructor to initialize a theme
    Theme(const string& bgColor, const string& fColor, int fSize, const string& iStyle)
        : backgroundColor(bgColor), fontColor(fColor), fontSize(fSize), iconStyle(iStyle) {}

    // Method to apply and display the theme details
    void displayTheme() const {
        cout << "Background Color: " << backgroundColor << endl;
        cout << "Font Color: " << fontColor << endl;
        cout << "Font Size: " << fontSize << endl;
        cout << "Icon Style: " << iconStyle << endl;
    }

    // Method to get a preview of the theme as a string
    string getThemePreview() const {
        return backgroundColor + " background, " + fontColor + " font, Size " + to_string(fontSize) + "px, " + iconStyle + " icons";
    }
};

// Function to display available themes and allow user to select
void displayMenu(const map<string, Theme>& themes) {
    cout << "Select a theme:\n";
    int i = 1;
    for (const auto& theme : themes) {
        cout << i << ". " << theme.first << endl;
        ++i;
    }
}

// Main function to demonstrate theme switching
int main() {
    // Create themes
    Theme classic("White", "Black", 14, "Standard");
    Theme sport("Red", "White", 16, "Sport");
    Theme eco("Green", "Dark Gray", 12, "Minimal");

    // Store themes in a map using insert instead of operator[]
    map<string, Theme> themes;
    themes.insert({"Classic", classic});
    themes.insert({"Sport", sport});
    themes.insert({"Eco", eco});

    // Display available themes
    displayMenu(themes);

    // Ask the user to select a theme
    int choice;
    cout << "Enter the number of your choice: ";
    cin >> choice;

    // Validate the input
    if (choice < 1 || choice > themes.size()) {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    // Iterate to find the selected theme
    auto it = themes.begin();
    advance(it, choice - 1);

    // Display selected theme
    cout << "\nYou selected the " << it->first << " theme.\n";
    cout << "Preview: " << it->second.getThemePreview() << endl;
    cout << "\nApplying theme...\n";
    it->second.displayTheme();

    return 0;
}
