#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

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
    int lastBet;
    Score score;
public:
#pragma region Constructors
    Slots() : reels(nullptr), money(1000), bet(0), score{} {}
    Slots(int money) : reels(nullptr), money(money), bet(0), score{} {}
    ~Slots() { if (reels != nullptr) delete[] reels; }
#pragma endregion

#pragma region getters_setters
    int getMoney()const { return money; }
    int setMoney(int money) { this->money = money; }
#pragma endregion

#pragma region functions
    void print()const;
    void showMoney()const;
    void showResults()const;
#pragma endregion

#pragma region slot_functions
    // choice random item from enum Item
    Item randomChar();
    // fill all reels
    void fillReels();
    // final spin animation
    void spin();
    // check position to win
    void isWin();
    // asks what to deposit
    void dodep();
#pragma endregion

};