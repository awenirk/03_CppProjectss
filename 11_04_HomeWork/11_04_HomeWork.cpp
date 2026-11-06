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
int main()
{
    srand(time(0));
    int choice = 1;
    bool gameWin = false;
    int tempBet;
    Slots s(1000);

    cout << "Welcome to my game!\n";
    Sleep(500);

    while (choice != 0 or gameWin != true) {
        cout << "\n-=-=-=- Menu: -=-=-=-"
        cout << "0. Exit" << endl;
        cout << "1. Spin" << endl;
        cout << "2. Edit bet" << endl;
        cout << "3. None" << endl;
        cout << "4. Show stats" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 0:
            break;
        case 1:
            s.spin();
            s.isWin();
            break;
        case 2:
            cout << "Enter bet:";
            cin >> tempBet;
            s.seteBet(tempBet);
            break;
        case 3:
            // nedodelano
            break;
        case 4:
            Clear();
            s.showStats();
            _getch();
            break;
        default:
            break;
        }
    }
    
    Sleep(500);
    cout << "\nGoodbye!\n";
    Sleep(500);
}