#include <iostream>
#include <cstring>

class String {
    char* buf;
public:
    String(const char* str): buf{new char[std::strlen(str) + 1]} {
        std::strcpy(buf, str);
    }


    String(const String& other): String(other.buf)  // delegat!
    {
        std::strcpy(buf, other.buf);
    }

    // zaalokowac nowy bufor na stringa

    // przez to ze przekazujemy przez wartosc kopia tworzy sie automatycznie daltego, nie musimy tworzyc zmiennej tmp
    String& operator = (String other) {
       /* char * temp = new char[std::strlen(other.buf) +1];
        std::strcpy(temp, other.buf);

        delete[] buf;
        buf = temp; // przypisujemy nowo - stworzony bufor
        return *this;

        */
      //  String tmp{other};

        std::swap(buf, other.buf);
        return *this;

        // nie tracimy zasobow ale cena jest wydajnosc, bo wykonujemy kopie
    }

    ~String() {
        delete[] buf;
    }


};
// wlasny konst kop i oper przyp

int main() {
    String a{"Ala"};
    String b{a};
    String c{"Kot"};
    (c = a) = b;
    a = a;

    // std::cout << a << std::endl;
}
