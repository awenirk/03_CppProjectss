#include <iostream>
using namespace std;

template <typename T>
T getMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
class MyClass {
    int* colection;
    int size;
public:
    MyClass() {
        colection = nullptr;
        size = 0;
    }
};




int main()
{
    const int size = 10;
    int arr[size] = { 1, 5, 3, 9, 2, 8, 4, 7, 6, 0 };
    short arr2[size] = { 1, 5, 3, 9, 2, 8, 4, 7, 6, 0 };
    long arr3[size] = { 1, 5, 3, 9, 2, 8, 4, 7, 6, 0 };
    string colors[6] = { "red", "green", "blue", "yellow", "orange", "purple" };

}
