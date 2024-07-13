#include <iostream>
#include <stack>

using namespace std;

void towerOfHanoi(int num, char a = 'A', char b = 'B', char c = 'C') {
  if (num == 1) {
    cout << "Disk " << num << " moved from " << a << " to " << c << endl;
    return;
  }
  towerOfHanoi(num - 1, a, c, b);
  cout << "Disk " << num << " moved from " << a << " to " << c << endl;
  towerOfHanoi(num - 1, b, a, c);
}

int main() {
  int diskNum = -1;
  while (2 > diskNum || diskNum > 3) {
    cout << "Input: ";
    cin >> diskNum;
  }
  towerOfHanoi(diskNum);
  return 0;
}