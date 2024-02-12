#include <bits/stdc++.h>
#include <conio.h>

struct Item {
    std::string name = "";
    double price = 0;
    int amount = 1;
};

struct Invoice {
    std::string firstName = "";
    std::string lastName = "";
    std::vector<Item> items;
};

std::unordered_map<std::string, Invoice> invoices;

void addInvoice();
void displayInvoices();
std::string toLower(std::string txt);
std::string titleCase(std::string txt);

int main() {
    while (1) {
        int choice = 0;
        do {
            system("cls");
            std::cout << "What would you like to do?\n";
            std::cout << "1. Add Invoice\n";
            std::cout << "2. Display Invoices\n";
            std::cout << "3. Exit\n> ";
            std::cin >> choice;
        } while (1 > choice || choice > 3);

        switch (choice) {
            case 1:
                addInvoice();
                break;
            case 2:
                displayInvoices();
                break;
            case 3:
                system("cls");
                std::cout << "Thank you for using the program.";
                return 0;
        }
        std::cout << "Click any key to continue.";
        getch();
    }
    return 0;
}

void addInvoice() {
    Invoice invoice;

    do {
        system("cls");
        std::cout << "First Name\n> ";
        std::getline(std::cin, invoice.firstName);
    } while (3 > invoice.firstName.length() || invoice.firstName.length() > 30);

    do {
        system("cls");
        std::cout << "Second Name\n> ";
        std::getline(std::cin, invoice.lastName);
    } while (3 > invoice.lastName.length() || invoice.lastName.length() > 30);

    auto search = invoices.find(toLower(invoice.lastName + "/" + invoice.firstName));
    if (search != invoices.end())
        invoice = search->second;

    std::vector<Item> &items = invoice.items;
    Item item;

    do {
        system("cls");
        std::cout << "Item Name\n> ";
        std::getline(std::cin, item.name);
    } while (3 > item.name.length() || item.name.length() > 30);

    do {
        system("cls");
        std::cout << "Item Price\n> ";
        std::cin >> item.price;
    } while (0 >= item.price);

    bool contains = false;
    for (Item &tempItem : items) {
        if (toLower(tempItem.name) == toLower(item.name)) {
            tempItem.amount++;
            tempItem.price = item.price;
            contains = true;
            break;
        }
    }
    if (!contains) {
        items.push_back(item);
    }
    invoice.items = items;
    invoices[toLower(invoice.lastName + "/" + invoice.firstName)] = invoice;
}

void displayInvoices() {
    std::cout << std::left << std::setw(30) << "First Name" << std::setw(30) << "Last Name" << std::setw(30) << "Item Name" << std::setw(15) << "Price" << std::setw(15) << "Amount" << std::setw(15) << "Total" << std::endl;
    for (auto& pair : invoices) {
        Invoice invoice = pair.second;
        std::vector<Item> &items = invoice.items;
        std::cout << std::left << std::setw(30) << titleCase(invoice.firstName) << std::setw(30) << titleCase(invoice.lastName) << std::setw(30) << titleCase(items[0].name) << std::setw(15) << items[0].price << std::setw(15) << items[0].amount << std::setw(15) << (items[0].price * items[0].amount) << std::endl;
        for (int i = 1; i < items.size(); i++) {
            std::cout << std::left << std::setw(60) << "" << std::setw(30) << titleCase(items[i].name) << std::setw(15) << items[i].price << std::setw(15) << items[i].amount << std::setw(15) << (items[i].price * items[i].amount) << std::endl;
        }
    }
}

std::string toLower(std::string txt) {
    for (char &c : txt)
        c = tolower(c);
    return txt;
}

std::string titleCase(std::string txt) {
    txt[0] = toupper(txt[0]);
    for (int i = 1; i < txt.size(); i++)
        txt[i] = isspace(txt[i-1]) ? toupper(txt[i]) : tolower(txt[i]);
    return txt;
}