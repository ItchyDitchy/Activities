#include <iostream>
using namespace std;

float arithmeticOperation(float number1, float number2, string operator) {
    
}

int main() {
    float number1, number2;
    string sOperator;
    string splitNumbers;
    cout << "Enter two numbers (e.g. \"1 2\"): ";
    cin >> splitNumbers;
    while (number1 == null || number2 == null) {

    }
    while (sOperator != "+" && sOperator != "-" && sOperator != "*" && sOperator != "/") {
        cout << "You did not enter a valid operator.\nEnter the operator(+, -, *, /) : ";
    }
    cout << "The result of the operation is : " << arithmeticOperation(number1, number2, sOperator);
    return 0;
}