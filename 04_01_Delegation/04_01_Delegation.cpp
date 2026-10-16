#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string file = "file.txt";


/*
Завдання 1 :(практична робота на уроці)
Створіть додаток «Телефонна книга». Необхідно збері-
гати дані про абонента (ПІБ, домашній телефон, робочий
телефон, мобільний телефон, додаткова інформація про
контакт) всередині відповідного класу(Abonent).

Наповніть клас змінними-членами, функціями-членами, конструкторами.
Створити статичну змінну для кількості абонентів.
Використати делегування конструкторів.
*/
class Abonent {
    string Name;
    string surName;
    string middleName;

    string home_phone;
    string work_phone;
    string mobile_phone;
    string additional_information;

public:
    static int countAbonents;
    // -=-=-=-=-=-=-=-=-=-=-=-
    Abonent()
    {
        Name = "No name";
        surName = "No surname";
        middleName = "No middlename";
        home_phone = "No home phone";
        work_phone = "No work phone";
        mobile_phone = "No mobile phone";
        additional_information = "No additional information";
        countAbonents++;
    }
    Abonent(string name, string surname, string middlename,
        string homePhone, string workPhone,
        string mobilePhone, string addInf): Abonent() // Думаю цього достатньо що б зарахувати за використання делегації
    {
        this->Name = name;
        this->surName = surname;
        this->middleName = middlename;
        this->home_phone = homePhone;
        this->work_phone = workPhone;
        this->mobile_phone = mobilePhone;
        this->additional_information = addInf;
    }
    Abonent(const Abonent& other) {
        Name = other.Name;
        surName = other.surName;
        middleName = other.middleName;
        home_phone = other.home_phone;
        work_phone = other.work_phone;
        mobile_phone = other.mobile_phone;
        additional_information = other.additional_information;
        countAbonents++;
    }
    ~Abonent() { countAbonents--; }
    
    // -=-=-=-=-=-=-=-=-=-=-=-
    void ShowInfo() const {
        cout << "Full name: " << Name << " "
            << surName << " " << middleName << endl;

        cout << "Home phone: "<< home_phone << endl;
        cout << "Work phone: "<< work_phone << endl;
        cout << "Mobile phone: "<< mobile_phone << endl;
        cout << "Additional information: "<< additional_information << endl << endl;
    }
    // -=-=-=- Setters -=-=-=-
    void SetName(string name, string surname, string middlename) {
        this->Name = name;
        this->surName = surname;
        this->middleName = middlename;
    }
    void setHomePhone(string homePhone) { this->home_phone = homePhone; }
    void setWorkPhone(string workPhone) { this->work_phone = workPhone; }
    void setMobilePhone(string mobilePhone) { this->mobile_phone = mobilePhone; }
    void setAdditionalInformations(string addInf) { this->additional_information = addInf; }
    // -=-=-=- Getters -=-=-=-
    string getName() const { return Name; }
    string getHomePhone() const { return home_phone; }
    string GetFullName() const { return Name + " " + surName + " " + middleName; }
    static int GetCount() { return countAbonents; }
    // -=-=-=-=-=-=-=-=-=-=-=-
    void SaveToFile() const {
        ofstream out(file);

        if (!out.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        out << Name << '\n';
        out << surName << '\n';
        out << middleName << '\n';

        out << home_phone << '\n';
        out << work_phone << '\n';
        out << mobile_phone << '\n';
        out << additional_information << '\n';
    }
    void LoadFromFile() {
        ifstream in(file);

        if (!in.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        getline(in, Name);
        getline(in, surName);
        getline(in, middleName);

        getline(in, home_phone);
        getline(in, work_phone);
        getline(in, mobile_phone);
        getline(in, additional_information);
    }
};

/*
На додаткові 12 балів
Завдання 2:(домашня робота)
class PhoneBook
{
Abonent * abonents
int countAbonent ;
void Add(Abonent a){}
void Delete(string phone){}
void SearchByName(string name){}
void SearchByPhone(string phone{}
void ShowAll(){}
}
Надайте користувачеві можливість додавати нових абонентів,
видаляти абонентів,
шукати абонентів за ПІБ, показувати всіх абонентів.
Методи, які не змінюють this зробити CONST

***зберігати інформацію в файл і завантажувати з файлу (записати у файл треба 1 абонента і
зчитати з файлу треба 1 абонета).
*/
class PhoneBook
{
    Abonent* abonents;
    int countAbonent;
public:
    PhoneBook() {
        abonents = nullptr;
        countAbonent = 0;
    }
    ~PhoneBook() { delete[] abonents; }
    // -=-=-=-=-=-=-=-=-=-=-=-
    void Add(Abonent a) {
        Abonent* temp = new Abonent[countAbonent+1];
        if (abonents != nullptr)
            for (int i = 0; i < countAbonent; i++)
                temp[i] = abonents[i];
        temp[countAbonent] = a;
        delete[] abonents;
        abonents = temp;
        countAbonent++;
    }
    void Delete(string phone) {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getHomePhone() == phone) {
                cout << "Видалено: " << abonents[i].GetFullName() << endl;
                if (countAbonent == 1) {
                    delete[] abonents;
                    abonents = nullptr;
                    countAbonent = 0;
                    return;
                }
                Abonent* temp = new Abonent[countAbonent - 1];

                for (int j = 0, k = 0; j < countAbonent; j++) {
                    if (j != i) {
                        temp[k] = abonents[j];
                        k++;
                    }
                }

                delete[] abonents;
                abonents = temp;
                countAbonent--;
                return;
            }
        }
    }
    // -=-=-=-=-=-=-=-=-=-=-=-
    void SearchByName(string name) const {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].GetFullName() == name) abonents[i].ShowInfo();
        }
    }
    void SearchByPhone(string phone) const {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getHomePhone() == phone) abonents[i].ShowInfo();
        }
    }
    // -=-=-=-=-=-=-=-=-=-=-=-
    void ShowAll() const {
        for (int i = 0; i < countAbonent; i++) 
            abonents[i].ShowInfo();
    }
};


int Abonent::countAbonents = 0;
int main()
{
    cout << "Hello world!" << endl;
    PhoneBook Book;
    Abonent a("Name1", "Surname1", "Middlename1", "HP", "WP", "MP", "AI");
    Book.Add(a);
    Abonent b("Name2", "Surname2", "Middlename2", "HP", "WP", "MP", "AI");
    Book.Add(b);
    Book.ShowAll();

    cout << endl;

    b.SaveToFile();

    Abonent c;
    c.LoadFromFile();
    c.ShowInfo();

}
