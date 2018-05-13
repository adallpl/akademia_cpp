#ifndef ALGORITMS_H
#define ALGORITMS_H
#include <string>
#include <iostream>
#include <memory>
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
    // ...
};

void runListMethods();

///////////////////////////////////////////////////////////////

struct BSTNode;

class BinSearchTree {
    BSTNode *m_pRoot {nullptr}; // korzen
    int m_elemCount {0};
    bool m_isIncr {true};   //

    BSTNode* insertRecur(int elem, BSTNode *pCurrRoot);
    BSTNode *recurInsert1(BSTNode *pParentNode, int elem);
    std::string toStringRecur(BSTNode *pCurrRoot) const;    //
    BSTNode* mirrorRecur(BSTNode *pCurrRoot) const;
    int depthRecur(BSTNode *pCurrRoot) const;
    bool containsRecur(int elem, BSTNode *pCurrRoot) const;
    BSTNode* newBSTNode(int elem) const;
    void deleteElems(BSTNode *pCurrRoot);

public:
    static BinSearchTree* fromArray(int const arr[], int size); // PO CO STATIC?
    //BinSearchTree(int const arr[], int size);
    BinSearchTree() {}
    ~BinSearchTree();
    void insert(int value);
    std::string toString();
    bool contains(int elem) const;
    void mirror();
    int depth() const;
};

void runBinSearchTreeMethods();


#endif // ALGORITMS_H
