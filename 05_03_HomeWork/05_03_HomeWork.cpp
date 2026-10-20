#include <iostream>
using namespace std;

/* Завдання №2
Створіть клас Worker. Необхідно зберігати дані:
ПІБ, посада, рік вступу на роботу, зарплата.
Створити масив об’єктів. Вивести:
■ список працівників, стаж роботи яких на цьому підприємстві перевершує задане число років;
■ список працівників, зарплата яких перевищує задану;
■ список працівників, які займають задану посаду.
Використовуйте explicit-конструктор і константні функції-члени
(наприклад, для відображення даних про працівника і т.д.).
*/
void Clear() { system("cls"); }

class Worker {
    string name;
    string position;
    int year;
    double salary;

public:
    Worker() {
        this->name = "No name";
        this->position = "No position";
        this->year = 0;
        this->salary = 0;
    }
    Worker(string name, string position, int year, double salary) {
        this->name = name;
        this->position = position;
        this->year = year;
        this->salary = salary;
    }
    Worker(const Worker& other) {
        this->name = other.name;
        this->position = other.position;
        this->year = other.year;
        this->salary = other.salary;
    }
    explicit Worker(int year) {
        this->name = "No name";
        this->position = "No position";
        this->year = year;
        this->salary = 0;
    }

    void Print()const {
        cout << "Name: " << name << '\n';
        cout << "Position: " << position << '\n';
        cout << "Year: " << year << '\n';
        cout << "Salary: " << salary << '\n' << '\n';
    }
    string getPosition()const {
        return position;
    }
    int getYear()const {
        return year;
    }
    double getSalary()const {
        return salary;
    }

};

class Company {
    Worker* workers;
    int countWorkers;

public:
    Company() {
        workers = nullptr;
        countWorkers = 0;
    }
    ~Company() {
        if (countWorkers != 0) delete[] workers;
    }

    void PrintAll() {
        for (int i = 0; i < countWorkers; i++) {
            workers[i].Print();
        }
    }

    void PrintPosition(string position)const {
        for (int i = 0; i < countWorkers; i++)
            if (workers[i].getPosition() == position) workers[i].Print();
    }
    void PrintSalary(double salary)const {
        for (int i = 0; i < countWorkers; i++)
            if (workers[i].getSalary() > salary) workers[i].Print();
    }
    void PrintYear(int year)const {
        for (int i = 0; i < countWorkers; i++)
            if (2026 - workers[i].getYear() > year) workers[i].Print();
    }

    void addWorker(Worker& worker) {
        Worker* temp = new Worker[countWorkers + 1];
        for (int i = 0; i < countWorkers; i++) {
            temp[i] = workers[i];
        }
        temp[countWorkers] = worker;
        delete[] workers;
        workers = temp;
        countWorkers++;
    }
};


int main()
{
    Company company;

    Worker worker1("John Doe", "Manager", 2015, 50000);
    Worker worker2("Jane Smith", "Developer", 2016, 45000);
    Worker worker3("Bob Johnson", "Designer", 2014, 40000);
    Worker worker4("Alice Brown", "Manager", 2017, 55000);
    Worker worker5("Charlie Wilson", "Developer", 2018, 48000);
    company.addWorker(worker1);
    company.addWorker(worker2);
    company.addWorker(worker3);
    company.addWorker(worker4);
    company.addWorker(worker5);

    cout << "All workers:\n\n";
    company.PrintAll();
    cin.get();
    Clear();

    cout << "Workers with year greater than 2015:\n\n";
    company.PrintYear(2015);
    cin.get();
    Clear();

    cout << "Workers with salary greater than 45000:\n\n";
    company.PrintSalary(45000);
    cin.get();
    Clear();

    cout << "Workers with position 'Manager':\n\n";
    company.PrintPosition("Manager");
    cin.get();
}