#include "PointClass.h"

Point::Point(int x, int y) : x(x), y(y) {}

void Point::Print() { 
    cout << "Point: (" << x << ", " << y << ")" << endl;

}
