#include <iostream>
#include <string>
using namespace std;

#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

int compta_tresors_accessibles(BinTree<char> t);
int compta_tresors_inaccessibles(BinTree<char> t);

void main_apartat1() {
    BinTree<char> t;
    while (cin >> t) {
        cout << compta_tresors_accessibles(t) << endl;
    }
}

void main_apartat2() {
    BinTree<char> t;
    while (cin >> t) {
        cout << compta_tresors_inaccessibles(t) << endl;
    }
}

int main() {
    string apartat;
    getline(cin, apartat);
    if (apartat == "apartat1") {
        main_apartat1();
    } else {
        main_apartat2();
    }
}
