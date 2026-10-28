#include "Book.h"
#include "Library.h"

Library TestLibrary(Library lib) {
    Library temp;
    return lib;
}

int main()
{
    Book book("Kobzar", 2000, "Ray rasdbery", 250, Genre::Fantasy);
    book.ShowInfo();

    Library lib("Youngth Library", "Kyivska 16");
    lib.AddBook(Book("The Hitchhiker's Guide to the Galaxy", 1979, "Douglas Adams", 224, Comedy));
    lib.AddBook(Book("Good Omens", 1990, "Neil Gaiman & Terry Pratchett", 416, Comedy));
    lib.AddBook(Book("To Kill a Mockingbird", 1960, "Harper Lee", 281, Drama));
    lib.AddBook(Book("Harry Potter and the Sorcerer's Stone", 1997, "J.K. Rowling", 309, Fantasy));
    lib.AddBook(Book("Dune", 1965, "Frank Herbert", 896, Sci_Fi));
    lib.AddBook(Book("The Adventures of Sherlock Holmes", 1892, "Arthur Conan Doyle", 307, Fantasy));
    lib.AddBook(Book("Pride and Prejudice", 1813, "Jane Austen", 279, Fantasy));
    lib.AddBook(Book("1984", 1949, "George Orwell", 328, Sci_Fi));
    lib.AddBook(Book("Three Men in a Boat", 1889, "Jerome K. Jerome", 223, Comedy));
    lib.AddBook(Book("The Great Gatsby", 1925, "F. Scott Fitzgerald", 180, Drama));
    lib.showLibrary();

    Library copy(lib);
    cout << "-=-=-=-=-=-=- Copy -=-=-=-=-=-=-" << endl;
    copy.showLibrary();

    Library newLib = copy;
    cout << "-=-=-=-=-=-=- Copy -=-=-=-=-=-=-" << endl;
    newLib.showLibrary();

    TestLibrary(lib);

}
