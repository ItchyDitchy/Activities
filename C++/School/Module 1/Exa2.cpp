#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, branch, course, address;
    int age = -1, branchID;

    cout << "What is your name?\n";
    cin >> name;
    cout << "\nHow old are you?\n";
    cin >> age;
    cout << "\nIn what branch of FEU are you?\n";
    while (!(cin >> branchID) && (branchID <= 0 || branchID > 7)) {
        cout << "\nYou have given an invalid branch.\nIn what branch of FEU are you?\n";
    }
    string branchArray[] = {"FEU Institute of Technology", "FEU Diliman", "FEU Makati", "FEU Cavite", "FEU High SChool", "FEU Alabang", "FEU Roosevelt"};
    branch = branchArray[branchID];
    return 0;
}