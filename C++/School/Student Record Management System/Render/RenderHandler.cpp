#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

static string repeatCharacter(char character, int numTimes) {
    string repeatedString;
    for (int i = 0; i < numTimes; i++) {
        repeatedString += character;
    }
    return repeatedString;
}

int main() {
    std::cout << "Enter your input (press Enter to finish): ";

    char ch;
    std::string input;

    while ((ch = _getch()) != '\r') {  // '\r' represents the Enter key
        char cha = toupper(ch);
        //std::cout << cha;  // Echo the character
        input += ch;  // Append the character to the input string
    }

    std::cout << std::endl;
    std::cout << "Input recorded: " << input << std::endl;

    return 0;
}

string toUpper(string str) {
    for (char& c : str) {
        c = std::toupper(c);
    }
    return str;
}