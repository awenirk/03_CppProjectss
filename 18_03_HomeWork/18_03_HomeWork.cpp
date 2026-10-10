#include <iostream>
#include <fstream>
using namespace std;

class Point {
    double x, y, z;

public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void InputData() {
        cout << "Enter X: "; cin >> x;
        cout << "Enter Y: "; cin >> y;
        cout << "Enter Z: "; cin >> z;
    }
    void ShowData() {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }

    void SaveToFile() {
        ofstream file("point.txt");

        if (file.is_open()) {
            file << x << endl;
            file << y << endl;
            file << z << endl;
            file.close();

            cout << "Data saved successfully!" << endl;
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }

    void LoadFromFile() {
        ifstream file("point.txt");

        if (file.is_open()) {
            file >> x >> y >> z;
            file.close();

            cout << "Data loaded successfully!" << endl;
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }
};

int main() {
    Point p;
    p.InputData();
    cout << endl << "Point coordinates:" << endl;
    p.ShowData();
    p.SaveToFile();

    Point p2;
    p2.LoadFromFile();
    cout << endl << "Loaded coordinates:" << endl;
    p2.ShowData();
}
