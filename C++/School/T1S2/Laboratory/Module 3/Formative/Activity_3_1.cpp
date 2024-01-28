#include <bits/stdc++.h>

int main() {
    std::cout << "*********************\n";
    std::cout << "STRING COMPARE\n";
    std::cout << "*********************\n";
    char firstWord[100];
    char secondWord[100];
    std::cout << "Enter a first word (str1): ";
    std::cin.getline(firstWord, sizeof(firstWord));
    std::cout << "Enter a second word (str2): ";
    std::cin.getline(secondWord, sizeof(secondWord));
    int result = strcmp(firstWord, secondWord);
    std::cout << (result == 0 ? "equal" : (result > 0 ? "positive" : "negative"));
    return 0;
}