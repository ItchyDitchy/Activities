#include <iostream>

using namespace std;

int main() {
    char shapeChar;
    system("cls");
    cout << "Volume of Figures\n[C] - Cube\n[R] - Rectangular Prism\n[S] - Sphere\n\nChoose figure: ";
    cin >> shapeChar;
    switch (shapeChar) {
        case 'C':
        case 'c':
            cout << "You have chosen Cube\n";
            double side;
            cout << "Enter side: ";
            cin >> side;
            cout << "The volume of the Cube is: " << side * side * side;
            return 0;
        case 'R':
        case 'r':
            cout << "You have chosen Rectangular Prism\n";
            double width, length, height;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter height: ";
            cin >> height;
            cout << "The volume of the Rectangular Prism is: " << width * length * height;
            return 0;
        case 'S':
        case 's':
            double radius;
            cout << "You have chosen Sphere\n";
            cout << "Enter radius: ";
            cin >> radius;
            cout << "The volume of the Sphere is: " << radius * radius * radius * 4 / 3 * 3.14;
            return 0;
        default:
            cout << "Invalid input.";
    }
    return 0;
}