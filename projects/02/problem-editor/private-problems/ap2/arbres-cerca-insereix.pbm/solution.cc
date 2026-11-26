#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* esq;
    Node* dre;

    ~Node()
    {
        delete esq;
        delete dre;
    }
};

void insert(Node*& p, int x)
{
    if (not p)
        p = new Node { x, nullptr, nullptr };
    else if (x < p->val)
        insert(p->esq, x);
    else if (x > p->val)
        insert(p->dre, x);
}

void preordre(Node* p)
{
    if (not p)
        return;
    cout << p->val << endl;
    preordre(p->esq);
    preordre(p->dre);
}

int main()
{
    Node* bst = nullptr;
    int x;
    while (cin >> x) {
        insert(bst, x);
    }
    preordre(bst);
    delete bst;
}
