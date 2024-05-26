#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

class StudentSet {
 private:
  string set[MAX_SIZE];
  int size;

 public:
  StudentSet() { size = 0; }

  void add(string name) {
    if (size >= MAX_SIZE) {
      cout << "Error: Set is full." << endl;
      return;
    }

    // Check if the item already exists in the set
    if (contains(name)) return;

    // Add the item to the set
    set[size] = name;
    size++;
  }

  void remove(string name) {
    // Search for the item in the set
    int index = -1;
    for (int i = 0; i < size; i++) {
      if (set[i] == name) {
        index = i;
        break;
      }
    }

    // If the item is found, remove it from the set
    if (index >= 0) {
      for (int i = index; i < size - 1; i++) {
        set[i] = set[i + 1];
      }
      size--;
    }
  }

  bool contains(string name) {
    // Search for the item in the set
    for (int i = 0; i < size; i++)
      if (set[i] == name) return true;
    return false;
  }

  void print() {
    cout << "Set: { ";
    for (int i = 0; i < size; i++) cout << set[i] << " ";
    cout << "}" << endl;
  }
};

int main() {
  StudentSet s;
  string name;
  // Add some students to the set
  s.add("Akira");
  s.add("JL");
  s.add("Gelo");
  s.add("Mikki");
  s.add("Nate");

  // Print the set
  s.print();

  // Check if a student is in the set
  cout << "Who do you want to check? ";
  cin >> name;

  if (s.contains(name)) {
    cout << "Yipee!!! He is in the set." << endl;
  } else {
    cout << "Oops! He is not in the set." << endl;
  }

  // Remove a student from the set
  cout << "Who do you want to remove? ";
  cin >> name;
  s.remove(name);

  // Print the updated set
  s.print();

  // Check if a student is in the set
  if (s.contains(name)) {
    cout << "Yipee! He is in the set." << endl;
  } else {
    cout << "Saddd!!! " << name << " is not anymore in the set." << endl;
  }

  return 0;
}
