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

// export import to file
// exception bet

int main()
{
    srand(time(0));
    int choice = 1;
    bool gameWin = false;
    int tempBet;
    Slots s(1000);

    cout << "Welcome to my game!\n";
    Sleep(1200);

    while (choice != 0 && s.getMoney() > 0 && s.getMoney() < 1000000) {
        system("cls");
        cout << "-=-=-=- Menu: -=-=-=-\n";
        cout << "1. Spin\n";
        cout << "2. Edit bet\n";
        cout << "3. Show money\n";
        cout << "4. Show stats\n";
        cout << "0. Exit\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 0:
            break;
        case 1:
            s.spin();
            s.isWin();
            cout << "\nEnter to continue...";
            _getch();
            break;
        case 2:
            cout << "Enter bet: ";
            cin >> tempBet;
            if (tempBet > s.getMoney()) {
                cout << "Bet can`t be more than your money!" << endl;
            }
            else {
                s.seteBet(tempBet);
                s.setLastBet(tempBet);
                cout << "Bet set successful!" << endl;
            }
            break;
        case 3:
            system("cls");
            s.showMoney();
            cout << "\nEnter to continue...";
            _getch();
            break;
        case 4:
            s.showStats();
            cout << "\nEnter to continue...";
            _getch();
            break;
        default:
            break;
        }
    }
    if (s.getMoney() <= 0) { cout << "\nYou have gone bankrupt.\n"; }
    else if (s.getMoney() > 0 and s.getMoney() < 1000000) { cout << "\nYou not lose!\n"; }
    else if (s.getMoney() > 1000000) { cout << "\nCongratulations, you beat the game.\n"; }
    cout << "Goodbye!\n";
}