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
        cout << REDHB << "[Error]" << WHT << " Shopping Cart is empty.\n";
        cout << "Click any key to continue.";
        getch();
        return;
    }

    Node* current = head;
    double totalCost = 0.0;

    cout << fixed << setprecision(2);
    cout << "Shopping Cart:" << endl;

    vector<Product> vProducts;
    while (current) {
        vProducts.push_back(current->value);
        totalCost += current->value.getCost();
        current = current->next_node;
    }

    displayProducts(vProducts);

    cout << "\nTotal Cost: " << GRN << "Php " << totalCost << "\n";
    cout << WHT << "Click any key to continue.";
    getch();
}

void checkOut() {
    system("cls");
    if (!head) {
        cout << REDHB << "[Error]" << WHT << " Shopping Cart is empty.\n";
        cout << "Cannot proceed with checkout.\n";
        cout << "Click any key to continue.";
        getch();
        return;
    }

    Node* current = head;
    double totalCost = 0.0;

    cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << WHT << "Receipt:\n";
    cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << fixed << setprecision(2);

    vector<Product> vProducts;
    while (current) {
        vProducts.push_back(current->value);
        totalCost += current->value.getCost();
        current = current->next_node;
    }

    displayProducts(vProducts);

    cout << WHT << "Total Cost: " << GRN << "Php " << totalCost << "\n\n";
    cout << WHT << "Thank you for shopping!\n";
    cout << "Checkout successful.\n";

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