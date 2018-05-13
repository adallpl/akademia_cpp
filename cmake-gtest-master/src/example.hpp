#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <cmath>
using namespace std;

struct Node;
class List {
    Node *m_pHead {nullptr};
    int m_elemCount {0};
    void deleteElems(Node *pList);
public:
    static List* fromArray(int const arr[], int size); //factory method
    //List(int const arr[], int size);
    List() {}
    ~List();
    void insert(int value);
    void reverse();
    std::string toString() const;
    bool contains(int elem) const;
    int elemCount() const { return m_elemCount; }
};

void runListMethods();

// Returns 5
int five();

struct Node {
    int value;
    Node *pNext;
    ~Node() { /*std::cout << "destruction of " << value << std::endl;*/ }
};

void runListMethods()
{
    using namespace std;
    cout << "*** Testing l1 = [1,2,3,4,5,6,7,8,9] ***" << endl;

    constexpr int arr1[] = {1,2,3,4,5,6,7,8,9};
    std::unique_ptr<List> pL1(List::fromArray(arr1, 9));
    cout << "L1 = " << pL1->toString() << endl;

    cout << "L1.contains(3) = " << pL1->contains(3) << endl;
    cout << "L1.contains(10) = " << pL1->contains(10) << endl;

    cout << "*** Reversing L1... " << endl;
    pL1->reverse();
    cout << "L1 = " << pL1->toString() << endl;
    cout << endl;

    cout << "*** Testing list L2 = [] ***" << endl;

    unique_ptr<List> pL2(new List);
    cout << "L2 = " << pL2->toString() << endl;

    cout << "L2.contains(1) = " << pL2->contains(1) << endl;

    cout << "*** Reversing L2... " << endl;
    pL2->reverse();
    cout << "L2 = " << pL2->toString() << endl;
}
List* List::fromArray(int const arr[], int size)
{
    List* pL = new List;

    for (int i = size - 1; i >= 0; --i) {
        pL->insert(arr[i]);
    }

    return pL;
}
List::~List()
{
    deleteElems(m_pHead);
    this->m_elemCount = 0; //?
}
void List::insert(int elem)
{
    Node *pCurrHead = this->m_pHead;

    Node *pCurrNode = new Node;
    pCurrNode->value = elem;
    pCurrNode->pNext = pCurrHead;

    this->m_pHead = pCurrNode;
    this->m_elemCount++;
}
std::string List::toString() const
{
    using std::string; using std::to_string; // vs. using namespace
    string result {"["};

    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        result += to_string(pNode->value);
        if (pNode->pNext != nullptr) {
            result += ',';
        }
    }

    result += "]";
    return result;
}
bool List::contains(int elem) const
{
    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        if (pNode->value == elem) {
            return true;
        }
    }

    return false;
}

void List::reverse()
{
    Node *pPrevNode = nullptr, *pNode = this->m_pHead, *pNextNode;

    while (pNode != nullptr) {
        // swap/reconnect
        pNextNode = pNode->pNext;
        pNode->pNext = pPrevNode;

        // move to the next node
        pPrevNode = pNode;
        pNode = pNextNode;
    }

    this->m_pHead = pPrevNode;
}

void List::deleteElems(Node *pList)
{
    Node *pCurrHead = pList;

    if (pCurrHead != nullptr) {
        deleteElems(pCurrHead->pNext);
        delete pCurrHead;
    }
}

struct Solution{

    double x1;
    double x2;
    int count;
    bool identity;
};

inline Solution roots(double a, double b, double c)
{
    Solution wynik;
    double delta = (b*b) - (4*a*c);
    const double eps = 1e-5;
    if(std::abs(delta) == eps)
    {
        wynik.count = 1;
        wynik.identity = false;
        wynik.x1 = -(b/(2*a));
        wynik.x2 = wynik.x1;
    }
    else if(std::abs(delta) > eps)
    {
        wynik.count = 2;
        wynik.identity = false;
        wynik.x2 = -(b + (sqrt(delta)))/2*a;
        wynik.x1 = -(b - (sqrt(delta)))/2*a;
    }
    else if(std::abs(delta) < eps)
    {
        wynik.count = 0;
    }

    return wynik;
}

class Rational
{
    int numerator;
    int denominator;
    // denominator > 0

public:

    Rational(int num, int denom = 1): numerator(num), denominator(denom){ }

    int num() const {return numerator;}
    int denom() const {return denominator;}

    Rational & operator += (Rational a){
        return *this;
    }

    // modyfukujace umieszczamy w ciele klasy

};

inline bool operator == (Rational a, Rational b);
inline bool operator != (Rational a, Rational b);
inline bool operator < (Rational a, Rational b);
inline bool operator <= (Rational a, Rational b);
inline bool operator > (Rational a, Rational b);
inline bool operator >= (Rational a, Rational b);

inline Rational operator - (Rational a);
inline Rational operator + (Rational a, Rational b){
    a+=b;
    return b;
}
std::ostream& operator << (std::ostream& os, Rational a)
{
   os << a.num()<< "/" << a.denom();
    return os;
}
class Literal;
class Add;
class Multiply;
class Visitor{
public:
    virtual void visit(const Literal& e) = 0;
    virtual void visit(const Add& e) = 0;
    virtual void visit(const Multiply& e)= 0;
    Visitor() = default;
};

class Expression{

public:
    virtual ~Expression() = 0;
    virtual double eval() const = 0;
    virtual void accept(Visitor& v) const = 0;
};

inline double Expression::eval() const{
    std::cout << "Eval z Expression" << std::endl;

}
inline Expression::~Expression() = default;

class Literal: public Expression
{
    double val;
public:

    explicit Literal(double val): val{val} {}
    inline double eval() const{
        // override - kiedy nadpisujemy funkcje czysto wirtualne,
                                   // kompilator wie ze funkcja ma z zalozenia nadpisywac funkcje z klasy bazowej
        return val;
    }
    void accept(Visitor& v) const // najbardziej pasujacy typ bedzie wybrany przy przeciazaniu!
    {
        v.visit(*this);
    }

};

class BinaryOperator: public Expression{

protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    BinaryOperator( std::unique_ptr<Expression> left,  std::unique_ptr<Expression> right)
        : left{std::move(left)}, right{std::move(right)} {} // uzywamy move aby...
   /* ~BinaryOperator(){

        std::cout << "Usuwam left i right" << std::endl;
        delete left;
        delete right;
    }*/ // nie potrzebujemy destruktora bo mamy unique_ptr!

    Expression& getleft();
    Expression& getleft();
};


class Add: public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;

    double eval() const override{
        return left -> eval() + right -> eval();
    }
    void accept(Visitor& v) const // najbardziej pasujacy typ bedzie wybrany przy przeciazaniu!
    {
        v.visit(*this);
    }
};


class Multiply: public BinaryOperator {

public:
    using BinaryOperator::BinaryOperator;

    double eval() const override{
        return left -> eval() * right -> eval();
    }
    void accept(Visitor& v) const // najbardziej pasujacy typ bedzie wybrany przy przeciazaniu!
    {
        v.visit(*this);
    }
};




class UnaryOperator: public Expression{

protected:
    Expression* left;
    Expression* right;
public:
    UnaryOperator(Expression* left, Expression* right): left{left}, right{right} {}
};

class Minus: public UnaryOperator {

public:
    using UnaryOperator::UnaryOperator;

    double eval() const override{
        return left -> eval() - right -> eval();
    }
};


class Printer: public Visitor{
public:
    void visit(const Literal& e) override {
        std::cout << e.eval() << std::endl;
    }
    void visit(const Add& e) override {
    e.getleft().accept(&this);
    std::cout << " + " << std::endl;
    e.getRight().accept(*this);
    }
    void visit(const Multiply& e) override {

    }
};
















