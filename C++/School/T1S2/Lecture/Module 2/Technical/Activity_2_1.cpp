#include <iostream>

int main() {
    int numbers[10];
    std::cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        std::cin >> numbers[i];

    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    int matches = 0;
    for (int i = 0; i < 10; i++)
        if (numbers[i] == number)
            matches++;

    std::cout << "Times of number " << number << " present in the array: " << matches;
    return 0;
}