#include <iostream>

using namespace std;

class Shape {
    public:
        double num1;
        double num2;
        double getArea() {}
};

class Triangle : public Shape {
    public:
        double getArea() {
            return num1 * num2 / 2;
        }
};

class Rectangle : public Shape {
    public:
        double getArea() {
            return num1 * num2;
        }
};

int main() {
    Shape* shape;

    shape = new Triangle();
    cout << "Enter base and height: ";
    cin >> shape->num1 >> shape->num2;
    cout << "Area of triangle is " << shape->getArea();

    shape = new Rectangle();
    cout << "Enter length and width: ";
    cin >> shape->num1 >> shape->num2;
    cout << "Area of rectangle is " << shape->getArea();
    return 0;
}