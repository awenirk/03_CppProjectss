#include <iostream>
using namespace std;
/*
Завдання 2:
Реалізувати клас Vector, який містить колекцію точок на площині.
Точки зберігаються у вигляді списка (змінна типу List).
Для класу потрібно реалізувати необхідний набір конструкторів,
методи для видалення, додавання нової точки на початок та в кінець
та метод Print() для виводу точок на екран.
*/

template <typename T>
class List {

};

class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void print() { cout << '(' << x << ', ' << y << ')' << endl; }
};

class Vector
{
    List<Point> points;
    int size;
};



int main()
{
    
}
