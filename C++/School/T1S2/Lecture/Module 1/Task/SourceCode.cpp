#include <iostream>
#include <ctime>
#include <cmath>

float choiceFunction();
float choiceFunction(float base, float exponent);
float choiceFunction(float base);

int main() {
    float choice = 0;
    std::cout << "What would you like to do?\n";
    std::cout << "[1] Seed Random\n";
    std::cout << "[2] Display Power\n";
    std::cout << "[3] Compute Square Root\n";
    std::cout << "[4] Display the Round off number\n";
    std::cout << "[5] Exit\n";
    std::cout << "Choice (1-5): ";
    std::cin >> choice;

    float num1;
    float num2;
    float num3;
    int choiceA = roundf(choice);
    system("cls");

    switch (choiceA) {
        case 1:
            std::cout << "Results: " << choiceFunction();
            break;
        case 2:
            std::cout << "Enter a Base: ";
            std::cin >> num1;
            std::cout << "Enter Exponent: ";
            std::cin >> num2;
            std::cout << "Results: " << choiceFunction(num1, num2);
            break;
        case 3:
            std::cout << "Enter Base: ";
            std::cin >> num1;
            std::cout << "Results: " << choiceFunction(num1);
            break;
        case 4:
            std::cout << "Enter a number with decimal place: ";
            std::cin >> num1;
            std::cout << "Results: " << roundf(num1);
            break;
        default:
            std::cout << "Thank you!";
            break;
    }
    return 0;
}

float choiceFunction() {
    srand(time(nullptr));
    return rand();
}

float choiceFunction(float base, float exponent) {
    return powf(base, exponent);
}

float choiceFunction(float base) {
    return sqrtf(base);
}