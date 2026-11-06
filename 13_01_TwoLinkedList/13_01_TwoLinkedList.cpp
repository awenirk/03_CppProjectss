#include <iostream>
using namespace std;

class List {
private:
	struct Node {
		Node* prev;
		int value;
		Node* next;
		Node(): prev(nullptr), value(0), next(nullptr) {}
		Node(Node* p, int v, Node* n): prev(p), value(v), next(n) {}
	};
	Node* head;
	Node* tail;

public:
#pragma region constructors
	List() {
		head = tail = nullptr;
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
#pragma region functions
	bool isEmpty()const {
		return head == nullptr;
	}
	void print() {
		/*
		Node* current = head;
		while (current != nullptr) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
		*/
		for (Node* i = head; i != nullptr; i = i->next) {
			cout << i->value << ' ';
		}
		cout << endl;
	}
#pragma endregion
#pragma region add_del
	void AddToHead(int value) {
		Node* newNode = new Node(nullptr, value, head);
		if (isEmpty()) { head = tail = newNode; }
		else {
			head->prev = newNode;
			head = newNode;
		}
		
	}
	void AddToTail(int value) {
		Node* newNode = new Node(tail, value, nullptr);
		if (isEmpty()) { head = tail = newNode; }
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	void deleteFromHead() {
		if (isEmpty()) return;
		if (head->next == nullptr) {
			delete head;
			head = tail = nullptr;
		}
		else {
			head = head->next;
			delete head;
			head->prev = nullptr;
		}
	}
	void deleteFromTail() {
		if (isEmpty()) return;
		if (tail->prev == nullptr) {
			delete tail;
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
#pragma endregion
};




int main()
{
	List l;
	for (int i = 0; i < 10; i++) {
		l.AddToHead(i);
	}
	l.print();

}