#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    getline(std::cin, str);

    int spaces = 0;
    for (char c : str)
        if (isspace(c))
            spaces++;

    std::vector<std::string> words(spaces + 1);
    int spaceIndex = spaces;
    for (char c : str) {
        if (isspace(c)) {
            spaceIndex--;
            continue;
        }
        words[spaceIndex] += c;
    }

    for (std::string word : words)
        std::cout << word << "\n";
    return 0;
}