#include <iostream>

using namespace std;

int main() {
    int no;
    cout << "Enter a number: ";
    cin >> no;
    if (no % 2 == 0)
        cout << "It is even.";
    else
        cout << "It is odd.";
    return 0;
}