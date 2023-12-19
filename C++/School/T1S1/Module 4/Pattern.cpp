#include <iostream>
#include <windows.h>
using namespace std;

main() {
    for (int x = 1; x <= 5; x++) {
        for (int y = 1; y <= x; y++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}