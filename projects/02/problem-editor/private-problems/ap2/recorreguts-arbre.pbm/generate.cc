#include "atzar.cc"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

atzar A(1);

typedef struct node* punter;

struct node {
    int elem;
    punter esq, dre;
};

string st(int x)
{
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    return s;
}

punter arbre(int n)
{
    if (!n)
        return 0;

    punter p = new node;
    p->elem = A.uniforme(0, 1000);
    int e = A.uniforme(0, n - 1);
    p->esq = arbre(e);
    p->dre = arbre(n - 1 - e);
    return p;
}

void preordre(punter p, bool primer, ofstream& ofs)
{
    if (!p) {
        if (not primer)
            ofs << ' ';
        ofs << -1;
        return;
    }

    if (not primer)
        ofs << ' ';
    ofs << p->elem;
    preordre(p->esq, false, ofs);
    preordre(p->dre, false, ofs);
}

int main()
{
    for (int p = 100; p <= 150; ++p) {
        string s = "test-" + st(p) + ".inp";
        ofstream ofs(s.c_str());
        if (!ofs) {
            cout << "ERROR OBRINT EL FITXER " << s << endl;
            return -1;
        }

        int n = (p < 150 ? p - 96 : 10000);
        punter pt = arbre(n);
        preordre(pt, true, ofs);
        ofs << endl;
    }
}
