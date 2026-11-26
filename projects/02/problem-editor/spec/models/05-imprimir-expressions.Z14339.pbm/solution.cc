#include <sstream>
using namespace std;

#include "tree.hh"
using namespace pro2;

bool is_number(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string expression_to_string(Tree<string> t) {
    assert(!t.empty(), "expression_to_string: arbre buit");
    string value = t.value();
    if (is_number(value)) {
        return value;
    }
    ostringstream sout;
    sout << "(";
    sout << expression_to_string(t.child(0));
    for (int i = 1; i < t.num_children(); i++) {
        sout << ' ' << value << ' ';
        sout << expression_to_string(t.child(i));
    }
    sout << ")";
    return sout.str();
}
