#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Для масиву вагонів створити окрему структуру
з наступними полями:
struct Vagon
номер вагону
кількість місць
кількість пасажирів
class Train
Створити клас Потяг. У класі оголосити поля(змінні члени класу):
модель
кількість вагонів
вказівник на масив вагонів(динамічний).Vagon * vagon;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Реалізувати метод додавання вагону до динамічного масиву
Реалізувати метод - додати 1 пасажира у вагон
Реалізувати конструктор копіювання
*/
struct Vagon {
    int number;
    int seat;
    int passengers;
};
class Train {
    string model;
    int countVagons;
    Vagon* vagons;
public:
    // Constructors
    Train() {
        model = "No model";
        countVagons = 0;
        vagons = nullptr;
    }
    Train(string model, int cv, Vagon* vagons) {
        this->model = model;
        this->countVagons = cv;
        if (cv > 0) {
            this->vagons = new Vagon[cv];
            for (int i = 0; i < cv; i++) {
                this->vagons[i] = vagons[i];
            }
        }
        else {
            this->vagons = nullptr;
            this->countVagons = 0;
        }
    }
    Train(const Train& other) {
        model = other.model;
        countVagons = other.countVagons;
        if (countVagons > 0) {
            vagons = new Vagon[countVagons];
            for (int i = 0; i < countVagons; i++) {
                vagons[i] = other.vagons[i];
            }
        }
        else {
            vagons = nullptr;
        }
    }
    ~Train() {
        delete[] vagons;
    }
    
    // Methods
    void Show() {
        cout << "Your train:" << endl;
        cout << "Model: " << model << endl;
        cout << "Count vagons: " << countVagons << endl;
        cout << "Vagons: " << endl << endl;
        for (int i = 0; i < countVagons; i++) {
            cout << "Vagon #" << i << ":" << endl;
            cout << "Number: " << vagons[i].number << endl;
            cout << "Seat: " << vagons[i].seat << endl;
            cout << "Passengers: " << vagons[i].passengers << endl << endl;
        }
    }
    void AddNewVagon(Vagon vagon) {
        Vagon* temp = new Vagon[countVagons + 1];
        for (int i = 0; i < countVagons; i++) {
            temp[i].number = vagons[i].number;
            temp[i].seat = vagons[i].seat;
            temp[i].passengers = vagons[i].passengers;
        }
        temp[countVagons] = vagon;
        delete[] vagons;
        vagons = temp;
        countVagons++;
    }
    void AddPassenger(int number) {
        if (number < 0 || number >= countVagons) {
            cout << "Vagon not found" << endl;
            return;
        }
        if (vagons[number].passengers >= vagons[number].seat) {
            cout << "Vagon full" << endl;
            return;
        }
        vagons[number].passengers++;
    }
};

int main()
{
    Train t1;
    t1.Show();

    Vagon arr[2] = { { 1, 10, 0 },{ 2, 5, 3 } };
    Train t2("Intercity", 2, arr);
    t2.Show();

    t2.AddNewVagon({ 3, 4, 0 });
    t2.AddPassenger(0);
    t2.AddPassenger(2);
    t2.Show();

    Train t3(t2);
    t3.AddPassenger(1);
    t3.Show();

    t2.Show();
}
 