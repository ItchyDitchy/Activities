#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int magic, guess = 0;
    magic = rand();
    cout << "Enter your guess: ";
    cin >> guess;
    if (guess == magic) {
        cout << "You're right. \n";
        cout << magic << " is the magic number";
    } else {
        cout << "Sorry, you're wrong.\n";
    }
    return 0;
}