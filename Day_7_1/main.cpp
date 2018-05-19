#include <iostream>
#include <cstring>

// kolejnosc wywolania konstruktorow
using namespace std;
struct A{
    std::string a;
    A(): a{"abcde"}
    {std::cout << "konst a z A" << std::endl; }
};
struct B: A{
    string a;
    string c;

    B(): c{"Ala"}, A{}, a{c} // kolejnsoc na liscie nie ma zadnego znaczenia przy wywolaniu
    {}

    B(int): a{" "}, c{"asdf"}
    {}
    // 1. kod w ciele konst wykona sie po
}; // override - infpormuje kompilator  ze metoda jext nadpisana z kalsy bazowej

// klasy polimorficzne

struct C{
    virtual void f() const  { }
    virtual ~C() = default;
};

struct D: C{
    void f() const override{}
};

void f(C c){
    c.f();
}


class String {
    char* buf;
public:
    String(const char* str):buf{new char[strlen(buf) +1]} {
      std::strcpy(buf, str);
    }

    String(const String& other): buf{other.buf} { }
    String& operator = (const String& other) {
        buf = other.buf;
        return *this;
    }
    ~String(){
        delete[] buf;
    }
};



int main()
{
 //   D d;
  //  C c{d};
  //  f(c);
    String a{"ala"};
    String c{"kot"};
    // the rule of 3: konst kopiujacy, operator przypisania, destruktor
    c = a;

    return 0;
}
