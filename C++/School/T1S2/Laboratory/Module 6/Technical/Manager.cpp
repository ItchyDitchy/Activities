#include <bits/stdc++.h>
#include <conio.h>
#include "Product.cpp"

using namespace std;

class Manager {
    private:
        unordered_map<string, Product> products;
        string storedPassword;
        int size = 0;

    public:
        Manager() : storedPassword("") {};
        Manager(string storedPassword) : storedPassword(storedPassword) {}

        bool hasPassword() {
            return storedPassword.length() > 0;
        }

        bool checkPassword(string password) {
            return storedPassword == password;
        }

        void addProduct(Product product) {
            products[product.getKey()] = product;
            size++;
        }

        void addProduct(string key, string displayName, double price) {
            addProduct(Product(key, displayName, price));
        }

        void addProduct(string displayName, double price) {
            addProduct(toLower(strip(displayName)), displayName, price);
        }

        void removeProduct(string key) {
            products.erase(key);
            size--;
        }

        unordered_map<string, Product> getProducts() {
            return products;
        }

        vector<Product> getProductsAsVector() {
            vector<Product> productsV;
            for (auto& item : products)
                productsV.push_back(item.second);
            return productsV;
        }

        Product getByProductKey(string key) {
            return products[key];
        }

        bool containsProductKey(string key) {
            return products.find(key) != products.end();
        }

        bool saveData(ofstream &db) {
            if (!db.is_open())
                return 0;
            db << storedPassword << "$";
            for (auto& item : products) {
                Product product = item.second;
                db << product.getDisplayName() << "," << product.getPrice() << ";";
            }
            return 1;
        }

        int getSize() {
            return size;
        }
};