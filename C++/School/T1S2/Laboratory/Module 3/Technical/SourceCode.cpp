#include <bits/stdc++.h>

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyza";
    std::cout << "Original string: " << word << "\n";
    for (char& c : word) {
        char nextChar = alphabet[alphabet.find_first_of(tolower(c))+1];
        c = isupper(c) ? toupper(nextChar) : nextChar;
    }
    std::cout << "New String: " << word;
    return 0;
}