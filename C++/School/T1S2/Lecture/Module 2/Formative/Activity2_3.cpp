#include <bits/stdc++.h>

int main() {
    int vowels[6] = {0, 0, 0, 0, 0, 0};
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);
    for (int i = 0; i < text.length(); i++) {
        char letter = std::tolower(text[i]);
        switch (tolower(text[i])) {
        case 'a':
            vowels[0]++;
            break;
        case 'e':
            vowels[1]++;
            break;
        case 'i':
            vowels[2]++;
            break;
        case 'o':
            vowels[3]++;
            break;
        case 'u':
            vowels[4]++;
            break;
        case ' ':
            vowels[5]++;
            break;
        }
    }
    std::cout << "A - " << vowels[0] << "\nE - " << vowels[1] << "\nI - " << vowels[2] << "\nO - " << vowels[3] << "\nU - " << vowels[4] << "\nWhitespaces - " << vowels[5];
}