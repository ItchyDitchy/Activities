#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct Node {
    int number;
    Node* next;
};

Node* head = nullptr;

void addRecord(const int number) {
    Node* newNode = new Node;
    newNode -> number = number;
    newNode -> next = head;
    head = newNode;
}

void viewRecords() {
    Node* current = head;
    while (current != nullptr) {
        cout << current -> number << (current -> next != nullptr ? ", " : "");
        current = current -> next;
    }
    cout << endl << "----------------------------------" << endl;
}

void computeSum() {
    Node* current = head;
    int size = 0;
    int sum = 0;
    while (current != nullptr) {
        sum += current -> number;
        current = current -> next;
        size++;
    }
    cout << "Sum of " << size << " numbers is " << sum << "." << endl;
    cout << "----------------------------------" << endl;
}

int main() {
    while (1) {
        int choice = 0;
        do {
            system("cls");
            cout << "1. Add Record(s)" << endl;
            cout << "2. View Records" << endl;
            cout << "3. Sum of All Records" << endl;
            cout << "4. Exit" << endl;
            cout << "What would you like to do?" << endl << "> ";
            cin >> choice;
        } while (1 > choice || choice > 6);

        system("cls");
        switch (choice) {
            case 1:
                while (1) {
                    int size = 0;
                    do {
                        system("cls");
                        cout << "Assign number of nodes : ";
                        cin >> size;
                    } while (size < 1);

                    int sum = 0;
                    int number[size];
                    for (int i = 0; i < size; i++) {
                        system("cls");
                        cout << "Enter number of nodes : ";
                        for (int j = 0; j < i; j++)
                            cout << number[j] << ",";
                        cin >> number[i];
                        sum += number[i];
                        addRecord(number[i]);
                    };
                    system("cls");
                    cout << "Sum of " << size << " numbers : " << sum << endl;
                    cout << "Successfully added " << size << " new records." << endl;
                    char choice = 'n';
                    do {
                        cout << "Would you like to input another set of nodes y/n : ";
                        cin >> choice;
                        choice = tolower(choice);
                    } while (choice != 'y' && choice != 'n');
                    if (choice == 'n')
                        break;
                }
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                computeSum();
                break;
            case 4:
                cout << "Thank you for using the program.";
                return 0;
        }

        cout << endl << "Click any key to continue.";
        getch();
    }
    return 0;
}