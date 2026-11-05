#include "Slots.h"

#pragma region table_print
string getSymbol(Item item) {
    switch (item) {
    case CHERRY:
        return "CHERRY";
    case LEMON:
        return "LEMON";
    case BAR:
        return " BAR";
    case DIAMOND:
        return "DIAMOND";
    case SEVEN:
        return " SEVEN";
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
void Clear() { system("cls"); }
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
}

void Slots::isWin() {
    if (true) {
        cout << "You win: " << bet * 1 << endl;
    }
    else {
        cout << "You lose: " << bet << endl;
    }
}

void Slots::dodep() {}
#pragma endregion
