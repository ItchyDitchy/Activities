#include <iostream>

int main() {
    int sum = 0, i = 0, number;
    while (i<3) {
        i++;
        std::cout << "Number " << i << ": ";
        std::cin >> number;
        sum+=number;
    }
    std::cout << "Sum: " << sum;
}