#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  stack<char> charStack;
  string text;
  cout << "Enter a string of braces: ";
  cin >> text;
  for (char c : text)
    if (c == '{')
      charStack.push(c);
    else
      charStack.pop();
  cout << "Minimum number of replacements required: " << charStack.size();
}