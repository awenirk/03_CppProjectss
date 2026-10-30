#include <iostream>
using namespace std;

/*
class Stack {
    enum {EMPTY = -1, FULL = 9};
    int arr[FULL + 1];
    int topIndex;
public:
    Stack() {
        topIndex = EMPTY;
    }
    Stack(const Stack& other) = delete;
    ~Stack() {}

    bool isFull() {
        return topIndex == FULL;
    }
    bool isEmpty() {
        return topIndex == EMPTY;
    }
    bool Push(int elem) {
        if (!isFull) {
            topIndex++;
            arr[topIndex] = elem;
            return true;
        }
        return false;
    }
    int pop() {
        if (!isEmpty) { return arr[topIndex--]; }
    }
    int getCount() {
        return topIndex + 1;
    }
    void clear() {
        topIndex = EMPTY;
    }
    int Peek() {
        if (!isEmpty) { return arr[topIndex]; }
    }
    void Print() {
        for (int i = 0; i < topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
*/

class Stack {
private:
    enum {EMPTY = -1};
    int* arr;
    int size;
    int topIndex;

public:
    Stack() = default;
    Stack(int size):size(size) {
        arr = new int[size];
        topIndex = EMPTY;
    }
    ~Stack() {
        if (arr != nullptr) delete[] arr;
    }
    bool isFull() {
        return topIndex == size-1;
    }
    bool Push(int elem) {
        if (!isFull) {
            topIndex++;
            arr[topIndex] = elem;
            return true;
        }
        return false;
    }
    bool isEmpty() {
        return topIndex == EMPTY;
    }
    int pop() {
        if (!isEmpty) { return arr[topIndex--]; }
    }

    int getCount() {
        return topIndex + 1;
    }
    void clear() {
        topIndex = EMPTY;
    }
    int Peek() {
        if (!isEmpty) { return arr[topIndex]; }
    }
    void Print() {
        for (int i = 0; i < topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    Stack st(15);
    cout << "Size = " << st.getCount() << endl;
    for (int i = 0; i < 7; i++) {
        st.Push(rand % 50);
    }

    cout << "Size = " << st.getCount() << endl;
    st.Print();
    while (!st.isEmpty()) {
        cout << "Delete element: " << st.pop() << endl;
        st.Print();
    }
    cout << "Size: "




}

