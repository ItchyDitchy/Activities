#include <iostream>


int addition(int a, int b) {
    return a+b;
}

int main() {
    std::cout << "Test 1 has " << ((addition(3, 2) == 5) ? "passed" : "failed") << ".\n";
    std::cout << "Test 2 has " << ((addition(-3, -6) == -9) ? "passed" : "failed") << ".\n";
    std::cout << "Test 3 has " << ((addition(7, 3) == 10) ? "passed" : "failed") << ".\n";
}