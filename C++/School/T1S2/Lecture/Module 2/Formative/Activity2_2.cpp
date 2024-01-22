#include <bits/stdc++.h>
#include <algorithm>

int main() {
    int size;
    std::cout << "Enter the size of the array [1-100]: ";
    std::cin >> size;
    int numbers[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Array element " << (i+1) << ": ";
        std::cin >> numbers[i];
    }
    std::sort(numbers, numbers + size);
    std::cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
        std::cout << numbers[i] << " ";
}