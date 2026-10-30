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
    Library(Library&& oth);

    void showLibrary()const;
    void AddBook(Book b);

};

