#include <iostream>

using namespace std;

int main() {
    int grade;

    cout << "Enter grade: ";
    cin >> grade;
    if (grade >= 91 && grade <= 100)
        cout << "Letter Grade: A";
    else if (grade >= 81 && grade <= 90)
        cout << "Letter Grade: B";
    else if (grade >= 70 && grade <= 80)
        cout << "Letter Grade: C";
    else if (grade >= 0 && grade <= 69)
        cout << "Letter Grade: F";
    else
        cout << "You've entered wrong data.";
    return 0;
}