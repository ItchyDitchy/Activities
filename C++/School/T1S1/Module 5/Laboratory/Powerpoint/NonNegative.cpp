#include <iostream>

using namespace std;

int main() {
    int no;
    cout << "Enter a number: ";
    cin >> no;
    if (no >= 0)
        cout << "It is a non negative integer.";
    else
        cout << "It is a negative integer.";
    return 0;
}