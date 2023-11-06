#include <iostream>
#include <iomanip>
#include <unordered_map>

// idk how to do oop here in cpp, I only know java Lol
std::unordered_map<int, Account> accounts;

class Account {
    private:
        int accountNumber;
        int password;
        bool admin = false;
        double limit = 50000;
        double balance = 0;
    public:
        Account() {
            ;
        }
        Account(int password) {

        }
        Account(int accountNumber, int password) {
            
        }
};

int main() {
    
    return 0;
}