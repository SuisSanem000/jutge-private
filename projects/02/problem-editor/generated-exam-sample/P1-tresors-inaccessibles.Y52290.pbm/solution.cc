#include "bintree.hh"
using namespace pro2;

int compta_tresors_accessibles(BinTree<char> t) {
    if (t.empty()) {
        return 0;
    }
    if (t.value() == 'X') {
        return 0;
    }
    int n = (t.value() == '*' ? 1 : 0);
    return n + compta_tresors_accessibles(t.left()) + compta_tresors_accessibles(t.right());
}

int compta_tresors_inaccessibles_rec(BinTree<char> t, bool inaccessible) {
    if (t.empty()) {
        return 0;
    }
    bool ara_inaccessible = inaccessible || t.value() == 'X';
    int n = (ara_inaccessible && t.value() == '*' ? 1 : 0);
    return n + compta_tresors_inaccessibles_rec(t.left(), ara_inaccessible) +
           compta_tresors_inaccessibles_rec(t.right(), ara_inaccessible);
}

int compta_tresors_inaccessibles(BinTree<char> t) {
    return compta_tresors_inaccessibles_rec(t, false);
}
