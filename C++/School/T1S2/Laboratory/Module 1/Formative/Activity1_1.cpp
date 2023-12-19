#include <iostream>
#include <iomanip>

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
int modulus(int num1, int num2);

int main() {
    char repeat = 'y';

    do {
        std::cout << "=====================================================================\n";
        std::cout << "\t\t\t\tMENU\n";
        std::cout << "=====================================================================\n";
        std::cout << "\t1. Add\n";
        std::cout << "\t2. Subtract\n";
        std::cout << "\t3. Multiply\n";
        std::cout << "\t4. Divide\n";
        std::cout << "\t5. Modulus\n";

        int choice = 0;
        do {
            std::cout << "Enter your choice(1-5): ";
            std::cin >> choice;
        } while (1 > choice || choice > 5);

        int num1;
        int num2;

        do {
            std::cout << "Enter your two integer numbers: ";
            std::cin >> num1, num2;
        } while (num1 || num2);

        int result;
        switch (choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                result = divide(num1, num2);
                break;
            case 5:
                result = modulus(num1, num2);
                break;
        }

        std::cout << "\nResult: " << result;
        std::cout << "Press y or Y to continue: ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    return num1 / num2;
}

int modulus(int num1, int num2) {
    return num1 % num2;
}