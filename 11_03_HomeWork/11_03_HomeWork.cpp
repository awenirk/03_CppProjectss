#include <iostream>
#include <conio.h>
using namespace std;

/* Завдання 1:
Розробити додаток, що імітує чергу друку принтера.
Програма надає меню з наступними можливостями:

•Додати документ в чергу.
Користувач повинен ввести ім’я файлу та
вибрати свою посаду. В залежності від посади,
документу надається певний пріорітет
(до прикладу: гість – 1, адміністратор – 2, менеджер – 3,
 директор – 4 і тд.)

•Виконати друк. Відображається на екран документ,
який наразі друкується (з максимальним пріорітетом).

Для збереження колекції документів використати динамічну
структуру даних – Queue (черга з пріорітетним включенням).
Клас черга має бути шаблонним.
*/

void clear() { system("cls"); }

template <typename T>
class Queue {
    struct Paper {
        string fileName;
        int priority;

        void print() {
            cout << priority << ' ' << fileName << " | ";
        }
    };
    Paper* papers;
    int size;
public:
    Queue() = default;
    Queue(Paper item) {
		Paper* papers = new Paper[1];
		papers[0].fileName = item.fileName;
		papers[0].priority = item.priority;
        size = 1;
    }
    ~Queue() { if (papers != nullptr) { delete[] papers; } }
    void printAll() {
        if (papers != nullptr) {
            for (int i = 0; i < size; i++) {
                papers[i].print();
            }
            cout << endl;
        }
        else cout << "Queue is empty." << endl;
	}
    bool PrintPaper() {
        if (papers != nullptr) {
            cout << "Paper " << papers[0].fileName << " was printed." << endl;
            if (size > 1) {
                for (int i = 0; i < size - 1; i++) {
                    papers[i] = papers[i + 1];
                }
                size--;
			}
            else if (size == 1) {
                delete[] papers;
                papers = nullptr;
                size = 0;
			}
			return true;
        }
        else {
            cout << "Queue is empty." << endl;
			return false;
        }
    }
    void AddPaper(Paper item) {
        int index = 0;
        while (index < size && papers[index].priority > item.priority)index++;
        Paper* temp = new Paper[size + 1];
        for (int i = 0; i < index; i++) {
            temp[i] = papers[i];
        }
        temp[index] = item;
        for (int i = index; i < size; i++) {
            temp[i + 1] = papers[i];
        }
        if (papers != nullptr) delete[] papers;
        papers = temp;
        size++;
	}
    void EnterPaper() {
        Paper item;
        cout << "Enter file name: ";
        cin >> item.fileName;
        cout << "Enter priority: ";
        cin >> item.priority;
        AddPaper(item);
		cout << "Paper " << item.fileName << " was added to the queue." << endl << endl;
	}
};


int main()
{
	Queue<int> q;
    int choice = 1;

    while (choice != 0) {
		cout << "Menu:" << endl;
		cout << "1. Show all papers " << endl;
		cout << "2. Add paper to queue " << endl;
		cout << "3. Print paper " << endl;
		cout << "4. Print all paper " << endl;
		cout << "0. Exit " << endl;
		cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
        case 1:
            q.printAll();
            cout << "\nPress any key to continue...";
            _getch();
            clear();
            break;
        case 2:
            q.EnterPaper();
            cout << "\nPress any key to continue...";
            _getch();
            clear();
            break;
        case 3:
            q.PrintPaper();
            cout << "\nPress any key to continue...";
            _getch();
            clear();
            break;
        case 4:
            while (q.PrintPaper()) { q.PrintPaper(); }
            cout << "\nPress any key to continue...";
            _getch();
            clear();
            break;
        default:
            break;
        }
        
    }
	cout << "Goodbye!" << endl;
}