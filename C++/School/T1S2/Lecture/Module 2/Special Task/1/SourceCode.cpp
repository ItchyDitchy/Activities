#include <bits/stdc++.h>
#include <conio.h>
#include <iomanip>
#include "ColorImpl.h"

int size = 220;

void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight(); // center I guess, padding Lol

int main() {
    int state = 0;
    do {
        system("cls");
        std::cout << GRN << "#####";
        for (int i = 0; i < size; i++) {
            std::cout << ".";
        }
        std::cout << "\n";
        std::cout << WHT << "" << std::setw(size/2) << "1. tolower\n";
        std::cout << "" << std::setw(size/2) << "2. toupper\n";\
        std::cout << "" << std::setw(size/2) << "3. islower\n";\
        std::cout << "" << std::setw(size/2) << "4. isupper\n";\
        std::cout << "" << std::setw(size/2) << "5. isalpha\n";\
        std::cout << "" << std::setw(size/2) << "6. isdigit\n";\
        std::cout << "" << std::setw(size/2) << "7. isalnum\n";
        std::cout << "" << std::setw(size/2) << "8. exit\n";
        std::cout << GRN << "#####";
        for (int i = 0; i < size; i++) {
            std::cout << ".";
        }
        std::cout << WHT << "\n> ";
        std::cin >> state;

        switch (state) {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            case 7:
                seven();
                break;
            case 8:
                std::cout << "Thank you.\n";
                std::cout << "Click any key to continue.";
                getch();
                return 0;
        }

        state = 0;
        std::cout << "Click any key to continue.";
        getch();
    } while (1 > state || state > 8);
    return 0;
}

void one() {
    std::string text = "";
    std::string newText = "";
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"tolower\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        newText += tolower(text[i]);
    }
    std::cout << "Result: " << newText << "\n";
}

void two() {
    std::string text = "";
    std::string newText = "";
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"toupper\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        newText += toupper(text[i]);
    }
    std::cout << "Result: " << newText << "\n";
}

void three() {
    std::string text = "";
    std::string newText = "";
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"islower\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        newText += tolower(text[i]);
    }
    std::string result = text == newText ? "True" : "False";
    std::cout << "Result: " << result << "\n";
}

void four() {
    std::string text = "";
    std::string newText = "";
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"isupper\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        newText += toupper(text[i]);
    }
    std::string result = text == newText ? "True" : "False";
    std::cout << "Result: " << result << "\n";
}

void five() {
    std::string text = "";
    int count = 0;
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"isalpha\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i]))
            count++;
    }
    std::cout << "Result: " << (count == text.length() ? "True" : "False") << "\n";
}

void six() {
    std::string text = "";
    int count = 0;
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"isdigit\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        if (isdigit(text[i]))
            count++;
    }
    std::cout << "Result: " << (count == text.length() ? "True" : "False") << "\n";
}

void seven() {
    std::string text = "";
    int count = 0;
    do {
        system("cls");
        std::cout << "What string would you like to use the function \"isalnum\" on?\n> ";
        getline(std::cin, text);
    } while (text.length() == 0);
    for (int i = 0; i < text.length(); i++) {
        if (isalnum(text[i]))
            count++;
    }
    std::cout << "Result: " << (count == text.length() ? "True" : "False") << "\n";
}