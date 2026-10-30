#include "Vector.h"

Vector::Vector() : points(nullptr), countPoint(0) {}

Vector::Vector(int num) : countPoint(num), points(nullptr) {
    if (num > 0) {
        points = new Point[num];
    }
}

Vector::~Vector() {
    if (points != nullptr) {
        delete[] points;
    }
}

Vector::Vector(const Vector& other) {
    countPoint = other.countPoint;
    points = new Point[countPoint];
    for (int i = 0; i < countPoint; i++) {
        points[i] = other.points[i];
    }
}

Vector::Vector(Vector&& other) : points(other.points), countPoint(other.countPoint) {
    other.points = nullptr;
    other.countPoint = 0;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        if (points != nullptr) {
            delete[] points;
        }
        countPoint = other.countPoint;
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; i++) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

void Vector::Add(const Point& point) {
    Point* newPoints = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; i++) {
        newPoints[i] = points[i];
    }
    newPoints[countPoint] = point;
    delete[] points;
    points = newPoints;
    countPoint++;
}

void Vector::Print() const {
    for (int i = 0; i < countPoint; i++) {
        points[i].Print();
    }
}

