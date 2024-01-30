#include <bits/stdc++.h>
#include <conio.h>
#include "Player.cpp"

std::vector<Player> players = {};

void loadPlayers();
void addRecord();
void viewPlayersRecord();
void viewAverage();
void viewMaxAverage();
void viewMinAverage();

int main() {
    loadPlayers();

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
                viewPlayersRecord();
                break;
            case 3:
                viewAverage();
                break;
            case 4:
                viewMaxAverage();
                break;
            case 5:
                //viewMinAverage();
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

void loadPlayers() {
    std::ifstream db("database.txt");
    if (!db.is_open())
        return;

    std::string data;
    db >> data;
    std::string name = "";
    std::string builder = "";

    for (char c : data) {
        if (c == ',') {
            name = builder;
            builder = "";
            continue;
        }
        if (c == ';') {
            Player player = {name, std::stoi(builder)};
            players.push_back(player);
            builder = "";
            name = "";
            continue;
        }
        builder += c;
    }
    db.close();
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

    int score = -1;
    do {
        system("cls");
        std::cout << "What is the score?\n> ";
        std::cin >> score;
    } while (0 > score);
    system("cls");

    std::cout << "Creating player data...\n";
    Player player = {name, score};
    players.push_back(player);

    system("cls");
    std::cout << "Saving player data...\n";

    std::ofstream db("database.txt", std::ios_base::app);
    if (!db.is_open()) {
        std::cout << "Error let's go!"; // Stay positive.
        return;
    }
    std::cout << "Saving data...\n";
    db << name << "," << score << ";";
    db.close();

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
        for (int i = start; i < limit; i++) {
            Player player = players[i];
            std::cout << "#" << (i + 1) << "\t" << player.name;
            for (int i = 0; i < 20-player.name.length(); i++)
                std::cout << " ";
            std::cout << player.score << "\n";
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
        total += player.score;
    system("cls");
    std::cout << "The average score is " << (total/double(players.size())) << ".";
}

void viewMaxAverage() {
    std::unordered_map<std::string, std::pair<double, int>> scores;
    for (const Player& player : players) {
        if (scores.find(player.name) == scores.end()) {
            std::pair<double, int> scorePair = { player.score, 1 };
            scores[player.name] = scorePair;
        }
        else {
            scores[player.name].first += player.score;
            scores[player.name].second++;
        }
    }
    std::string name = "";
    double highest = 0;
    for (auto& pair : scores) {
        double average = pair.second.first / pair.second.second;
        if (highest < average) {
            highest = average;
            name = pair.first;
        }
    }
    std::cout << "The highest average out of " << scores.size() << " players is " << name << "'s at " << highest << "\n";
    std::cout << "Click any key to continue.";
    getch();
}

void viewMinAverage() {
    std::unordered_map<std::string, std::pair<double, int>> scores;
    for (const Player& player : players) {
        if (scores.find(player.name) == scores.end()) {
            std::pair<double, int> scorePair = { player.score, 1 };
            scores[player.name] = scorePair;
        }
        else {
            scores[player.name].first += player.score;
            scores[player.name].second++;
        }
    }
    std::string name = "";
    double lowest = 0;
    for (auto& pair : scores) {
        double average = pair.second.first / pair.second.second;
        if (lowest > average) {
            lowest = average;
            name = pair.first;
        }
    }
    std::cout << "The lowest average out of " << scores.size() << " players is " << name << "'s at " << lowest << "\n";
    std::cout << "Click any key to continue.";
    getch();
}