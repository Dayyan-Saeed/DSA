#include <iostream>

using namespace std;

class StackSorter {
public:
    virtual void sort(int* arr, int size) = 0;
};

class QuickSort : public StackSorter {
public:
    void sort(int* arr, int size) {
        if (size <= 1) {
            return;
        }

        int pivot = arr[size - 1];
        int i = -1;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[size - 1]);

        sort(arr, i + 1);
        sort(arr + i + 2, size - i - 2);
    }
};

class Stack {
private:
    int* arr;
    int top_index;
    int capacity;
    StackSorter* sorter;

public:
    Stack(int capacity, StackSorter* sorter) {
        this->arr = new int[capacity];
        this->top_index = -1;
        this->capacity = capacity;
        this->sorter = sorter;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top_index < capacity - 1) {
            top_index++;
            arr[top_index] = value;
        }
        else {
            cout << "Stack is full!" << endl;
        }
    }

    int pop() {
        if (top_index >= 0) {
            int value = arr[top_index];
            top_index--;
            return value;
        }
        else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool empty() {
        return top_index == -1;
    }

    void sort() {
        sorter->sort(arr, top_index + 1);
    }

    void print() {
        cout << "Stack: ";
        for (int i = top_index; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) {
                cout << ",";
            }
        }
        cout << endl;
    }
};

int main() {
    StackSorter* sorter = new QuickSort();
    Stack stack(5, sorter);
    stack.push(3);
    stack.push(8);
    stack.push(4);
    stack.push(9);
    stack.push(1);

    stack.print();
    stack.sort();
    stack.print();

    delete sorter;
    return 0;
}