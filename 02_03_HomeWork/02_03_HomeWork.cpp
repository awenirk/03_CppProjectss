#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
Завдання 2:
Створити клас Student який буде містити характеристики: ім’я, вік, колекція оцінок, кількість оцінок та середню оцінку.
В класі повинні буди реалізовані наступні конструктори:
Конструктор по замовчуванню () – встановлюватиме початкові дані
Параметризований конструктор (const char* name, int age) – ініціалізує клас значеннями з параметрів
Також створити деструктор для звільнення ресурсів та наступні методи:
 
Print () – виводить інформацію про студента на екран
AddMark (int mark) – додає оцінку для студента
SetAverageMark () – приватний метод для обрахунку та встановлення середньої оцінки студента (викликається всередині класа при додаванні оцінки)
Save () – збереження студента в файл
Load () – зчитування студента в файла
Забезпечити клас необхідними методами для доступа до властивостей (getters, setters). По можливості застосувати делегування конструкторів.
*/
const string File = "file.txt";



class Student {
private:
    string name;
    int age;
    int* marks;
    int countMarks;
    float averageMark;
    void setAverageMark() {
        float temp = 0;
        for (int i = 0; i < countMarks; i++) {
            temp += marks[i];
        }
        if (countMarks == 0) averageMark = 0;
        else averageMark = temp / countMarks;
    }
public:
    // Constructors, deconstructor
    Student() {
        cout << "Default constructor" << endl;
        name = "No name";
        age = 0;
        marks = nullptr;
        countMarks = 0;
        averageMark = 0;
    }
    Student(string name, int age) {
        cout << "Parametrizer constructor!" << endl;
        this->name = name;
        this->age = age;
        marks = nullptr;
        countMarks = 0;
        averageMark = 0;
    }
    ~Student()
    {
        cout << "Destructor: " << name << endl;
        if (marks != nullptr) delete[] marks;
    }
    
    // Print, addMark
    void Print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMarks; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage Mark: " << averageMark << endl;
    }
    void addMark(int mark) {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++) {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        if (marks != nullptr) delete[] marks;
        marks = temp;
        countMarks++;
        setAverageMark();
    }

    // getters
    string getName() { return name; }
    int getAge() { return age; }
    int* getMarks() { return marks; }
    int getCountMarks() { return countMarks; }
    float getAverageMark() { return averageMark; }

    // setters
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setMarks(int* marks) { this->marks = marks; }
    void setCountMarks(int countMarks) { this->countMarks = countMarks; }
    void setAverageMark(float averageMark) { this->averageMark = averageMark; }
    
    // Save and load
    void SaveToFile() {
        ofstream out(File);

        if (!out.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        out << name << '\n';
        out << age << '\n';
        out << countMarks << '\n';

        for (int i = 0; i < countMarks; i++) {
            out << marks[i] << ' ';
        }

        out << '\n' << averageMark;
        out.close();

        cout << "Data saved successfully!" << endl;
    }
    void LoadFromFile() {
        ifstream in(File);

        if (!in.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        string newName;
        int newAge, newCount;
        float newAverage;

        if (!getline(in, newName) ||
            !(in >> newAge >> newCount) ||
            newCount < 0 || newCount > 10000) {
            cout << "Invalid file data!" << endl;
            return;
        }

        int* newMarks = nullptr;

        if (newCount > 0) {
            newMarks = new int[newCount];

            for (int i = 0; i < newCount; i++) {
                if (!(in >> newMarks[i])) {
                    delete[] newMarks;
                    cout << "Invalid marks!" << endl;
                    return;
                }
            }
        }

        if (!(in >> newAverage)) {
            delete[] newMarks;
            cout << "Invalid average mark!" << endl;
            return;
        }

        name = newName;
        age = newAge;
        delete[] marks;
        marks = newMarks;
        countMarks = newCount;
        averageMark = newAverage;

        cout << "Data loaded successfully!" << endl;
    }

};


int main()
{
    Student st;
    st.Print();

    st.setName("Anton");
    st.addMark(10);
    st.addMark(12);
    st.addMark(8);

    cout << "\n--- Student 1 ---\n";
    st.Print();

    cout << "\nName: " << st.getName() << endl;
    cout << "Age: " << st.getAge() << endl;

    st.SaveToFile();

    Student st2("Max", 18);
    st2.addMark(5);
    st2.addMark(7);

    cout << "\n--- Student 2 before loading ---\n";
    st2.Print();

    st2.LoadFromFile();

    cout << "\n--- Student 2 after loading ---\n";
    st2.Print();

}