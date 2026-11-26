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

Node* llegir()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;
    Node* esq = llegir();
    Node* dre = llegir();
    return new Node { val, esq, dre };
}

void postordre(Node* a)
{
    if (a) {
        postordre(a->esq);
        postordre(a->dre);
        cout << " " << a->val;
    }
}

void inordre(Node* a)
{
    if (a) {
        inordre(a->esq);
        cout << " " << a->val;
        inordre(a->dre);
    }
}

int main()
{
    Node* a = llegir();

    cout << "pos:";
    postordre(a);
    cout << endl;

    cout << "ino:";
    inordre(a);
    cout << endl;

    delete a;
}
