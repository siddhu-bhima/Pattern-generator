#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Function to center-align a string within a given width
void printCentered(string text, int width) {
    int padding = (width - text.length()) / 2;
    cout << string(padding, ' ') << text << string(padding, ' ') << endl;
}

// Function for animated printing of a line
void animatedPrint(string line, int delay = 100) {
    for (char c : line) {
        cout << c;
        sleep_for(milliseconds(delay / line.length()));
    }
    cout << endl;
}

// Function to generate a right-aligned triangle
void generateTriangle(int size, char symbol) {
    cout << "\nRight-Aligned Triangle:\n";
    for (int i = 1; i <= size; i++) {
        animatedPrint(string(size - i, ' ') + string(i, symbol));
    }
}

// Function to generate a centered pyramid
void generatePyramid(int size, char symbol) {
    cout << "\nCentered Pyramid:\n";
    for (int i = 1; i <= size; i++) {
        animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
    }
}

// Function to generate a diamond
void generateDiamond(int size, char symbol) {
    cout << "\nDiamond:\n";
    // Upper half
    for (int i = 1; i <= size; i++) {
        animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
    }
    // Lower half
    for (int i = size - 1; i >= 1; i--) {
        animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
    }
}

// Function to generate an inverted right-aligned triangle
void generateInvertedTriangle(int size, char symbol) {
    cout << "\nInverted Right-Aligned Triangle:\n";
    for (int i = size; i >= 1; i--) {
        animatedPrint(string(size - i, ' ') + string(i, symbol));
    }
}

// Function to generate a hollow pyramid
void generateHollowPyramid(int size, char symbol) {
    cout << "\nHollow Pyramid:\n";
    for (int i = 1; i <= size; i++) {
        if (i == 1 || i == size)
            animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
        else
            animatedPrint(string(size - i, ' ') + symbol + string(2 * i - 3, ' ') + symbol);
    }
}

// Function to generate a hollow diamond
void generateHollowDiamond(int size, char symbol) {
    cout << "\nHollow Diamond:\n";
    // Upper half
    for (int i = 1; i <= size; i++) {
        if (i == 1 || i == size)
            animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
        else
            animatedPrint(string(size - i, ' ') + symbol + string(2 * i - 3, ' ') + symbol);
    }
    // Lower half
    for (int i = size - 1; i >= 1; i--) {
        if (i == 1 || i == size)
            animatedPrint(string(size - i, ' ') + string(2 * i - 1, symbol));
        else
            animatedPrint(string(size - i, ' ') + symbol + string(2 * i - 3, ' ') + symbol);
    }
}

int main() {
    int size, choice;
    char continueChoice, symbol;

    do {
        // Clear console (optional, works on Windows, use "clear" for Unix)
        system("cls");

        // Display title
        printCentered("=== Pattern Generator ===", 30);
        cout << endl;

        // Get pattern size
        cout << "Enter the size of the pattern (1-20): ";
        cin >> size;
        if (size < 1 || size > 20) {
            cout << "Invalid size! Please enter a number between 1 and 20.\n";
            continue;
        }

        // Get character for pattern
        cout << "Enter the character for the pattern: ";
        cin >> symbol;

        // Display menu
        cout << "\nSelect a pattern:\n";
        cout << "1. Right-Aligned Triangle\n";
        cout << "2. Centered Pyramid\n";
        cout << "3. Diamond\n";
        cout << "4. Inverted Right-Aligned Triangle\n";
        cout << "5. Hollow Pyramid\n";
        cout << "6. Hollow Diamond\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Generate selected pattern
        switch (choice) {
            case 1:
                generateTriangle(size, symbol);
                break;
            case 2:
                generatePyramid(size, symbol);
                break;
            case 3:
                generateDiamond(size, symbol);
                break;
            case 4:
                generateInvertedTriangle(size, symbol);
                break;
            case 5:
                generateHollowPyramid(size, symbol);
                break;
            case 6:
                generateHollowDiamond(size, symbol);
                break;
            default:
                cout << "\nInvalid choice! Please select a number between 1 and 6.\n";
                break;
        }

        // Ask to continue
        cout << "\nGenerate another pattern? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Thank you for using Pattern Generator!\n";
    return 0;
}
