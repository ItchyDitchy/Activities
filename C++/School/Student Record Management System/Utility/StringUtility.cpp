#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class StringUtility {
    public:
        static string trim(const std::string& str) {
        std::string trimmed = str;

        // Remove leading spaces
        trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));

        // Remove trailing spaces
        trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), trimmed.end());
            return trimmed;
        }

        static string repeatCharacter(string str, int numTimes) {
            string repeatedString;
            for (int i = 0; i < numTimes; i++) {
                repeatedString += str;
            }
            return repeatedString;
        }

};