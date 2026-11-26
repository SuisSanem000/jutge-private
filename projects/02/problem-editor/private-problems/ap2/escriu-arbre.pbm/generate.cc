#include "atzar.cc"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

atzar A(2);

typedef struct node* punter;

struct node {
    string elem;
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

string par()
{
    string s;
    int m = A.uniforme(1, 9);
    while (m--)
        s += 'a' + A.uniforme(0, 25);
    return s;
}

punter arbre(int n)
{
    if (!n)
        return 0;

    punter p = new node;
    p->elem = par();
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
        string s = "prova-" + st(p) + ".ent";
        ofstream ofs(s.c_str());
        if (!ofs) {
            cout << "ERROR OBRINT EL FITXER " << s << endl;
            return -1;
        }

        int n = (p < 150 ? p - 96 : 1000);
        punter p = arbre(n);
        ofs << n << endl;
        preordre(p, true, ofs);
        ofs << endl;
    }
}
