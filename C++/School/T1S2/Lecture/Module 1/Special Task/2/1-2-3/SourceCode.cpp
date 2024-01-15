#include <bits/stdc++.h>
#include <conio.h>

void sum();
void odd();
void sumOdd();
void parking();

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
            std::cout << "4. Parking\n";
            std::cout << "5. Exit\n";
            std::cout << "[1-5] : ";
            std::cin >> choice;
        } while (1 > choice || choice > 5);

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
                parking();
                break;
            case 5:
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

// Parking Variables
std::string slots[5][26][6];

void park();
void unpark();
int countSlots();
int letterToNumber(char letter);

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void parking() {
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 26; y++)
            for (int z = 0; z < 6; z++)
                slots[x][y][z] = "";

    int choice;
    while (true) {
        choice = 0;
        do {
            system("cls");
            std::cout << "What would you like to do? Parking Slots Left: " << countSlots() << "\n";
            std::cout << "1. Park\n";
            std::cout << "2. Unpark\n";
            std::cout << "3. Exit\n";
            std::cout << "[1-3] ";
            std::cin >> choice;
        } while (1 > choice || choice > 3);

        switch (choice) {
            case 1:
                park();
                break;
            case 2:
                unpark();
                break;
            case 3:
                system("cls");
                std::cout << "Thank you for using the parking program.\n";
                return;
        }
    };
}

void park() {
    std::string name = "";
    do {
        system("cls");
        std::cout << "What should the car be called? [3-16 Characters] ";
        std::cin >> name;
    } while (3 > name.length() || name.length() > 16);
    while (true) {
        int floor = 0;
        do {
            system("cls");
            std::cout << "Which floor would you like to park? [1-5] ";
            std::cin >> floor;
        } while (1 > floor || floor > 5);
        char letter = '1';
        int value = 0;
        do {
            system("cls");
            std::cout << "Which row would you like to park? [A-Z] ";
            std::cin >> letter;
            value = letterToNumber(letter);
        } while (1 > value || value > 26);

        int column = 0;
        do {
            system("cls");
            std::cout << "Which row would you like to park? [1-6] ";
            std::cin >> column;
        } while (1 > column || column > 6);

        if (slots[floor][value][column] == "") {
            slots[floor][value][column] = name;
            std::cout << "You have parked car \"" << name << "\" at floor " << floor << " at slot " << letter << column << ".\n";
            std::cout << "Click any character to continue.";
            getch();
            return;
        }

        system("cls");
        std::cout << "Someone is already parked there!\n";
        std::cout << "Click any character to continue.";
        getch();
    }
}

void unpark() {
    int floor = 0;
    do {
        system("cls");
        std::cout << "Which floor would you like to unpark? [1-5] ";
        std::cin >> floor;
    } while (1 > floor || floor > 5);
    char letter = '1';
    int value = 0;
    do {
        system("cls");
        std::cout << "Which row would you like to unpark? [A-Z] ";
        std::cin >> letter;
        value = letterToNumber(letter);
    } while (1 > value || value > 26);
    int column = 0;
    do {
        system("cls");
        std::cout << "Which row would you like to unpark? [1-6] ";
        std::cin >> column;
    } while (1 > column || column > 6);

    if (slots[floor][value][column] == "") {
        std::cout << "The slot is empty.\n";
    } else {
        std::cout << "The car \"" << slots[floor][value][column] << "\" has been unparked.\n";
        slots[floor][value][column] = "";
    }
    std::cout << "Click any character to continue.";
    getch();
}

int countSlots() {
    int sum = 5*26*6;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 26; y++)
            for (int z = 0; z < 6; z++)
                if (slots[x][y][z] == "");
                    sum--;
    return sum;
}

int letterToNumber(char letter) {
    int value = tolower(letter) - 'a' + 1;
    return (1 > value || value > 26) ? 0 : value;
}