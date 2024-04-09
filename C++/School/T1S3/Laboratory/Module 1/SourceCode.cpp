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
            for (int i = pos; i < size; i++)
                array[i + 1] = array[i];
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
                cout << "Cannot add item due to max capacity!";
                return;
            }
            array[size++] = val;
        }

        void displayElements() {
            cout << "\nArray: [" << array[0];
            for (int i = 1; i < size; i++)
                cout << ", " << array[i];
            cout << "]";
        }
};

int main() {
    return 0;
}