#include <iostream>

int main() {
    int start, last;
    std::cout << "Enter starting number: ";
    std::cin >> start;
    std::cout << "Enter last number: ";
    std::cin >> last;
    
    if (start > last) {
        std::cout << "Invalid input.";
        return 0;
    }

    std::cout << "The numbers are: ";

    while (start <= last) {
        std::cout << start++;
    }
    return 0;
}