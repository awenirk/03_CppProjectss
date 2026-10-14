#include <iostream>
#include <Windows.h>
using namespace std;

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
Завдання 1:
Створити клас Rectangle1, який буде описувати прямокутник. Клас містить розміри: ширина, висота, символ, який відображатиме прямокутник на екрані та координати розміщення. Для збереження координат створити структуру Coord, яка міститиме X та Y координату.
Клас повинен містити наступні конструктори:
Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
Параметризований конструктор, який приймає один параметр «розмір» та ініціалізує ним ширину та висоту
Параметризований конструктор, який приймає два параметри «ширину» та «висоту», які являються розмірами об’єкта
Та наступні методи:
Вивід фігури на екран, відповідного розміру, символом та у відповідних координатах
Зміна розміру прямокутника. Метод приймає два парметри: 1 – зміна висоти, 2 – ширини
Переміщення прямокутника. Метод приймає два парметри: 1 – величина переміщення по осі X, 2 – по осі Y
Методи повинні включати перевірку на коректність даних (від’ємна ширина, координати і тд). Створити екземпляр об’єкту та протестувати написаті методи.
*/
struct Coord {
    int x;
    int y;
};
class Rectangle1 {
    int width;
    int height;
    char symbol;
    Coord Cord;
public:
    Rectangle1() {
        cout << "Default constructor!" << endl;
        this->width = 0;
        this->height = 0;
        this->symbol = '*';
        this->Cord.x = 0;
        this->Cord.y = 1;
    }
    Rectangle1(int size) {
        cout << "First constructor!" << endl;
        this->width = size;
        this->height = size;
        this->symbol = '*';
        this->Cord.x = 0;
        this->Cord.y = 1;
    }
    Rectangle1(int width, int height) {
        cout << "Second constructor!" << endl;
        this->width = width;
        this->height = height;
        this->symbol = '*';
        this->Cord.x = 0;
        this->Cord.y = 1;
    }
    Rectangle1(int width, int height, char symbol) {
        cout << "Third constructor!" << endl;
        this->width = width;
        this->height = height;
        this->symbol = symbol;
        this->Cord.x = 0;
        this->Cord.y = 1;
    }
    Rectangle1(int width, int height, char symbol, int x, int y) {
        cout << "Fourth constructor!" << endl;
        this->width = width;
        this->height = height;
        this->symbol = symbol;
        this->Cord.x = x;
        this->Cord.y = y;
    }

    void Print() {
        SetPos(Cord.x, Cord.y);
        for (int i = 0; i < height; i++) {
            for (int i = 0; i < width; i++)
            {
                cout << symbol << " ";
            }
            SetPos(Cord.x, Cord.y+i+1);
        }
    }
    void Clear() {
        SetPos(Cord.x, Cord.y);
        for (int i = 0; i < height; i++) {
            for (int i = 0; i < width; i++)
            {
                cout << "  ";
            }
            SetPos(Cord.x, Cord.y + i+1);
        }
    }
    
    void ChangeWH(int height, int width) {
        this->height = height;
        this->width = width;
    }
    void ChangeXY(int x, int y) {
        this->Cord.x = x;
        this->Cord.y = y;
    }
    void ChangeSymbol(char sym) { this->symbol = sym; }


};



int main()
{
    Rectangle1 rt1;
    Rectangle1 rt2(5);
    Rectangle1 rt3(5, 3);
    Rectangle1 rt4(5, 5, '&', 5, 5);

    rt1.Print();
    Sleep(2000);
    rt1.Clear();

    rt2.Print();
    Sleep(2000);
    rt2.Clear();

    rt3.Print();
    Sleep(2000);
    rt3.Clear();

    rt4.Print();
    Sleep(2000);

    rt4.Clear();
    rt4.ChangeWH(8, 10);
    rt4.ChangeXY(15, 5);
    rt4.Print();
    Sleep(2000);
    rt4.ChangeSymbol('%');
    rt4.Print();

}
