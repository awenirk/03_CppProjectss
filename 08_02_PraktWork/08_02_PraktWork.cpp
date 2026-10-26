#include <iostream>
using namespace std;

/*
Завдання 1:
Перетворити раніше створений клас Array на шаблон, який дозволить
зберігати елементи будь-якого типу. Функціональність залишити на
тому ж рівні.
Додати можливість створювати об'єкт та присвоювати йому
значення шляхом спискової ініціалізації: { 1, 2, 3...}

Завдання 2:
Реалізуйте шаблонні функції для пошуку максимуму,
мінімуму, сортування масиву (будь-яким алгоритмом
сортування), двійкового пошуку в масиві, заміни елемента
масиву на передане значення. Ці методи винести за межі класу
*/

template<typename Ar>
class Array
{
    Ar* arr;
    int size;
public:
    #pragma region Constructors
    Array() {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size) {
        this->size = size;
        arr = new Ar[size] {};
    }
    
    ~Array() {
        if (arr != nullptr)
            delete[]arr;
    }
    #pragma endregion
    
    void Fill(initializer_list<Ar> list);

    void Print() {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    #pragma region Task 1
    Array(initializer_list<Ar> list) {
        this->size = list.size();
        arr = new Ar[size];
        int i = 0;
        for (Ar elem : list)
        {
            arr[i] = elem;
            i++;
        }
    }
    #pragma endregion

    #pragma region Task 2
    int BinarySearch(Ar key);
    void max();
    void min();
    void sort();
    void replace(int index, Ar value);
    #pragma endregion
};

template<typename Ar>
void Array<Ar>::Fill(initializer_list<Ar> list)
{
    if (arr != nullptr)
        delete[]arr;
    this->size = list.size();
    arr = new int[size];
    int i = 0;
    for (int elem : list)
    {
        arr[i] = elem;
        i++;
    }

}

#pragma region Task 2
template<typename Ar>
int Array<Ar>::BinarySearch(Ar key) {
    int B = 0, E = size - 1;
    while (true) {
        int p = (B + E) / 2;

        if (key > arr[p])        B = p + 1;
        else if (key < arr[p])   E = p - 1;
        else if (key == arr[p])  return p;
        if (B > E)               return -1;
    }
}

template<typename Ar>
void Array<Ar>::max() {
    Ar max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Max: " << max << endl;
}

template<typename Ar>
void Array<Ar>::min() {
    Ar min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Min: " << min << endl;
}

template<typename Ar>
void Array<Ar>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename Ar>
void Array<Ar>::replace(int index, Ar value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
}
#pragma endregion

int main()
{
    cout << "Hello World!\n";
    Array<int> arr(10);
    arr.Print();
    cout << endl;

    arr.Fill({ 1, 5, 3, 9, 2, 8, 4, 7, 6, 0 });
    arr.Print();
    cout << endl;

    cout << "Binary Search result for 5: " << arr.BinarySearch(5) << endl;
    cout << endl;

    arr.max();
    arr.min();
    cout << endl;

    arr.sort();
    arr.Print();
    cout << endl;

    arr.replace(2, 10);
    arr.Print();

}