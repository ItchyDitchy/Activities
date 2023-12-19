#include <iostream>

using namespace std;

double Area_Rectangle(double length, double width) {
    return length*width;
}

double Area_Circle(double radius) {
    return 3.14*radius*radius;
}

int main() {
    char choice; 
    cout << "S H A P E S \n\n[R] - Rectangle\n[C] - Circle\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
        case 'R':
        case 'r':
            double length, width;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter width: ";
            cin >> width;
            cout << "The area of the rectangle is " << Area_Rectangle(length, width);
            break;
        case 'C':
        case 'c':
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            cout << "The area of the rectangle is " << Area_Circle(radius);;
            break;
        default:
            cout << "Invalid choice";
            return 0;
    }
    return 0;
}