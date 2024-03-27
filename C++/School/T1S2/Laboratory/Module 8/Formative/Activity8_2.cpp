#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
    public:
        string admissionNumber;
        string name;
        int english, math, science;

        int getAverage() {
            return (english + math + science) / 3;
        }
};

int main() {
    vector<Student> students;
    while (students.size() < 5) {
        Student student;
        cout << "Enter admission number: ";
        cin >> student.admissionNumber;

        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, student.name);

        do {
            cout << "Enter grades in English, Math, Science:" << "\n";
            cin >> student.english >> student.math >> student.science;
        } while (student.english < 1 || student.math < 1 || student.science < 1);
        students.push_back(student);
        cout << "\n\n\n";
    }

    int totalAverage = 0;
    for (Student student : students) {
        cout << "Admission number: " << student.admissionNumber << "\n";
        cout << "Student name: " << student.name << "\n";
        cout << "English: " << student.english << "\n";
        cout << "Math: " << student.math << "\n";
        cout << "Science: " << student.science << "\n";
        int average = student.getAverage();
        cout << "Average: " << average << "\n\n";
        totalAverage += average;
    }
    cout << "\n\n\nTotal Average: " << totalAverage / students.size();
    return 0;
}