#include <iostream>

int main() {
    double num1 = 0, num2 = 0;
    
    while (num1 == 0) {
        std::cout << "Enter 1st number: ";
        std::cin >> num1;
    }

    while (num2 == 0) {
        std::cout << "Enter 2nd number: ";
        std::cin >> num2;
    }

    std::cout << "Product: " << num1 * num2;
    return 0;
}