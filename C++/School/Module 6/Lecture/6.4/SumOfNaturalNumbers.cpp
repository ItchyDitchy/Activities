#include <iostream>

int main() {
    int num = -1, sum = 0;

    do {
        std::cout << "Enter a number: ";
        std::cin >> num;
    } while (num < 0);
    
    for (int i = 1; i <= num; i++)
        sum += i;

    std::cout << "The sum from 1 to " << num << " is " << sum;
    return 0;
}

// Better to use a formula rather than a loop tbh.