#include <iostream>
using namespace std;
/*
Завдання 1:
Створити клас Airplane (літак), який буде мати наступні характеристики:
• Модель
• Тип
• Кількість пасажирів
• Максимальна кількість пасажирів

За допомогою перевантаження операторів реалізувати:
1. Перевірку на рівність типів літаків (операція ==) friend
2. Збільшення і зменшення пасажирів в салоні літака (операції ++ та --
в префіксній формі)
3. Порівняння двох літаків по максимально можливій кількості пасажирів
на борту (операція >) friend
4. Збільшити кількість пасажирів на певне значення (оператор (15))
Перевантаження логічних операцій виконати за допомогою дружніх функцій.
При виконанні операцій, потрібно перевіряти чи не перебільшено максимальну
кількість пасажирів.
! Результат завантажити у вигляді .cpp файла.
*/
class Airplane {
    string model;
    string type;
    int passengers;
    int maxPassengers;
public:
    Airplane(string model, string type, int passengers, int maxPassengers)
        : model(model), type(type), passengers(passengers), maxPassengers(maxPassengers) {
    }

    #pragma region Task 1
    friend bool operator==(const Airplane& a1, const Airplane& a2) {
        return a1.type == a2.type;
    }
    #pragma endregion
    
    #pragma region Task 2
    void operator++() {
        if (passengers < maxPassengers) {
            passengers++;
        }
    }
    void operator--() {
        if (passengers > 0) {
            passengers--;
        }
    }
    #pragma endregion
    
    #pragma region Task 3
    friend bool operator>(const Airplane& a1, const Airplane& a2) {
        return a1.maxPassengers > a2.maxPassengers;
    }
    #pragma endregion
    
    #pragma region Task 4
    void operator()(int value) {
        if (passengers + value <= maxPassengers) {
            passengers += value;
        }
    }
    #pragma endregion

    #pragma region MyFunctions
    void PrintInfo() {
        cout << "Model: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Passengers: " << passengers << endl;
        cout << "Max Passengers: " << maxPassengers << endl << endl;
    }
    #pragma endregion

};


int main()
{
    Airplane plane1("Plae", "Passenger", 100, 150);
    Airplane plane2("Plane1", "Passenger", 120, 180);
    plane1.PrintInfo();
    plane2.PrintInfo();
    if (plane1 == plane2) {
        cout << "Planes are of the same type" << endl << endl;
    }

    ++plane1;
    plane1.PrintInfo();
    --plane2;
    plane2.PrintInfo();

    if (plane1 > plane2) {
        cout << "Plane 1 has a higher maximum passenger capacity" << endl << endl;
    }
    else cout << "Plane 2 has a higher maximum passenger capacity" << endl << endl;

    cout << "Increasing passengers in plane 1 by 20" << endl;
    plane1(20);
    plane1.PrintInfo();

}