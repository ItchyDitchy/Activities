#include <iostream>

using namespace std;

int main() {
    char opt;
    cout << "MENU OF SHAPES\n";
    cout << "S - Square\n";
    cout << "R - Rectangle\n";
    cout << "C - Circle\n";
    cout << "Enter your choice: ";
    cin >> opt;
    switch (opt) {
        case 'S':
        case 's':
            cout << "You chose square.";
            break;
        case 'R':
        case 'r':
            cout << "You picked rectangle.";
            break;
        case 'C':
        case 'c':
            cout << "You selected circle.";
            break;
        default:
            cout << "Invalid entry.";
    }
    return 0;
}