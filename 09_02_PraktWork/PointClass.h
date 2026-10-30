#include <iostream>
#include <Windows.h>
using namespace std;
#pragma once


class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);

    void Print();

    void operator++() { x++; y++; }
    void operator--() { x--; y--; }
    void operator!() { x = -x; y = -y; }

    void operator>(const Point& other) {
        if (x > other.x && y > other.y) {
            cout << "Point is further from origin than the other point." << endl;
        }
        else {
            cout << "Point is not further from origin than the other point." << endl;
        }
    }
    void operator<(const Point& other) {
        if (x < other.x && y < other.y) {
            cout << "Point is closer to origin than the other point." << endl;
        }
        else {
            cout << "Point is not closer to origin than the other point." << endl;
        }
    }
};
