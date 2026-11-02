#include <iostream>
#include <conio.h>
using namespace std;

struct Element {
    char letter;
    int priority;
    void print() {
        cout << letter << ' ' << priority << " | ";
    }
};



class Queue {
    Element* elements;
    int count;
public:
    Queue(): elements(nullptr), count(0) {}
    ~Queue() { if (elements != nullptr) delete[] elements; }

    bool isEmpty()const { return count == 0; }
    void Enqueue(Element el) {
        int index = 0;
        while (index < count && elements[index].priority < el.priority)index++;
        Element* temp = new Element[count + 1];
        for (int i = 0; i < index; i++) {
            temp[i] = elements[i];
        }
        temp[index] = el;
        for (int i = index; i < count; i++) {
            temp[i + 1] = elements[i];
        }
        if (elements != nullptr) delete[] elements;
        elements = temp;
        count++;
    }
    Element Dequeue() {
        if (!isEmpty()) {
            Element first = elements[0];
            for (int i = 0; i < count; i++) {
                elements[i] = elements[i + 1];
            }
            elements--;
            return first;
        }
    }

    void Print() {
        cout << "-=-=-=-=-=- Queue -=-=-=-=-=-" << endl;
        for (int i = 0; i < count; i++) {
            elements[i].print();
        }
        cout << endl;
    }


};

int main()
{
    srand(time(0));
    Queue q;
    Element el{ 'A', 1 };
    q.Enqueue(el);
    q.Enqueue(Element{'B', 2});
    q.Enqueue(Element{'C', 3});
    q.Enqueue(Element{'G', 4});
    q.Enqueue(Element{'K', 7});
    q.Print();
    q.Enqueue(Element{'D', 5});
    q.Print();
    q.Enqueue(Element{'Q', 3});
    q.Print();

    while (!q.isEmpty()) {
        cout << "Delete emenent: ";
        q.Dequeue().print();
        cout << endl;
    }


}