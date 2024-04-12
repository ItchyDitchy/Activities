#include <iostream>

using namespace std;

class Array1D {
    private:
        int capacity;
        int size = 0;
        int *array;
    public:
        Array1D(int arrayCap = 10) {
            this->array = new int[capacity];
            this->capacity = arrayCap;
        }

        ~Array1D() {
            delete [] array;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() const {
            return size == 0;
        };

        bool isFull() const {
            return size == capacity;
        }

        void insertItem(int pos, int val) {
            if (isFull()) {
                cout << "Unable to insert element due to max capacity!";
                return;
            }
            for (int i = size; i > pos; i--)
                array[i] = array[i - 1];
            array[pos] = val;
            size++;
        }

        void removeItem(int pos) {
            for (int i = pos; i < size; i++)
                array[i] = array[i+1];
            size--;
        }

        void addItem(int val) {
            if (isFull()) {
                cout << "Cannot add item due to max capacity!" << endl;
                return;
            }
            array[size++] = val;
        }

        void displayElements() {
            cout << "Array: [" << array[0];
            for (int i = 1; i < size; i++)
                cout << ", " << array[i];
            cout << "]\n";
        }
};

int main() {
    Array1D arr(5);
    arr.addItem(10);
    arr.addItem(20);
    arr.addItem(30);
    arr.displayElements();
    arr.insertItem(1, 15);
    arr.displayElements();
    arr.addItem(40);
    arr.displayElements();
    arr.addItem(50);
    arr.removeItem(0);
    arr.displayElements();
    cout << "Array Size: " << arr.getSize() << endl;
    if (arr.isEmpty())
        cout << "Array is empty!" << endl;
    else
        cout << "Array is not empty!" << endl;
    return 0;
}