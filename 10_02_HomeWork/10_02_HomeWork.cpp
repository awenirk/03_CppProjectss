#include <iostream>
using namespace std;

/* Завдання 1:
Реалізуйте клас стек для роботи з символами (символь-
ний стек). Стек повинен мати фіксований розмір. Також
реалізуйте набір операцій для роботи зі стеком: внесення
символу в стек, видалення символу зі стеку, підрахунок
кількості символів в стеці, перевірку, чи стек порожній,
перевірку, чи стек повний, очищення стеку, отримання
без видалення верхнього символу в стеці. */

/* Завдання 2:
Змініть стек з першого завдання зі статичного типу на
динамічний (за нестачі вільного місця потрібно змінити
розмір внутрішнього масиву без втрати даних). */

/* Завдання 3:
До створеного класа Stack додати шаблонний тип для елементів масива.
Додати можливість в параметризований конструткор крім місткості передавати
набір значень стека, застосувати initializer_list. */

template <typename T>
class Stack {
private:
    enum { EMPTY = -1 };
    T* arr;
    int size;
    int topIndex;

public:
    #pragma region Constructors
    Stack() = default;
    Stack(int size) :size(size) {
        arr = new T[size];
        topIndex = EMPTY;
    }
    Stack(initializer_list<T> List) : size(List.size()), topIndex(EMPTY) {
        arr = new T[size];
        for (const auto& elem : List) {
            Push(elem);
        }
    }
    ~Stack() {
        if (arr != nullptr) delete[] arr;
    }
    #pragma endregion

    #pragma region functions 1
    bool isFull() {
        return topIndex == size - 1;
    }
    bool isEmpty() {
        return topIndex == EMPTY;
    }
    int getCount() {
        return topIndex + 1;
    }
    #pragma endregion

    #pragma region functions 2
    bool Push(T elem) {
        if (!isFull()) {
            topIndex++;
            arr[topIndex] = elem;
            return true;
        }
        else {
            T temp = new T[size + 10];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size += 10;
            return false;
        }
    }
    void clear() {
        topIndex = EMPTY;
    }
    T pop() {
        if (!isEmpty()) { return arr[topIndex--]; }
    }
    T Peek() {
        if (!isEmpty()) { return arr[topIndex]; }
    }
    #pragma endregion

    void Print() {
        for (int i = 0; i < topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    srand(time(0));
    Stack<int> st(15);

    for (int i = 0; i < 10; i++) {
        st.Push(rand() % 50);
    }
    st.Print();

    
}