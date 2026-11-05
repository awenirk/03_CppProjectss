#include "Slots.h"

#pragma region table_print
void BegginLine(Table& T) {
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
void textLine(Table& T) {
    cout << (char)186 << " " << left << setw(T.n1 - 1) << T.t1;
    cout << (char)186 << " " << left << setw(T.n2 - 1) << T.t2;
    cout << (char)186 << " " << left << setw(T.n3 - 1) << T.t3;
    cout << (char)186 << "  " << left << setw(T.n4 - 2) << T.t4;
    cout << (char)186 << " " << left << setw(T.n5 - 1) << T.t5;
    cout << (char)186 << endl;
}
void fillLine(Table& T) {
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
void EndLine(Table& T) {
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
void Clear() { system("cls"); }
void Slots::print() const {
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
void Slots::showMoney() const {
    cout << "Your money:" << money << endl;
}
void Slots::showResults() const {
    cout << "Last bet:" << lastBet << endl;
    cout << "Your spin count: " << score.spinsCount << endl;
    cout << "Your wins count: " << score.winsCount << endl;
    cout << "Your lose count: " << score.lossesCount << endl;
    cout << "Your total wins: " << score.totalWon << endl;
    cout << "Your total lose: " << score.totalLose << endl;
}
#pragma endregion

#pragma region slot_functions
// choice random item from enum Item
Item Slots::randomChar() {
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
void Slots::fillReels() {
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
void Slots::spin() {
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
void Slots::isWin() {
    if (true) {
        cout << "You win: " << bet * 1 << endl;
    }
    else {
        cout << "You lose: " << bet << endl;
    }
}

// asks what to deposit
void Slots::dodep() {}
#pragma endregion

