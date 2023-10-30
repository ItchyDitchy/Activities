#include <iostream>

using namespace std;

int main() {
    int initial, terminal;
    cout << "Enter initial value: ";
    cin >> initial;
    cout << "Enter terminal value: ";
    cin >> terminal;

    if (initial <= terminal) {
        cout << "Numbers in the range divisible by 5:\n";
        do {
            if (initial % 5 == 0)
                cout << initial << " ";
            initial++;
        } while (initial <= terminal);
    } else {
        cout << "Invalid entry.";
    }
}