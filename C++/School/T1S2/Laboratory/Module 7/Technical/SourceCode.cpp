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
void saveData();

int main() {
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
        Person person;
        sscanf(line.c_str(), "%[^,],%[^,],%[^,],%[^,]", person.name, person.course, person.email, person.number);
        people.push_back(person);
    }
    db.close();
}

void saveData() {
    cout << "\nLoading file...\n";
    ofstream db("mytxt.txt");
    cout << "Accessing file...\n";
    if (!db.is_open()) {
        cout << "Couldn't access the file!";
        getch();
        return;
    }

    cout << "Saving shopping cart...\n";
    for (Person person : people)
        db << person.name << ";" << person.course << ";" << person.email << ";" << person.number << endl;
    db.close();
    cout << "Saved data.\n";
}