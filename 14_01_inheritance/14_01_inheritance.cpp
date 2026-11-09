#include <iostream>
using namespace std;

class Enemy {
protected:
    string name;
    int health;
    float strenght;
    static const int maxHealth = 100;
public:
    Enemy(): name("No name"), health(maxHealth), strenght(0) {}
    Enemy(string mane, float strenght): name(mane), health(maxHealth), strenght(strenght) {}
    void print()const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << '%' << endl;
        cout << "Strenght: " << strenght << endl;

    }
    void decreaseHealth(int value) {
        if (health - value > 0) { health -= value; }
        else health = 0;
    }
    bool isAlive()const {
        return health > 0;
    }

    void fight(int damage) {
        cout << "Getting damage : " << damage << '%' << endl;
        decreaseHealth(damage);
        cout << "Health: " << health << endl;
    }
    float atack()const {
        cout << "Atack with strenght: " << strenght << endl;
        return strenght;
    }

};

class Dragon : public Enemy {
    float armor;
public:
    Dragon(): armor(0), Enemy() {}
    Dragon(string n, float s, float a): armor(0), Enemy(n, s) {}
    void fight(int damage) {
        Enemy::fight(damage - armor);
    }
    void print()const {
        cout << "-=-=-=- Dragon -=-=-=-" << endl;
        Enemy::print();
        cout << "Armot: " << armor << endl;
    }
};

class Wizard : public Enemy {
    float turbo_Atack;
public:
    Wizard() {
        turbo_Atack = 0;
    }
    Wizard(string n, float s, float t): turbo_Atack(t), Enemy(n,s) {}
    float AtackWithTurboPower() {
        cout << "Atack with turbo power!" << endl;
        return turbo_Atack + strenght;
    }
    void print() {
        cout << "-=-=-=- Wizard -=-=-=-" << endl;
        Enemy::print();
        cout << "Turbo atack power: " << turbo_Atack << endl;
    }
};



int main()
{
    cout << "Hello World!\n";
    Dragon dragon("Leftarion", 5, 8);
    Dragon boss("Righterion", 7, 10);
    dragon.print();
    boss.print();
    int i = 1;
    cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-" << endl << endl << endl;

    do {
        cout << "-=-=-=-=-=-=- Round " << i << " -=-=-=-=-=-=-" << endl;
        dragon.fight(boss.atack());
        boss.fight(dragon.atack());
        i++;
        cout << endl;

    } while (boss.isAlive() and dragon.isAlive());
    
    cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    dragon.print();
    boss.print();
    cout << "-=-=-=-=-=-=-=-=-=-=-=-" << endl << endl;

    Wizard wizard("Chacklun", 4, 4);
    i = 1;
    do {
        cout << "-=-=-=-=-=-=- Round " << i << " -=-=-=-=-=-=-" << endl;
        wizard.fight(boss.atack());
        boss.fight(wizard.atack());
        i++;
        cout << endl;

    } while (boss.isAlive() and wizard.isAlive());


    cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    wizard.print();
    boss.print();
    cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-" << endl;
}
