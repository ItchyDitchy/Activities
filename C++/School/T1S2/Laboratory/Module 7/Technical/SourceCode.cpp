#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct Person {
    string name;
    string course;
    string email;
    string number;
};

vector<Person> people;

void loadData();
void saveData(Person person);

int main() {
    loadData();
    while (1) {
        int choice = 0;
        do {
            system("cls");
            cout << "1. Read\n";
            cout << "2. Append\n";
            cout << "3. Exit\n> ";
            cin >> choice;
        } while (1 > choice || choice > 3);

        switch (choice) {
            case 1:
                for (Person person : people) {
                    cout << "=============================\n";
                    cout << "Name: " << person.name << "\n";
                    cout << "Course: " << person.course << "\n";
                    cout << "Email: " << person.email << "\n";
                    cout << "Number: " << person.number << "\n\n";
                }
                cout << "Click any key to continue...";
                getch();
                break;
            case 2:
                {
                    Person person;
                    do {
                        system("cls");
                        cout << "Name: ";
                        getline(cin, person.name);
                    } while (3 > person.name.length());
                    do {
                        system("cls");
                        cout << "Course: ";
                        getline(cin, person.course);
                    } while (3 > person.course.length());
                    do {
                        system("cls");
                        cout << "Email: ";
                        getline(cin, person.email);
                    } while (3 > person.email.length());
                    do {
                        system("cls");
                        cout << "Number: ";
                        getline(cin, person.number);
                    } while (3 > person.number.length());
                    system("cls");
                    people.push_back(person);
                    saveData(person);
                    cout << "Added user.";
                    getch();
                }
                break;
            case 3:
                system("cls");
                cout << "Closed the program...";
                return 0;
        }
    }
    return 0;
}

// DATABASE
void loadData() {
    ifstream db("mytxt.txt");
    if (!db.is_open()) {
        cout << "Unable to open file stream!";
        return;
    }

    string line;
    while (getline(db, line)) {
        char name[50], course[50], email[50], number[50];
        sscanf(line.c_str(), "%[^,],%[^,],%[^,],%[^,]", name, course, email, number);
        people.push_back(Person{string(name), string(course), string(email), string(number)});
    }
    db.close();
}

void saveData(Person person) {
    cout << "\nLoading file...\n";
    ofstream db("mytxt.txt", ios::app);
    cout << "Accessing file...\n";
    if (!db.is_open()) {
        cout << "Couldn't access the file!";
        getch();
        return;
    }
    db << person.name << "," << person.course << "," << person.email << "," << person.number << endl;
    db.close();
    cout << "Saved data.\n";
}