#include <iostream>
#include "example.hpp"
#include <memory>
#include <time.h>
using namespace std;

void ff(const Rational & a) {}

// c+11
std::string f() {return std::string("To jest string!");}

//wedlug nowszego standardu:
std::unique_ptr<Expression> f1() {
    return std::unique_ptr<Expression>{new Literal{2}};
}

// losowe wyrazenia


/*
 * 0: return new Literal
 * 1: - e1 = random expression
 *    - e2 = random expression
 *       return new Add{e1, e2};
 *
 * 2: e1 = random_Expression();
 *    e2 = random_Expression();
 *      return new Multiply{e1, e2};
*/


std::unique_ptr<Expression> random_expression(int k)
{
    srand(time(NULL));
    int number = std::rand() % 5;

    if(k == 0 || number < 3)
    {
        return std::unique_ptr<Expression> { new Literal {rand() % 10 }};
    }
    else if(number == 3)
    {
        std::unique_ptr<Expression> e1 = random_expression(k-1);
        std::unique_ptr<Expression> e2 = random_expression(k-1);
        std::cout << "Dodawanie!" << std::endl;
        return unique_ptr<Expression>{ new Add{std::move(e1), std::move(e2)}};
    }
    else if(number == 4)
    {
        std::unique_ptr<Expression> e1 = random_expression(k-1);
        std::unique_ptr<Expression> e2 = random_expression(k-1);
        std::cout << "Mnozenie!" << std::endl;
        return unique_ptr<Expression>{ new Multiply{std::move(e1), std::move(e2)}};

    }
}


int main()
{



    // d c++11 mielismy konstruktor kopiujacy.:
    std::string s = f(); // tu jest wywolywany konst kop do zainicjaklziowania s w main()
    std::string s2 = s;

    std::cout << s2 << std::endl;

        //wedlug nowszego standardu:

    std::unique_ptr<Expression> p = f1();
    std::unique_ptr<Expression> p2 = std::move(p); // tu bedzie uzyty konst przenoszacy. p zostanie zresetowany i przeniesiony do p2!
    // nie mzona tego kopiowa, ani morzenosci i przy przenozeniu zostaje zniszczony
    // teraz p na nic nie wskazuje, jest zainicjalizowany zerem(0)
    // czyli unique_ptr -> przenozenie zasobow

    /*  Rational a{3,2}, b{3, 8};
    f(3);
    Rational c = 5 + a;
    std::cout << c << std::endl;

    std::cout << "******************************************************************************" << std::endl;

    Literal l1{2};
    Literal l2{1.1};
    Literal l3{3.2};

    Add s(&l1, &l2);
    Multiply m(&s, &l3);

  //  std::cout << m.eval() << std::endl;

    std::cout << "******************************************************************************" << std::endl;

    {
        Expression* l1 = new Literal{4};
        Expression* l2 = new Literal{1.2};
        Expression* l3 = new Literal{4.3};
        Expression* s = new Add{l1, l2};
        Expression* m = new Multiply{s, l3};

        delete m;

    }*/
    Expression* old_ptr = new Literal{3};
    {
        std::unique_ptr<Expression> p{ old_ptr} ; // wskanzik na expresion zainicjalizowany jako Literal
                                                       // smart_pointera nie da ssie kopiowac
    //   p.reset(old_ptr);
        Expression* raw_ptr = p.release();
        std::unique_ptr<Expression> p2{ raw_ptr };
        std::unique_ptr<Expression> p3 = std::move(p2);


    }

    std::cout << "*******************************************************************" << std::endl;


   // Literal l1{2};
    std::unique_ptr<Expression> l1{ new Literal{2}}; // po wywoalniu move l1 jest zerowane (sa nullptr)i wsk z a wskazuje
    std::unique_ptr<Expression> l2{ new Literal{5}};
    Add a{std::move(l1), std::move(l2)}; // inque_ptr jest teraz w a ,pamiec zostanei zwolnuoa wtedy jak zostanie usuniety a!
                                         // mozna wydobyc informacje na co wskazuja unique_ptr ktore sa w obiekie Add ale musimy
                                         // zrobic jakas funkcje ktoraz zwaraca nam na co pokazuje ten wskanzik
    std::cout << a.eval() << std::endl;


    std::cout << "*******************************************************************" << std::endl;

    // losowe wyrazenia
    auto e = random_expression(1000);
    for(int i = 0; i < 10; i++)
    {

        std::cout << e->eval() << std::endl;
    }


    //wsisitor

    std::unique_ptr<Expression> l4{new Literal{5}};
    std::unique_ptr<Expression> l5{new Add{std::move(l4), std::move(l5)}};
    Printer p{};
    p.visit(*add);
    return 0;
}
