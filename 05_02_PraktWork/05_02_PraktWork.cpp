#include <iostream>
using namespace std;

/* Завдання №1
Створіть клас Book. Необхідно зберігати дані: автор,
назва, видавництво, рік, кількість, сторінок.
Створити масив об’єктів.
Вивести:
■■ список книг заданого автора;
■■ список книг, випущених заданим видавництвом;
■■ список книг, випущених після заданого року.

Використовуйте explicit-конструктор і константні
функції-члени (наприклад, для відображення даних про
книгу і т.д.).
*/
void Clear() { system("cls"); }

class Book {
    string author;
    string name;
    string publish;
    int year;
    int pages;

public:
    Book() {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = 0;
        this->pages = 0;
    }
    Book(string author, string name, string publish, int year, int pages) {
        this->author = author;
        this->name = name;
        this->publish = publish;
        this->year = year;
        this->pages = pages;
    }
    Book(const Book& other) {
        this->author = other.author;
        this->name = other.name;
        this->publish = other.publish;
        this->year = other.year;
        this->pages = other.pages;
    }
    explicit Book(int year) {
        this->author = "No author";
        this->name = "No name";
        this->publish = "No publisher";
        this->year = year;
        this->pages = 0;
    }
    
    void Print()const {
        cout << "Author: " << author << '\n';
        cout << "Name: " << name << '\n';
        cout << "Publish: " << publish << '\n';
        cout << "Year: " << year << '\n';
        cout << "Pages: " << pages << '\n';
    }
    string getAuthor()const {
        return author;
    }
    string getPublis()const {
        return publish;
    }
    int getYear()const {
        return year;
    }
};

class Library {
    Book* books;
    int countBooks;

public:
    Library() {
        books = nullptr;
        countBooks = 0;
    }
    ~Library() {
        if (countBooks != 0) delete[] books;
    }
    
    void PrintAll() {
        for (int i = 0; i < countBooks; i++) {
            books[i].Print();
            cout << '\n';
        }
    }

    void PrintAuthor(string author)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getAuthor() == author) books[i].Print();
    }
    void PrintPublish(string publish)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getPublis() == publish) books[i].Print();
    }
    void PrintYear(int year)const {
        for (int i = 0; i < countBooks; i++)
            if (books[i].getYear() > year) books[i].Print();
    }

    void addBook(Book& book) {
        Book* temp = new Book[countBooks + 1];

        for (int i = 0; i < countBooks; i++) {
            temp[i] = books[i];
        }

        temp[countBooks] = book;

        delete[] books;
        books = temp;
        countBooks++;
    }
};


int main()
{
    Library lib;

    Book book1("Author1", "Book1", "Publisher1", 1000, 100);
    Book book2("Author2", "Book2", "Publisher2", 2000, 200);
    Book book3("Author3", "Book3", "Publisher3", 3000, 300);
    Book book4("Author4", "Book4", "Publisher4", 4000, 400);
    Book book5("Author5", "Book5", "Publisher5", 5000, 500);
    Book book6("Author6", "Book6", "Publisher6", 6000, 600);

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.addBook(book5);
    lib.addBook(book6);

    cout << "All books:\n\n";
    lib.PrintAll();
    cin.get();
    Clear();

    cout << "Books by Author3:\n\n";
    lib.PrintAuthor("Author3");
    cin.get();
    Clear();

    cout << "Books by Publisher5:\n\n";
    lib.PrintPublish("Publisher5");
    cin.get();
    Clear();
    

    cout << "Books after 3000 year:\n\n";
    lib.PrintYear(3000);
    cin.get();
}