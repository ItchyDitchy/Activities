#include <bits/stdc++.h>

int main() {
    int size = 0;
    system("cls");
    std::cout << "How many numbers would you like to check sum the odds? ";
    std::cin >> size;
    int numbers[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        system("cls");
        std::cout << "Input number " << (i+1) << ": ";
        std::cin >> numbers[i];
        if (numbers[i] % 2 != 0 )
            sum += numbers[i];
    }
    std::cout << "Result: " << sum;
    return 0;
}