#include <iostream>
#include <windows.h>
using namespace std;

int Amain() {
    for (int x = 1; x <= 5; x++) {
        int y = 1;
        while (y++ <= x) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

main() {
    int x = 5, y = 1;
    while (y <= 5) {
        while (y <= x) {
            std::cout << "*";
            y++;
        }
        std::cout << "\n";
    }
}