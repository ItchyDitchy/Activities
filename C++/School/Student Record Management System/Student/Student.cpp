#include <string>

using namespace std;

class Student {
    public:
        long getID() {
            return id;
        }

        long getCreationTime() {
            return creationTime;
        }

        string getName() {
            return prefix + " " + firstName + " " + middleName + " " + surname + " " + suffix;
        }

        string getFirstName() {
            return firstName;
        }

        string getMiddleName() {
            return middleName;
        }

        string getSurname() {
            return surname;
        }

        string getPrefix() {
            return prefix;
        }

        string getSuffix() {
            return suffix;
        }

        string getProgram() {
            return program;
        }

        string getStatus() {
            return status;
        }

        string getType() {
            return type;
        }

        string getAcademicStanding() {
            return academicStanding;
        }

        int getYear() {
            return year;
        }

    private:
        long id, creationTime, birthDate;
        string firstName, middleName, surname, prefix, suffix,
            program, status, type, academicStanding;
        int year;
};