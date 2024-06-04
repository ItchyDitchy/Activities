#include <iostream>
#include <string>

using namespace std;

string handleReversal(string& post, string& pre, int cur) {
  cout << "This is a recursive function" << endl;
  if (pre.size() >= cur) {
    cout << "\"" << post << "\" \"" << pre << "\" " << cur << endl;
    post += pre[pre.size() - cur++];
    handleReversal(post, pre, cur);
  }
  return post;
}
int main() {
  string word;
  cout << "Word: ";
  cin >> word;
  string post = "";
  cout << handleReversal(post, word, 0);
}