#include <bits/stdc++.h>

int main() {
    std::cout << "*********************\n";
    std::cout << "STRING CONCATENATION\n";
    std::cout << "*********************\n";
    char str1[100], str2[100];
    std::cout << "Enter a first word (str1): ";
    std::cin.getline(str1, sizeof(str1));
    std::cout << "Enter a first word (str2): ";
    std::cin.getline(str2, sizeof(str2));
    strcat(str1, str2);
    std::cout << "New string value for str1: " << str1;
    return 0;
}