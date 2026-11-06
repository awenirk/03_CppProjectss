#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

void Clear() { system("cls"); }

enum Item {
    CHERRY = 0,
    LEMON = 1,
    BAR = 2,
    DIAMOND = 3,
    SEVEN = 4
};
struct Score {
    int spinsCount;  // count
    int winsCount;   // count
    int lossesCount; // count
    int totalWon;    // $
    int totalLose;   // $
};
struct Table {
    int n1, n2, n3, n4, n5;
    Item t1, t2, t3, t4, t5;
    Table(int n1): n1(n1), n2(n1), n3(n1), n4(n1), n5(n1) {}
    Table(int n1, int n2, int n3, int n4, int n5): n1(n1), n2(n2), n3(n3), n4(n4), n5(n5) {}
    void setTs(Item* reels) {
        this->t1 = reels[0];
        this->t2 = reels[1];
        this->t3 = reels[2];
        this->t4 = reels[3];
        this->t5 = reels[4];
    }
};

class Slots {
    Item* beginReels;
    Item* reels;
    Item* endReels;
    int money;
    int bet;
    int lastBet;
    Score score;
public:
#pragma region Constructors
    Slots() : beginReels(nullptr), reels(nullptr), endReels(nullptr),
        money(1000), bet(0), lastBet(0), score{} {}
    Slots(int money) : beginReels(nullptr), reels(nullptr), endReels(nullptr),
        money(money), bet(0), lastBet(0), score{} {}
    ~Slots() {
        if (beginReels != nullptr) delete[] beginReels;
        if (reels != nullptr) delete[] reels;
        if (endReels != nullptr) delete[] endReels;
    }
#pragma endregion
#pragma region getters_setters
    void setMoney(int money) { this->money = money; }
    void seteBet(int bet) { this->bet = bet; }
#pragma endregion
#pragma region functions
    void print()const;
    void showMoney()const;
    void showStats()const;
#pragma endregion
#pragma region slot_functions
    Item randomChar();
    void fillReels();
    void spin();
    bool isWin();
    void dodep();
#pragma endregion
};