#include <bits/stdc++.h>
#include "StringUtils.cpp"

using namespace std;

class Product {
private:
    string key;
    string displayName;
    double price;
    int quantity;
public:
    Product() : key(""), displayName(""), price(0.0), quantity(0) {}

    Product(string key, string displayName, double price = 0.0, int quantity = 0) : key(key), displayName(displayName), price(price), quantity(quantity) {}
    Product(string displayName, double price = 0.0, int quantity = 0) : key(toLower(strip(displayName))), displayName(displayName), price(price), quantity(quantity) {}

    string getKey() {
        return key;
    }
    string getDisplayName() {
        return displayName;
    }
    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    string setKey(string key) {
        this->key = key;
    }
    string setDisplayName(string displayName) {
        this->displayName = displayName;
    }
    double setPrice(double price) {
        this->price = price;
    }

    int setQuantity(int quantity) {
        this->quantity = quantity;
    }

    double getCost() {
        return fabs(price * quantity);
    }

    Product clone(int quantity) {
        return Product(key, displayName, price, quantity);
    }
};