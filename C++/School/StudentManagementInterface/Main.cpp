#include <string>
#include <iostream>
#include "ColorImpl.h"

using std::string;
using std::cout;

string defaultProfile[] = {
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉",
    "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"
};

void replaceAll(string& str, const string& oldSubstr, const string& newSubstr) {
    size_t pos = 0;
    while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length();
    }
}

void parseColor(string& str) {
    replaceAll(str, "&#", "\033[38;2;#");
}

// Initializer
int main() {
    // string str = BLK << "test";
    cout << GRN << "▉";
    // for (string str : defaultProfile) {
    //     cout << str;
    // }
}