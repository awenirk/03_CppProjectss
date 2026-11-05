#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

/* Завдання 1:
Створити імітацію гри "однорукий бандит".
Наприклад, при натисканні кнопки «Enter» відбувається «обертання» трьох барабанів
(кількість обертань кожного з них вибирається випадково),
на яких зображені різні значки і якщо випадає певна комбінація,
то гравець отримує якийсь виграш.
Виконати дане завдання з використанням Queue
(данімічна структура даних – черга)
*/

// I decided not to struggle with the queue, but to write my own class.
// I decided not to struggle with the queue, but to write my own class.
// I decided not to struggle with the queue, but to write my own class.

void Clear() { system("cls"); }

enum Item {
    CHERRY = 1,
    LEMON = 2,
    BAR = 3,
    DIAMOND = 4,
    SEVEN = 5
};

struct Score {
    int spinsCount;  // count
    int winsCount;   // count
    int lossesCount; // count
    int totalWon;    // $
    int totalLose;   // $
};

class Slots {
    Item* reels;
    Item* topSymbols;
    Item* bottomSymbols;
    int money;
    int bet;
    Score score;
public:
#pragma region Constructors
    Slots() : reels(nullptr), money(1000), bet(0), score{} {}
    Slots(int money) : reels(nullptr), money(money), bet(0), score{} {}
    ~Slots() { if (reels != nullptr) delete[] reels; }
#pragma endregion

#pragma region functions
    void print()const {
        if (reels == nullptr) {
            cout << "Error! Reels not filled." << endl;
            return;
        }
        // тут ше зробити табличний гарний вивід
        else {
            cout << setw(5) << reels[0] << " |";
            cout << setw(5) << reels[1] << " |";
            cout << setw(5) << reels[2] << " |";
            cout << setw(5) << reels[3] << " |";
            cout << setw(5) << reels[4];
        }
    }
    void showResults()const {
        cout << "Your money:" << money << endl;
        cout << "Your spin count: " << score.spinsCount << endl;
        cout << "Your wins count: " << score.winsCount << endl;
        cout << "Your lose count: " << score.lossesCount << endl;
        cout << "Your total wins: " << score.totalWon << endl;
        cout << "Your total lose: " << score.totalLose << endl;
    }
#pragma endregion

#pragma region slot_functions
    // choice random item from enum Item
    Item randomChar() {
        int temp = 1 + rand() % 100;
        Item item = CHERRY;
        if (temp > 0 && temp <= 40) item = CHERRY;
        else if (temp > 40 && temp <= 65) item = LEMON;
        else if (temp > 65 && temp <= 85) item = BAR;
        else if (temp > 85 && temp <= 95) item = DIAMOND;
        else if (temp > 95 && temp <= 100) item = SEVEN;
        return item;
    }

    // fill all reels
    void fillReels() {
        Item* temp = new Item[5];
        for (int i = 0; i < 5; i++) {
            temp[i] = randomChar();
            // cout << temp[i] << ' ';
        }
        if (reels != nullptr)
            delete[] reels;
        reels = temp;
    }

    // final spin animation
    void spin() {
        Sleep(1000);
        cout << "Start!";
        Sleep(500);
        Clear();

        cout << '#';
        Sleep(150);
        Clear();
        cout << '@';
        Sleep(150);
        Clear();
        cout << ')';
        Sleep(150);
        Clear();
        cout << '|';
        Sleep(150);
        Clear();
        cout << '&';
        Sleep(150);
        Clear();
        cout << '%';
        Sleep(150);
        Clear();

        cout << 1 << endl;
        Sleep(500);
    }

    // check position to win
    void isWin() {}

#pragma endregion

#pragma region getters_setters
    int getMoney()const { return money; }
    int setMoney(int money) { this->money = money; }
#pragma endregion

};


int main()
{
    srand(time(0));
    cout << "Start!\n";

    Slots s(100);
    // s.showResults();

    s.fillReels();
    cout << endl;
    s.print();




    /*
    int choice = 1;
    while (choice != 0) {
        cout << "0. Exit" << endl;
        cout << "1. Spin" << endl;
        cout << "3. Show " << endl;
        cout << "Enter your choice: ";
        cin.get() >> choice;
        switch (choice) {
        case 0:
            break;
        case 1:


        default:
            break;
        }
    }
    */

    cout << "\nGoodbye!\n";
}