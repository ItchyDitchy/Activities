#include <bits/stdc++.h>
#include <conio.h>

void sum();
void odd();
void sumOdd();

int main() {
    char repeat = 'y';

    do {
        int choice = 0;

        do {
            system("cls");
            std::cout << "What would you like to do?\n";
            std::cout << "1. Sum Numbers\n";
            std::cout << "2. List Odd Numbers\n";
            std::cout << "3. Sum Odd Numbers\n";
            std::cout << "4. Exit\n";
            std::cout << "[1-4] : ";
            std::cin >> choice;
        } while (1 > choice || choice > 4);

        switch (choice) {
            case 1:
                sum();
                break;
            case 2:
                odd();
                break;
            case 3:
                sumOdd();
                break;
            case 4:
                system("cls");
                std::cout << "\nThank you for using the program.";
                return 0;
        }

        std::cout << "\nClick any character to continue.";
        getch();

        repeat = 'n';
        do {
            system("cls");
            std::cout << "Go back to main menu? [Y/N] ";
            std::cin >> repeat;
        } while (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y');
    } while (repeat == 'y' || repeat == 'Y');

    system("cls");
    std::cout << "\nThank you for using the program.";
    return 0;
}

void sum() {
    int size = 0;
    system("cls");
    std::cout << "How many numbers would you like to sum up? ";
    std::cin >> size;
    int numbers[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        system("cls");
        std::cout << "Input number " << (i+1) << ": ";
        std::cin >> numbers[i];
        sum += numbers[i];
    }
    std::cout << "Result: " << sum;
};

void odd() {
    int size = 0;
    system("cls");
    std::cout << "How many numbers would you like to check for odds? ";
    std::cin >> size;
    int numbers[size];
    for (int i = 0; i < size; i++) {
        system("cls");
        std::cout << "Input number " << (i+1) << ": ";
        std::cin >> numbers[i];
    }
    std::cout << "Result: ";
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0)
            std::cout << "\n" << numbers[i];
    }
};

void sumOdd() {
    int size = 0;
    system("cls");
    std::cout << "How many numbers would you like to check sum the odds? ";
    std::cin >> size;
    int numbers[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        system("cls");
        std::cout << "Input number " << (i+1) << ": ";
        std::cin >> numbers[i];
        if (numbers[i] % 2 != 0 )
            sum += numbers[i];
    }
    std::cout << "Result: " << sum;
};