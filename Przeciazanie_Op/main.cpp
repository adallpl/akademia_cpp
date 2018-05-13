#include <iostream>

using namespace std;

//Liczby wymierne

class Rational
{
    int nominator;
    int dominator;
    // dominator > 0

public:
    Rational(int nom, int dom)
    {
        nominator = nom;
        dominator = dom;
        int d = gcd(nom ,dom); // sprawdzenei co wieskzeczy czy dom czy nom
        // denom < 0 -> nom: =-nom
        // denom := = -denom
    }
};

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
