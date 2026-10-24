#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Завдання 1:
Створіть клас Array – це клас динамічного масиву чисел з певним функціоналом (початковий шаблон завантажено в Slack).
Властивостями класа буде вказівник на сам масив (long* arr) та його теперішній розмір (int size).

Клас повинен дозволяти наступний функціонал:
Заповнити масив значеннями (випадковими, з клавіатури або ж по замовчуванню)
Відображати вміст масиву
Додавати елемент в масив
 Видаляти елемент з масива (по значенню або по індексу)
 Відсортувати масив (по спаданню/зростанню)
Визначати значення (мінімальне, максимальне або середнє арифметичне)

Також передбачити набір конструкторів:
Конструктор за замовчуванням, який встановлювтиме початкові значення
Конструктор, який прийматиме розмір масиву та заповнюватиме нулем всі елементи
Конструктор копіювання, який буде копіювати всі дані об'єкта включаючи масив
Також реалізувати деструктор в класі для уникнення втрати пам’яті.
Врахувати можливі помилки (видалення не існуючого елемента, порожній масив і тд.). Успіхів!
*/

/*
Завдання 2:
До раніше створеного класу Array додайте перевантаження оператора [], ()

[] – повертає елемент за вказаним індексом (по посиланню)
() – збільшує всі елементи масиву на зазначену величину
*/


class Array {
    int size = 0;
    long* arr = nullptr;

public:
    #pragma region Constructors, and destructor
    Array() {
        size = 0;
        arr = nullptr;
    }
    Array(int size) {
        if (size > 0) {
            this->size = size;
            arr = new long[size] {};

        }
        else {
            this->size = 0;
            arr = nullptr;
        }
    }
    Array(const Array& other) {
        size = other.size;

        if (size > 0) {
            arr = new long[size];

            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        else arr = nullptr;
    }
    ~Array() {
        delete[] arr;
    }
    #pragma endregion

    #pragma region Functions
    void FillArray() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }

        // double num = arr[0];
        int choice = 0;

        cout << "1. Fill random" << endl;
        cout << "2. Enter from keyboard" << endl;
        cout << "3. Set default" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < size; i++)
                arr[i] = rand() % 100 + 1;
            break;
        case 2:
            for (int i = 0; i < size; i++) {
                cout << "Enter " << i + 1 << " number: ";
                cin >> arr[i];
            }
            break;
        case 3:
            for (int i = 0; i < size; i++)
                arr[i] = 0;
            break;
        default:
            cout << "Error" << endl;
            break;
        }
    }
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void addElementToArray(long value) {
        long* temp = new long[size + 1];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        temp[size] = value;
        delete[] arr;
        arr = temp;
        size++;
    }
    void deleteElement() {
        if (size == 0)
            cout << "Array is empty!" << endl;
        else {
            int choice = 0;

            cout << "1. Delete last element" << endl;
            cout << "2. Delete by index" << endl;
            cout << "Enter your choice: "; cin >> choice;

            switch (choice) {
            case 1: {
                long* temp = new long[size - 1];
                for (int i = 0; i < size - 1; i++)
                    temp[i] = arr[i];
                delete[] arr;
                arr = temp;
                size--;
                break;
            }
            case 2: {
                int index;
                cout << "Enter index: "; cin >> index;
                if (index < 0 || index >= size) {
                    cout << "Incorrect index!" << endl;
                    return;
                }
                long* temp = new long[size - 1];
                for (int i = 0; i < index; i++)
                    temp[i] = arr[i];
                for (int i = index; i < size - 1; i++)
                    temp[i] = arr[i + 1];
                delete[] arr;
                arr = temp;
                size--;
                break;
            }
            default:
                cout << "Error" << endl;
                break;
            }
        }
    }
    void SortArray() {
        if (size == 0) cout << "Array is empty!" << endl;
        else {
            int choice = 0;
            long temp;

            cout << "1. Normal sort" << endl;
            cout << "2. Reverse sort" << endl;
            cout << "Enter your choice: "; cin >> choice;

            switch (choice) {
            case 1:
                for (int i = 0; i < size; i++) {
                    for (int j = size - 1; j > i; j--)
                    {
                        if (arr[j - 1] > arr[j]) {
                            temp = arr[j - 1];
                            arr[j - 1] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    for (int j = size - 1; j > i; j--)
                    {
                        if (arr[j - 1] < arr[j]) {
                            temp = arr[j - 1];
                            arr[j - 1] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                break;
            default:
                cout << "Error" << endl;
                break;
            }


        }
    }
    double minMaxAref() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return 0;
        }

        double num = arr[0];
        int choice = 0;

        cout << "1. Max num" << endl;
        cout << "2. Min num" << endl;
        cout << "3. Arithmetic mean" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 1; i < size; i++)
                if (arr[i] > num) num = arr[i];
            return num;
        case 2:
            for (int i = 1; i < size; i++)
                if (arr[i] < num) num = arr[i];
            return num;
        case 3:
            for (int i = 1; i < size; i++)
                num += arr[i];
            num /= size;
            return num;

        default:
            cout << "Error!" << endl;
            return 0;
        }
    }
    #pragma endregion

    #pragma region Task 2
    void operator()(long value) {
        for (int i = 0; i < size; i++)
            arr[i] += value;
    }
    void operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Incorrect index!" << endl;
            return;
        }
        cout << arr[index] << endl;
    }
    #pragma endregion

};

int main()
{
    srand(time(0));

    Array arr(4);

    cout << "New array: ";
    arr.Print();

    arr.FillArray();
    cout << "Filled array: ";
    arr.Print();



    arr(5);
    cout << "Array + 5: ";
    arr.Print();
    
    cout << "3 item in array: ";
    arr[2];


    /*
    long value;
    cout << "\nEnter value to add: ";
    cin >> value;

    arr.addElementToArray(value);
    cout << "After adding: ";
    arr.Print();

    arr.deleteElement();
    cout << "After deleting: ";
    arr.Print();

    arr.SortArray();
    cout << "After sorting: ";
    arr.Print();

    cout << "Result: " << arr.minMaxAref() << endl;

    Array copy(arr);
    cout << "\nCopy of array: ";
    copy.Print();

    arr.addElementToArray(999);
    cout << "Original after adding 999: ";
    arr.Print();

    cout << "Copy stayed unchanged: ";
    copy.Print();
    */
}