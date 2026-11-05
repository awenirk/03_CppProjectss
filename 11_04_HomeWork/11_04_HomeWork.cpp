#include "slots.h"

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

int main()
{
    srand(time(0));
    cout << "Start!\n";
    Sleep(500);

    Slots s(100);
    // s.showResults();

    //s.fillReels();
    //s.print();

    s.spin();


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

    Sleep(500);
    cout << "\nGoodbye!\n";
}