#include <bits/stdc++.h>

int main() {
    int size = 0;
    system("cls");
    std::cout << "How many numbers would you like to check for odds? ";
    std::cin >> size;
    int numbers[size];
    for (int i = 0; i < size; i++) {
        system("cls");
        std::cout << "Input number " << (i+1) << ": ";
        std::cin >> numbers[i];
    }
    std::cout << "Result: ";
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0)
            std::cout << "\n" << numbers[i];
    }
    return 0;
}