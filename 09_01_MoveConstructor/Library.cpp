#include "Library.h"

Library::Library() {
    name = "No Name";
    address = "No Address;";
    books = nullptr;
    countBooks = 0;
}

Library::Library(string name, string address) {
    this->name = name;
    this->address = address;
    books = nullptr;
    countBooks = 0;
}

Library::Library(const Library& oth) {
    this->name = oth.name;
    this->address = oth.address;
    this->countBooks = oth.countBooks;
    this->books = new Book[countBooks];
    for (int i = 0; i < countBooks; i++)
        this->books[i] = oth.books[i];
}

inline Library& Library::operator=(const Library& oth) {
    this->name = oth.name;
    this->address = oth.address;
    this->countBooks = oth.countBooks;
    this->books = new Book[countBooks];
    for (int i = 0; i < countBooks; i++)
        this->books[i] = oth.books[i];
    cout << "Operaator =" << endl;
    return *this;
}

Library::~Library() {
    if (books != nullptr)
        delete[] books;
}

void Library::showLibrary() const {
    cout << "Name: " << name << endl;
    cout << "Address library: " << address << endl;
    for (int i = 0; i < countBooks; i++) {
        books[i].ShowInfo();
        cout << endl << endl;
    }
}

void Library::AddBook(Book b) {
    Book* temp = new Book[countBooks + 1];
    for (int i = 0; i < countBooks; i++) {
        temp[i] = books[i];
    }
    temp[countBooks] = b;
    if (books != nullptr) delete[] books;
    countBooks++;
    books = temp;
}
