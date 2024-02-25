#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct Player {
    string nickname;
    int age;
    double score1;
    double score2;
};

struct Node {
    Player player;
    Node* next;
};

Node* head = nullptr;

void addRecord(const Player& player) {
    Node* newNode = new Node;
    newNode -> player = player;
    newNode -> next = head;
    head = newNode;
}

void viewRecords() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Age: " << current->player.age << endl;
        cout << "Score 1: " << current->player.score1 << endl;
        cout << "Score 2: " << current->player.score2 << endl;
        cout << "----------------------------------" << endl;
        current = current -> next;
    }
}

void computeAverage() {
    Node* current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Average Score: " << average << endl;
        cout << "----------------------------------" << endl;
        current = current->next;
    }
}

void showMaxAverage() {
    Node* current = head;
    double maxAverage = -1;
    while (current != nullptr) {
        double average = (current -> player.score1 + current->player.score2) / 2.0;
        if (average > maxAverage)
            maxAverage = average;
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        double average = (current -> player.score1 + current->player.score2) / 2.0;
        if (average == maxAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
}

void showMinAverage() {
    Node* current = head;
    double minAverage = 999999;
    while (current != nullptr) {
        double average = (current -> player.score1 + current->player.score2) / 2.0;
        if (average < minAverage)
            minAverage = average;
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        double average = (current -> player.score1 + current->player.score2) / 2.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
}

int main() {
    while (1) {
        int choice = 0;
        do {
            system("cls");
            cout << "1. Add Record" << endl;
            cout << "2. View Records" << endl;
            cout << "3. Compute Average" << endl;
            cout << "4. Show Max Average" << endl;
            cout << "5. Show Min Average" << endl;
            cout << "6. Exit" << endl;
            cout << "What would you like to do?" << endl << "> ";
            cin >> choice;
        } while (1 > choice || choice > 6);

        system("cls");
        switch (choice) {
            case 1: {
                    Player player;
                    do {
                        system("cls");
                        cout << "What would you like the nickname to be?" << endl << "> ";
                        cin >> player.nickname;
                    } while (3 > player.nickname.length() || player.nickname.length() > 16);
                    do {
                        system("cls");
                        cout << "What would you like the age to be?" << endl << "> ";
                        cin >> player.age;
                    } while (player.age < 1);
                    do {
                        system("cls");
                        cout << "What would you like the score 1 to be?" << endl << "> ";
                        cin >> player.score1;
                    } while (player.score1 < 1);
                    do {
                        system("cls");
                        cout << "What would you like the score 2 to be?" << endl << "> ";
                        cin >> player.score2;
                    } while (player.score2 < 1);
                    addRecord(player);
                    cout << "Successfully added new user.";
                }
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                computeAverage();
                break;
            case 4:
                showMaxAverage();
                break;
            case 5:
                showMinAverage();
                break;
            case 6:
                cout << "Thank you for using the program.";
                return 0;
        }

        cout << endl << "Click any key to continue.";
        getch();
    }
    return 0;
}