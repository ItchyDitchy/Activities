#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // String Inputs
    string name, address, civilStatus, gender;
    cout << "What is your name?\n";
    getline(cin, name);
    cout << "Where do you live?\n";
    getline(cin, address);
    cout << "What is your civil status?\n";
    getline(cin, civilStatus);
    cout << "What is your gender?\n";
    getline(cin, gender);

    // Double Inputs
    double ratePerHr, hoursWork, grossPay, tax;
    cout << "What is your rate per hour?\n";
    cin >> ratePerHr;
    cout << "How many hours did you work?\n";
    cin >> hoursWork;

    // Calculation
    grossPay = ratePerHr*hoursWork;
    tax = grossPay*0.2;

    // Output Data
    system("cls");
    int width = 34;
    string header = "++++++++++PAYROLL SYSTEM++++++++++";
    cout << setw((56-header.length())/2.0) << left << "" << header << "\n\n";
    cout << setw(width) << left << ("NAME: " + name) << setw(20) << ("CIVIL STATUS: " + civilStatus);
    cout << setw(35) << left << ("\nADDRESS: " + address) << setw(20) << ("GENDER: " + gender);
    cout << "\n";
    cout << setw(35) << left << "\nINCOME" << setw(20) << "DEDUCTIONS\n";
    cout << setw(35) << left << ("\nRATE PER HR: " + to_string(ratePerHr)) << setw(20) << "Pag-IBIG: 200";
    cout << setw(35) << left << ("\nHOURS WORK: " + to_string(hoursWork)) << setw(20) << "SSS: 100";
    cout << setw(35) << left << ("\nGROSS PAY: " + to_string(grossPay)) << setw(20) << ("Tax: " + to_string(tax));
    cout << setw(35) << left << "" << ("\nNET PAY: " + to_string(grossPay-tax-300));
}