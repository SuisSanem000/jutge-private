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

int profunditat(Node* a)
{
    if (a) {
        return 1 + max(profunditat(a->esq), profunditat(a->dre));
    } else {
        return 0;
    }
}

int main()
{

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        Node* a = llegir();
        cout << profunditat(a) << endl;
        delete a;
    }
}
