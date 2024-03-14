#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "ShoppingCart.cpp"

using namespace std;

Manager manager;
ShoppingCart cart;

void loadData();
void saveData();

int displayMenu();
bool verifyManager();
void setProducts();
void processUserOption();

int main() {
    loadData();
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    while (1) {
        choice = displayMenu();
        switch (choice) {
            case 1:
                processUserOption();
                break;
            case 2:
                cart.displayCart();
                break;
            case 3:
                cart.checkOut();
                break;
            case 4:
                if (verifyManager())
                    setProducts();
                else {
                    system("cls");
                    cout << RED << "Authentication failed. Access denied.\n";
                    cout << WHT << "Click any key to continue.";
                    getch();
                }
                break;
            case 5:
                saveData();
                system("cls");
                cout << GRN << "Exiting program.\n";
                cout << "Delos Reyes\nFernando\nIsip\nPanio\nPenaranda";
                return 0;
        }
        saveData();
    }

    return 0;
}

// DATABASE
void loadData() {
    ifstream db("database.txt");
    if (!db.is_open()) {
        cout << "Unable to open file stream!";
        return;
    }

    string data;
    db >> data;
    string builder = "";
    vector<string> dataList;


    for (char c : data) {
        if (c == '$') {
            manager = Manager(builder);
            builder = "";
            continue;
        }
        if (c == ',') {
            dataList.push_back(builder);
            builder = "";
            continue;
        }

        if (c == ';') {
            dataList.push_back(builder);
            builder = "";
            if (dataList.size() == 2) {
                for (string data : dataList)
                    cout << data << "\n";
                cout << "\n";
                manager.addProduct(dataList[0], stod(dataList[1]));
            } else if (dataList.size() == 3) {
                Product product = Product(dataList[0], stod(dataList[1]), stoi(dataList[2]));
                cart.addItem(product);
            }
            dataList.clear();
            builder = "";
            continue;
        }
        builder += c;
    }
    db.close();
}

void saveData() {
    cout << BHRED << "\nLoading file...\n";
    ofstream db("database.txt");
    cout << "Accessing file...\n";
    if (!db.is_open()) {
        cout << "Couldn't access the file!";
        getch();
        return;
    }
    cout << "Checking manager data...\n";
    if (manager.hasPassword() == 0) {
        db.close();
        return;
    }

    cout << "Saving manager data...\n";
    if (manager.saveData(db))
        cout << "Successfully saved manager data.";

    cout << "Saving shopping cart...\n";
    Node* current = cart.getHead();
    while (current) {
        Product product = current->value;
        db << product.getDisplayName() << "," << product.getPrice() << ";" << product.getQuantity();
        current = current->next_node;
    }
    db.close();
    cout << "Saved data.\n" << reset;
}

// FEATURES
int displayMenu() {
    int choice;

    do {
        system("cls");
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << WHT << "\t\t WELCOME TO SHOPPING CART!\n";
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << YEL << "1. Add Product to Cart\n";
        cout << "2. View Cart\n";
        cout << "3. Check Out\n";
        cout << "4. Manager (Set Products)\n";
        cout << "5. Exit\n";
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << WHT << "Enter your choice [1-5]\n";
        cout << BLU << "> " << WHT;
        cin >> choice;
    } while (1 > choice || choice > 5);

    return choice;
}

bool verifyManager() {
    if(!manager.hasPassword()){
        string password;
        do {
            system("cls");
            cout << "Set a password [8-20 Characters]\n> ";
            cin >> password;
        } while (8 > password.length() || password.length() > 20);
        manager = Manager(password);
    }

    string password;
    do {
        system("cls");
        cout<<"Enter password: ";
        cin >> password;
    } while (8 > password.length() || password.length() > 20);

    return manager.checkPassword(password);
}

void setProducts() {
    string displayName;
    do {
        system("cls");
        cout << "Enter Details for Product #" << manager.getSize() + 1 << "\n";
        cout << "Display Name [3-32 Characters]\n";
        cout << BLU << "> " << WHT;
        getline(cin, displayName);
    } while (3 > displayName.length() ||
        displayName.length() > 32 ||
        manager.containsProductKey(toLower(strip(displayName))) ||
        toLower(strip(displayName)) == "cancel");

    double price;
    do {
        system("cls");
        cout << "Enter Details for Product #" << manager.getSize() + 1 << "\n";
        cout << "Display Name [3-32 Characters]\n";
        cout << BLU << "> " << WHT << displayName << "\n";
        cout << "Price (Php)\n";
        cout << BLU << "> " << WHT;
        cin >> price;
    } while (price <= 0);

    manager.addProduct(displayName, price);
    cout << "\n\n" << GRN << "The product has been recorded!\n";
    cout << WHT << "Click any key to continue.";
    getch();
}

void processUserOption() {
    system("cls");
    if (manager.getSize() < 1) {
        cout << REDHB << "[Error]" << WHT << " There are no products available!\n";
        cout << "Click any key to continue.";
        getch();
        return;
    }

    vector<Product> products = manager.getProductsAsVector();

    string key;
    do {
        system("cls");
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << WHT << "Select a product to add to the cart.\n";
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        displayProducts(products);
        cout << GRN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << WHT << "\nEnter the product key\n";
        cout << BLU << "> " << WHT;
        cin >> key;
        key = toLower(strip(key));
    } while (!manager.containsProductKey(key) && key == "cancel");

    int quantity;
    do {
        system("cls");
        cout << "Enter the quantity\n";
        cout << BLU << "> " << WHT;
        cin >> quantity;
    } while (quantity <= 0);

    Product clone = manager.getByProductKey(key).clone(quantity);
    cart.addItem(clone);
    system("cls");
    cout << "Product added to the cart!\n";
    cout << "Click any key to continue.";
    getch();
}