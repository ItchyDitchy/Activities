#include <bits/stdc++.h>
#include <conio.h>
#include "ColorImpl.h"

std::string removeDuplicates(std::string text);
std::string toUpper(std::string text);
std::unordered_map<char, int> scores;

int main() {
    int size = 220;
    int attempts = 10;
    std::string text = "";
    std::string confirm = "N";

    do {
        text = "";

        do {
            system("cls");
            std::cout << "Input a word for the user to guess! [3-16 characters]\n> ";
            std::cin >> text;
        } while (3 > text.length() || text.length() > 16);

        text = toUpper(text);
        std::string chars = removeDuplicates(text);

        scores.clear();
        for (int i = 0; i < chars.length(); i++) {
            std::cout << chars << " Input the point value for letter " << char(toupper(chars[i])) << "\n> ";
            std::cin >> scores[chars[i]];
        }

        std::cout << "Proceed [Y/N]\n> ";
        std::string input = "";
        std::cin >> input;
        confirm = toupper(input[0]);
    } while (confirm != "Y");

    std::string guess = "";
    std::string clue = "";

    do {
        system("cls");

        std::cout << "\n" << WHT;
        std::cout << std::setw(size/2) << "Guess the word!\n";
        std::cout << std::setw(size/2) << "Clue:\n";
        std::cout << std::setw(size/2) << "- " << text.length() << " Characters\n";
        std::cout << std::setw(size/2) << "> ";
        std::cin >> guess;

        guess = toUpper(guess);

        std::cout << std::setw(size/2) << "You are wrong!\n";
        for (int i = 0; i < guess.length(); i++) {
            for (int j = 0; j < text.length(); j++) {
                if (guess[i] == text[j])
                    clue += guess[i];
            }
        }
        clue = removeDuplicates(clue);
        int score = 0;
        for (int i = 0; i < clue.length(); i++) {
            score += scores.at(toupper(clue[i]));
            std::cout << char(toupper(clue[i])) << " " << scores.at(toupper(clue[i])) << "\n";
        }
        getch();

        if (guess == text) {
            system("cls");
            std::cout << "You got the word in " << std::max(0, 11-attempts) << " attempt(s)!\n";
            std::cout << "You've got a score of " << score << ".\n";
            std::cout << "Congratulations! ^_^";
            return 0;
        }

        attempts--;
        if (clue.length() > 0) {
            std::cout << std::setw(size/2) << "Clue: With \"" << clue << "\" character(s)\n";
        }
        std::cout << std::setw(size/2) << "You currently have a score of " << score << ".\n";
        std::cout << std::setw(size/2) << "You have " << attempts << " attempts left.\n";
        std::cout << GRN << "#####";
        for (int i = 0; i < size; i++) {
            std::cout << ".";
        }
        std::cout << "\n" << WHT;
        std::cout << "Click any key to continue.";
        getch();
    } while (attempts > 0);
    if (attempts == 0) {
        system("cls");
        std::cout << "Come on dude, you've input the word, but you've guessed wrong?";
    };
    return 0;
}

std::string toUpper(std::string text) {
    for (int i = 0; i < text.length(); i++)
        text[i] = toupper(text[i]);
    return text;
}

std::string removeDuplicates(std::string text) {
    for (int i = 0; i < text.size(); i++)
        for (int j = i + 1; j < text.size(); j++) {
            if (text[i] == text[j]) {
                text.erase(j, 1 );
                continue;
            }
            j++;
        }
    return text;
}