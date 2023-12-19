#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "Utility/StringUtility.cpp"
#include "ColorImpl.h"
#include <windows.h>

using namespace std;

double columnGap1 = 31;
string pages[] = {"Dashboard", "Student Records", "Student Registration", "Course Management", "Teacher Management", "Notifications", "Reports and Analytics", "About", "Changelogs"};
int pageNum = 0;
string input;
char character;
string page = pages[pageNum];
int updates = 0;
boolean isInput = false;

boolean update() { 
    if (isInput) {
    } else {
        if (character == 80 && pageNum < sizeof(pages)/sizeof(pages[0])-1) {
            pageNum++;
        } else if (character == 72 && pageNum > 0) {
            pageNum--;
        }
    }
    system("cls");
    input = input + character;
    updates++;
    page = pages[pageNum];
    cout << WHT << "┏" << StringUtility::repeatCharacter("━",104) << "┓" << "\n";
    cout <<        "┃" << setw(35) << BCYN << "Student User Interface - ItchyDitchy v0.0.01" << setw(39) << WHT << "┃" << "\n";
    cout << WHT << "┣" << StringUtility::repeatCharacter("━",26) << "┳" << StringUtility::repeatCharacter("━",77) << "┫" << "\n";
    cout << setw(1) << left << (page == "Dashboard"             ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Dashboard" + string(WHT)   << setw(1) << (page == "Dashboard"              ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Student Records"       ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Student Records"         + string(WHT)   << setw(1) << (page == "Student Records"        ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Student Registration"  ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Student Registration"    + string(WHT)   << setw(1) << (page == "Student Registration"   ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" <<  "\n";
    cout << setw(1) << left << (page == "Course Management"     ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Course Management"       + string(WHT)   << setw(1) << (page == "Course Management"      ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Teacher Management"    ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Teacher Management"      + string(WHT)   << setw(1) << (page == "Teacher Management"     ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Notifications"         ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Notifications"           + string(WHT)   << setw(1) << (page == "Notifications"          ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Reports and Analytics" ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Reports and Analytics"   + string(WHT)   << setw(1) << (page == "Reports and Analytics"  ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "About"                 ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " About"                   + string(WHT)   << setw(1) << (page == "About"                  ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << setw(1) << left << (page == "Changelogs"            ?   "┣━" + string(BWHT) : "┃ ") << setw(columnGap1) << " Changelogs"              + string(WHT)   << setw(1) << (page == "Changelogs"             ? "━┫" : " ┃") << setw(77) << ""  << setw(1) << "┃" << "\n";
    cout << WHT << "┣" << StringUtility::repeatCharacter("━",26) << "┻" << StringUtility::repeatCharacter("━",77) << "┫" << "\n";
    cout << setw(1) << left << "┃ " << setw(118)        << " [Z] Navigation   [X] Editor Panel   [C] Filter Panel   [← ↑ → ↓] Movement               [M] Quit" + string(WHT) << setw(1) << "┃"   << "\n";
    cout << WHT << "┗" << StringUtility::repeatCharacter("━",104) << "┛" << "\n";
    cout << "\nCharacter: \"" << character << "\" | Updates: " << updates << " | Pages: " << page << " | PageNum: " << pageNum << "/" << sizeof(pages)/sizeof(pages[0])-1 << " | CharacterID: " << int(character);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    update();
    do {
        character = _getch();
        update();
    } while (!isInput && !(character == 'M' || character == 'm'));
    system("cls");
    cout << BGRN << "Thank you for using the Student User Interface v0.0.01 by ItchyDitchy\n\n" << WHT;
    cout << "\nCharacter: \"" << character << "\" | Updates: " << updates << " | Pages: " << page << " | PageNum: " << pageNum << " | CharacterID: " << int(character);
    return 0;
}

string toUpper(string str) {
    for (char& c : str) {
        c = toupper(c);
    }
    return str;
}
