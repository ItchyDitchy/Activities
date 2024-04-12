#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int string_length(char* txt);
void string_compare(char* txt1, char* txt2);
void string_concatenate(char* txt1, char* txt2);

int main() {
    while (1) {
        int choice = 0;
        while (1 > choice || choice > 4) {
            system("cls");
            cout << "What do you want to do?\n";
            cout << "1. Find the string length\n";
            cout << "2. Compare two strings\n";
            cout << "3. Concatenate two strings\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                {
                    char txt[100];
                    cout << "Enter a string: ";
                    cin.ignore();
                    cin.getline(txt, 100);
                    cout << "Length of the string is: " << string_length(txt) << "\n";
                }
                break;
            case 2:
                {
                    char txt1[100];
                    cout << "Enter a string: ";
                    cin >> txt1;
                    char txt2[100];
                    cout << "Enter another string: ";
                    cin >> txt2;
                    string_compare(txt1, txt2);
                }
                break;
            case 3:
                {
                    char txt1[100];
                    cout << "Enter a string: ";
                    cin >> txt1;
                    char txt2[100];
                    cout << "Enter another string: ";
                    cin >> txt2;
                    string_concatenate(txt1, txt2);
                    cout << "Concatenated string: " << txt1 << "\n";
                }
                break;
            case 4:
                system("cls");
                cout << "Program closed.";
                return 0;
        }
        cout << "Click any key to continue.";
        getch();
    }
    return 0;
}

int string_length(char* txt) {
    int length = 0;
    while (*txt != '\0') {
        length++;
        txt++;
    }
    return length;
}

void string_compare(char* txt1, char* txt2) {
    int txt1_length = string_length(txt1);
    int txt2_length = string_length(txt2);
    if (txt1_length == txt2_length)
        cout << "The strings have the same length.\n";
    else
        cout << "The first string is " << (txt1_length > txt2_length ? "longer" : "shorter") << " than the second string.\n";
}

void string_concatenate(char* txt1, char* txt2) {
    while (*txt1 != '\0')
        txt1++;
    while (*txt2 != '\0') {
        *txt1++ = *txt2++;
    }
}