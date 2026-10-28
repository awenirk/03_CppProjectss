#pragma once
#include "Book.h"

class Library {
private:
    string name;
    string address;
    Book* books;
    int countBooks;

public:
    Library();
    Library(string name, string address);
    Library(const Library& oth);
    Library& operator =(const Library& oth);
    ~Library();
    Library(Library&& oth) {
        this->name = oth.name;
        this->address = oth.address;
        this->countBooks = oth.countBooks;
        this->books = oth.books;
        oth.books = nullptr;
        cout << "Move constructor" << endl;
    }

    void showLibrary()const;
    void AddBook(Book b);

};

