#include <bits/stdc++.h>

int main() {
    std::string words[5] = {"", "", "", "", ""};
    for (int i = 0; i < 5; i++) {
        do {
            system("cls");
            std::cout << "Enter word #" << (i+1) << "[>3 Characters]: ";
            std::cin >> words[i];
        } while (words[i].length() < 3);
    }

    system("cls");
    std::cout << "Word Simulation:";

    int tUpperCase = 0;
    int tLowerCase = 0;
    int tDigits = 0;
    int tPunctuation = 0;

    for (int i = 0; i < 5; i++) {
        int upperCase = 0;
        int lowerCase = 0;
        int digits = 0;
        int punctuation = 0;

        for (int j = 0; j < words[i].length(); j++) {
            if (isupper(words[i][j]))
                upperCase++;
            if (islower(words[i][j]))
                lowerCase++;
            if (isdigit(words[i][j]))
                digits++;
            if (!isalnum(words[i][j]))
                punctuation++;
        }

        std::cout << "\n" << words[i] << " > ";

        if (upperCase)
            std::cout << " " << upperCase << " Uppercase";
        if (lowerCase)
            std::cout << " " << lowerCase << " Lowercase";
        if (digits)
            std::cout << " " << digits << " Digits";
        if (punctuation)
            std::cout << " " << punctuation << " Punctuations";

        tUpperCase += upperCase;
        tLowerCase += lowerCase;
        tDigits += digits;
        tPunctuation += punctuation;
    }

    std::cout << "\n\nSummary: ";
    std::cout << "\nUppercase: " << tUpperCase;
    std::cout << "\nLowercase: " << tLowerCase;
    std::cout << "\nDigits: " << tDigits;
    std::cout << "\nPunctuations: " << tPunctuation;
    return 0;
}