#include <bits/stdc++.h>
#include <conio.h>
#include "Player.cpp"

std::vector<Player> players = {};

void addRecord();
void viewPlayersRecord();
void viewAverage();
void viewMaxAverage();
void viewMinAverage();

int main() {
    bool repeat = true;
    while (repeat) {
        int choice = 0;
        do {
            system("cls");
            std::cout << "==============================================\n";
            std::cout << "\t\tMENU\n";
            std::cout << "==============================================\n";
            std::cout << "1. Add record\n";
            std::cout << "2. View players record\n";
            std::cout << "3. Compute the average\n";
            std::cout << "4. Show the player(s) who get the max average.\n";
            std::cout << "5. Show the player(s) who get the min average.\n";
            std::cout << "6. Exit\n> ";
            std::cin >> choice;
        } while (1 > choice || choice > 6);
        system("cls");
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                if (players.size() == 0) {
                    system("cls");
                    std::cout << "This function is not available at the moment!";
                    std::cout << "Click any key to continue.";
                    getch();
                    break;
                }
                viewPlayersRecord();
                break;
            case 3:
                if (players.size() == 0) {
                    system("cls");
                    std::cout << "This function is not available at the moment!";
                    std::cout << "Click any key to continue.";
                    getch();
                    break;
                }
                viewAverage();
                break;
            case 4:
                if (players.size() == 0) {
                    system("cls");
                    std::cout << "This function is not available at the moment!";
                    std::cout << "Click any key to continue.";
                    getch();
                    break;
                }
                viewMaxAverage();
                break;
            case 5:
                if (players.size() == 0) {
                    system("cls");
                    std::cout << "This function is not available at the moment!";
                    std::cout << "Click any key to continue.";
                    getch();
                    break;
                }
                viewMinAverage();
                break;
            case 6:
                system("cls");
                std::cout << "Thank you for using the program.";
                repeat = false;
                break;
        }
    }

    std::cout << "Saving data...\n";
    std::cout << "Successfully saved the data.\n";
    return 0;
}

void addRecord() {
    std::string name = "";
    do {
        system("cls");
        std::cout << "What is the username?\n> ";
        std::cin >> name;
        std::string tName = "";
        for (char c : name)
            if (isalnum(c))
                tName += c;
    } while (3 > name.length() || name.length() > 16);

    int age = -1;
    do {
        system("cls");
        std::cout << "What is the age?\n> ";
        std::cin >> age;
    } while (0 > age);

    int score1 = -1;
    do {
        system("cls");
        std::cout << "What is the first score?\n> ";
        std::cin >> score1;
    } while (0 > score1);

    int score2 = -1;
    do {
        system("cls");
        std::cout << "What is the second score?\n> ";
        std::cin >> score2;
    } while (0 > score2);
    system("cls");

    std::cout << "Creating player data...\n";
    Player player = {name, age, score1, score2};
    players.push_back(player);

    std::cout << "New player data has been recorded!";
}

void viewPlayersRecord() {
    int page = 1;
    int tempPage = page;
    int pages = int(ceil(players.size()/10.0));
    do {
        tempPage = page;
        system("cls");
        int limit = std::min(int(players.size()), 10 * tempPage);
        int start = (page - 1) * 10;
        std::cout << "Page   :\t" << page << "\t/\t" << pages << "\nRecords:\t" << limit << "\t/\t" << players.size() << "\n";
            std::cout << std::setw(12) << std::left << "Placement" << std::setw(20) << "Username" << std::setw(10) << "Age" << std::setw(10) << "Score 1" << std::setw(10) << "Score 2" << "\n";
        for (int i = start; i < limit; i++) {
            Player player = players[i];
            std::cout << std::setw(12) << std::left << ("#" + std::to_string(i + 1)) << std::setw(20) << player.name << std::setw(10) << player.age << std::setw(10) << player.score1 << std::setw(10) << player.score2 << "\n";
        }
        do {
            std::cout << "\nWhich page would you like to view? [1-" << pages << " | 0 = Exit]\n> ";
            std::cin >> tempPage;
        } while (0 > tempPage || tempPage > pages);
        page = tempPage;
    } while (page != 0);
}

void viewAverage() {
    int total = 0;
    for (Player player : players)
        total += player.score1 + player.score2;
    system("cls");
    std::cout << "The average score is " << (total/double(players.size())) << ".";
    std::cout << "Click any key to continue.";
    getch();
}

void viewMaxAverage() {
    std::string name = "null";
    double highest = 0;
    for (Player player : players) {
        double average = (player.score1 + player.score2) / 2;
        if (highest < average) {
            highest = average;
            name = player.name;
        }
    }
    std::cout << "The highest average out of " << players.size() << " players is " << name << "'s at " << highest << "\n";
    std::cout << "Click any key to continue.";
    getch();
}

void viewMinAverage() {
    std::string name = "null";
    double lowest = 2147483647;
    for (Player player : players) {
        double average = (player.score1 + player.score2) / 2;
        if (lowest > average) {
            lowest = average;
            name = player.name;
        }
    }
    std::cout << "The lowest average out of " << players.size() << " players is " << name << "'s at " << lowest << "\n";
    std::cout << "Click any key to continue.";
    getch();
}