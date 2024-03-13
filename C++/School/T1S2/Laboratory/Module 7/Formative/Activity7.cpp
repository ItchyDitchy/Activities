#include <iostream>
#include <fstream>
#include <String>
#include <conio.h>

using namespace std;

struct Player {
    string nickname;
    int age;
    double scores[5];
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
        cout << "Scores: ";
        for (int i = 0; i < 5; i++)
            cout << current->player.scores[i] << " ";
        cout << endl << "----------------------------------" << endl;
        current = current->next;
    }
}

void computeAverage() {
    Node* current = head;
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += current->player.scores[i];
        double average = sum / 5.0;
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
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += current->player.scores[i];
        double average = sum / 5.0;
        if (average > maxAverage)
            maxAverage = average;
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += current -> player.scores[i];
        double average = sum / 5.0;
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
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += current -> player.scores[i];
        double average = sum / 5.0;
        if (average < minAverage)
            minAverage = average;
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += current -> player.scores[i];
        double average = sum / 5.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
}

void openFile() {
    ofstream outFile("player_records.txt");
    Node* current = head;
    while (current != nullptr) {
        outFile << current -> player.nickname << endl;
        outFile << current -> player.age << endl;
        for (int i = 0; i < 5; i++)
            outFile << current->player.scores[i] << "";
        outFile << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Records saved to 'player_records.txt'." << endl;
}

void closeFile() {
    cout << "File closed." << endl;
}

int main() {
    openFile();
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

                    system("cls");
                    cout << "What would you like the scores to be?" << endl << "> ";
                    for (int i = 0; i < 5; i++)
                    cin >> player.scores[i];
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
                closeFile();
                return 0;
        }

        cout << endl << "Click any key to continue.";
        getch();
    }
    return 0;
}