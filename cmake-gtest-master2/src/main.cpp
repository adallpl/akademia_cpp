#include <iostream>
#include "example.hpp"
#include "rational.hpp"
#include <memory>
#include <cstdio>
#include <cstdlib>

using namespace std;


class Literal;
class Add;
class Mult;

class Visitor {
public:
    virtual void visit(const Literal& e) = 0;
    virtual void visit(const Add& e) = 0;
    virtual void visit(const Mult& e) = 0;
    virtual ~Visitor() = default;
};


class Expression {
public:
    virtual ~Expression() = 0;
    virtual double eval() const = 0;
    virtual void accept(Visitor& v) const = 0;
};

inline Expression::~Expression() = default;

inline double Expression::eval() const {
    return 0;
}

class Literal : public Expression {
    double val;
public:
    explicit Literal(double val): val{val} { }

    double eval() const override {
        return val;
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class BinaryOp : public Expression {
protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    BinaryOp(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left{std::move(left)}, right{std::move(right)} { }
    Expression& getLeft() const { return *left; }
    Expression& getRight() const { return *right; }
};

class Add : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double eval() const override {
        return left->eval() + right->eval();
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class Mult : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double eval() const override {
        return left->eval() * right->eval();
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class Printer : public Visitor {
    std::ostream& os;
    double value;
public:
    void visit(const Literal& e) override {
        std::cout << e.eval();
    }
    void visit(const Add& e) override {
        e.getLeft().accept(*this);
        std::cout << " + ";
        e.getRight().accept(*this);
    }
    void visit(const Mult& e) override {
        e.getLeft().accept(*this);
        double leftValue = value;
        e.getRight().accept(*this);
        double rightValue = value;

        value = leftValue * rightValue;

    }
    double getValue() const{
        return value;
    }
    // zobaczyc implementacje Printer!!!

};

// visitor
/*std::ostream& operator << (std::ostream &os, const Expression& e)
{
    Printer printer{os};
    e.accept(printer);
    return os;
}*/




int main()
{
    std::unique_ptr<Expression> l1{ new Literal{5} };
    std::unique_ptr<Expression> l2{ new Literal{3} };
    std::unique_ptr<Expression> add{ new Add{std::move(l1), std::move(l2)} };
   // Printer p{};
  //  add->accept(p);

    // output nieformatowany:

    // napisac funckje kopiujaca plik!!!

    //std::istream in;
   // std::ostream out;
   /* char buf[4096];

   while(in){
        //sprawdamy tu czuy nie doszlisymy do konca pliku z kotregeo czytamy.
        in.read();
        int size =  gcount(); // albo read
        out.write(...);
    }
    const char* path_read = "plik_czytaj.txt";
    const char* path_write = "plik_zapisz.txt";

    ofstream out;
    istream in;
    out.open(path_read, ios::out);

    fprintf(file_write, "Sample text from program" );
    // Failed to open the file, print message and end program
    if (file_open == nullptr) {
        // stderr - standard error (diagnostic) output
        // stdout - standard output
        // stdin  - standard input
        fputs("Could not open file\n", stderr); // wyjscie standardowe bledu
        exit(1);
    }else{
        fputs("File correctly open!\n", stdout);
    }

    //fprintf (fp, "%s", tekst); // zapisz nasz łańcuch w pliku
    //close (fp);  zamknij plik


   const int SIZE = 10;
    int data[SIZE];
    // Fill it with some data pattern
    for (int i = 0; i < SIZE; ++ i) {
        data[i] = 0x40302010;
    }
    // Write 10 data items, each of size sizeof(int)
    // array name = pointer to its beginning
    int written = fwrite(data, sizeof(int), SIZE, file); // dane do zapisania, rozmair pojed elelentu, rozmiar danych, gdzie chcemuy zapisac
    // zwraca ilsoc obiekotw ktore udalo sie zapisac

    // Less objects successfully written than we wanted = error
    if (written < SIZE) {
        // %d - integer, %s - string // pisze stringa razem z odpowiednio sformatowanymi danymi
        fprintf(stderr, "Error, only written %d items to file %s\n", written, path);
    }
*/

    // bledy i ich propagacja

    // mechanizm wyjatku



}

