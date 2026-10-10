#include <iostream>
using namespace std;
/*
struct Player {
    string name;
    short age;
    int games;
    int goals;
};

void PrintPlayer(Player& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "Games: " << p.games << endl;
    cout << "Golas: " << p.goals << endl;
}
void InitPlayer(Player& p) {
    cout << "Enter name: "; cin >> p.name;
    cout << "Enter age: "; cin >> p.age;
    p.games = 0;
    p.goals = 0;
}
void AddGameToPlayer(Player& p, int goals = 0) {
    p.games++;
    p.goals += goals;
}*/

class Player // all private
{
private:
    string name;
    short age;
    int games;
    int goals;

public:
    void PrintPlayer() {
        cout << "Your player:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Games: " << games << endl;
        cout << "Golas: " << goals << endl;
    }
    void InitPlayer() {
        cout << "Init Player" << endl;
        cout << "Enter name: "; cin >> name;
        cout << "Enter age: "; cin >> age;
        games = 0;
        goals = 0;
    }
    void AddGameToPlayer(int Goals = 0) {
        games++;
        this->goals += Goals;
    }
};

class Student {
private:
    string name; // data members
    int marks[3];
public:
    // setter
    void setName(string name) {
        this->name = name;
    }
    void setMark(int index, int mark) {
        if (mark >= 1 and mark <= 12)
            marks[index] = mark;
        else marks[index] = 0;
    }
    // getter
    string getName() { return name; }
    int getmark(int index) { return marks[index]; }

    // -------
    double getAverage() { // member function | Функції члени класу | Методи
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += marks[i];
        }
        return sum;
    }
};


int main()
{
    Student st;
    st.setName("Ivan");

    st.setMark(0, 11);
    st.setMark(1, 8);
    st.setMark(2, 4);

    cout << "Name: " << st.getName() << endl;
    cout << "mark 1: " << st.getmark(0) << endl;
    cout << "mark 2: " << st.getmark(1) << endl;
    cout << "mark 3: " << st.getmark(2) << endl;




    /*
    Player player;
    player.InitPlayer();
    player.PrintPlayer();
    cout << endl;

    player.AddGameToPlayer(3);
    cout << endl;
    player.PrintPlayer();
    player.AddGameToPlayer(2);
    cout << endl;
    player.PrintPlayer();
    player.AddGameToPlayer(1);
    cout << endl;
    player.PrintPlayer();
    */
    //InitPlayer(player);
    //PrintPlayer(player);
    //AddGameToPlayer(player);
    //AddGameToPlayer(player);
    //AddGameToPlayer(player);
    //PrintPlayer(player);
}