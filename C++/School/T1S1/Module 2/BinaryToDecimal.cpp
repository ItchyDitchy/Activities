#include <iostream>
using namespace std;

int main() {
 int decimal = 0, binary = 0, remainder = 0, product = 1;
    cout << "BINARY TO DECIMAL CONVERSION" << endl;
    cout << endl;
    cout << "Enter a number: ";
    cin >> binary;
    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * product;
        product *= 2;
        binary /= 10;
    }
    cout << "The number in decimal form is: " << decimal;
}