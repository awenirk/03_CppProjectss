#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;

	Node(): value(0), next(nullptr){}
	Node(int value, Node* next): value(value), next(next) {}
};

class List {
	Node* head;
public:
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
	void AddToHead(int value) {
		Node* newNode = new Node(value, head);
		head = newNode;
	}
	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
	void AddToTail(int value) {
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



};




int main()
{
	List l;
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