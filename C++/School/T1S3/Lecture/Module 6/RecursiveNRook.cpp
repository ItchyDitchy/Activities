#include <iostream>

using namespace std;

void calcRooks(int size);
bool rooks(int board[], int current, int size);
bool noConflicts(int board[], int current, int size);

int main() {
  int size;
  cout << "Size: ";
  cin >> size;
  calcRooks(size);
  return 0;
}

void calcRooks(int size) {
  int board[size];
  for (int& i : board) i = -1;
  rooks(board, 0, size);
}

bool rooks(int board[], int current, int size) {
  cout << endl << "rooks called with " << current << " in Times." << endl;
  cout << "This is a recursive function." << endl;
  cout << endl << "Rook Map: ";
  for (int i = 0; i < size; i++) cout << board[i] << " ";
  if (current != size) {
    for (int i = 0; i < size; i++) {
      board[current] = i;
      if (noConflicts(board, current, size) && rooks(board, current + 1, size))
        return true;
    }
    cout << "rooks return with " << current << "in Times." << endl;
    return false;
  }
  return true;
}

bool noConflicts(int board[], int current, int size) {
  for (int i = 0; i < current; i++)
    if (board[i] == board[current]) return false;
  return true;
}
