#include <iostream>
using namespace std;


class Point {
    int x;
    int y;

public:
    Point() {
        x = y = 0;
    }
    Point(int value)
    {
        this->x = value;
        this->y = value;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void Print() {
        cout << "X: " << x << " Y: " << y << endl;
    }
    Point plus(const Point& other) {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point minus(const Point& other) {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    // Owerload operators
    // void operator [ sumbol operator ]() {}

    #pragma region Math operators
    Point operator +(const Point& other) {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator -(const Point& other) {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other) {
        Point res(this->x * other.x, this->y + other.y);
        return res;
    }
    Point operator /(const Point& other) {
        Point res(this->x / other.x, this->y + other.y);
        return res;
    }
    #pragma endregion

    #pragma region Binary operators
    Point operator +=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator =(const Point& other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    #pragma endregion
    #pragma region Uno operators
    Point operator +=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    #pragma endregion

    #pragma region Logic operators < > <= >= ! == !=
    bool operator > (const Point& other) {
        return ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other) {
        return ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >= (const Point& other) {
        return ((this->x + this->y) >= (other.x + other.y));
    }
    bool operator <= (const Point& other) {
        return ((this->x + this->y) <= (other.x + other.y));
    }
    bool operator == (const Point& other) {
        return ((this->x == other.x) && (this->y == other.y));
    }
    bool operator == (const Point& other) {
        return ((this->x != other.x) || (this->y != other.y));
        // or
        return !(*this == other);
    }
    #pragma endregion






};




int main()
{
    cout << "Hello World!\n";

    int a = 5, b = 4;
    cout << a + b << endl;
    cout << a << endl;
    cout << b << endl;

    Point p1(5, 3);
    Point p2(7, 8);
    /*
    Point res = p1 + p2;
    res = p1 - p2;
    res = p1 - p2;
    */

    cout << "Point 1: "; p1.Print();
    cout << "Point 2: "; p2.Print();

    Point res = p1.plus(p2);
    cout << "Res: "; res.Print();
    res = p1.minus(p2);
    cout << "Res: "; res.Print();

    res = p1 + p2; // res = p1.operator + (p2);
    cout << "Res: "; res.Print();

    res = p1 - p2;
    cout << "Res: "; res.Print();

    res = p1 * p2;
    cout << "Res: "; res.Print();

    res = p1 / p2;
    cout << "Res: "; res.Print();

    p1 += p2;
    cout << "Res: "; p1.Print();


    if (p1 > p2)
        cout << "p1 > p1" << endl;
    else cout << "p1 < p1" << endl;
    if (p1 < p2)
        cout << "p1 < p1" << endl;
    else cout << "p1 > p1" << endl;


}
