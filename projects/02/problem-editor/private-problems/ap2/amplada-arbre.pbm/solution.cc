#include <algorithm>
#include <iostream>
#include <queue>
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

int amplada(Node* a)
{
    if (not a)
        return 0;

    int amplada = 1;
    queue<Node*> q1, q2;
    q1.push(a);
    while (not q1.empty()) {

        while (not q1.empty()) {
            Node* p = q1.front();
            q1.pop();
            if (p->esq)
                q2.push(p->esq);
            if (p->dre)
                q2.push(p->dre);
        }
        amplada = max(amplada, int(q2.size()));
        swap(q1, q2);
    }

    return amplada;
}

int main()
{

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        Node* a = llegir();
        cout << amplada(a) << endl;
        delete a;
    }
}
