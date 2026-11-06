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
        T value;
		Node* next;
        Node() : prev(nullptr), value(), next(nullptr) {}
        Node(Node* p, const T& v, Node* n) : prev(p), value(v), next(n) {}
	};
	Node* head;
	Node* tail;

public:
#pragma region constructors
	List() {
		head = tail = nullptr;
	}
    List(const List& other) : head(nullptr), tail(nullptr) {
        for (Node* current = other.head; current != nullptr; current = current->next) {
            AddToTail(current->value);
        }
    }
    List& operator=(const List& other) {
        if (this == &other) return *this;
        while (!isEmpty()) deleteFromHead();
        for (Node* current = other.head; current != nullptr; current = current->next) {
            AddToTail(current->value);
        }
        return *this;
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
    template <typename Func>
    void forEach(Func func) const {
        for (Node* i = head; i != nullptr; i = i->next) {
            func(i->value);
        }
    }
    void deleteByPos(int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < pos; i++) {
            if (current == nullptr) {
                cout << "Position out of range!" << endl;
                return;
            }
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current;
        }
        else {
            cout << "Position out of range!" << endl;
        }
    }
    void addByPos(int pos, T value) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            AddToHead(value);
            return;
        }
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of range!" << endl;
                return;
            }
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(current, value, current->next);
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            else {
                tail = newNode;
            }
            current->next = newNode;
        }
        else {
            cout << "Position out of range!" << endl;
        }
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
        Node* oldHead = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        else head->prev = nullptr;
        delete oldHead;
	}
	void deleteFromTail() {
		if (isEmpty()) return;
        Node* oldTail = tail;
        tail = tail->prev;
        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        delete oldTail;
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
#pragma region constructors
	Train(): model("No model"), countVagons(0) {}
	Train(string model) : model(model), countVagons(0) {}
    Train(const Train& t) : model(t.model), countVagons(t.countVagons), vagons(t.vagons) {}
#pragma endregion

#pragma region add_del
    void addVagonToHead(Vagon v) {
        vagons.AddToHead(v);
        countVagons++;
    }
    void addVagonToTail(Vagon v) {
        vagons.AddToTail(v);
        countVagons++;
    }
    void deleteVagonFromHead() {
        if (!vagons.isEmpty()) {
            vagons.deleteFromHead();
            countVagons--;
        }
    }
    void deleteVagonFromTail() {
        if (!vagons.isEmpty()) {
            vagons.deleteFromTail();
            countVagons--;
        }
    }
#pragma endregion

#pragma region functions
	void show() {
        cout << "Train model:" << model << endl;
        cout << "Count vagons: " << countVagons << endl;
        vagons.forEach([](const Vagon& vagon) {
            cout << "Vagon " << vagon.vagonNum
                << ", seats: " << vagon.countSeat
                << ", passengers: " << vagon.countPasangers << endl;
        });
    }
    void deleteByPosition(int position) {
        if (position < 0 || position >= countVagons) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 0) {
            deleteVagonFromHead();
        }
        else if (position == countVagons - 1) {
            deleteVagonFromTail();
        }
        else {
            vagons.deleteByPos(position);
            countVagons--;
        }
    }
#pragma endregion

};


int main()
{
    Train t("Express");
    // t.show();

}