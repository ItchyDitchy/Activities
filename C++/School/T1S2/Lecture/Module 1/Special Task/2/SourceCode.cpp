#include <bits/stdc++.h>
#include <conio.h>

#include "SSS.cpp"

std::string userName;
std::string position;

double totalSalary = -1;

double basicPay = -1;
double allowance = -1;
double incentives = -1;

double monthlyContributions;

double sss = -1;
double philHealth = -1;
double pagIBIG = 100;

double grossPay;
double tax;
double totalDeduction;

int main() {
    do {
        system("cls");
        std::cout << "What would you like your username to be?\n> ";
        getline(std::cin, userName);
        userName += " ";
    } while (userName.length() <= 1);
    userName = userName.substr(0, userName.find(" "));

    do {
        system("cls");
        std::cout << "Hello " << userName << "!\n";
        std::cout << "What position do you have in your company?\n> ";
        getline(std::cin, position);
    } while (position.length() <= 1);
    position = position.substr(0, position.find(" "));

    do {
        system("cls");
        std::cout << "Welcome to the Employee Payroll Calculator!\n";
        std::cout << "Let us compute your payroll.\n";
        std::cout << "How much is basic pay?\n> ";
        std::cin >> basicPay;
    } while (basicPay < 0);

    do {
        system("cls");
        std::cout << "How about your allowance?\n> ";
        std::cin >> allowance;
    } while (allowance < 0);

    do {
        system("cls");
        std::cout << "Your incentives?\n> ";
        std::cin >> incentives;
    } while (incentives < 0);

    system("cls");
    std::cout << "Currently, you have a gross pay of " << (totalSalary = basicPay + allowance) << ".\n";
    std::cout << "Let us now start with your monthly contributions!\n";
    std::cout << "Please click any key to continue.";
    getch();

    system("cls");
    std::cout << "Let us continue with your monthly contributions.\n";
    std::cout << "Your SSS calculates at " << (sss = calculateSSS(totalSalary)) << ".\n";
    std::cout << "Your PhilHealth calculates at " << (philHealth = totalSalary * 0.045 / 2) << ".\n";
    std::cout << "Your Pag-IBIG calculates at... Oh wait, this is could be changed by you.\n";
    std::cout << "Please click any key to continue.";
    getch();

    do {
        system("cls");
        std::cout << "How much do you save with Pag-IBIG?\n> ";
        std::cin >> pagIBIG;
    } while (pagIBIG < 100);

    system("cls");
    std::cout << "You have a total of " << (monthlyContributions = sss + philHealth + pagIBIG) << " in monthly contributions!\n";
    std::cout << "We should continue with your taxes then :)\n";
    std::cout << "Please click any key to continue.";
    getch();

    system("cls");
    grossPay = totalSalary + incentives;
    std::cout << "Your taxes calculate at " << (tax = grossPay - 0.2 * totalSalary) << ".\n";
    std::cout << "With that, your total deduction is equal to " << (totalDeduction = monthlyContributions + tax) << ".\n";
    double netPay = grossPay - totalDeduction;
    std::cout << "Your net pay is equal to " << netPay << ".\n";
    std::cout << "Please click any key to continue.";
    getch();

    system("cls");
    std::cout << "Here is a summary of your payroll.\n";
    std::cout << "\nBASIC DETAILS:\n";
    std::cout << "Username: " << userName << "\n";
    std::cout << "Position: " << position << "\n";
    std::cout << "\nGENERAL SALARY\n";
    std::cout << "Basic Pay: " << basicPay << "\n";
    std::cout << "Allowance: " << allowance << "\n";
    std::cout << "Incentives: " << incentives << "\n";
    std::cout << "\nGOVERNMENT CONTRIBUTIONS\n";
    std::cout << "SSS: " << sss << "\n";
    std::cout << "Phil Health: " << philHealth << "\n";
    std::cout << "Pag-Ibig: " << pagIBIG << "\n";
    std::cout << "\nTAXES\n";
    std::cout << "Tax: " << tax << "\n";
    std::cout << "\nRESULTS\n";
    std::cout << "Total Deduction: " << totalDeduction << "\n";
    std::cout << "Net Pay: " << netPay << "\n";

    std::cout << "Please click any key to continue.";
    getch();
    system("cls");
    std::cout << "Thank you for using this simple employee payroll calculator.";
    return 0;
}