#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cout << "Enter some string: ";
    getline(std::cin, str);
    for (int i = 0; i < str.length(); i++)
        str[i] = isspace(str[i-1]) ? toupper(str[i]) : tolower(str[i]);
    std::cout << str;
}