#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string admissionNumber;
    cout << "Enter admission number: ";
    cin >> admissionNumber;

    string studentName;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, studentName);

    int english, math, science;
    do {
        cout << "Enter grades in English, Math, Science:" << "\n";
        cin >> english >> math >> science;
    } while (english < 1 || math < 1 || science < 1);

    cout << "Admission number: " << admissionNumber << "\n";
    cout << "Student name: " << studentName << "\n";
    cout << "English: " << english << "\n";
    cout << "Math: " << math << "\n";
    cout << "Science: " << science << "\n";
    cout << "Average: " << (english + math + science) / 3 << "\n\n";
    return 0;
}