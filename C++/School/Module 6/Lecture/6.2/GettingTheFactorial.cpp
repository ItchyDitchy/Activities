#include <iostream>

int main() {
    int num = 0, factorial = 1, i = 1;

    do {
        std::cout << "Enter an integer number: ";
        std::cin >> num;
    } while (num == 0);

    do {
        factorial *= i++;
    } while (i <= num);

    std::cout << "The factorial of " << num << " is: " << factorial;
    return 0;
}