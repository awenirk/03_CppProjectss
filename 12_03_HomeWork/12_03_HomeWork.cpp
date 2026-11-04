#include <iostream>
using namespace std;

/* Завдання 2:
Реалізувати клас Vector, який містить колекцію точок на площині.
Точки зберігаються у вигляді списка (змінна типу List).
Для класу потрібно реалізувати необхідний набір конструкторів,
методи для видалення, додавання нової точки на початок та в кінець
та метод Print() для виводу точок на екран.
*/

class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void print() { cout << '(' << x << ', ' << y << ')'; }
};

template <typename T>
class List {
    struct Node {
        T value;
        Node* next;

        Node() : value(T()), next(nullptr) {}
        Node(T value, Node* next) : value(value), next(next) {}
    };
    Node* head;
public:

#pragma region Constructors
    List() {
        head = nullptr;
    }
    ~List() {
        Node* current = nullptr;
        while (head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }
    }
#pragma endregion

#pragma region Add _del
    void AddToHead(T value) {
        Node* newNode = new Node(value, head);
        head = newNode;
    }

    void AddToTail(T value) {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr) { head = newNode; }
        else {
            Node* current = head;
            while (current->next != nullptr) { current = current->next; }
            current->next = newNode;
        }
    }
    void deleteFromTail() {
        if (head != nullptr) {
            if (head == nullptr) return;
            if (head->next == nullptr) {
                delete head;
                head == nullptr;
            }
            else {
                Node* current = head;
                while (current->next->next != nullptr) { current = current->next->next; }
                delete current->next;
                current->next = nullptr;
            }
        }
    }
    void deleteFromHead() {
        if (head != nullptr) {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }
#pragma endregion

#pragma region other_functions
    void print() {
        Node* current = head;
        while (current != nullptr) {
            current->value.print();
            current = current->next;
        }
        cout << endl;
    }
    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    T getIndex(int index) {
        if (index < 0 || index >= size()) {
            cout << "Index out of bounds" << endl;
            return T();
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
#pragma endregion

};

class Vector {
    List<Point> points;
    int size;
public:
    Vector(): points(), size(0) {}
    void print() { points.print(); }
    void AddPointToHead(Point point) { points.AddToHead(point); }
    void AddPointToTail(Point point) { points.AddToTail(point); }
    void deletePointFromHead() { points.deleteFromHead(); }
    void deletePointFromTail() { points.deleteFromTail(); }
};


int main()
{
    Vector v;
    v.AddPointToHead(Point(1, 2));
    v.AddPointToHead(Point(5, 6));
    v.AddPointToHead(Point(7, 8));
    v.print();

    v.AddPointToTail(Point(3, 4));
    v.print();

    v.deletePointFromHead();
    v.print();


    
}
