#include <iostream>

using namespace std;

// Drzewo bianrne - in-order, pre-order
class BinSearchTree {
    struct BSTNode
    {
        int value; // tez szablon
        BSTNode *pLeft; // glebokosc lewego podrzewa( jeseli gl == cos) to cos sie dzieje
        BSTNode *pRight;
    };

    BSTNode *pRoot;
public:
    BinSearchTree();
    BinSearchTree(int const arr[], int size);
    // kolejy konst moglyv vyc aby zbudowac drzeewo z listy

    ~BinSearchTree();
    void insert(int value);
    std::string toString();
    bool contains();
    void mirror();
    // ...
};

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
