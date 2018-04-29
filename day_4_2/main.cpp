#include <iostream>
#include <string>
using namespace std;

// na panelu: zaproponuj interfejs i implemetacje listy
// poimplementowac zasady solidu
// naryswaoc sobie zeby bylo latwiej
//
class List {
    struct Node
    { // wezel listy
        int value; // tu mozna szablon zamiast inta
        Node *pNext;
    };

    Node *pHead; // odniesienie do glowy
public:
    List();
    List(int const arr[], int size);    // tworzy liste z tablicy,
    ~List();
    void insert(int value); // przepiac head
    void reverse(); // odwrocenie(moze byc static) lub zwracac wskaznik do obiektu
    string toString(); // cala lista do stringa
    bool contains(int elem); // czy zawiera element
    // ...
};


int main(int argc, char *argv[])
{

    int tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    return 0;
}


List::List() // kosntruktor domyslny
{

}

List::List(const int arr[], int size) // przekazujemy tablice i przekazujemy ja do listy
{

}

List::~List()
{

}

void List::insert(int value) // przepinanie head i wsatwainie elementu na poczatek listy
{

}

void List::reverse() // odwrocenie elementow listy
{

}

string List::toString()
{
    string pom;
    return pom;
}

bool List::contains(int elem) // sprawdzenie czy zawiera element podany w indeksie
{
    bool has_elem = 0;
    for (size_t i = 0; i < (*this).size(); ++i)
    {
        if((*this))
    }

}
