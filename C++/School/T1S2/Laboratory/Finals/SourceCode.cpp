#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

string genders[3] = {"MALE", "FEMALE", "OTHER"};
string months[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Student {
    Student* next;
    long long int idNumber = -1;
    string fullName;
    string birthday;
    string address;
    int gender;
    string degreeProgram;
    int yearLevel;
};

Student* head = nullptr;

void loadData();
void saveData();

void addRecord(long long int idNumber, string fullName, string birthday, string address, int gender, string degreeProgram, int yearLevel);
bool isStudent(long long int idNumber);
vector<Student> searchStudent(string txt);
Student searchStudent(long long int idNumber);
bool removeRecord(long long int idNumber);

void displayStudent(Student student);

bool isLeapYear(int year);

bool contains(string txt, string find);
string toLower(string txt);
string titleCase(string txt);

int main() {
    loadData();
    while (1) {
        int choice = 0;
        do {
            system("cls");
            cout << "What do you want to do?\n";
            cout << "1. Add New Record\n";
            cout << "2. Search Record\n";
            cout << "3. Display All Records\n";
            cout << "4. Display Specific Record\n";
            cout << "5. Delete Record\n";
            cout << "6. Exit\n";
            cout << "\nPlease type your selection: ";
            cin >> choice;
        } while (1 > choice || choice > 6);

        system("cls");

        switch (choice) {
            case 1:
                {
                    long long int idNumber = -1;
                    do {
                        system("cls");
                        cout << "ID Number [Number]: ";
                        cin.clear();
                        cin >> idNumber;
                    } while (0 > idNumber);

                    if (isStudent(idNumber)) {
                        system("cls");
                        cout << "That student already exists!\n";
                        break;
                    }

                    string fullName;
                    do {
                        system("cls");
                        cout << "Full Name [Text]: ";
                        cin.clear();
                        getline(cin, fullName);
                    } while (fullName.empty() || fullName.length() > 100 || contains(fullName, ";"));

                    int year = -1;
                    do {
                        system("cls");
                        cout << "Birth Year [Number]: ";
                        cin.clear();
                        cin >> year;
                    } while (1900 > year);

                    int month = -1;
                    do {
                        system("cls");
                        cout << "1. January\n";
                        cout << "2. February\n";
                        cout << "3. March\n";
                        cout << "4. April\n";
                        cout << "5. May\n";
                        cout << "6. June\n";
                        cout << "7. July\n";
                        cout << "8. August\n";
                        cout << "9. September\n";
                        cout << "10. October\n";
                        cout << "11. November\n";
                        cout << "12. December\n";
                        cout << "Birth Month: ";
                        cin >> month;
                    } while (1 > month || month > 12);

                    int day = -1;
                    do {
                        system("cls");
                        cout << "Birth day [Number]: ";
                        cin.clear();
                        cin >> day;
                    } while (0 > day || day > days[month-1] + (month == 2 && isLeapYear(year) ? 1 : 0));

                    string address;
                    do {
                        system("cls");
                        cout << "Address [Text]: ";
                        cin.clear();
                        getline(cin, address);
                    } while (address.empty() || address.length() > 100 || contains(address, ";"));

                    int gender;
                    do {
                        system("cls");
                        cout << "1. Male\n";
                        cout << "2. Female\n";
                        cout << "3. Other\n";
                        cout << "Gender [Number]: ";
                        cin.clear();
                        cin >> gender;
                    } while (1 > gender || gender > 3);

                    string degreeProgram;
                    do {
                        system("cls");
                        cout << "Degree Program [Text]: ";
                        cin.clear();
                        getline(cin, degreeProgram);
                    } while (degreeProgram.empty() || degreeProgram.length() > 100 || contains(degreeProgram, ";"));

                    int yearLevel = -1;
                    do {
                        system("cls");
                        cout << "Year Level [Integer]: ";
                        cin.clear();
                        cin >> yearLevel;
                    } while (1 > yearLevel || yearLevel > 16);

                    addRecord(idNumber, titleCase(fullName), months[month-1] + " " + to_string(day) + ", " + to_string(year), titleCase(address), gender - 1, titleCase(degreeProgram), yearLevel);
                    cout << "User has been saved.\n";
                    saveData();
                }
                break;
            case 2:
                {
                    string txt = "";
                    do {
                        system("cls");
                        cout << "Text to find [Text]: ";
                        cin.clear();
                        getline(cin, txt);
                    } while (1 > txt.length() || txt.length() > 30 || contains(txt, ";"));
                    vector<Student> students = searchStudent(txt);
                    for (Student student : students) {
                        displayStudent(student);
                    }
                    cout << "\nFound " << students.size() << " students from the key.\n\n";
                }
                break;
            case 3:
                {
                    Student* current = head;
                    int total = 0;
                    while (current != nullptr) {
                        displayStudent(*current);
                        total++;
                        current = current -> next;
                    }

                    cout << "\nFound " << total << " students.\n\n";
                }
                break;
            case 4:
                {
                    long long int idNumber = -1;
                    do {
                        system("cls");
                        cout << "Student ID Number [Number]: ";
                        cin >> idNumber;
                    } while (0 > idNumber);

                    Student student = searchStudent(idNumber);
                    if (student.idNumber < 0) {
                        cout << "There is no student with that ID Number.\n";
                        break;
                    }
                    displayStudent(student);
                    cout << "\nFound the student.\n\n";
                }
                break;
            case 5:
                {
                    long long int idNumber = -1;
                    do {
                        system("cls");
                        cout << "Student ID Number [Number]: ";
                        cin >> idNumber;
                    } while (0 > idNumber);

                    if (removeRecord(idNumber)) {
                        cout << "Student Record with ID Number " << idNumber << " has been removed.\n";
                        saveData();
                        break;
                    }

                    cout << "There is no student with that ID Number.\n";
                }
                break;
            case 6:
                cout << "\nThank you for using the program.";
                return 0;
        }
        cout << "Click any key to continue...";
        getch();
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

    string line;
    while (getline(db, line)) {
        char idNumber[100], fullName[100], birthday[100], address[100], gender[100], degreeProgram[100], yearLevel[100];
        sscanf(line.c_str(), "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]", idNumber, fullName, birthday, address, gender, degreeProgram, yearLevel);
        addRecord(stoll(idNumber), string(fullName), string(birthday), string(address), stoi(gender), string(degreeProgram), stoi(yearLevel));
    }
    db.close();
}

void saveData() {
    cout << "\nLoading file...\n";
    ofstream db("database.txt");
    cout << "Accessing file...\n";
    if (!db.is_open()) {
        cout << "Couldn't access the file!";
        getch();
        return;
    }

    Student* current = head;
    do {
        db << current -> idNumber << ";" << current -> fullName << ";" << current -> birthday << ";" << current -> address << ";" << current -> gender << ";" << current -> degreeProgram << ";" << current -> yearLevel << endl;
    } while ((current = current -> next) != nullptr);
    db.close();
    cout << "Saved data.\n";
}

// LINKED LIST & FUNCTIONS
void addRecord(long long int idNumber, string fullName, string birthday, string address, int gender, string degreeProgram, int yearLevel) {
    Student* newStudent = new Student{nullptr, idNumber, fullName, birthday, address, gender, degreeProgram, yearLevel};

    if (head == nullptr)
        head = newStudent;
    else {
        Student* current = head;
        while (current -> next != nullptr)
            current = current -> next;
        current -> next = newStudent;
    }
}

bool isStudent(long long int idNumber) {
    Student* current = head;
    while (current != nullptr) {
        if (current -> idNumber == idNumber)
            return true;
        current = current -> next;
    }
    return false;
}

vector<Student> searchStudent(string txt) {
    vector<Student> students;
    Student* current = head;
    while (current != nullptr) {
        string compile = to_string(current -> idNumber) + ";" +
            current -> fullName + ";" +
            current -> birthday + ";" +
            current -> address + ";" +
            to_string(current -> gender) + ";" +
            current -> degreeProgram + ";" +
            to_string(current -> yearLevel) + ";";
        if (contains(compile, txt))
            students.push_back(*current);
        current = current -> next;
    }
    return students;
}

Student searchStudent(long long int idNumber) {
    Student* current = head;
    while (current != nullptr) {
        if (current -> idNumber == idNumber)
            return *current;
        current = current -> next;
    }
    return Student();
}

bool removeRecord(long long int idNumber) {
    if (head == nullptr)
        return false;

    if (head -> idNumber == idNumber) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Student* current = head;
    while (current -> next != nullptr) {
        if (current -> next -> idNumber == idNumber) {
            Student* toDelete = current -> next;
            current->next = toDelete -> next;
            delete toDelete;
            return true;
        }
        current = current->next;
    }

    return false;
}

void displayStudent(Student student) {
    cout << "=============================\n";
    cout << "Student ID Number: " << student.idNumber << "\n";
    cout << "Full Name: " << student.fullName << "\n";
    cout << "Birthday: " << student.birthday << "\n";
    cout << "Address: " << student.address << "\n";
    cout << "Gender: " << genders[student.gender] << "\n";
    cout << "Degree Program: " << student.degreeProgram << "\n";
    cout << "Year Level: " << student.yearLevel << "\n";
}

// STRING UTILS
bool contains(string txt, string find) {
    txt = toLower(txt);
    find = toLower(find);
    return txt.find(find) != string::npos;
}

string toLower(string txt) {
    for (char& c : txt)
        c = tolower(c);
    return txt;
}

// OTHER
bool isLeapYear(int year) {
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

string titleCase(string txt) {
    for (int i = 0; i < txt.length(); i++)
        txt[i] = isspace(txt[i-1]) ? toupper(txt[i]) : tolower(txt[i]);
    return txt;
}
