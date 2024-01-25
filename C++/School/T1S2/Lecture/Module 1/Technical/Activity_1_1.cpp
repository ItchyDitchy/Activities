#include <iostream>
#include <string>
#include <cmath>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int modulo(int a, int b);
int power(int a, int b);

int main() {
    int choice = 0;
    int a = 0;
    int b = 0;
    do {
        system("cls");
        std::cout << "What operation would you like to do?\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Modulo\n";
        std::cout << "5. Power\n";
        std::cin >> choice;
    } while (1 > choice || choice > 5);
    system("cls");
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    int c;
    switch (choice) {
        case 1:
            c = add(a, b);
            break;
        case 2:
            c = subtract(a, b);
            break;
        case 3:
            c = multiply(a, b);
            break;
        case 4:
            c = modulo(a, b);
            break;
        case 5:
            c = power(a, b);
            break;
    }

    std::string choices[5] = {"sum", "difference", "product", "remainder", "exponentiate"};
    std::cout << "The " << choices[choice-1] << " is " << c;
    return 0;
}

int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
int modulo(int a, int b) {
    return a % b;
}
int power(int a, int b) {
    return std::pow(a, b);
}