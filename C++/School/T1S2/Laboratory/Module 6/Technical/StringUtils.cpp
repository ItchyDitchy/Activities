#include <string>

using namespace std;

string strip(string txt) {
    string tmp = "";
    for (char c : txt)
        if (isalnum(c))
            tmp += c;
    return tmp;
}

string toLower(string txt) {
    for (char &c : txt)
        c = tolower(c);
    return txt;
}

string toUpper(string txt) {
    for (char &c : txt)
        c = toupper(c);
    return txt;
}

string titleCase(string txt) {
    for (int i = 0; i < txt.size(); i++)
        txt[i] = isspace(txt[i-1]) ? toupper(txt[i]) : tolower(txt[i]);
    return txt;
}