#include <iostream>
#include <conio.h>
using namespace std;

class Queue {
    // FIFO
    int* arr;
    int maxSize;
    int topIndex;
public:
    Queue() = default;
    Queue(int max_size) {
        this->maxSize = max_size;
        arr = new int[maxSize];
        topIndex = 0;
    }
    ~Queue() { if (arr != nullptr) delete[] arr; }

    bool isFull()const { return maxSize == topIndex; }
    bool isEmpty()const { return topIndex == 0; }
    void EnQueue(int elem) { if (!isFull()) { arr[topIndex++] = elem; } }
    /* int Dequeue() {
        if (!isEmpty()) {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++) {
                arr[i] = arr[i + 1];
            }
            topIndex--;
            return first;
        }
    } */
    //Queue cycle
    int Dequeue() { 
        if (!isEmpty()) {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++) {
                arr[i] = arr[i + 1];
            }
            arr[topIndex-1] = first;
            return first;
        }
    }
    int GetCount()const { return topIndex; }
    int Clear() { topIndex = 0; }
    void Show()const {
        for (int i = 0; i < topIndex; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

};

int main()
{
    srand(time(0));
    Queue q(16);
    for (int i = 0; i < 10; i++) {
        q.EnQueue(rand() % 50);
        // q.EnQueue(rand() % 50);
    }
    q.Show();
    cout << "Size: " << q.GetCount() << endl;

    _getch();
    system("cls");
    while (!q.isEmpty()) {
        cout << "Delete element: " << q.Dequeue() << endl;
        cout << "Size: " << q.GetCount() << endl;
        q.Show();
        cout << endl;
        _getch();
        system("cls");
    }











}