#include <bits/stdc++.h>
#include <conio.h>
#include "Manager.cpp"

using namespace std;

class Node {
public:
    Product value;
    Node* next_node;

    Node(Product product, Node* next_node = NULL)
        : value(product), next_node(next_node) {}
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(NULL) {}

    void addItem(const Product& product) {
        Node* new_node = new Node(product);
        if (!head)
            head = new_node;
        else {
            Node* current = head;
            while (current->next_node)
                current = current->next_node;
            current->next_node = new_node;
        }
    }

    Node* getHead() {
        return head;
    }

void displayCart() {
    system("cls");
    if (!head) {
        cout << "Shopping Cart is empty.\n";
        cout << "Click any key to continue.";
        getch();
        return;
    }

    Node* current = head;
    double totalCost = 0.0;

    cout << fixed << setprecision(2);
    cout << "Shopping Cart:" << endl;

    while (current) {
        Product product = current->value;
        double cost = product.getCost();
        cout << product.getQuantity() << "x "
            << product.getDisplayName() << "(s) - Php "
            << cost << endl;
        totalCost += cost;
        current = current->next_node;
    }

    cout << "Total Cost: Php " << totalCost << endl;
    cout << "Click any key to continue.";
    getch();
}

void checkOut() {
    system("cls");
    if (!head) {
        cout << "Shopping Cart is empty. Cannot proceed with checkout.\n";
        cout << "Click any key to continue.";
        getch();
        return;
    }

    Node* current = head;
    double totalCost = 0.0;

    cout << "Receipt:\n";
    cout << fixed << setprecision(2);

    while (current) {
        Product product = current->value;
        double cost = product.getCost();
        cout << product.getQuantity() << "x "
            << product.getDisplayName() << "(s) - Php "
            << cost << endl;
        totalCost += cost;
        current = current->next_node;
    }

    cout << "Total Cost: Php " << totalCost << endl;
    cout << "Thank you for shopping! Checkout successful.\n";

    clearCart();
    cout << "Click any key to continue.";
    getch();
}

    void clearCart() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next_node;
            delete temp;
        }
        head = NULL;
    }

    ~ShoppingCart() {
        clearCart();
    }
};