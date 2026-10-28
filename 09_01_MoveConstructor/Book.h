#pragma once
#include <iostream>
using namespace std;

enum Genre{ None, Fantasy, Roman, History, Drama, Sci_Fi,
            Horror, Comedy, Political, Education};

class Book {
private:
    string title;
    int year;
    string author;
    int pages;
    Genre genre = Comedy;

public:
    Book();
    Book(string t, int y, string a, int p, Genre g) :title(t), year(y), author(a), pages(p), genre(g)  {}
    void ShowInfo()const;

};

