#include <string>

using namespace std;

class Product {
public:
    string name;
    double price;

    // Default constructor
    Product() : name(""), price(0.0) {}

    Product(string name, double price) : name(name), price(price) {}
};