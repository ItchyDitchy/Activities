#include <iostream>

int main() {
    int sum = 0, number;
    for (int i=1; i<=3; i++) {
        std::cout << "Number " << i << ": ";
        std::cin >> number;
        sum+=number;
    }
    std::cout << "Sum: " << sum;
}