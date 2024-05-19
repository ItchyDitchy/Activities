#include <iostream>
using namespace std;

template <typename T>
class Stack {
 private:
  T* a;
  int n;
  int top;

 public:
  Stack(int size) {
    n = size;
    a = new T[n];
    top = -1;
  }
  void push(T element) {
    if (top == n - 1) {
      cout << "Stack is full\n";
    } else {
      ++top;
      a[top] = element;
    }
  }

  T pop() {
    if (top == -1) return T();
    int temp = a[top];
    top--;
    return temp;
  }

  void display() {
    int temp = top;
    while (temp > -1) {
      cout << a[temp] << endl;
      temp--;
    }
  }

  void operations() {
    int ch;
    while (true) {
      cout << "\nStack Operations Menu\n1- Push an element\n2- Pop\n3- Display "
              "the elements\n4- Exit\nSelect an operation: ";
      cin >> ch;
      switch (ch) {
        case 1: {
          T element;
          cout << "Enter the element to push: ";
          cin >> element;
          push(element);
          break;
        }
        case 2: {
          T val = pop();
          if (val != -1) {
            cout << "Popped element: " << val << endl;
          }
          break;
        }
        case 3: {
          display();
          break;
        }
        case 4: {
          exit(0);
        }
        default: {
          cout << "Invalid choice.\n";
        }
      }
    }
  }
};

int main() {
  int size;
  cout << "Enter the size of the stack: ";
  cin >> size;
  Stack<int> s(size);
  s.operations();
  return 0;
}
