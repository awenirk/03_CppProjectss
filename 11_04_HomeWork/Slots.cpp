#include "Slots.h"

#pragma region table_print
string getSymbol(Item item) {
    switch (item) {
    case CHERRY:
        return "CHERRY"; // 🍒
    case LEMON:
        return "LEMON"; // 🍋
    case BAR:
        return " BAR"; // 💸
    case DIAMOND:
        return "DIAMOND"; // 💎
    case SEVEN:
        return " SEVEN"; // 🔥
    case NONE:
        return " NONE";
    default:
        return "?";
    }
}
void BegginLine(const Table& T) {
    cout << (char)201;
    for (int i = 0; i < T.n1; i++)
        cout << (char)205;
    cout << (char)203;
    for (int i = 0; i < T.n2; i++)
        cout << (char)205;
    cout << (char)203;
    for (int i = 0; i < T.n3; i++)
        cout << (char)205;
    cout << (char)203;
    for (int i = 0; i < T.n4; i++)
        cout << (char)205;
    cout << (char)203;
    for (int i = 0; i < T.n5; i++)
        cout << (char)205;
    cout << (char)187 << endl;
}
void textLine(const Table& T) {
    cout << (char)186 << " " << left << setw(T.n1 - 1) << getSymbol(T.t1);
    cout << (char)186 << " " << left << setw(T.n2 - 1) << getSymbol(T.t2);
    cout << (char)186 << " " << left << setw(T.n3 - 1) << getSymbol(T.t3);
    cout << (char)186 << " " << left << setw(T.n4 - 1) << getSymbol(T.t4);
    cout << (char)186 << " " << left << setw(T.n5 - 1) << getSymbol(T.t5);
    cout << (char)186 << endl;
}
void fillLine(const Table& T) {
    cout << (char)204;
    for (int i = 0; i < T.n1; i++)
        cout << (char)205;
    cout << (char)206;
    for (int i = 0; i < T.n2; i++)
        cout << (char)205;
    cout << (char)206;
    for (int i = 0; i < T.n3; i++)
        cout << (char)205;
    cout << (char)206;
    for (int i = 0; i < T.n4; i++)
        cout << (char)205;
    cout << (char)206;
    for (int i = 0; i < T.n5; i++)
        cout << (char)205;
    cout << (char)185 << endl;
}
void EndLine(const Table& T) {
    cout << (char)200;
    for (int i = 0; i < T.n1; i++)
        cout << (char)205;
    cout << (char)202;
    for (int i = 0; i < T.n2; i++)
        cout << (char)205;
    cout << (char)202;
    for (int i = 0; i < T.n3; i++)
        cout << (char)205;
    cout << (char)202;
    for (int i = 0; i < T.n4; i++)
        cout << (char)205;
    cout << (char)202;
    for (int i = 0; i < T.n5; i++)
        cout << (char)205;
    cout << (char)188 << endl;
}
#pragma endregion

#pragma region functions
void Slots::print() const {
    if (reels == nullptr) { cout << "Error! Reels not filled." << endl; }
    else {
        Table T(8,8,8,8,8);
        BegginLine(T);

        T.setTs(beginReels);
        textLine(T);
        fillLine(T);

        T.setTs(reels);
        textLine(T);
        fillLine(T);

        T.setTs(endReels);
        textLine(T);

        EndLine(T);
    }
}
void Slots::showMoney() const {
    cout << "Your money:" << money << endl;
}
void Slots::showStats() const {
    cout << "Last bet:" << lastBet << endl;
    cout << "Your spin count: " << score.spinsCount << endl;
    cout << "Your wins count: " << score.winsCount << endl;
    cout << "Your lose count: " << score.lossesCount << endl;
    cout << "Your total wins: " << score.totalWon << endl;
    cout << "Your total lose: " << score.totalLose << endl;
}
#pragma endregion
 
#pragma region slot_functions
Item Slots::randomChar() {
    int temp = 1 + rand() % 100;
    Item item = CHERRY;
    if (temp > 0 && temp <= 45) item = CHERRY;
    else if (temp > 45 && temp <= 75) item = LEMON;
    else if (temp > 75 && temp <= 91) item = BAR;
    else if (temp > 91 && temp <= 98) item = DIAMOND;
    else if (temp > 98 && temp <= 100) item = SEVEN;
    return item;
}
void Slots::fillReels() {
    Item* temp1 = new Item[5];
    Item* temp2 = new Item[5];
    Item* temp3 = new Item[5];
    for (int i = 0; i < 5; i++) {
        temp1[i] = randomChar();
        temp2[i] = randomChar();
        temp3[i] = randomChar();
        // cout << temp[i] << ' ';
    }
    if (reels != nullptr)
        delete[] reels;
    if (beginReels != nullptr)
        delete[] beginReels;
    if (endReels != nullptr)
        delete[] endReels;
    beginReels = temp1;
    reels = temp2;
    endReels = temp3;
}
void Slots::spin() {
    fillReels();
    Item FinalBeginReels[5];
    Item FinalReels[5];
    Item FinalEndReels[5];

    for (int i = 0; i < 5; i++) {
        FinalBeginReels[i] = randomChar();
        FinalReels[i] = randomChar();
        FinalEndReels[i] = randomChar();
    }

    for (int stopped = 0; stopped < 5; stopped++) {
        for (int spin = 0; spin < 13; spin++) {
            for (int reel = stopped; reel < 5; reel++) {
                beginReels[reel] = randomChar();
                reels[reel] = randomChar();
                endReels[reel] = randomChar();
            }

            Clear();
            print();
            Sleep(60);
        }

        beginReels[stopped] = FinalBeginReels[stopped];
        reels[stopped] = FinalReels[stopped];
        endReels[stopped] = FinalEndReels[stopped];

        Clear();
        print();
    }
    score.spinsCount++;
}
bool Slots::isWin() {
    bool win = false;
    int counts[5] = {0, 0, 0, 0, 0};
    int winningSymbol = -1;
    int wins = 0;

    for (int i = 0; i < 5; i++) {
        int symbol = reels[i];
        if (symbol >= 0 && symbol <= 4) {
            counts[symbol]++;
        }
    }
    for (int symbol = 0; symbol <= 4; symbol++) {
        if (counts[symbol] >= 3) {
            if (counts[symbol] > wins) {
                wins = counts[symbol];
                winningSymbol = symbol;
            }
        }
    }


    if (wins < 3) {
        cout << "You lose: " << bet << endl;
        money -= bet;
        score.lossesCount++;
        score.totalLose += bet;
        win = false;
    }
    else {
        cout << "Your bet: " << bet << endl;
        money -= bet;
        score.winsCount++;
        win = true;
        switch (wins) {
        case 3:
            cout << "Three in a row!" << endl;
            switch (winningSymbol) {
            case 0:
                cout << "You win: " << bet * 0.5 << endl;
                money = money + (bet * 0.5);
                score.totalWon += (bet * 0.5);
                break;
            case 1:
                cout << "You win: " << bet * 1 << endl;
                money = money + (bet * 1);
                score.totalWon += (bet * 1);
                break;
            case 2:
                cout << "Chance is: 2.89%" << endl;
                cout << "It will drop 1 in 34 spins" << endl;
                cout << "You win: " << bet * 2 << endl;
                money = money + (bet * 2);
                score.totalWon += (bet * 2);
                break;
            case 3:
                cout << "Chance is: 0.29% !!!" << endl;
                cout << "It will drop 1 in 337 spins" << endl;
                cout << "You win: " << bet * 6 << endl;
                money = money + (bet * 6);
                score.totalWon += (bet * 6);
                break;
            case 4:
                cout << "Chance is: 0.0076% !!!" << endl;
                cout << "It will drop 1 in 13.015 spins" << endl;
                cout << "You win: " << bet * 15 << endl;
                money = money + (bet * 15);
                score.totalWon += (bet * 15);
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << "Four in a row!!" << endl;
            switch (winningSymbol) {
            case 0:
                cout << "Chance is: 11.2%" << endl;
                cout << "It will drop 1 in 9 spins" << endl;
                cout << "You win: " << bet * 2 << endl;
                money = money + (bet * 2);
                score.totalWon += (bet * 2);
                break;
            case 1:
                cout << "Chance is: 2.83%" << endl;
                cout << "It will drop 1 in 35 spins" << endl;
                cout << "You win: " << bet * 4 << endl;
                money = money + (bet * 4);
                score.totalWon += (bet * 4);
                break;
            case 2:
                cout << "Chance is: 0.275% !" << endl;
                cout << "It will drop 1 in 363 spins" << endl;
                cout << "You win: " << bet * 12 << endl;
                money = money + (bet * 12);
                score.totalWon += (bet * 12);
                break;
            case 3:
                cout << "Chance is only: 0.011% !!" << endl;
                cout << "It will drop 1 in 8.956 spins" << endl;
                cout << "You win: " << bet * 50 << endl;
                money = money + (bet * 50);
                score.totalWon += (bet * 50);
                break;
            case 4:
                cout << "Chance is only: 0.000078% !!!" << endl;
                cout << "It will drop 1 in 1.275.510 spins" << endl;
                cout << "You win: " << bet * 200 << endl;
                money = money + (bet * 200);
                score.totalWon += (bet * 200);
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (winningSymbol) {
            case 0:
                cout << "Jackpot" << endl;
                cout << "Chance is: 1.84528% !!!" << endl;
                cout << "It will drop 1 in 54 spins" << endl;
                cout << "You win: " << bet * 10 << endl;
                money = money + (bet * 10);
                score.totalWon += (bet * 10);
                break;
            case 1:
                cout << "Jackpot!" << endl;
                cout << "Chance is: 0.243% !!!" << endl;
                cout << "It will drop 1 in 411 spins" << endl;
                cout << "You win: " << bet * 30 << endl;
                money = money + (bet * 30);
                score.totalWon += (bet * 30);
                break;
            case 2:
                cout << "Jackpot!!" << endl;
                cout << "Chance is: 0.010486% !!!" << endl;
                cout << "It will drop 1 in 9.536 spins" << endl;
                cout << "You win: " << bet * 200 << endl;
                money = money + (bet * 200);
                score.totalWon += (bet * 200);
                Sleep(3000);
                break;
            case 3:
                cout << "JACKPOT!!!" << endl;
                cout << "Chance is only: 0.000168% !!!" << endl;
                cout << "It will drop 1 in 594.990 spins" << endl;
                cout << "You win: " << bet * 1500 << endl;
                money = money + (bet * 1500);
                score.totalWon += (bet * 1500);
                Sleep(5000);
                break;
            case 4:
                cout << "BIGEST JACKPOT EVER IN WORLD!!!!!!" << endl;
                cout << "Chance is only: 0.000032% !!!" << endl;
                cout << "It will drop 1 in 3.125.000 spins" << endl;
                cout << "You win: " << bet * 10000 << endl;
                money = money + (bet * 10000);
                score.totalWon += (bet * 10000);
                Sleep(10000);
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    showMoney();
    lastBet = bet;
    return win;
}
#pragma endregion

Table::Table(int n1) : n1(n1), n2(n1), n3(n1), n4(n1), n5(n1) {
    t1 = NONE;
    t2 = NONE;
    t3 = NONE;
    t4 = NONE;
    t5 = NONE;
}
Table::Table(int n1, int n2, int n3, int n4, int n5) : n1(n1), n2(n2), n3(n3), n4(n4), n5(n5) {
    t1 = NONE;
    t2 = NONE;
    t3 = NONE;
    t4 = NONE;
    t5 = NONE;
}