#include <iostream>
using namespace std;

/*
1. Для масиву вагонів створити окрему структуру
з наступними полями:
struct Vagon
номер вагону
кількість місць
кількість пасажирів
2.class Train
Створити клас Потяг. У класі оголосити поля(змінні члени класу):
модель
кількість вагонів
для збереження масиву вагонів викорисати List<Vagon> vagons;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Додати методи додавання вагона в початок/кінець та видалення з
початку/кінця.
Реалізувати конструктор копіювання

3. Додати метод DeleteFromHead для класу двозв*язного списку.

Завдання 4:
На 12 балів зробити видалення по позиції та додавання по позиції
*/

template <typename T>
class List {
private:
	struct Node {
		Node* prev;
		int value;
		Node* next;
		Node() : prev(nullptr), value(0), next(nullptr) {}
		Node(Node* p, int v, Node* n) : prev(p), value(v), next(n) {}
	};
	Node* head;
	T value;
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
	void AddToHead(T value) {
		Node* newNode = new Node(nullptr, value, head);
		if (isEmpty()) { head = tail = newNode; }
		else {
			head->prev = newNode;
			head = newNode;
		}

	}
	void AddToTail(T value) {
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

class Train {
private:
	struct Vagon {
		int vagonNum;
		int countSeat;
		int countPasangers;
		Vagon(): vagonNum(0), countSeat(0), countPasangers(0) {}
		Vagon(int vagonNum): vagonNum(vagonNum), countSeat(0), countPasangers(0) {}
	};
	string model;
	int countVagons;
	List<Vagon> vagons;
public:
	Train(): model("No model"), countVagons(0) {}
	Train(string model) : model(model), countVagons(0) {}
	Train(Train v) : model(v.model), countVagons(0) {}

	void show() {}

	void addVagonToHead(Vagon v) { vagons.AddToHead(v); }
	void addVagonToTail(Vagon v) { vagons.AddToTail(v); }
	void deleteVagonFromHead(Vagon v) { vagons.deleteFromHead(); }
	void deleteVagonFromTail(Vagon v) { vagons.deleteFromTail(); }
};


int main()
{
	List<int> l;
	for (int i = 0; i < 10; i++) {
		l.AddToHead(i);
	}
	l.print();

}