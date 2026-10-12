#include <iostream>
#include <string>
using namespace std;

struct Date {
    int Year;
    int Month;
    int Day;
};

class Student
{
    string Name;
    string Surname;
    string Lastname;
    Date BirthDate;
    string PhoneNumber;
    string City;
    string Country;
    string EducationName;
    string EducationCity;
    string EducationCountry;
    int GroupName;
public:
    // Getters (accessor)
    string getName() { return Name; }
    string getSurname() { return Surname; }
    string getLastname() { return Lastname; }
    Date getBirthDate() { return BirthDate; }
    string getPhoneNumber() { return PhoneNumber; }
    string getCity() { return City; }
    string getCountry() { return Country; }
    string getEducationName() { return EducationName; }
    string getEducationCity() { return EducationCity; }
    string getEducationCountry() { return EducationCountry; }
    int getGroupName() { return GroupName; }
    // Setters (mutator)
    void setName(string name) { Name = name; }
    void setSurname(string surname) { Surname = surname; }
    void setLastname(string lastname) { Lastname = lastname; }
    void setBirthDate(Date birthdate) { BirthDate = birthdate; }
    void setPhoneNumber(string phoneNumber) { PhoneNumber = phoneNumber; }
    void setCity(string city) { City = city; }
    void setCountry(string country) { Country = country; }
    void setEducationName(string educationName) { EducationName = educationName; }
    void setEducationCity(string educationCity) { EducationCity = educationCity; }
    void setEducationCountry(string educationCountry) { EducationCountry = educationCountry; }
    void setGroupName(int groupName) { GroupName = groupName; }
    // =========================================================
    void InputData() {
        cout << "Enter name: "; cin >> Name;
        cout << "Enter surname: "; cin >> Surname;
        cout << "Enter lastname: "; cin >> Lastname;

        cout << "Enter birth year: "; cin >> BirthDate.Year;
        cout << "Enter birth month: "; cin >> BirthDate.Month;
        cout << "Enter birth day: "; cin >> BirthDate.Day;

        cout << "Enter phoneNumber: "; cin >> PhoneNumber;
        cout << "Enter city: "; cin.ignore(); getline(cin, City);
        cout << "Enter country: "; getline(cin, Country);
        cout << "Enter educational institution name: "; getline(cin, EducationName);
        cout << "Enter educational institution city: "; getline(cin, EducationCity);
        cout << "Enter educational institution country: "; getline(cin, EducationCountry);
        cout << "Enter group Name: "; cin >> GroupName;
    }
    void ShowData() {
        cout << "Name: " << Name << endl;
        cout << "Surname: " << Surname << endl;
        cout << "Lastname: " << Lastname << endl;

        cout << "Birth year: " << BirthDate.Year << endl;
        cout << "Birth month: " << BirthDate.Month << endl;
        cout << "Birth day: " << BirthDate.Day << endl;

        cout << "PhoneNumber: " << PhoneNumber << endl;
        cout << "City: " << City << endl;
        cout << "Country: " << Country << endl;
        cout << "EducationName: " << EducationName << endl;
        cout << "EducationCity: " << EducationCity << endl;
        cout << "EducationCountry: " << EducationCountry << endl;
        cout << "GroupName: " << GroupName << endl;
    }
};


int main()
{
    Student st;
    st.InputData();
    st.ShowData();
}
