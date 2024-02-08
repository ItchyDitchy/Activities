#include <bits/stdc++.h>
#include <conio.h>

struct Student {
    int studentID = -1;
    std::string firstName = "";
    std::string lastName = "";
    float GPA = -1;
};

void addStudent();
void displayStudents();
float calculateAverageGPA();
void findStudentsByLastName(std::string lastName);

std::string tolower(std::string txt);
std::vector<Student> students;

int main() {
    while (true) {
        int choice = 0;
        do {
            system("cls");
            std::cout << "Student Database Management System\n";
            std::cout << "1. Add Student\n";
            std::cout << "2. Display Students\n";
            std::cout << "3. Calculate Average GPA\n";
            std::cout << "4. Find Student by Last Name\n";
            std::cout << "5. Exit\n> ";
            std::cin >> choice;
        } while (1 > choice || choice > 5);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                system("cls");
                std::cout << "The average gpa is " << calculateAverageGPA() << "\n";
                std::cout << "Click any key to continue.";
                getch();
                break;
            case 4:
                {
                    std::string lastName = "";
                    do {
                        system("cls");
                        std::cout << "What last name would you like to lookup?\n> ";
                        std::cin >> lastName;
                    } while (2 > lastName.length() || lastName.length() > 50);
                    findStudentsByLastName(lastName);
                }
                break;
            case 5:
                system("cls");
                std::cout << "Thank you for using the program.";
                return 0;
        }
    }
    return 0;
}

void addStudent() {
    Student student;
    do {
        system("cls");
        std::cout << "What is the student id?\n> ";
        std::cin >> student.studentID;
    } while (1 > student.studentID);
    do {
        system("cls");
        std::cout << "What is the first name?\n> ";
        std::cin >> student.firstName;
    } while (2 > student.firstName.length() || student.firstName.length() > 50);
    do {
        system("cls");
        std::cout << "What is the last name?\n> ";
        std::cin >> student.lastName;
    } while (2 > student.lastName.length() || student.firstName.length() > 50);
    do {
        system("cls");
        std::cout << "What is the GPA?\n> ";
        std::cin >> student.GPA;
    } while (1 > student.GPA);
    students.push_back(student);
}

void displayStudents() {
    int page = 1;
    int tempPage = page;
    int pages = int(ceil(students.size()/10.0));
    do {
        tempPage = page;
        system("cls");
        int limit = std::min(int(students.size()), 10 * tempPage);
        int start = (page - 1) * 10;
        std::cout << std::left << "Page   :\t" << page << "\t/\t" << pages << "\nRecords:\t" << limit << "\t/\t" << (std::to_string(students.size()) + "\n") ;
        std::cout << std::setw(30) << "Student ID" << std::setw(50) << "First Name" << std::setw(50) << "Last Name" << std::setw(10) << "GPA\n";
        for (int i = start; i < limit; i++) {
            Student student = students[i];
            std::string studentNumber = "#" + std::to_string(student.studentID);
            std::cout << "\n" << std::setw(30) << studentNumber << std::setw(50) << student.firstName << std::setw(50) << student.lastName << std::setw(10) << student.GPA;
        }
        do {
            std::cout << "\nWhich page would you like to view? [1-" << pages << " | 0 = Exit]\n> ";
            std::cin >> tempPage;
        } while (0 > tempPage || tempPage > pages);
        page = tempPage;
    } while (page != 0);
}

float calculateAverageGPA() {
    float gpa = 0;
    for (Student student : students)
        gpa += student.GPA;
    return gpa / students.size();
}

void findStudentsByLastName(std::string lastName) {
    system("cls");
    lastName = tolower(lastName);
    for (Student student : students) {
        if (tolower(student.lastName) == lastName) {
            std::string studentNumber = "#" + std::to_string(student.studentID);
            std::cout << std::setw(30) << "Student ID" << std::setw(50) << "First Name" << std::setw(50) << "Last Name" << std::setw(10) << "GPA\n";
            std::cout << "\n" << std::setw(30) << studentNumber << std::setw(50) << student.firstName << std::setw(50) << student.lastName << std::setw(10) << student.GPA << "\n";
            std::cout << "Click any key to continue.\n";
            getch();
            return;
        }
    }
    std::cout << "No student found with that last name.\n";
    std::cout << "Click any key to continue.\n";
    getch();
}

std::string tolower(std::string txt) {
    for (char& c : txt)
        c = tolower(c);
    return txt;
}