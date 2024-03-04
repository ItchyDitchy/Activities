#include <bits/stdc++.h>
#include <conio.h>
#include <Product.cpp>

using namespace std;

class Node {
public:
    string item;
    int quantity;
    double price;
    Node* next_node;

    Node(string item, int quantity, double price, Node* next_node = nullptr)
        : item(item), quantity(quantity), price(price), next_node(next_node) {}
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(nullptr) {}

    void addItem(const Product& product, int quantity) {
        Node* new_node = new Node(product.name, quantity, product.price);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current -> next_node) {
                current = current -> next_node;
            }
            current -> next_node = new_node;
        }
    }

    void displayCart() {
        Node* current = head;
        double totalCost = 0.0;

        cout << fixed << setprecision(2);
        cout << "Shopping Cart:" << endl;
        system("cls");

        while (current) {
            cout << current->quantity << " " << current->item << "(s) - Php"
                 << current->price * current->quantity << endl;

            totalCost += current->price * current->quantity;
            current = current->next_node;
        }
        cout << "Total Cost: Php" << totalCost << endl;
        system("cls");
    }

    void checkOut() {
        Node* current = head;
        double totalCost = 0.0;

        cout << "Receipt:\n";
        cout << fixed << setprecision(2);

        while (current) {
            cout << current->quantity << " " << current->item << "(s) - Php"
                 << current->price * current->quantity << endl;

            totalCost += current->price * current->quantity;
            current = current->next_node;
        }

        cout << "Total Cost: Php" << totalCost << endl;
        cout << "Thank you for shopping! Checkout successful.\n";
        system("cls");
        getch();

        clearCart();
    }

    void clearCart() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next_node;
            delete temp;
        }
        head = nullptr;
    }

    ~ShoppingCart() {
        clearCart();
    }
};