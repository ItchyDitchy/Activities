#include <iostream>

int main() {
    int sum = 0, i = 0, number;
    do {
        i++;
        std::cout << "Number " << i << ": ";
        std::cin >> number;
        sum+=number;
    } while (i<3);
    std::cout << "Sum: " << sum;
}