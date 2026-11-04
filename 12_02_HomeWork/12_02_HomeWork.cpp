#include <iostream>
using namespace std;

/*
Завдання 1:
-Написати метод видалення з голови.
-зробити ліст шаблонним
*/

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

#pragma region AddDel
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

#pragma region Print
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << ' ';
            current = current->next;
        }
        cout << endl;
    }
#pragma endregion

};


int main()
{
    List<int> l;
    l.AddToTail(911);
    for (int i = 0; i <= 10; i++) {
        l.AddToHead(i);
    }
    l.print();
    for (int i = 0; i <= 10; i++) {
        l.AddToTail(i);
    }
    l.AddToTail(11);
    l.AddToTail(12);
    l.print();
}
