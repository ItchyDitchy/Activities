#include <bits/stdc++.h>

int main() {
    int numbers[10];
    std::cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        std::cin >> numbers[i];
    std::cout << "Even numbers are located at indices: ";
    for (int i = 0; i < 10; i++)
        if (numbers[i] % 2 == 0)
        std::cout << i << " ";
    return 0;
}