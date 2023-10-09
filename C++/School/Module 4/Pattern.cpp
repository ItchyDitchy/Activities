#include <iostream>
#include <windows.h>
using namespace std;

main() {
    for (int x = 1; x <= 5; x++) {
        int y = 1;
        while (y++ <= x) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}