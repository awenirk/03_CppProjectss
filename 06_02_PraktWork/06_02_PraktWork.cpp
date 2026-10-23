#include <iostream>
#include <iomanip>
using namespace std;

/*
Завдання 1:
Створити клас «Time», який буде описувати час 3-ма характеристиками: години, хвилини, секунди.
В класі потрібно реалізувати наступні конструктори:
•	Конструктор по замовчуванню () – встановлюватиме початкові дані
•	Параметризований (hours, minutes, seconds) – встановлює кожну властивість
•	Параметризований (seconds) – створює клас перевівши дану
     кількість секунд в години, хвилини, секунди. Наприклад: 5555 = 1год 32хв 35сек
•	5555/3600- h; 5555/60%60 – m; 5555%60 - s

Також передбачити методи:
1.	Виводу часу на екран в форматі hh:mm:ss
2.	Збільшення часу на одну секунду (11:59:59)++ -> 12:00:00

Клас повинен мати перевантаження наступних бінарних операторів:
•	+ – * /	виконується певна арифметична операція
     з часом та повертається результат у вигляді нового об'єкту Time
•	> < >= <=	перевіряється, який об’єкт містить
     більшу/меншу кількість часу та повертається результат у вигляді типу bool
•	== !=		перевіряється чи класи мають не/однаковий час
Використайте explicit для деяких конструкторів.

Додаткове персональе завдання: Додати дні у розрахунок.
*/

class Time {
    int days;
    int hours;
    int minutes;
    int seconds;
public:
    #pragma region Constructors
    Time() {
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int days, int hours, int minutes, int seconds) {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        if (hours >= 24) {
            days += hours / 24;
            hours = hours % 24;
        }
        this->days = days;
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    explicit Time(int seconds) {
        this->days = seconds / 86400;
        this->hours = (seconds % 86400) / 3600;
        this->minutes = (seconds % 3600) / 60;
        this->seconds = seconds % 60;
    }
    #pragma endregion

    #pragma region Work with time
    void PrintFull() {
        cout << "Days: " << days << '\n';
        cout << "Hours: " << hours << '\n';
        cout << "Minutes: " << minutes << '\n';
        cout << "Seconds: " << seconds << '\n';
    }
    void PrintShort() {
        cout << "Time: " << days << ":"
            << setw(2) << setfill('0') << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    void HelloMessage() {
        if (hours >= 5 && hours < 12)
            cout << "Good Morning" << '\n';
        else if (hours >= 12 && hours < 18)
            cout << "Good Afternoon" << '\n';
        else if (hours >= 18 && hours < 22)
            cout << "Good Evening" << '\n';
        else cout << "Good Night" << '\n';
    }

    void IncreaseOneSecond() {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
            if (minutes >= 60) {
                minutes = 0;
                hours++;
                if (hours >= 24) {
                    hours = 0;
                    days++;
                }
            }
        }
    }
    void decreaseOneSecond() {
        seconds--;
        if (seconds < 0) {
            seconds = 59;
            minutes--;
            if (minutes < 0) {
                minutes = 59;
                hours--;
                if (hours < 0) {
                    hours = 23;
                    days--;
                }
            }
        }
    }
    #pragma endregion

    #pragma region Owerload operators 1
    Time operator +(const Time& other) {
        int totalSeconds = (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) +
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
        Time result(totalSeconds);
        // result.PrintFull();
        return result;
    }
    Time operator -(const Time& other) {
        int totalSeconds = (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) -
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
        Time result(totalSeconds);
        // result.PrintFull();
        return result;
    }
    Time operator *(const Time& other) {
        int totalSeconds = (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) *
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
        Time result(totalSeconds);
        // result.PrintFull();
        return result;
    }
    Time operator /(const Time& other) {
        if (other.days == 0 && other.hours == 0 && other.minutes == 0 && other.seconds == 0) {
            cout << "Error: Division by zero!" << '\n';
        }
        else {
            int totalSeconds = (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) /
                (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
            Time result(totalSeconds);
            // result.PrintFull();
            return result;
        }
    }
    #pragma endregion

    #pragma region Owerload operators 2
    bool operator >(const Time& other) {
        return (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) >
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
    }
    bool operator <(const Time& other) {
        return (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) <
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
    }
    bool operator >=(const Time& other) {
        return (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) >=
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
    }
    bool operator <=(const Time& other) {
        return (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) <=
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
    }
    #pragma endregion
    
    #pragma region Owerload operators 3
    bool operator ==(const Time& other) {
        return (this->days * 86400 + this->hours * 3600 + this->minutes * 60 + this->seconds) ==
            (other.days * 86400 + other.hours * 3600 + other.minutes * 60 + other.seconds);
    }
    bool operator !=(const Time& other) {
        return !((*this) == other);
    }
    #pragma endregion

    #pragma region Owerload operators 4
    void operator ++(int) {
        IncreaseOneSecond();
    }
    void operator --(int) {
        decreaseOneSecond();
    }
    #pragma endregion

};


int main()
{
    cout << "Start program!\n";
    Time time1(0, 50, 0, 6);
    time1.HelloMessage();
    time1.PrintFull();
    time1.PrintShort();
    // add more tests for operators
    time1++;
    time1.PrintShort();
    time1--;
    time1.PrintShort();
    Time time2(1, 33, 59, 55);
    time1 = time1 + time2;
    time1.PrintShort();
}