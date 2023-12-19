#include <iostream>

using namespace std;

int main() {
    double monthlySales, income;
    cout << "Monthly Sales: ";
    cin >> monthlySales;
    if (monthlySales >= 50000)
        income = 575 + monthlySales * 0.16;
    else if (monthlySales >= 40000)
        income = 550 + monthlySales * 0.14;
    else if (monthlySales >= 30000)
        income = 525 + monthlySales * 0.12;
    else if (monthlySales >= 20000)
        income = 500 + monthlySales * 0.09;
    else if (monthlySales >= 10000)
        income = 450 + monthlySales * 0.03;
    else
        income = 400 + 0.03 * monthlySales;
    cout << "Income: " << income;
}