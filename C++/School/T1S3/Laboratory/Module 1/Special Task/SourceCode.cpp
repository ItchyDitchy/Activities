#include <iostream>
#include <iomanip>
#include <windows.h>
#include "ColorImpl.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    while (1) {
        int choice = 0;
        while (1 > choice || choice > 10) {
            system("cls");
            cout << GRN << left << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
            cout << GRN << left << "┃" << right << setw(104) << "┃\n";
            cout << GRN << left << "┃" << setw(40) << "" << WHT << setw(50) << "Welcome To Kai's Casino!" << right << setw(17) << GRN << "┃\n";
            cout << GRN << left << "┃" << right << setw(104) << "┃\n";
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "1. Registration" << right << setw(17) << GRN << "┃\n"; // Linked List
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "2. Black Jack" << right << setw(17) << GRN << "┃\n"; // Stacks
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "3. Roulette" << right << setw(17) << GRN << "┃\n"; // Queues
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "4. RPS" << right << setw(17) << GRN << "┃\n"; // Recursion
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "5. Binary Tree" << right << setw(17) << GRN << "┃\n"; // Tree & Binary Tree
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "6. Program Statistics" << right << setw(17) << GRN << "┃\n"; // Graph
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "7. Chip Leaderboard" << right << setw(17) << GRN << "┃\n"; // Sorting Algorithm
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "8. Chip Profile" << right << setw(17) << GRN << "┃\n"; // Searching Algorithm
            cout << GRN << left << "┃" << setw(40) << "" << YEL << setw(50) << "9. Exit" << right << setw(17) << GRN << "┃\n";
            cout << GRN << left << "┃" << right << setw(104) << "┃\n";
            cout << GRN << left << "┃" << setw(40) << "" << MAG << setw(50) << "Choose a ride to go to! [1-9]" << right << setw(17) << GRN << "┃\n"; //
            cout << GRN << left << "┃" << right << setw(104) << "┃\n";
            cout << GRN << left << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
            cin >> choice;
        }
    }
}