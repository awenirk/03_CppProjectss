#include "PointClass.h"
#pragma once

inline void SetPos(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Для класу потрібно реалізувати весь необхідний набір конструкторів
// (копіювання та переміщення обов'язково),
// оператор =, деструткор,
// метод Add() для додавання нової точки
// та Print() для виводу інформації на екран.

// * Реалізувати вивів точок у відповідних координатах на консолі. Для цього можна використати функцію gotoxy
// !Результат завантажити у вигляді.cpp файла.
// * – додаткове завдання


class Vector {
    Point* points;
    int countPoint;
public:
    Vector();
    Vector(int num);
    ~Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);

    Vector& operator=(const Vector& other);
    void Add(const Point& point);
    void Print() const;
    void PrintAtPosition(int x, int y) const {
        for (int i = 0; i < countPoint; i++) {
            SetPos(x, y + i);
            points[i].Print();
        }
    }
};
