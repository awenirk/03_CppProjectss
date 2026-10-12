#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
    void printDate() {
        cout << "BirthDate: " << day << " | " << month << " | " << year << endl;
    }
};

class Student {
    string name;
    string surname;
    string middlename;
    Date birthdate;
    string phone;
    int* marks;
    int countMarks;
    float averagemMark;
    
public:
    Student() {
        name = "No name";
        surname = "No surname";
        middlename = "No middlename";
        birthdate = { 1,1,1 };
        phone = "No phone";
        marks = nullptr;
        countMarks = 0;
        averagemMark = 0;
    }
    Student(string name, string surname, string middleneme) {
        cout << "Parametrizer constructor!" << endl;
        this->name = name;
        this->surname = surname;
        this->middlename = middlename;
        birthdate = { 1,1,1 };
        phone = "No phone";
        marks = nullptr;
        countMarks = 0;
        averagemMark = 0;
    }
    void addMaek(int mark) {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++) {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        if (marks != nullptr) delete[] marks;
        marks = temp;
        countMarks++;
    }
    void Print() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Middlename: " << middlename << endl;
        birthdate.printDate();
        cout << "Phone: " << phone << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMarks; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage Mark: " << averagemMark << endl;
    }
    // Setters
    void setName(string name) { this->name = name; }
    void setLastname(string surname) { this->surname = surname; }
    void setMiddlename(string middlename) { this->middlename = middlename; }
    
    // destructor
    ~Student()
    {
        cout << "Destructor: " << name << endl;
        if (marks != nullptr) delete[] marks;
    }
};


int main()
{
    cout << "Hello World!\n";
    Student st;
    st.Print();

    st.setName("Anton");
    st.setLastname("Chugun");
    st.setMiddlename("Lapuh");
    cout << endl;
    st.Print();

    
    Student st2("NAME", "GASHIM", "MUSHKA");
    st.Print();

}