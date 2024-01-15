#include <bits/stdc++.h>

int letterToNumber(char letter) {
    letter = tolower(letter);
    return letter - 'a' + 1;
}
int main() {
    char letter;
    std::cin >> letter;
    std::cout << " : " << letterToNumber(letter);
}
