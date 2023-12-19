#include <iostream>
#include <conio.h>

double square(double s);
double rectangle(double l, double w);
double triangle(double b, double h);
double circle(double r);

int main() {
    int choice = 0;

    std::cout << "====================\n";
    std::cout << "MENU\n";
    std::cout << "====================\n";
    std::cout << "[1] - Area of square\n";
    std::cout << "[2] - Area of rectangle\n";
    std::cout << "[3] - Area of triangle\n";
    std::cout << "[4] - Area of circle\n";
    std::cout << "[5] - exit\n";
    std::cout << "--------------------\n";

    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
    } while (1 > choice && choice > 5);

    std::cout << "--------------------\n";

    double side = 0;
    double length = 0;
    double width = 0;
    double base = 0;
    double height = 0;
    double radius = 0;

    switch (choice) {
        case 1:
            std::cout << "AREA OF SQUARE\n";
            std::cout << "--------------------\n";

            do {
                std::cout << "Enter the side of the square: ";
                std::cin >> side;
            } while (side <= 0);

            std::cout << "\n";
            std::cout << "The area is " << square(side) << " sq. units";
            break;
        case 2:
            std::cout << "AREA OF RECTANGLE\n";
            std::cout << "--------------------\n";

            do {
                std::cout << "Enter the length and width of the rectangle: ";
                std::cin >> length, width;
            } while (length <= 0 || width <= 0);

            std::cout << "\n";
            std::cout << "The area is " << rectangle(length, width) << " sq. units";
            break;
        case 3:
            std::cout << "AREA OF TRIANGLE\n";
            std::cout << "--------------------\n";

            do {
                std::cout << "Enter the base and width of the height: ";
                std::cin >> base, height;
            } while (base <= 0 || base <= 0);

            std::cout << "\n";
            std::cout << "The area is " << triangle(base, height) << " sq. units";
            break;
        case 4:
            std::cout << "AREA OF CIRCLE\n";
            std::cout << "--------------------\n";

            do {
                std::cout << "Enter the radius: ";
                std::cin >> radius;
            } while (radius <= 0);

            std::cout << "\n";
            std::cout << "The area is " << circle(radius) << " sq. units";
            break;
        case 5:
            std::cout << "Thank you!";
            _getch();
            break;
    }
    return 0;
}

double square(double s) {
    return s * s;
}

double rectangle(double l, double w) {
    return l * w;
}

double triangle(double b, double h) {
    return b*h/2;
}

double circle(double r) {
    return 3.14*r*r;
}