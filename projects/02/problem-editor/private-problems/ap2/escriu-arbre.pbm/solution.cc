#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string val;
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
    string val;
    cin >> val;
    if (val == "-1")
        return nullptr;
    Node* esq = llegir();
    Node* dre = llegir();
    return new Node { val, esq, dre };
}

void escriure(Node* a, int c = 0)
{
    if (a) {
        escriure(a->dre, c + 10);
        for (int rep = c + 10 - a->val.size(); rep > 0; --rep)
            cout << ' ';
        cout << a->val << endl;
        escriure(a->esq, c + 10);
    }
}

int main()
{
    Node* a = llegir();
    escriure(a);
    delete a;
}
