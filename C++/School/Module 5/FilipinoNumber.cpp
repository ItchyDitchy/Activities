#include <iostream>

using namespace std;

int main() {
    int no;
    cout << "Enter a number: ";
    cin >> no;
    switch (no) {
        case 1:
            cout << "Isa";
            break;
        case 2:
            cout << "Dalawa";
            break;
        case 3:
            cout << "Tatlo";
            break;
        default:
            cout << "Invalid input";
    }
    return 0;
}