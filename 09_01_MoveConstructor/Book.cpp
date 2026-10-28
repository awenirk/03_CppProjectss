#include "Book.h"

Book::Book() {
    title = "no title";
    year = 0;
    author = "no author";
    pages = 0;
    genre = None;
}

void Book::ShowInfo() const {
    cout << "Title: " << title << endl << "Year: " << year
        << endl << "Author: " << author << endl
        << "Pages: " << pages << endl << "Genre: ";

    switch (genre) {
    case None:      cout << "None" << endl << endl; break;
    case Fantasy:   cout << "" << endl << endl; break;
    case Roman:     cout << "" << endl << endl; break;
    case History:   cout << "" << endl << endl; break;
    case Drama:     cout << "" << endl << endl; break;
    case Sci_Fi:    cout << "" << endl << endl; break;
    case Horror:    cout << "" << endl << endl; break;
    case Comedy:    cout << "" << endl << endl; break;
    case Political: cout << "" << endl << endl; break;
    case Education: cout << "" << endl << endl; break;
    default: break;
    }
}
