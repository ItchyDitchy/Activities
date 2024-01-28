#include <bits/stdc++.h>

bool isPalindrome(std::string word);
std::string toLower(std::string word);

int main() {
    std::cout << "*********************\n";
    std::cout << "PALINDROME\n";
    std::cout << "*********************\n";
    std::string word;
    std::cout << "Enter a word: ";
    getline(std::cin, word);
    std::cout << word << " is" << (isPalindrome(word) ? "" : " not") << " a palindrome";
    return 0;
}

bool isPalindrome(std::string word) {
    std::string palindrome = word;
    int j = word.length() - 1;
    int i = 0;
    while (i < j)
        std::swap(palindrome[i++], palindrome[j--]);
    return toLower(word) == toLower(palindrome);
}

std::string toLower(std::string word) {
    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    return word;
}