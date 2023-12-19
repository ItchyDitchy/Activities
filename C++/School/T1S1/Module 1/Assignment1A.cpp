#include <iostream>
#include <string>
using namespace std;

void countDigits() {
    int number;
    cout << "What number would you like to check for?\n- Non-positive\n- Digit length\nNumber: ";
    cin >> number;
    cout << "\nYour number is a " << (number > 0 ? "positive" : "non-positive") << " number.\n";
    string sNumber = to_string(number);
    cout << "Your number has a length of " << (sNumber.length() - (sNumber.find("-") != sNumber.npos ? 1 : 0));
}

int main() {
    countDigits();
    return 0;
}