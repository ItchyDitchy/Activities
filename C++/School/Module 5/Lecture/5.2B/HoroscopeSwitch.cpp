#include <iostream>
#include <string>

using namespace std;

int main() {
    int month, day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    switch (month) {
        case 1:
            cout << "Zodiac sign for January " << day << " is " << (day >= 20 ? "Aquarius" : "Capricorn");
            break;
        case 2:
            cout << "Zodiac sign for February " << day << " is " << (day >= 19 ? "Pisces" : "Aquarius");
            break;
        case 3:
            cout << "Zodiac sign for March " << day << " is " << (day >= 21 ? "Aries" : "Pisces");
            break;
        case 4:
            cout << "Zodiac sign for April " << day << " is " << (day >= 20 ? "Taurus" : "Aries");
            break;
        case 5:
            cout << "Zodiac sign for May " << day << " is " << (day >= 20 ? "Gemini" : "Taurus");
            break;
        case 6:
            cout << "Zodiac sign for June " << day << " is " << (day >= 21 ? "Cancer" : "Gemini");
            break;
        case 7:
            cout << "Zodiac sign for July " << day << " is " << (day >= 21 ? "Leo" : "Cancer");
            break;
        case 8:
            cout << "Zodiac sign for August " << day << " is " << (day >= 23 ? "Virgo" : "Leo");
            break;
        case 9:
            cout << "Zodiac sign for September " << day << " is " << (day >= 23 ? "Libra" : "Virgo");
            break;
        case 10:
            cout << "Zodiac sign for October " << day << " is " << (day >= 23 ? "Scorpio" : "Libra");
            break;
        case 11:
            cout << "Zodiac sign for November " << day << " is " << (day >= 22 ? "Sagittarius" : "Scorpio");
            break;
        case 12:
            cout << "Zodiac sign for December " << day << " is " << (day >= 22 ? "Capricorn" : "Sagittarius");
            break;
        default:
            cout << "Invalid date!";
    }
    return 0;
}