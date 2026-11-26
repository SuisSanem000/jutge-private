#include "atzar.cc"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

atzar A(1);

typedef struct node* punter;

struct node {
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
    ofs << 0;
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

        int m = (p < 150 ? 1 : 1000);
        ofs << m << endl;
        ofs << endl;
        while (m--) {
            int n = (p == 149 ? 10000 : A.uniforme(4, 100));
            punter p = arbre(n);
            preordre(p, true, ofs);
            ofs << endl;
            if (m)
                ofs << endl;
        }
    }
}
