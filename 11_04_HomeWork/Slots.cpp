#include "Slots.h"
#pragma region MyRegion

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

#pragma region MyRegion
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
        return;
        cout << "You win: " << bet * 1 << endl;
    }
    else {
        cout << "You lose: " << bet << endl;

    }
}

// asks what to deposit
void Slots::dodep() {}
#pragma endregion

