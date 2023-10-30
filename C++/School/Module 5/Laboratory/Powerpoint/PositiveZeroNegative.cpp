#include <iostream>

using namespace std;

int main() {
    int no;
    cout << "Enter a number: ";
    cin >> no;
    if (no > 0)
        cout << "It is positive.";
    else if (no < 0)
        cout << "It is negative.";
    else
        cout << "It is zero.";
    return 0;
}