#include <bits/stdc++.h>
#include <conio.h>
#include <ShoppingCart.cpp>

using namespace std;

const int MAX_PRODUCTS = 10;
Product products[MAX_PRODUCTS];
ShoppingCart cart;

int displayMenu();
bool authenticateManager();
void setProducts(Product* products);
void processUserOption(Product* products, ShoppingCart& cart);

int main() {

    while (1) {
        int choice = displayMenu();
        switch (choice) {
            case 1:
                processUserOption(products, cart);
                break;

            case 2:
                cart.displayCart();
                break;
                system("cls");

            case 3:
                cart.checkOut();
                break;
                system("cls");

            case 4:
                if (authenticateManager()) {
                    setProducts(products);
                } else {
                    cout << "Authentication failed. Access denied.\n";
                }
                break;
                system("cls");

            case 5:
                cout << "Exiting program.";
                return 0;
        }

        system("cls");
        cout << "Click any key to continue.";
        getch();
    }
}

int displayMenu() {
    int choice = 0;
    do {
        system("cls");
        cout << "=========================================================\n";
        cout << "\t\t WELCOME TO SHOPPING CART!!\n";
        cout << "=========================================================\n";
        cout << "1. Add Product to Cart\n";
        cout << "2. View Cart\n";
        cout << "3. Check Out\n";
        cout << "4. Manager (Set Products)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice [1-5];\n> ";
        cin >> choice;
    } while (1 > choice || choice > 5);
    return choice;
}

bool authenticateManager() {
    string password;
    cout << "Enter the manager password: ";
    cin >> password;

    return password == "your_password";
    system("cls");
}

void setProducts(Product* products) {
    cout << "Enter the details for each product:\n";
    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        cout << "Product " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> products[i].name;
        system("cls");
        cout << "Price (Php): ";
        while (!(cin >> products[i].price) || products[i].price <= 0) {
            getch();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive price: ";
        }
    }
    system("cls");
    cout << "Products set successfully!\n";
    cout << "Click any key to continue.";
    getch();
}

void processUserOption(Product* products, ShoppingCart& cart) {
    int productIndex, quantity;

    cout << "Select a product to add to the cart:\n";
    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        system("cls");
        cout << i + 1 << ". " << products[i].name << " - Php" << products[i].price << endl;
    }

    do {
        system("cls");
        cout << "Enter the product number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid product number: ";
    } while (!(cin >> productIndex) || productIndex < 1 || productIndex > MAX_PRODUCTS);

    cout << "Enter the quantity: ";
    while (!(cin >> quantity) || quantity <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive quantity: ";
        system("cls");
    }

    cart.addItem(products[productIndex - 1], quantity);
    cout << "Product added to the cart!\n";
    system("cls");
}