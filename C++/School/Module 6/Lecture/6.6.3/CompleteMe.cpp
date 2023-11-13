#include <iostream>

using namespace std;

int main() {
    int x = 1, no;
    cout << "Enter number: ";
    cin >> no;
    cout << "Multiplication Table of " << no << endl;
    
    while (x <= 10)
        cout << no << " x " << x << " = " << no * x++ << "\n"; 
    return 0;
}