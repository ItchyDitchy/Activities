#include <iostream>

int main() {
    int limit = 0;
    std::cout << "Enter a number: ";
    std::cin >> limit;
    
    if (limit <= 0) {
        std::cout << "Invalid input.";
        return 0;
    }

    for (int i = 0; i < limit; i++) {
        for (int j = 0; j <= i; j++)
            std::cout << "*";
        std::cout << std::endl;
    }
    return 0;
}