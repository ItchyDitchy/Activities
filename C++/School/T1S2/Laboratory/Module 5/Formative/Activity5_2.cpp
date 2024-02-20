#include <iostream>
#include <cstring>

using namespace std;

char* stringRev(char *s);

int main() {
    char str[] = "Happy Day";
    cout << stringRev(str);
    system("pause > 0");
    return 0;
}

char* stringRev(char *s) {
    char* tmp;
    tmp = new char;
    int i, cnt(0);
    for (i = 0; i < strlen(s); i++) {
        cout << s[i] << endl;
        cnt++;
    }
    for (i = 0; i < cnt; i++)
        tmp[i] = s[cnt-1-i];
    tmp[i] = '\0';
    return tmp;
}