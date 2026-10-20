#include <iostream>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    void setDay(int day) {
        this->day = day;
    }
    int getDay() {
        day += 10;
        return day;
    }
    int getDay() const{
        return day;
    }


    void Print() {
        day++;
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Account {
private:
    double sum;
    const double rate;
public:
    Account(double sum, double rate): rate(rate) {
        this->sum = sum;
    }
    double getRate()const { return rate; }
    double getIncome() { return sum * rate / 100; }
    double getIncome()const { return sum * rate / 100; }

    double getSum() { return sum; }
    double getSum()const { return sum; }
    double setSum()const {
        sum += getIncome();
        return sum;
    }



};
// пряма ініціалізація
// уніфіуована ініціалізація

class Array {
    int* arr;
    int size;
public:
    Array(int size) {
        this->size = size;
        arr = new int[size];
    }
    ~Array() { if (arr != nullptr) { delete[] arr; } }

    int getSize() {
        return size;
    }
    int getSize()const {
        return size;
    }
    int getValue(int index) {
        return arr[index];
    }
    int setValue(int index, int num) {
        arr[index] = num;
    }
    void display(int index)const {
        cout << arr[index] << "";
    }


};

void PrintArr(const Array &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        arr.display(i);
    }
    cout << endl;
}

int main()
{
    int size = 4;
    Array arr(size);
    for (int i = 0; i < size; i++) {
        arr.setValue(size - i, i);
    }
    PrintArr(arr);
    cout << "!!!!!!!!!!!!!" << endl;
    PrintArr(8);



    Account acc1(2000, 5);
    const Account acc2(5000, 8);

    cout << acc1.getRate() << endl;
    cout << acc2.getRate() << endl;

    cout << acc1.getSum() << endl;
    cout << acc2.getSum() << endl;

    cout << acc1.getIncome() << endl;
    cout << acc2.getIncome() << endl;

    cout << acc1.setSum() << endl;
    cout << acc2.setSum() << endl;


    /*
    
    cout << "Hello World!\n";
    const int size = 5;
    const int month[3]{ 31,31,28 };
    // month[0] = 45;

    Date holidayDate{ 25, 10, 2026 };
    holidayDate.Print();
    holidayDate.setDay(19);

    holidayDate.getDay();

    const Date indep{ 24, 8,2027 };
    indep.Print();
    indep.day = 25;
    indep.setDay(19);
    indep.getDay();
    */

}
